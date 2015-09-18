/**************FileParmameter*********************/

nsl_static_var(SearchKeywordFP, File=Keyword.txt, Refresh=SESSION, Mode=SEQUENTIAL, FirstDataLine=1);
nsl_static_var(ProductIdFP, File=ProductId.txt, Refresh=SESSION, Mode=RANDOM, FirstDataLine=1);
nsl_static_var(UserIdFP,PasswordFP, File=Login.txt, Refresh=SESSION, Mode=SEQUENTIAL, EncodeMode=Specified, CharsToEncode="@");
nsl_static_var(FirstNameFP,LastNameFP,AddressFP,CityFP,StateFP,PostalCodeFP,PhoneNumberFP,EmailAddressFP, File=AddressDetail.txt, Refresh=SESSION, Mode=SEQUENTIAL);
nsl_static_var(RegFirstNameFP,RegLastNameFP,RegAddressFP,RegCityFP,RegStateFP,RegPostalCodeFP,RegPhoneNumberFP, File=RegAddressDetail.txt, Refresh=SESSION, Mode=SEQUENTIAL);
//nsl_static_var(CardTypeFP,CardNameIdFP,CardNumFP,CardExpMonthFP,CardExpYearFP,CardCVVFP, File=/home/netstorm/Controller_1/data/Webstore/Paymentdetails.txt, Refresh=SESSION, Mode=SEQUENTIAL);
nsl_static_var(CardTypeFP,CardNameIdFP,CardNumFP,CardExpMonthFP,CardExpYearFP,CardCVVFP, File=/home/netstorm/work/data/Akamai/Paymentdetails.txt, Refresh=SESSION, Mode=SEQUENTIAL);

nsl_web_find(TEXT="The E-mail Address and/or Password you've entered has an error", PAGE=RegisterUserPage, FAIL=FOUND, ID="You Are Not Signin", ActionOnFail=STOP);

nsl_web_find(TEXT="Oops! Some information is missing or invalid below", PAGE=Reg_BillingInformationPage,PAGE=Unreg_PaymentInformationPage,PAGE=Unreg_BillingInformationPage, PAGE=Reg_PaymentInformationPage,PAGE=ShoppingCartPage,PAGE=UpdatedAddToBagPage,PAGE=RegisterUserPage, FAIL=FOUND, ID="Incorrect Billing or Payment Page", ActionOnFail=STOP);
nsl_web_find(TEXT="Your Shopping Bag is currently empty", PAGE=ShoppingCartPage, FAIL=FOUND, ID="shopping Bag is empty[{AddToBagSkuId}]", ActionOnFail=STOP);
nsl_web_find(TEXT="Proceed to shopping bag and checkout", PAGE=AddToBagPage, FAIL=NOTFOUND, ID="Product not added successfully", ActionOnFail=STOP);
nsl_web_find(TEXT="Kohl's | Shop Clothing, Shoes, Home, Kitchen, Bedding, Toys & More", PAGE=HomePage, FAIL=NOTFOUND, ID="Homepage is not found", ActionOnFail=STOP);
nsl_web_find(TEXT="All Products", PAGE=SearchKeywordPage, PAGE=SortPage, PAGE=PaginationPage, FAIL=NOTFOUND, ID="Product Matrix Page not found : 'All Products' not found", ActionOnFail=STOP); 
nsl_web_find(TEXT="Order Success - Kohls.com", PAGE=Unreg_PlacedOrderPage,PAGE=Reg_PlacedOrderPage, FAIL=NOTFOUND, ID="Order confirm Page not found", ActionOnFail=STOP);
nsl_web_find(TEXT="start : product_guide.jsp", PAGE=AddToBagPage,PAGE=UpdateItemPage, FAIL=NOTFOUND, ID="ProductDetailPage not found", ActionOnFail=STOP);
nsl_web_find(TEXT="Shopping Bag - Kohls.com", PAGE=ShoppingCartPage,  PAGE=UpdatedAddToBagPage, FAIL=NOTFOUND, ID="ShoppingCart Page not found", ActionOnFail=STOP);
nsl_web_find(TEXT="Billing and Shipping Information - Kohls.com", PAGE=RegisterUserPage, PAGE=CO_CheckOut, FAIL=NOTFOUND, ID="BillingInformationPage not found", ActionOnFail=STOP);
nsl_web_find(TEXT="Payment Information - Kohls.com", PAGE=Unreg_BillingInformationPage, PAGE=Reg_BillingInformationPage, FAIL=NOTFOUND, ID="Payment information Page not found[{ShipGroupIdSP}]", ActionOnFail=STOP);
nsl_web_find(TEXT="Review and Place Your Order - Kohls.com", PAGE=Reg_PaymentInformationPage, PAGE=Unreg_PaymentInformationPage, FAIL=NOTFOUND, ID="Place Order page not found", ActionOnFail=STOP);
nsl_web_find(TEXT="Try a new search", PAGE=RefinementPage, PAGE=SearchKeywordPage, FAIL=FOUND, ID="RefinementPage Not Found[{SearchKeywordFP}]", ActionOnFail=STOP);
//nsl_web_find(TEXT="We're sorry, this item is no longer available",PAGE=ProductDetailPage, PAGE=SearchProductIdPage, FAIL=FOUND, ID="This item is not availaable", ActionOnFail=STOP);
nsl_web_find(TEXT="Product Matrix Page", PAGE=TopNavPage, FAIL=FOUND, ID="TopNavigation Link not configured correctly. [{TopNavUrlFP}]", ActionOnFail=STOP);
nsl_web_find(TEXT="Error_page_msg", PAGE=*, FAIL=FOUND, ID="Error_page_msg found on screen.", ActionOnFail=STOP);


