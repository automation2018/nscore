/*-----------------------------------------------------------------------------
    Name:ProductSelectionStart
    Written By: Madhu
    Date : 03/28/2013 07:47:42
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"
#include "Util.c"

void ProductSelectionStart()
{
	//printf("\n ++++++++++  ProductSelectionStart ++++++++++  \n");

	int TotalPagesToNavigate = 0;

	//TotalPagesToNavigate = ns_get_random_number_int(8, 12); // NOTE : this needs to be changed to ensure we generate 10 pages per session for FSM scenario
	TotalPagesToNavigate = ns_get_random_number_int(6, 8); // NOTE : this needs to be changed to ensure we generate 10 pages per session for FSM scenario

    ns_set_int_val("nsTotalPagesToNavigate", TotalPagesToNavigate);    
    
    // To being with PendingPagesToNavigate is equal to TotalPagesToNavigate
    ns_set_int_val("nsPendingPagesToNavigate", TotalPagesToNavigate);
    
    #ifdef NS_DEBUG_ON
    printf("\n +++++ ProductSelectionStart : TotalPages To Navigate in Product Selection = %d\n", TotalPagesToNavigate);
    #endif
   //Lets start the first step
   ProductSelectionMoveNext(0,0); 
}



