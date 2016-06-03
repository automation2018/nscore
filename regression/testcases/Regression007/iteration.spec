$TName|$SCRIPT2|$CHECKMON1|$CHECKMON2|$CHECKMON3|$CHECKMON4

#Basic RTC cases For FCU

#Increasing users in Start Phase
REG-007-001|#|CHECK_MONITOR NS NSAfter 2 NA 2 NA NA NA /opt/cavisson/monitors/custom/chm_runtime_changes -f /home/automation/workbench/automation/nscore/lib/RTC_FILES/start.rtc|#|#|#

#Increasing users in RampUp Phase
REG-007-002|#|CHECK_MONITOR NS NSAfter 3 RampUp0 2 NA NA NA /opt/cavisson/monitors/custom/chm_runtime_changes -f /home/automation/workbench/automation/nscore/lib/RTC_FILES/rampup.rtc|#|#|#

#Increasing users in Stablize Phase
REG-007-003|#|CHECK_MONITOR NS NSAfter 3 Stabilize0 2 NA NA NA /opt/cavisson/monitors/custom/chm_runtime_changes -f /home/automation/workbench/automation/nscore/lib/RTC_FILES/stabilize.rtc|#|#|#

#Increasing users in Duration Phase
REG-007-004|#|CHECK_MONITOR NS NSAfter 3 Duration0 2 NA NA NA /opt/cavisson/monitors/custom/chm_runtime_changes -f /home/automation/workbench/automation/nscore/lib/RTC_FILES/duration.rtc|#|#|#

#Increasing users in RampDown Phase
REG-007-005|#|CHECK_MONITOR NS NSAfter 3 RampDown0 2 NA NA NA /opt/cavisson/monitors/custom/chm_runtime_changes -f /home/automation/workbench/automation/nscore/lib/RTC_FILES/rampdown.rtc|#|#|#

#RTC in multiple phases
REG-007-006|SGRP G2 NA Internet 0 tours_RTC2 100|CHECK_MONITOR NS NSAfter1 3 RampUp0 2 NA NA NA /opt/cavisson/monitors/custom/chm_runtime_changes -f /home/automation/workbench/automation/nscore/lib/RTC_FILES/rampup1_RTC|CHECK_MONITOR NS NSAfter2 3 Stabilize0 2 NA NA NA /opt/cavisson/monitors/custom/chm_runtime_changes -f /home/automation/workbench/automation/nscore/lib/RTC_FILES/stabilize1_RTC|CHECK_MONITOR NS NSAfter3 3 Duration0 2 NA NA NA /opt/cavisson/monitors/custom/chm_runtime_changes -f /home/automation/workbench/automation/nscore/lib/RTC_FILES/duration1_RTC|CHECK_MONITOR NS NSAfter4 3 RampDown0 2 NA NA NA /opt/cavisson/monitors/custom/chm_runtime_changes -f /home/automation/workbench/automation/nscore/lib/RTC_FILES/rampdown1_RTC
