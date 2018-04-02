//nsl_search_var(PinSearch, PAGE=count_json, LB="PIN_", RB="callback", ORD=ANY_NONEMPTY, SaveOffset=0, ActionOnNotFound=Error, RETAINPREVALUE="YES", EncodeMode=None);
//nsl_decl_var(DeclParam);
//ns_save_string(ns_eval_string("{PinSearch}"),"DeclParam");

//nsl_decl_var(DP);
//nsl_search_var(SP, PAGE=index, LB="<form name=\"\"", RB="</form>");
//nsl_web_find(TEXT="easy returns every day", PAGE=index, FAIL=NOTFOUND, ID="string not matched", SaveCount=ghuug, ActionOnFail=STOP);
//nsl_decl_var(ghuug);
//nsl_web_find(TEXT/RE="static_pb_drawer+js", PAGE=*, FAIL=NOTFOUND, ID="Hello your contents verified", SaveCount=SaviCount, ActionOnFail=CONTINUE);
//nsl_decl_var(SaviCount);
//nsl_web_find(TextPfx/RE="cof+e+", TextSfx/RE="furnit+ur*", PAGE=*, FAIL=NOTFOUND, ID="Strings/Content Verified", SaveCount=saveCount, ActionOnFail=CONTINUE);
//nsl_decl_var(saveCount);
//nsl_web_find(Checksum=1244879995abdafedcadbe3256543643, PAGE=*, FAIL=NOTFOUND, ID="Sum Verified", SaveCount=CSum, ActionOnFail=CONTINUE);
//nsl_decl_var(CSum);
//nsl_web_find(TEXT="Varnika", PAGE=*, FAIL=NOTFOUND, ID="Text is not present", ActionOnFail=STOP);
nsl_web_find(TEXT="KOHL'S", PAGE=index, FAIL=NOTFOUND, ID="Text not found", ActionOnFail=CONTINUE);
//nsl_decl_var(savecount);
