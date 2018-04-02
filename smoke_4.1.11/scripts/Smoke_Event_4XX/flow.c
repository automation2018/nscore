/*-----------------------------------------------------------------------------
    Name: flow
    Recorded By: automation
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
    ns_start_transaction("login");
    ns_web_url ("login",
        "URL=http://127.0.0.1/cgi-bing/loginn?userSession=75893.0884568651DQADHfApHDHfcDtccpfAttcf&username=netstorm&password=cavisson&login.x=0&login.y=0&login=Login&JSFormSubmit=off"
    );

    ns_page_think_time(5.0);
    ns_end_transaction("login", NS_AUTO_STATUS);
    
    ns_start_transaction("Reservation");
    ns_web_url ("reservation",
        "URL=http://127.0.0.1/cgi-bing/reservations"
    );
    ns_page_think_time(5.0);
    ns_end_transaction("Reservation", NS_AUTO_STATUS);
}
