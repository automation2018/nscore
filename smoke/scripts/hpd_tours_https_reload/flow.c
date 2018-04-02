/*-----------------------------------------------------------------------------

    Name: flow
    Recorded By: anupam
    Date of recording: 03/12/2014 02:51:06
    Flow details:
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"


void flow()
{
   ns_start_transaction("IndexPage");
    ns_web_url ("index",
        "URL=https://127.0.0.1/service.html",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124026631.png",
        "Snapshot=webpage_13946124027021.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/login.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/images/banner_merctur.jpg", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    );

    ns_page_think_time(0.2);
    ns_end_transaction("IndexPage", NS_AUTO_STATUS);
    
 }
