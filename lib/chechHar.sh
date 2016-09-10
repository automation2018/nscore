#! /bin/bash
TR_NUM=44930
PARTITION=20160822152040

while read x y
do
    metric=$x
    metric_position=$y
    csvData=( $(cut -d ',' -f $metric_position /home/netstorm/work/logs/TR${TR_NUM}/${PARTITION}/reports/csv/PageRBUDetailRecord.csv) )
    i=0
    for line in $(python parseHar.py $TR_NUM $PARTITION $metric)
    do
        if [ $line -ne ${csvData[i]} ]; then
            echo "FAIL"
            exit 1
        fi
        i=$i+1
    done
done < rbu_params
echo "PASS"
