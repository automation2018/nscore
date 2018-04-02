$K_TNAME|$K_NUM_USERS|$K_RAMP_UP_TIME|$K_DURATION|$K_RAMP_DOWN_TIME|$K_SCRIPT|$K_SVR_HOST|$K_RR_MODE|$K_REPORTING|$K_SESSION_PACING|$K_O_THINK_TIME|$K_THINK_TIME|$K_NEW_USER|$K_TRACING|$K_HIERARICHAL_VIEW|$K_PAGE_AS_TRANSACTION|%URL

#PAGE_AS_TRANSACTION 1 0 mode . means in every page tx prefix is added like tx_<page name> and transaction applied
SMOKE-041-01|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|page_asTrx_tours|127.0.0.1 10.10.30.96 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|PAGE_AS_TRANSACTION 1 0|URL=http://127.0.0.1/tours/index.html

#PAGE_AS_TRANSACTION 1 1 mode . means in every page tx prefix is not added like <page name> but transaction applied
SMOKE-041-02|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|page_asTrx_tours|127.0.0.1 10.10.30.96 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|PAGE_AS_TRANSACTION 1 1|URL=http://127.0.0.1/tours/index.html

#PAGE_AS_TRANSACTION 2 0 mode . means in every page tx prefix is added with exit status like tx_<page name>_sucess and tx_<page name>_fail
SMOKE-041-03|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|page_asTrx_tours|127.0.0.1 10.10.30.96 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|PAGE_AS_TRANSACTION 2 0|URL=http://127.0.0.1/tours/index.html

#PAGE_AS_TRANSACTION 2 1 mode . means in every page tx prefix is not added with exit status like <page name>_sucess and <page name>_fail
SMOKE-041-04|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|page_asTrx_tours|127.0.0.1 10.10.30.96 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|PAGE_AS_TRANSACTION 2 1|URL=http://127.0.0.1/tours/index.html

#PAGE_AS_TRANSACTION 3 0 mode . means in every page tx prefix is added with error status like tx_<page name>_4xx
SMOKE-041-05|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|page_asTrx_tours|127.0.0.1 10.10.30.96 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|PAGE_AS_TRANSACTION 3 0|URL=http://127.0.0.1/tttours/index.html

#PAGE_AS_TRANSACTION 3 1 mode . means in every page tx prefix is not added with error status like <page name>_4xx
SMOKE-041-06|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|page_asTrx_tours|127.0.0.1 10.10.30.96 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL ALL 3 10 50|ALL 1|ALL 0 0 0 0|default|PAGE_AS_TRANSACTION 3 1|URL=http://127.0.0.1/tttours/index.html

#END_ITERATION


