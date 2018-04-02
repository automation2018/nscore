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
    ns_web_url ("index",
        "URL=http://127.0.0.1/tours/index.html",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "HEADER=Content-type:multipart/form-data,boundary=AaBx2c",
         MULTIPART_BODY_BEGIN,
         MULTIPART_BOUNDARY,
         "BODY=$CAVINCLUDE$=multiPart.bin",         
         MULTIPART_BOUNDARY,
         "HEADER=Content-type:multipart/form-data,boundary=BbBx2c",
         MULTIPART_BODY_BEGIN,
         MULTIPART_BOUNDARY,
        "BODY={body}",
         MULTIPART_BODY_END,  
         MULTIPART_BODY_END,  
         );
 
    ns_web_url ("login",
        "URL=http://127.0.0.1/cgi-bin/login?userSession=75893.0884568651DQADHfApHDHfcDtccpfAttcf&username=netstorm&password=netstorm&login.x=0&login.y=0&login=Login&JSFormSubmit=off",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "HEADER=Content-type:multipart/form-data,boundary=CCBx2c",
         MULTIPART_BODY_BEGIN,
         MULTIPART_BOUNDARY,
         "BODY=$CAVINCLUDE$=multiPart.txt",
         MULTIPART_BODY_END,
        INLINE_URLS,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/banner_animated.gif", 
            "HEADER=Content-type:multipart/form-data,boundary=DdBx2c",
             MULTIPART_BODY_BEGIN,
             MULTIPART_BOUNDARY,
            "BODY={body}",
             MULTIPART_BOUNDARY,
            "HEADER=Content-type:multipart/form-data,boundary=EeBx2c", 
             MULTIPART_BODY_BEGIN,
             MULTIPART_BOUNDARY,
             "BODY={body}",
             MULTIPART_BOUNDARY,
             "HEADER=Content-type:multipart/form-data",
             MULTIPART_BODY_BEGIN,
             MULTIPART_BOUNDARY,
             "BODY=$CAVINCLUDE$=multiPart.xml",
             MULTIPART_BODY_END,
             MULTIPART_BODY_END,
             MULTIPART_BODY_END,
             END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/sun_swede.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/flights.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/home.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/Merc10-dev/images/signoff.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/images/banner_merctur.jpg", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://127.0.0.1/tours/vep/images/velocigen.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE
    );
}
