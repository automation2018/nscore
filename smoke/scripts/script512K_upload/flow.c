#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow()
{
    ns_web_url("Static512K_upload",
    "METHOD=POST",
    "URL=http://127.0.0.1/tours/index.html",
	"HEADER=Content-Type: application/text",
    "BODY=$CAVINCLUDE$=a.txt",         
    );
}
