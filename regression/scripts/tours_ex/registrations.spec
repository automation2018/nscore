nsl_decl_var(WebFind_Count);

nsl_decl_var(buffer);

nsl_decl_var(RepSize_Retvar);
nsl_search_var(Pagename, PAGE=index_html, LB="Welcome to the Mercury Tours website.  To make",RB="please enter your account information to the", ORD=1, SaveOffset=1, SaveLen=11, Convert= HTMLToURL, ActionOnNotFound= Warning);

nsl_static_var(Username,Password, FILE=Userpass.dat, REFRESH=SESSION, MODE=SEQUENTIAL, VAR_VALUE=F1=value);

nsl_static_var(passenger_names, FILE=final.dat, REFRESH=SESSION, MODE=SEQUENTIAL, VAR_VALUE=F1=value);

nsl_static_var(DepCity,DepDate,ArrCity,RetDate,NumPass,SeatPref,SeatType, FILE=UserDetails.dat, REFRESH=SESSION, MODE=SEQUENTIAL, VAR_VALUE=F1=value);

nsl_web_find(TEXT="Welcome to the Mercury", PAGE=index_html, FAIL = NOTFOUND, ID="Text not found", SaveCount=WebFind_Count,ActionOnFail= Continue);

nsl_web_find(TextPfx="Using the menu to the left", TextSfx="you can search for new", PAGE=login, FAIL = NOTFOUND, ID="Text not found",SaveCount=WebFind_Count,ActionOnFail= Continue);

nsl_web_find(TEXT/RE="Departure City*", PAGE=reservation, FAIL = NOTFOUND, ID="Text not found", SaveCount=WebFind_Count,ActionOnFail= Continue);

nsl_web_find(TextPfx/RE/IC="Flight Departing From*", TextSfx="on", PAGE=findflight, FAIL = NOTFOUND, ID="Text not found", SaveCount=WebFind_Count,ActionOnFail= Continue);

nsl_web_find(TextPfx/RE/IC="Method of paymen?t", TextSfx/RE/IC="cred+it card", PAGE=findflight_2, FAIL = NOTFOUND, ID="Text not found", SaveCount=WebFind_Count,ActionOnFail= Continue);

nsl_web_find(TextPfx="Your reservation", TextSfx/RE/IC="Confirmed*", PAGE=findflight_3, FAIL = NOTFOUND, ID="Text not found", SaveCount=WebFind_Count,ActionOnFail= Continue);

nsl_web_find(TEXT/RE/IC="Please enter your account Informatio+n to the", PAGE=welcome, FAIL = NOTFOUND, ID="Text not found", SaveCount=WebFind_Count,ActionOnFail= Continue);

nsl_check_reply_size(MODE=NotBetweenMinMax, Value1=100, Value2=110, PAGE=findflight, Action=Continue, VAR=RepSize_Retvar);
