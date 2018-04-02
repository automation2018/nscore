nsl_static_var(uname:1,pass:2, File=filepara, Refresh=SESSION, Mode=SEQUENTIAL, EncodeMode=All);
nsl_static_var(repeat:1, File=repeat.txt, Refresh=SESSION, Mode=SEQUENTIAL, EncodeMode=All);
nsl_decl_var(search_para_value);
nsl_decl_var(count);
nsl_decl_var(parameter1);

nsl_decl_var(occurrence1);
nsl_decl_var(occurrence2);
nsl_decl_var(occurrence3);
nsl_decl_var(occurrence4);
nsl_decl_var(occurrence5);
//nsl_web_find(TEXT="Tours", PAGE=index_html, FAIL=FOUND, ActionOnFail=STOP);
