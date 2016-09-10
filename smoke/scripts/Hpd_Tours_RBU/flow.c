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
    ns_web_url ("index_html",
        "URL=http://10.10.30.38/tours/index.html",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "HEADER=VALUE:SG",
        "PreSnapshot=webpage_13946124026631.png",
        "Snapshot=webpage_13946124027021.png",
        "PageLoadWaitTime=60",
//        "PageLoadWaitTime=120",
        "BrowserUserProfile={BrowserUserProfile}",
        "HarLogDir={HarLogDir}",
        "VncDisplayId={VncDisplayId}",
        "HarRenameFlag=1",
/*        INLINE_URLS,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/login.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/images/banner_merctur.jpg", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
  */  );


    ns_end_transaction("IndexPage", NS_AUTO_STATUS);
   ns_page_think_time(2.0);
    ns_start_transaction("Login");
    ns_web_url ("login",
        "URL=http://10.10.30.38/cgi-bin/login?userSession=75893.0884568651DQADHfApHDHfcDtccpfAttcf&username=saurabh&password=cavisson&login.x=0&login.y=0&login=Login&JSFormSubmit=off",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124046151.png",
        "Snapshot=webpage_13946124046821.png",
        "PageLoadWaitTime=60",
//        "PageLoadWaitTime=120",
        "BrowserUserProfile={BrowserUserProfile}",
        "HarLogDir={HarLogDir}",
        "VncDisplayId={VncDisplayId}",
        "HarRenameFlag=1",
    /*    INLINE_URLS,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/images/banner_merctur.jpg", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
   */ );

//    ns_page_think_time(2.0);


   ns_end_transaction("Login", NS_AUTO_STATUS);
ns_page_think_time(2.0);
    ns_start_transaction("Reservation");
    //Page Auto splitted for Image Link 'Search Flights Button' Clicked by User
    ns_web_url ("reservation",
        "URL=http://10.10.30.38/cgi-bin/reservation",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124048461.png",
        "Snapshot=webpage_13946124049111.png",
        "PageLoadWaitTime=60",
//        "PageLoadWaitTime=120",
        "BrowserUserProfile={BrowserUserProfile}",
        "HarLogDir={HarLogDir}",
        "VncDisplayId={VncDisplayId}",
        "HarRenameFlag=1",
     /*   INLINE_URLS,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/splash_Findflight.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/images/continue.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
   */ );

//   ns_page_think_time(2.0);
    ns_end_transaction("Reservation", NS_AUTO_STATUS);

    ns_start_transaction("FindFlight");
    ns_web_url ("findflight",
        "URL=http://10.10.30.38/cgi-bin/findflight?depart=Acapulco&departDate=03-13-2014&arrive=Acapulco&returnDate=03-14-2014&numPassengers=1&seatPref=None&seatType=Coach&findFlights.x=42&findFlights.y=9&findFlights=Submit",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124050301.png",
        "Snapshot=webpage_13946124051084.png",
        "PageLoadWaitTime=60",
//        "PageLoadWaitTime=120",
        "BrowserUserProfile={BrowserUserProfile}",
        "HarLogDir={HarLogDir}",
        "VncDisplayId={VncDisplayId}",
        "HarRenameFlag=1",
     /*   INLINE_URLS,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/images/splash_Searchresults.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/images/continue.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/images/startover.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
   */ );

   // ns_page_think_time(2.0);
    ns_end_transaction("FindFlight", NS_AUTO_STATUS);
ns_page_think_time(2.0);
    ns_start_transaction("FindFlight2");
    ns_web_url ("findflight_2",
        "URL=http://10.10.30.38/cgi-bin/findflight?outboundFlight=button0&hidden_outboundFlight_button0=000%7C0%7C03-13-2014&hidden_outboundFlight_button1=001%7C0%7C03-13-2014&hidden_outboundFlight_button2=002%7C0%7C03-13-2014&hidden_outboundFlight_button3=003%7C0%7C03-13-2014&numPassengers=1&advanceDiscount=&seatType=Coach&seatPref=None&reserveFlights.x=77&reserveFlights.y=9",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124052189.png",
        "Snapshot=webpage_13946124052857.png",
        "PageLoadWaitTime=60",
//        "PageLoadWaitTime=120",
        "BrowserUserProfile={BrowserUserProfile}",
        "HarLogDir={HarLogDir}",
        "VncDisplayId={VncDisplayId}",
        "HarRenameFlag=1",
     /*   INLINE_URLS,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/images/splash_creditcard.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/images/purchaseflight.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/images/startover.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    */);

 //   ns_page_think_time(2.0);

    ns_end_transaction("FindFlight2", NS_AUTO_STATUS);
ns_page_think_time(2.0);
    ns_start_transaction("FindFlight3");
    ns_web_url ("findflight_3",
        "URL=http://10.10.30.38/cgi-bin/findflight?firstName=Tiger&lastName=Scott&address1=4261+Stevenson+Blvd.&address2=Fremont%2C+CA+94538&pass1=Scott+Tiger&creditCard=&expDate=&oldCCOption=&numPassengers=1&seatType=Coach&seatPref=None&outboundFlight=000%7C0%7C03-13-2014&advanceDiscount=&buyFlights.x=36&buyFlights.y=12&.cgifields=saveCC",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124054874.png",
        "Snapshot=webpage_13946124055544.png",
        "PageLoadWaitTime=60",
//        "PageLoadWaitTime=120",
        "BrowserUserProfile={BrowserUserProfile}",
        "HarLogDir={HarLogDir}",
        "VncDisplayId={VncDisplayId}",
        "HarRenameFlag=1",
      /*  INLINE_URLS,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/images/splash_flightconfirm.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/images/bookanother.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
   */ );

//    ns_page_think_time(2.0);
    ns_end_transaction("FindFlight3", NS_AUTO_STATUS);
ns_page_think_time(2.0);
    ns_start_transaction("Welcome");
    ns_web_url ("welcome",
        "URL=http://10.10.30.38/cgi-bin/welcome",
//	"METHOD=POST",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124059964.png",
        "Snapshot=webpage_13946124060496.png",
        "PageLoadWaitTime=60",
//        "PageLoadWaitTime=120",
        "BrowserUserProfile={BrowserUserProfile}",
        "HarLogDir={HarLogDir}",
        "VncDisplayId={VncDisplayId}",
        "HarRenameFlag=1",
//	"BODY=$CAVINCLUDE$=req.html",
     /*   INLINE_URLS,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/Merc10-dev/images/login.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/images/banner_merctur.jpg", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.10.30.38/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    */);

}
