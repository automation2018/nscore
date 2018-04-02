nsl_static_var(LowRespTime:1, File=SlowResponseTime.csv, Refresh=SESSION, Mode=SEQUENTIAL, EncodeMode=All);
nsl_static_var(LowStatusCode:2, File=SlowStatusCode.csv, Refresh=SESSION, Mode=WEIGHTED_RANDOM, EncodeMode=All);
nsl_static_var(MedRespTime:1, File=MedResponseTime.csv, Refresh=SESSION, Mode=SEQUENTIAL, EncodeMode=All);
nsl_static_var(MedStatusCode:2, File=MedStatusCode.csv, Refresh=SESSION, Mode=WEIGHTED_RANDOM, EncodeMode=All);
nsl_static_var(HighRespTime:1, File=HighResponseTime.csv, Refresh=SESSION, Mode=SEQUENTIAL, EncodeMode=All);
nsl_static_var(HighStatusCode:2, File=HighStatusCode.csv, Refresh=SESSION, Mode=WEIGHTED_RANDOM, EncodeMode=All);
