#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "../../include/ns_string.h"



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

 ns_web_url(0); // autoredirect_start
 ns_web_url(1); // autoredirect_secmove
 ns_web_url(2); // autoredirect_thirdmove
}



