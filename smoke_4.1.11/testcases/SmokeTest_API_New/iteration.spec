$TestDescription|$Script|%ApiValue|$KeyValue
#
## INLINE TRANSACTION 
## cases for fail inline transaction and also when main url fails
SMOKE-024-001|hpd_tours_inline_tx|"TxName=TxInlineIndex"|G_INLINE_DELAY G1 index 2 2000
SMOKE-024-002|hpd_tours_inline_tx|"TxName=TxInlineHome"|G_INLINE_DELAY G1 index 2 2000
SMOKE-024-003|hpd_tours_inline_tx|"TxName=TxInlineReservation"|G_INLINE_DELAY G1 index 2 2000
#
#
## INLINE REPEAT
SMOKE-024-004|hpd_tours_inline_repeat|"REPEAT=2"|G_INLINE_DELAY G1 index 2 2000
SMOKE-024-005|hpd_tours_inline_repeat|"REPEAT=5"|G_INLINE_DELAY G1 index 2 2000
SMOKE-024-006|hpd_tours_inline_repeat|"REPEAT=7"|G_INLINE_DELAY G1 index 2 2000
#
## REPEAT & TX
SMOKE-024-007|hpd_tours_inline_repeat_tx|"REPEAT=10"|G_INLINE_DELAY G1 index 2 0
#
## NS TIMER API
SMOKE-024-008|hpd_tours_timer_api|//|G_INLINE_DELAY G1 index 2 2000
#
## ns_decode_3des 
SMOKE-024-009|ns_decode_3des_param|5|#
SMOKE-024-010|ns_decode_3des_param|8|#
SMOKE-024-011|ns_decode_3des_param|11|#
SMOKE-024-014|ns_decode_3des_param|14|#
SMOKE-024-015|ns_decode_3des_param|17|#
SMOKE-024-016|ns_decode_3des_param|20|#
SMOKE-024-017|ns_decode_3des_param|23|#

## Split API
#SMOKE-024-018|API_split|#|#
SMOKE-024-019|API_split_withSP|#|#
