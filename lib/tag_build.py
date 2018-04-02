#!usr/bin/env python
import os
import argparse
import commands

parser = argparse.ArgumentParser(description='Tag build release')

parser.add_argument(
    '-r',
    '--release',
    required=True,
    help="Provide build release and version to tag build like 4.1.7.23"
    )
args = parser.parse_args()


def main():
    buildTagPath = getBuildTagPath(args.release)
    print buildTagPath

    #remove build user from 23 machine
    cmd = "sed -i '/build/d' /net/cvsroot/CVSROOT/readers"
    remuser = "nsu_server_admin -g -i -s '10.10.30.23' -c '{}'".format(cmd)
    st,out = commands.getstatusoutput(remuser) 
    buildTagPath = getBuildTagPath(args.release)
    print buildTagPath
    os.chdir(buildTagPath)
    ####run nsi_tag_release shell like nsi_tag_release -N4.1.7.23
    st,out = commands.getstatusoutput('nohup bash nsi_tag_release -N {} &> /tmp/nohup_tag.out'.format(args.release))
    print out
    if st != 0:
        removeFile = ''
        with open('/tmp/cvs_update_out.log') as f:
            for line in f:
                if not line.startswith('?'):
                    removeFile += line[1:].rstrip()
        
        if removeFile:
            print "conflict files found : %s" %removeFile
            st,out = commands.getstatusoutput('rm -f {}'.format(removeFile))
            if st == 0:
                st,out = commands.getstatusoutput('cvs update {}'.format(removeFile))
                print out
                main()
        else:
            print "unable to remove files"
    else:
        if "Completed cvs tag and changing of version files" in open('/tmp/nohup_tag.out').read():
          
            print "Build tagged successfully"
            #Enable commit for all user
            commitEnable = 'nsu_server_admin -g -i -s"10.10.30.23" -c"bash /net/cvsroot/CVSROOT/commit_write"'
            st,out = commands.getstatusoutput(commitEnable)
            if st == 0:
                print "Commit enable done successfully"
            else:
                print "Error in enabling commit"
        else:
            print "Build tagging failed. Unhandle error"
 
 
def getBuildTagPath(build):
    if os.path.exists('/home/build/work_{}/cavisson/src'.format(build.rsplit('.',1)[0].replace('.',''))):
        return '/home/build/work_{}/cavisson/src'.format(build.rsplit('.',1)[0].replace('.',''))

    else:
        return '/home/build/NSCVS/cavisson/src'


if __name__ == '__main__':
    print "dont tag build"
    main()
