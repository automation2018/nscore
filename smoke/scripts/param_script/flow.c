/*-----------------------------------------------------------------------------
    Name: flow
    Recorded By: netstorm
    Date of recording: 01/23/2016 01:02:04
    Flow details:
    Build details: 4.1.5 (build# 2)
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow()
{
    ns_start_transaction("Home");
    ns_web_url ("Home",
       // "URL=http://127.0.0.1/tours/index.html",
        "URL=http://127.0.0.1/tours/index.html",
        "HEADER=Accept-Language:en-us,en;q=0.5; random_string={PassengernoRN}",
        "PreSnapshot=webpage_1453582771179.png",
        "Snapshot=webpage_1453582771393.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/login.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/images/banner_merctur.jpg", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    );
    ns_end_transaction("Home", NS_AUTO_STATUS);
    ns_page_think_time(0);

    //Page Auto splitted for Image Link 'Login' Clicked by User
    ns_start_transaction("Login");
    ns_web_url ("Login",
        //"URL=http://127.0.0.1/cgi-bin/login?userSession=75893.0884568651DQADHfApHDHfcDtccpfAttcf&username=netstorm&password=netstorm&login.x=59&login.y=14&login=Login&JSFormSubmit=off",
        "URL=http://127.0.0.1/cgi-bin/login?userSession={SessionIdSP}&username={UnameFP}&password={UpassFP}&login.x=59&login.y=14&login=Login&JSFormSubmit=off",
        "HEADER=Accept-Language:en-us,en;q=0.5;random_string={PassengernoRN}",
        "PreSnapshot=webpage_1453582787193.png",
        "Snapshot=webpage_1453582787520.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/images/banner_merctur.jpg", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    );
    ns_end_transaction("Login", NS_AUTO_STATUS);
    ns_page_think_time(0);

    //Page Auto splitted for Image Link 'Search Flights Button' Clicked by User
    ns_start_transaction("Booking");
    ns_web_url ("Booking",
       // "URL=http://127.0.0.1/cgi-bin/reservation",
        "URL=http://127.0.0.1/cgi-bin/reservation",
        "HEADER=Accept-Language:en-us,en;q=0.5;random_string={PassengernoRN}",
        "PreSnapshot=webpage_1453582792364.png",
        "Snapshot=webpage_1453582792706.png",
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
    ns_end_transaction("Booking", NS_AUTO_STATUS);
    ns_page_think_time(0);

    //Page Auto splitted for Image Link 'findFlights' Clicked by User
    ns_start_transaction("Searchflight");
    ns_web_url ("Searchflight",
       // "URL=http://127.0.0.1/cgi-bin/findflight?depart=London&departDate=01-24-2016&arrive=New+York&returnDate=01-26-2016&numPassengers=1&seatPref=Window&seatType=First&findFlights.x=70&findFlights.y=18&findFlights=Submit",
        "URL=http://127.0.0.1/cgi-bin/findflight?depart={DeparturecityFP}&departDate={Date}&arrive={ArrivalcityFP}&returnDate={Date}&numPassengers={PassengernoRN}&seatPref={SeatFP}&seatType={Seat_typesFP}&findFlights.x=70&findFlights.y=18&findFlights=Submit",
        "HEADER=Accept-Language:en-us,en;q=0.5;random_string={PassengernoRN}",
        "PreSnapshot=webpage_1453582816166.png",
        "Snapshot=webpage_1453582816506.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/images/splash_Searchresults.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/images/continue.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/images/startover.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    );
    ns_end_transaction("Searchflight", NS_AUTO_STATUS);
    ns_page_think_time(0);

    //Page Auto splitted for Image Link 'reserveFlights' Clicked by User
    ns_start_transaction("Searchflight2");
    ns_web_url ("Searchflight2",
       // "URL=http://127.0.0.1/cgi-bin/findflight?hidden_outboundFlight_button0=230%7C1535%7C01-24-2016&hidden_outboundFlight_button1=231%7C1396%7C01-24-2016&outboundFlight=button2&hidden_outboundFlight_button2=232%7C1465%7C01-24-2016&hidden_outboundFlight_button3=233%7C1256%7C01-24-2016&numPassengers=1&advanceDiscount=&seatType=First&seatPref=Window&reserveFlights.x=71&reserveFlights.y=9",
        "URL=http://127.0.0.1/cgi-bin/findflight?hidden_outboundFlight_button0={FlightDetailsFP}01-24-2016&hidden_outboundFlight_button1=231%7C1396%7C01-24-2016&outboundFlight={FlightInfoFP}&hidden_outboundFlight_button2=232%7C1465%7C01-24-2016&hidden_outboundFlight_button3=233%7C1256%7C01-24-2016&numPassengers={PassengernoRN}&advanceDiscount=&seatType={Seat_typesFP}&seatPref={SeatFP}&reserveFlights.x=71&reserveFlights.y=9",
         "HEADER=Accept-Language:en-us,en;q=0.5;random_string={PassengernoRN}",
        "PreSnapshot=webpage_1453582827126.png",
        "Snapshot=webpage_1453582827508.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/images/splash_creditcard.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/images/purchaseflight.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/images/startover.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    );
    ns_end_transaction("Searchflight2", NS_AUTO_STATUS);
    ns_page_think_time(0);

    //Page Auto splitted for Image Link 'buyFlights' Clicked by User
    ns_start_transaction("Searchflight3");
    ns_web_url ("Searchflight3",
       // "URL=http://127.0.0.1/cgi-bin/findflight?firstName=Tiger&lastName=Scott&address1=4261+Stevenson+Blvd.&address2=Fremont%2C+CA+94538&pass1=Scott+Tiger&creditCard=1234&expDate=21.02&oldCCOption=&numPassengers=1&seatType=First&seatPref=Window&outboundFlight=232%7C1465%7C01-24-2016&advanceDiscount=&buyFlights.x=93&buyFlights.y=9&.cgifields=saveCC",
        "URL=http://127.0.0.1/cgi-bin/findflight?firstName={FirstnameFP}&lastName={LastnameFP}&address1={AddressFP}&address2={ZipFP}&pass1={PassengernameFP}&creditCard={CreditcardUN}&expDate={ExpDate}&oldCCOption=&numPassengers={PassengernoRN}&seatType={Seat_typesFP}&seatPref={SeatFP}&outboundFlight=232%7C1465%7C01-24-2016&advanceDiscount=&buyFlights.x=93&buyFlights.y=9&.cgifields=saveCC",
        "HEADER=Accept-Language:en-us,en;q=0.5;random_string={PassengernoRN}",
        "PreSnapshot=webpage_1453582858509.png",
        "Snapshot=webpage_1453582858929.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/images/splash_flightconfirm.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/images/bookanother.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    );
    ns_end_transaction("Searchflight3", NS_AUTO_STATUS);
    ns_page_think_time(0);

    //Page Auto splitted for Image Link 'SignOff Button' Clicked by User
    ns_start_transaction("Logout");
    ns_web_url ("Logout",
        //"URL=http://127.0.0.1/cgi-bin/welcome",
        "URL=http://127.0.0.1/cgi-bin/welcome",
        "HEADER=Accept-Language:en-us,en;q=0.5;random_string={PassengernoRN}",
        "PreSnapshot=webpage_1453582915339.png",
        "Snapshot=webpage_1453582915679.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/login.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/images/banner_merctur.jpg", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    );
    ns_end_transaction("Logout", NS_AUTO_STATUS);
    ns_page_think_time(0);

}
