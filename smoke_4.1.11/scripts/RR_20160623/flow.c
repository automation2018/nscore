/*-----------------------------------------------------------------------------
    Name: flow
    Recorded By: netstorm
    Date of recording: 05/19/2014 03:45:25
    Flow details:
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow()
{
   char *file_id;
   char *search_parm;

   ns_start_transaction("reservation_2");

   ns_web_url ("index",
        "METHOD=POST",
        "URL=http://127.0.0.1{url}",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "BODY=<sessionId>{session_id}</sessionId>",
    );
    file_id = ns_eval_string("{id}");
    search_parm = ns_eval_string("{search1}");
    if (!strcmp(file_id , search_parm))
    {
       ns_end_transaction("reservation_2", NS_AUTO_STATUS);
    }
    else
    {
      ns_end_transaction("reservation_2", 64);
    }


  /*  ns_start_transaction("reservation_3");

    ns_web_url ("index1",
        "METHOD=POST",
        "URL=http://65.49.10.6:9044{url}",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "BODY=<sessionId>{session_id}</sessionId>",
    );
    file_id = ns_eval_string("{id}");
    search_parm = ns_eval_string("{search1}");
    if (!strcmp(file_id , search_parm))
    {
       ns_end_transaction("reservation_3", NS_AUTO_STATUS);
    }
    else
    {
      ns_end_transaction("reservation_3", NS_SUCCESS_STATUS);
    } */

}

