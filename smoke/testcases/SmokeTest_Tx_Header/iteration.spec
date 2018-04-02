$TNAME|$TX_HTTP_HEADER



#G_SEND_NS_TX_HTTP_HEADER <group> <mode> [Tx Variable] [Http Header]
#Send Transaction Header not pass in main and Inline URL
SMOKE-065-001|G_SEND_NS_TX_HTTP_HEADER ALL 0

#Send Transaction Header with Main URL
SMOKE-065-002|G_SEND_NS_TX_HTTP_HEADER ALL 1

#Send Transaction Header with Main URL with g1 group
SMOKE-065-003|G_SEND_NS_TX_HTTP_HEADER G1 1 

#Send Transaction Header with Main URL and Inline 
SMOKE-065-004|G_SEND_NS_TX_HTTP_HEADER ALL 2

#Send Transaction Header with Main URL and Inline 
SMOKE-065-005|G_SEND_NS_TX_HTTP_HEADER G1 2

