//nsl_web_find(TEXT="Welcome to Anupam Tours", PAGE=login);
//nsl_web_find(TEXT="Welcome to Mercury Tours", PAGE=login);
//nsl_static_var(BrowserUserProfile:1,HarLogDir:2,VncDisplayId:3, File=DetailFile_10records, Refresh=SESSION, Mode=UNIQUE, FirstDataLine=1, EncodeMode=All);
//nsl_static_var(BrowserUserProfile:1,HarLogDir:2,VncDisplayId:3, File=DetailFile, Refresh=SESSION, Mode=UNIQUE, FirstDataLine=1, EncodeMode=All);
//nsl_static_var(BrowserUserProfile:1,HarLogDir:2,VncDisplayId:3, File=DetailFile, Refresh=USE, Mode=UNIQUE, FirstDataLine=1, EncodeMode=All);
//nsl_static_var(BrowserUserProfile:1,HarLogDir:2,VncDisplayId:3, File=DetailFile, Refresh=SESSION, Mode=SEQUENTIAL, FirstDataLine=1, EncodeMode=All);
//nsl_search_var(SearchTitle, PAGE=*, LB="<title>", RB="</title>", SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);

//nsl_static_var(PLWT:1, File=StaticFile, Refresh=SESSION, Mode=UNIQUE, FirstDataLine=1, EncodeMode=All);
//nsl_static_var(PLWT:1, File=StaticFile, Refresh=SESSION, Mode=SEQUENTIAL, FirstDataLine=1, EncodeMode=All);
//nsl_static_var(PLWT:1, File=StaticFile, Refresh=SESSION, Mode=RANDOM, FirstDataLine=1, EncodeMode=All);
//nsl_static_var(PLWT:1, File=StaticFile, Refresh=SESSION, Mode=WEIGHTED_RANDOM, FirstDataLine=1, EncodeMode=All);
//nsl_static_var(PLWT, File=StaticFile, Refresh=SESSION, Mode=WEIGHTED_RANDOM, EncodeMode=All);
//nsl_static_var(PLWT:1, File=StaticFile, Refresh=USE, Mode=SEQUENTIAL, FirstDataLine=1, EncodeMode=All);
//nsl_static_var(PLWT:1, File=StaticFile, Refresh=USE, Mode=RANDOM, FirstDataLine=1, EncodeMode=All);
//nsl_static_var(PLWT:1, File=StaticFile, Refresh=USE, Mode=WEIGHTED_RANDOM, FirstDataLine=1, EncodeMode=All);
//nsl_static_var(PLWT:1, File=StaticFile, Refresh=USE, Mode=UNIQUE, FirstDataLine=1, EncodeMode=All);
//nsl_static_var(PLWT:1, File=StaticFile, Refresh=USE, Mode=USE_ONCE, FirstDataLine=1, EncodeMode=All);

