$TNAME|%TxStatus|%URLStatus|%PgThinkTime|%TxId

# C Var based tx name
# AutoStatus, 3xx Based, 2xx Based, Tx Specific
SMOKE-019-001|NS_AUTO_STATUS|200|0.2|2
SMOKE-019-002|NS_AUTO_STATUS|302|0.2|3
SMOKE-019-003|0|200|0.2|1
SMOKE-019-004|64|200|0.2|4

# TxConcurrent 
# Testing of nesting Transactions with different service, page think time and Txstatuses
#     1. AutoStatus- TxEnd in Same & Reverse & Mixed error
#     2. URL Failures - TxEnd in Same, reverse & mixed order
#     3. Success Status- TxEnd in Same, reverse & mixed order
#     4. Transaction Errors - Same, reverse & mixed order

# TxAPIErrors
# Testing of start, end, get status, get time API with different service/page think time and statuses
#     1. auto status
#     2. tx success
#     3. tx errors

# TxSetDiffStatus
# Testing of start, end, get status, get time API with different service/page think time and statuses using SetStatus API
#     1. set tx status auto, except auto
#     2. set tx status success, except auto
#     3. set tx status errors, except auto

# TxNameValidation
# 1. Valid name 
# 2. 0 charachter - 0 pageThinkTime
# 3. 49 charachter tx name
# 4. 100 charachter tx name 
# 5. Special charachter tx name 
# 6. Numeric Charachter tx name
# 7. Transaction name starting with underscore
# 8. Space between Transaction Name
# 9. Left Balnk
