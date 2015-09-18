/*-----------------------------------------------------------------------------
    Name: Home
    Recorded By: netstorm
    Date of recording: 02/16/2013 03:08:39
    Flow details:
    Modification History:
    03/22/2013 - Updated to work with CD5 R3 - Madhu
    03/23/2013 - Updated to work with products with options - Madhu    

    No of pages : 1
-----------------------------------------------------------------------------*/
/*
	Steps:
	1. Enter a valid keyword in the �Search Text Box� field.(For Ex: jeans,women jeans)
	2. Click the �Search� button or hit the Enter key.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void Url_Res()
{

int size = 1;

ns_save_data_ex(ns_eval_string("{random}"), NS_TRUNC_FILE, "%s", ns_url_get_resp_msg(&size));



}
void Home()
{ 
	int lcount=0;
	int GoToHome = ns_get_random_number_int(0, 99); 

	if(GoToHome < 100)
	{	
		#ifdef NS_DEBUG_ON
		printf("\n ++++++++++ HomePage ++++++++++++++\n");
    	#endif
    	ns_start_transaction("HomePage");	
    	ns_web_url ("HomePage",
    	    //"URL=http://www-sf.kohlsecommerce.com/kohlsStore/",
        	"URL=http://www-sf.kohlsecommerce.com/Home.html",
        	"HEADER=Accept-Language:en-us,en;q=0.5",
        	"POSTURLCALLBACK=Url_Res",
		"PreSnapshot=webpage_1361007369767.png",
        	"Snapshot=webpage_1361007395075.png",

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
"URL=http://www-sf.kohlsecommerce.com/media/omniture/mbox.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/omniture/SkavaOmnitureCode.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Shipping-0821-FS50?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Shipping-0821-YesPass?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Shipping-0821-Earn?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/images/kohls-logo.png", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot1-20130822-YesPass01?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot1-20130822-YesPass02?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot1-20130822-Bonusbuys?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot1-20130822-Kcash?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot1-20130822-Callout01-1?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot1-20130822-Callout01B?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot1-20130822-Callout01C?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot1-20130822-Callout01D?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot1-20130822-Callout01E?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot1-20130822-Callout02?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot1-20130822-Callout03?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot1-20130822-Callout04?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot1-20130822-Callout05?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot1-20130822-OHStatement?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot1-20130822-Callout06?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot1-20130822-Callout07?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot1-20130822-Callout08?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeatureSpot2-20130822-BTSShop01?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeatureSpot2-20130822-BTSShop02?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeatureSpot2-20130822-BTSShop03?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeatureSpot2-20130822-BTSShop04?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeatureSpot2-20130822-BTSShop05?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeatureSpot2-20130822-BTSShop06?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeatureSpot2-20130822-BTSShop07?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot2-20130822-KCares01?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/HP-FeaturedSpot2-20130822-KCares02?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Equity-20130822-WhiteSale?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Equity-20130822-TekGear-1?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Universal_FooterNavigation_20130523_YesGraphic?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/plugins/likebox.php?href=http%3A%2F%2Fwww.facebook.com%2Fkohls&width=315&colorscheme=light&connections=5&border_color=%23A5A9AC&stream=false&header=false&height=185", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Universal_FooterNavigation_20130523_square?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/tag.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/iframe?c=4DPyaxM", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/omniture/s_code.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/omniture/sitecatalyst/omniture_akamai.jsp", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/launch_window.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/foresee/foresee-trigger.js", END_INLINE
	    	);

    	ns_end_transaction("HomePage", NS_AUTO_STATUS);
    	ns_page_think_time(0);
	}


	//ns_set_int_val("SearchLoop", ns_get_random_number_int(2,3));
	ns_set_int_val("SearchLoop", ns_get_random_number_int(1,2));
	//ns_set_int_val("BrowseLoop", ns_get_random_number_int(2,3));
	
	//lcount = ns_get_random_number_int(3,5);
	lcount = ns_get_random_number_int(2,3);
	ns_set_int_val("BrowseLoop", lcount);
	ns_set_int_val("BrowseLoopHWM", lcount);
}
