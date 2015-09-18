#!/usr/bin/env python 

try:
    import cav_pxssh
except ImportError:
    print 'Error in importing pxssh' 
    exit(101) 


def run(s, command):
    '''Run the command from the child object'''
    s.sendline(command)
    s.prompt(timeout=300) #Somecases needs more time to execute
    print pretty(s.before) 


def pretty(s):
    '''Remove the first line and trailing whitespaces 
    and newline'''
    return '\n'.join(s.strip().split('\r\n')[1:]) 

def connect(host, user, password):
    try:
        s = cav_pxssh.pxssh(timeout=90) 
        s.login(host, user, password)

        return s
    except Exception as e:
        print 'Error connecting'
        print e
        exit(0)


if __name__ == '__main__':
    import sys 
    host    = sys.argv[1] 
    user    = sys.argv[2] 
    passwd  = sys.argv[3] 
    command = sys.argv[4] 

    run(connect(host, user, passwd), command) 
