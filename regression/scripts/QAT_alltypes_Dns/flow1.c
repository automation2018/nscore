#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow1()
{
ns_dns_query("get_hostbyName",
                 "DNS_SERVER_IP=127.0.0.1",
                 "TYPE=A",
                 "ASSERT_RR_TYPE=A",
                 "ASSERT_RR_DATA=10.10.10.10",
		 "NAME=www.yahoo.com"
);
ns_dns_query("get_hostbyName_2",
                 "DNS_SERVER_IP=127.0.0.1",
                 "TYPE=AAAA",
                 "ASSERT_RR_TYPE=AAAA",
                 "NAME=www.yahoo.com"
);
ns_dns_query("get_hostbyName_3",
                 "DNS_SERVER_IP=127.0.0.1",
                 "TYPE=MX",
                 "ASSERT_RR_TYPE=MX",
                 "NAME=www.yahoo.com"
);
ns_dns_query("get_hostbyName_4",
                 "DNS_SERVER_IP=127.0.0.1",
                 "TYPE=NS",
                 "ASSERT_RR_TYPE=NS",
                 "ASSERT_RR_DATA=www.l.yahoo.com",
                 "NAME=www.yahoo.com"
);
ns_dns_query("get_hostbyName_5",
                 "DNS_SERVER_IP=127.0.0.1",
                 "TYPE=SOA",
                 "ASSERT_RR_TYPE=SOA",
                 "NAME=www.yahoo.com"
);
ns_dns_query("get_hostbyName_6",
                 "DNS_SERVER_IP=127.0.0.1",
                 "TYPE=PTR",
                 "ASSERT_RR_TYPE=PTR",
                 "ASSERT_RR_DATA=100 abc.yahoo.com",
                 "NAME=www.yahoo.com"
);
ns_dns_query("get_hostbyName_7",
                 "DNS_SERVER_IP=127.0.0.1",
                 "TYPE=CNAME",
                 "ASSERT_RR_TYPE=CNAME",
                 "ASSERT_RR_DATA=abc.1.yahoo.com",
                 "NAME=www.yahoo.com"
);
}

