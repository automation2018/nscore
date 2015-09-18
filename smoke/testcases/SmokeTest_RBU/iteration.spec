$TestDescription|$ScriptName|$User|$Sessions|%PageLoadWaitTime|$RBU_KEYWORD|$clip_mode|$frequency|$quality|$cache_mode|$clear_cache|$user_agent|$BROWSER_TYPE|$header_mode|%method|%header

#Testcases for Firefox/Chromium browser
#Firefox 24 is used as NS Firefox(default case)
#Chromium 34 is used as NS Chrome
SMOKE-011-001|Smoke_RBU|1|1|60|G_RBU ALL ALL 1 1 0 1 0|0|100|100|0|0|RBU_FIREFOX_USER_AGENT|ENABLE_NS_FIREFOX 1|0|GET|automation:header
SMOKE-011-002|Smoke_RBU|1|1|60|G_RBU ALL ALL 1 1 0 1 1|0|100|100|1|0|RBU_CHROME_USER_AGENT|ENABLE_NS_CHROME 0|0|GET|automation:header

SMOKE-011-003|Smoke_RBU|1|1|60|G_RBU ALL ALL 1 1 0 1 0|0|100|100|0|0|RBU_FIREFOX_USER_AGENT|ENABLE_NS_FIREFOX 1|1|GET|automation:header
SMOKE-011-004|Smoke_RBU|1|1|60|G_RBU ALL ALL 1 1 0 1 0|0|100|100|0|0|RBU_FIREFOX_USER_AGENT|ENABLE_NS_FIREFOX 1|1|POST|automation:header

SMOKE-011-005|Smoke_RBU|1|1|60|G_RBU ALL ALL 1 1 0 1 1|0|100|100|1|0|RBU_CHROME_USER_AGENT|ENABLE_NS_CHROME 0|1|GET|automation:header
SMOKE-011-006|Smoke_RBU|1|1|60|G_RBU ALL ALL 1 1 0 1 1|0|100|100|1|0|RBU_CHROME_USER_AGENT|ENABLE_NS_CHROME 0|1|POST|automation:header

#TODO
#Testcases for clip capture feature to get page render time value
#Testcases for browser cache mechanism for chrome implementation of RBU
