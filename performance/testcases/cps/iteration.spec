$TestDescription|$ScriptName|$User|$OEF|$Wan|$HPM|%Url
#
#
Performance_cps_128User_OEF_010|scriptTiny|128|0 1 0|0|0|http
#Performance_cps_128User_OEF_011|scriptTiny|128|0 1 1|0|0|http
#Performance_cps_128User_OEF_111|scriptTiny|128|1 1 1|0|0|http
Performance_cps_128User_OEF_010_HPM|scriptTiny|128|0 1 0|0|1|http
Performance_cps_128User_OEF_011_HPM|scriptTiny|128|0 1 1|0|1|http
Performance_cps_128User_OEF_111_HPM|scriptTiny|128|1 1 1|0|1|http
#Performance_cps_128User_OEF_010_WAN_HPM|scriptTiny|128|0 1 0|1|1|http
#Performance_cps_128User_OEF_011_WAN_HPM|scriptTiny|128|0 1 1|1|1|http
#Performance_cps_128User_OEF_111_WAN_HPM|scriptTiny|128|1 1 1|1|1|http
#Performance_cps_128User_OEF_010_WAN|scriptTiny|128|0 1 0|1|0|http
#Performance_cps_128User_OEF_011_WAN|scriptTiny|128|0 1 1|1|0|http
#Performance_cps_128User_OEF_111_WAN|scriptTiny|128|1 1 1|1|0|http
##
##
##Give All Mandatory Fields with Query TYPE NS|QAT_DNS_1Page|NS|203.122.63.152|www.yahoo.com|//ASSERT_RR_TYPE|//ASSERT_RR_DATA

# Performance testcase for cps using java type script
Performance_cps_java_128User_OEF_010|TinyScript|128|0 1 0|0|0|//
Performance_cps_java_128User_OEF_HPM_001|TinyScript|128|0 1 0|0|1|//
Performance_cps_java_128User_OEF_HPM_002|TinyScript|128|0 1 1|0|1|//
Performance_cps_java_128User_OEF_HPM_003|TinyScript|128|1 1 1|0|1|//
