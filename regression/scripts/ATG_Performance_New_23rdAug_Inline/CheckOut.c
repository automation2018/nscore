/*-----------------------------------------------------------------------------
    Name: CheckOut
    Recorded By: netstorm
    Date of recording: 03/12/2013 12:51:01
    Flow details:
    Modification History:
    03/22/2013 - Updated to work with CD5 R3 - Madhu
    03/23/2013 - Updated to work with products with options - Madhu    


-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"
#include "Util.c"
void CheckOut()
{
	#ifdef NS_DEBUG_ON
	printf("\n ++++++++++ Check Out ++++++++++++++\n");
    #endif
	if(strcmp(ns_eval_string("{AddToBagSkuId}"), "") == 0)
	{ 
		#ifdef NS_DEBUG_ON
     	printf("\n ++++ CheckOut : No items to checkout - Abandoning session. \n");
  		#endif
  		ns_exit_session();    				        
	}
    /*ns_web_url ("CheckOutPage",
        "URL=http://www-sf.kohlsecommerce.com/checkout/shopping_cart.jsp?_DARGS=/checkout/cart/cart_checkout_form.jsp",
        "METHOD=POST",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "HEADER=Content-Length:526",
        "HEADER=Content-Type:application/x-www-form-urlencoded",
        "COOKIE=cookieSetting;JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;",
        "REDIRECT=YES",
        "LOCATION=http://10.210.222.129:17010/checkout/shipping_billing_information.jsp?_requestid=4780",
        "PreSnapshot=webpage_1363258457485.png",
        "Snapshot=webpage_1363258469538.png",
        //"BODY=_dyncharset=UTF-8&_dynSessConf=6944508524083184195&ci15000027=1&moveToPurchaseInfoSuccessURL=shopping_cart_move_to_checkout_success_url&_D%3AmoveToPurchaseInfoSuccessURL=+&moveToPurchaseInfoErrorURL=shopping_cart_move_to_checkout_error_url&_D%3AmoveToPurchaseInfoErrorURL=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.moveToPurchaseInfoByCommerceId=submit&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.moveToPurchaseInfoByCommerceId=+&_DARGS=%2Fcheckout%2Fcart%2Fcart_checkout_form.jsp",
        "BODY=_dyncharset=UTF-8&_dynSessConf={DynSessionConfSP}&ci{CheckOutCiSP}=1&moveToPurchaseInfoSuccessURL=shopping_cart_move_to_checkout_success_url&_D%3AmoveToPurchaseInfoSuccessURL=+&moveToPurchaseInfoErrorURL=shopping_cart_move_to_checkout_error_url&_D%3AmoveToPurchaseInfoErrorURL=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.moveToPurchaseInfoByCommerceId=submit&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.moveToPurchaseInfoByCommerceId=+&_DARGS=%2Fcheckout%2Fcart%2Fcart_checkout_form.jsp",
        INLINE_URLS,
            "URL=http://10.210.222.129:17010/checkout/shipping_billing_information.jsp?_requestid=4780", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=cookieSetting;JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/foresee/foresee-alive.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/javascript/launch_window.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/javascript/jquery-1.7.2.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/javascript/jquery.fancybox-1.3.4.pack.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/javascript/jquery.maskedinput.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/javascript/global.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/javascript/custom.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/javascript/myaccount.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/javascript/modal_validation.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/javascript/shipping_bill_custom.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/javascript/checkout_custom.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/javascript/jcarousellite.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/css/reset.css", END_INLINE,
            "URL=http://10.210.222.129:17010/media/css/checkout.css", END_INLINE,
            "URL=http://10.210.222.129:17010/media/css/jquery.fancybox-1.3.4.css", END_INLINE,
            "URL=http://10.210.222.129:17010/media/images/kohls-logo-checkout.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/images/loader.gif", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/images/button_continue_wide.gif", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/images/billing-shipping-heading.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/images/indicator-active.gif", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/images/indicator.gif", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/images/sign-in.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/images/arch.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/images/AccordionTab2.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/images/shipping-method-heading.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/images/button_continue.gif", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/images/arch-bag.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/images/your-shopping-bag.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/images/bag-item-background.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://s.btstatic.com/tag.js", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.210.222.129:17010/media/omniture/s_code.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://ww9.kohls.com/b/ss/kohlsatgsitoracle/1/H.25/s76296018332614?AQB=1&ndh=1&t=14%2F2%2F2013%2016%3A24%3A28%204%20-330&ns=kohls&pageName=checkout%3Ashipping%20billing&g=http%3A%2F%2F10.210.222.129%3A17010%2Fcheckout%2Fshipping_billing_information.jsp%3F_requestid%3D4780&r=http%3A%2F%2F10.210.222.129%3A17010%2Fcheckout%2Fshopping_cart.jsp&events=scCheckout&products=%3B91399600%3B1%3B24.99%3Bevent9%3D24.99%2C%3Btax%3B%3B%3Bevent4%3D1.86&c1=checkout&c2=checkout&c3=checkout&v3=external&c4=checkout&c7=checkout&v8=non-search&c9=checkout&v9=cart&c10=checkout&c11=checkout&c17=not%20logged%20in&v17=not%20logged%20in&c18=D%3Dv18&v18=05%3A54%20am&c19=D%3Dv19&v19=thursday&c20=D%3Dv20&v20=week%20day&c22=2013-03-14&v22=Kohl%27s&v48=650250418&c50=P3VgRBpVvPljPQQgD0vMMPfgvV10F2pgvg3GlndNxxv61nn5xh5y!982294971!1363257653903&s=1366x768&c=24&j=1.7&v=N&k=Y&bw=1366&bh=588&pid=cart&pidt=1&oid=functiononclick(event)%7Bjavascript%3Adocument.cart_checkout.submit()%3B%7D&oidt=2&ot=BUTTON&AQE=1", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=s_vi;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/foresee/foresee-trigger.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://10.210.222.129:17010/media/foresee/foresee-surveydef.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;cookieSetting;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE
    );*/
    
    Fill_CheckOutBody();
    ns_start_transaction("CheckOut");
    ns_web_url ("CO_CheckOut",
        "URL=http://www-sf.kohlsecommerce.com/checkout/shopping_cart.jsp?_DARGS=/checkout/cart/cart_checkout_form.jsp",
        "METHOD=POST",
        "HEADER=Accept-Language:en-us,en;q=0.5",
        "HEADER=Content-Length:526",
        "HEADER=Content-Type:application/x-www-form-urlencoded",
        "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;",
        "REDIRECT=YES",
        "LOCATION=http://www-sf.kohlsecommerce.com/checkout/shipping_billing_information.jsp?_requestid=18674",
        "PreSnapshot=webpage_1364021306668.png",
        "Snapshot=webpage_1364021316789.png",
        //"BODY=_dyncharset=UTF-8&_dynSessConf=2976243690354325225&ci54000132=1&moveToPurchaseInfoSuccessURL=shopping_cart_move_to_checkout_success_url&_D%3AmoveToPurchaseInfoSuccessURL=+&moveToPurchaseInfoErrorURL=shopping_cart_move_to_checkout_error_url&_D%3AmoveToPurchaseInfoErrorURL=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.moveToPurchaseInfoByCommerceId=submit&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.moveToPurchaseInfoByCommerceId=+&_DARGS=%2Fcheckout%2Fcart%2Fcart_checkout_form.jsp",
        //"BODY=_dyncharset=UTF-8&_dynSessConf={DynSessionConfSP}&ci{CheckOutCiSP}=1&moveToPurchaseInfoSuccessURL=shopping_cart_move_to_checkout_success_url&_D%3AmoveToPurchaseInfoSuccessURL=+&moveToPurchaseInfoErrorURL=shopping_cart_move_to_checkout_error_url&_D%3AmoveToPurchaseInfoErrorURL=+&%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.moveToPurchaseInfoByCommerceId=submit&_D%3A%2Fatg%2Fcommerce%2Forder%2Fpurchase%2FCartModifierFormHandler.moveToPurchaseInfoByCommerceId=+&_DARGS=%2Fcheckout%2Fcart%2Fcart_checkout_form.jsp",
        "BODY={CheckOutDP}",
        INLINE_URLS,
            "URL=http://www-sf.kohlsecommerce.com/checkout/shipping_billing_information.jsp?_requestid=18674", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/foresee/foresee-alive.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/launch_window.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery-1.7.2.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery.fancybox-1.3.4.pack.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery.maskedinput.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/global.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/custom.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/myaccount.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/modal_validation.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/shipping_bill_custom.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/checkout_custom.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/javascript/jcarousellite.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/images/kohls-logo-checkout.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/images/error-icon.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/css/jquery.fancybox-1.3.4.css", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/css/checkout.css", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/css/reset.css", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/images/loader.gif", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/images/button_continue_wide.gif", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/images/billing-shipping-heading.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/images/indicator-active.gif", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/images/indicator.gif", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/images/sign-in.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/images/arch.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/images/AccordionTab2.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/images/shipping-method-heading.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/images/button_continue.gif", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/images/arch-bag.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/images/your-shopping-bag.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/images/bag-item-background.png", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/omniture/s_code.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/foresee/foresee-trigger.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE,
            "URL=http://ww9.kohls.com/b/ss/kohlsatgsitoracle/1/H.25/s81567681147516?AQB=1&ndh=1&t=23%2F2%2F2013%2012%3A18%3A35%206%20-330&ns=kohls&pageName=checkout%3Ashipping%20billing&g=http%3A%2F%2F10.210.222.225%3A17010%2Fcheckout%2Fshipping_billing_information.jsp%3F_requestid%3D18674&r=http%3A%2F%2F10.210.222.225%3A17010%2Fcheckout%2Fshopping_cart.jsp&events=scCheckout&products=%3B90197036%3B1%3B40.0%3Bevent9%3D40.0%2C%3Btax%3B%3B%3Bevent4%3D2.82&c1=checkout&c2=checkout&c3=checkout&v3=external&c4=checkout&c7=checkout&v8=non-search&c9=checkout&v9=cart&c10=checkout&c11=checkout&c17=not%20logged%20in&v17=not%20logged%20in&c18=D%3Dv18&v18=01%3A48%20am&c19=D%3Dv19&v19=saturday&c20=D%3Dv20&v20=week%20end&c22=2013-03-23&v22=Kohl%27s&v48=680566731&c50=74QVRNMMjgdQwDfTGrkpchmKw57QpLJlLq99gVRgqp9zBvkMF7ST!727627445!1364020428223&s=1366x768&c=24&j=1.7&v=N&k=Y&bw=1366&bh=588&pid=cart&pidt=1&oid=functiononclick(event)%7Bjavascript%3Adocument.cart_checkout.submit()%3B%7D&oidt=2&ot=BUTTON&AQE=1", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=s_vi;", END_INLINE,
            "URL=http://www-sf.kohlsecommerce.com/media/foresee/foresee-surveydef.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;CartTotal;ItemDetails;fsr.a;", END_INLINE
    );
	ns_end_transaction("CheckOut", NS_AUTO_STATUS);
    ns_page_think_time(0);

}
