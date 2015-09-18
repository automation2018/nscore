#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

// #include "/home/netstorm/work/RedBox/RedBoxLibs/ns_use_once_var.c"


#define MAX_REQ_BUF_SIZE 4096

#define PURCHASE "%22purchase%22+%3a+%7b+%0d%0a++++++++++++%22Items%22+%3a+%5b"
#define RENT "%22rental%22+%3a+%7b+%0d%0a++++++++++++%22Items%22+%3a+%5b"

#define DVD_PCT 90
#define BLURAY_PCT 9
#define GAME_PCT 1

#define PURCHASE_BLOCK 0
#define RENT_BLOCK 1

#define ITEM_BLOCK_BEFORE_BAR_CODE "%20%7b+%0d%0a++++++++++++++++%22Barcode%22+%3a+%22"

#define ITEM_TAX_RATE 8.2500

#define MOVIE_DVD 1
#define MOVIE_BLUE_RAY 2
#define GAME 3


#define PURCHASE_MOVIE_DVD_UNIT_PRICE 5// To Purchase DVD

#define RENT_MOVIE_DVD_UNIT_PRICE 1 // $1
#define RENT_MOVIE_BLU_RAY_UNIT_PRICE 1.5 // $1.5
#define RENT_GAME_UNIT_PRICE 2 // $2

#define PURCHASE_ITEM_BLOCK_AFTER_BAR_CODE_MOVIE_DVD "%22%2c%0d%0a++++++++++++++++%22VendStatus%22+%3a+%22Vended%22%2c%0d%0a++++++++++++++++%22Prices%22+%3a+%7b+%0d%0a++++++++++++++++++++%22pricesetid%22+%3a+3%2c%0d%0a++++++++++++++++%22purchase%22+%3a+5%2c%0d%0a++++++++++++++++++++%22expirationprice%22+%3a+1%0d%0a++++++++++++++++%7d%0d%0a++++++++++++++++%0d%0a++++++++++++%7d+%5d%2c%0d%0a++++++++++++%22Totals%22+%3a+%7b+%0d%0a++++++++++++++++%22TaxRate%22+%3a+"

#define PURCHASE_ITEM_BLOCK_AFTER_PurchaseTaxRateVar "%2c%0d%0a++++++++++++++++%22SubTotal%22+%3a+"
#define PURCHASE_ITEM_BLOCK_AFTER_PurchaseSubTotalVar "%2c%0d%0a++++++++++++++++%22TaxAmount%22+%3a+%22"
#define PURCHASE_ITEM_BLOCK_AFTER_PurchaseTaxAmountVar "%22%2c%0d%0a++++++++++++++++%22GrandTotal%22+%3a+"
#define PURCHASE_ITEM_BLOCK_AFTER_PurchaseGrandTotalVar "%2c%0d%0a++++++++++++++++%22DiscountedSubtotal%22+%3a+"
#define PURCHASE_ITEM_BLOCK_AFTER_PurchaseDiscountedSubtotalVar "%0d%0a++++++++++++%7d%0d%0a++++++++%7d%2c%0d%0a%0d%0a++++++++"

#define RENT_ITEM_BLOCK_AFTER_BAR_CODE_MOVIE_DVD "%22%2c%0d%0a%09%09%22VendStatus%22+%3a+%22Vended%22%2c%0d%0a++++++++++++++++%22ProductFamily%22+%3a+%22Movies%22%2c%0d%0a++++++++++++++++%22ProductType%22+%3a+%22DVD%22%2c%0d%0a++++++++++++++++%22Prices%22+%3a+%7b+%0d%0a++++++++++++++++++++%22pricesetid%22+%3a+3%2c%0d%0a++++++++++++++++%22extranight%22+%3a+1%2c%0d%0a++++++++++++++++++++%22expirationprice%22+%3a+1%2c%0d%0a++++++++++++++++++++%22initialnight%22+%3a+1%2c%0d%0a++++++++++++++++++++%22nonreturn%22+%3a+24%2c%0d%0a++++++++++++++++++++%22nonreturndays%22+%3a+24%0d%0a++++++++++++++++%7d%0d%0a++++++++++++%7d"

