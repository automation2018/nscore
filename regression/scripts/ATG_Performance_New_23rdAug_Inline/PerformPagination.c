/*-----------------------------------------------------------------------------
    Name:PerformPagination
    Recorded By: Madhu/Bibi
    Date of recording: 03/26/2013 03:47:42
    Flow details:
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"
#include "Util.c"


void PerformPagination()
{	
	int MaxLoop = 0;
	int MaxLinks = 0;  
	int PagesNavigated = 0; 
	int i;
    int ZeroproductCount = 0;
	int MaxNavigatePages = ns_get_int_val("nsMaxNavigateInNextStep"); // Max number of pages I can navigate here 	
	//int DoPagination = ns_get_random_number_int(0, 5); // Randomize if user does a pagination
	int DoPagination = ns_get_random_number_int(0, 2); // Randomize if user does a pagination

		
	if(DoPagination != NO) // User is doing pagination
	{		
		ZeroproductCount = ns_get_int_val("ZeroProductsCountSP_count");
		if(ZeroproductCount > 0)
		{		
    	 // Zero products.. skip this
    	 return;
		}
       

		#ifdef NS_DEBUG_ON
		printf("\n ++++++++++ PerformPagination YES ++++++++++ \n");
		#endif
	    MaxLinks = ns_get_int_val("PaginationUrlSPCount_count");  
	    
	    #ifdef NS_DEBUG_ON
	    printf("\n MaxLinks: %d\n",MaxLinks);
	    #endif
	    #ifdef NS_DEBUG_ON
	 	printf("\n MaxNavigatePages: %d\n",MaxNavigatePages);
	 	#endif

	 	if(MaxLinks == 0) //in case there is no pages to navigate 
	 	{ 
	 		#ifdef NS_DEBUG_ON
	    	printf("\n ++++ MaxLinks= %d, No pages to do pagination.\n",MaxLinks); 
	    	#endif 
	 	} 
	 	else 
	 	{
	    	MaxLoop = GetMin(MaxNavigatePages, MaxLinks);
	    	#ifdef NS_DEBUG_ON
	    	printf("\n ++++ Perform Pagination for %d times ++++ \n",MaxLoop);
	    	#endif
	    
	   	 	//loop to apply paginations on the search result	   	    
  			for (i=0; i < MaxLoop; i++) 
  			{
	   			//printf("Before PaginationPage\n");   
	    		ns_start_transaction("Pagination");
	    		ns_web_url ("PaginationPage",
	        	//"URL=http://10.210.154.161:17010/search.jsp?N=0&search=socks&WS=96",
	        	"URL=http://www-sf.kohlsecommerce.com/{PaginationUrlSP}",
	        	"HEADER=Accept-Language:en-us,en;q=0.5",
	        	"COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;",
	        	"PreSnapshot=webpage_1364292944927.png",
	        	"Snapshot=webpage_1364292963580.png",
	        	INLINE_URLS,
        	"URL=http://10.210.154.161:17010/media/foresee/foresee-alive.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
	        "URL=http://10.210.154.161:17010/media/javascript/jquery-1.7.2.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
 	        "URL=http://10.210.154.161:17010/media/javascript/global.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
 	        "URL=http://10.210.154.161:17010/media/javascript/myaccount.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
 	        "URL=http://10.210.154.161:17010/media/javascript/jquery.validate.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,	
 	        "URL=http://10.210.154.161:17010/media/javascript/UI_validation.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/modal_validation.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/cart.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/fancybox/jquery.fancybox-1.3.4.pack.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/custom.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/jquery.numeric.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/video.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/myaccount_custom.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/kohls_v1_m56577569839297458.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/fb_like_pdt.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/jquery.nicescroll.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/scroll.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/jcarousellite.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/cloud-zoom.1.0.2.min.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/carousel_inline.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/product.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/search_functionality.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/kohls_v1_m56577569836982750.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/omniture/mbox.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/custom.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/157850_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/157850_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/157850_Brown_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/529030_White?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/529030_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/529030_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.210.154.161:17010/mediaBUY_3_GET_1_50_PERCENTAGE", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", "REDIRECT=YES", "LOCATION=http://10.210.154.161:17010/", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/320107_Navy?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/320107_Navy_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1152198_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1152198_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1152198_Charcoal_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1152198_Tan_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/606126_Cobblestone?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/606126_Cobblestone_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/606126_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/703560_Multi?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/703560_Multi_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/112278_White?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/112278_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/112278_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/424201_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/424201_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/424201_Taupe_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/424201_Navy_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/716590_Gray_Combo?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/716590_Gray_Combo_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/716590_Light_Gray_Combo_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/927614_Gray_Melange?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/927614_Gray_Melange_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/927614_Bootstrap_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/927614_Navy_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/966993_White?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/966993_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/966993_Gray_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1234026_Gray_Heather?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1234026_Gray_Heather_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1171093_Navy?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1171093_Navy_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1171093_Gray_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1171093_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1234051_Green?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1234051_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1234051_Green_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1147361_Gray?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1147361_Gray_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1147361_Dark_Brown_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1037611_Multi?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1037611_Multi_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1125074_White?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1125074_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1229012_Multi/None?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1229012_Multi/None_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1276003_Multi?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1276003_Multi_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1233132_Multi?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1233132_Multi_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1152102_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1152102_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1152102_Navy_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/696693_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/696693_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/696693_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/521266_Multi?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/521266_Multi_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1214547_Gray_Combo?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1214547_Gray_Combo_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/15914_White_Logo?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/15914_White_Logo_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/15914_Multi/None_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1164678_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1164678_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1164678_Chocolate_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1164678_Navy_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1348568_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1348568_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1348568_Ivory_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1271879_Camo?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1271879_Camo_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/855097_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/855097_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/855097_Nude_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/977048_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/977048_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/977048_Taupe_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/696671_Multi?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/696671_Multi_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/599734_Pink?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/599734_Pink_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/358438_White?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/358438_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/358438_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1262068_Gray?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1262068_Khaki_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1262068_Gray_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1262068_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1138986_Multi?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1138986_Multi_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/619408_Featherstone?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/619408_Featherstone_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/619408_Corkboard_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/821223_Green_Combo?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/821223_Gray_Combo_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/821223_Green_Combo_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1206122_Tan?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1206122_Tan_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1206122_Gray_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1206122_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1206122_Khaki_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/975931_Multi?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/975931_Multi_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/176496_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/176496_Town_Taupe_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/176496_Barely_There_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/176496_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/176496_Barely_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/176496_Little_Color_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/176496_Soft_Beige_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/935917_Griffin?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/935917_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/935917_Griffin_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/935917_Ivory_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1262092_Sandstone?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1262092_Charcoal_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1262092_Sandstone_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1262092_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/906668_Coal?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/906668_Coal_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/906668_Brown_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1280642_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1280642_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1280642_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/498654_White?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/498654_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1033082_Black_Iris?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1033082_Black_Iris_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1033082_Khaki_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1206134_Black_Gray_Blue?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1206134_Black_Gray_Blue_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1270741_Tickled_Pink?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1270741_Tickled_Pink_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1270741_White_Pink_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1270741_Sulphur_Springs_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1270741_Capri_Breeze_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1101849_Multi?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1101849_Multi_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1126130_White?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1126130_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1126130_Marled_Assorted_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1126130_Navy_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.210.154.161:17010/media/fancybox/jquery.fancybox-1.3.4.pack.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://10.210.154.161:17010/", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1275963_Multi_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1169336_White?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1169336_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1169336_White_Assort_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1169336_Black_Assort_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1190682_Navy?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1190682_Navy_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1190682_Brown_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1119757_Multi?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1119757_Multi_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1169309_Tan?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1169309_Tan_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1169309_Gray_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1153757_Ivory_Combo?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1153757_Ivory_Combo_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1153757_Gray_Combo_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1153757_Black_Combo_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1173994_Black_Rose?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1173994_Black_Rose_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1173994_Flannel_Rose_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/619423_White?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/619423_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/619423_Featherstone_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1229011_Multi/None?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1229011_Multi/None_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1234048_Brown_Heather?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1234048_Brown_Heather_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1234048_Pink_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1234048_Blue_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1169296_Teal?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1169296_Teal_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1169296_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/598492_Brown?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/598492_Brown_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/598492_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1234037_White?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1234037_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/883160_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/883160_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/883160_Blue_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/598499_Brown?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/598499_Brown_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/350673_Brights?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/350673_Brights_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/324330_White?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/324330_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/324330_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1116467_Multi?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1116467_Multi_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1169334_White?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1169334_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1169334_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1089194_Multi?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1089194_Multi_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1224508_Blue?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1224508_Blue_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/927521_Steel_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/927521_Steel_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/927521_Bootstrap_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/909866_Vanilla_Icing?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/909866_Gingerbread_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/909866_Vanilla_Icing_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/909866_Berry_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1275963_Multi?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1153765_Orange?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1153765_Orange_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1153765_Blue_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1153765_Pink_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/906038_White?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/906038_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/906038_Assorted_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/455736_White?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/455736_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/455736_Brown_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/455736_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/455736_Navy_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1112130_Travel_Buff?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1112130_Travel_Buff_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1112130_Town_Taupe_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/288456_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/288456_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/288456_Sand_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1173773_White?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1173773_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1173784_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1173784_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/614815_Nude?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/614815_Nude_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/614815_Jet_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/889701_Natural?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/889701_Natural_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/889701_Denim_Blue_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/889701_Navy_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1169347_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1169347_Nearly_Nude_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1169347_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/320220_White?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/320220_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/320220_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/174036_Navy?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/174036_Navy_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/174036_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1011193_Ivory?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1011193_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1011193_Ivory_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1275989_Multi?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1275989_Multi_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/114414_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/114414_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/114414_New_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/114414_Brown_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/114414_Blue_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/114414_Dark_Beige_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/404012_Black?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/404012_Black_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/404012_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1152816_Nude?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1152816_Glacier_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1152816_Nude_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1271877_Camo?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1271877_Camo_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/7928_White?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/7928_White_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1228969_Multi/None?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1228969_Multi/None_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1224348_Lavender?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1224348_White_Rainbow_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1224348_Lavender_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1224348_Hot_Pink_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1151744_Gray_Yellow?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1151744_Gray_Yellow_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://kohls.tt.omtrdc.net/m2/kohls/mbox/standard?mboxHost=10.210.154.161&mboxSession=1364292838375-181938&mboxPC=1364292838375-181938.17_61&mboxPage=1364292957033-677627&screenHeight=768&screenWidth=1366&browserWidth=1366&browserHeight=588&browserTimeOffset=330&colorDepth=24&mboxCount=1&mbox=kohlscom_equity_bar&mboxId=0&mboxTime=1364312758049&mboxURL=http%3A%2F%2F10.210.154.161%3A17010%2Fsearch.jsp%3FN%3D0%26search%3Dsocks%26WS%3D96&mboxReferrer=http%3A%2F%2F10.210.154.161%3A17010%2Fsearch.jsp%3Fsearch%3Dsocks%26_requestid%3D17499&mboxVersion=40", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://kohls.tt.omtrdc.net/m2/kohls/mbox/standard?mboxHost=10.210.154.161&mboxSession=1364292838375-181938&mboxPC=1364292838375-181938.17_61&mboxPage=1364292957033-677627&screenHeight=768&screenWidth=1366&browserWidth=1366&browserHeight=588&browserTimeOffset=330&colorDepth=24&mboxCount=2&mbox=kohlscom_search_feature&mboxId=0&mboxTime=1364312759105&mboxURL=http%3A%2F%2F10.210.154.161%3A17010%2Fsearch.jsp%3FN%3D0%26search%3Dsocks%26WS%3D96&mboxReferrer=http%3A%2F%2F10.210.154.161%3A17010%2Fsearch.jsp%3Fsearch%3Dsocks%26_requestid%3D17499&mboxVersion=40", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.210.154.161:17010/mediaBUY_3_GET_1_50_PERCENTAGE", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", "REDIRECT=YES", "LOCATION=http://10.210.154.161:17010/", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1022157_Multi_Tonal?wid=372&hei=372&op_sharpen=1", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://media.kohls.com.edgesuite.net/is/image/kohls/1022157_Multi_Tonal_sw?wid=20&hei=20", "HEADER=Accept-Language:en-us,en;q=0.5", END_INLINE,
            "URL=http://10.210.154.161:17010/media/omniture/s_code.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://10.210.154.161:17010/omniture/sitecatalyst/omniture_akamai.jsp", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://ww9.kohls.com/b/ss/kohlsatgsitoracle/1/H.25/s35582834388703?AQB=1&ndh=1&t=26%2F2%2F2013%2015%3A46%3A1%202%20-330&ns=kohls&pageName=homepage&g=http%3A%2F%2F10.210.154.161%3A17010%2Fsearch.jsp%3FN%3D0%26search%3Dsocks%26WS%3D96&r=http%3A%2F%2F10.210.154.161%3A17010%2Fsearch.jsp%3Fsearch%3Dsocks%26_requestid%3D17499&events=event28&products=%3Bproductmerch3&c1=homepage&c2=homepage&c3=homepage&v3=external&c4=homepage&c7=homepage&v8=non-search&c9=homepage&v9=search%20results%3A%20page%20%201&c10=homepage&c11=homepage&c17=not%20logged%20in&v17=not%20logged%20in&c18=D%3Dv18&v18=05%3A15%20am&c19=D%3Dv19&v19=tuesday&c20=D%3Dv20&v20=week%20day&c22=2013-03-26&v22=Kohl%27s&v29=%3A2&c50=JpZ9RR0dQ4lXZ5WKWFLf23VY0gycv2w24gqvtYwL4MW87SwwTNRt!1504147867!1364292829822&s=1366x768&c=24&j=1.7&v=N&k=Y&bw=1366&bh=588&AQE=1", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=s_vi;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/foresee/foresee-trigger.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/javascript/search.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://10.210.154.161:17010/media/foresee/foresee-surveydef.js", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;fsr.a;", END_INLINE,
            "URL=http://10.210.154.161:17010/", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;", END_INLINE,
            "URL=http://ww9.kohls.com/b/ss/kohlsatgsitoracle/1/H.25/s34158502757523?AQB=1&ndh=1&t=26%2F2%2F2013%2015%3A46%3A46%202%20-330&ns=kohls&pageName=homepage&g=http%3A%2F%2F10.210.154.161%3A17010%2Fsearch.jsp%3FN%3D0%26search%3Dsocks%26WS%3D96&events=event28&products=%3Bproductmerch3&pe=lnk_e&pev1=http%3A%2F%2F10.210.154.161%3A17010%2Fsearch.jsp&s=1366x768&c=24&j=1.7&v=N&k=Y&bw=1366&bh=588&pid=homepage&pidt=1&oid=http%3A%2F%2F10.210.154.161%3A17010%2Fsearch.jsp%3FN%3D4294721321%26search%3Dsocks&ot=A&AQE=1", "HEADER=Accept-Language:en-us,en;q=0.5", "COOKIE=s_vi;", "PreSnapshot=webpage_1364293006096.png", "Snapshot=webpage_1364293010168.png", END_INLINE
    			);
    			ns_end_transaction("Pagination", NS_AUTO_STATUS);
				ns_page_think_time(0);
				//printf("After PaginationPage\n");
				PagesNavigated = PagesNavigated + 1;
  			}	
	 	} 
 	}
 	else
 	{
 		#ifdef NS_DEBUG_ON
		printf("\n ++++++++++ PerformPagination NO ++++++++++ \n");
		#endif 		 
 	}
	// Update this step details globally 
 	ProductSelectionMoveNext(2, PagesNavigated); //Current step number = 2, Pages naviagted in this step is = PagesNavigated
}
	
