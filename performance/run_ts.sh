#!/usr/bin/env bash

# include  libraries
source $NS_WDIR/lib/automation_util
source $NS_WDIR/lib/automation_config.dat 


# Perf test specific global variables
PERF_TEST_DATA_FILE="/home/automation/workbench/automation/nscore/performance/.perf/PerfResult"
JAVA_PERF_TEST_DATA_FILE="/home/automation/workbench/automation/nscore/performance/.perf/javabasedperfresult"
SSL_PERF_RESULT_FILE="/home/automation/workbench/automation/nscore/logs/ssl_perf_result.html"


# Initiates current testsuite specific environment variables
function init() {
  CUR_DIR=$(pwd)

  # Get Release Specific Information
  RELEASE=$(cat $NS_WDIR/etc/version |grep VERSION| cut -d " "  -f2| cut -d . -f1,2,3)
  MAJOR=$(cat $NS_WDIR/etc/version | head -1 |cut -d "." -f4)
  MINOR=$(cat $NS_WDIR/etc/version | tail -1  | cut -d " " -f2)

  # Results directory to store the automation result.
  R_DIR="${CUR_DIR}/results/$RELEASE/${MAJOR}.${MINOR}"

  [ ! -d "${R_DIR}" ] && mkdir -p "${R_DIR}"

  #Temporary File.
  TEMP_FILE=/tmp/ns_run.$$

  #Result File.
  CYCLENO=$(get_cycle_num)
  R_FILE="${R_DIR}/${testSuite}_${CYCLENO}.txt"
  XML_FILE="${R_DIR}/${testSuite}_${CYCLENO}.xml"
  
  export R_FILE
  export XML_FILE
  export TEMP_FILE
}


# Runs testsuite bin/ts_run
function run(){
    testSuite="$1"            
    debug_opt="$2"            

    # Changing current directory to ns_wdir 
    cd $NS_WDIR

    echo "Starting NSCore performance automation suite using command bin/ts_run"
    echo "Running TestSuite = '$testSuite'"

    # Running test in backend
    Project=$(project_name $testSuite)
    bin/ts_run -n ${Project}/${testSuite} | tee $TEMP_FILE    


    #Check return code. If RC=2, automation timed out case. RC=0 Success
    RC=$?

    [ $RC -ne 0 ] && {
       echo "Possible test case failure. Check logs..."
    } || {
       echo "NSCore ${testSuite} automation suite has ended"
    }

    [ "X$debug_opt" == "X--debug" ] && {
       copy_logs
    }

    # Setting result summary of currently finished testsuite
    set_test_summary_ex
 
    # Returning back to automation workbench
    cd - >/dev/null
}


# Cleans temporary files
function clean_up(){
    echo "Cleaning up temporary files."
    rm -f ${TEMP_FILE}
}


# To copy TR's in current directory logs folder.
# Only when --debug option is passed while running the shell;
function copy_logs(){
    [ ! -d ${CUR_DIR} ] && mkdir -p ${CUR_DIR}/logs

    sleep 1

    for trNum in $(grep TestRun ${TEMP_FILE} | awk -F'=' '{print $2}')
    do
        if [ -d $NS_WDIR/logs/TR${trNum} ];then
          debug_log "Copying test runs to ${CUR_DIR}/logs"
          cp -r $NS_WDIR/logs/TR${trNum} ${CUR_DIR}/logs/
          debug_log "Copied TR${trNum}"
        else
          error_log "TestRun not found"
        fi
    done
}


# Returns count of testcase for current testsuite
function get_test_case_count() {
    testcases=$(cat testsuites/${suite_conf} |grep -v "#" | cut -d ' ' -f2)
    count=0
  
    for testcase in ${testcases}
    do
        i=$(grep -c "^Performance" testcases/${testcase}/iteration.spec)
        count=$(($count + $i))
    done
  
    echo ${count}
}


# Provide info about total testcase executed &
# numbers of NSFail testcases
function update_test_status() {
    cycle_num="${1}"
    suite="${2}"
    TMP_COUNT_FILE="/tmp/last"
    
    if [ "${suite}" == "Performance_Cps" ]; then
        NSFailCount=$(grep -c "NetstormFail" $NS_WDIR/logs/tsr/${cycle_num}/cycle_summary.report)
	    TotalExecuted=$(get_test_case_count)
	    echo "NSFailCount=$NSFailCount" >${TMP_COUNT_FILE}
	    echo "TotalExecuted=$TotalExecuted" >>${TMP_COUNT_FILE}
	    export NSFailCount
	    export TotalExecuted 
    else
        fail=$(grep -c "NetstormFail" $NS_WDIR/logs/tsr/${cycle_num}/cycle_summary.report)
	    total=$(get_test_case_count)
        NSFailCount=$((fail + NSFailCount))
	    TotalExecuted=$((total + TotalExecuted))
        sed -i "s/NSFailCount.*/NSFailCount=${NSFailCount}/g" ${TMP_COUNT_FILE}
        sed -i "s/TotalExecuted.*/TotalExecuted=${TotalExecuted}/g" ${TMP_COUNT_FILE}
	    export NSFailCount
	    export TotalExecuted 
    fi
}


