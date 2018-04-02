/*-----------------------------------------------------------------------------
    Name: flow
    Written By: Asheesh Tivaree
    Date of recording: 23/Jan/018
    Flow details:
    Build details: 4.1.11
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow()
{
    ns_start_transaction("Script1_Pushed_3_Resources");
    ns_web_url ("Script1_Pushed_3_Resources",
        "URL=https://127.0.0.1/ServerPush/index.html",
        INLINE_URLS,
        "URL=https://127.0.0.1/ServerPush/Merc10-dev/images/banner_animated.gif", END_INLINE,
        "URL=https://127.0.0.1/ServerPush/Merc10-dev/images/sun_swede.gif", END_INLINE,
        "URL=https://127.0.0.1/ServerPush/Merc10-dev/images/login.gif", END_INLINE,
        "URL=https://127.0.0.1/ServerPush/images/banner_merctur.jpg", END_INLINE,
    );

    ns_end_transaction("Script1_Pushed_3_Resources", NS_AUTO_STATUS);
    ns_page_think_time(6.724);
    
    ns_start_transaction("Script1_Pushed_5_Resources");
    ns_web_url ("Script1_Pushed_5_Resources",
        "URL=https://127.0.0.1/ServerPush/push/push.html",
        INLINE_URLS,
        "URL=https://127.0.0.1/ServerPush/push/script.js", END_INLINE,
        "URL=https://127.0.0.1/ServerPush/push/style.css", END_INLINE,
        "URL=https://127.0.0.1/ServerPush/push/images/sun_swede1.gif", END_INLINE,
        "URL=https://127.0.0.1/ServerPush/push/images/sun_swede2.gif", END_INLINE,
        "URL=https://127.0.0.1/ServerPush/push/images/sun_swede3.gif", END_INLINE,
        "URL=https://127.0.0.1/ServerPush/push/images/sun_swede4.gif", END_INLINE,
        "URL=https://127.0.0.1/ServerPush/push/images/sun_swede5.gif", END_INLINE,
        "URL=https://127.0.0.1/ServerPush/push/images/sun_swede6.gif", END_INLINE,
        "URL=https://127.0.0.1/ServerPush/push/images/sun_swede7.gif", END_INLINE,
        "URL=https://127.0.0.1/ServerPush/push/images/sun_swede8.gif", END_INLINE,
        "URL=https://127.0.0.1/ServerPush/push/images/sun_swede9.gif", END_INLINE,
        "URL=https://127.0.0.1/ServerPush/push/images/sun_swede10.gif", END_INLINE,
        "URL=https://127.0.0.1/ServerPush/push/images/sun_swede11.gif", END_INLINE,
    );

    ns_end_transaction("Script1_Pushed_5_Resources", NS_AUTO_STATUS);
    ns_page_think_time(6.724);
    
    ns_start_transaction("Script1_Pushed_2_Resources");
    ns_web_url ("Script1_Pushed_2_Resources",
        "URL=https://127.0.0.1/ServerPush/new/test.html",
        INLINE_URLS,
        "URL=https://127.0.0.1/ServerPush/new/style.css", END_INLINE,
        "URL=https://127.0.0.1/ServerPush/new/script.js", END_INLINE,
    );

    ns_end_transaction("Script1_Pushed_2_Resources", NS_AUTO_STATUS);
    ns_page_think_time(6.724);
}
