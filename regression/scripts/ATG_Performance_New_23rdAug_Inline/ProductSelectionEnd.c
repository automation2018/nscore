/*-----------------------------------------------------------------------------
    Name:ProductSelectionEnd
    Written By: Madhu
    Date : 03/28/2013 07:47:42
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void ProductSelectionEnd()
{
	#ifdef NS_DEBUG_ON
	printf("\n ++++++++++ ProductSelectionEnd ++++++++++  \n");
	#endif
	
	//TODO:
	
	// Need to select a product so that next flows can continue using the same product
	// What if the selected product is out of stock ?	

	// Capture and update the below information and rest flows will work as is
	// ns_save_string(xxx, "CurrentProdID");	
    // ns_save_string(xxx, "CurrentProdDetailPage");	
    // ns_save_string(xxx, "CurrentSkuID");		

}