//nsl_static_var(user:1,pass:2, File=param2, Refresh=USE, Mode=UNIQUE, EncodeMode=All);
//nsl_static_var(name:2, File=weighted_file, Refresh=USE, Mode=WEIGHTED_RANDOM, EncodeMode=All);
//nsl_static_var(user:1,pass:2, File=param2, Refresh=USE, Mode=SEQUENTIAL, EncodeMode=All);
//nsl_static_var(user:1,pass:2, File=param2, Refresh=USE, Mode=RANDOM, EncodeMode=All);
//nsl_static_var(user:1,pass:2, File=param2, Refresh=USE, Mode=USE_ONCE, EncodeMode=All, OnUseOnceError=ABORTSESSION);


nsl_static_var(user:1,pass:2, File=param3, Refresh=SESSION, Mode=SEQUENTIAL, EncodeMode=All);
//nsl_static_var(user:1,pass:2, File=param3, Refresh=%REFRESH, Mode=%MODE, EncodeMode=All);
//nsl_static_var(name:2, File=weighted_file, Refresh=SESSION, Mode=WEIGHTED_RANDOM, EncodeMode=All);
//nsl_static_var(user:1,pass:2, File=param2, Refresh=SESSION, Mode=SEQUENTIAL, EncodeMode=All);
//nsl_static_var(user:1,pass:2, File=param2, Refresh=SESSION, Mode=RANDOM, EncodeMode=All);
//nsl_static_var(user:1,pass:2, File=param2, Refresh=SESSION, Mode=USE_ONCE, EncodeMode=All, OnUseOnceError=ABORTSESSION);
