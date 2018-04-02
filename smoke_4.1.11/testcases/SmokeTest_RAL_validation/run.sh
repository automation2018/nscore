#!/bin/bash

# This is for tool run test
Tool=/home/automation/workbench/automation/nscore/smoke/testcases/SmokeTest_RAL_validation/Replay_wells
ns_index_file="${Tool}"/replay_data1/ns_index_0
soap_index_file="${Tool}"/replay_data/replay_data/extracts/SOAP.log.1.txt
echo $Tool

Directory_Path=/home/netstorm/work/scripts/webService_Replay
Scenario_File=/home/netstorm/work/scenarios/webService_Replay.conf

########### Remove Script file if exist before tool run #############
    if [ -d ${Directory_Path} ] ; then 
        rm -rf ${Directory_Path}
        echo "Directory removed"
    else
        echo "Script does not exist"
    fi

############# Remove Scenarion file if exist before tool run #################
    if [ -f ${Scenario_File} ]; then 
        rm -rf ${Scenario_File}
        echo "Scenario file removed"
    else
        echo "Scenario file does not exist"

    fi 

###### Script generation tool ##############    
Tool_Run=$( ${Tool}/ntp_replay_gen  -i  ${Tool}/Replay.conf -f )
#echo $Tool_Run


    if [ -f ${Scenario_File} ]; then
        echo "File exist"
        echo "SERVER_HOST 127.0.0.1 10.10.30.96 -" >> ${Scenario_File}
        echo "Server host added sucessfully inside scenario file"
    else
        echo "Scenario file does not exist"
    fi


function read_ns_indexFile(){
    while read -r line
    do
        data=$line
        data1=$(echo "${data}" | cut -d ',' -f 1,3)
        echo "${data1}"
    done < ${ns_index_file}

}

function read_Soap_Log_File(){
    while read -r line
    do 
        data=${line}
        data1=$(echo "${data}" |grep -o "RequestTimeEx=.*\|<ns[1-9]:XACustId>.*</ns[1-9]:XACustId>" |egrep -o "[0-9.]+[0-9.]")
        echo "${data1}"
    done < ${soap_index_file}
}


data2=($(read_Soap_Log_File))
>file.in
for i in ${data2[@]}
do
     awk "BEGIN { printf(\"%.0f\n\", $i); }"|tee -a file.in 
done
cat file.in | sed "N;s/\n/,/" > file.out

>file.in
i=0
baseReqTime=
for line in $(cat file.out); do
    id=$(cut -d , -f 2 <<< $line)
    reqTime=$(cut -d , -f 1 <<< $line)
    if [ $i -eq 0 ]; then
        baseReqTime=$reqTime
        echo "$id,0"|tee -a file.in
        i=$((i+1))
        continue
    fi
    timeDiff=$(((reqTime - baseReqTime)*1000))
    echo "$id,$timeDiff"|tee -a file.in
done

data1=($(read_ns_indexFile))
for i in "${data1[@]}";
do 
    for line in $(cat file.in);
    do
        if [ "$i" ==  "$line" ];then
            echo "PASS"
        fi
    done
done