#define RENT_ITEM_BLOCK_AFTER_BAR_CODE_BLUE_RAY "%22%2c%0d%0a%09%09%22VendStatus%22+%3a+%22Vended%22%2c%0d%0a++++++++++++++++%22ProductFamily%22+%3a+%22Movies%22%2c%0d%0a++++++++++++++++%22ProductType%22+%3a+%22Blu-ray%22%2c%0d%0a++++++++++++++++%22Prices%22+%3a+%7b+%0d%0a++++++++++++++++++++%22pricesetid%22+%3a+3%2c%0d%0a++++++++++++++++%22extranight%22+%3a+1.5%2c%0d%0a++++++++++++++++++++%22expirationprice%22+%3a+1.5%2c%0d%0a++++++++++++++++++++%22initialnight%22+%3a+1.5%2c%0d%0a++++++++++++++++++++%22nonreturn%22+%3a+33%2c%0d%0a++++++++++++++++++++%22nonreturndays%22+%3a+22%0d%0a++++++++++++++++%7d%0d%0a++++++++++++%7d"

#define RENT_ITEM_BLOCK_BEFORE_PRODUCT_GAME "%22%2c%0d%0a%09%09%22VendStatus%22+%3a+%22Vended%22%2c%0d%0a++++++++++++++++%22ProductFamily%22+%3a+%22Games%22%2c%0d%0a++++++++++++++++%22ProductType%22+%3a+%22"

#define RENT_ITEM_BLOCK_AFTER_PRODUCT_GAME "%22%2c%0d%0a++++++++++++++++%22Prices%22+%3a+%7b+%0d%0a++++++++++++++++++++%22pricesetid%22+%3a+3%2c%0d%0a++++++++++++++++%22extranight%22+%3a+2%2c%0d%0a++++++++++++++++++++%22expirationprice%22+%3a+1%2c%0d%0a++++++++++++++++++++%22initialnight%22+%3a+2%2c%0d%0a++++++++++++++++++++%22nonreturn%22+%3a+48%2c%0d%0a++++++++++++++++++++%22nonreturndays%22+%3a+24%0d%0a++++++++++++++++%7d%0d%0a++++++++++++%7d"


static char* create_uniq_string() {

  static unsigned int count, count1;
  static char uniq_str[50];

  //sprintf(uniq_str, "A%06dA-%04X-%04X-%04X-%012X", count, count, count, ns_get_nvmid(), (unsigned)time(NULL));
  sprintf(uniq_str, "A%7.7d-%4.4X-%4.4X-%4.4X-%12.12X", count1, count, count, ns_get_nvmid(), (unsigned)time(NULL));
  count1++;
  count1 = count1%10000000;
  count++;
  count = count%10000;
  return uniq_str;
}

static void set_msg_id() {
  char *refnum = create_uniq_string();
  #ifdef NS_DEBUG_ON
  printf("%s: ==========>%s<\n", (char*)__FUNCTION__, refnum);
  #endif
  ns_save_string(refnum, "MessageIdVar");
}

