/*-----------------------------------------------------------------------------
    Name:ChangeView
    Recorded By: Madhu
    Date of recording: 03/26/2013 03:47:42
    Flow details:
    Modification History:
    
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"
#include "Util.c"

void ChangeView()
{	
	int PagesNavigated = 0;
	int ZeroproductCount = 0;
	//int DoChangeView = ns_get_random_number_int(0, 5); // Randomize if user does a change view
	int DoChangeView = ns_get_random_number_int(0, 2); // Randomize if user does a change view

	if(DoChangeView != NO) // User is doing change view
	{
		ZeroproductCount = ns_get_int_val("ZeroProductsCountSP_count");
		if(ZeroproductCount > 0)
		{		
    	 // Zero products.. skip this
    	 return;
		}
			
		#ifdef NS_DEBUG_ON
		printf("\n ++++++++++ Change View YES ++++++++++ \n");
		#endif
    	ns_start_transaction("ChangeView");
    	ns_web_url ("ChangeViewPage",
        "URL=http://www-sf.kohlsecommerce.com/catalog/fragments/setProductListingView.jsp",
        "METHOD=POST",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "HEADER=Content-Length:20",
        "HEADER=x-requested-with:XMLHttpRequest",
        "HEADER=Content-Type:application/x-www-form-urlencoded; charset=UTF-8",
        "COOKIE=JSESSIONID;Tracking_Cookie:4730053;mbox;s_sess;s_pers;fsr.s;",
        "PreSnapshot=webpage_1366303211972.png",
        "Snapshot=webpage_1366303220604.png",
        //"BODY=tab_class_new=medium"
        "BODY=tab_class_new={ChangeViewTypeFP}"
    );
    ns_end_transaction("ChangeView", NS_AUTO_STATUS);    
    ns_page_think_time(0);
    PagesNavigated = PagesNavigated + 1;
   }
   else
   {
   	    #ifdef NS_DEBUG_ON
   		printf("\n ++++++++++ Change View NO  ++++++++++ \n");
   		#endif
   }
 
   ProductSelectionMoveNext(4, PagesNavigated); //Current step number = 4, Pages naviagted in this step is = PagesNavigated

}
