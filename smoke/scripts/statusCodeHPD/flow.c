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
   ns_start_transaction("status101");
   ns_web_url ("status-101",
        "URL=http://10.10.30.96/service101",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124026631.png",
        "Snapshot=webpage_13946124027021.png",
        INLINE_URLS,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
    );

    ns_page_think_time(0.2);
    ns_end_transaction("status101", NS_AUTO_STATUS);
    
   ns_start_transaction("status200");
   ns_web_url ("status-200",
        "URL=http://10.10.30.96/service200",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124026631.png",
        "Snapshot=webpage_13946124027021.png",
        INLINE_URLS,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
    );

    ns_page_think_time(0.2);
    ns_end_transaction("status200", NS_AUTO_STATUS);

   ns_start_transaction("status204");
   ns_web_url ("status-204",
        "URL=http://10.10.30.96/service204",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124026631.png",
        "Snapshot=webpage_13946124027021.png",
        INLINE_URLS,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
    );

    ns_page_think_time(0.2);
    ns_end_transaction("status204", NS_AUTO_STATUS);

   ns_start_transaction("status206");
   ns_web_url ("status-206",
        "URL=http://10.10.30.96/service206",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124026631.png",
        "Snapshot=webpage_13946124027021.png",
        INLINE_URLS,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
    );

    ns_page_think_time(0.2);
    ns_end_transaction("status206", NS_AUTO_STATUS);

   ns_start_transaction("status301");
   ns_web_url ("status-301",
        "URL=http://10.10.30.96/service301",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124026631.png",
        "Snapshot=webpage_13946124027021.png",
        INLINE_URLS,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
    );

    ns_page_think_time(0.2);
    ns_end_transaction("status301", NS_AUTO_STATUS);

   ns_start_transaction("status302");
   ns_web_url ("status-302",
        "URL=http://10.10.30.96/service302",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124026631.png",
        "Snapshot=webpage_13946124027021.png",
        INLINE_URLS,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
    );

    ns_page_think_time(0.2);
    ns_end_transaction("status302", NS_AUTO_STATUS);

   ns_start_transaction("status400");
   ns_web_url ("status-400",
        "URL=http://10.10.30.96/service400",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124026631.png",
        "Snapshot=webpage_13946124027021.png",
        INLINE_URLS,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
    );

    ns_page_think_time(0.2);
    ns_end_transaction("status400", NS_AUTO_STATUS);

   ns_start_transaction("status401");
   ns_web_url ("status-401",
        "URL=http://10.10.30.96/service401",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124026631.png",
        "Snapshot=webpage_13946124027021.png",
        INLINE_URLS,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
    );

    ns_page_think_time(0.2);
    ns_end_transaction("status401", NS_AUTO_STATUS);
    
   ns_start_transaction("status403");
   ns_web_url ("status-403",
        "URL=http://10.10.30.96/service403",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124026631.png",
        "Snapshot=webpage_13946124027021.png",
        INLINE_URLS,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
    );

    ns_page_think_time(0.2);
    ns_end_transaction("status403", NS_AUTO_STATUS);

   ns_start_transaction("status404");
   ns_web_url ("status-404",
        "URL=http://10.10.30.96/service404",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124026631.png",
        "Snapshot=webpage_13946124027021.png",
        INLINE_URLS,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
    );

    ns_page_think_time(0.2);
    ns_end_transaction("status404", NS_AUTO_STATUS);

   ns_start_transaction("status500");
   ns_web_url ("status-500",
        "URL=http://10.10.30.96/service500",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124026631.png",
        "Snapshot=webpage_13946124027021.png",
        INLINE_URLS,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
    );

    ns_page_think_time(0.2);
    ns_end_transaction("status500", NS_AUTO_STATUS);
    
   ns_start_transaction("status504");
   ns_web_url ("status-504",
        "URL=http://10.10.30.96/service504",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124026631.png",
        "Snapshot=webpage_13946124027021.png",
        INLINE_URLS,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
    );

    ns_page_think_time(0.2);
    ns_end_transaction("status504", NS_AUTO_STATUS);

   ns_start_transaction("status505");
   ns_web_url ("status-505",
        "URL=http://10.10.30.96/service505",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "PreSnapshot=webpage_13946124026631.png",
        "Snapshot=webpage_13946124027021.png",
        INLINE_URLS,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
            "URL=https://10.10.30.96/index1.html", END_INLINE,
    );

    ns_page_think_time(0.2);
    ns_end_transaction("status505", NS_AUTO_STATUS);

}
