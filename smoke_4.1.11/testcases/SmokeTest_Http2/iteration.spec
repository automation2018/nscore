$TestDescription|$Script1|$Script2|$Sessions|$HTTP_Mode_grp1|$HTTP_Mode_grp2|$Server_host1|$Server_host2
#Upgrade mode- One group with mode 0. 
SMOKE-057-001|SGRP G1 NA Internet 0 Http2_script1 1|#|2|G_HTTP_MODE ALL 0|#|G_SERVER_HOST ALL 127.0.0.1 10.10.30.37:9020 -|G_SERVER_HOST ALL 127.0.0.2 10.10.30.37:9020 -
#Prior Knowledge mode- One group with mode 2.
SMOKE-057-002|SGRP G1 NA Internet 0 Http2_script1 1|#|2|G_HTTP_MODE ALL 2|#|G_SERVER_HOST ALL 127.0.0.1 10.10.30.37:9020 -|G_SERVER_HOST ALL 127.0.0.2 10.10.30.37:9020 -
#Upgrade mode- Two groups, one is with mode 0 and another is with mode 1.
#SMOKE-057-003|SGRP G1 NA Internet 0 Http2_script1 1|SGRP G2 NA Internet 0 Http2_script2 1|4|G_HTTP_MODE G1 0|#|G_SERVER_HOST ALL 127.0.0.1 10.10.30.37:9020 -|G_SERVER_HOST ALL 127.0.0.2 10.10.30.37:9020 -
#Prior Knowledge mode- Two groups, One is with mode 2 and another is with mode 1.
SMOKE-057-004|SGRP G1 NA Internet 0 Http2_script1 1|SGRP G2 NA Internet 0 Http2_script2 1|4|G_HTTP_MODE G1 2|#|G_SERVER_HOST ALL 127.0.0.1 10.10.30.37:9020 -|G_SERVER_HOST ALL 127.0.0.2 10.10.30.37:9020 -
#Upgrade mode- Different hosts.
SMOKE-057-005|SGRP G1 NA Internet 0 Http2_script1 1|SGRP G2 NA Internet 0 Http2_script2 1|4|G_HTTP_MODE ALL 0|#|G_SERVER_HOST ALL 127.0.0.1 10.10.30.37:9020 -|G_SERVER_HOST ALL 127.0.0.2 10.10.30.37:9020 -
#Prior Knowledge mode- Different hosts.
SMOKE-057-006|SGRP G1 NA Internet 0 Http2_script1 1|SGRP G2 NA Internet 0 Http2_script2 1|4|G_HTTP_MODE ALL 2|#|G_SERVER_HOST ALL 127.0.0.1 10.10.30.37:9020 -|G_SERVER_HOST ALL 127.0.0.2 10.10.30.37:9020 -
