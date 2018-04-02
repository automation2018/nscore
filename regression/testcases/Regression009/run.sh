#!/bin/bash

# This is for tool run test
Tool=/home/automation/workbench/automation/nscore/regression/testcases/Regression008/Replay_wells

echo $Tool
Tool_Run=$( ${Tool}/ntp_replay_gen  -i  ${Tool}/Replay.conf -f )
echo $Tool_Run

Scenario_File=/home/netstorm/work/scenarios/Regression/Regression/webService_Replay.conf

if [ -f ${Scenario_File} ]; then
    echo "File exist"
    echo "SERVER_HOST 127.0.0.1 10.10.30.96 -" >> ${Scenario_File}
    
    Directory_Path=/home/automation/workbench/automation/nscore/regression/scripts/webService_Replay/
    if [ -d ${Directory_Path} ]; then
        rm -rf /home/automation/workbench/automation/nscore/regression/scripts/webService_Replay/
        echo "directory removed"
        mv -f  /home/netstorm/work/scripts/Regression/Regression/webService_Replay/  /home/automation/workbench/automation/nscore/regression/scripts/
        echo "script moved"
    else
        mv -f  /home/netstorm/work/scripts/Regression/Regression/webService_Replay/  /home/automation/workbench/automation/nscore/regression/scripts/
        echo "script moved"
    fi

     mv -f  /home/netstorm/work/scenarios/Regression/Regression/webService_Replay.conf /home/automation/workbench/automation/nscore/regression/scenarios/
     echo "scenarion moved"
else
    echo "File does not exist"
fi


