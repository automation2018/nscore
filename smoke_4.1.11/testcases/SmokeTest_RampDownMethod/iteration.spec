$TestDescription|$KeyValue1

# G_RAMP_DOWN_METHOD ALL (ramp down all vusers)
# G_RAMP_DOWN_METHOD <Group name> <mode> <option> <time> 
SMOKE-026-001|G_RAMP_DOWN_METHOD ALL 0 1

# Allow current session to complete , Hasten completion by disregarding all Think Times
#SMOKE-026-002|G_RAMP_DOWN_METHOD ALL 0 2

#Allow current session to complete ,Hasten completion by disregarding all Think Times, and use idle time of 10 seconds
#SMOKE-026-003|G_RAMP_DOWN_METHOD ALL 0 3 10

# Allow cuurent page to complete,  Hasten completion by using idle time  of 10 seconds
#SMOKE-026-004|G_RAMP_DOWN_METHOD ALL 1 2 10

# Stop immediately
#SMOKE-026-005|G_RAMP_DOWN_METHOD ALL 2

#G_RAMP_DOWM_METHOD ALL
#SOMKE-026-006|G_RAMP_DOWN_METHOD ALL 0 0