nsl_search_var(DynSessionConfSP, PAGE=HomePage, PAGE=HomePageSearch, PAGE=SearchKeywordPage, PAGE=SearchProductIdPage, PAGE=TopNavPage,PAGE=HomePageSearchK, LB="dynSessConf\" value=\"", RB="\" type=\"hidden\"></input", SaveOffset=0, RETAINPREVALUE="YES");
//nsl_search_var(ReferIdSP, PAGE=UpdateItemPage, LB="SelectedSkuId : ", RB="\r\tskuCount", ORD=ANY, SaveOffset=0, RETAINPREVALUE="NO");
nsl_search_var(ProductSelectUrlSP, PAGE=SearchKeywordPage, PAGE=RefinementPage, PAGE=PaginationPage, PAGE=LeftNavPage, PAGE=SortPage, LB="<a href=\"/product/", RB="\"", ORD=ANY, SaveOffset=0, RETAINPREVALUE="NO");
nsl_search_var(EditItemUrlSP, PAGE=ShoppingCartPage, LB="<a href=\"/product/", RB="&action=edit\">", ORD=ANY, SaveOffset=0, RETAINPREVALUE="YES");
nsl_search_var(ShipGroupIdSP, PAGE=CO_CheckOut, LB="<input name=\"fh_ship_group_id\" value=\"", RB="\" type=\"hidden\">", SaveOffset=0, RETAINPREVALUE="YES");
//nsl_search_var(UpdateIdSP, PAGE=ShoppingCartPage, LB="<form id=\"update_", RB="\"", SaveOffset=0, RETAINPREVALUE="NO");
//nsl_search_var(CheckOutCiSP, PAGE=ShoppingCartPage, PAGE=UpdatedAddToBagPage, LB="<form id=\"update_ci", RB="\"", ORD=ANY, SaveOffset=0, RETAINPREVALUE="NO");

nsl_decl_var(AddToBagSkuId);


/**** Refinement flow - START *******************/

nsl_decl_var(RefinementUrl);
nsl_decl_var(nsTotalPagesToNavigate);
nsl_decl_var(nsPendingPagesToNavigate);
nsl_decl_var(nsPagesNavigatedInCurrentStep);
nsl_decl_var(nsMaxNavigateInNextStep);

