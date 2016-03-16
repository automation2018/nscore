#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow1()
{
    ns_smtp_send ("smtp_session",
	"SMTP_SERVER=127.0.0.1",
	"USER_ID=amit.sharma@cavisson.com",
	"PASSWORD=compass",
	"FROM_EMAIL=soujanya@cavisson.com",
	"TO_EMAILS=testing@cavisson.com",
	"CC_EMAILS=tanmay@cavisson.com,amit.sharma@cavisson.com",
	"BCC_EMAILS=sanjeev@cavisson.com,jitendra@cavisson.com",
	"SUBJECT=SMTP test Mail",
	"BODY=Hello you are invited to the annual event",
	"HEADER=X-Priority:3",
	"MESSAGE_COUNT=1"
    );
}
