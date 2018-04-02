/*-----------------------------------------------------------------------------
    Name: flow
    Recorded By: Asheesh Tivaree
    Date of recording: 09/10/2016 03:17:03
    Flow details:
    Build details: 4.1.5 (build# 57)
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

/* Inline Checkpoint user guide. 

Syntax : 
ns_checkpoint(pfx, pfx_re_ic, sfx, sfx_re_ic, fail, action_on_fail, save_count_param); //It has seven fields.

Field Descriptions :
(1) pfx : This field is use to provide the complete string or LB.
    For Example: char pfx="cavisson1";

(2) pfx_re_ic : It has four options and it is applicable on pfx field.
    For Example: int pfx_re_ic = 0;
    0 means no regular expression and no ignore case.
    1 means regular expression enable.
    2 means ignore case enable.
    3 means both regular expression and ignore case are enable. 

(3) sfx : This field is use to provide RB.
    For Example: char sfx[]=""; // No RB is provided.
 
(4) sfx_re_ic : It has four options and it is applicable on sfx field.
    For Example: int sfx_re_ic = 0;
    0 means no regular expression and no ignore case.
    1 means regular expression enable.
    2 means ignore case enable.
    3 means both regular expression and ignore case are enable. 

(5) fail : It has 3 options
    For Example: int fail = 0;
    0 means found.
    1 means not found.
   -1 means failure condition not checked.

(6) action_on_fail : It has two options.
    For Example: action_on_fail=0;
    0 means stop.
    1 means continue.

(7) save_count_param : It is use to check string occurrence count.
    For Example: char *save_count_param= "occurrence1"; // occurrence is a declare parameter.
    "" means save occurrence is not applied.

It was the user guide */


// Function to stop the session after found the string by giving CVFail. (Failure condition checked).
void inline_checkpoint1()
{
ns_checkpoint("cavisson1", 0, "", 0, 0, 0, "");
}

// Function to continue with the session after found the string by giving CVFail. (Failure condition checked).
void inline_checkpoint2()
{
ns_checkpoint("cavisson1", 0, "", 0, 0, 1, "");
}

// Function to continue with the session after string found (NO CVFail will observed). (Failure condition unchecked).
void inline_checkpoint3()
{
ns_checkpoint("cavisson1", 0, "", 0, -1, 1, "");
}

// Function to stop the session if string not found (CVFail will observed). (Failure condition unchecked).
void inline_checkpoint4()
{
ns_checkpoint("xyz", 0, "", 0, -1, 1, "");
}

// Regular Expression and ignore case : If string found then will stop the session by giving CVFail (Failure condition checked).
void inline_checkpoint5()
{
ns_checkpoint("thi*s", 3, "on1", 3, 0, 0, "");
}

// Regular Expression and ignore case : If string found then will continue the session by giving CVFail (Failure condition checked).
void inline_checkpoint6()
{
ns_checkpoint("thi*s", 3, "on1", 3, 0, 1, "");
}

// Regular Expression and ignore case : If string found then will continue the session(Failure condition unchecked) (NO CVFail will observed).
void inline_checkpoint7()
{
ns_checkpoint("thi*s", 3, "on1", 3, -1, 0, "");
}

// Function to stop the session after found the string by giving CVFail. (Failure condition checked).
void inline_checkpoint8()
{
ns_checkpoint("cavisson3", 0, "", 0, 0, 0, "");
}

void message()
{
printf("\n\n No checkpoint is applied!!! \n\n"); 
}

//Main flow started.
void flow()
   { 
    ns_start_transaction("Main_transaction_1");           
    ns_web_url ("index_html",
        "URL=http://127.0.0.1/tours/index.html",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_1440668801861.png",
        "Snapshot=webpage_1440668802047.png",
//First Inline URL.            
        INLINE_URLS,
        %post1,
        "URL=http://127.0.0.1/kohls_pay/kohls1.html","txname=trans1","REPEAT=%REPEAT", "HEADER=Accept-Language:en-us,en;q=0.5",
         END_INLINE,
//Second Inline URL.
        "URL=http://127.0.0.1/kohls_pay/kohls2.html","txname=trans2", "HEADER=Accept-Language:en-us,en;q=0.5",
         END_INLINE,
//Third Inline URL.
         %post2,
         "URL=http://127.0.0.1/kohls_pay/kohls3.html","txname=trans3", "HEADER=Accept-Language:en-us,en;q=0.5",
          END_INLINE,
//Fourth Inline URL.
         "URL=http://127.0.0.1/kohls_pay/kohls4.html","txname=trans4", "HEADER=Accept-Language:en-us,en;q=0.5",
           END_INLINE,
//Fifth Inline URL
         "URL=http://127.0.0.1/kohls_pay/kohls5.html","txname=trans5", "HEADER=Accept-Language:en-us,en;q=0.5",
            END_INLINE
           );
    ns_end_transaction("Main_transaction_1", NS_AUTO_STATUS);    
  ns_page_think_time(0);

/* printf(" \nTotal occurance count in inline_1 is : %s \n\n", ns_eval_string("{occurrence1}"));
 printf(" \nTotal occurance count in inline_2 is : %s \n\n", ns_eval_string("{occurrence2}"));
 printf(" \nTotal occurance count in inline_3 is : %s \n\n", ns_eval_string("{occurrence3}"));
 printf(" \nTotal occurance count in inline_4 is : %s \n\n", ns_eval_string("{occurrence4}"));
*/ 
    ns_start_transaction("Main_transaction_2");    
    ns_web_url ("login",
        "URL=http://127.0.0.1/cgi-bin/login?userSession=75893.0884568651DQADHfApHDHfcDtccpfAttcf&username=&password=&login.x=56&login.y=12&login=Login&JSFormSubmit=off",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_1440668805766.png",
        "Snapshot=webpage_1440668806200.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/images/banner_merctur.jpg", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    );
    ns_end_transaction("Main_transaction_2", NS_AUTO_STATUS);    
    ns_page_think_time(0);


    //Page Auto splitted for Image Link 'Search Flights Button' Clicked by User
    ns_start_transaction("Main_transaction_3");    
    ns_web_url ("reservation",
        "URL=http://127.0.0.1/cgi-bin/reservation",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_1440668807799.png",
        "Snapshot=webpage_1440668808482.png",
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
    ns_end_transaction("Main_transaction_3", NS_AUTO_STATUS);    
    ns_page_think_time(0);

    //Page Auto splitted for Image Link 'findFlights' Clicked by User
    ns_start_transaction("Main_transaction_4");    
    ns_web_url ("findflight",
        "URL=http://127.0.0.1/cgi-bin/findflight?depart=Acapulco&departDate=09-01-2015&arrive=Acapulco&returnDate=09-02-2015&numPassengers=1&seatPref=None&seatType=First&findFlights.x=80&findFlights.y=17&findFlights=Submit",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_1440668811598.png",
        "Snapshot=webpage_1440668812296.png",
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
    ns_end_transaction("Main_transaction_4", NS_AUTO_STATUS);    
    ns_page_think_time(0);

    //Page Auto splitted for Image Link 'reserveFlights' Clicked by User
    ns_start_transaction("Main_transaction_5");    
    ns_web_url ("welcome",
        "URL=http://127.0.0.1/cgi-bin/welcome",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_1440668818103.png",
        "Snapshot=webpage_1440668818704.png",
       INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/login.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/images/banner_merctur.jpg", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE

    );
    ns_end_transaction("Main_transaction_5", NS_AUTO_STATUS);    
    ns_page_think_time(0);


}
