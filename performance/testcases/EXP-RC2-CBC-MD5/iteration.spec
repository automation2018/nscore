$TestDescription|$ScriptName|$User|$OEF|$Wan|$HPM|%Url|$Ciphers|$KA_PCT|$NUM_KA
#
#CPS evaluation Testcase for ssl based NS requests
EXP-RC2-CBC-MD5_CPS|scriptTiny|128|0 1 0|0|0|https|EXP-RC2-CBC-MD5|G_KA_PCT ALL 0|G_NUM_KA ALL 1 1
#HPS evaluation Testcase for ssl based NS requests
EXP-RC2-CBC-MD5_HPS|scriptTiny|128|0 1 0|0|0|https|EXP-RC2-CBC-MD5|G_KA_PCT ALL 100|G_NUM_KA ALL 0 0
#Throughput evaluation Testcase for ssl based NS requests
EXP-RC2-CBC-MD5_TPUT|script40K|128|0 1 0|0|0|https|EXP-RC2-CBC-MD5|G_KA_PCT ALL 100|G_NUM_KA ALL 0 0
