
// File parameters
nsl_decl_var(CCNumVar);
nsl_decl_var(CCLastNameVar);
nsl_decl_var(CCFirstNameVar);
nsl_decl_var(CCPostalCodeVar);
nsl_decl_var(CCExpirationMonthVar);
nsl_decl_var(CCExpirationYearVar);
nsl_decl_var(CCIdVar);
nsl_decl_var(CCLastFourVar);
nsl_decl_var(CCTypeVar);
nsl_decl_var(CCKeyIdVar);
nsl_decl_var(CCTrack2Var);

nsl_static_var(CCNumVar1,CCLastNameVar1,CCFirstNameVar1,CCPostalCodeVar1,CCExpirationMonthVar1,CCExpirationYearVar1,CCIdVar1,CCLastFourVar1,CCTypeVar1,CCKeyIdVar1,CCTrack2Var1, File=/home/netstorm/work/data/AAAData_0513/Integration/CC_withoutCP_PCI.txt, Refresh=SESSION, Mode=RANDOM,EncodeMode=None, FirstDataLine=2, CopyFileToTR=No);

nsl_static_var(CCNumVar2,CCLastNameVar2,CCFirstNameVar2,CCPostalCodeVar2,CCExpirationMonthVar2,CCExpirationYearVar2,CCIdVar2,CCLastFourVar2,CCTypeVar2,CCKeyIdVar2,CCTrack2Var2,CPNumber,AcctNumber,CardAccountID, File=/home/netstorm/work/data/AAAData_0513/Integration/CC_withCP_PCI.txt, Refresh=SESSION, Mode=RANDOM,EncodeMode=None, FirstDataLine=2, CopyFileToTR=No);

nsl_static_var(GCNumVar,GCExpirationMonthVar,GCExpirationYearVar,GCIdVar,GCLastFourVar,GCKeyIdVar,GCTrack2Var,GCNumber, File=/home/netstorm/work/data/AAAData_0513/Integration/GC_CP.txt, Refresh=SESSION, Mode=RANDOM,EncodeMode=None, FirstDataLine=2, CopyFileToTR=No);

nsl_decl_var(FirstName);
nsl_decl_var(LastName);
nsl_decl_var(CardNumber);
nsl_decl_var(PostalCode);
nsl_decl_var(ExpMonth);
nsl_decl_var(ExpYear);
nsl_decl_var(KeyId);
nsl_decl_var(CardID);
nsl_decl_var(LastFour);
nsl_decl_var(CardType);
nsl_decl_var(Track2);
nsl_decl_var(PickUpEmail);
nsl_decl_var(BarcodeVal);
nsl_decl_var(RefNumber);
nsl_decl_var(KioskId);

nsl_static_var(CCFirstName,CCLastName,CCCardNumber,CCPostalCode,CCExpMonth,CCExpYear,CCKeyId,CCCardID,CCLastFour,CCCardType,CCTrack2,CCCardAcctID, File=/home/netstorm/work/data/AAAData_0513/Integration/PickUpValidation.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=None, CopyFileToTR=No);

nsl_static_var(CCPickUpEmail,CCBarcodeVal,CCRefNumber,CCKioskId,CCRentedDate,CCCustomerID,CCInvoiceID, File=/home/netstorm/work/data/AAAData_0513/Integration/PickUp.txt, Refresh=SESSION, FirstDataLine=2, Mode=RANDOM, EncodeMode=None, CopyFileToTR=No);

nsl_static_var(GCReservationEmail,GCFirstName,GCLastName,GCCardNumber,Numbergc,GCExpMonth,GCExpYear,GCTrack2,GCKeyId,GCCardID,GCLastFour, File=/home/netstorm/work/data/AAAData_0513/Integration/GCPickUpValidation.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=None, CopyFileToTR=No);

nsl_static_var(GCPickUpEmail,GCBarcodeVal,GCRefNumber,GCKioskId,GCRentedDate,GCCustomerID,GCInvoiceID, File=/home/netstorm/work/data/AAAData_0513/Integration/GCPickUpData.txt, Refresh=SESSION, FirstDataLine=2, Mode=RANDOM, EncodeMode=None, CopyFileToTR=No);

nsl_static_var(CardHash,Email, File=/home/netstorm/work/data/AAAData_0513/Integration/CH_Email.txt, Refresh=SESSION, Mode=RANDOM,EncodeMode=None, CopyFileToTR=No);

nsl_static_var(CC_CardId,EmailAdd,CardAcctId, File=/home/netstorm/work/data/AAAData_0513/Integration/CC_ID_Email.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=None, CopyFileToTR=No);

