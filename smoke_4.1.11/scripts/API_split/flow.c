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
   char buffer[100]="Hi,This,is,used,for,testing,purpose,only,for,spli,api";
   int max_flds=10;
   char *fields[20];
   int ret_name ;
   ret_name=ns_string_split( buffer, fields , "," , max_flds);
   int i;
   for (i=0;i<ret_name;i++)
   {
   fprintf(stdout,"splitted field : %s\n", fields[i]);
   }
}