nsl_search_var(RefinementUrlBlockSP, PAGE=SearchKeywordPage, PAGE=RefinementPage, PAGE=LeftNavPage, LB="Begin faceted search navigation.", RB="<div id=\"end-dimensions\" class=\"visually-hidden\">", ORD=ANY, SaveOffset=0, RETAINPREVALUE="NO");
nsl_search_var(RefinementUrlSPCount, PAGE=RefinementPage, PAGE=SearchKeywordPage, PAGE=LeftNavPage, LB="<li> <a class=\"\" href=\"/", RB="\"> <span class=\"checkbox ir\">", ORD=ALL, SaveOffset=0, Search=Variable, Var=RefinementUrlBlockSP, RETAINPREVALUE="NO");
nsl_search_var(RefinementUrlSP, PAGE=SearchKeywordPage, PAGE=RefinementPage, PAGE=LeftNavPage, LB="<li> <a class=\"\" href=\"/", RB="\"> <span class=\"checkbox ir\">", ORD=ANY, SaveOffset=0, Search=Variable, Var=RefinementUrlBlockSP, RETAINPREVALUE="NO");
nsl_search_var(ProductDetailSP, PAGE=SearchKeywordPage, PAGE=RefinementPage, PAGE=LeftNavPage, LB="<div class=\"product-cd\">", RB="</div>", SaveOffset=0, RETAINPREVALUE="NO");
nsl_search_var(AddToBagSP, PAGE=SearchKeywordPage, PAGE=RefinementPage, PAGE=LeftNavPage, LB="<div class=\"addtobag\">", RB="</div>", SaveOffset=0, RETAINPREVALUE="NO");

/**** Refinement flow - END   ******************/



/**** Pagination flow - START *******************/
nsl_search_var(PaginationUrlBlockSP, PAGE=SearchKeywordPage,PAGE=PaginationPage,PAGE=LeftNavPage,  LB="<div class=\"display-controls display-controls-top\">", RB="<ul id=\"product-matrix\" class=\"clearfix\">", ORD=ANY, SaveOffset=0, RETAINPREVALUE="NO");
nsl_search_var(PaginationUrlSP, PAGE=SearchKeywordPage,PAGE=PaginationPage,PAGE=LeftNavPage,  LB="<li><a class=\"\" href=\"/", RB="\">", ORD=ANY, SaveOffset=0, Search=Variable, Var=PaginationUrlBlockSP, RETAINPREVALUE="NO");
nsl_search_var(PaginationUrlSPCount, PAGE=SearchKeywordPage,PAGE=PaginationPage,PAGE=LeftNavPage,  LB="<li><a class=\"\" href=\"/", RB="\">", ORD=ALL, SaveOffset=0, Search=Variable, Var=PaginationUrlBlockSP, RETAINPREVALUE="NO");
/**** Pagination flow - END   ******************/

//nsl_search_var(SI_ProductIdSP, PAGE=ProductDetailPage, PAGE=SearchProductIdPage,PAGE=CollectionItemPage, LB="'entity.id=", RB="'", ORD=ANY, SaveOffset=0, RETAINPREVALUE="YES");
nsl_search_var(SkuIdStatusSP, PAGE=ProductDetailPage,PAGE=SearchProductIdPage,LB="\"inventoryStatus\":\"", RB="\"", ORD=ALL, SaveOffset=0, RETAINPREVALUE="NO");
nsl_search_var(SkuIdSP, PAGE=ProductDetailPage, PAGE=SearchProductIdPage,LB="\"skuId\":\"", RB="\"", ORD=ALL, SaveOffset=0, RETAINPREVALUE="NO");
nsl_search_var(AvaliableSkuSP, PAGE=ProductDetailPage, PAGE=SearchProductIdPage,LB="\"inventoryStatus\":\"true\"", RB=",", ORD=ALL, SaveOffset=0, RETAINPREVALUE="NO");

/***** Browse Flow -  Start********************/

