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
 ns_start_transaction("cgi_bin_home");
 ns_web_url("cgi_bin_home",
 "URL=http://10.10.30.96/cgi-bin/home",
);
ns_end_transaction("cgi_bin_home", NS_AUTO_STATUS);
ns_page_think_time(0.2);

   int max_flds=10;
   char *fields[20];
   int ret_name ;
   ret_name=ns_string_split( ns_eval_string("{buff_SP}"), fields , " " , max_flds);
   int i;
   for (i=0;i<ret_name;i++)
   {
   fprintf(stdout,"splitted field is : %s\n", fields[i]);
   }
}
