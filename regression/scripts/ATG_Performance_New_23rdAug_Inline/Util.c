/*-----------------------------------------------------------------------------
    Name:Util.c
    Written By: Madhu
    Date : 03/28/2013 07:47:42
    Modification History:
-----------------------------------------------------------------------------*/
#ifndef _UTIL_FILE
#define _UTIL_FILE


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

#define YES 1
#define NO  0

static int GetMin(int number1, int number2)
{
	if(number1 < number2)
	{
		return number1;
	}
	return number2;
}

static void ProductSelectionMoveNext(int currentStepNumber, int PagesNavigatedInCurrentStep )
{
	#ifdef NS_DEBUG_ON
	printf("\n ProductSelectionMoveNext (currentStepNumber= %d, PagesNavigatedInCurrentStep= %d) \n",currentStepNumber, PagesNavigatedInCurrentStep );
	#endif
	//TODO: We will revisit this logic while tuning..
	
	int TotalNoOfSteps = 4; // Refine, Pagination, Sort, View..
	int MaxNavigateInNextStep = 0;
	int PendingPagesToNavigate = ns_get_int_val("nsPendingPagesToNavigate");

    PendingPagesToNavigate = PendingPagesToNavigate - PagesNavigatedInCurrentStep;
    if(PendingPagesToNavigate > 0 && currentStepNumber < TotalNoOfSteps)
    {
		MaxNavigateInNextStep = PendingPagesToNavigate/(TotalNoOfSteps - currentStepNumber); // NOTE : Will revisit this again
		// MaxNavigateInNextStep = PendingPagesToNavigate/4; 
    }
	
	ns_set_int_val("nsMaxNavigateInNextStep", MaxNavigateInNextStep);  
	ns_set_int_val("nsPendingPagesToNavigate", PendingPagesToNavigate);  
}

static int IsProductDetailPage()
{
	int returnValue = NO;
    char *productdetail;
    productdetail = ns_eval_string("{ProductDetailSP}");
    char *addtobag;
    addtobag = ns_eval_string("{AddToBagSP}");
    // PDP page contains both "Product Details" and "addtobag"
    if ( (strlen(productdetail) == 0) && ( strlen(addtobag) == 0) )
    {
    	// Both validation strings are not found, hence this is not PDP
    	#ifdef NS_DEBUG_ON
    	printf("\n****************INSIDE IF *********************\n");
	    #endif
      	returnValue = NO;   
    }
    else
    {
		
   		//printf(" This is a Product detail Page \n [%s] \n [%s]. \n", ns_eval_string("{ProductDetailSP}"), ns_eval_string("{AddToBagSP}"));
   	   #ifdef NS_DEBUG_ON
   		printf("\n****************INSIDE ELSE CONDITION*****************\n");
		#endif
   		returnValue = YES;
    }
    return returnValue;
}

