//nsl_web_find(TEXT="Welcome to Anupam Tours", PAGE=login);
//nsl_web_find(TEXT="Welcome to Mercury Tours", PAGE=login);
//nsl_static_var(BrowserUserProfile:1,HarLogDir:2,VncDisplayId:3, File=DetailFile_10records, Refresh=SESSION, Mode=UNIQUE, FirstDataLine=1, EncodeMode=All);
nsl_static_var(BrowserUserProfile:1,HarLogDir:2,VncDisplayId:3, File=DetailFile, Refresh=SESSION, Mode=UNIQUE, FirstDataLine=1, EncodeMode=All);
//nsl_static_var(BrowserUserProfile:1,HarLogDir:2,VncDisplayId:3, File=DetailFile, Refresh=USE, Mode=UNIQUE, FirstDataLine=1, EncodeMode=All);
//nsl_static_var(BrowserUserProfile:1,HarLogDir:2,VncDisplayId:3, File=DetailFile, Refresh=SESSION, Mode=SEQUENTIAL, FirstDataLine=1, EncodeMode=All);
//nsl_search_var(SearchTitle, PAGE=*, LB="<title>", RB="</title>", SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
