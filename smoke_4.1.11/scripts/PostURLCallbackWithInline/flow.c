/*-----------------------------------------------------------------------------
    Name: flow
    Recorded By: netstorm
    Date of recording: 09/28/2015 02:51:01
    Flow details:
    Build details: 4.1.3 (build# 27)
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

int post_call_back()
{
    char *ptr = "http://10.10.30.96/PostCallBack/PostCallBack_var.html";
    ns_set_embd_objects(1, &ptr, 1);
}


void flow()
{
    ns_start_transaction("Transaction_1");
    ns_web_url ("index1",
        "URL=http://10.10.30.96/PostCallBack/PostCallBack_WithInline.html",
        "PostURLCallback=post_call_back",
    );
    ns_end_transaction("Transaction_1", NS_AUTO_STATUS);

/*
    ns_start_transaction("Transaction_2");
    ns_web_url ("index2",
        "URL=http://10.10.30.96/page2.html",
        //"URL=http://10.10.70.3:9002/req",
        // "POSTURLCALLBACK:2=hie",
    );
    ns_end_transaction("Transaction_2", NS_AUTO_STATUS);

    ns_start_transaction("Transaction_3");
    ns_web_url ("index3",
        "URL=http://10.10.30.96/ashish.html",
         //"URL=http://10.10.70.3:9002/req",
         "POSTURLCALLBACK:2=hie",
     );
    ns_start_transaction("Transaction_3");
*/

}
                                                                       
