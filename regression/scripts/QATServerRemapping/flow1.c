#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow1()
{

    ns_setup_save_url(1,1,"first_host");
    ns_web_url("page1_html",
        "METHOD=GET",
        "URL=http://127.0.0.1/Remapping_test/page1.html"
    );

    ns_force_server_mapping (NULL, NULL);
    ns_web_url("page2_html",
        "METHOD=GET",
        "URL=http://127.0.0.1/Remapping_test/page2.html"
    );

    ns_setup_save_url(1,0,"last_host");
    ns_web_url("page3_html",
        "METHOD=GET",
        "URL=http://127.0.0.1/Remapping_test/page3.html"
    );

//ns_force_server_mapping ("192.168.1.64:81","192.168.1.35:81");
    ns_web_url("page4_html",
        "METHOD=GET",
        "URL=http://192.168.1.64:81/Remapping_test/page13.html"
    );

    ns_setup_save_url(1,5,"fifth_host");
    ns_web_url("page5_html",
        "METHOD=GET",
        "URL=http://127.0.0.1/Remapping_test/page2.html"
    );

//ns_force_server_mapping ("192.168.1.72", NULL);
    ns_web_url("page6_html",
        "METHOD=GET",
        "URL=http://192.168.1.64:81/Remapping_test/page14.html"
    );
}


