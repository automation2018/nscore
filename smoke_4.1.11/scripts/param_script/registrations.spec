//nsl_web_find(TEXT="Find Flights", PAGE=Booking, FAIL=NOTFOUND, ID="Text string is  not found", ActionOnFail=STOP);
//nsl_web_find(TEXT="Welcome to Mercury Tours", PAGE=Login, FAIL=NOTFOUND, ID="Text string is not found", ActionOnFail=STOP);
//nsl_web_find(TEXT="Mercury Tours", PAGE=Home, FAIL=NOTFOUND, ID="Text string is not found", ActionOnFail=STOP);
//nsl_web_find(TEXT="Search Results", PAGE=Searchflight, FAIL=NOTFOUND, ID="Text String is not found", ActionOnFail=STOP);
//nsl_web_find(TEXT="Method of Payment", PAGE=Searchflight2, FAIL=NOTFOUND, ID="Text string is not found", ActionOnFail=STOP);
//nsl_web_find(TextPfx="<title>", TextSfx="</title>", PAGE=Searchflight3, FAIL=NOTFOUND, ID="Text string is not found", ActionOnFail=STOP);
//nsl_web_find(TextPfx="<title>", TextSfx="</title>", PAGE=Logout, FAIL=NOTFOUND, ID="Text string is not found", ActionOnFail=STOP);
////nsl_web_find(TEXT/RE="Mercury*", PAGE=Login, FAIL=NOTFOUND, ID="string is not found", ActionOnFail=STOP);
//
//nsl_static_var(UnameFP:1,UpassFP:2, File=LoginData, Refresh=SESSION, Mode=USE_ONCE, FirstDataLine=2, EncodeMode=All);
//nsl_static_var(ArrivalcityFP:1,DeparturecityFP:2,File=CityData, Refresh=SESSION, Mode=SEQUENTIAL, FirstDataLine=2, EncodeMode=All);
//nsl_static_var(SeatFP:1, File=SeatData, Refresh=SESSION, Mode=SEQUENTIAL, FirstDataLine=2, EncodeMode=All);
//nsl_static_var(Seat_typesFP:1, File=Seat_Types, Refresh=SESSION, Mode=SEQUENTIAL, FirstDataLine=2, EncodeMode=All);
//nsl_static_var(FirstnameFP:1,LastnameFP:2,AddressFP:3,ZipFP:4,PassengernameFP:5,File=Passenger_Details, Refresh=SESSION, Mode=SEQUENTIAL, FirstDataLine=2, EncodeMode=All);
//
//nsl_date_var(Date, Format="%m/%d/%Y", Refresh=SESSION);
//nsl_date_var(ExpDate, Format="%m/%d/%Y", Offset=730.00:00:00, Refresh=SESSION);
//nsl_unique_number_var(CreditcardUN, Format=%09lu, Refresh=SESSION);
nsl_random_number_var(PassengernoRN, Max=1000, Format=%05lu, Refresh=%REFRESH_MODE);
//nsl_static_var(FlightInfoFP:1,FlightDetailsFP:2, File=FlightDetail, Refresh=SESSION, Mode=SEQUENTIAL, EncodeMode=All);
//nsl_search_var(SessionIdSP, PAGE=Home, LB="value=", RB=">", SaveOffset=0, RETAINPREVALUE="NO", EncodeMode=None);
