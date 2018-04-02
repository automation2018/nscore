$TNAME|$INLINE_KEYWORD|%post2|%pre2

# G_INLINE_DELAY
# Mode 1 : WEIBULL formula used
SMOKE-017-001|G_INLINE_DELAY G1 index 1 1500 300 1000 6000|//|//
SMOKE-017-002|G_INLINE_DELAY G1 ALL 1 1500 300 1000 6000|//|//
SMOKE-017-003|G_INLINE_DELAY ALL ALL 1 1500 300 1000 6000|"PostURLCallback=post_call_back_start"|"PostURLCallback=post_call_back_end"

# Mode 2
SMOKE-017-004|G_INLINE_DELAY G1 index 2 1000|//|//
SMOKE-017-005|G_INLINE_DELAY G1 ALL 2 2000|//|//
SMOKE-017-006|G_INLINE_DELAY ALL ALL 2 2000|"PostURLCallback=post_call_back_start"|"PostURLCallback=post_call_back_end"

# Mode 3
SMOKE-017-007|G_INLINE_DELAY G1 index 3 1000 3000|//|//
SMOKE-017-008|G_INLINE_DELAY G1 ALL 3 1000 2000|//|//
SMOKE-017-009|G_INLINE_DELAY ALL ALL 3 1000 2000|"PostURLCallback=post_call_back_start"|"PostURLCallback=post_call_back_end"

# Mode 4
SMOKE-017-010|G_INLINE_DELAY G1 index 4 custom_delay_single|//|//
SMOKE-017-011|G_INLINE_DELAY G1 ALL 4 custom_delay_single|//|//
SMOKE-017-012|G_INLINE_DELAY ALL ALL 4 custom_delay_single|"PostURLCallback=post_call_back_start"|"PostURLCallback=post_call_back_end"

# G_INLINE_MIN_CON_REUSE_DELAY
SMOKE-017-013|G_INLINE_MIN_CON_REUSE_DELAY G2 1000 3000|"PostURLCallback=post_call_back_start"|"PostURLCallback=post_call_back_end"
SMOKE-017-014|G_INLINE_MIN_CON_REUSE_DELAY ALL 1000 3000|"PostURLCallback=post_call_back_start"|"PostURLCallback=post_call_back_end"

# LOG_INLINE_BLOCK_TIME  
# validation to be done from GUI
SMOKE-017-015|LOG_INLINE_BLOCK_TIME|//|//


# ENABLE_PAGE_BASED_STATS  
# validation to be done from GUI
SMOKE-017-016|ENABLE_PAGE_BASED_STATS 1|//|//
