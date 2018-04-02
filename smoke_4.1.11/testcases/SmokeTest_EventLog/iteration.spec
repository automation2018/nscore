$TestDescription|$ScriptName|$Users|$Duration|$Event_Log|$Event_Def_File|$Idle_Msecs|$PageThinkTime|$OverrideThinktime|$SessionPacing

##EVENT_LOG DO NOT FILTER : MODE 0
SMOKE-016-001|Smoke_Event_4XX|1|TIME 00:00:30|EVENT_LOG Information 0|#|#|#|#|#
SMOKE-016-002|Smoke_Event_TO|1|TIME 00:00:30|EVENT_LOG Warning 0|#|G_IDLE_MSECS G1 0|#|#|#
SMOKE-016-003|Smoke_Event_ConFail|1|TIME 00:00:30|EVENT_LOG Minor 0|#|#|#|#|#
SMOKE-016-004|Smoke_Event_CvFail|1|TIME 00:00:30|EVENT_LOG Major 0|#|#|#|#|#

##EVENT_LOG FILTER BASED ON EVENTS AS IN EVENT DEF FILE : MODE 1
#Log events with state change Mode(1) : Mode in event definition file
SMOKE-016-005|Smoke_Event_5XX_State_Change|1|TIME 00:00:30|EVENT_LOG Debug 1|EVENT_DEFINITION_FILE 5xxError.dat|#|#|#|#

#Log events with event counts Mode(2) : Mode in event definition file
SMOKE-016-006|Smoke_Event_TO|1|TIME 00:00:30|EVENT_LOG Warning 1|EVENT_DEFINITION_FILE timeout_event.dat|G_IDLE_MSECS G1 0|#|#|#

#Log events with event time Mode (3) : Mode in event definition file
SMOKE-016-007|Smoke_Event_CvFail|1|TIME 00:00:30|EVENT_LOG Major 1|EVENT_DEFINITION_FILE cvfail_event.dat|#|#|#|#

#Log events with no filter Mode(0) : Mode in event definition file
SMOKE-016-008|Smoke_Event_CvFail|1|TIME 00:00:30|EVENT_LOG Major 1|EVENT_DEFINITION_FILE nofilter.dat|#|#|#|#

##EVENT_LOG FILTER ALL EVENTS NO EVENTS WILL BE LOGGED : MODE 2
SMOKE-016-009|Smoke_Event_4XX|1|TIME 00:00:30|EVENT_LOG Information 2|EVENT_DEFINITION_FILE 4xxError.dat|#|#|#|#

# TODO
# EVENT_LOG MISCELENIOUS TESTCASES
# 5xx event url need to be updated
# Add RESPONSE_LINE HTTP/1.1 500 Internal Server Error
# In the URL directory structure $HPD_ROOT/control/default/<path-to-url>
#Need to add all event_definition_file mode
#mode 1 #mode 2 #mode 3 #mode 9
