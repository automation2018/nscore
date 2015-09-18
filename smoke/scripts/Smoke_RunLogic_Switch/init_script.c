/*-----------------------------------------------------------------------------
    Name: init_script
    Recorded By: netstorm
    Date of recording: 7/5/2011 5:24:17
    Flow details:
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"
int init_script()
{ 	
	int value  = %per_value1;
        %per_value2;
	ns_set_int_val("switch_var", value);
	 return 0;
   
}
