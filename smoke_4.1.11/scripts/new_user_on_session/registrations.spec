nsl_static_var(userid:1,password:2, File=file.seq, Refresh=SESSION, Mode=SEQUENTIAL, EncodeMode=All);
nsl_search_var(sp, PAGE=login, LB="<title>", RB="</title>", SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_decl_var(dp1);
nsl_decl_var(dp2);
nsl_decl_var(dp3);
//nsl_web_find(TEXT="Tours", PAGE=login, FAIL=FOUND, ActionOnFail=CONTINUE);
