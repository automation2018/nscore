#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"


extern int init_script();
extern int exit_script();

typedef void FlowReturn;

// Note: Following extern declaration is used to find the list of used flows. Do not delete/edit it
// Start - List of used flows in the runlogic
extern FlowReturn Trans_findflight();
extern FlowReturn Trans_login();
extern FlowReturn Trans_reservation();
extern FlowReturn Trans_welcome();
extern FlowReturn Trans_index();
extern FlowReturn default_flow();
// End - List of used flows in the runlogic


void runlogic()
{
    NSDL2_RUNLOGIC(NULL, NULL, "Executing init_script()");

    init_script();

    NSDL2_RUNLOGIC(NULL, NULL, "Executing while block - MorePages. NS Variable = cav_replay_more_pages:0:>");
    {

        NSDL2_RUNLOGIC(NULL, NULL, "NS Variable value for block - MorePages = %d", ns_get_int_val("cav_replay_more_pages"));
        while(ns_get_int_val("cav_replay_more_pages") > 0)
        {

            NSDL2_RUNLOGIC(NULL, NULL, "Executing switch block - NextPages. NS Variable = cav_replay_page_id");
            {

                NSDL2_RUNLOGIC(NULL, NULL, "NS Variable value for block - NextPages = %d", ns_get_int_val("cav_replay_page_id"));
                switch(ns_get_int_val("cav_replay_page_id"))
                {
                    case 0:
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Trans_findflight (case value = 0)");
                        Trans_findflight();
                        break;
                    case 1:
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Trans_login (case value = 1)");
                        Trans_login();
                        break;
                    case 2:
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Trans_reservation (case value = 2)");
                        Trans_reservation();
                        break;
                    case 3:
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Trans_welcome (case value = 3)");
                        Trans_welcome();
                        break;
                    case 4:
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Trans_index (case value = 4)");
                        Trans_index();
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
