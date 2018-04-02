$Test_Name|$Script_Name|$Users|$Sessions|%Url|%Username|%Password|$PageDump|$KeepAlive

########################################################################################
#  Basic authentication steps                                                          #
#  1: C  --> S   GET ...                                                               #
#  2: C <--  S   401 Unauthorized WWW-Authenticate: Basic realm=”…”                    #
#  3: C  --> S   GET ... Authorization: Basic <base64-encoded <username:password> >    #
#  4: C <--  S   200 Ok                                                                #
########################################################################################

# In case of using file param to parametirized the value of username/password while the refresh mode is session
SMOKE-002-001|MainUrlAuth_Cmode_Param_Session|1|1|http|netstorm|netstorm|#|#

# In case of using file param to parametirized the value of username/password while the refresh mode is USE
SMOKE-002-002|MainUrlAuth_Cmode_Param_Use|1|1|http|netstorm|netstorm|#|#

# For page dump 
SMOKE-002-003|Main_apache_PageDump|1|1|http|netstorm|netstorm|G_TRACING ALL 4 1 0 0|#

# Connection is keep Alive or non keep alive
SMOKE-002-004|MainUrlAuth_Cmode_Search_Check|1|1|http|netstorm|netstorm|#|G_KA_PCT ALL 100
SMOKE-002-005|MainUrlAuth_Cmode_Search_CVfail|1|1|http|netstorm|netstorm|#|G_KA_PCT ALL 0

#For time out 

# QOP with AuthHeader;Issue was in Macy's
# Reason
# Netstorm is expecting "qop " value with Auth Header, 
# but server is not sending qop value with auth header. 
# This is the reason Netstorm is not seding Auth header with next reques