nsl_static_var(TopNavUrlFP, File=TopNavUrl.txt, Refresh=SESSION, Mode=RANDOM, FirstDataLine=6, EncodeMode=None);
nsl_search_var(LeftNavBlockSP, PAGE=TopNavPage, LB="<h1 id=\"sale-event-title\">", RB="<div id=\"end-dimensions\" class=\"visually-hidden\">", ORD=ANY, SaveOffset=0, RETAINPREVALUE="NO");
//nsl_search_var(LeftNavUrlSP, PAGE=TopNavPage, LB="<li><a href=\"/", RB="\">", ORD=ANY, SaveOffset=0, ActionOnNotFound=Error, Search=Variable, Var=LeftNavBlockSP, RETAINPREVALUE="NO");
nsl_search_var(LeftNavUrlSP1, PAGE=TopNavPage, LB="<li><a href=\"/catalog/", RB="\">", ORD=ANY, SaveOffset=0, ActionOnNotFound=Error, Search=Variable, Var=LeftNavBlockSP, RETAINPREVALUE="NO");
nsl_search_var(LeftNavUrlSP2, PAGE=TopNavPage, LB="<li><a href=\"/catalog/", RB="\">", ORD=ANY, SaveOffset=0, ActionOnNotFound=Error, Search=Variable, Var=LeftNavBlockSP, RETAINPREVALUE="NO");
nsl_search_var(LeftNavUrlSP3, PAGE=TopNavPage, LB="<li><a href=\"/catalog/", RB="\">", ORD=ANY, SaveOffset=0, ActionOnNotFound=Error, Search=Variable, Var=LeftNavBlockSP, RETAINPREVALUE="NO");
nsl_search_var(LeftNavUrlSP4, PAGE=TopNavPage, LB="<li><a href=\"/catalog/", RB="\">", ORD=ANY, SaveOffset=0, ActionOnNotFound=Error, Search=Variable, Var=LeftNavBlockSP, RETAINPREVALUE="NO");
nsl_search_var(LeftNavUrlSP5, PAGE=TopNavPage, LB="<li><a href=\"/catalog/", RB="\">", ORD=ANY, SaveOffset=0, ActionOnNotFound=Error, Search=Variable, Var=LeftNavBlockSP, RETAINPREVALUE="NO");
nsl_search_var(ItemTypeCheckBlockSP, PAGE=ProductDetailPage, PAGE=SearchProductIdPage, LB="<!-- Collection Details tab content starts from here -->", RB="</div> <!-- Collection Details tab content ends here -->", ORD=ANY, SaveOffset=0, RETAINPREVALUE="NO");
nsl_search_var(ItemTypeCheckSP, PAGE=ProductDetailPage, PAGE=SearchProductIdPage, LB="<div id=\"", RB="\" >", SaveOffset=0, Search=Variable, Var=ItemTypeCheckBlockSP, RETAINPREVALUE="NO");
nsl_search_var(CollectionUrlSP, PAGE=ProductDetailPage, PAGE=SearchProductIdPage, LB="<a href=\"/product/", RB="\">", ORD=ANY, SaveOffset=0, Search=Variable, Var=ItemTypeCheckBlockSP, RETAINPREVALUE="NO");
nsl_search_var(ZeroProductsSP, PAGE=LeftNavPage, PAGE=SearchKeywordPage, LB="<h2 id=\"number-products\">0", RB="</h2>", ORD=ANY, SaveOffset=0, RETAINPREVALUE="NO");
nsl_search_var(ZeroProductsCountSP, PAGE=LeftNavPage, PAGE=SearchKeywordPage, LB="<h2 id=\"number-products\">0", RB="</h2>", ORD=ALL, SaveOffset=0, RETAINPREVALUE="NO");




/********ChangeViewFlow*********************/

nsl_static_var(ChangeViewTypeFP, File=ChangeViewType.txt, Refresh=SESSION, Mode=SEQUENTIAL);

/***************SortProductFlow*****************/
nsl_search_var(SortBlockSP, PAGE=SearchKeywordPage, PAGE=LeftNavPage, LB="<select id=\"select-sort\" class=\"js-select-list display-none\" name=\"select-sort\">", RB="<input type=\"hidden\" id=\"contextPath\" value=\"\"/>", ORD=ANY, SaveOffset=0, RETAINPREVALUE="NO");
nsl_search_var(SortUrlSP, PAGE=SearchKeywordPage,  PAGE=LeftNavPage, LB="<li> <a href=\"", RB="\">", ORD=ANY, SaveOffset=0, ActionOnNotFound=Error, Search=Variable, Var=SortBlockSP, RETAINPREVALUE="NO");