# Execution begins from here
function main() {
    echo "Initializing test environment "
    init

    # Display test case count
    echo "Total Cases to test in ${testSuite} suite = $(get_test_case_count)"

    # This function creates the header for result file.
    set_results_header_ex

    # TODO 
    export curr_date_time=$(date)

    # Call to run  to start automation
    run "${testSuite}" "${debug_opt}"
    
    # TODO 
    # To check why one error related to grep command 
    # error coming after execution of run module
    TSR_DIR=$(grep "Test Cycle Number" ${TEMP_FILE} | egrep -o [0-9_]+)
    PERF_R_FILE=$NS_WDIR/logs/tsr/$TSR_DIR/CurrentDataCSVData.CSV

    # Cleans up temp file/s
    clean_up
    
    # Check cycle summary report file and append total test run executed
    # Check for netstorm failed cases and update the count
    update_test_status "${TSR_DIR}" "${testSuite}"

    # Parse the txt file and create results in xml format- NEW
    ${PYTHON_TOOL} -i "${R_FILE}" -o "${XML_FILE}" -f $(get_failed_test_count) -p $(get_passed_test_count) -t $(get_test_case_count)

    # Match the testsuite name and process the results operation
    # If CPS : Overwrite PERF_TEST_DATA_FILE with second line of PERF_R_FILE
    #    SSL : Run gen_ssl_perf_report.rb script with necessary arguments
    #    HPS/TPut : Append test data of first testcase of each of these metric to PERF_TEST_DATA_FILE
     
    if [ "$testSuite" == "Performance_Cps" ];then
		# C script based perf stat
        cat $PERF_R_FILE |head -2 |tail -1 >${PERF_TEST_DATA_FILE}
		
		# Java type script based perf stat
		cps_java=$(grep "Performance_cps_java_128User_OEF_010" $NS_WDIR/logs/tsr/$TSR_DIR/CurrentDataCSVData.CSV)
		echo ${cps_java} >${JAVA_PERF_TEST_DATA_FILE}
    elif [ "$testSuite" == "Performance_SSL" ]; then
        gen_ssl_perf_report.rb -i $PERF_R_FILE -o $SSL_PERF_RESULT_FILE 
    else
		# C script based perf stat
	    hps=$(grep  "Performance_hps_128User_OEF_010" $NS_WDIR/logs/tsr/$TSR_DIR/CurrentDataCSVData.CSV | head -1)
	    echo $hps >>${PERF_TEST_DATA_FILE}
	    throughput=$(grep  "Performance_throughput_128User_OEF_010" $NS_WDIR/logs/tsr/$TSR_DIR/CurrentDataCSVData.CSV | head -1)   
	    echo $throughput >>${PERF_TEST_DATA_FILE}

		# Java type script based perf stat
		hps_java=$(grep "Performance_hps_java_128User_OEF_010" $NS_WDIR/logs/tsr/$TSR_DIR/CurrentDataCSVData.CSV)
		echo ${hps_java} >>${JAVA_PERF_TEST_DATA_FILE}
		throughput_java=$(grep "Performance_throughput_java_128User_OEF_010" $NS_WDIR/logs/tsr/$TSR_DIR/CurrentDataCSVData.CSV)
		echo ${throughput_java} >>${JAVA_PERF_TEST_DATA_FILE}
    fi 
    
    exit 0
}


# Permit only 'automation' user to run test
[ "X${USER}" != "Xnetstorm" ] && echo "ERROR: You must log in with 'netstorm' user" && exit -1


# Store all command line arguments to shell
testSuite="${1}"
debug_opt="${2}"


if [ "$testSuite" == "Performance_Cps" ];then
    suite_conf="Performance_Cps.conf"
elif [ "$testSuite" == "Performance" ];then
    suite_conf="Performance.conf"
else
    suite_conf="Performance_SSL.conf" 
fi

# Execution begins from here 
main
