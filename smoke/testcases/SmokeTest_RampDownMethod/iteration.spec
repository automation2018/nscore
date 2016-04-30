$TestDescription|$KeyValue1

# RAMP_DOWN_METHOD (ramp down all vusers)
SMOKE-026-001|RAMP_DOWN_METHOD 0 1

# Allow current session to complete , Hasten completion by disregarding all Think Times
SMOKE-026-002|RAMP_DOWN_METHOD 0 2

#Allow current session to complete , Hasten completion by disregarding all Think Times, and use idle time of 10 seconds
SMOKE-026-003|RAMP_DOWN_METHOD 0 3 10

# Allow cuurent page to complete,  Hasten completion by using idle time  of 10 seconds
SMOKE-026-004|RAMP_DOWN_METHOD 1 2 10

# Stop immediately
SMOKE-026-005|RAMP_DOWN_METHOD 2
