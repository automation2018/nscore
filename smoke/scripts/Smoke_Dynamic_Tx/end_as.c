/*-----------------------------------------------------------------------------
    Name: flow
    Recorded By: netstorm
    Date of recording: 01/14/2017 06:12:13
    Flow details:
    Build details: 4.1.7 (build# 8)
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void end_as()
{
    char *var="c_var_tx";

// Static Transaction 
    ns_start_transaction(%trans1);
    ns_web_url ("Page1",
        "URL=http://127.0.0.1/tours/index.html",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "PreSnapshot=webpage_1484397720750.png",
        "Snapshot=webpage_1484397722929.png",
    );
    ns_end_transaction(%trans1, NS_AUTO_STATUS);
    ns_page_think_time(2.748);

// Dynamic Transaction
  ns_start_transaction(%trans2);
ns_web_url ("Page2",
        "URL=http://127.0.0.1/cgi-bin/login?userSession=75893.0884568651DQADHfApHDHfcDtccpfAttcf&username=&password=&login.x=47&login.y=1&login=Login&JSFormSubmit=off",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "PreSnapshot=webpage_1484397725162.png",
        "Snapshot=webpage_1484397725393.png",
    );
   ns_end_transaction(%trans2, NS_AUTO_STATUS);    
    ns_page_think_time(1.34);
    
// Static to dynamic OR dynamic to static OR C-var to dynamic OR dynamic to C-var   
    ns_start_transaction(%trans3);
    ns_web_url ("Page3",
        "URL=http://127.0.0.1/cgi-bin/reservation",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "PreSnapshot=webpage_1484397726717.png",
        "Snapshot=webpage_1484397726967.png",
    );
    ns_end_transaction_as(%trans3, NS_AUTO_STATUS, %end_as);
    ns_page_think_time(1.686);
    
// Dynamic Transaction    
    ns_start_transaction(%trans4);
    ns_web_url ("Page4",
        "URL=http://127.0.0.1/cgi-bin/findflight?depart=Acapulco&departDate=01-15-2017&arrive=Acapulco&returnDate=01-16-2017&numPassengers=1&seatPref=None&seatType=Coach&findFlights.x=14&findFlights.y=6&findFlights=Submit",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "PreSnapshot=webpage_1484397728654.png",
        "Snapshot=webpage_1484397728858.png",
    );
     ns_end_transaction(%trans4, NS_AUTO_STATUS);
    ns_page_think_time(2.0);

}
