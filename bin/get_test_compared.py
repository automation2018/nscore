#!/usr/bin/env python

'''
This is a python based utility to comapre current
test runs with baseline test run and provide output  

[INFO]
Currently this deisgn can catter for only one curent
testrun. Will add flexibility to compare more than
one current test run with a baseline test run.

[OUTPUT FORMAT]
The output of this utility is of HTML type. Hence
the output data can be used to mail test data purposes.

To view in browser following steps can be followed.

1. get_test_compared.py -b 1000 -t 1001 >/tmp/somefile.html

2. The same file can be requested in browser to get
   tabulated test comparision data.

[USAGE PURPOSE]
This can be used for performance data automation and represent
MIME type report of NS, ND or other cavisson products. Currently
it is being used for ND performance report automation.

[TODO]
To add some more exceptions handler codes to make it the 
utility more dynamic and self explanatory.
'''

import argparse, sys

TRUN_PATH="/home/netstorm/work/logs"


def parse_arg_values():
    parser = argparse.ArgumentParser()
    parser.add_argument("-b", "--baseline",
                        help="Baseline testrun number",
                        required=True)
    parser.add_argument("-t", "--testrun",
                        help="Comma separated testrun numbers",
                        required=True)

    return parser.parse_args()

def print_usages():
    USAGE = "This is a python utility to be used for command line\n performance data comparision. First argument is baseline\n testrun and second is comma separated current test run numbers.\n\n User can use this as follows:\n\n compare_testrun.py -b 1000 -t 1001"

    print USAGE

class ModelTestData(object):
    def __init__(self, trun, metric, avg, min, max):
        self.trun = trun
        self.metric = metric
        self.avg    = float(avg)
        self.min    = float(min)
        self.max    = float(max)

    def asDict(self):
        perf_data = {
            'trun' : self.trun,
            'metric' : self.metric,
            'avg' : self.avg,
            'min' : self.min,
            'max' : self.max
        }
        return perf_data


class ModelDisplayData(object):
    def __init__(self, trun, metric, cvalue, div):
        self.trun = trun
        self.metric = metric
        self.cvalue = cvalue
        self.div    = div

    def asDict(self):
        display_data = {
            'trun' : {
            'testcase' : self.trun,
            'metric' : self.metric,
            'cvalue' : self.cvalue,
            'div'    : self.div
            }
         }
        return display_data


def get_perf_data(trun):
    l = []
    with open('%s/TR%s/perf.csv' %(TRUN_PATH, trun)) as fp:
        for line in fp:
            metric, avg, min, max = line.strip().split(',') 
            l.append(ModelTestData(trun, metric, avg, min, max).asDict())

    return l


def process_perormance_data(basedata, testlist):
    res = [] 
    
    for d in testlist:
        for e in d:
            trun = e['trun']
	    metric = e['metric']
	    cvalue = e['avg']
	    div = round(abs(basedata[0]['avg'] - e['avg']) / basedata[0]['avg'], 3)
	    displaydata = ModelDisplayData(trun, metric, cvalue, div).asDict()
	    res.append(displaydata)
    
    return res


def get_dynamic_table(current, base):
    trtd = ""
    
    for i, b in zip(range(len(current)), base):
        trtd += "<tr><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>" \
        %(str(current[i]['trun']['metric']), str(b['trun']), str(b['avg']), str(current[i]['trun']['testcase']), str(current[i]['trun']['cvalue']), str(current[i]['trun']['div']))

    return trtd


def get_css():
    css = "<style>th{background-color:black; color: white; text-align: left;}</style>"
    return css


def generate_html_data(base, current):
    html = "<!DOCTYPE html><html><head>"
    html += get_css()
    html += "</head><body><table><tr><th>Metric</th><th>BaseLineTestRun</th><th>BaseLineValue</th><th>CurrentTestRun</th><th>CurrentValue</th><th>Diviation</th></tr>"
    html += get_dynamic_table(current, base) 
    html += "</table></body></html>"
    
    return html


def compare_trun(baseline, current):
    basedata = get_perf_data(baseline)    
    truns = current.split(',')
    testlist = [] 
  
    for trun in truns:
        currentdata = get_perf_data(trun)
        testlist.append(currentdata)

    trdata = process_perormance_data(basedata, testlist)
    print generate_html_data(basedata, trdata)


def main():
    opts = parse_arg_values()
    btrun = opts.baseline 
    ctrun = opts.testrun
    argflag = False    
   
    if btrun and not ctrun:
        print_usages()
    elif not btrun and not ctrun:
        print_usages()
    elif not btrun and ctrun:
        print_usages()
    else:
        argflag = True

    if argflag:
        compare_trun(btrun, ctrun)


if __name__ == '__main__':
    main()
