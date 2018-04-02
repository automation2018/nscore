$TestDescription|$ScriptName1|$sgrp2|$users|$Pagethinktime1|$Pagethinktime2|$override_Value|$Session_pacing|$duration|%custom_val|%return_custom_val

# Single Group Based Scenario
#SMOKE-008-001|Smoke_PageThink|#|1|G_PAGE_THINK_TIME ALL ALL 2 5000|#|ALL ALL 1|#|SESSIONS 2|//|//
#SMOKE-008-002|Smoke_PageThink|#|1|G_PAGE_THINK_TIME ALL ALL 3 5000 10000|#|ALL ALL 1|#|SESSIONS 1|//|//
#SMOKE-008-003|Smoke_PageThink|#|1|G_PAGE_THINK_TIME ALL ALL 1 2|#|ALL ALL 1|#|SESSIONS 1|//|//
#SMOKE-008-004|Smoke_PageThink|#|1|G_PAGE_THINK_TIME g1 reservation 2 5000|#|ALL ALL 1|#|SESSIONS 1|//|//
#SMOKE-008-005|Smoke_PageThink|#|1|G_PAGE_THINK_TIME g1 welcome 2 5000|#|ALL ALL 2 5|#|SESSIONS 1|//|//
#SMOKE-008-006|Smoke_PageThink|#|1|G_PAGE_THINK_TIME g1 findflight_3 2 10000|#|ALL ALL 3 10 50|#|SESSIONS 1|//|//


# Declare an array and return a random value from that arary
SMOKE-008-007|Smoke_Page_Think_Custom_1|SGRP g2 NA Internet 0 Smoke_Page_Think_Custom_2 1|1|G_PAGE_THINK_TIME g1 login 4 custom_pg_think|#|ALL ALL 1|#|SESSIONS 2|double custom_time = 5.0;|return custom_time;
SMOKE-008-008|Smoke_Page_Think_Custom_1|SGRP g2 NA Internet 0 Smoke_Page_Think_Custom_2 1|1|G_PAGE_THINK_TIME g2 login 4 custom_pg_think|#|ALL ALL 1|#|SESSIONS 2|double custom_time = 10.0;|return custom_time;
SMOKE-008-009|Smoke_Page_Think_Custom_1|SGRP g2 NA Internet 0 Smoke_Page_Think_Custom_2 1|1|G_PAGE_THINK_TIME g1 ALL 4 custom_pg_think|#|ALL ALL 1|#|SESSIONS 2|double custom_time = 3.0;|return custom_time;
SMOKE-008-010|Smoke_Page_Think_Custom_1|SGRP g2 NA Internet 0 Smoke_Page_Think_Custom_2 1|1|G_PAGE_THINK_TIME g2 ALL 4 custom_pg_think|#|ALL ALL 1|#|SESSIONS 2|double custom_time = 5.0;|return custom_time;
#SMOKE-008-011|Smoke_Page_Think_Custom_1|SGRP g2 NA Internet 0 Smoke_Page_Think_Custom_2 1|1|G_PAGE_THINK_TIME ALL ALL 4 custom_pg_think|#|ALL ALL 1|#|SESSIONS 2|double custom_time = 5.0;|return custom_time;
#SMOKE-008-012|Smoke_Page_Think_Custom_1|SGRP g2 NA Internet 0 Smoke_Page_Think_Custom_2 1|1|G_PAGE_THINK_TIME g1 index 4 custom_delay|#|ALL ALL 1|#|SESSIONS 2|//|//

# With Overide keyword 
#SMOKE-008-013|Smoke_Page_Think_Custom_1|SGRP g2 NA Internet 0 Smoke_Page_Think_Custom_2 1|1|G_PAGE_THINK_TIME g1 index 2 2000|#|ALL index 1|#|SESSIONS 2|//|//
#SMOKE-008-014|Smoke_Page_Think_Custom_1|SGRP g2 NA Internet 0 Smoke_Page_Think_Custom_2 1|1|G_PAGE_THINK_TIME g1 index 3 1000 3000 |#|ALL A|#|SESSIONS 2|//|//
#SMOKE-008-015|Smoke_Page_Think_Custom_1|SGRP g2 NA Internet 0 Smoke_Page_Think_Custom_2 1|1|G_PAGE_THINK_TIME g1 index 4 custom_delay|#|ALL ALL 1|#|SESSIONS 2|//|//
#SMOKE-008-016|Smoke_Page_Think_Custom_1|SGRP g2 NA Internet 0 Smoke_Page_Think_Custom_2 1|1|G_PAGE_THINK_TIME g1 index 0|#|ALL ALL 1|#|SESSIONS 2|//|//
#SMOKE-008-017|Smoke_Page_Think_Custom_1|SGRP g2 NA Internet 0 Smoke_Page_Think_Custom_2 1|1|G_PAGE_THINK_TIME g1 index 2 2000|#|ALL ALL 1|#|SESSIONS 2|//|//
#SMOKE-008-018|Smoke_Page_Think_Custom_1|SGRP g2 NA Internet 0 Smoke_Page_Think_Custom_2 1|1|G_PAGE_THINK_TIME g1 index 3 1000 2000|#|ALL ALL 1|#|SESSIONS 2|//|//
#SMOKE-008-019|Smoke_Page_Think_Custom_1|SGRP g2 NA Internet 0 Smoke_Page_Think_Custom_2 1|1|G_PAGE_THINK_TIME g1 index 2 1000|#|ALL ALL 1|#|SESSIONS 2|//|//
#SMOKE-008-013|Smoke_Page_Think_Custom_1|SGRP g2 NA Internet 0 Smoke_Page_Think_Custom_2 1|1|G_PAGE_THINK_TIME ALL ALL 4 custom_delay|#|ALL ALL 1|#|SESSIONS 2|//|//
