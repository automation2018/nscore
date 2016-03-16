#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

static int p;
static char buffer[2048];
void flow1()
{

    ns_start_transaction("hpd_ex_login");
    ns_web_url("index_html",
        "METHOD=GET",
        "URL=http://127.0.0.1/tours/index.html",
        "HEADER=Accept-Language: en-us,en;q=0.5",
        "HEADER=Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", 
            "HEADER=Accept-Language: en-us, en;q=0.50", 
            "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", 
            "COOKIE =test;", 
            "HEADER=Accept-Language: en-us, en;q=0.50", 
            "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/login.gif", 
            "HEADER=Accept-Language: en-us, en;q=0.50", 
            "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
            "URL=http://127.0.0.1/tours/images/banner_merctur.jpg", 
            "HEADER=Accept-Language: en-us, en;q=0.50", 
            "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE
    );

    ns_page_think_time(0.0);
    ns_web_url("login",
        "METHOD=GET",
        "URL=http://127.0.0.1/cgi-bin/login?userSession=75893.0884568651DQADHfApHDHfcDtccpfAttcf&username={Username}&password={Password}&login.x=51&login.y=16&login=Login&JSFormSubmit=off",
	"HEADER=Accept-Language: en-us,en;q=0.5",
	"HEADER=Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7",
	INLINE_URLS,
	    "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
  	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE
    );

    ns_end_transaction("hpd_ex_login",0);
    ns_page_think_time(0.0);

    ns_start_transaction("hpd_ex_findflight");
    
    ns_web_url("reservation",
        "METHOD=GET",
	"URL=http://127.0.0.1/cgi-bin/{Pagename}",
	"HEADER=Accept-Language: en-us,en;q=0.5",
	"HEADER=Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7",
	INLINE_URLS,
	    "URL=http://127.0.0.1/tours/Merc10-dev/images/splash_Findflight.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=http://127.0.0.1/tours/images/continue.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE
    );

    ns_end_transaction("hpd_ex_findflight",0);
    ns_page_think_time(0.0);

    ns_web_url("findflight",
        "METHOD=GET",
	"URL=http://127.0.0.1/cgi-bin/findflight?depart={DepCity}&departDate={DepDate}&arrive={ArrCity}&returnDate={RetDate}&numPassengers={NumPass}&seatPref={SeatPref}&seatType={SeatType}&findFlights.x=72&findFlights.y=14&findFlights=Submit",
	"HEADER=Accept-Language: en-us,en;q=0.5",
	"HEADER=Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7",
	INLINE_URLS,
	    "URL=http://127.0.0.1/tours/images/splash_Searchresults.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=http://127.0.0.1/tours/images/startover.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE
    );

    ns_page_think_time(0.0);
    ns_start_transaction("hpd_ex_reservation");

    ns_web_url("findflight_2",
	"METHOD=GET",
	"URL=http://127.0.0.1/cgi-bin/findflight?outboundFlight=button0&hidden_outboundFlight_button0=260%7C438%7C12-06-2005&hidden_outboundFlight_button1=261%7C399%7C12-06-2005&hidden_outboundFlight_button2=262%7C418%7C12-06-2005&hidden_outboundFlight_button3=263%7C359%7C12-06-2005&numPassengers={NumPass}&advanceDiscount=&seatType={SeatType}&seatPref=None&reserveFlights.x=95&reserveFlights.y=13",
	"HEADER=Accept-Language: en-us,en;q=0.5",
	"HEADER=Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7",
	INLINE_URLS,
	    "URL=http://127.0.0.1/tours/images/splash_creditcard.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=http://127.0.0.1/tours/images/purchaseflight.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE
    );
char tmp_buf[2048];
p=atoi(ns_eval_string("{NumPass}"));
int i;
char f[]="firstname";
char l[]="lastname";
tmp_buf[0]=0;
buffer[0]=0;
for (i = 1; i < p+1; i++)
{
strcat(buffer, tmp_buf);
}
ns_save_string(buffer,"buffer");

    ns_page_think_time(0.0);

    ns_web_url("findflight_3",
	"METHOD=GET",
	"URL=http://127.0.0.1/cgi-bin/findflight?firstName=Tiger&lastName=Scott&address1=4261+Stevenson+Blvd.&address2=Fremont%2C+CA+94538&{buffer}creditCard=1234&expDate=0109&oldCCOption=&numPassengers={NumPass}&seatType={SeatType}&seatPref={SeatPref}&outboundFlight=260%7C438%7C12-06-2005&advanceDiscount=&buyFlights.x=88&buyFlights.y=11&.cgifields=saveCC",
	"HEADER=Accept-Language: en-us,en;q=0.5",
	"HEADER=Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7",
	INLINE_URLS,
	    "URL=http://127.0.0.1/tours/images/splash_flightconfirm.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE,
	    "URL=http://127.0.0.1/tours/images/bookanother.gif", 
	    "HEADER=Accept-Language: en-us, en;q=0.50", 
	    "HEADER=Accept-Charset: ISO-8859-1, utf-8;q=0.66, *;q=0.66", END_INLINE
    );

    ns_end_transaction("hpd_ex_reservation",0);
    ns_page_think_time(0.0);

    ns_start_transaction("hpd_ex_logout");

    ns_web_url("welcome",
	"METHOD=GET",
	"URL=http://127.0.0.1/cgi-bin/welcome",
	"HEADER=Accept-Language: en-us,en;q=0.5",
	"HEADER=Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7",
    );

    ns_end_transaction("hpd_ex_logout",0);
    ns_page_think_time(0.0);
}
