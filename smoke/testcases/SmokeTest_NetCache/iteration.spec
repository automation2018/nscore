$Description|$Script|$Users|$Sessions|$NetworkCaching
######################################################################################################################
#Case to check the functionality of various keywords influencing network caching

SMOKE-015-001|Smoke_NetCache|1|1|G_ENABLE_NETWORK_CACHE_STATS G1 1 0

#Cases added to test the behaviour of NO server for netcache headers sent as a request
SMOKE-015-002|Smoke_NetCache_With_Netocean_Service|1|1|G_ENABLE_NETWORK_CACHE_STATS G1 1 0
SMOKE-015-003|Smoke_NetCache_With_Netocean_Service_Parameterization|1|19|G_ENABLE_NETWORK_CACHE_STATS G1 1 0
