$K_TNAME|$K_NUM_USERS|$K_RAMP_UP_TIME|$K_DURATION|$K_RAMP_DOWN_TIME|$K_SCRIPT|$K_USER_SESSION|$K_SGRP_KEYWORD|%url

#To test value of declare var is persisting or not with mode (0,0)
SMOKE-059-001|1|ALL IMMEDIATELY|SESSIONS 2|ALL IMMEDIATELY|new_user_on_session|G_NEW_USER_ON_SESSION ALL 0 0|#|welcome

#To test value of declare var is persisting or not with mode (0,1)
SMOKE-059-002|1|ALL IMMEDIATELY|SESSIONS 2|ALL IMMEDIATELY|new_user_on_session|G_NEW_USER_ON_SESSION ALL 0 1|#|welcome

#To test value of declare var is persisting or not with mode (1,0)
SMOKE-059-003|1|ALL IMMEDIATELY|SESSIONS 2|ALL IMMEDIATELY|new_user_on_session|G_NEW_USER_ON_SESSION ALL 1 0|#|welcome

#To test value of declare var is persisting or not with mode (1,1)
SMOKE-059-004|1|ALL IMMEDIATELY|SESSIONS 2|ALL IMMEDIATELY|new_user_on_session|G_NEW_USER_ON_SESSION ALL 1 1|#|welcome

#To test value of declare var is persisting or not with mode (0,0) when group is 1
SMOKE-059-005|1|ALL IMMEDIATELY|SESSIONS 4|ALL IMMEDIATELY|new_user_on_session|G_NEW_USER_ON_SESSION g1 0 0|SGRP g2 NA NA Internet 0 new_user_on_session 1|welcome

#To test value of declare var is persisting or not with mode (0,1) when group is 1
SMOKE-059-006|1|ALL IMMEDIATELY|SESSIONS 4|ALL IMMEDIATELY|new_user_on_session|G_NEW_USER_ON_SESSION g1 0 1|SGRP g2 NA NA Internet 0 new_user_on_session 1|welcome

#To test value of declare var is persisting or not with mode (1,0) when group is 1
SMOKE-059-007|1|ALL IMMEDIATELY|SESSIONS 4|ALL IMMEDIATELY|new_user_on_session|G_NEW_USER_ON_SESSION g1 1 0|SGRP g2 NA NA Internet 0 new_user_on_session 1|welcome

#To test value of declare var is persisting or not with mode (1,1) when group is 1
SMOKE-059-008|1|ALL IMMEDIATELY|SESSIONS 4|ALL IMMEDIATELY|new_user_on_session|G_NEW_USER_ON_SESSION g1 1 1|SGRP g2 NA NA Internet 0 new_user_on_session 1|welcome

#To test value of declare var is persisting or not with mode (0,1) 
#SMOKE-059-009|1|ALL IMMEDIATELY|SESSIONS 4|ALL IMMEDIATELY|new_user_on_session|G_NEW_USER_ON_SESSION ALL 0 1|#|welcomeeee


#END_ITERATION


