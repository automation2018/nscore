#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"


void flow1()
{
    ns_start_transaction("hpd_ssl_page1_trans1");

    ns_web_url("index_html",
	"METHOD=GET",
	"URL=https://127.0.0.1/tours/index.html",
	"HEADER=Accept-Language: en-us,en;q=0.5",
	"HEADER=Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7",
	INLINE_URLS,
	    "URL=https://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language: en-us, en;q=0.50",
 	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=https://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", 
	    "COOKIE=a;", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=https://127.0.0.1/tours/Merc10-dev/images/login.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=https://127.0.0.1/tours/images/banner_merctur.jpg", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE
    );

    ns_end_transaction("hpd_ssl_page1_trans1",0);
    ns_page_think_time(0.0);

    ns_start_transaction("hpd_ssl_page2_trans2");

    ns_web_url("login",
	"METHOD=GET",
	"URL=https://127.0.0.1/cgi-bin/login?userSession=75893.0884568651DQADHfApHDHfcDtccpfAttcf&username=guest&password=guest&login.x=51&login.y=16&login=Login&JSFormSubmit=off",
	"HEADER=Accept-Language: en-us,en;q=0.5",
	"HEADER=Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7",
	INLINE_URLS,
	    "URL=https://127.0.0.1/tours/Merc10-dev/images/flights.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=https://127.0.0.1/tours/Merc10-dev/images/home.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=https://127.0.0.1/tours/Merc10-dev/images/signoff.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=https://127.0.0.1/tours/vep/images/velocigen.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE
    );

    ns_end_transaction("hpd_ssl_page2_trans2",0);
    ns_page_think_time(0.0);

    ns_start_transaction("hpd_ssl_page3_trans3");

    ns_web_url("reservation",
	"METHOD=GET",
	"URL=https://127.0.0.1/cgi-bin/reservation",
	"HEADER=Accept-Language: en-us,en;q=0.5",
	"HEADER=Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7",
	INLINE_URLS,
	    "URL=https://127.0.0.1/tours/Merc10-dev/images/splash_Findflight.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=https://127.0.0.1/tours/images/continue.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE
    );
    
    ns_end_transaction("hpd_ssl_page3_trans3",0);
    ns_page_think_time(0.0);

    ns_start_transaction("hpd_ssl_page4_trans4");

    ns_web_url("findflight",
	"METHOD=GET",
	"URL=https://127.0.0.1/cgi-bin/findflight?depart=London&departDate=12-06-2005&arrive=San+Francisco&returnDate=12-07-2005&numPassengers=1&seatPref=None&seatType=Coach&findFlights.x=72&findFlights.y=14&findFlights=Submit",
	"HEADER=Accept-Language: en-us,en;q=0.5",
	"HEADER=Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7",
	INLINE_URLS,
	    "URL=https://127.0.0.1/tours/images/splash_Searchresults.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=https://127.0.0.1/tours/images/startover.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE
    );

    ns_end_transaction("hpd_ssl_page4_trans4", 0);
    ns_page_think_time(0.0);

    ns_start_transaction("hpd_ssl_page5_trans5");

    ns_web_url("findflight_2",
	"METHOD=GET",
	"URL=https://127.0.0.1/cgi-bin/findflight?outboundFlight=button0&hidden_outboundFlight_button0=260%7C438%7C12-06-2005&hidden_outboundFlight_button1=261%7C399%7C12-06-2005&hidden_outboundFlight_button2=262%7C418%7C12-06-2005&hidden_outboundFlight_button3=263%7C359%7C12-06-2005&numPassengers=1&advanceDiscount=&seatType=Coach&seatPref=None&reserveFlights.x=95&reserveFlights.y=13",
	"HEADER=Accept-Language: en-us,en;q=0.5",
	"HEADER=Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7",
	INLINE_URLS,
	    "URL=https://127.0.0.1/tours/images/splash_creditcard.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=https://127.0.0.1/tours/images/purchaseflight.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE
    );

    ns_end_transaction("hpd_ssl_page5_trans5",0);
    ns_page_think_time(0.0);

    ns_start_transaction("hpd_ssl_page6_trans6");

    ns_web_url("findflight_3",
	"METHOD=GET",
	"URL=https://127.0.0.1/cgi-bin/findflight?firstName=Tiger&lastName=Scott&address1=4261+Stevenson+Blvd.&address2=Fremont%2C+CA+94538&pass1=Scott+Tiger&creditCard=1234&expDate=0109&oldCCOption=&numPassengers=1&seatType=Coach&seatPref=None&outboundFlight=260%7C438%7C12-06-2005&advanceDiscount=&buyFlights.x=88&buyFlights.y=11&.cgifields=saveCC",
	"HEADER=Accept-Language: en-us,en;q=0.5",
	"HEADER=Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7",
	INLINE_URLS,
	    "URL=https://127.0.0.1/tours/images/splash_flightconfirm.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=https://127.0.0.1/tours/images/bookanother.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE
    );

    ns_end_transaction("hpd_ssl_page6_trans6",0);
    ns_page_think_time(0.0);

    ns_start_transaction("hpd_ssl_page7_trans7");

    ns_web_url("welcome",
	"METHOD=GET",
	"URL=https://127.0.0.1/cgi-bin/welcome",
	"HEADER=Accept-Language: en-us,en;q=0.5",
	"HEADER=Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7"
    );

    ns_end_transaction("hpd_ssl_page7_trans7",0);
    ns_page_think_time(0.0);
}
