//nsl_static_var(uname:1,pass:2, File=filepara, Refresh=SESSION, Mode=SEQUENTIAL, EncodeMode=All);
//nsl_date_var(date, Format="%m/%d/%Y", Offset=1.00:00:00, Refresh=SESSION);
//nsl_web_find(TEXT="Tours", PAGE=index_html, FAIL=FOUND, ActionOnFail=CONTINUE);
//nsl_web_find(TEXT="Mercury", PAGE=index_html);
nsl_search_var(response, PAGE=index_html, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