static int set_item_block(char *barcode_local_buf, char *item_block_buf, int type, char block_type)
{
int item_block_buf_len = 0;
    char *item_block_after_bar_code = NULL;
    char temp_buf[2048];
    int item_block_after_bar_len = 0;
    char PurchaseTaxRateVarArr[8]; 
    char PurchaseSubTotalVarArr[8]; 
    char PurchaseTaxAmountVarArr[8]; 
    char PurchaseGrandTotalVarArr[8];
    char PurchaseDiscountedSubtotalVarArr[8];
    char Barcode_str[16];
    char Product_str[16];
    char *block_type_ptr = NULL;
    
  if(block_type == PURCHASE_BLOCK) {
   ns_advance_param("BarcodeDVDVar");
   strcpy(Barcode_str, ns_eval_string("{BarcodeDVDVar}")); 

   strcpy(PurchaseTaxRateVarArr, ns_eval_string("{PurchaseTaxRateVar}"));
   strcpy(PurchaseSubTotalVarArr, ns_eval_string("{PurchaseSubTotalVar}"));
   strcpy(PurchaseTaxAmountVarArr, ns_eval_string("{PurchaseTaxAmountVar}"));
   strcpy(PurchaseGrandTotalVarArr, ns_eval_string("{PurchaseGrandTotalVar}"));
   strcpy(PurchaseDiscountedSubtotalVarArr, ns_eval_string("{PurchaseDiscountedSubtotalVar}")); 
  
  item_block_after_bar_len += sprintf(temp_buf, "%s%s%s%s%s%s%s%s%s%s%s",
                               PURCHASE_ITEM_BLOCK_AFTER_BAR_CODE_MOVIE_DVD,
                               PurchaseTaxRateVarArr, 
                               PURCHASE_ITEM_BLOCK_AFTER_PurchaseTaxRateVar,
                               PurchaseSubTotalVarArr,
                               PURCHASE_ITEM_BLOCK_AFTER_PurchaseSubTotalVar,
                               PurchaseTaxAmountVarArr,
                               PURCHASE_ITEM_BLOCK_AFTER_PurchaseTaxAmountVar,
                               PurchaseGrandTotalVarArr,
                               PURCHASE_ITEM_BLOCK_AFTER_PurchaseGrandTotalVar,
                               PurchaseDiscountedSubtotalVarArr,
                               PURCHASE_ITEM_BLOCK_AFTER_PurchaseDiscountedSubtotalVar);

    item_block_after_bar_code = temp_buf; 
    block_type_ptr = PURCHASE;
  } else if (block_type == RENT_BLOCK){ // Rent
    block_type_ptr = RENT;

    if(type == MOVIE_DVD) { 
        ns_advance_param("BarcodeDVDVar"); 
        strcpy(Barcode_str, ns_eval_string("{BarcodeDVDVar}"));
        item_block_after_bar_code = RENT_ITEM_BLOCK_AFTER_BAR_CODE_MOVIE_DVD;
    } else  if(type == MOVIE_BLUE_RAY) {
        ns_advance_param("BarcodeBlurayVar");
        strcpy(Barcode_str, ns_eval_string("{BarcodeBlurayVar}"));
        item_block_after_bar_code = RENT_ITEM_BLOCK_AFTER_BAR_CODE_BLUE_RAY;
    } else  if(type == GAME) {
         ns_advance_param("GameProductType");
         strcpy(Product_str, ns_eval_string("{GameProductType}"));
         strcpy(Barcode_str, ns_eval_string("{BarcodeGameVar}"));
         item_block_after_bar_len += sprintf(temp_buf, "%s%s%s", RENT_ITEM_BLOCK_BEFORE_PRODUCT_GAME,Product_str,RENT_ITEM_BLOCK_AFTER_PRODUCT_GAME);
         item_block_after_bar_code = temp_buf;
    } else {
	#ifdef NS_DEBUG_ON
        fprintf(stderr, "%s : Invalid type = %d\n", (char*)__FUNCTION__, type);
	#endif
        return -1;
    }
  
  } else {
	#ifdef NS_DEBUG_ON
      	fprintf(stderr, "%s : Block type neither Purchase nor Rent", (char*)__FUNCTION__);
	#endif	
	return -1;
  }

   if((type == MOVIE_DVD && block_type == PURCHASE_BLOCK) || (block_type == RENT_BLOCK)) {
   // Append ItemBlock
   if(strlen(item_block_buf) == 0) // First
    item_block_buf_len += sprintf(item_block_buf, "%s%s%s%s%s",
                                                  item_block_buf,
						  block_type_ptr,
                                                  ITEM_BLOCK_BEFORE_BAR_CODE,
                                                  Barcode_str, 
                                                  item_block_after_bar_code);
    else // 2nd and other should have comma (+) following be space (%2c)
      item_block_buf_len += sprintf(item_block_buf, "%s+%%2c%s%s%s",
                                                  item_block_buf,
                                                  ITEM_BLOCK_BEFORE_BAR_CODE,
                                                  Barcode_str, 
                                                  item_block_after_bar_code);
   }

   return 0;
}
  
  // Create ItemBlock for BlueRay
/* Note : We can not use ns_set_int_val to save double/float value;
 * To save double/float value do following
 * 1- copy that value in any buffer
 * 2- save using ns_save_string
 */
