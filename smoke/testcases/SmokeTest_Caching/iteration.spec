$TestDescription|$KeyValue1

# G_HTTP_CACHING <group> <% of users> <caching across session for same user enable/disable> <enable/disable client freshness>

# no caching across session for same user, client freshness 
# cache hit rate will be 100% of total users
SMOKE-025-001|G_HTTP_CACHING ALL 100 1 1

# no caching across session for same user, client freshness 
# cache hit rate will be 100% of total users of G1
SMOKE-025-002|G_HTTP_CACHING G1 100 1 1

# no caching across session for same user, client freshness 
# cache hit rate will be 50% of total users of G1
SMOKE-025-003|G_HTTP_CACHING G1 50 1 1

# caching across session for same user,client freshness disable
# cache hit rate will be 50% of total users of G1
SMOKE-025-004|G_HTTP_CACHING G1 100 0 0
