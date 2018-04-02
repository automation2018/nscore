$K_TNAME|$K_NUM_USERS|$K_RAMP_UP_TIME|$K_DURATION|$K_RAMP_DOWN_TIME|$K_SCRIPT|$K_OVERRIDE_THINKTIME|$K_THINK_TIME|$K_OVERRIDE_THINKTIME2|$SGRP2

#To check override recorded think time for mode   "Use recorded think time" for g1
SMOKE-060-001|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|override_pagethink_time|G1 index 0|#|#|#

#To check override recorded think time for mode   "Use recorded think time". for g1 and g2
SMOKE-060-002|1|ALL IMMEDIATELY|SESSIONS 2|ALL IMMEDIATELY|override_pagethink_time|G1 index 0|#|G_OVERRIDE_RECORDED_THINK_TIME G2 login2 0|SGRP G2 NA NA Internet 0 override_pagethink_time2 1

#To check override recorded think time for mode  "Use multiply by of recorded think time" for g1
SMOKE-060-003|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|override_pagethink_time|G1 index 2 5|#|#|#

#To check override recorded think time for mode  "Use multiply by of recorded think time" for g1 and g2
SMOKE-060-004|1|ALL IMMEDIATELY|SESSIONS 2|ALL IMMEDIATELY|override_pagethink_time|G1 index 2 5|#|G_OVERRIDE_RECORDED_THINK_TIME G2 login2 2 5|SGRP G2 NA NA Internet 0 override_pagethink_time2 1

#To check override recorded think time for mode  "Use multiply by of recorded think time" with different pages of same group.
SMOKE-060-005|1|ALL IMMEDIATELY|SESSIONS 1|ALL IMMEDIATELY|override_pagethink_time|G1 index 2 5|#|G_OVERRIDE_RECORDED_THINK_TIME G1 login 2 4|#

#To check override recorded think time for mode  " Use multiply by of recorded think time" with a particular page of a group and all pages of different group.
SMOKE-060-006|1|ALL IMMEDIATELY|SESSIONS 2|ALL IMMEDIATELY|override_pagethink_time|G1 index 2 5|#|G_OVERRIDE_RECORDED_THINK_TIME G2 ALL 2 3|SGRP G2 NA NA Internet 0 override_pagethink_time2 1

#To check override recorded think time for mode  "Use multiply by of recorded think time" with all pages of different groups.
SMOKE-060-007|1|ALL IMMEDIATELY|SESSIONS 2|ALL IMMEDIATELY|override_pagethink_time|G1 ALL 2 5|#|G_OVERRIDE_RECORDED_THINK_TIME G2 index2 2 3|SGRP G2 NA NA Internet 0 override_pagethink_time2 1

#To check override recorded think time for mode "Use random percentage of recorded think time" with aparticular page of any group
SMOKE-060-008|1|ALL IMMEDIATELY|SESSIONS 2|ALL IMMEDIATELY|override_pagethink_time|G1 index 3 20 50|#|#|#

#END_ITERATION


