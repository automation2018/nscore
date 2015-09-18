#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"


extern int init_script();
extern int exit_script();

typedef void FlowReturn;

// Note: Following extern declaration is used to find the list of used flows. Do not delete/edit it
// Start - List of used flows in the runlogic
extern FlowReturn authc();
extern FlowReturn authorizeBillPay();
extern FlowReturn authorizeICT();
extern FlowReturn authorizePhoneEnrollment();
extern FlowReturn default_flow();
// End - List of used flows in the runlogic


void runlogic()
{
    NSDL2_RUNLOGIC(NULL, NULL, "Executing init_script()");

    init_script();

    NSDL2_RUNLOGIC(NULL, NULL, "Executing while block - MorePages. NS Variable = cav_replay_more_pages");
    {

        NSDL2_RUNLOGIC(NULL, NULL, "NS Variable value for block - MorePages = %d", ns_get_int_val("cav_replay_more_pages"));
        while(ns_get_int_val("cav_replay_more_pages"))
        {

            NSDL2_RUNLOGIC(NULL, NULL, "Executing switch block - NextPages. NS Variable = cav_replay_page_id");
            {

                NSDL2_RUNLOGIC(NULL, NULL, "NS Variable value for block - NextPages = %d", ns_get_int_val("cav_replay_page_id"));
                switch(ns_get_int_val("cav_replay_page_id"))
                {
                    case 0:
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - authc (case value = 0)");
                        authc();
                        break;
                    case 1:
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - authorizeBillPay (case value = 1)");
                        authorizeBillPay();
                        break;
                    case 2:
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - authorizeICT (case value = 2)");
                        authorizeICT();
                        break;
                    case 3:
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - authorizePhoneEnrollment (case value = 3)");
                        authorizePhoneEnrollment();
                        break;
                    default:
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - default_flow (case value = -1)");
                        default_flow();
                        break;
                }
            }
        }
    }

    NSDL2_RUNLOGIC(NULL, NULL, "Executing ns_exit_session()");
    ns_exit_session();
}
