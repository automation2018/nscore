$Test_Name|$Script_Name|$Users|$Sessions|%Url|%Username|%Password|$PageDump|$KeepAlive
#
#Cases for Basic Auth
#In case of using file param to parametirized the value of username/password while the refresh mode is session
SMOKE-002-001|MainUrlAuth_Cmode_Param_Session|1|1|http|arun_QA|arun|#|#

#In case of using file param to parametirized the value of username/password while the refresh mode is USE
SMOKE-002-002|MainUrlAuth_Cmode_Param_Use|1|1|http|arun_QA|arun|#|#

#For page dump 
SMOKE-002-003|Main_apache_PageDump|1|1|http|arun_QA|arun|G_TRACING ALL 4 1 0 0|#

#Connection is keep Alive or non keep alive
SMOKE-002-004|MainUrlAuth_Cmode_Search_Check|1|1|http|arun_QA|arun|#|G_KA_PCT ALL 100
SMOKE-002-005|MainUrlAuth_Cmode_Search_CVfail|1|1|http|arun_QA|arun|#|G_KA_PCT ALL 0

#for time out 
