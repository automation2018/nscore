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
    ns_web_url ("page1",
        "URL=http://127.0.0.1/caching/url_caching_1.html"
    );
    
    ns_web_url ("page2",
        "URL=http://127.0.0.1/caching/url_caching_1.html"
    );
	
	/*ns_web_url ("page2",
        "URL=http://127.0.0.1/caching/url_caching_2.html"
    );
	
	ns_web_url ("page3",
        "URL=http://127.0.0.1/caching/url_caching_3.html"
    );*/
}
