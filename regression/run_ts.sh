#!/usr/bin/env bash

# Include  libraries
source $NS_WDIR/lib/automation_util
source $NS_WDIR/lib/automation_config.dat

init() {
  CUR_DIR=$(pwd)
  #Get Release Specific Information
  RELEASE=$(cat $NS_WDIR/etc/version |grep VERSION| cut -d " "  -f2| cut -d . -f1,2,3)
  MAJOR=$(cat $NS_WDIR/etc/version | head -1 |cut -d "." -f4)
  MINOR=$(cat $NS_WDIR/etc/version | tail -1  | cut -d " " -f2)

  #Results directory to store the automation result.
  R_DIR="${CUR_DIR}/results/$RELEASE/${MAJOR}.${MINOR}"

  mkdir -p "${R_DIR}"

  #Temporary File.
  T_FILE=/tmp/ns_run.$$

  #Result File.
  CYCLENO=$(get_cycle_num)
  R_FILE="${R_DIR}/${testSuite}_${CYCLENO}.txt"
  XML_FILE="${R_DIR}/${testSuite}_${CYCLENO}.xml"
  
  export R_FILE
  export XML_FILE
}

run(){
# Waits till successfull completion message is not recieved.
    testSuite="$1"            #placeholder to store the current running test suite
    debug_opt="$2"            #placeholder to store debug

    cd $NS_WDIR

    echo "INFO: Starting automation using command bin/ts_run"
    echo "INFO: Running TestSuite = '$testSuite'"
    
    Project=$(project_name $testSuite)
    echo "Project=${Project}"
    # running test in backend
      bin/ts_run -n ${Project}/${testSuite} #${ND_DEBUG_OPT}


    #Check return code. If RC=2, automation timed out case. RC=0 Success
    RC=$?

    [ $RC -ne 0 ] && {
       echo "ERROR: Possible test case failure. Check logs..."
       # Don't cleanup here.. 
    } || {
       echo "INFO: NSCore automation has ended"
    }

    [ "X$debug_opt" == "X--debug" ] && {
       copy_logs
     }
    
    set_test_summary_ex
}

# Cleanup function. To remove temporary files if being used.
clean_up()
{
    echo "INFO: Cleaning up temporary files."
    rm -f ${T_FILE}
}

# To copy TR's in current directory logs folder.
# Only when --debug option is passed while running the shell;
copy_logs(){
    cur_dir=`pwd`
    mkdir -p ${CUR_DIR}/logs

    sleep 1
    for trNum in $(grep TestRun ${T_FILE} |awk -F'=' '{print $2}')
    do
        if [ -d $NS_WDIR/logs/TR${trNum} ];then
          echo "DEBUG: Copying test runs to ${CUR_DIR}/logs"
          cp -r $NS_WDIR/logs/TR${trNum} ${CUR_DIR}/logs/
          echo "DEBUG: Copied TR${trNum}"
        else
          echo "ERROR: TestRun not found"
        fi
    done
}

#To get the test case count
get_test_case_count() {

  testcases=$(cat testsuites/${testSuite}.conf |grep -v "#" | cut -d ' ' -f2)
  count=0
  for testcase in ${testcases}
  do
    i=$(grep -c "^REG" testcases/${testcase}/iteration.spec)
    count=$(($count + $i))
  done
  echo ${count}
}


#Execution begins here
main() {
    #Setup enviroment for netdiagnostics automation suite.
    echo "INFO: Initializing test environment "
    init

    #display test case count
    echo "Total Cases to test in ${testSuite} suite = $(get_test_case_count)"

    #This function creates the header for result file.
    set_results_header_ex

    #Call to run  to start automation
    run "${testSuite}" "${debug_opt}"

    #Cleans up tmp files
    clean_up

    #Parse the txt file and create results in xml format- NEW
    echo "INFO: Writing testresults in XML format to ${XML_FILE} "
    ${PYTHON_TOOL} -i "${R_FILE}" -o "${XML_FILE}" -f $(get_failed_test_count) -p $(get_passed_test_count) -t $(get_total_test_count)

    #Uploads test results to sqlite database
    echo "INFO: Uploading results to $DATABASE"
    ${DB_UPLOAD} ${R_FILE} ${DATABASE}

    exit 0
}


#Permit only 'automation' user to run test
[ "X${USER}" != "Xautomation" ] && echo "ERROR: You must log in with 'automation' user" && exit -1

#Store all command line arguments to shell
testSuite="${1}"
debug_opt="${2}"

#Calling main
main
