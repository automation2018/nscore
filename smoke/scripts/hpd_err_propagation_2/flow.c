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
    ns_start_transaction("tx_first");
    ns_web_url ("index",
        "URL=http://127.0.0.1/tours/index.html",
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
   

    ns_start_transaction("tx_second");
    ns_web_url ("login",
        "URL=http://127.0.0.1/loginSubmit",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124046151.png",
        "Snapshot=webpage_13946124046821.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/images/banner_merctur.jpg", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
     );

     ns_page_think_time(2.0);
	 ns_end_transaction("tx_second", NS_AUTO_STATUS);
   
  
	 ns_web_url("reservation",
	     "URL=http://127.0.0.1/cgi-bin/reservation",
		 "HEADER=Accept-Language:en-us,en;q=0.5",
		 "PreSnapshot=webpage_13946124048461.png",
		 "Snapshot=webpage_13946124049111.png",
		 INLINE_URLS,
		     "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
			 "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
			 "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
			 "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
			 "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
			 "URL=http://127.0.0.1/tours/Merc10-dev/images/splash_Findflight.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
			 "URL=http://127.0.0.1/tours/images/continue.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
			 "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
	 );
	 
	 ns_page_think_time(1.0);
	ns_end_transaction("tx_first", NS_AUTO_STATUS);
}
