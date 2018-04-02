/*-----------------------------------------------------------------------------
    Name: flow
    Recorded By: netstorm
    Date of recording: 03/27/2017 11:29:46
    Flow details:
    Build details: 4.1.7 (build# 41)
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow()
{
	    int *ptr=ns_get_sessid();
		char *val1,*val2;
		val1=ns_eval_string("{sp}");
	    val2=ns_eval_string("{dp1}");
		 //printf("****value before condition, first [%s] , second [%s]\n\n",val1,val2);
		if(strcmp(val1,"")!=0 &&  strcmp(val2,"")!=0)
		{	
		printf("\n\n\nThis is session : %d\n\n",ptr);
		printf("\n\n\nThis is new session and value of search para [%s] is persisting \n\n\n", val1);
		printf("\n\n\nThis is new session and value of declare para [%s] is persisting \n\n\n", val2);
		}
		else
		{
			printf("\n\n\nParametrer value is not persisting\n\n");
		}
	
	
    ns_start_transaction("index_html");
    ns_web_url ("index_html",
        "URL=http://127.0.0.1/tours/index.html",
        "HEADER=Upgrade-Insecure-Requests:1************value of search: {sp}",
        "HEADER=Accept-Language:en-in",
        "PreSnapshot=webpage_1490594338528.png",
        "Snapshot=webpage_1490594340834.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/login.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/images/banner_merctur.jpg", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE
    );

    ns_end_transaction("index_html", NS_AUTO_STATUS);
    ns_page_think_time(13.461);

    ns_start_transaction("login");
    ns_web_url ("login",
        "URL=http://127.0.0.1/cgi-bin/login?userSession=75893.0884568651DQADHfApHDHfcDtccpfAttcf&username=netstorm&password=netstorm&login.x=60&login.y=16&login=Login&JSFormSubmit=off",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "PreSnapshot=webpage_1490594353952.png",
        "Snapshot=webpage_1490594355477.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/images/banner_merctur.jpg", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE
    );

    ns_end_transaction("login", NS_AUTO_STATUS);
    ns_page_think_time(2.92);
    
    ns_save_string(ns_eval_string("{sp}"),"dp1");
    
   // printf("\n\n*************value of search para is: %s\n\n", ns_eval_string("{sp}"));
   // printf("\n\n**************value of decl para is: %s\n\n", ns_eval_string("{dp1}"));

    ns_start_transaction("reservation");
    ns_web_url ("reservation",
        "URL=http://127.0.0.1/cgi-bin/reservation",
        "HEADER=Upgrade-Insecure-Requests:1************value of search: {sp}",
        "HEADER=Accept-Language:en-in",
        "PreSnapshot=webpage_1490594358371.png",
        "Snapshot=webpage_1490594358868.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/splash_Findflight.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/images/continue.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE
    );

    ns_end_transaction("reservation", NS_AUTO_STATUS);
    ns_page_think_time(2.865);

    ns_start_transaction("reservation_2");
    ns_web_url ("reservation_2",
        "URL=http://127.0.0.1/cgi-bin/reservation",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "PreSnapshot=webpage_1490594361721.png",
        "Snapshot=webpage_1490594362929.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/splash_Findflight.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/images/continue.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE
    );

    ns_end_transaction("reservation_2", NS_AUTO_STATUS);
    ns_page_think_time(4.167);

    ns_start_transaction("findflight");
    ns_web_url ("findflight",
        "URL=http://127.0.0.1/cgi-bin/findflight?depart=Acapulco&departDate=04-01-2017&arrive=Acapulco&returnDate=04-02-2017&numPassengers=1&seatPref=None&seatType=Coach&findFlights.x=78&findFlights.y=13&findFlights=Submit",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "PreSnapshot=webpage_1490594367084.png",
        "Snapshot=webpage_1490594368952.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/images/splash_Searchresults.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/images/startover.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/images/continue.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE
    );

    ns_end_transaction("findflight", NS_AUTO_STATUS);
    ns_page_think_time(4.124);

    ns_start_transaction("findflight_2");
    ns_web_url ("findflight_2",
        "URL=http://127.0.0.1/cgi-bin/findflight?outboundFlight=button0&hidden_outboundFlight_button0=000%7C0%7C04-01-2017&hidden_outboundFlight_button1=001%7C0%7C04-01-2017&hidden_outboundFlight_button2=002%7C0%7C04-01-2017&hidden_outboundFlight_button3=003%7C0%7C04-01-2017&numPassengers=1&advanceDiscount=&seatType=Coach&seatPref=None&reserveFlights.x=72&reserveFlights.y=6",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "PreSnapshot=webpage_1490594372699.png",
        "Snapshot=webpage_1490594373296.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/images/splash_creditcard.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/images/startover.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/images/purchaseflight.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE
    );

    ns_end_transaction("findflight_2", NS_AUTO_STATUS);
    ns_page_think_time(5.356);

    ns_start_transaction("findflight_3");
    ns_web_url ("findflight_3",
        "URL=http://127.0.0.1/cgi-bin/findflight?firstName=Tiger&lastName=Scott&address1=4261+Stevenson+Blvd.&address2=Fremont%2C+CA+94538&pass1=Scott+Tiger&creditCard=&expDate=&oldCCOption=&numPassengers=1&seatType=Coach&seatPref=None&outboundFlight=000%7C0%7C04-01-2017&advanceDiscount=&buyFlights.x=34&buyFlights.y=24&.cgifields=saveCC",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "PreSnapshot=webpage_1490594378620.png",
        "Snapshot=webpage_1490594378871.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/images/splash_flightconfirm.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/images/bookanother.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE
    );

    ns_end_transaction("findflight_3", NS_AUTO_STATUS);
    ns_page_think_time(4.402);

    ns_start_transaction("welcome");
    ns_web_url ("welcome",
        "URL=http://127.0.0.1/cgi-bin/%url",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "PreSnapshot=webpage_1490594383238.png",
        "Snapshot=webpage_1490594383382.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/login.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/images/banner_merctur.jpg", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-in", "COOKIE=Name1;Name2", END_INLINE
    );

    ns_end_transaction("welcome", NS_AUTO_STATUS);
    ns_page_think_time(2.832);

}
