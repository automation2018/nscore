//nsl_search_var(searchvar, PAGE=page1, LB="<p>", RB="</p>", ActionOnNotFound= Warning);
//nsl_search_var(searchvar, PAGE=page1, LB="<tr>", RB="</tr>", SaveOffset=14, SaveLen=31, ORD=ALL, ActionOnNotFound=Warning);
//nsl_static_var(CaptchaFP:1, File=captchaWordList.dat, Refresh=USE, Mode=RANDOM, EncodeMode=All);
nsl_search_var(searchvar, PAGE=page1, LB="<td>", RB="</td>", ORD=ALL, ActionOnNotFound=Warning);
nsl_decl_var(DecryptedCaptchaDP);
nsl_decl_var(SearchVarHdr);
