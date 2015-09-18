/*-----------------------------------------------------------------------------
    Name:RefineSearch
    Recorded By: Priya
    Date of recording: 03/26/2013 03:47:42
    Flow details:
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"
#include "Util.c"

void RefineSearch()
{	
	int index =0;
	int MaxLoop = 0;
	int NavigateLoop = 0;
	int MaxDimensionLinks = 0;  
	int PagesNavigated = 0;
	int SimulateBackAction = NO; 
	int ZeroproductCount = 0;
	
    char Refinebuffer[1000]="";
    char LastRefinedUrl[1000]="";
    char Url_buf[2000] = "";
    char SessionConf_buf[64] = "";
    char SearchKeyword_buf[64] = "";
    
    sprintf(SessionConf_buf,"%s",ns_eval_string("{DynSessionConfSP}"));
    sprintf(SearchKeyword_buf,"%s",ns_eval_string("{SearchKeywordFP}"));
    sprintf(Url_buf,"search.jsp?_dyncharset=UTF-8&_dynSessConf=%s&search=%s&_D%%3Asearch=+&%%2Fcom%%2Fkohls%%2Fsearch%%2Fformhandler%%2FSearchFormHandler.queryBean.requestType=search&_D%%3A%%2Fcom%%2Fkohls%%2Fsearch%%2Fformhandler%%2FSearchFormHandler.queryBean.requestType=+&submit-search=&_D%%3Asubmit-search=+&_DARGS=%%2Fcatalog%%2Fsearch%%2Fsearch.jsp",SessionConf_buf,SearchKeyword_buf);
    ns_save_string(Url_buf,"SearchKeywordDP"); 
	int MaxNavigatePages = ns_get_int_val("nsMaxNavigateInNextStep"); // Max number of pages I can navigate here
	//int DoRefineSearch = ns_get_random_number_int(0, 5); // Randomize if user does a refine search
	int DoRefineSearch = ns_get_random_number_int(0, 2); // Randomize if user does a refine search
      
    // Save the first URL in case you need to simulate GOBACK action 
	sprintf(LastRefinedUrl,"%s",ns_eval_string("{SearchKeywordDP}"));
	
	#ifdef NS_DEBUG_ON
    printf("@@@@@@@@@@@@@@@@The value of  is last refine url @@@@@@@@@@@@@\n= [%s]\n",LastRefinedUrl);
    #endif
    
	if(DoRefineSearch != NO) // User is doing refine search
	{			
		ZeroproductCount = ns_get_int_val("ZeroProductsCountSP_count");
		if(ZeroproductCount > 0)
		{		
    	 // Zero products.. skip this
    	 return;
		}
    							
		#ifdef NS_DEBUG_ON
		printf("\n ++++++++++ RefineSearch YES ++++++++++ \n");
	    #endif
	        MaxDimensionLinks = ns_get_int_val("RefinementUrlSPCount_count"); 
	        
	        if(MaxDimensionLinks==0)
	        {
				#ifdef NS_DEBUG_ON
				printf("\n ++++++++++ RefineSearch - Exit Session ++++++++++ \n");
	    		#endif
	        	ns_exit_session();
	        }
	        MaxLoop = GetMin(MaxNavigatePages, MaxDimensionLinks);
	 	    NavigateLoop = ns_get_random_number_int(1, MaxLoop); // Randomize the loops
	 	
	 	   #ifdef NS_DEBUG_ON
	        printf("\n MaxDimensionLinks is [%d] \n", MaxDimensionLinks);
		    printf("\n MaxNavigatePages  is [%d] \n", MaxNavigatePages);
		    printf("\n MaxLoop   is [%d] \n", MaxLoop);
		    printf("\n NavigateLoop   is [%d] \n", NavigateLoop);
            #endif

		for(index = 0; index < NavigateLoop; index++)
		{
			// CALCULATE THE REFINEMENT URL - START
			if(SimulateBackAction == NO )
			{
				sprintf(Refinebuffer,"%s", ns_eval_string("{RefinementUrlSP}"));
				ns_save_string(Refinebuffer,"RefinementUrl");
								
				if(strcmp(Refinebuffer, "") == 0)
				{
					// If the url is empty, skip this cycle.
					//index = index - 1;
   					//continue;
   					 ns_exit_session();
				}
			}
			else
			{
				// Simulating GOBACK action
				#ifdef NS_DEBUG_ON
				printf("\n%%%%%%%%%%%%%%%%INSIDE ELSE CONDITION OF FOR LOOP%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
				#endif
				ns_save_string(LastRefinedUrl,"RefinementUrl"); // Got the last URL used..					
				#ifdef NS_DEBUG_ON
   				printf(" +++++ Simulating GOBACK action to [%s] \n", LastRefinedUrl);
				#endif
			}
			// CALCULATE THE REFINEMENT URL - END
			
			// Do the Refinement		   	  
	    	ns_start_transaction("Refinement");    
	    	ns_web_url ("RefinementPage",
	        	//"URL=http://10.210.154.161:17010/search.jsp?N=4294721321&search=socks",
	        	"URL=http://www-sf.kohlsecommerce.com/catalog/silver-on-the-rocks-jewelry.jsp",
	      
	        ///	"URL=http://www-sf.kohlsecommerce.com/search/home-decor.jsp?CN=4294720830&N=4294720830&search=ninjago",
	        	//"URL=http://www-sf.kohlsecommerce.com/search/black.jsp?CN=4294905288&amp;N=4294905288&amp;search=SUV",
	        	"HEADER=Accept-Language:en-us,en;q=0.5",
	        	"COOKIE=JSESSIONID;mbox;s_sess;s_pers;fsr.s;",
	        	"PreSnapshot=webpage_1364293010188.png",
	        	"Snapshot=webpage_1364293021294.png",
	        
		INLINE_URLS,
	
		"URL=http://www-sf.kohlsecommerce.com/media/foresee/foresee-alive.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/cart.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery-1.7.2.min.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/global.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/myaccount.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery.validate.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/jquery.validate_product.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/UI_validation.js", END_INLINE,
"URL=http://www-sf.kohlsecommerce.com/media/javascript/modal_validation.js", END_INLINE,
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
	    	
	    	// Refinement can bringup a page that is
	    	// 1> Product Matrix Page - Same as what is to beign with (RefinementPage) 
	    	// 2> Product Details Page - Handled below
	    	// 3> No Products found - This case is NA
	    	
	    	if(IsProductDetailPage() == YES) // Case 2..
	    	{
      			ns_end_transaction_as("Refinement", NS_AUTO_STATUS,"ViewProductDetail");
      			
      			#ifdef NS_DEBUG_ON
   				printf(" ++++ PDP Page Loaded. [%s]\n", ns_eval_string("{RefinementUrl}"));
      			#endif
      			
      			// Trigger the GoBack action ...
      			SimulateBackAction = YES;
			#ifdef NS_DEBUG_ON
      			printf("\n@@@@@@@@@@@@@The value of SBA is [%d]",SimulateBackAction);
			#endif

      			if(index <= NavigateLoop)
      			{
      				// If this is last loop, increase the loop by one to accomidate the Go Back action
      				NavigateLoop = NavigateLoop + 1; 
      			}
	    	}
	    	else
	    	{
	    		ns_end_transaction("Refinement", NS_AUTO_STATUS);
				#ifdef NS_DEBUG_ON
   				printf(" ++++ Refinement Page Loaded. [%s]\n", ns_eval_string("{RefinementUrl}"));
				#endif
				
				// Save the last RefinementPage URL - need for GoBack simulation..
				sprintf(LastRefinedUrl,"%s", ns_eval_string("{RefinementUrl}"));
				SimulateBackAction = NO; 
	    	}
	    	
	    	ns_page_think_time(0);
		    // Update the number of pages we navigated here
		    PagesNavigated = index + 1; //index is 0 based
		}	
	    	
 	}
 	else
 	{
		#ifdef NS_DEBUG_ON
 		printf("\n ++++++++++ RefineSearch NO ++++++++++ \n");
		#endif
 	}
 	
	// Update this step deatils globally 
 	ProductSelectionMoveNext(1, PagesNavigated); //Current step number = 1, Pages naviagted in this step is = PagesNavigated
}
