/*-----------------------------------------------------------------------------
    Name:SearchProductId
    Recorded By: netstorm
    Date of recording: 02/16/2013 06:13:49
    Flow details:
    Modification History:
    03/22/2013 - Updated to work with CD5 R3 - Madhu
    03/23/2013 - Updated to work with products with options - Madhu 
    04/10/2013 - Tested with CD5 R15 - Anjali
    04/17/2013- Updated to work with single and multi- Anjali   
    No of pages : 2
-----------------------------------------------------------------------------*/
/*
	Steps:
	1. Enter the valid Web ID in �Search Text Box� field  displayed in the global header.                                             
	2. Click on �Search� button or hit Enter key.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void SearchProductId()
{
	int  AvaliSkuCount = 0;
    int  SkuIdCount = 0;
    char SkuIdvariable[128];
    char SkuIdstatus[128];
    char *StatusType;
    int i = 0;

    if(strcmp(ns_eval_string("{DynSessionConfSP}"), "") == 0)
    {
    	ns_start_transaction("HomePage_SearchPid");
	    	ns_web_url ("HomePageSearch",
        	//"URL=http://www-sf.kohlsecommerce.com/kohlsStore/",
        	"URL=http://www-sf.kohlsecommerce.com/Home.html",
        	"HEADER=Accept-Language:en-us,en;q=0.5",
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
    	ns_end_transaction("HomePage_SearchPid", NS_AUTO_STATUS);
    	ns_page_think_time(0);    
    }
	
	#ifdef NS_DEBUG_ON
	printf("\n ++++++++++ Search Product Id ++++++++++++++\n");
	#endif
    ns_start_transaction("SearchProductID");
    ns_web_url ("SearchProductIdPage",
        //"URL=http://www-sf.kohlsecommerce.com/kohlsStore/search.jsp?_dyncharset=UTF-8&_dynSessConf=1948367958937601290&search=731799&_D%3Asearch=+&%2Fcom%2Fkohls%2Fsearch%2Fformhandler%2FSearchFormHandler.queryBean.requestType=search&_D%3A%2Fcom%2Fkohls%2Fsearch%2Fformhandler%2FSearchFormHandler.queryBean.requestType=+&submit-search=&_D%3Asubmit-search=+&_DARGS=%2FkohlsStore%2Fcatalog%2Fsearch%2Fsearch.jsp",
        //"URL=http://www-sf.kohlsecommerce.com/search.jsp?_dyncharset=UTF-8&_dynSessConf={DynSessionConfSP}&search={ProductIdFP}&_D%3Asearch=+&%2Fcom%2Fkohls%2Fsearch%2Fformhandler%2FSearchFormHandler.queryBean.requestType=search&_D%3A%2Fcom%2Fkohls%2Fsearch%2Fformhandler%2FSearchFormHandler.queryBean.requestType=+&submit-search=&_D%3Asubmit-search=+&_DARGS=%2FkohlsStore%2Fcatalog%2Fsearch%2Fsearch.jsp",
        "URL=http://www-sf.kohlsecommerce.com/search.jsp?_dyncharset=UTF-8&search={ProductIdFP}&_D%3Asearch=+&%2Fcom%2Fkohls%2Fsearch%2Fformhandler%2FSearchFormHandler.queryBean.requestType=search&_D%3A%2Fcom%2Fkohls%2Fsearch%2Fformhandler%2FSearchFormHandler.queryBean.requestType=+&submit-search=&_D%3Asubmit-search=+&_DARGS=%2Fcatalog%2Fsearch%2Fsearch.jsp",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "COOKIE=JSESSIONID;mbox;s_sess;s_pers;",
        "REDIRECT=YES",
        "LOCATION=http://www-sf.kohlsecommerce.com/kohlsStore/product/prd-731799/melissa-and-doug-bug-jug-fill-and-spill-set.jsp?skuId=731799&searchTerm=731799&_requestid=5306",
        "PreSnapshot=webpage_1361018548419.png",
        "Snapshot=webpage_1361018585417.png",
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
    
    if(!strcmp(ns_eval_string("{ItemCheckAvailSP}"),"no_result"))
    {
    	ns_end_transaction_as("SearchProductID", 0, "SearchProductID_NotAvailable");
    	
    }
    
    // Check if there are any Avaliable SkuIDs    
    AvaliSkuCount = ns_get_int_val("AvaliableSkuSP_count");
    #ifdef NS_DEBUG_ON
    printf("AvaliSkuCount = %d", AvaliSkuCount);
    #endif
    if(AvaliSkuCount == 0)
    {
    	ns_end_transaction_as("SearchProductID", 0, "SearchProductID_NoStock");	  
	    #ifdef NS_DEBUG_ON
    	printf("\n ++++ SearchProductID : No available SkuId found for the product. : %s \n", ns_eval_string("{ProductSelectUrlSP}"));
    	#endif
    	//  Log the  UnAvailable SKUID to file - START   
    	SkuIdCount = ns_get_int_val("SkuIdSP_count");
    	for(i = 0; i < SkuIdCount; i++)
    	{
		
      		sprintf(SkuIdstatus,"{SkuIdStatusSP_%d}", (i + 1)); //To get the status of the SkuId
            
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
        		// This SkuId is good.. continue looping..
  	  		}
  			else
  	  		{
	   		  sprintf(SkuIdvariable,"{SkuIdSP_%d}", (i + 1)); // To get the Index of in stock SkuId
              ns_save_data_ex("UnAvailableSkuId_List.txt", NS_APPEND_FILE, SkuIdvariable);
			      #ifdef NS_DEBUG_ON
     			  printf("\n SearchProductID : SkuID %s is out of stock.", ns_eval_string(SkuIdvariable)); 
     			  #endif
  	  		}
		}
    	//  Log the  UnAvailable SKUID to file - END   

    	return;    		
    }
    else
    {
    	ns_end_transaction("SearchProductID", NS_AUTO_STATUS);
    }
    
    ns_page_think_time(0);
    
/*    

    // The product viewed may be a single product or collection item
	// End of this flow a single product must be avaliable for adding to cart  
	#ifdef NS_DEBUG_ON
	printf("\n The value of ItemCheckBlockSP is [%s]\n",ns_eval_string("{ItemTypeCheckBlockSP}"));
	#endif
	#ifdef NS_DEBUG_ON
	printf("\n The value of ItemCheckSP is [%s]\n",ns_eval_string("{ItemTypeCheckSP}"));	
	#endif
	if(!strcmp(ns_eval_string("{ItemTypeCheckSP}"),"collection_id"))
    {
    	// This is a collection item..
    	#ifdef NS_DEBUG_ON
    	printf("\n ++++ SearchProductId : It is a MultiItem ++++ \n");    	    	
	    #endif
    	ns_start_transaction("ViewCollectionItem");
    	ns_web_url ("SPId_CollectionItemPage",
        	//"URL=http://www-sf.kohlsecommerce.com/product/prd-c29118/style-safari-separates-girls-7-16.jsp?action=&prodId=c29118&activeProdId=1091332",
        	"URL=http://www-sf.kohlsecommerce.com/product/{CollectionUrlSP}",
        	"HEADER=Accept-Language:en-us,en;q=0.5",
        	"COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;",
        	"PreSnapshot=webpage_1366176152505.png",
        	"Snapshot=webpage_1366176173565.png",
        	INLINE_URLS,
            "URL=http://www-sf.kohlsecommerce.com/media/foresee/foresee-alive.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery-1.7.2.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/global.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/myaccount.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery.validate.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery.validate_product.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/UI_validation.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/modal_validation.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/cart.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/fancybox/jquery.fancybox-1.3.4.pack.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/custom.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery.numeric.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/video.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/myaccount_custom.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/skava-pdp.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery.nicescroll.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/scroll.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/jcarousellite.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/carousel_inline.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/product.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/fb_like_pdt.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/kohls_v1_m56577569836982750.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery.fancybox-1.3.4.pack.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/jcarousellite_1.0.1.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/cloud-zoom.1.0.2.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/customPDP.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/fancybox/jquery.easing-1.3.pack.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/product_reviews_bv_head.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://reviews.kohls.com/bvstaging/static/9025/bazaarvoice.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=s_vi;ARPTH;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/omniture/mbox.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/kohls_v1_m56577569839297458.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/jcarousellite_1.0.1.min.js", END_INLINE,
            "URL=http://kohls.ugc.bazaarvoice.com/bvstaging/module/9025/jquery.core.js", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://kohls.ugc.bazaarvoice.com/bvstaging/module/9025/cmn/9025/display.pkg.js", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://kohls.ugc.bazaarvoice.com/bvstaging/module/9025/rr/9025/display.pkg.js", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/sku_pdp_collection.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1091332_Gold?wid=400&hei=400&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1091332?wid=50&hei=50&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1091332_Gold_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://kohls.tt.omtrdc.net/m2/kohls/mbox/standard?mboxHost=10.210.222.225&mboxSession=1366175687711-29113&mboxPC=1366175687711-29113.17_38&mboxPage=1366176155474-774897&screenHeight=768&screenWidth=1366&browserWidth=1366&browserHeight=588&browserTimeOffset=330&colorDepth=24&mboxCount=1&entity.id=1091332&entity.name=Mudd%20Giraffe%20Tee%20-%20Girls%207-16&entity.pageURL=%2Fproduct%2Fprd-1091332%2Fmudd-giraffe-tee-girls-7-16.jsp&entity.thumbnailURL=http%3A%2F%2Fmedia.kohls.com.edgesuite.net%2Fis%2Fimage%2Fkohls%2F1091332_Gold%3Fwid%3D75%26amp%3Bamp%3Bhei%3D75%26amp%3Bamp%3Bop_sharpen%3D1&entity.brand=Mudd&entity.value=%2420.00&entity.ratingsImageUrl=&entity.reviewCount=&entity.rating=&entity.productRatingURL=%2Fproduct%2Fprd-1091332%2Fmudd-giraffe-tee-girls-7-16.jsp%3FclickAction%3Dcsrating%23reviews&entity.productReviewURL=%2Fproduct%2Fprd-1091332%2Fmudd-giraffe-tee-girls-7-16.jsp%3FclickAction%3DcsreviewCount%23reviews&entity.available=true&mbox=kohlscom_product_recommendations&mboxId=0&mboxTime=1366195971321&mboxURL=http%3A%2F%2F10.210.222.225%3A17010%2Fproduct%2Fprd-c29118%2Fstyle-safari-separates-girls-7-16.jsp%3Faction%3D%26prodId%3Dc29118%26activeProdId%3D1091332&mboxReferrer=http%3A%2F%2F10.210.222.225%3A17010%2Fproduct%2Fprd-c29118%2Fstyle-safari-separates-girls-7-16.jsp%3Faction%3D%26prodId%3Dc29118%26activeProdId%3D1001647&mboxVersion=40", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/images/sub/cross_top_v1_m56577569832235932.gif", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/449398_Charcoal?wid=75&amp;hei=75&amp;op_sharpen=1&wid=150&hei=150", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://kohls.ugc.bazaarvoice.com/9025/4.7/5/rating.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/115554_Cornstalk?wid=75&amp;hei=75&amp;op_sharpen=1&wid=150&hei=150", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://kohls.ugc.bazaarvoice.com/9025/2.5/5/rating.gif", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1255761_White?wid=75&amp;hei=75&amp;op_sharpen=1&wid=150&hei=150", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/489118_Sterling_Silver?wid=75&amp;hei=75&amp;op_sharpen=1&wid=150&hei=150", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/images/sub/cross_bottom_v1_m56577569832235933.gif", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://s.btstatic.com/tag.js", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/omniture/s_code.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://ww9.kohls.com/b/ss/kohlsatgsitoracle/1/H.25/s72343788377233?AQB=1&ndh=1&t=17%2F3%2F2013%2010%3A52%3A52%203%20-330&ns=kohls&pageName=pdp%3A(c29118)%20style%20safari%20separates%20-%20girls%207-16&g=http%3A%2F%2F10.210.222.225%3A17010%2Fproduct%2Fprd-c29118%2Fstyle-safari-separates-girls-7-16.jsp%3Faction%3D%26prodId%3Dc29118%26activeProdId%3D1091332&r=http%3A%2F%2F10.210.222.225%3A17010%2Fproduct%2Fprd-c29118%2Fstyle-safari-separates-girls-7-16.jsp%3Faction%3D%26prodId%3Dc29118%26activeProdId%3D1001647&events=prodView%2Cevent3&products=%3Bc29118%3B%3B%3B%3Bevar16%3Dn&c1=homepage&c2=homepage&c3=homepage&v3=external&c4=product%20detail%20page&c5=non-search&c7=homepage&v8=non-search&c9=homepage&v9=pdp%3A(c29118)%20style%20safari%20separates%20-%20girls%207-16&c10=homepage&c11=homepage&c17=not%20logged%20in&v17=not%20logged%20in&c18=D%3Dv18&v18=00%3A22%20am&c19=D%3Dv19&v19=wednesday&c20=D%3Dv20&v20=week%20day&c22=2013-04-17&v22=Kohl%27s&v40=atg&v42=original&c50=NcMQKXHBCgsSZMK7SY1KrXyJnIp0khx1Cq5ekB6N4sTAbV0y7Oy1!-2059203790!1366175677042&v59=product%20page&tnt=53507%3A4%3A0%2C&s=1366x768&c=24&j=1.7&v=N&k=Y&bw=1366&bh=588&AQE=1", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=s_vi;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/foresee/foresee-trigger.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/foresee/foresee-surveydef.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE
    	);
    	ns_end_transaction("ViewCollectionItem", NS_AUTO_STATUS);
    	ns_page_think_time(0);
  
    }
*/     
    
   
}