static void set_data_for_rent(int max_item_count) {
  int i;
  char item_block_buf[MAX_REQ_BUF_SIZE + 1];
  char barcode_local_buf[MAX_REQ_BUF_SIZE + 1];
  char temp_buf[128];  // to save double/float value
  
  double subtotal;
  double tax_amount;
  double grand_total;
  double discounted_subtotal;
  
  int numDVD=0,numBlueRay=0,numGame=0;
  int total_items, item_selected;
  
   int total_item_pct = ns_get_random_number_int(1,100);
   if (total_item_pct <= RENT_ONEITEM )
      total_items = 1;
    else
      total_items = 2;

  item_selected = 0;
  int num = ns_get_random_number_int(1,100);

  if( num <= DVD_PCT)
  {
    numDVD = ns_get_random_number_int(1, total_items);
    item_selected += numDVD;
  }
  else if ( num > DVD_PCT && num <= (DVD_PCT + BLURAY_PCT))
  {
    numBlueRay = ns_get_random_number_int(1, total_items);
    item_selected += numBlueRay;
  }
  else if ( num > (DVD_PCT + BLURAY_PCT) && num <= (DVD_PCT + BLURAY_PCT + GAME_PCT))
  {
    numGame = ns_get_random_number_int(1, total_items);
    item_selected += numGame;
  }
  if(item_selected < total_items)
  {
    //To get number of Bluray to be rented based on number of DVD and BlueRay
    numBlueRay = total_items - item_selected;
   item_selected += numBlueRay;
  }
 
#ifdef NS_DEBUG_ON
  printf("Max item = %d, numPct = %d, item_selected = %d, Total Item Pct = %d, Total items for rent = %d, numDVD = %d, numBlueRay = %d, numGame = %d\n", max_item_count, num, item_selected, total_item_pct, total_items, numDVD, numBlueRay, numGame );
#endif

  ns_set_int_val("RentalItemTotalVar", total_items);
 
  barcode_local_buf[0] = '\0';
  item_block_buf[0] = '\0';

  // Create ItemBlock for DVD if any
  for(i = 0; i < numDVD ; i++) {
    set_item_block(barcode_local_buf, item_block_buf, MOVIE_DVD, RENT_BLOCK);
  }
  
  // Create ItemBlock for BlueRay
  for(i = 0; i < numBlueRay ; i++) {
    set_item_block(barcode_local_buf, item_block_buf, MOVIE_BLUE_RAY, RENT_BLOCK);
  }
  
  // Create ItemBlock for Game
  for(i = 0; i < numGame ; i++) {
    set_item_block(barcode_local_buf, item_block_buf, GAME, RENT_BLOCK);
  }
  
  ns_save_string(barcode_local_buf, "RentedBarcodeListVar");

  ns_save_string(item_block_buf, "RentalItemBlockVar");

  subtotal = numDVD * RENT_MOVIE_DVD_UNIT_PRICE +  numBlueRay * RENT_MOVIE_BLU_RAY_UNIT_PRICE +  numGame * RENT_GAME_UNIT_PRICE  ;

 char promo_code[64];
 strcpy(promo_code, ns_eval_string("{DiscountValue}"));
 double promo_code_double = atof(promo_code);
 if(promo_code_double != 0){
     tax_amount = ((subtotal - promo_code_double) * ITEM_TAX_RATE )/100.00;
     if(tax_amount < 0){tax_amount = 0;}
     grand_total = (subtotal - promo_code_double) + tax_amount;
     if(grand_total < 0){grand_total = 0;}
     discounted_subtotal = subtotal - promo_code_double;
     if(discounted_subtotal < 0){discounted_subtotal = 0;}
 }
 else{ 

   tax_amount = (subtotal * ITEM_TAX_RATE )/100.00;
   grand_total = subtotal + tax_amount;
   discounted_subtotal = subtotal;
 }

  
  // Fill variable for Total counts ---
  
  // Save TaxRate
  sprintf(temp_buf, "%.4lf", ITEM_TAX_RATE);
  ns_save_string(temp_buf, "RentalTaxRateVar");

  // Save SubTotal
  sprintf(temp_buf, "%.4lf", subtotal);
  ns_save_string(temp_buf, "RentalSubTotalVar");
  
  // Save TaxAmount
  sprintf(temp_buf, "%.5lf", tax_amount);
  ns_save_string(temp_buf, "RentalTaxAmountVar");
  
  // Save GrandTotal
  sprintf(temp_buf, "%.5lf", grand_total);
  ns_save_string(temp_buf, "RentalGrandTotalVar");

  // Save DiscountedSubtotal
  sprintf(temp_buf, "%.4lf", discounted_subtotal);
  ns_save_string(temp_buf, "RentalDiscountedSubtotalVar");
  
}

