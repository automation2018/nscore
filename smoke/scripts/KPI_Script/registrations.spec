//nsl_search_var(s2, PAGE=index, LB="<add>", RB="</add>", EncodeMode=ALL, Convert= HtmlToText);
//nsl_decl_var(s3);
//nsl_decl_var(s1);
//nsl_decl_var(s3);
//nsl_decl_var(s4);
//nsl_decl_var(s5);


//nsl_search_var(s2, PAGE=index, LB="<add>", RB="</add>", EncodeMode=Specified, CharsToEncode="#");
//nsl_search_var(s2, PAGE=login2_html, LB="st", Search=VARIABLE, VAR=s1, EncodeMode=Specified, CharsToEncode="&");
//nsl_search_var(s1, PAGE=index_html, LB="expires", RB="09:03:15");
//nsl_search_var(s2, PAGE=index_html, LB="expires", RB="09:03:15", SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
//nsl_json_var(json, PAGE=index_html, OBJECT_PATH="root[1].name", ORD=1, SaveOffset=0, EncodeMode=None);
//nsl_json_var(json, PAGE=*, OBJECT_PATH="r.children.categories.children.categories.children.categories.properties.iteminfo.metainfo.title", ORD=1, SaveOffset=0, ActionOnNotFound=Error);
//nsl_json_var(j1, PAGE=login_html, PAGE=login_html, OBJECT_PATH="root.");
//nsl_json_var(j2, PAGE=login_html, OBJECT_PATH="root.expires", SaveOffset=0, EncodeMode=None, RedirectionDepth=3,ActionOnNotFound=Error);
//nsl_json_var(j3, PAGE=index_html, OBJECT_PATH="root.children.categories.name", SaveOffset=0,ORD=ALL, EncodeMode=None);
//nsl_json_var(j4, PAGE=index_html, OBJECT_PATH="root.children.categories[name = For the Home].children.categories[0].name", SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
//nsl_xml_var(XML_P, PAGE=index_html, NODE=<vin><entries><request><cookies><name>, VALUE=<>, ORD=3, EncodeMode=None);
//nsl_xml_var(XML_P2, PAGE=index_html, NODE=<vin><entries><request><cookies><name>, VALUE=<123>, ORD=1, EncodeMode=None);
//nsl_static_var(abc, File=file1, Refresh=SESSION, Mode=USE_ONCE, OnUseOnceError=ABORTPAGE , EncodeMode=All);
//nsl_static_var(abc, File=file1, Refresh=SESSION, Mode=USE_ONCE, OnUseOnceError=ABORTPAGE , EncodeMode=All);
//nsl_static_var(abc, File=file1, Refresh=SESSION, Mode=USE_ONCE, OnUseOnceError=ABORTPAGE , EncodeMode=All);
//nsl_static_var(abc, File=file1, Refresh=SESSION, Mode=USE_ONCE, OnUseOnceError=ABORTTEST, EncodeMode=All);
//nsl_static_var(abc, File=file1, Refresh=USE, Mode=SEQUENTIAL, EncodeMode=All);
//nsl_static_var(retailerUserId_FP:1,firstName_FP:2,lastName_FP:3,email_FP:4,checkSum_FP:5, File=Details.txt, Refresh=SESSION, Mode=SEQUENTIAL, EncodeMode=All, EncodeSpaceBy=%20);