static void Fill_AddToBag()
{

  char CollectionID_buf[256 + 1] = "";
  char AddToBagSkuId_buf[256 + 1] = "";
  char quantity_buf[64 + 1]="";
  
  #ifdef NS_DEBUG_ON
  printf("\n#######the value of item check is [%s]##############\n",ns_eval_string("{ItemTypeCheckSP}"));
  printf("\n@@@@@@@@@@@@the value of block is [%s]@@@@@@@@@@@@\n",ns_eval_string("{MI_FormBlockSP}"));
  #endif
  if(!strcmp(ns_eval_string("{ItemTypeCheckSP}"),"collection-content"))
  {
  	#ifdef NS_DEBUG_ON
  	printf("\n @@@@@@@@@@@@@@@@@INSIDE IF CONDITION@@@@@@@@@@@@@@@@@@@@@\n");
  	#endif
    sprintf(AddToBagSkuId_buf,"/atg/commerce/order/purchase/CartModifierFormHandler.catalogRefIds=%s",ns_eval_string("{AddToBagSkuId}"));
    sprintf(CollectionID_buf,"/atg/commerce/order/purchase/CartModifierFormHandler.collectionId=%s",ns_eval_string("{CollectionIDSP}"));
    strcpy(quantity_buf, "add_cart_quantity=1");
    ns_set_form_body("MI_FormBlockSP", "AddToBagDP", 1, 3, AddToBagSkuId_buf,CollectionID_buf,quantity_buf);
  }
  
  else                                                                                                                                    
  {
  	#ifdef NS_DEBUG_ON
  	printf("\n @@@@@@@@@@@@@@@@@INSIDE ELSE CONDITION@@@@@@@@@@@@@@@@@@@@@@@@\n");
  	#endif
    sprintf(AddToBagSkuId_buf,"/atg/commerce/order/purchase/CartModifierFormHandler.catalogRefIds=%s",ns_eval_string("{AddToBagSkuId}"));
     strcpy(quantity_buf, "add_cart_quantity=1");
     ns_set_form_body("SI_FormBlockSP", "AddToBagDP", 1, 2, AddToBagSkuId_buf,quantity_buf);
  }
  
}
static void Fill_UnReg_PaymentDetailBody()
{

  char CardType_buf[1024 + 1]="";
  char CardHolderName_buf[1024 + 1]="";
  char CardNumber_buf[1024 + 1]="";
  char ExpiryMonth_buf[1024 + 1]="";
  char ExpiryYear_buf[1024 + 1]="";
  char CardId_buf[1024 + 1]="";
  char creditcard[]="isCreditCardRequired=__EXCLUDE__";
  char add_gift_attrx[]="add_gift_card.x=__EXCLUDE__";
  char add_gift_attry[]="add_gift_card.y=__EXCLUDE__";
  char add_kohls_attrx[]="add_kohls_cash.x=__EXCLUDE__";
  char add_kohls_attry[]="add_kohls_cash.y=__EXCLUDE__";
  char add_promo_attrx[]="add_promo_code.x=__EXCLUDE__";
  char add_promo_attry[]="add_promo_code.y=__EXCLUDE__";
  sprintf(CardType_buf, "cardtype=%s", ns_eval_string("{CardTypeFP}"));
  sprintf(CardHolderName_buf, "cardname=%s", ns_eval_string("{CardNameIdFP}"));
  sprintf(CardNumber_buf, "cardnum=%s", ns_eval_string("{CardNumFP}"));
  sprintf(ExpiryMonth_buf, "cardexp_month=%s", ns_eval_string("{CardExpMonthFP}"));
  sprintf(ExpiryYear_buf, "cardexp_year=%s", ns_eval_string("{CardExpYearFP}"));
  sprintf(CardId_buf, "cardcvv=%s", ns_eval_string("{CardCVVFP}"));
  ns_set_form_body("UnReg_PaymentFormBlockSP", "UnReg_PaymentInfoDP", 1, 13, CardType_buf, CardHolderName_buf, CardNumber_buf, ExpiryMonth_buf, ExpiryYear_buf, CardId_buf,creditcard,add_gift_attrx,add_gift_attry,add_kohls_attrx,add_kohls_attry,add_promo_attrx,add_promo_attry);
}
static void Fill_Reg_PaymentDetailBody()
{
	//char creditcard[]="isCreditCardRequired=__EXCLUDE__";
	char rg_incardtype[]="cardtype-asd=visa - 0007";
    char rg_nickname[]="/atg/commerce/order/purchase/KLSPaymentInfoFormHandler.creditCardNickName=visa - 0007";
    char add_gift_attrx[]="add_gift_card.x=__EXCLUDE__";
    char add_gift_attry[]="add_gift_card.y=__EXCLUDE__";
    char add_kohls_attrx[]="add_kohls_cash.x=__EXCLUDE__";
    char add_kohls_attry[]="add_kohls_cash.y=__EXCLUDE__";
    char add_promo_attrx[]="add_promo_code.x=__EXCLUDE__";
    char add_promo_attry[]="add_promo_code.y=__EXCLUDE__";
    char CardId_buf[1024 + 1]="";
    sprintf(CardId_buf, "cardcvv=%s", ns_eval_string("{CardCVVFP}"));
    ns_set_form_body("Reg_PaymentFormBlockSP", "Reg_PaymentInfoDP", 1, 9,rg_incardtype,rg_nickname,add_gift_attrx,add_gift_attry,add_kohls_attrx,add_kohls_attry,add_promo_attrx,add_promo_attry,CardId_buf );
}


static void Fill_CheckOutBody()
{
    
    ns_set_form_body("CheckOutFormBlockSP", "CheckOutDP", 1, 0 );
}

static void Fill_EditItemBody()
{
    char editquantity_buf[56]="";
    sprintf(editquantity_buf, "update_cart_quantity=1");
    ns_set_form_body("EditItemFormBlockSP", "EditItemDP", 1, 1,editquantity_buf );
}

static void fill_SubmitOrderBody()
{
	char submit_attrx[]="submit.x=__EXCLUDE__";
    char submit_attry[]="submit.y=__EXCLUDE__";
	ns_set_form_body("SubmitOrderFormBlockSP", "SubmitOrderDP",1,2,submit_attrx,submit_attry);
}


static void Fill_ATG_SignInBody()
{
	
    //printf("$$$$$$$$$$4The value of FP is [%s]$$$$$$$",ns_eval_string("{UserIdFP}"));
    //printf("\n#######the value of Pwd is [%s]##############\n",ns_eval_string("{PasswordFP}"));
    char csi_buf[256 + 1]=""; 
    char csipwd_buf[128 + 1]="";
    char reg_checkout[]="kohls_checkout_registered=";
    
    sprintf(csi_buf, "LOGIN<>userid=%s", ns_eval_string("{UserIdFP}"));
    sprintf(csipwd_buf, "LOGIN<>passwordLogin=%s", ns_eval_string("{PasswordFP}"));
    ns_set_form_body("ATG_SignInFormBlockSP", "ATG_SignInDP",1,3,csi_buf,csipwd_buf,reg_checkout);
}

#endif

