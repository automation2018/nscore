/*-----------------------------------------------------------------------------
    Name: init_script
    Recorded By: netstorm
    Date of recording: 7/1/2011 11:20:35
    Flow details:
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"
int init_script()
{	
	int value1 = %dowhile_value;
	int value2 = %while_value;
	int value3 = %switch_value;
	ns_set_int_val("var_dowhile",value1);
	ns_set_int_val("var_while",value2);
	ns_set_int_val("var_switch",value3);
	
    return 0;
}