nsl_static_var(BarcodeDVDVar, File=/home/netstorm/work/data/AAAData_0513/Integration/BarcodeDVD.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=None, CopyFileToTR=No);
nsl_static_var(BarcodeBlurayVar, File=/home/netstorm/work/data/AAAData_0513/Integration/BarcodeBluRay.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=None, CopyFileToTR=No);
nsl_static_var(GameTitleId,BarcodeGameVar,GameProductType, File=/home/netstorm/work/data/AAAData_0513/Integration/Games_Rental.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=None, CopyFileToTR=No);

nsl_decl_var(AuthMsgType);
nsl_decl_var(DiscountCode);
nsl_decl_var(EmailIdVar);

nsl_decl_var(ReturnBarcodeVar);
nsl_static_var(ReturnWidCreditVar, File=/home/netstorm/work/data/AAAData_0513/Integration/Return_withCredits.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=None, CopyFileToTR=No);
nsl_static_var(ReturnWidNoCreditVar, File=/home/netstorm/work/data/AAAData_0513/Integration/Return_withoutCredits.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=None, CopyFileToTR=No);

nsl_static_var(Barcode1, File=/home/netstorm/work/data/AAAData_0513/Integration/DiscBarcode1.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=None, CopyFileToTR=No);
nsl_static_var(Barcode2, File=/home/netstorm/work/data/AAAData_0513/Integration/DiscBarcode2.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=None, CopyFileToTR=No);

nsl_static_var(ItemIDVar,ItemTypeVar,TemplateName,CampaignName, File=/home/netstorm/work/data/OptInItemID.txt, Refresh=SESSION, Mode=RANDOM, FirstDataLine=2, CopyFileToTR=No);
nsl_static_var(MerchType, File=/home/netstorm/work/data/MerchType.txt, Refresh=SESSION, Mode=RANDOM, CopyFileToTR=No);
nsl_static_var(KioskIdVar, File=/home/netstorm/work/data/KioskIdSTG.txt, Refresh=SESSION,Mode=RANDOM, EncodeMode=None, CopyFileToTR=No);
nsl_static_var(VendStatusVar, File=/home/netstorm/work/data/Vendstatus.txt, Refresh=SESSION, Mode=RANDOM, CopyFileToTR=No);
nsl_static_var(DeckVar, File=/home/netstorm/work/data/Deck.txt, Refresh=SESSION, Mode=RANDOM, CopyFileToTR=No);
nsl_static_var(SlotVar, File=/home/netstorm/work/data/Slot.txt, Refresh=SESSION, Mode=RANDOM, CopyFileToTR=No);
nsl_static_var(SessionDataVar, File=/home/netstorm/work/data/SessionData.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=Specified, CharsToEncode="'\"{}:=+/", CopyFileToTR=No);
nsl_static_var(OptVar, File=/home/netstorm/work/data/OptData.txt, Refresh=SESSION, Mode=RANDOM, CopyFileToTR=No);

// Checkpoints

