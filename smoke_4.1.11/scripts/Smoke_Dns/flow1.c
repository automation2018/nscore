#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow1()
{
ns_dns_query("get_hostbyName",
                 "DNS_SERVER_IP=127.0.0.1",
                 "TYPE=%type",
                 "ASSERT_RR_TYPE=%rr_type",
		 "NAME=%name"
);
}
