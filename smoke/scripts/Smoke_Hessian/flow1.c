#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"
void flow1()
{  
  ns_web_url("HessianRequest",
    "METHOD=POST",
    "URL=http://127.0.0.1/hessian_service/hessian_test.xml",
    %type
    %rr_type
    "HEADER=Content-Type: application/x-hessian",
    "BODY=$CAVINCLUDE$=%name"
  );
}
