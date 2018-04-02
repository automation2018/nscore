$TestDescription|$Script|%Page|%Method|$Sessions|$HTTP_Mode|$AUTO_REDIRECT|$Server_host|$DEPTH
#HTTP/1.1
#Redirection upto 5 depth without using parent url method for redirected url.
SMOKE-004-001|SGRP G1 NA Internet 0 Auto_Redirect 1|Page1.html|GET|2|G_HTTP_MODE ALL 1|AUTO_REDIRECT 10 0|SERVER_HOST 127.0.0.1 10.10.30.96 -|5
#Redirection upto 5 depth using parent url method for redirected url.
SMOKE-004-002|SGRP G1 NA Internet 0 Auto_Redirect 1|Page1.html|POST|2|G_HTTP_MODE ALL 1|AUTO_REDIRECT 10 1|SERVER_HOST 127.0.0.1 10.10.30.96 -|5
#Redirection from http to https upto depth 1 without using parent url method for redirected url.
SMOKE-004-003|SGRP G1 NA Internet 0 Auto_Redirect 1|http_to_https.html|GET|2|G_HTTP_MODE ALL 1|AUTO_REDIRECT 10 0|SERVER_HOST 127.0.0.1 10.10.30.96 -|1
#Redirection from http to https upto depth 1 using parent url method for redirected url.
SMOKE-004-004|SGRP G1 NA Internet 0 Auto_Redirect 1|http_to_https.html|POST|2|G_HTTP_MODE ALL 1|AUTO_REDIRECT 10 1|SERVER_HOST 127.0.0.1 10.10.30.96 -|1
#Redirection from one host to another host.
SMOKE-004-005|SGRP G1 NA Internet 0 Auto_Redirect 1|diff_host.html|GET|2|G_HTTP_MODE ALL 1|AUTO_REDIRECT 10 0|SERVER_HOST 127.0.0.1 10.10.30.96 -|1
#Redirection restriction after depth 3.
SMOKE-004-006|SGRP G1 NA Internet 0 Auto_Redirect 1|Page1.html|GET|2|G_HTTP_MODE ALL 1|AUTO_REDIRECT 3 0|SERVER_HOST 127.0.0.1 10.10.30.96 -|5

##HTTP2 Upgrade mode.
##Redirection upto 5 depth without using parent url method for redirected url.
SMOKE-004-007|SGRP G1 NA Internet 0 Auto_Redirect_http2 1|Page1.html|GET|2|G_HTTP_MODE ALL 0|AUTO_REDIRECT 10 0|SERVER_HOST 127.0.0.1 10.10.30.37:443 -|5
##Redirection upto 5 depth using parent url method for redirected url.
SMOKE-004-008|SGRP G1 NA Internet 0 Auto_Redirect_http2 1|Page1.html|POST|2|G_HTTP_MODE ALL 0|AUTO_REDIRECT 10 1|SERVER_HOST 127.0.0.1 10.10.30.37:443 -|5
##Redirection from one host to another host.
SMOKE-004-009|SGRP G1 NA Internet 0 Auto_Redirect_http2 1|diff_host.html|GET|2|G_HTTP_MODE ALL 0|AUTO_REDIRECT 10 0|SERVER_HOST 127.0.0.1 10.10.30.37:443 -|1
##Redirection restriction after depth 3.
SMOKE-004-010|SGRP G1 NA Internet 0 Auto_Redirect_http2 1|Page1.html|GET|2|G_HTTP_MODE ALL 0|AUTO_REDIRECT 3 0|SERVER_HOST 127.0.0.1 10.10.30.37:443 -|5

##HTTP2 Prior Knowledge Mode.
##Redirection upto 5 depth without using parent url method for redirected url.
SMOKE-004-011|SGRP G1 NA Internet 0 Auto_Redirect_http2 1|Page1.html|GET|2|G_HTTP_MODE ALL 2|AUTO_REDIRECT 10 0|SERVER_HOST 127.0.0.1 10.10.30.37:443 -|5
##Redirection upto 5 depth using parent url method for redirected url.
SMOKE-004-012|SGRP G1 NA Internet 0 Auto_Redirect_http2 1|Page1.html|POST|2|G_HTTP_MODE ALL 2|AUTO_REDIRECT 10 1|SERVER_HOST 127.0.0.1 10.10.30.37:443 -|5
##Redirection from one host to another host.
SMOKE-004-013|SGRP G1 NA Internet 0 Auto_Redirect_http2 1|diff_host.html|GET|2|G_HTTP_MODE ALL 2|AUTO_REDIRECT 10 0|SERVER_HOST 127.0.0.1 10.10.30.37:443 -|1
##Redirection restriction after depth 3.
SMOKE-004-014|SGRP G1 NA Internet 0 Auto_Redirect_http2 1|Page1.html|GET|2|G_HTTP_MODE ALL 2|AUTO_REDIRECT 3 0|SERVER_HOST 127.0.0.1 10.10.30.37:443 -|5