nsl_web_find(TEXT="ReferenceNumber%22%3a", PAGE=RentService, FAIL=NOTFOUND, ID="Auth Req is not successful.Reference Num not Found.", ActionOnFail=STOP);
nsl_web_find(TEXT="Success%22%3atrue", PAGE=DiscountValidationService, FAIL=NOTFOUND, ID="Discount Req is not successful.Success is False", ActionOnFail=STOP);
nsl_web_find(TEXT="Success%22%3atrue", PAGE=GetCustCredit, FAIL=NOTFOUND,ID="GetCredit Not Successful.Success is false");
nsl_web_find(TEXT="Success%22%3atrue", PAGE=RentService, FAIL=NOTFOUND, ID="Auth Req is not successful.Success is False", ActionOnFail=STOP);
nsl_web_find(TEXT="Success%22%3atrue", PAGE=ReconcileService, FAIL=NOTFOUND,ID="Reconcile Not Successful.Success is false");
nsl_web_find(TEXT="Success%22%3atrue", PAGE=ReturnService, FAIL=NOTFOUND,ID="Return Not Successful.Success is false");
nsl_web_find(TEXT="No Transaction was found", PAGE=ReturnService, FAIL=FOUND, ID="ReturnService Page failed", ActionOnFail=STOP);
nsl_web_find(TEXT="Return: Success", PAGE=ReturnService, FAIL=FOUND, ID="ReturnService failed", ActionOnFail=STOP);
nsl_web_find(TEXT="Success%22%3atrue", PAGE=KioskPing, FAIL=NOTFOUND,ID="KioskPing Not Successful.Success is false");
nsl_web_find(TEXT="ServerBusy%22%3afalse", PAGE=KioskPing, FAIL=NOTFOUND,ID="KioskPing Server is Busy");
nsl_web_find(TEXT="Success%22%3atrue", PAGE=DiscActionService, FAIL=NOTFOUND,ID="DiscActionService Not Successful");
nsl_web_find(TEXT="%22ReferenceNumber%22%3a0%2c", PAGE=RentService, FAIL=FOUND,ID="Reference Number is Zero", ActionOnFail=STOP);
nsl_web_find(TEXT="IsUnplayable%22%3atrue", PAGE=UnplayableReturnService, FAIL=NOTFOUND,ID="Return Not Successful.Success is false");
nsl_web_find(TEXT="Success%22%3atrue", PAGE=AuthorizeFailure, FAIL=NOTFOUND,ID="AuthorizeFailure Page Not Successful.Success is false");
nsl_web_find(TEXT="Success%22%3atrue", PAGE=ReconcileFailure, FAIL=NOTFOUND,ID="ReconcileFailure Not Successful.Success is false");
nsl_web_find(TEXT="Success%22%3atrue", PAGE=EmailConfirmation, FAIL=NOTFOUND,ID="EmailConfirmation Not Successful");
nsl_web_find(TEXT="Success%22%3atrue", PAGE=KioskOptInService, FAIL=NOTFOUND,ID="KioskOptInService Not Successful");
nsl_web_find(TEXT="Success%22%3atrue", PAGE=PickUpValidation, FAIL=NOTFOUND,ID="PickUpValidation Not Successful");
nsl_web_find(TEXT="Success%22%3atrue", PAGE=PickUp, FAIL=NOTFOUND,ID="PickUp Not Successful");

// Search parameters
nsl_search_var(RefNumVar, PAGE=RentService, LB="ReferenceNumber%22%3a", RB="%2c%22");
nsl_search_var(FailRefNumVar, PAGE=AuthorizeFailure, LB="ReferenceNumber%22%3a", RB="%2c%22");
nsl_search_var(DiscountValue, PAGE=DiscountValidationService, LB="%22Amount%22%3a", RB="%2c");
nsl_date_var(TransactionDateVar, Format=%Y-%m-%dT%H:%M:%S.1234567, Refresh=USE);

// Other paramters
nsl_decl_var(ErrorCount);
nsl_web_find(TEXT="%22HasErrors%22%3atrue%2c", PAGE=*, SaveCount=ErrorCount);
nsl_search_var(ErrorMessage, PAGE=*, LB="%22Errors%22%3a%5b", RB="%5d");

nsl_decl_var(ServiceIdVar);
nsl_decl_var(ScriptStatus);
nsl_decl_var(PgThinkTimeVar);
nsl_decl_var(MessageIdVar);

nsl_decl_var(RentalItemTotalVar);
nsl_decl_var(PurchaseItemTotalVar);

nsl_decl_var(RentalItemBlockVar);
nsl_decl_var(PurchaseItemBlockVar);

nsl_decl_var(RentalTaxRateVar);
nsl_decl_var(PurchaseTaxRateVar);

nsl_decl_var(RentalTaxAmountVar);
nsl_decl_var(PurchaseTaxAmountVar);

nsl_decl_var(RentalSubTotalVar);
nsl_decl_var(PurchaseSubTotalVar);

nsl_decl_var(RentalGrandTotalVar);
nsl_decl_var(PurchaseGrandTotalVar);

nsl_decl_var(RentalDiscountedSubtotalVar);
nsl_decl_var(PurchaseDiscountedSubtotalVar);

nsl_decl_var(LastPingTSVar);
nsl_decl_var(LastRentalTSVar);
nsl_decl_var(LastFailureRentalTSVar);
nsl_decl_var(LastOfflineRentalTSVar);
nsl_decl_var(LastReturnTSVar);
nsl_decl_var(LastUnplayableTSVar);
nsl_decl_var(LastKioskAnalyticsTSVar);
nsl_decl_var(LastDiscountValidationTSVar);
nsl_decl_var(LastGetCustCreditTSVar);
nsl_decl_var(PageIdBeforePingVar);
nsl_decl_var(ServiceIdBeforePingVar);
nsl_decl_var(LastOptInRentalTSVar);
nsl_decl_var(LastDiscActionTSVar);
nsl_decl_var(LastEmailConfirmTSVar);
nsl_decl_var(LastPickUpValidationTSVar);
nsl_decl_var(LastGCPickUpValidationTSVar);
nsl_decl_var(LastGCRentalTSVar);

