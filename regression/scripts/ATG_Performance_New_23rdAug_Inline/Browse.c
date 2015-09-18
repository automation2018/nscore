/*-----------------------------------------------------------------------------
    Name:Browse
    Recorded By: netstorm
    Date of recording: 02/27/2013 03:18:09
    Flow details:
    Modification History:
    03/22/2013 - Updated to work with CD5 R3 - Madhu
    03/23/2013 - Updated to work with products with options - Madhu    
    16/04/2013 - Updated to work with Randomization of LeftnavSelection--Anjali
    No of pages : 2
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"
/*
	Steps:
	An anonymous customer is on the "Department" page
	1.Click the left nav links on the "Department" page.
*/
void Browse()
{
	int loop = 0;
	int loophwm = 0;
	int ZeroproductCount = 0;
	#ifdef NS_DEBUG_ON
	printf("\n ++++++++++ Browse ++++++++++++++\n");
	#endif
    loop = ns_get_int_val("BrowseLoop");	
    loophwm = ns_get_int_val("BrowseLoopHWM");	
    #ifdef NS_DEBUG_ON
    printf("\n ++++ Looping Browse for %d \n", loop);
    #endif
    ns_set_int_val("BrowseLoop", loop - 1);

    if (loop == loop) {
    	
    	ns_start_transaction("SaleEventPage");
    	ns_web_url ("TopNavPage",
        	//"URL=http://www-sf.kohlsecommerce.com/sale-event/for-the-home.jsp?CN=3000000277&N=3000000277",
        	"URL=http://www-sf.kohlsecommerce.com/{TopNavUrlFP}",
        	"HEADER=Accept-Language:en-us,en;q=0.5",
        	"COOKIE=JSESSIONID;mbox;s_sess;s_pers;",
        	"PreSnapshot=webpage_1362006863506.png",
        	"Snapshot=webpage_1362006889582.png",
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
"URL=http://www-sf.kohlsecommerce.com/media/css/left-nav.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/css/deals_inline.css", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/omniture/mbox.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/omniture/SkavaOmnitureCode.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Shipping-0821-FS50?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Shipping-0821-YesPass?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Shipping-0821-Earn?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/images/kohls-logo.png", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/SaleBanner-MRKTSpot1-20130822?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/SaleBanner-MRKTSpot2-20130822-LONG?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity1-20130804-C1-Header?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity1-20130804-C1?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity1-20130804-C2?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity1-20130804-C3?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity1-20130804-C4?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity1-20130804-C5?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity1-20130804-C6?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity1-20130804-C7?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity1-20130804-C8?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity1-20130804-C9?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity1-20130804-C10?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-FeatureSpot-20130822?scl=1&qlt=100,1", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity2-20130804-E1?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity2-20130804-E2?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity1-20130804-B1-Header?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity1-20130804-B1?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity1-20130804-B2?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity1-20130804-B3?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity1-20130804-B4?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/JE-MarketingEquity2-20130804-W?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Universal_FooterNavigation_20130523_YesGraphic?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/plugins/likebox.php?href=http%3A%2F%2Fwww.facebook.com%2Fkohls&width=315&colorscheme=light&connections=5&border_color=%23A5A9AC&stream=false&header=false&height=185", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/is/image/kohls/Universal_FooterNavigation_20130523_square?scl=1&qlt=100", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/tag.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/iframe?c=4DPyaxM", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/omniture/s_code.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/omniture/sitecatalyst/omniture_akamai.jsp", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/launch_window.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/foresee/foresee-trigger.js", END_INLINE,    
	);
    	ns_end_transaction("SaleEventPage", NS_AUTO_STATUS);
    	ns_page_think_time(40.106);
    }
    
    
    if (loop == 1) {
    	ns_save_string (ns_eval_string ("{LeftNavUrlSP1}"), "LeftNavUrlSP");
    } else if (loop == 2) {
    	ns_save_string (ns_eval_string ("{LeftNavUrlSP2}"), "LeftNavUrlSP");
    } else if (loop == 3) {
        ns_save_string (ns_eval_string ("{LeftNavUrlSP3}"), "LeftNavUrlSP");
    } else if (loop == 4) {
    	ns_save_string (ns_eval_string ("{LeftNavUrlSP4}"), "LeftNavUrlSP");
    } else {
    	ns_save_string (ns_eval_string ("{LeftNavUrlSP5}"), "LeftNavUrlSP");
    }
    
    
    //Page Auto splitted for Link 'Rugs' Clicked by User
    ns_start_transaction("CatalogPage");    
    ns_web_url ("LeftNavPage",
        //"URL=http://www-sf.kohlsecommerce.com/catalog/for-the-home-home-decor-rugs.jsp?CN=3000002078&N=3000002078",
        //"URL=http://www-sf.kohlsecommerce.com/catalog/toys.jsp?CN=3000001397&N=3000001397+4294732972",
        //"URL=http://www-sf.kohlsecommerce.com/catalog/juniors-white.jsp?CN=4294719935+4294902518&N=4294719935+3000022155+4294902523+4294902518",
        //"URL=http://www-sf.kohlsecommerce.com/{LeftNavUrlFP}", 
        "URL=http://www-sf.kohlsecommerce.com/catalog/jennifer-lopez-jewelry.jsp",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "COOKIE=JSESSIONID;mbox;s_sess;s_pers;",
        "PreSnapshot=webpage_1362006929601.png",
        "Snapshot=webpage_1362007014002.png",
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
    
    
    ZeroproductCount = ns_get_int_val("ZeroProductsCountSP_count");
	if(ZeroproductCount == 0)
	{
        //if(strlen(ns_eval_string("{ZeroProductsSP}")== 0))                          
    	ns_end_transaction("CatalogPage", NS_AUTO_STATUS);              
	}                 
	else
	{
		//#ifdef NS_DEBUG_ON
    	//printf("++++++ LeftNavigation_NoProducts URL = [%s] ++++++ \n",ns_eval_string("{LeftNavUrlFP}"));
    	//#endif
    	ns_end_transaction_as("CatalogPage", 0, "CatalogPage_NoProducts");	      
	}
		         
    ns_page_think_time(31.456);
    
    #ifdef NS_DEBUG_ON
	printf("\n ++++++++++ LeftNavigation URL ++++++++++ [%s] \n", ns_eval_string ("{LeftNavUrlSP}"));
	#endif

    /*
    ns_start_transaction("ProductDetailPage");
    ns_web_url ("ProductPage",
        //"URL=http://10.210.205.1:17010/product/prd-384796/vtech-explore-learn-helicopter.jsp",
        //"URL=http://10.210.205.1:17010/product/prd-731799/melissa-doug-bug-jug-fill-spill-set.jsp",
        "URL=http://10.210.205.1:17010/{TopNavPdpFP}",GG
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;",
        "PreSnapshot=webpage_1363333210798.png",
        "Snapshot=webpage_1363333564062.png",
        INLINE_URLS,
            "URL=http://10.210.205.1:17010/media/foresee/foresee-alive.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/jquery-1.7.2.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/global.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/myaccount.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/jquery.validate_product.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/UI_validation.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/modal_validation.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/cart.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/fancybox/jquery.fancybox-1.3.4.pack.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/custom.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/jquery.numeric.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/video.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/myaccount_custom.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://d3t1dw6evd1rv7.cloudfront.net/kregistry/wishlist.js", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://d3t1dw6evd1rv7.cloudfront.net/kregistry/giftguide.js", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://d3t1dw6evd1rv7.cloudfront.net/kregistry/registry.js", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/kohls_v1_m56577569839297458.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/skava-pdp.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/jquery.nicescroll.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/scroll.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/jcarousellite.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/carousel_inline.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/product.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/kohls_v1_m56577569836982750.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/jcarousellite_1.0.1.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/cloud-zoom.1.0.2.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/jquery.validate_tell.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/fancybox/jquery.easing-1.3.pack.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/fancybox/jquery.fancybox-1.3.4.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/fancybox/jquery.mousewheel-3.0.4.pack.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/customPDP.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/omniture/mbox.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/css/cloud-zoom.css", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/jquery.nicescroll.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;fsr.a;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/jcarousellite_1.0.1.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;fsr.a;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/myaccount_custom.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;fsr.a;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/fancybox/jquery.easing-1.3.pack.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;fsr.a;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/fancybox/jquery.fancybox-1.3.4.pack.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;fsr.a;", END_INLINE,
            "URL=http://kohls.tt.omtrdc.net/m2/kohls/mbox/standard?mboxHost=10.210.205.1&mboxSession=1363333109171-172636&mboxPC=1363333109171-172636.17_15&mboxPage=1363333216325-596327&screenHeight=768&screenWidth=1366&browserWidth=1366&browserHeight=588&browserTimeOffset=330&colorDepth=24&mboxCount=1&mbox=kohlscom_equity_bar&mboxId=0&mboxTime=1363353016341&mboxURL=http%3A%2F%2F10.210.205.1%3A17010%2Fproduct%2Fprd-384796%2Fvtech-explore-learn-helicopter.jsp&mboxReferrer=http%3A%2F%2F10.210.205.1%3A17010%2Fsearch.jsp%3Fsearch%3Dhelicopter%26_requestid%3D857&mboxVersion=40", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/sku_pdp.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;fsr.a;", END_INLINE,
            "URL=http://kohls.tt.omtrdc.net/m2/kohls/mbox/standard?mboxHost=10.210.205.1&mboxSession=1363333109171-172636&mboxPC=1363333109171-172636.17_15&mboxPage=1363333216325-596327&screenHeight=768&screenWidth=1366&browserWidth=1366&browserHeight=588&browserTimeOffset=330&colorDepth=24&mboxCount=2&mbox=kohlscom_product384796_feature&mboxId=0&mboxTime=1363353026436&mboxURL=http%3A%2F%2F10.210.205.1%3A17010%2Fproduct%2Fprd-384796%2Fvtech-explore-learn-helicopter.jsp&mboxReferrer=http%3A%2F%2F10.210.205.1%3A17010%2Fsearch.jsp%3Fsearch%3Dhelicopter%26_requestid%3D857&mboxVersion=40", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/384796_Multi/None?wid=400&hei=400&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/384796?wid=60&hei=60&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://www.facebook.com/plugins/like.php?href=http://10.210.205.1:17010/product/prd-384796/vtech-explore-learn-helicopter.jsp&ref=product_page&send=false&layout=button_count&width=200&show_faces=true&action=like&colorscheme=light&font=verdana&height=25", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.210.205.1:17010/media/images/email_v1_m56577569832236561.gif", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;fsr.a;", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/676324_Multi/None?wid=75&hei=75&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/864116_Multi/None?wid=75&hei=75&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/901955_Multi/None?wid=75&hei=75&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://s.btstatic.com/tag.js", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.210.205.1:17010/media/images/shadow-helper.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www.facebook.com/plugins/likebox.php?href=http%3A%2F%2Fwww.facebook.com%2Fkohls&width=315&colorscheme=light&connections=5&border_color=%23A5A9AC&stream=false&header=false&height=185", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.210.205.1:17010/media/omniture/s_code.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;fsr.a;", END_INLINE,
            "URL=http://ww9.kohls.com/b/ss/kohlscomdev/1/H.25/s46293540921072?AQB=1&ndh=1&t=15%2F2%2F2013%2013%3A10%3A27%205%20-330&ns=kohls&pageName=pdp%3A(384796)%20vtech%20explore%20and%20learn%20helicopter&g=http%3A%2F%2F10.210.205.1%3A17010%2Fproduct%2Fprd-384796%2Fvtech-explore-learn-helicopter.jsp&r=http%3A%2F%2F10.210.205.1%3A17010%2Fsearch.jsp%3Fsearch%3Dhelicopter%26_requestid%3D857&events=prodView%2Cevent3&products=%3B384796%3B%3B%3B%3Bevar16%3Dn&v3=external&c4=product%20detail%20page&v8=non-search&v9=search%20results%3A%20page%20%201&c17=not%20logged%20in&v17=not%20logged%20in&c18=D%3Dv18&v18=02%3A40%20am&c19=D%3Dv19&v19=friday&c20=D%3Dv20&v20=week%20day&c22=2013-03-15&v22=Kohl%27s&c50=FRDGRCPHGV03ykh0zl9QnH2p7MNhQdWFr0wTx4nf2wnB2lJ6JhsC!1397552765!1363333095556&s=1366x768&c=24&j=1.7&v=N&k=Y&bw=1366&bh=588&AQE=1", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=s_vi;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/javascript/launch_window.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;fsr.a;", END_INLINE,
            "URL=http://10.210.205.1:17010/media/foresee/foresee-trigger.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;fsr.a;", END_INLINE,
            "URL=https://d3t1dw6evd1rv7.cloudfront.net/kohlswishlist/v201303010537/img/addToList.png", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=https://d3t1dw6evd1rv7.cloudfront.net/kohlsregistry/v201303140801/img/add_to_reg.png", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/384796_Multi/None?wid=1000&hei=1000&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.210.205.1:17010/media/images/addtobag_v1_m56577569832236562.gif", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;fsr.a;", END_INLINE,
            "URL=https://d3t1dw6evd1rv7.cloudfront.net/kohlsregistry/v201303140801/img/aTLLeft.png", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=https://d3t1dw6evd1rv7.cloudfront.net/kohlsregistry/v201303140801/img/aTLCenter.png", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=https://d3t1dw6evd1rv7.cloudfront.net/kohlsregistry/v201303140801/img/aTLRight.png", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=https://d3t1dw6evd1rv7.cloudfront.net/kohlswishlist/v201303010537/img/aTLLeft.png", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=https://d3t1dw6evd1rv7.cloudfront.net/kohlswishlist/v201303010537/img/aTLCenter.png", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=https://d3t1dw6evd1rv7.cloudfront.net/kohlswishlist/v201303010537/img/aTLRight.png", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.210.205.1:17010/media/foresee/foresee-surveydef.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;fsr.a;", END_INLINE,
            "URL=http://static.ak.fbcdn.net/rsrc.php/v2/yh/r/Ad2xCO8fWgA.js", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://static.ak.fbcdn.net/rsrc.php/v2/yh/r/Ad2xCO8fWgA.js", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://profile.ak.fbcdn.net/hprofile-ak-snc6/186177_1500105145_1427133611_q.jpg", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://profile.ak.fbcdn.net/hprofile-ak-ash4/371711_100002010730905_1972428977_q.jpg", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.210.205.1:17010/product/prd-384796/", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=cookieSetting;JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", "REDIRECT=YES", "LOCATION=http://10.210.205.1:17010/", END_INLINE,
            "URL=http://10.210.205.1:17010/", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;", END_INLINE
    );
    ns_end_transaction("ProductDetailPage", NS_AUTO_STATUS);
    ns_page_think_time(0);
    */
    
}
