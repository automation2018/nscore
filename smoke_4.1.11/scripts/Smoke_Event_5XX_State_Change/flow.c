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
    /* 2xx url */
    ns_start_transaction("twoxxurl");
    ns_web_url ("twoxxurl",
        "URL=http://127.0.0.1/tours/index.html"
    );

    ns_page_think_time(5.0);
    ns_end_transaction("twoxxurl", NS_AUTO_STATUS);

    
    /* 5xx url */
    ns_start_transaction("fivexxurl");
    ns_web_url ("fivexxurl",
        "URL=http://10.10.30.96/jstojsp/5xx_error_event.html",
    );
    ns_page_think_time(5.0);
    ns_end_transaction("fivexxurl", NS_AUTO_STATUS);
    
 
    /* 2xx url */
    ns_start_transaction("statechange_first_2xx");
    ns_web_url ("statechange_first_2xx",
        "URL=http://127.0.0.1/cgi-bin/login?userSession=75893.0884568651DQADHfApHDHfcDtccpfAttcf&username=netstorm&password=cavisson&login.x=0&login.y=0&login=Login&JSFormSubmit=off"
    );
    ns_page_think_time(5.0);
    ns_end_transaction("statechange_first_2xx", NS_AUTO_STATUS);


  
    /* 4xx url */
    ns_start_transaction("statechange_second_4xx");
    ns_web_url ("statechange_second_4xx",
        "URL=http://127.0.0.1/cgi-bing/loginn?userSession=75893.0884568651DQADHfApHDHfcDtccpfAttcf&username=netstorm&password=cavisson&login.x=0&login.y=0&login=Login&JSFormSubmit=off"
    );
    ns_page_think_time(5.0);
    ns_end_transaction("statechange_second_4xx", NS_AUTO_STATUS);
}
