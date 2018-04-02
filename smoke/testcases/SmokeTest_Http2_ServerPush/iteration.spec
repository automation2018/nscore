$TestDescription|$Script1|$Script2|$Sessions|$Autofetch|$HTTP_Mode|$ServerPush|$Caching|$ServerHost

#HTTP2 UPGRADE MODE :
#Upgrade mode- Enable Server push for all group. (Autofetch Enabled) 
SMOKE-069-001|SGRP G1 NA Internet 0 Http2_ServerPush 1|SGRP G2 NA Internet 0 Http2_ServerPush2 1|4|ALL ALL 1|ALL 0|ALL 1|#|127.0.0.1 10.10.30.37 -

#Upgrade mode- Enable server push for one group. (Autofetch Enabled)
SMOKE-069-002|SGRP G1 NA Internet 0 Http2_ServerPush 1|SGRP G2 NA Internet 0 Http2_ServerPush2 1|4|ALL ALL 1|ALL 0|G1 1|#|127.0.0.1 10.10.30.37 -

#Upgrade mode- Enable Server push for all group. (Recorded Inline Resources) 
SMOKE-069-003|SGRP G1 NA Internet 0 Http2_ServerPush 1|SGRP G2 NA Internet 0 Http2_ServerPush2 1|4|ALL ALL 0|ALL 0|ALL 1|#|127.0.0.1 10.10.30.37 -

#Upgrade mode- Enable server push for one group. (Recorded Inline Resources)
SMOKE-069-004|SGRP G1 NA Internet 0 Http2_ServerPush 1|SGRP G2 NA Internet 0 Http2_ServerPush2 1|4|ALL ALL 0|ALL 0|G1 1|#|127.0.0.1 10.10.30.37 -

#Upgrade mode- Enable server push for all group with http caching enabled (Autofetch Enabled)
SMOKE-069-005|SGRP G1 NA Internet 0 Http2_ServerPush 1|SGRP G2 NA Internet 0 Http2_ServerPush2 1|4|ALL ALL 1|ALL 0|ALL 1|G_HTTP_CACHING ALL 100 0|127.0.0.1 10.10.30.37 -

#HTTP2 PRIOR KNOWLEDGE MODE :
#Prior Knowledge mode- Enable Server push for all group. (Autofetch Enabled) 
SMOKE-069-006|SGRP G1 NA Internet 0 Http2_ServerPush 1|SGRP G2 NA Internet 0 Http2_ServerPush2 1|4|ALL ALL 1|ALL 2|ALL 1|#|127.0.0.1 10.10.30.37 -

#Prior Knowledge mode- Enable server push for one group. (Autofetch Enabled)
SMOKE-069-007|SGRP G1 NA Internet 0 Http2_ServerPush 1|SGRP G2 NA Internet 0 Http2_ServerPush2 1|4|ALL ALL 1|ALL 2|G1 1|#|127.0.0.1 10.10.30.37 -

#Prior Knowledge mode- Enable Server push for all group. (Recorded Inline Resources) 
SMOKE-069-008|SGRP G1 NA Internet 0 Http2_ServerPush 1|SGRP G2 NA Internet 0 Http2_ServerPush2 1|4|ALL ALL 0|ALL 2|ALL 1|#|127.0.0.1 10.10.30.37 -

#Prior Knowledge mode- Enable server push for one group. (Recorded Inline Resources)
SMOKE-069-009|SGRP G1 NA Internet 0 Http2_ServerPush 1|SGRP G2 NA Internet 0 Http2_ServerPush2 1|4|ALL ALL 0|ALL 2|G1 1|#|127.0.0.1 10.10.30.37 -

#Prior Knowledge mode- Enable server push for all group with http caching enabled (Autofetch Enabled)
SMOKE-069-010|SGRP G1 NA Internet 0 Http2_ServerPush 1|SGRP G2 NA Internet 0 Http2_ServerPush2 1|4|ALL ALL 1|ALL 2|ALL 1|G_HTTP_CACHING ALL 100 0|127.0.0.1 10.10.30.37 -

