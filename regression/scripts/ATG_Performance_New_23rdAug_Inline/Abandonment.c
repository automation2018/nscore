/*-----------------------------------------------------------------------------
    Name:Abandonment
    Recorded By: netstorm
    Date of recording: 02/16/2013 03:08:39
    Flow details:
    Modification History:
    03/22/2013 - Updated to work with CD5 R3 - Madhu
    03/23/2013 - Updated to work with products with options - Madhu
    04/10/2013 - Tested with CD5 R15 - Anjali    
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"
void Abandonment()
{
  #ifdef NS_DEBUG_ON
  printf("\n ++++++++++ Abandonment ++++++++++++++\n");
  #endif
  	ns_exit_session();    		
}
