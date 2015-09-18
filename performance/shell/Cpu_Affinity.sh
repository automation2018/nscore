#!/bin/bash
Configuration=`nsi_get_linux_release_ex -d`
Version=`nsi_get_linux_release_ex -r`
Conf_Version=${Configuration}_${Version}
echo "Conf_version is=$Conf_Version"
	if [ $Configuration == Fedora_9 ]; then
        	#For NS 37
		nsu_server_admin -s QANSRegression -F /home/arun_QA/cavisson/automation/Performance/LgPerformance/shell/Change_Affinity_Fc9.sh -D /tmp
		nsu_server_admin -s QANSRegression -c 'sh /tmp/Change_Affinity_Fc9.sh'
        	if [ $? == 0 ]; then
			echo "Shell executed sucessfully on 37 server"
		else
			echo "Not sucessfully executed"
			exit -1
		fi
		#For NO 38
		nsu_server_admin -s QANORegression -F /home/arun_QA/cavisson/automation/Performance/LgPerformance/shell/Change_Affinity_Fc9_38.sh -D /tmp
                nsu_server_admin -s QANORegression -c 'sh /tmp/Change_Affinity_Fc9_38.sh'	
			if [ $? == 0 ]; then
                		echo "Shell executed sucessfully on 38 server"
                	else    
                		echo "Not sucessfully executed"
                		exit -1 
                	fi
	fi	
	
		
	if [ "$Conf_Version" == "Fedora_14" ]; then
	
       		#For NS 81
       		nsu_server_admin -s QANS4 -F /home/automation_QA/cavisson/automation/Performance/LgPerformance/shell/Change_Affinity_Fc14.sh -D /tmp
		nsu_server_admin -s QANS4 -c 'sh /tmp/Change_Affinity_Fc14.sh' 
       			if [ $? == 0 ]; then
            		    echo "Shell executed sucessfully on 81"
                	else    
                		echo "Not sucessfully executed"
                		exit -1 
                	fi
		#For NO 82
                nsu_server_admin -s QANO4 -F /home/automation_QA/cavisson/automation/Performance/LgPerformance/shell/Change_Affinity_Fc14_82.sh -D /tmp
		nsu_server_admin -s QANO4 -c 'sh /tmp/Change_Affinity_Fc14_82.sh'
			if [ $? == 0 ]; then
               		   	 echo "Shell executed sucessfully on 82 server"
               		 else    
                		echo "Not sucessfully executed"
                		exit -1 
                	fi
	fi

	if [ "$Conf_Version" == "Ubuntu_1204" ]; then
	
		nsu_server_admin -s NS -F /home/automation_QA/cavisson/automation/Performance/LgPerformance/shell/Change_Affinity_Fc9.sh -D /tmp
                nsu_server_admin -s NS -c 'sh /tmp/Change_Affinity_Fc9.sh'
                if [ $? == 0 ]; then
                        echo "Shell executed sucessfully on 39 ubuntu server"
                else
                        echo "Not sucessfully executed"
                        exit -1
                fi
                nsu_server_admin -s NO -F /home/automation_QA/cavisson/automation/Performance/LgPerformance/shell/Change_Affinity_Fc9_38.sh -D /tmp
                nsu_server_admin -s NO -c 'sh /tmp/Change_Affinity_Fc9_38.sh'
                        if [ $? == 0 ]; then
                                echo "Shell executed sucessfully on 40 ubuntu server"
                        else
                                echo "Not sucessfully executed"
                                exit -1
                        fi

	fi
		