nsl_decl_var(BrowseLoop);
nsl_decl_var(SearchLoop);
nsl_decl_var(AddToBagDP);
nsl_decl_var(SearchKeywordDP);
nsl_decl_var(LeftNavUrlSP);
nsl_decl_var(BrowseLoopHWM);

nsl_search_var(CollectionIDSP, PAGE=SearchProductIdPage,PAGE=ProductDetailPage, LB="\"skava_collectionId\" value=\"", RB="\"/>", SaveOffset=0, RETAINPREVALUE="YES");
//nsl_search_var(CI_ProductIdSP, PAGE=SPId_CollectionItemPage,PAGE=CollectionItemPage, LB="productId\" value=\"", RB="\"", SaveOffset=0, RETAINPREVALUE="YES");
nsl_search_var(Update_ProductIdSP, PAGE=UpdateItemPage, LB="ProductId : ", RB="\r", SaveOffset=0, RETAINPREVALUE="YES");
nsl_static_var(LeftNavUrlFP, File=LeftNavUrl.txt, Refresh=SESSION, Mode=SEQUENTIAL, EncodeMode=None);

/************ set form block for RegCheckout and UnRegCheckOut****************/
//nsl_search_var(ShipGroupIdSP, PAGE=CO_CheckOut, LB="<input name=\"fh_ship_group_id\" value=\"", RB="\" type=\"hidden\">", SaveOffset=0, RETAINPREVALUE="YES");
nsl_search_var(UnReg_PaymentFormBlockSP, PAGE=Unreg_BillingInformationPage, LB="<form id=\"payment_form_1\"", RB="</form>", SaveOffset=0, RETAINPREVALUE="YES");
nsl_decl_var(UnReg_PaymentInfoDP);
nsl_search_var(Reg_PaymentFormBlockSP, PAGE=Reg_BillingInformationPage, LB="<form id=\"payment_form_1\"", RB="</form>", SaveOffset=0, RETAINPREVALUE="YES");
nsl_decl_var(Reg_PaymentInfoDP);
nsl_search_var(CheckOutFormBlockSP, PAGE=ShoppingCartPage,PAGE=UpdatedAddToBagPage, LB="<form id=\"cart_checkout\"", RB="</form>", ORD=3, SaveOffset=0, RETAINPREVALUE="YES");
nsl_decl_var(CheckOutDP);
nsl_search_var(EditItemFormBlockSP, PAGE=UpdateItemPage, LB="<form name=\"aadToBag\"", RB="</form>", SaveOffset=0, RETAINPREVALUE="YES");
nsl_decl_var(EditItemDP);
nsl_search_var(ATG_SignInFormBlockSP, PAGE=CO_CheckOut, LB="<form id=\"csi-form\"", RB="</form>", SaveOffset=0, RETAINPREVALUE="YES");
nsl_decl_var(ATG_SignInDP);
nsl_search_var(SI_FormBlockSP, PAGE=SearchProductIdPage , PAGE=ProductDetailPage ,  LB="<form name=\"aadToBag\"", RB="</form>", SaveOffset=0, RETAINPREVALUE="NO");
nsl_search_var(MI_FormBlockSP, PAGE=SearchProductIdPage, PAGE=ProductDetailPage, LB="<form id=\"addToCart", RB="</form>", SaveOffset=0, RETAINPREVALUE="NO");
nsl_search_var(SubmitOrderFormBlockSP, PAGE=Reg_PaymentInformationPage, PAGE=Unreg_PaymentInformationPage, LB="<form id=\"checkout_submit_order\"", RB="</form>", SaveOffset=0, RETAINPREVALUE="YES");
nsl_decl_var(SubmitOrderDP);
nsl_search_var(ItemCheckAvailBlockSP, PAGE=ProductDetailPage, PAGE=SearchProductIdPage, LB="<h1 class=\"title productTitleName\">", RB="</div>", SaveOffset=0, RETAINPREVALUE="YES");
nsl_search_var(ItemCheckAvailSP, PAGE=ProductDetailPage, PAGE=SearchProductIdPage, LB="<div class=\"", RB="\">", SaveOffset=0, Search=Variable, Var=ItemCheckAvailBlockSP, RETAINPREVALUE="YES");


nsl_unique_number_var(random, Format=%03lu, Refresh=USE); 
