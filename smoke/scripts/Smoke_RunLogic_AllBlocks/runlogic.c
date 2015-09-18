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
extern FlowReturn FlowSwitch();
extern FlowReturn Reservation();
extern FlowReturn Tours();
extern FlowReturn FlowWhile();
extern FlowReturn FlowDoWhile();
// End - List of used flows in the runlogic

int weight = %weight_value;
int min =  %min_value;
int max = %max_value;
int per1 = %per_value1;
int per2 = %per_value2;

void runlogic()
{
    NSDL2_RUNLOGIC(NULL, NULL, "Executing init_script()");

    init_script();

    NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - Parent");
    {

        NSDL2_RUNLOGIC(NULL, NULL, "Executing dowhile block - DoWhileBlock. NS Variable = var_dowhile");
        {

            NSDL2_RUNLOGIC(NULL, NULL, "NS Variable value for block - DoWhileBlock = %d", ns_get_int_val("var_dowhile"));
            do
            {

                NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - Seq1");
                {

                    NSDL2_RUNLOGIC(NULL, NULL, "Executing weight block - Weight");
                    {
                        //int Weightweight = ns_get_random_number_int(1, 100);
                        int Weightweight = ns_get_random_number_int(1, weight);

                        NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Weight = %d", Weightweight);

                        //if(Weightweight <= 100)
                        if(Weightweight <= weight)
                        {

                            NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Percentage (wt value = 100)");
                            {
                                //int Percentagepercent = ns_get_random_number_int(1, 100);
                                int Percentagepercent = ns_get_random_number_int(1, per1+per2);

                                NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Percentage = %d", Percentagepercent);

                                //if(Percentagepercent <= 50)
                                if(Percentagepercent <= per1)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoginLogout (pct value = 50%)");
                                    LoginLogout();
                                }
                                //else if(Percentagepercent <= 100)
                                else if(Percentagepercent <= per1+per2)
                                {

                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing count block - Count. Min = 1, Max = 1 (pct value = 50%)");
                                    {
                                        //int CountCount = ns_get_random_number_int(1, 1);
                                        int CountCount = ns_get_random_number_int(min, max);
                                        int CountLoop;
                                         for(CountLoop = 1; CountLoop <= CountCount; CountLoop++)
                                        {

                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing while block - while. NS Variable = var_while (pct value = 50%), SelectedCount = %d, Iteration = %d",CountCount, CountLoop);
                                            {

                                                NSDL2_RUNLOGIC(NULL, NULL, "NS Variable value for block - while = %d", ns_get_int_val("var_while"));
                                                while(ns_get_int_val("var_while"))
                                                {

                                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - SeqW (pct value = 50%), SelectedCount = %d, Iteration = %d",CountCount, CountLoop);
                                                    {

                                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing switch block - Switch. NS Variable = var_switch (pct value = 50%), SelectedCount = %d, Iteration = %d",CountCount, CountLoop);
                                                        {

                                                            NSDL2_RUNLOGIC(NULL, NULL, "NS Variable value for block - Switch = %d", ns_get_int_val("var_switch"));
                                                            switch(ns_get_int_val("var_switch"))
                                                            {
                                                                case 0:

                                                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - Seq2 (case value = 0), SelectedCount = %d, Iteration = %d",CountCount, CountLoop);
                                                                    {
                                                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Passenger");
                                                                        Passenger();
                                                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - FlowSwitch");
                                                                        FlowSwitch();
                                                                    }
                                                                    break;
                                                                case 1:

                                                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - Seq3 (case value = 1)");
                                                                    {
                                                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Reservation");
                                                                        Reservation();
                                                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - FlowSwitch");
                                                                        FlowSwitch();
                                                                    }
                                                                    break;
                                                                case 2:

                                                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - Seq4 (case value = 2)");
                                                                    {
                                                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoginLogout");
                                                                        LoginLogout();
                                                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - FlowSwitch");
                                                                        FlowSwitch();
                                                                    }
                                                                    break;
                                                                default:

                                                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - Seq5 (case value = -1)");
                                                                    {
                                                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Tours");
                                                                        Tours();
                                                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - FlowSwitch");
                                                                        FlowSwitch();
                                                                    }
                                                                    break;
                                                            }
                                                        }
                                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - FlowWhile");
                                                        FlowWhile();
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - FlowDoWhile");
                    FlowDoWhile();
                }
            } while(ns_get_int_val("var_dowhile"));
        }
    }

    NSDL2_RUNLOGIC(NULL, NULL, "Executing ns_exit_session()");
    ns_exit_session();
}
