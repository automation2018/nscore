$TestDescription|$ScriptName1|$ScriptName2|$users|$Pagethinktime1|$Pagethinktime2|$override_Value|$Session_pacing|$duration

#Single Group Based Scenario
SMOKE-008-001|Smoke_PageThink|#|1|G_PAGE_THINK_TIME ALL ALL 2 5000|#|1|#|SESSIONS 2
SMOKE-008-002|Smoke_PageThink|#|1|G_PAGE_THINK_TIME ALL ALL 3 5000 10000|#|1|#|SESSIONS 1
SMOKE-008-003|Smoke_PageThink|#|1|G_PAGE_THINK_TIME ALL ALL 1 2|#|1|#|SESSIONS 1
SMOKE-008-004|Smoke_PageThink|#|1|G_PAGE_THINK_TIME g1 reservation 2 5000|#|1|#|SESSIONS 1
SMOKE-008-005|Smoke_PageThink|#|1|G_PAGE_THINK_TIME g1 welcome 2 5000|#|2 5|#|SESSIONS 1
SMOKE-008-006|Smoke_PageThink|#|1|G_PAGE_THINK_TIME g1 findflight_3 2 10000|#|3 10 50|#|SESSIONS 1

#TODO
#Multiple Group Based Scenario
