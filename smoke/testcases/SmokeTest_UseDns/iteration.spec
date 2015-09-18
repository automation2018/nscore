$TestDescription|$ScriptName|$User|$Sessions|$USE_DNS
#
#G_USE_DNS keyword testcases
#
#G_USE_DNS <groupname or ALL> <Enable 0/1/2> <DNS Caching Mode 0/1/2> <DNS Log Mode 0/1> <DNS Connection Type<0/1>
SMOKE-016-001|UseDns|1|1|G_USE_DNS G1 0 0 1 0
SMOKE-016-002|UseDns|1|1|G_USE_DNS G1 1 1 1 0
SMOKE-016-003|UseDns|1|1|G_USE_DNS G1 1 1 1 1
SMOKE-016-004|UseDns|1|1|G_USE_DNS G1 1 2 0 0
SMOKE-016-005|UseDns|1|1|G_USE_DNS G1 2 0 0 0
SMOKE-016-006|UseDns|1|1|G_USE_DNS G1 2 1 1 1
SMOKE-016-007|UseDns|1|1|G_USE_DNS G1 2 2 1 1
