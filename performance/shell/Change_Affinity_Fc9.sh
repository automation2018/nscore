echo 00000003 >/proc/irq/17/smp_affinity
SMP_AFFINITY=`cat /proc/irq/17/smp_affinity`
Configuration=`nsi_get_linux_release_ex -r`
if [ "XX$Configuration" == "9" ]; then
	if [ "$SMP_AFFINITY" == "00000003" ];then 
		echo "assignment sucessful"
	else
		echo "Not sucessful"
	fi
fi
if [ "XX$Configuration" == "1204" ]; then
        if [ "$SMP_AFFINITY" == "3" ];then
                echo "assignment sucessful"
        else
                echo "Not sucessful"
        fi
fi

