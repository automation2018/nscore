import time
import commands
import argparse
import csv
import datetime as dt
import os
import sys

time_record=[]

#Reads csv file to fetch schedule settings applied in the scenario
def get_group_schedule_settings(target_file, group_name):
#    with open('/home/netstorm/Controller_Asheesh/logs/tsr/161125_101954/2035/FSR_GRP_results.csv') as inf:
    with open(target_file) as inf:
        entries_in_csv=inf.readlines();
        test_entry=entries_in_csv[-1].split(',')
        schedule_settings=filter(lambda i: group_name in i, test_entry)
        if 'START' in schedule_settings[1] and 'START' in schedule_settings[2]:
            del schedule_settings[2]
        return schedule_settings

#Calls each phase schedulers 
def get_phase_settings(schedule_keywords, target):
    get_start_phase_timings(schedule_keywords[1], target)
    get_ramp_up_phase_timings(schedule_keywords[2])
    get_duration_phase_timings(schedule_keywords[3])
    get_ramp_down_phase_timings(schedule_keywords[4])
    return time_record


#Start phase scheduler
def get_start_phase_timings(start_phase_schedule, target_file):
    if start_phase_schedule.split(' ')[2] == "IMMEDIATELY":
        time_record.insert(0, '00:00:02')
        time_record.insert(1, '00:00:02')
        time_record.insert(2, '00:00:02')

    elif start_phase_schedule.split(' ')[2] == "AFTER":

        if start_phase_schedule.split(' ')[3] == "TIME":
            time_record.insert(0, '00:00:02')
            time_record.insert(1, calculate_delay_time(start_phase_schedule.split(' ')[4]))
            time_record.insert(2, calculate_delay_time(start_phase_schedule.split(' ')[4]))

        elif start_phase_schedule.split(' ')[3] == "GROUP":
            group_to_wait_for = start_phase_schedule.split(' ')[4]
            st, ramp_down_base=commands.getstatusoutput("python /home/automation/workbench/automation/nscore/smoke/testcases/SmokeTest_FSR_GRP/get_group_phase_estimation.py {} {} 1".format(target_file, group_to_wait_for))
            ramp_down_base=ramp_down_base.split('\n')[-1]
            if len(start_phase_schedule.split(' ')) == 5:
#            if start_phase_schedule.split(' ')[5] == '':
                time_record.insert(0, ramp_down_base)
                time_record.insert(1, ramp_down_base)
                time_record.insert(2, ramp_down_base)
            else:
                time_record.insert(0, ramp_down_base)
                start_time=add_time(ramp_down_base, start_phase_schedule.split(' ')[5])
                time_record.insert(1, start_time)
                time_record.insert(2, start_time)


    return time_record[2]

#Ramp Up phase scheduler
def get_ramp_up_phase_timings(ramp_up_phase_schedule):
    if ramp_up_phase_schedule.split(' ')[3] == 'IMMEDIATELY':
        time_record.insert(3, time_record[2])
        time_record.insert(4, time_record[2])
    elif ramp_up_phase_schedule.split(' ')[3] == 'TIME_SESSIONS':
        ramp_up_end_time=add_time(time_record[2], ramp_up_phase_schedule.split(' ')[4])
        time_record.insert(3,ramp_up_end_time)
        time_record.insert(4,ramp_up_end_time)


#Duration phase scheduler
def get_duration_phase_timings(duration_phase_schedule):
    duration_start=time_record[4]
    duration_end_time=add_time(duration_start, duration_phase_schedule.split(' ')[3])
    time_record.insert(5, duration_end_time)
    time_record.insert(6, duration_end_time)


#Ramp Down phase scheduler
def get_ramp_down_phase_timings(ramp_down_phase_schedule):
    if ramp_down_phase_schedule.split(' ')[3] == 'IMMEDIATELY':
        time_record.insert(7, time_record[6])
    elif ramp_down_phase_schedule.split(' ')[3] == 'TIME_SESSIONS':
        ramp_down_end_time=add_time(time_record[6], ramp_down_phase_schedule.split(' ')[4])
        time_record.insert(7,ramp_down_end_time)

def get_ramp_down_end_time():
    return time_record[7]

def calculate_delay_time(delay_time_given):
    delay_time=delay_time_given.split(':')
    delay_time=map(int, delay_time)
    delay_time=dt.time(delay_time[0],delay_time[1],delay_time[2])
    delta = dt.timedelta(seconds=2)
    delay_time=((dt.datetime.combine(dt.date(1,1,1),delay_time) + delta).time())
    delay_time=delay_time.strftime('%H:%M:%S')
    return delay_time


def add_time(time1, time2):
    time1=time1.split(':')
    time1=map(int, time1)
    time1=dt.time(time1[0],time1[1],time1[2])

    time2 = time.strptime(time2.split(',')[0],'%H:%M:%S')
    time_insec= dt.timedelta(hours=time2.tm_hour,minutes=time2.tm_min,seconds=time2.tm_sec).total_seconds()
    delta=dt.timedelta(seconds = time_insec)
    result=((dt.datetime.combine(dt.date(1,1,1),time1) + delta).time())
    result=result.strftime('%H:%M:%S')
    return result

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('targetfile', help='Results file inside tsr that carries all parameters supplied to scenario')
    parser.add_argument('groupname', help='Name of the group to get phase timing estimation')
    parser.add_argument('dependency', help='1 if it has been called by another group whose start depends on its rampdown time otherwise 0')

    args = parser.parse_args()
    target_group = args.groupname
    target_file = args.targetfile
    group_schedule_settings=get_group_schedule_settings(target_file, target_group)
    group_schedule=get_phase_settings(group_schedule_settings, target_file)
    if args.dependency == '1':
        ramp_down_end_time=get_ramp_down_end_time()
        print ramp_down_end_time
    else:
        for i in group_schedule:

            print i,
