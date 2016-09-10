/*-----------------------------------------------------------------------------
    Name: flow
    Recorded By: netstorm
    Date of recording: 01/25/2014 01:45:58
    Flow details:
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow_save()
{

//ns_advance_param("BrowserUserProfile");
//ns_advance_param("HarLogDir");
//ns_advance_param("VncDisplayId");
	
char prof[256];
char log[256];
char id[256];

  strcpy(prof, ns_eval_string("{BrowserUserProfile}"));
  strcpy(log, ns_eval_string("{HarLogDir}"));
  strcpy(id, ns_eval_string("{VncDisplayId}"));

printf("BrowserUserProfile = [%s], HarLogDir = [%s], VncDisplayId = [%s]\n\n",
              prof, log, id);

    ns_start_transaction("Dummy");
	ns_web_url ("DummyPage",
        "URL=http://192.168.1.93:9062/tiny",
        "PageLoadWaitTime=30",
        "BrowserUserProfile={BrowserUserProfile}",
        "HarLogDir={HarLogDir}",
        "VncDisplayId={VncDisplayId}",
        "HarRenameFlag=1",
   );
    ns_end_transaction("Dummy", NS_AUTO_STATUS);
    
    ns_start_transaction("IndexPage");
    ns_web_url ("index_html",
        "URL=http://192.168.1.93:9062/tours/index.html#{BrowserUserProfile}",
        "METHOD=POST",
	"HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_1390637723595.png",
        "Snapshot=webpage_1390637723895.png",
        "PageLoadWaitTime=30",
        "BrowserUserProfile={BrowserUserProfile}",
        "HarLogDir={HarLogDir}",
        "VncDisplayId={VncDisplayId}",
	"HarRenameFlag=1",
	"BODY=THIS IS tours/index.html PAGE....!!!"
        INLINE_URLS,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/login.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/images/banner_merctur.jpg", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    );

    ns_page_think_time(11.65);
    ns_end_transaction("IndexPage", NS_AUTO_STATUS);
    ns_start_transaction("login");    
    ns_web_url ("login",
        "URL=http://192.168.1.93:9062/cgi-bin/login?userSession=75893.0884568651DQADHfApHDHfcDtccpfAttcf&username=&password=&login.x=50&login.y=7&login=Login&JSFormSubmit=off#{BrowserUserProfile}",
	"METHOD=POST",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_1390637735535.png",
        "Snapshot=webpage_1390637736107.png",
        "PageLoadWaitTime=30",
        "BrowserUserProfile={BrowserUserProfile}",
        "HarLogDir={HarLogDir}",
        "VncDisplayId={VncDisplayId}",
	"HarRenameFlag=1",
	"BODY=$CAVINCLUDE$=req.html",
        INLINE_URLS,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/images/banner_merctur.jpg", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    );

    ns_page_think_time(2.35);
    ns_end_transaction("login", NS_AUTO_STATUS);
    ns_start_transaction("Reservation");    
    //Page Auto splitted for Image Link 'Search Flights Button' Clicked by User
    ns_web_url ("reservation",
        "URL=http://192.168.1.93:9062/cgi-bin/reservation#{BrowserUserProfile}",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_1390637738397.png",
        "Snapshot=webpage_1390637739077.png",
        "PageLoadWaitTime=30",
        "BrowserUserProfile={BrowserUserProfile}",
        "HarLogDir={HarLogDir}",
        "VncDisplayId={VncDisplayId}",
	"HarRenameFlag=1",
        INLINE_URLS,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/splash_Findflight.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/images/continue.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    );

    ns_page_think_time(1.77);
    ns_end_transaction("Reservation", NS_AUTO_STATUS);
        
    ns_start_transaction("FindFlight");
    //Page Auto splitted for Image Link 'findFlights' Clicked by User
    ns_web_url ("findflight",
        "URL=http://192.168.1.93:9062/cgi-bin/findflight?depart=Acapulco&departDate=01-26-2014&arrive=Acapulco&returnDate=01-27-2014&numPassengers=1&seatPref=None&seatType=Coach&findFlights.x=48&findFlights.y=21&findFlights=Submit#{BrowserUserProfile}",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_1390637740857.png",
        "Snapshot=webpage_1390637741597.png",
        "PageLoadWaitTime=30",
        "BrowserUserProfile={BrowserUserProfile}",
        "HarLogDir={HarLogDir}",
        "VncDisplayId={VncDisplayId}",
	"HarRenameFlag=1",
        INLINE_URLS,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/images/splash_Searchresults.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/images/continue.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/images/startover.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    );

    ns_page_think_time(1.18);
    ns_end_transaction("FindFlight", NS_AUTO_STATUS);
    
    ns_start_transaction("FindFlight_2");    
    //Page Auto splitted for Image Link 'reserveFlights' Clicked by User
    ns_web_url ("findflight_2",
        "URL=http://192.168.1.93:9062/cgi-bin/findflight?outboundFlight=button0&hidden_outboundFlight_button0=000%7C0%7C01-26-2014&hidden_outboundFlight_button1=001%7C0%7C01-26-2014&hidden_outboundFlight_button2=002%7C0%7C01-26-2014&hidden_outboundFlight_button3=003%7C0%7C01-26-2014&numPassengers=1&advanceDiscount=&seatType=Coach&seatPref=None&reserveFlights.x=74&reserveFlights.y=10#{BrowserUserProfile}",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_1390637742787.png",
        "Snapshot=webpage_1390637743709.png",
        "PageLoadWaitTime=30",
        "BrowserUserProfile={BrowserUserProfile}",
        "HarLogDir={HarLogDir}",
        "VncDisplayId={VncDisplayId}",
	"HarRenameFlag=1",
        INLINE_URLS,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/images/splash_creditcard.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/images/purchaseflight.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/images/startover.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    );

    ns_page_think_time(3.18);
    ns_end_transaction("FindFlight_2", NS_AUTO_STATUS);    
   
    ns_start_transaction("FindFlight_3");
    //Page Auto splitted for Image Link 'buyFlights' Clicked by User
    ns_web_url ("findflight_3",
        "URL=http://192.168.1.93:9062/cgi-bin/findflight?firstName=Tiger&lastName=Scott&address1=4261+Stevenson+Blvd.&address2=Fremont%2C+CA+94538&pass1=Scott+Tiger&creditCard=&expDate=&oldCCOption=&numPassengers=1&seatType=Coach&seatPref=None&outboundFlight=000%7C0%7C01-26-2014&advanceDiscount=&buyFlights.x=98&buyFlights.y=24&.cgifields=saveCC#{BrowserUserProfile}",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_1390637746849.png",
        "Snapshot=webpage_1390637747661.png",
        "PageLoadWaitTime=30",
        "BrowserUserProfile={BrowserUserProfile}",
        "HarLogDir={HarLogDir}",
        "VncDisplayId={VncDisplayId}",
	"HarRenameFlag=1",
        INLINE_URLS,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/images/splash_flightconfirm.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/images/bookanother.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    );

    ns_page_think_time(3.4);
    ns_end_transaction("FindFlight_3", NS_AUTO_STATUS);
    
    ns_start_transaction("Welcome");    
    //Page Auto splitted for Image Link 'SignOff Button' Clicked by User
    ns_web_url ("welcome",
        "URL=http://192.168.1.93:9062/cgi-bin/welcome#{BrowserUserProfile}",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_1390637751011.png",
        "Snapshot=webpage_1390637751593.png",
        "PageLoadWaitTime=30",
        "BrowserUserProfile={BrowserUserProfile}",
        "HarLogDir={HarLogDir}",
        "VncDisplayId={VncDisplayId}",
	"HarRenameFlag=1",
        INLINE_URLS,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/Merc10-dev/images/login.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/images/banner_merctur.jpg", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://192.168.1.93:9062/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    );

    ns_page_think_time(6.6);
    ns_end_transaction("Welcome", NS_AUTO_STATUS);    
/*
	ns_start_transaction("NewURL");	
	ns_web_url ("NewURL",
        "URL=http://kperf.skavaone.com/kohlsopenapi/subcategorymobile.html?id=0&keyword=gold%20toe%20socks#brm-search?request_type=search&search_type=keyword&q=gold%20toe%20socks&l=gold%20toe%20socks",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_1390637751011.png",
        "Snapshot=webpage_1390637751593.png",
        "PageLoadWaitTime=30",
        "BrowserUserProfile={BrowserUserProfile}",
        "HarLogDir={HarLogDir}",
        "VncDisplayId={VncDisplayId}",
        "HarRenameFlag=1",
    );

    ns_page_think_time(6.6);
    ns_end_transaction("NewURL", NS_AUTO_STATUS);
*/
	ns_start_transaction("StaticURL");
	ns_web_url ("StaticURL",
        "URL=http://192.168.1.93:9062/custom/samples/test_apps/online_order.xml",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_1390637751011.png",
        "Snapshot=webpage_1390637751593.png",
        "PageLoadWaitTime=30",
        "BrowserUserProfile={BrowserUserProfile}",
        "HarLogDir={HarLogDir}",
        "VncDisplayId={VncDisplayId}",
        "HarRenameFlag=1",
    );

    ns_page_think_time(6.6);
    ns_end_transaction("StaticURL", NS_AUTO_STATUS);

    ns_stop_browser("{BrowserUserProfile}");
}
