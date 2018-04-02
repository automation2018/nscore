#!/usr/bin/env python

from jinja2 import FileSystemLoader, Environment
import os
import argparse
import commands
from datetime import datetime, timedelta
from time import gmtime, strftime
import sys

#nde_out_file="/home/netstorm/work/vishal/smoke_build/templates/nde_out_file.html"
#nde_out_file="nde_out_file.html"
core_out_file="core.html"
parser = argparse.ArgumentParser(description='Core finder') 

parser.add_argument(
    '-d', 
    '--directory',
    default=os.getenv('NS_WDIR', '.') ,
   help='directory to look for core files. Defaults to NS_WDIR or current directory'
)

parser.add_argument(
    '-p', 
    '--pattern',
    default='core.',
    help='pattern to search'
)
parser.add_argument(
    '-t', 
    '--timedelta',
    default=12,
    help='time delta in hours. Default is 4 hours'
)
parser.add_argument(
    '-f', 
    '--netstorm',
    default='netstorm',
    help='Netstorm file to check core. Default is bin/netstorm'
)
args = parser.parse_args()

def find_core_on_remote_machine(tot_core):
    try:
        import paramiko
        # Connect to remote host
        client = paramiko.SSHClient()
        client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        client.connect('10.10.30.96', username='root', password='C@VAdmin')

        # Run the transmitted script remotely without args and show its output.
        # SSHClient.exec_command() returns the tuple (stdin,stdout,stderr)
        stdout = client.exec_command('nsi_find_core.py -d "/var/www/hpd"')[1]
        for line in stdout:
            # Process each line in the remote output
            #print line
            tot_core.append(line)

        client.close()
    except IndexError:
        pass

def find(path, pattern, timedel):
    """Searches for core files in given path
    Checks for files with matching pattern and
    if the last modified time is less than four
    hours"""
    timedel = int(timedel)
    # datetime from four hours ago since program start
    ago = datetime.now() - timedelta(hours=timedel)

    # Inner function that checks if the file starts with given pattern
    # and the lastmodified time is as expected
    def iscore(f, pattern, time):
        mtime = datetime.fromtimestamp(os.stat(f).st_mtime)
        isfile = os.path.isfile

        # Filter self, sometimes it may return its own name
        return (pattern in f and not 'nsi_find_core.py' in f) and isfile(f) and (mtime > time)

    # Collect all matchin cores
    cores = [ f for f in map(lambda f: os.path.join(os.path.abspath(path), f), os.listdir(path)) if iscore(f, pattern, ago)]
    #return cores
    core_with_time = {}
    for core in cores:
        ctime = os.path.getctime(core)
        ctime = datetime.fromtimestamp(ctime).strftime('%D %r')
        core_with_time[core] = ctime
    return core_with_time


def main():
    tot_core = []
    
    cores = find(args.directory, args.pattern, args.timedelta)
    file_net=os.path.join(os.getenv('NS_WDIR','.'),'bin',args.netstorm)
    for core in cores:
        out = commands.getoutput('sudo gdb -q -n -ex bt -batch {} {}'.format(file_net, core))
        tot_core.append("{} | {} $$$$ {}".format(cores[core],core ,out.replace('\n', '<br>')))

    cores = find("/home/netstorm/work/lps", args.pattern, args.timedelta)
    for core in cores:
        out = commands.getoutput('sudo gdb -q -n -ex bt -batch {} {}'.format(file_net, core))
        tot_core.append("{} | {} $$$$ {}".format(cores[core],core ,out.replace('\n', '<br>')))
    
    find_core_on_remote_machine(tot_core)
    #print tot_core 
    if len(tot_core) > 0: 
        current_time = strftime("%d/%m/%Y %H:%M:%S")
        env = Environment(loader=FileSystemLoader(os.path.join(os.path.dirname(__file__), 'templates')))
        p = env.get_template(core_out_file)
        print p.render(data=tot_core, tot = len(tot_core), cur_time=current_time, headers=['Created at', 'Core', 'Stack Trace'], )
    else:
        print "No core found"
if __name__ == '__main__':
    main()

