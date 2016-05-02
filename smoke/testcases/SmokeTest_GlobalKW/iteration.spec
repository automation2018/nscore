$TestDescription|$KeyValue1|$KeyValue2|$KeyValue3|$KeyValue4|$KeyValue5|$KeyValue6|$KeyValue7|$ScriptG1|$SESSIONS

# PAGE_AS_TRANSACTION 
# Mode : 0 - Dont consider page as tranaction
SMOKE-021-001|PAGE_AS_TRANSACTION 0|#|#|#|#|#|#|Hpd_Tours_PAT|SESSIONS 1
# Mode : 1 - Consider page as tranaction
SMOKE-021-002|PAGE_AS_TRANSACTION 1|#|#|#|#|#|#|Hpd_Tours_PAT|SESSIONS 1
SMOKE-021-003|PAGE_AS_TRANSACTION 1 1|#|#|#|#|#|#|Hpd_Tours_PAT|SESSIONS 1
# Mode : 2 - Group pass and fail transaction individually (Succes Tx as Success, Fail Tx as Fail in trans_detail.dat file)
SMOKE-021-004|PAGE_AS_TRANSACTION 2 1|SGRP G2 NA Internet 0 Hpd_Tours_PAT_F_Tx 1|#|#|#|#|#|Hpd_Tours_PAT|SESSIONS 2
# Mode : 3 - Group transactions as per tx status (Succes Tx as Success, Fail Tx as per status in trans_detail.dat file)
SMOKE-021-005|PAGE_AS_TRANSACTION 3 1|SGRP G2 NA Internet 0 Hpd_Tours_PAT_F_Tx 1|#|#|#|#|#|Hpd_Tours_PAT|SESSIONS 2


# NUM_NVM
# Simple scenario, 5 groups, NUM_NVM 4, NVM_DISTRIBUTION 1
SMOKE-021-006|NUM_NVM 4 MACHINE|NVM_DISTRIBUTION 1|SGRP G2 NA Internet 0 Hpd_Tours_PAT 1|SGRP G3 NA Internet 0 Hpd_Tours_PAT 1|SGRP G4 NA Internet 0 Hpd_Tours_PAT 1|SGRP G5 NA Internet 0 Hpd_Tours_PAT 1|#|Hpd_Tours_PAT|SESSIONS 5

# Advance scenario, 4 groups, NUM_NVM 3, NVM_DISTRIBUTION 0
SMOKE-021-007|NUM_NVM 3 MACHINE|NVM_DISTRIBUTION 0|SGRP G2 NA Internet 0 Hpd_Tours_PAT 1|SGRP G3 NA Internet 0 Hpd_Tours_PAT 1|SGRP G4 NA Internet 0 Hpd_Tours_PAT 1|#|#|Hpd_Tours_PAT|SESSIONS 4

# Simple scenario, 2 groups, each group with 3 users, NUM_NVM 4, NVM_DISTRIBUTION 0
SMOKE-021-008|NUM_NVM 4 MACHINE|NVM_DISTRIBUTION 0|SGRP G2 NA Internet 0 Hpd_Tours_PAT 1|#|#|#|#|Hpd_Tours_PAT|SESSIONS 2

# Simple scenario, 2 groups, uneven user distributions, NUM_NVM 2, NVM_DISTRIBUTION 0
SMOKE-021-009|NUM_NVM 2 MACHINE|NVM_DISTRIBUTION 0|SGRP G2 NA Internet 0 Hpd_Tours_PAT 1|#|#|#|#|Hpd_Tours_PAT|SESSIONS 2



# DISABLE_COOKIES
# Used to disable cookies in the HTTP request. No cookies will be send in the HTTP request. mode 0 is default
SMOKE-021-010|DISABLE_COOKIES 0|AUTO_COOKIE 1 1|#|#|#|#|#|hpd_disable_cookie|SESSIONS 1
SMOKE-021-011|DISABLE_COOKIES 1|AUTO_COOKIE 1 1|#|#|#|#|#|hpd_disable_cookie|SESSIONS 1
