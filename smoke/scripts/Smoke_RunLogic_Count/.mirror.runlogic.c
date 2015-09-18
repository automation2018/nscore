#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"


extern int init_script();
extern int exit_script();

typedef void FlowReturn;

// Note: Following extern declaration is used to find the list of used flows. Do not delete/edit it
// Start - List of used flows in the runlogic
extern FlowReturn LoginLogout();
// End - List of used flows in the runlogic


void runlogic()
{
    NSDL2_RUNLOGIC(NULL, NULL, "Executing init_script()");

    init_script();

    NSDL2_RUNLOGIC(NULL, NULL, "Executing count block - Count. Min = 1, Max = 2");
    {
        int CountCount = ns_get_random_number_int(1, 2);
        int CountLoop;
         for(CountLoop = 1; CountLoop <= CountCount; CountLoop++)
        {
            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoginLogout");
            LoginLogout();
        }
    }

    NSDL2_RUNLOGIC(NULL, NULL, "Executing ns_exit_session()");
    ns_exit_session();
}
