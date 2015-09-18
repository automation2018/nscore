/*-----------------------------------------------------------------------------
    Name: Passenger
    Recorded By: netstorm
    Date of recording: 7/1/2011 11:22:15
    Flow details:
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"
void Passenger()
{
    ns_start_transaction("TxnPassengerFlow");
    ns_web_url ("index_html_3",
        "URL=http://127.0.0.1/tours/index.html",
        "HEADER=Accept-Language: en-US",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/login.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/images/banner_merctur.jpg", "HEADER=Accept-Language: en-US", END_INLINE
    );

    ns_web_url ("login_3",
        "URL=http://127.0.0.1/cgi-bin/login?userSession=75893.0884568651DQADHfApHDHfcDtccpfAttcf&username=saurabh&password=caisson&JSFormSubmit=off&login.x=49&login.y=4",
        "HEADER=Accept-Language: en-US",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/images/banner_merctur.jpg", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language: en-US", END_INLINE
    );

    ns_web_url ("reservation_2",
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
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language: en-US", END_INLINE
    );

    ns_web_url ("findflight",
        "URL=http://127.0.0.1/cgi-bin/findflight?depart=Acapulco&departDate=07-02-2011&arrive=Acapulco&returnDate=07-03-2011&numPassengers=1&seatPref=None&seatType=Coach&findFlights.x=48&findFlights.y=12",
        "HEADER=Accept-Language: en-US",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/images/startover.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/images/splash_Searchresults.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/images/startover.gif", "HEADER=Accept-Language: en-US", END_INLINE
    );

    ns_web_url ("findflight_2",
        "URL=http://127.0.0.1/cgi-bin/findflight?outboundFlight=button0&hidden_outboundFlight_button0=000%7C0%7C07-02-2011&hidden_outboundFlight_button1=001%7C0%7C07-02-2011&hidden_outboundFlight_button2=002%7C0%7C07-02-2011&hidden_outboundFlight_button3=003%7C0%7C07-02-2011&numPassengers=1&advanceDiscount=&seatType=Coach&seatPref=None&reserveFlights.x=99&reserveFlights.y=9",
        "HEADER=Accept-Language: en-US",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/images/splash_creditcard.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/images/purchaseflight.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/images/startover.gif", "HEADER=Accept-Language: en-US", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language: en-US", END_INLINE
    );
    ns_end_transaction("TxnPassengerFlow", NS_AUTO_STATUS);
}
