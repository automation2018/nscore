$K_TNAME|$K_NUM_USERS|$K_RAMP_UP_TIME|$K_DURATION|$K_RAMP_DOWN_TIME|$K_SCRIPT|$K_SVR_HOST|$K_RR_MODE|$K_REPORTING|$K_SESSION_PACING|$K_O_THINK_TIME|$K_NEW_USER|$K_S_SETTINGS_PROFILE|$K_HIERARICHAL_VIEW|$K_THINK_TIME

#SCENARIO_SETTINGS_PROFILE 

#smoke/smoke/reqrep.ssp file contain page_think_time and also page_think_time passes to scenario 
#its takes scenario page_think_time 
SMOKE-049-001|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|hpd_tours|127.0.0.1 10.10.30.96 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL 1|smoke/smoke/reqrep.ssp|default|ALL ALL 3 10 40

#it don't override the page_think_time contain in  smoke/smoke/reqrep.ssp file and its take scenario page_think_time
SMOKE-049-002|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|hpd_tours|127.0.0.1 10.10.30.96 -|1|ALL 1|ALL 1 0 2000|ALL ALL 1|ALL 1|smoke/smoke/reqrep.ssp|default|ALL ALL 3 20 50

#END_ITERATION


