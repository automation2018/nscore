nsl_web_find(TEXT="Hi response fjsahgjharom 82 serevr", PAGE=ntlm_html, FAIL = NOTFOUND, ID="Text not found", ActionOnFail= Continue);
nsl_search_var(Pagename, PAGE=ntlm_html, LB="Hi",RB="basic Auth",  ORD=1, SaveOffset=1, ActionOnNotFound= Warning);