static void set_data_for_purchase(int total_items) {
  int i;
  char item_block_buf[MAX_REQ_BUF_SIZE + 1];
  char barcode_local_buf[MAX_REQ_BUF_SIZE + 1];
  char temp_buf[128];  // to save double/float value

  double  subtotal;
  double tax_amount;
  double grand_total;
  double discounted_subtotal;
  
  int numPurchase;
  
  numPurchase = ns_get_random_number_int(1, total_items);
 
  #ifdef NS_DEBUG_ON 
  printf("%s Called\n", (char*)__FUNCTION__);
  printf("numPurchase = %d\n", numPurchase);
  #endif
  
  ns_set_int_val("PurchaseItemTotalVar", numPurchase);
  
// Total block values
  subtotal = numPurchase * PURCHASE_MOVIE_DVD_UNIT_PRICE;
  tax_amount = (subtotal * ITEM_TAX_RATE)/100.00;
  grand_total = subtotal + tax_amount;
  discounted_subtotal = subtotal;

  
  // Fill variable for Total counts ---
  
  // Save TaxRate
  sprintf(temp_buf, "%.4lf", ITEM_TAX_RATE);
  ns_save_string(temp_buf, "PurchaseTaxRateVar");

  // Save SubTotal
  ns_set_int_val("PurchaseSubTotalVar", subtotal);
  
  // Save TaxAmount
  sprintf(temp_buf, "%.4lf", tax_amount);
  ns_save_string(temp_buf, "PurchaseTaxAmountVar");
  
  // Save GrandTotal
  sprintf(temp_buf, "%.4lf", grand_total);
  ns_save_string(temp_buf, "PurchaseGrandTotalVar");

  // Save DiscountedSubtotal
  sprintf(temp_buf, "%.4lf", discounted_subtotal);
  ns_save_string(temp_buf, "PurchaseDiscountedSubtotalVar");
  
  barcode_local_buf[0] = '\0';
  item_block_buf[0] = '\0';
  
  // Create ItemBlock
  for(i = 0; i < numPurchase; i++) {
   set_item_block(barcode_local_buf, item_block_buf, MOVIE_DVD, PURCHASE_BLOCK);
  }

  // Save ItemBlock list
  ns_save_string(item_block_buf, "PurchaseItemBlockVar");
}


static void set_data_rent_service() { 

  // Decide for Rent only or Rent and purchase
  int num = ns_get_random_number_int(1,100);
  if( num <= RENT_ONLY) { 
    set_data_for_rent(2);
  } else {
  #ifdef NS_DEBUG_ON
    printf("%s: Purchase block selected\n", (char*)__FUNCTION__);
  #endif
    num = ns_get_random_number_int(1,100);
    if ( num <= RENT_PURCHASE_PUR_ONLY) {
      set_data_for_purchase(1);
    }
    else{ 
      set_data_for_purchase(1);
      set_data_for_rent(1);
    }
  } 
}

/* Check return value of this function */
/* if 0 = then return nxt page  else  return -1*/
static int ErrorCheck(char* pageName)
{
  char KioskId[64];
  char MessageId[64];
  int err_count;

  err_count = (ns_get_int_val("ErrorCount")); 
  if(err_count <= 0)
  {
    return 0;
  }
  else 
  {
    #ifdef NS_DEBUG_ON
    fprintf(stderr, "Error count = %d",err_count); 
    #endif
    strcpy(KioskId, ns_eval_string("{KioskIdVar}"));
    strcpy(MessageId, ns_eval_string("{MessageIdVar}"));
    #ifdef NS_DEBUG_ON
    fprintf(stderr, "Error in response for page %s, KioskId = %s, MsgId = %s. Error Message = %s\n", pageName, KioskId, MessageId, ns_eval_string("{ErrorMessage}"));
    #endif
  return 1;
  }
}

static char * gen_email_id(char *var_name)
{
  static unsigned int email_counter=0;
  static char email_id_buf[64];
  snprintf(email_id_buf, 63, "rb_%0x_%0x_%0x@tnxtest.com", (unsigned)time(NULL), (unsigned)getpid(), (unsigned)email_counter++);
  email_id_buf[63] = '\0';

  if(var_name != NULL)
    ns_save_string(email_id_buf, var_name);

  return (email_id_buf);

}

