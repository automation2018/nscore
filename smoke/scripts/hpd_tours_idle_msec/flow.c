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
    ns_web_url ("index",
        "URL=http://127.0.0.1/integrationtest",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124026631.png",
        "Snapshot=webpage_13946124027021.png",
    );

    ns_page_think_time(0.2);
    ns_end_transaction("IndexPage", NS_AUTO_STATUS);
}
