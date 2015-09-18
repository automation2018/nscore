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
    ns_web_url ("index",
        "URL=http://127.0.0.1/tours/index.html",
    );

    ns_page_think_time(5.0);
}
