/*-----------------------------------------------------------------------------
    Name:SortProducts
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

void SortProducts()
{	
	int PagesNavigated = 0;
	int ZeroproductCount = 0;
	//int DoSort = ns_get_random_number_int(0, 5); // Randomize if user does a sort
	int DoSort = ns_get_random_number_int(0, 2); // Randomize if user does a sort

	if(DoSort != NO) // User is doing sort
	{  
		ZeroproductCount = ns_get_int_val("ZeroProductsCountSP_count");
		if(ZeroproductCount > 0)
		{		
    	 // Zero products.. skip this
    	 return;
		}
		
				
		#ifdef NS_DEBUG_ON	
		printf("\n ++++++++++ Sort Product YES ++++++++++ \n");
		#endif
           ns_start_transaction("SortPage");
           ns_web_url ("SortPage",
        	"URL=http://www-sf.kohlsecommerce.com/search.jsp?N=0&search=socks&S=3",
        	//"URL=http://www-sf.kohlsecommerce.com/search.jsp",
        	"HEADER=Accept-Language:en-us,en;q=0.5",
        	"COOKIE=JSESSIONID;Tracking_Cookie:4730053;mbox;s_sess;s_pers;fsr.s;",
        	"PreSnapshot=webpage_1366303119200.png",
        	"Snapshot=webpage_1366303175666.png",
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
"URL=http://www-sf.kohlsecommerce.com/media/images/product_badges/warning_v1_m56577569839119759.gif", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1255296_Ivory_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1255296_Pink_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1255296_Turquoise_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/images/product_badges/Online_Exclusive_v1_m56577569839119755.gif", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1255289_Ivory_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1255289_Pink_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1255289_Teal_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1098555_Purple_Navy_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1170036_Black_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1170036_Champagne_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/images/bogo_images/bogo_1_1_P_50_v1_m56577569835792921.gif", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1171032_Black_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1171032_Ivory_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1098535_Green_Purple_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1098535_Purple_Red_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1223393_Yellow_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1223368_Ivory_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1223368_Mint_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1223368_Pink_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1430519_Athletic_Red_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1430519_Black_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/701833_Brights_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/734130_Black_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/734130_Midnight_Navy_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/734130_Pink_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/734130_Silver_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/734130_White_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1254946_Mean_Green_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1254946_Pink_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1254946_University_Red_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1254946_Varsity_Royal_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1255297_Ivory_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1255297_Mint_sw?wid=20&hei=20", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/1255297_Pink_sw?wid=20&hei=20", END_INLINE,
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
          ns_end_transaction("SortPage", NS_AUTO_STATUS);
          ns_page_think_time(0);
          //printf("\n **************Sorting Ends***********\n");
          PagesNavigated = PagesNavigated + 1;
 	}
 	else
 	{
		#ifdef NS_DEBUG_ON
 		printf("\n ++++++++++ Sort Product NO ++++++++++ \n");
		#endif
 	}
                
    // Update this step deatils globally 
 	ProductSelectionMoveNext(3, PagesNavigated); //Current step number = 3, Pages naviagted in this step is = PagesNavigated
}
