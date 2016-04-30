#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void TxCVarBasedName()
{ 
    int url_status = %URLStatus; // 1xx, 2xx, 3xx, 4xx, 5xx
    double pg_think_time = %PgThinkTime; // page think time in seconds
    int tx_status = %TxStatus;
    int get_tx_time, end_tx_status;

    int TxIdToRun = %TxId;	
    char *tx_name1 = "Login";
    char *tx_name2 = "Home";
    char *tx_name3 = "FindFlight";
    char *tx_name4 = "Reservation";
    char *tx_name_to_run;

    ns_define_transaction("Login");
    ns_define_transaction("Home");
    ns_define_transaction("FindFlight");
    ns_define_transaction("Reservation");

    if (TxIdToRun == 1)
    {
        tx_name_to_run = tx_name1;
        ns_start_transaction(tx_name1);
    }
    else if (TxIdToRun == 2)
    {
        tx_name_to_run = tx_name2;
        ns_start_transaction(tx_name2);
    }
    else if (TxIdToRun == 3)
    {
        tx_name_to_run = tx_name3;
        ns_start_transaction(tx_name3);
    }
    else
    {
        tx_name_to_run = tx_name4;
        ns_start_transaction(tx_name4);
    }


    ns_web_url("page1", 
        "URL=http://127.0.0.1/tours/index.html"
    );

    ns_page_think_time(pg_think_time);
    get_tx_time = ns_get_transaction_time(tx_name_to_run);
    end_tx_status = ns_end_transaction(tx_name_to_run, tx_status);
}
