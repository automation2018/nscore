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

void dummy()
{
    ns_web_url ("dummy",
        "URL=http://127.0.0.1/tours/index.html",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "PreSnapshot=webpage_1484397720750.png",
        "Snapshot=webpage_1484397722929.png",
    );
    ns_page_think_time(2.748);

}
