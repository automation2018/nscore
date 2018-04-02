# nscore
NetStorm : A real time load generator tool in the web application space.

'nscore' stands NetStorm Core. Hence this repository is meant for the core 
automation of NetStorm product. 

Core automation includes Smoke(functional testing), Regression testing and 
Performance testing.

Technologies Used:
1. UNIX BASH scripting
2. Python Scripting
3. Ruby Scripting
4. ANT : Another Neat Tool (Apache framework for workflow management) 
5. FLASK framework for designing ANALYTICS UI 
6. sqlite Database to store and manipulating test data

Directory Structure :
1. bin/  --> includes all required shell codes
2. build.xml --> ANT build file to regulate entire core automation
3. conf/  --> includes all client-server configuration files
4. lib/ --> includes libraries files, analytics.db and other automation meaningful utilities
5. logs/ --> includes debug and error log files, version info log files
6. performance/ --> home directory for NS performance automation
7. regression/ --> home directory for NS regression automation
8. smoke/ --> home directory for NS smoke automation

Additional drilled down of directory structre of each categories of 
tests(performance, regression, smoke) provided below is the representation 
of directory structure of smoke tests, all other test metrices have same 
directory structure in them.

smoke/ 
     --> build.xml -------------- smoke automation build file 
     --> build.properties ------- properties or values are defined here used in build.xml file
     --> mail.properties -------- properties or values are defined here used in build.xml file for mail triggering
     --> run_ts.sh -------------- this is a wrapper shell to ts_run to control automation
     --> update_mail_presetup --- automation initiation acknoledgment shell; it updates mail.proerties file as per test data
     --> update_mail_results ---- automation test results acknoledgment shell; it updates mail.proerties file as per test data
     --> results/ --------------- result directory stores test result as per release and build 
     --> scripts/ --------------- includes all test scripts used in test configuration
     --> scenarios/ ------------- includes all test configuration files
     --> testcases/ ------------- includes all testcases as per features 
                                  [ Note : person alligned to automation processes should be acquinted with this more] 
     --> testsuites/------------- includes test suite files in which testcases are mentioned to run test
