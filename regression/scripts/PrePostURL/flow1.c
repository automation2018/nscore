#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void my_pre()
{
   printf("########################my_pre() called\n");
}
void my_post()
{
   printf("########################my_post() called\n");
}

void flow1()
{
    ns_web_url("autoredirect_start",
	"METHOD=GET",
	"URL=https://127.0.0.1/custom/samples/autoredirect/autoredirect.start",
	"REDIRECT=YES",
	"LOCATION=/custom/samples/autoredirect/autoredirect.secmove",
	"PREURLCALLBACK=my_pre",
	"POSTURLCALLBACK=my_post",
	INLINE_URLS,
	    "URL=http://127.0.0.1/custom/samples/autoredirect/autoredirect.secmove",
	    "POSTURLCALLBACK=my_post",
	    "REDIRECT=YES",
	    "LOCATION=/custom/samples/autoredirect/autoredirect.thirdmove", END_INLINE,
	    "URL=http://127.0.0.1/custom/samples/autoredirect/autoredirect.thirdmove", END_INLINE
    );

    ns_web_url("autoredirect_secmove",
	"METHOD=GET",
	"URL=https://127.0.0.1/custom/samples/autoredirect/autoredirect.secmove",
	"PREURLCALLBACK=my_pre",
	"POSTURLCALLBACK=my_post",
	"REDIRECT=YES",
	"LOCATION=/custom/samples/autoredirect/autoredirect.secmove",
	INLINE_URLS,
  	    "URL=http://127.0.0.1/custom/samples/autoredirect/autoredirect.thirdmove", END_INLINE,
	    "URL=http://127.0.0.1/custom/samples/autoredirect/autoredirect.secmove", END_INLINE
    );
    ns_web_url("autoredirect_thirdmove",
	"METHOD=GET",
	"URL=https://127.0.0.1/custom/samples/autoredirect/autoredirect.thirdmove",
	INLINE_URLS,
	    "URL=http://127.0.0.1/custom/samples/autoredirect/autoredirect.secmove",
	    "PREURLCALLBACK=my_pre",
	    "REDIRECT=YES",
	    "LOCATION=/custom/samples/autoredirect/autoredirect.fourthmove", END_INLINE,
	    "URL=http://127.0.0.1/custom/samples/autoredirect/autoredirect.fourthmove", END_INLINE
    );
}

