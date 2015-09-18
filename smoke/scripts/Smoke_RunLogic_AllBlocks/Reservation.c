/*-----------------------------------------------------------------------------
    Name: Reservation
    Recorded By: netstorm
    Date of recording: 7/1/2011 11:21:26
    Flow details:
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"
void Reservation()
{
    ns_start_transaction("TxnReservationFlow");
    ns_web_url ("index_html_2",
        "URL=http://127.0.0.1/tours/index.html",
        "HEADER=Accept-Language: en-US",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/login.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/images/banner_merctur.jpg", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/login.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/images/banner_merctur.jpg", "HEADER=Accept-Language: en-US", END_INLINE
    );

    ns_web_url ("login_2",
        "URL=http://127.0.0.1/cgi-bin/login?userSession=75893.0884568651DQADHfApHDHfcDtccpfAttcf&username=saurabh&password=cavisson&JSFormSubmit=off&login.x=63&login.y=4",
        "HEADER=Accept-Language: en-US",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language: en-US", END_INLINE
    );

    ns_web_url ("reservation",
        "URL=http://127.0.0.1/cgi-bin/reservation",
        "HEADER=Accept-Language: en-US",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/splash_Findflight.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/images/continue.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language: en-US", END_INLINE
    );
    ns_end_transaction("TxnReservationFlow", NS_AUTO_STATUS);
}
