#!/usr/bin/env python
import os
import re
import locale
import argparse

PHASE_DURATION_START = "Starting phase 'Duration'"
PHASE_DURATION_END = "Phase 'Duration'" 
KEYWORD_TCP_CONNS = "HTTP TCP Conns"
KEYWORD_HITS_PER_SEC = "HTTP hit rate (per sec):"
KEYWORD_THROUGHPUT = "HTTP (Kbits/s)"

# Set the local first. We can use this to convert string with comma
# separated numbers to simple integers
locale.setlocale(locale.LC_ALL, 'en_US.UTF8')
atoi = locale.atoi

# HTTP TCP Conns: Current=7 Rate/s(Open=83 Close=82) Total(Open=61,052 Close=61,045)
regexp_cps = re.compile('HTTP TCP Conns: Current=[\d,]+ Rate/s\(Open=([\d,]+) Close=[\d,]+\)') 

# HTTP hit rate (per sec): Total=59,156 Success=59,156
regexp_hps = re.compile('HTTP hit rate \(per sec\): Total=([\d,]+) Success=[\d,]+')

# Throughput (Kbits/s): Eth(Rx=194,723.235 Tx=170,336.385)
#regexp_throughput = re.compile('Throughput \(Kbits/s\): Eth\(Rx=([\d,.]+) Tx=[\d,.]+\)')
regexp_throughput = re.compile('HTTP \(Kbits/s\) TCP\(Rx=([\d,.]+) Tx=([\d,.]+)\) HTTP Body\(Rx=([\d,.]+)\)')

# List to hold all stats
stats = []


def process(line, metric_type=1):
    """Matches each line with given regex and appends to the global 
    stats buffer. Each item in the stats list is a 3 item tuple which 
    consists of current, opened and closed connections values"""
    if metric_type == 1:
        if line.startswith(KEYWORD_TCP_CONNS):
            match = regexp_cps.match(line)
            if match is not None:
                stat = match.group(1)
                stats.append(atoi(stat))
                # Add in following format [(current, opened, closed), (current, opened, closed)]
    elif metric_type == 2:
        if line.startswith(KEYWORD_HITS_PER_SEC):
            match = regexp_hps.match(line)
            if match is not None:
                stat = match.group(1)
                stats.append(atoi(stat))
    elif metric_type == 3:
        if line.startswith(KEYWORD_THROUGHPUT):
            match = regexp_throughput.match(line)
            if match is not None:
                stat = match.group(1)
                stats.append(int(locale.atof(stat)))


def main(report, metric_type):
    """Reads the report file line by line and print outs the 
    average of current, opened and closed tcp connections"""
    
    with open(report) as f:
        start_processing = False
        for line in f:
            if line.startswith(PHASE_DURATION_START): start_processing = True
            if line.startswith(PHASE_DURATION_END): 
                start_processing = False
                # No need to read remaining file
                break
            if start_processing is True: process(line.strip(), metric_type)
        
    return (avg(stats))


def avg(seq):
    """Calculates average for a given sequence
    Sequence should be a list of integers"""
    if seq is None or len(seq) == 0:
        return 0
    return sum(seq)/len(seq)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-t', '--testrun', help='the testrun number')
    parser.add_argument(
        '-m', 
        '--metric', 
        default=1, 
        type=int, 
        help='the metric type: 1- CPS 2-HPS 3-THROUGHPUT'
    )
    args = parser.parse_args()
    
    if args.testrun is None:
        exit(parser.print_help())

    progress_report = os.path.join(
        os.getenv('NS_WDIR'), 
        'logs', 
        'TR' + args.testrun, 
        'progress.report'
    ) 
    
    if not os.path.exists(progress_report):
        exit('Progress report is not available for TR%s' % args.testrun)
    
    avg_stat = main(progress_report, args.metric)
    print avg_stat

