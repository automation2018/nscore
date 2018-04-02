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
extern FlowReturn Passenger();
// End - List of used flows in the runlogic
int per1 = %per_value1;
int per2 = %per_value2;

void runlogic()
{
    NSDL2_RUNLOGIC(NULL, NULL, "Executing init_script()");

    init_script();

    NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Percentage");
    {
        //int Percentagepercent = ns_get_random_number_int(1, 100);
        int Percentagepercent = ns_get_random_number_int(1,per1+per2);

        NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Percentage = %d", Percentagepercent);

        //if(Percentagepercent <= 70)
        if(Percentagepercent <= per1)
        {
            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoginLogout (pct value = 70%)");
            LoginLogout();
        }
        //else if(Percentagepercent <= 100)
        else if(Percentagepercent <= per1+per2)
        {
            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Passenger (pct value = 30%)");
            Passenger();
        }
    }

    NSDL2_RUNLOGIC(NULL, NULL, "Executing ns_exit_session()");
    ns_exit_session();
}
