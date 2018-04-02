/*-----------------------------------------------------------------------------
    Name:AddToBag
    Recorded By: netstorm
    Date of recording: 02/20/2013 06:32:18
    Flow details:
    Modification History:
    03/22/2013 - Updated to work with CD5 R3 - Madhu
    03/23/2013 - Updated to work with products with options - Madhu    
    04/10/2013 - Tested with CD5 R15 - Anjali
    16/10/2013-  Updated to work with skuidsAvailibilty--Anjali/Madhu
    No of pages : 2
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"
#include "Util.c"

void AddToBag()
{
	// This flow is called after the user has viewed the product - PDP (ViewProductDetail) 

	// Notes: 
	//1. A product can have multiple SkuIds, what if there are no Available SKUID (all are out of stock) ??
	// ::   if SKUID is not available.
    //      a.IN case of Browse and search, should go back to product detail page (ViewProductDetail.c) and get another product, 
    //      b.but in case of searchpid it go to back to SearchProductIdPage (SearchProductId.c), i.e. search for another Productid. 
    //         Note : These cases cannot be handled becoz in both the cases,the go back calls are in diferent flows.
    //        for now, i have abandon the user. (see below)
  
	//2. What if the product view page do not have multiple SKUs ?
	// ::  By no multiple SKUs, means there is no options for the product like color and size selection, ("Gold Toe® 3-pk. Fluffies® Crew Socks - Extended Size" )
	//     In this case there will be one skuid and status corresponding to it ,
	//     so ,In this case the for loop would be executed only once. - Taken care. 
	
    //3. What if the product view page is a collection item page ?
    //     This case is handled in the ViewProductDetail flow, when it comes here.. a product from 
    //     collection item is selected and it's PDP is viewed. - No action needed here for this case.


    int  i = 0;
    int  SkuIdFound = NO;
    int  SkuIdCount = 0;
    char SkuIdvariable[128];
    char SkuIdstatus[128];
    char SkuIdbuffer[128];
    char *StatusType;
    #ifdef NS_DEBUG_ON
	printf("\n ++++++++++ Add To Bag ++++++++++++++\n");
    #endif
    
    SkuIdCount = ns_get_int_val("SkuIdSP_count");
    for(i = 0; i < SkuIdCount; i++)
    {
      sprintf(SkuIdstatus,"{SkuIdStatusSP_%d}", (i + 1)); //To get the status of the SkuId
      
      
      if(!strcmp(ns_eval_string("{ItemCheckAvailBlockSP}"),"this item is no longer available"))
      {
      	continue;
      }
      if(SkuIdstatus==0)
      {
      	continue;
      }
      StatusType = ns_eval_string(SkuIdstatus);
      
      if(StatusType == NULL) //This should not happened
      {
      	continue;
      }
      if(!strcmp(StatusType, "true")) // To Check whether it is in stock or out of stock
      {
      	// Out of stock is false -- we can use this SkuID
		sprintf(SkuIdvariable,"{SkuIdSP_%d}", (i + 1)); // To get the Index of in stock SkuId
        sprintf(SkuIdbuffer,"%s",ns_eval_string(SkuIdvariable)); // To get the value of  in stock SkuId
        ns_save_string(SkuIdbuffer, "AddToBagSkuId"); 
        SkuIdFound =  YES;
        break; // We found the SkuId .. no need to continue looping..
  	  }
  	  else
  	  {
		sprintf(SkuIdvariable,"{SkuIdSP_%d}", (i + 1)); // To get the Index of in stock SkuId
     	#ifdef NS_DEBUG_ON
     	printf("\n AddToBag : SkuID %s is out of stock.", ns_eval_string(SkuIdvariable));  	  	
     	#endif
  	  }
	}
    //  Search Available SKUID  - END   
 	
    ns_start_transaction("AddToBag");

 	if(SkuIdFound == NO)
 	{
    	ns_end_transaction_as("AddToBag", 0, "AddToBag_NoStock");	  

 		// Could not find any SkuId that is available..
 		// for now abandon the flow. we can ehance this if needed.
 		#ifdef NS_DEBUG_ON
     	printf("\n ++++ AddToBag : No available SkuId found for the product. \n");
		#endif
		return;    		
 	}
 	
    Fill_AddToBag();
    ns_web_url ("AddToBagPage",
        //"URL=http://10.210.222.129:17010/catalog/navigation.jsp?_DARGS=/catalog/fragments/product_right_detail.jsp",
        "URL=http://www-sf.kohlsecommerce.com/catalog/navigation.jsp?_DARGS=/catalog/fragments/product_right_detail.jsp",
        "METHOD=POST",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "HEADER=Content-Length:1110",
        "HEADER=Content-Type:application/x-www-form-urlencoded",
        "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;",
        "REDIRECT=YES",
        "LOCATION=http://10.210.222.129:17010/product/prd-731799/melissa-doug-bug-jug-fill-spill-set.jsp?prodId=731799&skuId=91399600&_requestid=4768",
        "PreSnapshot=webpage_1363258056577.png",
        "Snapshot=webpage_1363258420473.png",
        //"BODY=_dyncharset=UTF-8&_dynSessConf=6944508524083184195&add_cart_quantity=1&_D%3Aadd_cart_quantity=+&color=&waist=&size=&inseem=&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.catalogRefIds=91399600&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.catalogRefIds=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.productId=731799&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.productId=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrder=&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrder=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderSuccessURL=shopping_cart_add_to_cart_success_url&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderSuccessURL=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderErrorURL=shopping_cart_add_to_cart_error_url&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderErrorURL=+&_DARGS=%2Fcatalog%2Ffragments%2Fproduct_right_detail.jsp",
        //"BODY=_dyncharset=UTF-8&_dynSessConf={DynSessionConfSP}&add_cart_quantity={QuantityRN}&_D%3Aadd_cart_quantity=+&color=&waist=&size=&inseem=&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.catalogRefIds={ReferIdSP}&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.catalogRefIds=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.productId={ProductIdFP}&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.productId=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrder=&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrder=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderSuccessURL=shopping_cart_add_to_cart_success_url&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderSuccessURL=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderErrorURL=shopping_cart_add_to_cart_error_url&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderErrorURL=+&_DARGS=%2Fcatalog%2Ffragments%2Fproduct_right_detail.jsp",
        //"BODY=_dyncharset=UTF-8&_dynSessConf={DynSessionConfSP}&add_cart_quantity={QuantityRN}&_D%3Aadd_cart_quantity=+&color=&waist=&size=&inseem=&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.catalogRefIds={ProductSkuFP}&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.catalogRefIds=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.productId={ProductIdFP}&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.productId=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrder=&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrder=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderSuccessURL=shopping_cart_add_to_cart_success_url&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderSuccessURL=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderErrorURL=shopping_cart_add_to_cart_error_url&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderErrorURL=+&_DARGS=%2Fcatalog%2Ffragments%2Fproduct_right_detail.jsp",
        //"BODY=_dyncharset=UTF-8&_dynSessConf={DynSessionConfSP}&add_cart_quantity={QuantityRN}&_D%3Aadd_cart_quantity=+&color=&waist=&size=&inseem=&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.catalogRefIds={CurrentSkuID}&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.catalogRefIds=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.productId={CurrentProdID}&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.productId=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrder=&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrder=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderSuccessURL=shopping_cart_add_to_cart_success_url&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderSuccessURL=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderErrorURL=shopping_cart_add_to_cart_error_url&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderErrorURL=+&_DARGS=%2Fcatalog%2Ffragments%2Fproduct_right_detail.jsp",
        //"BODY=_dyncharset=UTF-8&_dynSessConf={DynSessionConfSP}&add_cart_quantity={QuantityRN}&_D%3Aadd_cart_quantity=+&color=&waist=&size=&inseem=&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.catalogRefIds={AddToBagSkuId}&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.catalogRefIds=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.productId={ProductIdSP}&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.productId=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrder=&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrder=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderSuccessURL=shopping_cart_add_to_cart_success_url&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderSuccessURL=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderErrorURL=shopping_cart_add_to_cart_error_url&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.addItemToOrderErrorURL=+&_DARGS=%2Fcatalog%2Ffragments%2Fproduct_right_detail.jsp",
        "BODY={AddToBagDP}",
        INLINE_URLS,
    "URL=http://www-sf.kohlsecommerce.com/media/foresee/foresee-alive.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery-1.7.2.min.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/global.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/myaccount.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery.validate.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery.validate_product.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/UI_validation.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/modal_validation.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/cart.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/fancybox/jquery.fancybox-1.3.4.pack.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/custom.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery.numeric.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/video.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/myaccount_custom.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/product-matrix_v1_m56577569836982752.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/gift_registry_fix.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/balance_inquiry.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/custom.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/kohls_custom.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/fancybox/jquery.fancybox-1.3.4.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/pdn/wishlist.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/pdn/giftguide.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/pdn/wishlist.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/pdn/giftguide.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/pdn/registry.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/pdn/registry.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/skava-custom.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/kohls_v1_m56577569839297458.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/fb_like_pdt.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/jcarousellite.min.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/cloud-zoom.1.0.2.min.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/carousel_inline.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/product.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/search_functionality.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/kohls_v1_m56577569836982750.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/left-nav.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/sub_v1.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/sub_v2.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/overlay.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/global.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/search-again.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/dept_rotator.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/callout.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/omniture/mbox.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/omniture/SkavaOmnitureCode.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Shipping-0821-FS50?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Shipping-0821-YesPass?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Shipping-0821-Earn?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/images/kohls-logo.png", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1255602_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1255602_Jet_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1352464_Aqua_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1352464_White_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1352468_White_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1027290_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1027290_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1536239_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1536239_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1202382_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1092349_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1159803_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1423950_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1335553_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1335553_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/965474_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/965474_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1536244_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1536244_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1536240_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1536240_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1398671_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1398671_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1388711_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1388711_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1536242_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1536242_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1398676_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1398676_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1536246_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1536246_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1388707_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1388707_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1398670_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1398670_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1536247_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1536247_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1398694_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1398694_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1398693_Gold_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1398693_Silver_Tone_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/tag.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/iframe?c=4DPyaxM", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Universal_FooterNavigation_20130523_YesGraphic?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/plugins/likebox.php?href=http%3A%2F%2Fwww.facebook.com%2Fkohls&width=315&colorscheme=light&connections=5&border_color=%23A5A9AC&stream=false&header=false&height=185", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Universal_FooterNavigation_20130523_square?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/omniture/s_code.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/omniture/sitecatalyst/omniture_akamai.jsp", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/launch_window.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/foresee/foresee-trigger.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/search.js", END_INLINE
	);
    ns_end_transaction("AddToBag", NS_AUTO_STATUS);
    ns_page_think_time(0);
       
    ns_start_transaction("ViewShoppingCart");
    ns_web_url ("ShoppingCartPage",
        //"URL=http://10.210.222.129:17010/checkout/shopping_cart.jsp",
        "URL=http://www-sf.kohlsecommerce.com/checkout/shopping_cart.jsp",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;",
        "PreSnapshot=webpage_1363258431912.png",
        "Snapshot=webpage_1363258446537.png",
        INLINE_URLS,
    
	"URL=http://www-sf.kohlsecommerce.com/media/foresee/foresee-alive.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery-1.7.2.min.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/global.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/myaccount.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery.validate.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery.validate_product.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/UI_validation.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/modal_validation.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/cart.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/fancybox/jquery.fancybox-1.3.4.pack.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/custom.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery.numeric.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/video.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/myaccount_custom.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/global.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/product-matrix_v1_m56577569836982752.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/gift_registry_fix.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/balance_inquiry.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/custom.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/kohls_custom.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/fancybox/jquery.fancybox-1.3.4.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/my_account.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/tabfix.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/pdn/wishlist.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/pdn/giftguide.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/pdn/wishlist.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/pdn/giftguide.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/pdn/registry.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/pdn/registry.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/skava-custom.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/kohls_v1_m56577569839297458.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/skava-cart.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/launch_window.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/security_policy.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/omniture/mbox.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/omniture/SkavaOmnitureCode.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Shipping-0821-FS50?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Shipping-0821-YesPass?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Shipping-0821-Earn?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/images/kohls-logo.png", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/images/verisign_temp.gif", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1388451?wid=60&hei=60&op_sharpen=1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/tag.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/iframe?c=4DPyaxM", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/omniture/s_code.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/foresee/foresee-trigger.js", END_INLINE

	);
    ns_end_transaction("ViewShoppingCart", NS_AUTO_STATUS);
    ns_page_think_time(0);

}
