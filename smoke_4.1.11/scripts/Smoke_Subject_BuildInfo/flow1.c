#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"



void flow1()
{
    
ns_smtp_send ("smtp_session",
	"SMTP_SERVER=websrv.cavisson.com",
	"USER_ID=arun.yadav@cavisson.com",
	"PASSWORD=Cavisson!",
	"FROM_EMAIL=arun.yadav@cavisson.com",
	"TO_EMAILS=neeraj@cavisson.com",
        "CC_EMAILS=achint.agarwal@cavisson.com, shalu.panwar@cavisson.com, manmeet.singh@cavisson.com, ankur.srivastava@cavisson.com, arun.yadav@cavisson.com, ankur.mishra@cavisson.com, arun.goel@cavisson.com, ritesh.sharma@cavisson.com, sudhir.gupta@cavisson.com", 
	"SUBJECT=Smoke Automation started in NetStorm:VERSION 3.9.2.SysBuild 24 on Fc9 server",
	"BODY=Smoke AutoMation Started",
	"MESSAGE_COUNT=1"
    );
}
