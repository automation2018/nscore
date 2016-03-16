#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow1()
{
ns_pop_stat("stat_email",
                 "POP_SERVER=127.0.0.1",
                 "USER_ID={id}@{dom}.com",
                 "PASSWORD={pass}"
           );
ns_pop_list("list_email",
                 "POP_SERVER=127.0.0.1",
                 "USER_ID={id}@{dom}.com",
                 "PASSWORD={pass}"
           );
ns_pop_get("get_email",
                 "POP_SERVER=127.0.0.1",
                 "USER_ID={id}@{dom}.com",
                 "PASSWORD={pass}"
           );
}
