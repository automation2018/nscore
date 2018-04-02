#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"
void FlowWhile()
{
	int count = ns_get_int_val("var_while");
	if(count==0)
		return;
	else
	{
		count --;
		ns_set_int_val("var_while",count);
	}

}