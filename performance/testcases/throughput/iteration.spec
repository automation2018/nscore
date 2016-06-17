$TestDescription|$ScriptName|$User|$OEF|$Wan|$HPM|%Url
#
#
Performance_throughput_128User_OEF_010|script40K|128|0 1 0|0|0|http
#Throughput_128User_OEF_011|script40K|128|0 1 1|0|0|http
#Throughput_128User_OEF_111|script40K|128|1 1 1|0|0|http
Performance_throughput_128User_OEF_010_HPM|script40K|128|0 1 0|0|1|http
Performance_throughput_128User_OEF_011_HPM|script40K|128|0 1 1|0|1|http
Performance_throughput_128User_OEF_111_HPM|script40K|128|1 1 1|0|1|http
#Performance_throughput_128User_OEF_010_WAN_HPM|script40K|128|0 1 0|1|1|http
#Performance_throughput_128User_OEF_011_WAN_HPM|script40K|128|0 1 1|1|1|http
#Performance_throughput_128User_OEF_111_WAN_HPM|script40K|128|1 1 1|1|1|http
#Performance_throughput_128User_OEF_010_WAN|script40K|128|0 1 0|1|0|http
#Performance_throughput_128User_OEF_011_WAN|script40K|128|0 1 1|1|0|http
#Performance_throughput_128User_OEF_111_WAN|script40K|128|1 1 1|1|0|http
#
#Give All Mandatory Fields with Query TYPE NS|QAT_DNS_1Page|NS|203.122.63.152|www.yahoo.com|//ASSERT_RR_TYPE|//ASSERT_RR_DATA

# Performance testcase for throughput using java type script
Performance_throughput_java_128User_OEF_010|JTSScript40K|128|0 1 0|0|0|//
Performance_throughput_java_128User_OEF_HPM_001|JTSScript40K|128|0 1 0|0|1|//
Performance_throughput_java_128User_OEF_HPM_002|JTSScript40K|128|0 1 1|0|1|//
Performance_throughput_java_128User_OEF_HPM_003|JTSScript40K|128|1 1 1|0|1|//
