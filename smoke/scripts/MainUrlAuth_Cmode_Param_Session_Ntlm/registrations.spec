nsl_static_var(Usrname,Passwd, FILE=Userpass.dat, REFRESH=SESSION, MODE=SEQUENTIAL);
//nsl_web_find(TEXT="Hi this is cavisson system", PAGE=ntlm_html, FAIL = NOTFOUND, ID="Text not found", ActionOnFail= Continue);
//nsl_search_var(Pagename, PAGE=ntlm_html, LB="Hi",RB="system",  ORD=1, SaveOffset=1, SaveLen=11, ActionOnNotFound= Warning);
