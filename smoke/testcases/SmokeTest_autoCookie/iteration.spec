$K_TNAME|$K_NUM_USERS|$K_RAMP_UP_TIME|$K_DURATION|$K_RAMP_DOWN_TIME|$K_SCRIPT|$K_SVR_HOST|$K_RR_MODE|$K_REPORTING|$K_SESSION_PACING|$K_O_THINK_TIME|$K_THINK_TIME|$K_NEW_USER|$K_TRACING|$K_HIERARICHAL_VIEW|$K_AUTO_COOKIE|$HTTP_MODE

# HTTP/1.1 Protocol
#Set_Cookie header set in request file and Cookie header not set in response file
SMOKE-040-01|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|Cookie_ClientMode_Test|127.0.0.1 10.10.30.96 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|AUTO_COOKIE 1 0|ALL 1
#Enable auto Cookie with name as Key with expires attribute ignored
SMOKE-040-02|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|Cookie_ClientMode_Test|127.0.0.1 10.10.30.96 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|AUTO_COOKIE 2 0|ALL 1
#Enable auto Cookie with name and path as a key with expires attribute ignored
SMOKE-040-03|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|Cookie_ClientMode_Test|127.0.0.1 10.10.30.96 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|AUTO_COOKIE 3 0 |ALL 1
#Enable auto Cookie with name and domain as a Key with expires attribute ignored
SMOKE-040-04|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|Cookie_ClientMode_Test|127.0.0.1 192.168.255.3 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|AUTO_COOKIE 4 0|ALL 1

#HTTP/2.0 Protocol- Upgrade Mode :
#Set_Cookie header set in request file and Cookie header not set in response file
SMOKE-040-05|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|Cookie_ClientMode_Test|127.0.0.1 10.10.30.96 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|AUTO_COOKIE 1 0|ALL 0
#Enable auto Cookie with name as Key with expires attribute ignored
SMOKE-040-06|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|Cookie_ClientMode_Test|127.0.0.1 10.10.30.96 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|AUTO_COOKIE 2 0|ALL 0
#Enable auto Cookie with name and path as a key with expires attribute ignored
SMOKE-040-07|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|Cookie_ClientMode_Test|127.0.0.1 10.10.30.96 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|AUTO_COOKIE 3 0|ALL 0
#Enable auto Cookie with name and domain as a Key with expires attribute ignored
SMOKE-040-08|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|Cookie_ClientMode_Test|127.0.0.1 192.168.255.3 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|AUTO_COOKIE 4 0|ALL 0

#HTTP/2.0 Protocol- Prior Knowledge Mode :
#Set_Cookie header set in request file and Cookie header not set in response file
SMOKE-040-09|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|Cookie_ClientMode_Test|127.0.0.1 10.10.30.96 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|AUTO_COOKIE 1 0|ALL 2
#Enable auto Cookie with name as Key with expires attribute ignored
SMOKE-040-10|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|Cookie_ClientMode_Test|127.0.0.1 10.10.30.96 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|AUTO_COOKIE 2 0|ALL 2
#Enable auto Cookie with name and path as a key with expires attribute ignored
SMOKE-040-11|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|Cookie_ClientMode_Test|127.0.0.1 10.10.30.96 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|AUTO_COOKIE 3 0|ALL 2
#Enable auto Cookie with name and domain as a Key with expires attribute ignored
SMOKE-040-12|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|Cookie_ClientMode_Test|127.0.0.1 192.168.255.3 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|AUTO_COOKIE 4 0|ALL 2

#END_ITERATION


