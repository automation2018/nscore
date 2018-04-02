nsl_decl_var(count);
//nsl_web_find(TEXT = %Rb, PAGE=class2K_html, FAIL = %Ord, ActionOnFail=Continue, SaveCount=count);
nsl_web_find(CompareFile = %Rb, PAGE=class2K_html, FAIL = %Ord, ActionOnFail=Continue, SaveCount=count);
