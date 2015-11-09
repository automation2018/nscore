#!/usr/bin/env python
# Name                 : upgradeAagent.py
# Author               : nirajKpanda (git username) [ mailto : nirajpanda@outlook.com]
# Purpose              : Python Utility To Manage installations of NetStorm Builds from BuildHub
# Point Of Inspiration : easy_upgrade ruby utility
# Credit               : Ankur Sir 
import re
import os
import sys
import platform
import urllib
import urllib2
from BeautifulSoup import BeautifulSoup
import subprocess
from common import grep
import argparse

BASE_URL = "http://10.10.30.16:8000"


# Main class definition which can invoke all build processes
class UpgradeTools(object):
    # Initialization of class level variables
    def __init__(self, base_url, upgrade_dir, release=None, force_download=False):
        self.base_url       = base_url
        self.upgrade_dir    = upgrade_dir
        self.release        = release
        self.force_download = force_download

    
    # Module for getting specific build file 
    def do_search(self):
        soup = BeautifulSoup(urllib2.urlopen(BASE_URL).read())
        soup = soup.prettify()
      
        # Regular expression pattern for finding matched href string    
        # Info : () in re is used to colloect values 
        pattern = re.compile(r'<a id=\".+?\" title=\"Download\" data-toggle=\"tooltip\" data-placement=\"left\" class=\"btn btn-default\" href=\"(.+?)\">')
       

        # Find all matches and select the file as per user input 
        matches = pattern.findall(soup) 
        
        return matches

 
    # Module for download the build files
    def download_matches(self, matches):
        # Get linux distribution of underlying OS
        # NS BUILD SIGNATURE : self.release(first 3)/netstorm_all.release.distro*index*_64.bin
        # THIRDAPRTY BUILD SIGNATURE : self.release(first 3)/thirdparty.release_distro*index*_64.bin
        distro = platform.dist()[0]
        if distro == 'Ubuntu':
            ns_bin_sign = self.release[0:5:] + "/" + "netstorm_all." + self.release + ".Ubuntu1204_64.bin"
            tp_bin_sign = self.release[0:5:] + "/" + "thirdparty." + self.release + "_Ubuntu1204_64.bin"
        else:
            ns_bin_sign = self.release[0:5:] + "/" + "netstorm_all." + self.release + ".Fedora14_64.bin"
            tp_bin_sign = self.release[0:5:] + "/" + "thirdparty." + self.release + "_Fedora14_64.bin"

        links = []

        for match in matches:
            if match == ns_bin_sign or match == tp_bin_sign:
                links.append(match)
   
        for link in links:
            print "Going to download %s file from build server ...." %(os.path.basename(link))
            urllib.urlretrieve(BASE_URL + "/" + link, os.path.basename(link))
   
        bins = []
        for link in links:
            bins.append(self.upgrade_dir + "/" + os.path.basename(link))
        
        return bins

    
    # Modulr for making build files executables
    # This also checks the current dir and set the upgrade path
    def initiate_installations(self, bins):
        
        print "Changing modes of netstorm buid binaries...."
  
        for file in bins:
            subprocess.call(["chmod", "+x", os.path.basename(file)])
            print os.path.basename(file) + " made executable"
    
        print "Changing directory to %s" %(self.upgrade_dir)
        os.chdir(self.upgrade_dir)

        pwd = subprocess.check_output('pwd')
        print "PWD is : %s" + pwd

        ns_bin = grep(bins, '.*(netstorm_all).*.bin')
        tp_bin = grep(bins, '.*(thirdparty).*.bin')

        print "Available thirdparty file is " + tp_bin[0]
        print "Available netstorm file is " + ns_bin[0]
        
        
        print
        print   

        print "Installing thirdparty build"
        status = subprocess.call('./' + os.path.basename(tp_bin[0]))
    
        if status != 0:
            print "Installation failed"
        else:
            print "Installation successfully finished"
        
        print "Installing netstorm build"
        status = subprocess.call('./' + os.path.basename(ns_bin[0]))
        
        if status != 0:
            print "Installation failed"
        else:
            print "Installation successfully finished"
       
        print
        print   
   
        print "Changing directory back to workbanch /home/netstorm/Tejas/self-workplace/py-codes/easy_upgrade_image/PyUpgrade"
        os.chdir('/home/netstorm/Tejas/self-workplace/py-codes/easy_upgrade_image/PyUpgrade')
        
        pwd = subprocess.check_output('pwd')
        print "PWD is : %s" + pwd
 
        print "Build installation Over :):) HAPPY TESTING"


def main():
    ut = UpgradeTools(BASE_URL, "/home/netstorm/work/upgrade", "4.1.3.40", True)
    matches = ut.do_search()
    bins = ut.download_matches(matches)
    
    # TODO check pwd and change to upgrade dir if not in upgrade dir
    ut.initiate_installations(bins)
  

if __name__ == '__main__':
    main()
