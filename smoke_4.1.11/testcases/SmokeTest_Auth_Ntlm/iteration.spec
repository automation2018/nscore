$Test_Name|$Script_Name|$Users|$Sessions|$Version|%Url|%Username|%Password|$PageDump|$KeepAlive|%UrlSVC|$Idle_Msec

#In case of using file param to parametirized the value of username/password while the refresh mode is session
#Smoke_Http_auth_Ntlm_apache_main_param_session|MainUrlAuth_Cmode_Param_Session_Ntlm|1|1|0|http|arun_QA|arun|#|#
#SMOKE-018-001|MainUrlAuth_Cmode_Param_Session_Ntlm|1|1|0|http|arun_QA|arun|#|#|#|#|#

################Testcases with service of HPD
# verify the authentication for NTLMCase OK
SMOKE-018-002|AUTH_NTLM|1|1|1|http|arun|arun|#|#|?SvcTime=10&TestCase=OK|#

#verify the authentication for NTLMCase T0Fail
SMOKE-018-003|AUTH_NTLM|1|1|1|http|arun|arun|#|#|?SvcTime=10&TestCase=T0Fail|#

#verify the authentication for NTLMCase T1Fail
SMOKE-018-004|AUTH_NTLM|1|1|1|http|arun|arun|#|#|?SvcTime=10&TestCase=T1Fail|#

#verify the authentication for NTLMCase T3Fail
SMOKE-018-005|AUTH_NTLM|1|1|1|http|arun|arun|#|#|?SvcTime=10&TestCase=T3Fail|#

#verify the authentication for NTLMCase T3FailNoNTLMHdr
SMOKE-018-006|AUTH_NTLM|1|1|1|http|arun|arun|#|#|?SvcTime=10&TestCase=T3FailNoNTLMHdr|#


#################Netstorm to Apache Server

#verify the authentication for NTLM if only main URL is having authentication and inline dont
#SMOKE-018-007|auth_ntlm_apache|1|1|1|http|ntlm|ntlm|#|#|10.10.30.97:81/tours/index.html|#

#verify the authentication for NTLM if main URL and embedded URL is having authentication
#SMOKE-018-008|auth_ntlm_apache|1|1|1|http|ntlm|ntlm|#|#|10.10.30.97:8802/tours/NTLMurl|#



#verify the authentication for NTLM if only main URL is having authentication
#SMOKE-018-006|AUTH_NTLM|1|1|1|http|ntlm|ntlm|#|#|?SvcTime=10&TestCase=T3FailNoNTLMHdr|#
########################
#Currently Not working
#SMOKE-018-007|AUTH_NTLM|1|1|1|http|arun|arun|#|#|?SvcTime=10000&TestCase=OK|G_IDLE_MSECS ALL 2000
#SMOKE-018-008|AUTH_NTLM|1|1|1|http|arun|arun|#|#|?SvcTime=10000&TestCase=T0Fail|G_IDLE_MSECS ALL 2000
#SMOKE-018-009|AUTH_NTLM|1|1|1|http|arun|arun|#|#|?SvcTime=10000&TestCase=T1Fail|G_IDLE_MSECS ALL 2000
#SMOKE-018-010|AUTH_NTLM|1|1|1|http|arun|arun|#|#|?SvcTime=10000&TestCase=T3Fail|G_IDLE_MSECS ALL 2000
#SMOKE-018-011|AUTH_NTLM|1|1|1|http|arun|arun|#|#|?SvcTime=10000&TestCase=T3FailHdrtimeout|G_IDLE_MSECS ALL 2000
