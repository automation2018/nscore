$TestDescription|$ScriptName|$User|$Sessions|$Mode|$EmbMode|$KAPct|$DYNAMIC_HOST|$INCLUDE_DOMAIN|$EXCLUDE_DOMAIN|$INCLUDE_URL|$EXCLUDE_URL|$SERVER_HOST
# Autofetch general cases
SMOKE-003-001|OneMain_4Resp|1|1|1|0|100|#|#|#|#|#|SERVER_HOST 127.0.0.1 10.10.30.96 -
SMOKE-003-002|OneMain_4Resp|1|1|0|0|0|#|#|#|#|#|SERVER_HOST 127.0.0.1 10.10.30.96 -
SMOKE-003-003|OneMain_4Resp_2Embd|1|1|1|0|0|#|#|#|#|#|SERVER_HOST 127.0.0.1 10.10.30.96 -
SMOKE-003-004|OneMain_4Resp_2Embd|1|1|0|0|100|#|#|#|#|#|SERVER_HOST 127.0.0.1 10.10.30.96 -
#
# Cases for include/exclude domain/url which works along with AUTOFETCH and MAX_DYNAMIC_HOST keyword
SMOKE-003-005|AutoFetchDomainUrl|1|1|1|0|100|MAX_DYNAMIC_HOST 2|G_INLINE_INCLUDE_DOMAIN_PATTERN ALL 10.10.30.96|#|#|#|#
SMOKE-003-006|AutoFetchDomainUrl|1|1|1|0|100|MAX_DYNAMIC_HOST 2|#|G_INLINE_EXCLUDE_DOMAIN_PATTERN ALL www.google.com2|#|#|#
SMOKE-003-007|AutoFetchQuery|1|1|1|0|100|MAX_DYNAMIC_HOST 2|#|#|G_INLINE_INCLUDE_URL_PATTERN ALL *.js|#|#
SMOKE-003-008|AutoFetchQuery|1|1|1|0|100|MAX_DYNAMIC_HOST 2|#|#|#|G_INLINE_EXCLUDE_URL_PATTERN ALL *.js|#
#
# Cases for .jsp and regular expression based inlines in autofetch

SMOKE-003-009|AutoFetchQuery|1|1|1|0|100|MAX_DYNAMIC_HOST 2|#|#|#|G_INLINE_EXCLUDE_URL_PATTERN ALL *.jsp|#
SMOKE-003-010|AutoFetchQuery|1|1|1|0|100|MAX_DYNAMIC_HOST 2|#|#|#|G_INLINE_INCLUDE_URL_PATTERN ALL *.jsp|#
SMOKE-003-011|AutoFetchQuery|1|1|1|0|100|MAX_DYNAMIC_HOST 2|#|#|#|G_INLINE_EXCLUDE_URL_PATTERN ALL *.js+$|#
SMOKE-003-012|AutoFetchQuery|1|1|1|0|100|MAX_DYNAMIC_HOST 2|#|#|#|G_INLINE_INCLUDE_URL_PATTERN ALL *.js?$|#
SMOKE-003-013|AutoFetchQuery|1|1|1|0|100|MAX_DYNAMIC_HOST 2|#|#|#|G_INLINE_INCLUDE_URL_PATTERN ALL *.jsp?$|#
SMOKE-003-014|AutoFetchQuery|1|1|1|0|100|MAX_DYNAMIC_HOST 2|#|#|#|G_INLINE_INCLUDE_URL_PATTERN ALL *.js*|#
SMOKE-003-015|AutoFetchQuery|1|1|1|0|100|MAX_DYNAMIC_HOST 2|#|#|#|G_INLINE_INCLUDE_URL_PATTERN ALL *.j[sp]+|#
#
# Cases for PostCallBack Api usages;Issue was in Kohls;some JS requests which again requests to JSP resources
# NS engine unable to handale the situation with autofetch feature; so PostURLCallback was intorduced to list additional requests
SMOKE-003-016|PostURLCallbackWithOutInline|1|1|1|0|100|#|#|#|#|#|#
SMOKE-003-017|PostURLCallbackWithInline|1|1|1|0|100|#|#|#|#|#|#
SMOKE-003-018|PostURLCallbackWithRedirection|1|1|1|0|100|#|#|#|#|#|#
