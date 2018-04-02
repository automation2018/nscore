import datetime as dt
import time
import argparse
#Change if start phase is not immediate
phase_schedule=["00:00:02", "00:00:02"]


def get_schedule(scenario):
    with open(scenario) as inf:
        entries = inf.readlines();
        schedule_settings=filter(lambda i:i.startswith('SCHEDULE '), entries)
    for line in schedule_settings:
        phase_name = line.split(' ')[3]
        if phase_name == 'START':
            phase_op = phase_schedule[0] +','+ phase_schedule[1]
        elif phase_name == 'RAMP_UP':
            phase_op = get_ramp_up_schedule(line)
        elif phase_name == 'DURATION':
            phase_op = get_duration_schedule(line)
        elif phase_name == 'RAMP_DOWN':
            phase_op = get_ramp_down_schedule(line)


def get_ramp_up_schedule(schedule):
    phase_schedule.append(phase_schedule[-1])
    if schedule.split(' ')[5].strip() == 'IMMEDIATELY':
        phase_schedule.append(phase_schedule[-1])
    elif schedule.split(' ')[5] == 'TIME_SESSIONS':
        ramp_up_end = add_time(phase_schedule[-1], schedule.split(' ')[6])
        phase_schedule.append(ramp_up_end)
    return phase_schedule[-2] +','+phase_schedule[-1]


def get_duration_schedule(schedule):
    phase_schedule.append(phase_schedule[-1])
    duration_end = add_time(phase_schedule[-1], schedule.split(' ')[5].strip())
    phase_schedule.append(duration_end)
    return phase_schedule[-2] +','+phase_schedule[-1]


def get_ramp_down_schedule(schedule):
    phase_schedule.append(phase_schedule[-1])
    if schedule.split(' ')[5].strip() == 'IMMEDIATELY':
        phase_schedule.append(phase_schedule[-1])
    elif schedule.split(' ')[5] == 'TIME_SESSIONS':
        ramp_down_end = add_time(phase_schedule[-1], schedule.split(' ')[6])
        phase_schedule.append(ramp_down_end)
    return phase_schedule[-2] +','+phase_schedule[-1]


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
    parser = argparse.ArgumentParser();
    parser.add_argument('scenariofile', help='Path to scenario file carrying all schedule settings')
    args = parser.parse_args()
    scenario = args.scenariofile
    get_schedule(scenario)
    print " ".join(phase_schedule)
