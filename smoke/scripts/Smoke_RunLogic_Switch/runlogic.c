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
extern FlowReturn Reservation();
extern FlowReturn Tours();
// End - List of used flows in the runlogic

void runlogic()
{
    NSDL2_RUNLOGIC(NULL, NULL, "Executing init_script()");

    init_script();

    NSDL2_RUNLOGIC(NULL, NULL, "Executing switch block - Switch. NS Variable = switch_var");
    {

        NSDL2_RUNLOGIC(NULL, NULL, "NS Variable value for block - Switch = %d", ns_get_int_val("switch_var"));
        switch(ns_get_int_val("switch_var"))
        {
            case 0:
                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoginLogout (case value = 0)");
                LoginLogout();
                break;
            case 1:
                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Passenger (case value = 1)");
                Passenger();
                break;
            case -2:
                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Reservation (case value = -2)");
                Reservation();
                break;
            default:
                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Tours (case value = -1)");
                Tours();
                break;
        }
    }

    NSDL2_RUNLOGIC(NULL, NULL, "Executing ns_exit_session()");
    ns_exit_session();
}
