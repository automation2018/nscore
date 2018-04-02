import argparse
cluster_num=[]

def get_groups_scheduled(csv):
    with open(csv) as inf:
        entries_in_csv=inf.readlines();
    test_entry=entries_in_csv[-1].split(',')
    cluster_num.append(entries_in_csv[-1] .split(',')[4].split(' ')[1])
    scheduled_groups=filter(lambda i: 'SGRP' in i, test_entry)
    for entry in scheduled_groups:
        cluster_num.append(entry.split(' ')[8])
    unique_clusters=set(cluster_num)
    return unique_clusters

def get_unique_group_count(csv):
    uniq_groups = get_groups_scheduled(csv)
    print len(uniq_groups)

def get_matching_group_indices(csv):
    uniq_groups = get_groups_scheduled(csv)
    for group in uniq_groups:
        indices = [str(i) for i, x in enumerate(cluster_num) if x == group]
        print '%s|%s' %(group, ','.join(indices))

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('targetfile', help='/$HOME/Controller/logs/tsr/tsr_num/cycle_num/Testcase_results.csv')
    parser.add_argument('action', help='0- if number of unique groups is required & 1- if names of groups are required')

    args = parser.parse_args()
    target_csv = args.targetfile
    if args.action == '0':
        get_unique_group_count(target_csv)
    if args.action == '1':
        get_matching_group_indices(target_csv)
