#!/usr/bin/env bash


export NS_WDIR="/home/netstorm/work"
source /etc/bash.bashrc
TMP_LOG_FILE=/tmp/nde_start_test.log
>${TMP_LOG_FILE}


function get_running_trun(){
    run_string=$(nsu_show_netstorm)
	trun=$(egrep -o '[0-9]+' <<<$run_string)

	if [ -z ${trun} ];then 
		echo "No test is running.Hence exiting"
	else
	    echo $trun
	fi
}


function stop_running_test(){
    trun=$1
    echo "Going to stop the test gracefully"
	nsu_stop_test -s $trun
    echo "Triggered stop test command going to sleep for 20 seconds"
	sleep 120
    run_string=$(nsu_show_netstorm)
	print "run string after stopping and waiting for 60 seconds"
	print ${run_string}
	
	if [ -z ${run_string} ];then
		echo "Successfully stopped $trun test"
	else
		echo "Error while stopping the test $trun"
    fi
}


function start_nde_test(){
    echo "Working controller:"$NS_WDIR
	su ndeadmin -c "nsu_start_test -n monitoring.conf -S gui "| tee ${TMP_LOG_FILE}
    sleep 60
    get_running_trun
}


what_to_do=$1

if [ "${what_to_do}" == "status" ]; then
	get_running_trun
elif [ "${what_to_do}" == "stop" ]; then
    trun=$(get_running_trun)
	if [ ! -z ${trun} ]; then 
	    stop_running_test $trun
	else
		echo "currently no test is running.exiting...."
		exit 0
	fi
elif [ "${what_to_do}" == "start" ]; then 
	start_nde_test
else
	echo "Invalid arguments. Please check."
fi
