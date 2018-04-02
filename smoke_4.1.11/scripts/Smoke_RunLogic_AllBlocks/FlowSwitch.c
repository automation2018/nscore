#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"
void FlowSwitch()
{
	int count = ns_get_int_val("var_switch");
	count ++;
	ns_set_int_val("var_switch",count);
	
}