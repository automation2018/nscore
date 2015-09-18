#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"


extern int init_script();
extern int exit_script();

typedef void FlowReturn;

// Note: Following extern declaration is used to find the list of used flows. Do not delete/edit it
// Start - List of used flows in the runlogic
extern FlowReturn Home();
extern FlowReturn Browse();
extern FlowReturn ViewProductDetail();
extern FlowReturn Abandonment();
extern FlowReturn AddToBag();
extern FlowReturn SearchKeyword();
extern FlowReturn ProductSelectionStart();
extern FlowReturn RefineSearch();
extern FlowReturn PerformPagination();
extern FlowReturn SortProducts();
extern FlowReturn ChangeView();
extern FlowReturn ProductSelectionEnd();
extern FlowReturn SearchProductId();
extern FlowReturn CheckOut();
extern FlowReturn UpdateItem();
extern FlowReturn RegCheckOut();
extern FlowReturn UnRegCheckOut();
// End - List of used flows in the runlogic


void runlogic()
{
    NSDL2_RUNLOGIC(NULL, NULL, "Executing init_script()");

    init_script();

    NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - Start");
    {
        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Home");
        Home();

        NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - ProductAdddedBlock");
        {
            int ProductAdddedBlockpercent = ns_get_random_number_int(1, 100);

            NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - ProductAdddedBlock = %d", ProductAdddedBlockpercent);

            if(ProductAdddedBlockpercent <= 0)
            {

                NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - BrowseBlock (pct value = 0%)");
                {
                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Browse");
                    Browse();
                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - ViewProductDetail");
                    ViewProductDetail();

                    NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Block1 (pct value = 0%)");
                    {
                        int Block1percent = ns_get_random_number_int(1, 100);

                        NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Block1 = %d", Block1percent);

                        if(Block1percent <= 0)
                        {
                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Abandonment (pct value = 0%)");
                            Abandonment();
                        }
                        else if(Block1percent <= 100)
                        {
                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - AddToBag (pct value = 100%)");
                            AddToBag();
                        }
                    }
                }
            }
            else if(ProductAdddedBlockpercent <= 100)
            {

                NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - SearchKeywordBlock (pct value = 100%)");
                {
                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - SearchKeyword");
                    SearchKeyword();

                    NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - ProductSelection (pct value = 100%)");
                    {
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - ProductSelectionStart");
                        ProductSelectionStart();
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - RefineSearch");
                        RefineSearch();
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - PerformPagination");
                        PerformPagination();
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - SortProducts");
                        SortProducts();
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - ChangeView");
                        ChangeView();
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - ProductSelectionEnd");
                        ProductSelectionEnd();
                    }

                    NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Block2 (pct value = 100%)");
                    {
                        int Block2percent = ns_get_random_number_int(1, 100);

                        NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Block2 = %d", Block2percent);

                        if(Block2percent <= 0)
                        {
                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Abandonment (pct value = 0%)");
                            Abandonment();
                        }
                        else if(Block2percent <= 100)
                        {
                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - ViewProductDetail (pct value = 100%)");
                            ViewProductDetail();
                        }
                    }

                    NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Block2A (pct value = 100%)");
                    {
                        int Block2Apercent = ns_get_random_number_int(1, 100);

                        NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Block2A = %d", Block2Apercent);

                        if(Block2Apercent <= 0)
                        {
                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Abandonment (pct value = 0%)");
                            Abandonment();
                        }
                        else if(Block2Apercent <= 100)
                        {
                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - AddToBag (pct value = 100%)");
                            AddToBag();
                        }
                    }
                }
            }
            else if(ProductAdddedBlockpercent <= 100)
            {

                NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - SearchPIDBlock (pct value = 0%)");
                {
                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - SearchProductId");
                    SearchProductId();

                    NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Block3 (pct value = 0%)");
                    {
                        int Block3percent = ns_get_random_number_int(1, 100);

                        NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Block3 = %d", Block3percent);

                        if(Block3percent <= 0)
                        {
                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Abandonment (pct value = 0%)");
                            Abandonment();
                        }
                        else if(Block3percent <= 100)
                        {
                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - AddToBag (pct value = 100%)");
                            AddToBag();
                        }
                        else if(Block3percent <= 100)
                        {

                            NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - Block3A (pct value = 0%)");
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Browse");
                                Browse();
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - ViewProductDetail");
                                ViewProductDetail();

                                NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Block3B (pct value = 0%)");
                                {
                                    int Block3Bpercent = ns_get_random_number_int(1, 100);

                                    NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Block3B = %d", Block3Bpercent);

                                    if(Block3Bpercent <= 0)
                                    {
                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Abandonment (pct value = 0%)");
                                        Abandonment();
                                    }
                                    else if(Block3Bpercent <= 100)
                                    {
                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - AddToBag (pct value = 100%)");
                                        AddToBag();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - CheckOutBlock");
        {
            int CheckOutBlockpercent = ns_get_random_number_int(1, 100);

            NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - CheckOutBlock = %d", CheckOutBlockpercent);

            if(CheckOutBlockpercent <= 100)
            {
                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - CheckOut (pct value = 100%)");
                CheckOut();
            }
            else if(CheckOutBlockpercent <= 100)
            {
                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Abandonment (pct value = 0%)");
                Abandonment();
            }
            else if(CheckOutBlockpercent <= 100)
            {

                NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - EditandCheckOutBlock (pct value = 0%)");
                {
                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - UpdateItem");
                    UpdateItem();
                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - CheckOut");
                    CheckOut();
                }
            }
        }

        NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - PlaceOrderBlock");
        {
            int PlaceOrderBlockpercent = ns_get_random_number_int(1, 100);

            NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - PlaceOrderBlock = %d", PlaceOrderBlockpercent);

            if(PlaceOrderBlockpercent <= 0)
            {
                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Abandonment (pct value = 0%)");
                Abandonment();
            }
            else if(PlaceOrderBlockpercent <= 0)
            {
                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - RegCheckOut (pct value = 0%)");
                RegCheckOut();
            }
            else if(PlaceOrderBlockpercent <= 100)
            {
                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - UnRegCheckOut (pct value = 100%)");
                UnRegCheckOut();
            }
        }
    }

    NSDL2_RUNLOGIC(NULL, NULL, "Executing ns_exit_session()");
    ns_exit_session();
}
