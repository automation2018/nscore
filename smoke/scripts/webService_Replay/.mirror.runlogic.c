#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"


extern int init_script();
extern int exit_script();

typedef void FlowReturn;

// Note: Following extern declaration is used to find the list of used flows. Do not delete/edit it
// Start - List of used flows in the runlogic
extern FlowReturn aut_h_201_2();
extern FlowReturn auth_2_12_MissingIndex();
extern FlowReturn auth_2012();
extern FlowReturn auth_2012_MissingIndex();
extern FlowReturn au_th_2012();
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
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - aut_h_201_2 (case value = 0)");
                        aut_h_201_2();
                        break;
                    case 1:
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - auth_2_12_MissingIndex (case value = 1)");
                        auth_2_12_MissingIndex();
                        break;
                    case 2:
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - auth_2012 (case value = 2)");
                        auth_2012();
                        break;
                    case 3:
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - auth_2012_MissingIndex (case value = 3)");
                        auth_2012_MissingIndex();
                        break;
                    case 4:
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - au_th_2012 (case value = 4)");
                        au_th_2012();
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
