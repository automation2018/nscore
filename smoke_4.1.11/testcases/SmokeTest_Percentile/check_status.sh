#!/usr/bin/env bash

#source $NS_WDIR/lib/automation_util
#T_NAME=$(get_tname)


#function main(){
#    case $(get_tname) in
#        "SMOKE-037-001") validate_percentile ;;
#        *) handle_unknown_case ;;
#        ?) handle_unknown_case ;;
#    esac
#}
#
#
#function handle_unknown_case(){
#    log_status_and_exit_ex "FAIL" "Testcase not found"
#}


function calculate_percentiledata(){
    b_data=$1
    c_data=$2
    txname=$3
    echo "$b_data"
    echo "$c_data"
    b_data=$(nsi_db_get_obj_data --testrun $1 --object 2 --fields 4095 --status -2 --limit 22 --offset 0)
    c_data=$(nsi_db_get_obj_data --testrun $2 --object 2 --fields 4095 --status -2 --limit 22 --offset 0)
    echo "inside function"
    echo "$b_data"
    echo "$c_data"
    echo "$txname"
    for i in {12,13,14,15};do
        b_value=$(echo "$b_data"|grep "$txname" | awk -F'|' "{print \$$i}")
        c_value=$(echo "$c_data"|grep "$txname" | awk -F'|' "{print \$$i}")
        pct_diff=`echo ${b_value} ${c_value}|awk '{print ($1-$2)/$1*100}'`
        pct_diff=${pct_diff#-}
        echo "b_value=$b_value, c_value=$c_value; pct_diff=$pct_diff "
        [ $i -eq 12 ] && a=80
        [ $i -eq 13 ] && a=90
        [ $i -eq 14 ] && a=95
        [ $i -eq 15 ] && a=99

        [ $(echo "$pct_diff > 5"|bc) -eq 1 ] && exit 1
        #[ $pct_diff -gt 5 ] && log_status_and_exit_ex "FAIL" "Percentile testcase: percentage difference of $a% $txname transaction = $pct_diff"
    done
    return 0

}


function validate_percentile(){
    echo "kkk"
    baselinetr=5143
    currenttr=48144
    #currenttr=${T_RUN_ID}
    #baseline_data=$(nsi_db_get_obj_data --testrun 5143 --object 2 --fields 4095 --status -2 --limit 22 --offset 0)
    #currenttr_data=$(nsi_db_get_obj_data --testrun $currenttr --object 2 --fields 4095 --status -2 --limit 22 --offset 0)
    echo " $baseline_data"
    echo " $currenttr_data"
    for i in {"HighRespTx","LowRespTx","MedRespTx"};do
        echo "$i"
        calculate_percentiledata $baselinetr $currenttr $i
    done

    #log_status_and_exit_ex "PASS" " Percentile testcase passed"
}


#main
validate_percentile


#exit  0
