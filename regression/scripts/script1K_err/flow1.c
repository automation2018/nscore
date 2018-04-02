#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow1()
{
    ns_web_url("class1_0_html","METHOD=GET","URL=http://127.0.0.1/custom/samples/response_line/test_411.html",
	"HEADER=Accept-Language: en-us,en;q=0.5",
	"HEADER=Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7",
    );
}
