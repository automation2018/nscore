#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow2()
{
    ns_smtp_send ("smtp_session",
	"SMTP_SERVER=websrv.cavisson.com",
	"USER_ID=%type",
	"PASSWORD=%rr_type",
	"FROM_EMAIL=%name",
	"TO_EMAILS=dl-qa-auto@cavisson.com",
	"CC_EMAILS=vishal.singhal@cavisson.com",
	"BCC_EMAILS=ranjeet.kumar@cavisson.com",
	"SUBJECT=SMTP smoke test Mail",
	"BODY=Hello, You got this mail from smoke SMTP testcase run",
	"HEADER=X-Priority:3",
	"MESSAGE_COUNT=1"
    );
}
