#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow1()
{
    ns_ftp_get("page1",
	"FTP_SERVER=127.0.0.1",
        "USER_ID=netstorm",
        "PASSWORD=netstorm",
        "FILE=largetext.txt"
    );
}
