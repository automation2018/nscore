/*-----------------------------------------------------------------------------
    Name: AdjustInventory
    Recorded By: Priya
    Date of recording: 04/02/2013 11:10:04
    Flow details:
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void AdjustInventory()
{
	#ifdef NS_DEBUG_ON
	printf("Adjust Inventory called for SKUID %s \n", ns_eval_string("{AddToBagSkuId}"));
    #endif
    //Page Auto splitted for Button 'Adjust!' Clicked by User
    ns_web_url ("AdjustInventory",
        //"URL=http://10.210.211.1:17001/adjust-inventory/adjustinventory.jsp?skuCode=05281130&storeNumber=873",
        //"URL=http://10.210.211.1:17001/adjust-inventory/adjustinventory.jsp?skuCode={AddToBagSkuId}&storeNumber=873",
        "URL=http://www-sf.kohlsecommerce.com/adjust-inventory/adjustinventory.jsp?skuCode={AddToBagSkuId}&storeNumber=873",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "COOKIE=JSESSIONID;",
        "PreSnapshot=webpage_1364926192025.png",
        "Snapshot=webpage_1364926193126.png"
    );

    //ns_page_think_time(10.687);

}
