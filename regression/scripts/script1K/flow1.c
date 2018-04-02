#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow1()
{
    ns_start_transaction("static1K_page1_trans1");
    ns_web_url("class1_0_html",
	"METHOD=GET",
	"URL=http://127.0.0.1/file_set/dir00000/class1_0.html",
	"HEADER=Accept-Language: en-us,en;q=0.5",
	"HEADER=Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7"
    );
    ns_end_transaction("static1K_page1_trans1",0);
    ns_page_think_time(0.0);
}
