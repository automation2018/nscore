#!/usr/bin/env bash

# Include  libraries
source $NS_WDIR/lib/automation_util
source $NS_WDIR/lib/automation_config.dat 

# Bootstraps the automation test specific variables
function init() {
    CUR_DIR=$(pwd)

    # Get Release Specific Information
    RELEASE=$(cat $NS_WDIR/etc/version |grep VERSION| cut -d " "  -f2| cut -d . -f1,2,3)
    MAJOR=$(cat $NS_WDIR/etc/version | head -1 |cut -d "." -f4)
    MINOR=$(cat $NS_WDIR/etc/version | tail -1  | cut -d " " -f2)

    # Results directory to store the automation result.
    R_DIR="${CUR_DIR}/results/$RELEASE/${MAJOR}.${MINOR}"

    # Create results workbench if not exists
    [ ! -d "${R_DIR}" ] && mkdir -p "${R_DIR}"

    # Temporary File
    TEMP_FILE=/tmp/ns_run.$$

    # Result File.
    CYCLENO=$(get_cycle_num)
    R_FILE="${R_DIR}/${testSuite}_${CYCLENO}.txt"
    XML_FILE="${R_DIR}/${testSuite}_${CYCLENO}.xml"

    export R_FILE
    export XML_FILE
    export TEMP_FILE
}


# Using bin/ts_run to start testsuite
function run(){
    testSuite="$1"            
    debug_opt="$2"            

    # Changing directory location to ns_wdir
    cd $NS_WDIR

    echo "Starting NSCore smoke automation suite using command bin/ts_run"
    echo "Running TestSuite = '$testSuite'"

    # running test in backend
    Project=$(project_name $testSuite)
    echo "Project name is=$Project"
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

    # Set currently finshed testsuite summary 
    set_test_summary_ex
    
    # Changing directory location back to automation_wdir
    cd - >/dev/null
}


# Cleans up temporary files
function clean_up(){
    echo "Cleaning up temporary files"
    rm -f ${TEMP_FILE}
}


# To copy TR's in current directory logs folder.
# Only when --debug option is passed while running the shell;
function copy_logs(){
    [ ! -d ${CUR_DIR} ] && mkdir -p ${CUR_DIR}/logs

    sleep 1
    
    for trNum in $(grep TestRun ${TEMP_FILE} |awk -F'=' '{print $2}')
    do
	if [ -d $NS_WDIR/logs/TR${trNum} ];then
	  debug_log "Debug: Copying test runs to ${CUR_DIR}/logs"
	  cp -r $NS_WDIR/logs/TR${trNum} ${CUR_DIR}/logs/
	  
          debug_log "Copied TR${trNum}"
	
        else
	  debug_log "TestRun not found"
	fi
    done
}


#  Returns count of testcases to run in current testsuite
function get_test_case_count() {
  testcases=$(cat testsuites/${testSuite}.conf |grep -v "#" | cut -d ' ' -f2)
  count=0
  for testcase in ${testcases}
  do
    i=$(grep -ci "^SMOKE-" testcases/${testcase}/iteration.spec)
    count=$(($count + $i))
  done
  echo ${count}
}


# Provides info about total testcase executed &
# numbers of NSFail testcases
function update_test_status() {
    cycle_num="$1"
    NSFailCount=$(grep -c "NetstormFail" $NS_WDIR/logs/tsr/${cycle_num}/cycle_summary.report)
    TotalExecuted=$(get_test_case_count)
    echo "NSFailCount=$NSFailCount" >/tmp/last
    echo "TotalExecuted=$TotalExecuted" >>/tmp/last
}


# Execution begins from here
function main() {
    # Bootstraps the automation test specific variables
    echo "Initializing test environment "
    init

    # Display testcase count
    echo "Total Cases to test in ${testSuite} suite = $(get_test_case_count)"

    #This function creates the header for result file.
    set_results_header_ex

    #Call to run  to start automation
    run "${testSuite}" "${debug_opt}"

    # TODO
    # Variable to use update_test_status module 
    # To get total and nsfail testcase count
    TSR_DIR=$(grep "Test Cycle Number" ${TEMP_FILE} | egrep -o [0-9_]+)

    # Cleans up tmporary files
    clean_up

    # Check cycle summary report file and append total test run executed
    # check for netstorm failed cases and update the count
    update_test_status "${TSR_DIR}"

    # Module called to upload testresults to sqlite database
    echo "Uploading results to remote database"
    #${DB_UPLOAD} -r ${RELEASE} -v ${MINOR} -f ${R_FILE}
    exit 0
}


# Permit only 'automation' user to run test
[ "X${USER}" != "Xnetstorm" ] && echo "ERROR: You must log in with 'netstorm' user" && exit -1


# Store all command line arguments to shell
testSuite="${1}"
debug_opt="${2}"


# Call to main function
main
