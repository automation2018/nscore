nsl_search_var(dynamic1, PAGE=page1, LB="<title>", RB="</title>", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(dummy_tx, PAGE=dummy, LB="<input type=text name=", RB=" value='' size=12>", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(dynamic2, PAGE=page2, LB="<title>", RB="</title>", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(dynamic3, PAGE=page3, LB="<title>", RB="</title>", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_random_string_var(random, Min=5, Max=10, CharSet="a-zA-Z0-9", Refresh=SESSION);
