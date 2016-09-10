import json
import glob
import os
import sys

def get_timings_from_har():
    path = "/home/netstorm/work/logs/TR{}/{}/rbu_logs/harp_files/*.har".format(sys.argv[1], sys.argv[2])
    files = glob.glob(path)
    files.sort(key=os.path.getmtime)
    for file in files:
        f = open(file, 'r')
        data = json.load(f)
        print data["log"]["pages"][0]["pageTimings"][str(sys.argv[3])]


get_timings_from_har()
