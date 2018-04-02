/*-----------------------------------------------------------------------------
    Name: flow
    Recorded By: netstorm
    Date of recording: 10/22/2016 02:50:31
    Flow details:
    Build details: 4.1.6 (build# 30)
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow()
{
ns_start_transaction("GET_method");
 ns_web_url ("GET_method",
"METHOD=GET",
"URL=http://10.10.30.96/service50k",
    INLINE_URLS,
//            "URL=https://10.10.30.17:222/index1.html", "repeat=100", END_INLINE,
            "URL=http://10.10.30.96/service50k", END_INLINE,
  //          "URL=http://10.10.30.17:81/debug/log", END_INLINE,
);
ns_end_transaction("GET_method", NS_AUTO_STATUS);

// This is for POST method
ns_start_transaction("POST_method");
ns_web_url ("POST_method",
"METHOD=POST",
"URL=http://10.10.30.96/service10k",
//"BODY=hi !! this is Deepshikha Balliyan",    
"BODY=$CAVINCLUDE$=/home/netstorm/work/http2_large_resp.html",    
INLINE_URLS,
          "URL=https://10.10.30.96/service10k", "repeat=50", END_INLINE,
            "URL=https://10.10.30.96/service50k", END_INLINE,
//            "URL=https://10.10.30.17:222/index1.html", END_INLINE,
);
ns_end_transaction("POST_method", NS_AUTO_STATUS);

// This is for pUT method
ns_start_transaction("PUT_method"); 
ns_web_url ("PUT_method",
"METHOD=PUT",
"URL=http://10.10.30.96/service20k",
"BODY=$CAVINCLUDE$=/home/netstorm/work/http2_large_resp.html",
      INLINE_URLS,
            "URL=https://10.10.30.96/service20k", "repeat=40", END_INLINE,
//            "URL=https://10.10.30.17:222/index1.html", END_INLINE,
            "URL=http://10.10.30.96/index1.html", END_INLINE,
);
ns_end_transaction("PUT_method", NS_AUTO_STATUS);

// this one is for DELETE method
ns_start_transaction("DELETE_method");
ns_web_url ("DELETE_method",
"METHOD=DELETE",
"URL=https://10.10.30.96/service50k",
      INLINE_URLS,
            "URL=https://10.10.30.96/service50k", "repeat=100", END_INLINE,
            "URL=http://10.10.30.17:81/index1.html", END_INLINE,
            "URL=http://10.10.30.96/service20k", END_INLINE,
);
ns_end_transaction("DELETE_method", NS_AUTO_STATUS);
// This is for TRACE method
ns_start_transaction("TRACE_method");
ns_web_url ("TRACE_method",
//     "URL=https://10.10.30.96/service10k",
     "URL=http://10.10.30.96/service10k",
     "METHOD=TRACE",
      INLINE_URLS,
//            "URL=http://10.10.30.17:81/debug/log", "repeat=20", END_INLINE,
  //          "URL=http://10.10.30.96/service10k", END_INLINE,
            "URL=http://10.10.30.96/service100k", END_INLINE,
);
ns_end_transaction("TRACE_method", NS_AUTO_STATUS);

// This is for HEAD method
ns_start_transaction("HEAD_method");
ns_web_url ("HEAD_method",
     //"URL=http://10.10.30.96/service512k",
     "URL=http://10.10.30.96/service10k",
     "METHOD=HEAD",
      INLINE_URLS,
            "URL=http://10.10.30.96/service10k", END_INLINE,
            "URL=http://10.10.30.17:81/debug/log", "repeat=10", END_INLINE,
);
ns_end_transaction("HEAD_method", NS_AUTO_STATUS);
}
