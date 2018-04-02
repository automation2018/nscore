/*-----------------------------------------------------------------------------
    Name: flow
    Recorded By: netstorm
    Date of recording: 08/08/2017 04:33:59
    Flow details:
    Build details: 4.1.9 (build# 9)
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow()
{
    ns_start_transaction("index");
    ns_web_url ("index",
        "URL=http://172.24.1.45:8080/ORC/",
        "HEADER=Accept-Language:en-us",
        "HEADER=Upgrade-Insecure-Requests:1",
        "REDIRECT=YES",
        "LOCATION=https://172.24.1.45:8443/ORC/",
        "PreSnapshot=webpage_1502190213292.png",
        "Snapshot=webpage_1502190214082.png",
        INLINE_URLS,
            "URL=https://172.24.1.45:8443/ORC/", "HEADER=Accept-Language:en-us", "HEADER=Upgrade-Insecure-Requests:1", END_INLINE,
            "URL=https://172.24.1.45:8443/ORC/title2.htm", "HEADER=Upgrade-Insecure-Requests:1", "HEADER=Accept-Language:en-us", END_INLINE,
            "URL=https://172.24.1.45:8443/ORC/left.htm", "HEADER=Upgrade-Insecure-Requests:1", "HEADER=Accept-Language:en-us", END_INLINE,
            "URL=https://172.24.1.45:8443/ORC/t1.jpg", "HEADER=Accept-Language:en-us", END_INLINE,
            "URL=https://172.24.1.45:8443/ORC/right.htm", "HEADER=Upgrade-Insecure-Requests:1", "HEADER=Accept-Language:en-us", END_INLINE,
            "URL=https://172.24.1.45:8443/ORC/login.htm", "HEADER=Upgrade-Insecure-Requests:1", "HEADER=Accept-Language:en-us", END_INLINE,
            "URL=https://172.24.1.45:8443/ORC/seekerlog.htm", "HEADER=Upgrade-Insecure-Requests:1", "HEADER=Accept-Language:en-us", END_INLINE,
            "URL=https://172.24.1.45:8443/ORC/js/login_validation.js", "HEADER=Accept-Language:en-us", END_INLINE,
            "URL=https://172.24.1.45:8443/ORC/onlinelogin.htm", "HEADER=Upgrade-Insecure-Requests:1", "HEADER=Accept-Language:en-us", END_INLINE,
            "URL=https://172.24.1.45:8443/ORC/js/ologin_validation.js", "HEADER=Accept-Language:en-us", END_INLINE,
            "URL=https://172.24.1.45:8443/ORC/search11.htm", "HEADER=Upgrade-Insecure-Requests:1", "HEADER=Accept-Language:en-us", END_INLINE,
            "URL=https://172.24.1.45:8443/ORC/faqs.htm", "HEADER=Upgrade-Insecure-Requests:1", "HEADER=Accept-Language:en-us", END_INLINE,
            "URL=https://172.24.1.45:8443/ORC/search11.htm", END_INLINE
    );

    ns_end_transaction("index", NS_AUTO_STATUS);

    ns_page_think_time(10.089);

}
