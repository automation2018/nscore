$TestDescription|$ScriptName|$User|$Session|%Api1|%Api2|%Api3|%Api4
######################################################################################################################

#NS WEB ADD HEADER VALID FOR SINGLE SUBSEQUENT API
SMOKE-014-001|Hpd_Tours_Add_Remove_Headers|1|1|ns_web_add_header("Connection", "Upgrade", 0)|//|//|//
SMOKE-014-002|Hpd_Tours_Add_Remove_Headers|1|1|ns_web_add_header("Accept-Encoding", "gzip,deflate", 1)|//|//|//
SMOKE-014-003|Hpd_Tours_Add_Remove_Headers|1|1|ns_web_add_header("User-Agent", "Cavisson Browser 1.0", 2)|//|//|//

#NS WEB AUTO HEADER VALID FOR ALL SUBSEQUENT REQUESTS
SMOKE-014-004|Hpd_Tours_Add_Remove_Headers|1|1|ns_web_add_auto_header("Max-Forwards", "10", 0)|//|//|//
SMOKE-014-005|Hpd_Tours_Add_Remove_Headers|1|1|ns_web_add_auto_header("Warning", "Checking Add Auto Header API of Netstorm", 1)|//|//|//
SMOKE-014-006|Hpd_Tours_Add_Remove_Headers|1|1|ns_web_add_auto_header("Content-Disposition", "attachment; filename = 'fname.txt'", 2)|//|//|//

#NS CLEAN-UP AUTO HEADER WHICH REMOVE ALL THE CUSTOM HEADERS ADDED WITH NS_WEB_ADD_AUTO_HEADER API
SMOKE-014-007|Hpd_Tours_Add_Remove_Headers|1|1|ns_web_add_auto_header("Content-Disposition", "attachment; filename = 'fname.txt'", 2)|//|ns_web_cleanup_auto_headers()|//

#NS REMOVE AUTO HAEADER
SMOKE-014-008|Hpd_Tours_Add_Remove_Headers|1|1|ns_web_add_auto_header("Content-Disposition", "attachment; filename = 'fname.txt'", 2)|//|ns_web_remove_auto_header("Content-Disposition", 0)|//
SMOKE-014-009|Hpd_Tours_Add_Remove_Headers|1|1|ns_web_add_auto_header("Content-Disposition", "attachment; filename = 'fname.txt'", 2)|//|ns_web_remove_auto_header("Content-Disposition", 1)|ns_web_add_header("Connection", "Upgrade", 2)
