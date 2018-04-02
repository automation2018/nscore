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
    ns_web_url ("login",
        "URL=http://10.10.30.96/jstojsp/time_out_event.html",
    );

    ns_page_think_time(5.0);
}
