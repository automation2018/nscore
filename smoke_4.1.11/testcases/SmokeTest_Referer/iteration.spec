$TESTDESCRIPTION|$SESSIONS|$SESSION_MODE|$KEYWORD_VALUES|$SCRIPT1|$SCRIPT2|$MAX_HOST_KEYWORD|$AUTO_REDIRECT|$SAVE_LOCATION_KEYWORD
# HTTP REFERER 
# Functional test cases with auto redirection.
#Test case ID - NS_REFERER_002
SMOKE-034-001|1|0|ALL 0 1|http_referer1 1|#|#|#|#
#Test case ID - NS_REFERER_003
SMOKE-034-002|1|0|ALL 1 0|http_referer1 1|#|#|#|#
#Test case ID - NS_REFERER_004
SMOKE-034-003|1|0|ALL 1 1|http_referer1 1|#|#|#|#
#Test case ID - NS_REFERER_007
SMOKE-034-004|2|1|ALL 1 0|http_referer1 1|#|#|#|#

# With multiple hosts
#Test case ID - NS_REFERER_010
SMOKE-034-005|1|0|ALL 0 1|http_referer1 1|#|MAX_DYNAMIC_HOST 32|#|#
#Test case ID - NS_REFERER_011
SMOKE-034-006|1|0|ALL 1 0|http_referer2 1|#|MAX_DYNAMIC_HOST 32|#|#
#Test case ID - NS_REFERER_015
SMOKE-034-007|2|1|ALL 1 0|http_referer2 1|#|MAX_DYNAMIC_HOST 32|#|#


# Functional test cases without redirection
#Test case ID - NS_REFERER_023
SMOKE-034-008|2|1|ALL 1 0|http_referer1 1|#|MAX_DYNAMIC_HOST 32|AUTO_REDIRECT 20|G_SAVE_LOCATION_HDR_ON_ALL_RSP_CODE ALL 1
#Test case ID - NS_REFERER_024
#SMOKE-034-009|2|1|ALL 1 1|http_referer1 1|#|MAX_DYNAMIC_HOST 32|AUTO_REDIRECT 20|G_SAVE_LOCATION_HDR_ON_ALL_RSP_CODE ALL 1


# Functional test cases with group wise
#Test case ID - NS_REFERER_026
#SMOKE-034-010|2|0|G1 0 1|http_referer1 1|SGRP G2 NA Internet 0 http_referer3 1|MAX_DYNAMIC_HOST 32|#|#
#Test case ID - NS_REFERER_027
#SMOKE-034-011|2|0|G1 1 0|http_referer1 1|SGRP G2 NA Internet 0 http_referer3 1|MAX_DYNAMIC_HOST 32|#|#
#Test case ID - NS_REFERER_028
#SMOKE-034-012|2|0|G1 1 1|http_referer1 1|SGRP G2 NA Internet 0 http_referer2 1|MAX_DYNAMIC_HOST 32|#|#


# Functional Test cases with linking
# Linking from HTTP to HTTPS (#Test case ID - NS_REFERER_039)
SMOKE-034-013|1|0|ALL 1 0|http_referer_linking 1|#|#|#|#
# Linking from HTTPS to HTTPS (#Test case ID - NS_REFERER_040)
SMOKE-034-014|1|0|ALL 1 0|http_referer_linking 1|#|#|#|#
# Linking from HTTPS to HTTP (#Test case ID - NS_REFERER_041)
SMOKE-034-015|1|0|ALL 1 0|http_referer_linking 1|#|#|#|#


# Functional test cases with different status code
# Pending.................


