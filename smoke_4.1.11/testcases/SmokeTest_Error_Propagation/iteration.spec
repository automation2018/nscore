$TestDescription|$Script|$KeyValue1|$KeyValue2

# Url status success should show in progress report, also for page, tx and session
SMOKE-029-001|hpd_err_propagation_1|G_ERR_CODE_OK G1 1|#

# Test will not stop on url failure, and the page will end with CVFail status
SMOKE-029-002|hpd_err_propagation_1|G_ERR_CODE_OK G1 1|G_CONTINUE_ON_PAGE_ERROR ALL ALL 1

# script with 3 pages, 2 transactions
# First Tx : starts from 1st page and ends in 3rd page
# Second Tx : starts and ends in 2nd page and 2nd page should fail with 4xx
SMOKE-029-003|hpd_err_propagation_2|G_CONTINUE_ON_PAGE_ERROR ALL ALL 1|#

# Invalid
#SMOKE-029-004|hpd_err_propagation_3|G_CONTINUE_ON_PAGE_ERROR ALL ALL 1|CONSIDER_ZERO_AS_AUTO 1
