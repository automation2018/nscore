$TestDescription|$ScriptName|$User|$Sessions|$MaxTime|$Time|$Ramp_Up|$Sync_Point|$Progress

#SYNC_POINT <Group> <Type> <Name> <Active/Inactive> <Pct user> <Release target user> <Scripts>
#Type :  0: start transaction 1: start page  2: start script 3: custom sync point
#Active/Inactive : 0: inactive 1: active (Default)

SMOKE-013-001|Smoke_SyncPoint|10|10|00:05:00|00:01:00|RATE 120 M LINEARLY|SYNC_POINT g1 0 hpd_page1_trans1 1 100 10 Smoke_SyncPoint|1000

SMOKE-013-002|Smoke_SyncPoint|10|10|00:05:00|00:01:00|RATE 120 M LINEARLY|SYNC_POINT g1 0 hpd_page1_trans1 1 100 5 Smoke_SyncPoint|1000

SMOKE-013-003|Smoke_SyncPoint|10|10|00:05:00|00:01:00|RATE 120 M LINEARLY|SYNC_POINT g1 0 hpd_page1_trans1 1 100 20 Smoke_SyncPoint|1000

SMOKE-013-004|Smoke_SyncPoint|10|10|00:05:00|00:01:00|RATE 120 M LINEARLY|SYNC_POINT g1 0 hpd_page5_trans5  1 100 10 Smoke_SyncPoint|1000

SMOKE-013-005|Smoke_SyncPoint|10|10|00:05:00|00:01:00|RATE 120 M LINEARLY|SYNC_POINT g1 1 index_html 1 100 10 Smoke_SyncPoint|1000

SMOKE-013-006|Smoke_SyncPoint|10|10|00:05:00|00:01:00|RATE 120 M LINEARLY|SYNC_POINT g1 1 login 1 100 5 Smoke_SyncPoint|1000

####Sync Point Time Out ######
#### TimeOut Overall #######
SMOKE-013-007|Smoke_SyncPoint|10|10|00:00:20|00:00:20|RATE 120 M LINEARLY|SYNC_POINT g1 0 hpd_page1_trans1 1 100 100 Smoke_SyncPoint|1000

####### Vuser inter arrival timeout #######
SMOKE-013-008|Smoke_SyncPoint|10|10|00:05:00|00:00:20|STEP 1 00:00:30|SYNC_POINT g1 0 hpd_page1_trans1 1 100 10 Smoke_SyncPoint|1000


#Smoke_Sync_Point_InBtweenPage_10U_50pct_5user_release|Smoke_SyncPoint|10|10|00:01:00|SYNC_POINT g1 1 login 1 50 4 Smoke_SyncPoint|10000
