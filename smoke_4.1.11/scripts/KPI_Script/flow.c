/*-----------------------------------------------------------------------------
    Name: flow
    Recorded By: netstorm
    Date of recording: 11/05/2014 01:03:58
    Flow details:
    Build details: 4.0.1 (build# 4)
    Modification History:
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/epoll.h>
#include "ns_string.h"


int send_req(char *buff, char *response, int sock_fd)
{
  //char buff[4096];
  FILE *fp;
  struct stat fstat;
  int file_size = 0, bytes_write = 0, bytes_read = 0, last_bytes_read = 0, total_bytes_write = 0;
  char *ptr = NULL;

/*  fp = fopen(req_file, "r");
  if (fp == NULL) {
    fprintf(stdout, "Error in opening file :%s\n", req_file);
    return -1;
  }
  else 
  {
    stat(req_file, &fstat);
    file_size = fstat.st_size;
    bytes_read = fread(buff, 1, file_size, fp);
    buff[bytes_read] = '\0';
*/
    //printf("File = [%s], File_size = [%d], bytes_read = [%d], File data = [%s]\n", req_file, file_size, bytes_read, buff);
    file_size = strlen(buff);
    while(file_size > 0) {
    bytes_write = write(sock_fd, buff+total_bytes_write, file_size);
     if(bytes_write == 0){
       //printf("bytes read = 0 for file :[%s] Hence returning\n", req_file);
       //return -1;
     }
     else if(bytes_write < 0){
      fprintf(stdout, "Error: Failed to write for file name :");
       return -1;
     }
     else{
       file_size -= bytes_write;
       total_bytes_write += bytes_write;
       //fprintf(stdout,"read bytes = [%d] Response = [%s]\n", bytes_read, response);
     }
    }
  //}
  while(ptr == NULL) {
     bytes_read = read(sock_fd, buff, 4096);
     if(bytes_read == 0){
       //printf("bytes read = 0 Hence returning\n");
       //return -1;
     }
     else if(bytes_read < 0){
        //fprintf(stdout, "Error in reading Response for file = [%s], Error = [%s]\n", req_file, strerror(errno));
       return -1;
     }
     else{
       buff[bytes_read] = '\0';
       sprintf(response+last_bytes_read, "%s", buff);
       last_bytes_read += bytes_read;
       ptr = strstr(response, "</RESPONSE>");
       //printf("read bytes = [%d] Response = [%s]\n", bytes_read, response);
     }
  }
  response[last_bytes_read] = '\0';
  //fprintf(stdout,"buff = [%s], response = [%s], last_bytes_read = %d\n", buff, response, last_bytes_read);
  return 0;
}

int make_conn(int *sock_fd)
{
  struct sockaddr_in client;
  memset(&client, 0 , sizeof(client));

  *sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (*sock_fd < 0) {
    //perror("ERROR in opening socket");
    fprintf(stdout, "ERROR in opening socket");
    return (-1);
  }

 // efd = epoll_create(10);
  client.sin_family = AF_INET;
  client.sin_addr.s_addr = inet_addr("%serverIP");
  client.sin_port = htons(5003);

  if (connect(*sock_fd, (struct sockaddr *)&client, sizeof(client)) == -1) {
    //perror("ERROR in connect");
    fprintf(stdout, "ERROR in connect");
    return (-1);
  }
return 0;
}

void flow()
{
  int sock_fd;
  char req_file[4096];
  char resp1[4096];
  char output_buffer[4096];


  ns_web_url("tiny",
  "URL=http://127.0.0.1/tiny"

  ); 
  ns_start_transaction("CONNECT");
  int ret1 = make_conn(&sock_fd);
  if(ret1 == -1) {
   fprintf(stdout, "Error in connect\n");
   ns_end_transaction_as("CONNECT", 0, "CONNECT_FAIL");
   return (-1);
  }
  else {
    ns_end_transaction("CONNECT", NS_AUTO_STATUS);
  }

  ns_page_think_time(0.1);
  //Sending req for SESSION_START command

  sprintf(req_file, "<TRANSACTION><FUNCTION_TYPE>SESSION</FUNCTION_TYPE><COMMAND>START</COMMAND><MAC_LABEL>P_109</MAC_LABEL><COUNTER>7</COUNTER><MAC>PXjoBJjE2un7OUgwOEtYSYLDJFgJvXsvH1Veb08CJpY=</MAC><LANE>60</LANE><PURCHASE_ID>17072101150601536</PURCHASE_ID><STORE_NUM>115</STORE_NUM><INVOICE>1536</INVOICE><POS_IP>10.93.5.66</POS_IP><POS_PORT>5012</POS_PORT></TRANSACTION>");
  ns_start_transaction("SESSION_START");
  ret1 = send_req(req_file, resp1, sock_fd);
  if(ret1 == -1) {
   fprintf(stdout, "Error in sending request.\n");
   ns_end_transaction_as("SESSION_START", 0, "SESSION_START_WRITE_FAIL");
   return (-1);
  }
  ns_save_searched_string(NS_ARG_IS_BUF, resp1,  NS_ARG_IS_BUF, output_buffer, "<TERMINATION_STATUS>", "</TERMINATION_STATUS>", 1, NS_FROM_START, NS_SAVE_COMPLETE);
  if (strcmp(output_buffer,"SUCCESS") == 0)
    ns_end_transaction("SESSION_START", NS_AUTO_STATUS);
  else
    ns_end_transaction_as("SESSION_START", 0, "SESSION_START_FAILED");

  ns_page_think_time(5);

  //Sending req for TEST_MAC command
  ns_start_transaction("SECURITY_TEST_MAC");
  sprintf(req_file, "<TRANSACTION><FUNCTION_TYPE>SECURITY</FUNCTION_TYPE><COMMAND>TEST_MAC</COMMAND><MAC_LABEL>P_109</MAC_LABEL><COUNTER>5</COUNTER><MAC>gk30clklCgDzoadcdGcWAS2vRlN2JIpN2qFDa+rYh88=</MAC></TRANSACTION>");
  
  ret1 = send_req(req_file, resp1, sock_fd);
  if(ret1 == -1) {
   ns_end_transaction_as("SECURITY_TEST_MAC", 0, "SECURITY_TEST_MAC_WRITE_FAIL");
   return (-1);
  }
  ns_save_searched_string(NS_ARG_IS_BUF, resp1,  NS_ARG_IS_BUF, output_buffer, "<TERMINATION_STATUS>", "</TERMINATION_STATUS>", 1, NS_FROM_START, NS_SAVE_COMPLETE);  

  if (strcmp(output_buffer,"SUCCESS") == 0) 
    ns_end_transaction("SECURITY_TEST_MAC", NS_AUTO_STATUS);
  else
    ns_end_transaction_as("SECURITY_TEST_MAC", 0, "SECURITY_TEST_MAC_FAILED");
 
  ns_page_think_time(5);    


  //Sending req for DEVICE VERSION command
  ns_start_transaction("DEVICE_VERSION");
  sprintf(req_file, "<TRANSACTION><FUNCTION_TYPE>DEVICE</FUNCTION_TYPE><COMMAND>VERSION</COMMAND><MAC_LABEL>P_109</MAC_LABEL><COUNTER>6</COUNTER><MAC>ADj3iz0FhxknT/BWfq401KRaPzzSq/C9X8tFqfEnRko=</MAC><DISPLAY_VERSION>0</DISPLAY_VERSION></TRANSACTION>");
  
  ret1 = send_req(req_file, resp1, sock_fd);
  if(ret1 == -1) {
      printf("ending txn fo DEVICE_VERSION_FAILED");
   ns_end_transaction_as("DEVICE_VERSION", 0, "DEVICE_VERSION_WRITE_FAIL");
   return (-1);
  }

  ns_save_searched_string(NS_ARG_IS_BUF, resp1,  NS_ARG_IS_BUF, output_buffer, "<TERMINATION_STATUS>", "</TERMINATION_STATUS>", 1, NS_FROM_START, NS_SAVE_COMPLETE);

  if (strcmp(output_buffer,"SUCCESS") == 0)
    ns_end_transaction("DEVICE_VERSION", NS_AUTO_STATUS);
  else
    ns_end_transaction_as("DEVICE_VERSION", 0, "DEVICE_VERSION_FAILED");
  
  ns_page_think_time(5);

  //sending req for LINE_ITEM ADD command 
  ns_start_transaction("LINE_ITEM_ADD");
  sprintf(req_file, "<TRANSACTION><FUNCTION_TYPE>LINE_ITEM</FUNCTION_TYPE><COMMAND>ADD</COMMAND><MAC_LABEL>P_109</MAC_LABEL><COUNTER>9</COUNTER><MAC>9wDM4wO1IGDoYD22nWByVCPsQPAg3KrS8nCp3drdRac=</MAC><RUNNING_SUB_TOTAL>5.10</RUNNING_SUB_TOTAL><RUNNING_TRANS_AMOUNT>5.10</RUNNING_TRANS_AMOUNT><RUNNING_TAX_AMOUNT>0.00</RUNNING_TAX_AMOUNT><LINE_ITEMS><MERCHANDISE><LINE_ITEM_ID>300003</LINE_ITEM_ID><DESCRIPTION>$24.90</DESCRIPTION><FONT_COL_VALUE>FF0000</FONT_COL_VALUE></MERCHANDISE></LINE_ITEMS></TRANSACTION>");
  
  ret1 = send_req(req_file, resp1, sock_fd);
  if(ret1 == -1) {
      printf("ending txn for LINE_ITEM_ADD_WRITE_FAIL");
   ns_end_transaction_as("LINE_ITEM_ADD", 0, "LINE_ITEM_ADD_WRITE_FAIL");
   return (-1);
  }

  ns_save_searched_string(NS_ARG_IS_BUF, resp1,  NS_ARG_IS_BUF, output_buffer, "<TERMINATION_STATUS>", "</TERMINATION_STATUS>", 1, NS_FROM_START, NS_SAVE_COMPLETE);

  if (strcmp(output_buffer,"SUCCESS") == 0)
    ns_end_transaction("LINE_ITEM_ADD", NS_AUTO_STATUS);
  else
    ns_end_transaction_as("LINE_ITEM_ADD", 0, "LINE_ITEM_ADD_FAILED");
    ns_page_think_time(5);


  //sending req for LINE_ITEM OVERRIDE command
  ns_start_transaction("LINE_ITEM_OVERRIDE");
  sprintf(req_file, "<TRANSACTION><FUNCTION_TYPE>LINE_ITEM</FUNCTION_TYPE><COMMAND>OVERRIDE</COMMAND><MAC_LABEL>P_109</MAC_LABEL><COUNTER>12</COUNTER><MAC>gx01qoya2UG9XGqLXrf91bYDhcRyYvrhsFR7NyZXTs4=</MAC><RUNNING_SUB_TOTAL>10.20</RUNNING_SUB_TOTAL><RUNNING_TRANS_AMOUNT>10.20</RUNNING_TRANS_AMOUNT><RUNNING_TAX_AMOUNT>0.00</RUNNING_TAX_AMOUNT><LINE_ITEMS><MERCHANDISE><LINE_ITEM_ID>150000</LINE_ITEM_ID><DESCRIPTION>SPECIAL OFFER 953264685104811</DESCRIPTION><EXTENDED_PRICE>-1.80</EXTENDED_PRICE></MERCHANDISE></LINE_ITEMS></TRANSACTION>");
  
  ret1 = send_req(req_file, resp1, sock_fd);
  if(ret1 == -1) {
      printf("ending txn for LINE_ITEM_OVERRIDE_WRITE_FAIL");
   ns_end_transaction_as("LINE_ITEM_OVERRIDE", 0, "LINE_ITEM_OVERRIDE_WRITE_FAIL");
   return (-1);
  }

  ns_save_searched_string(NS_ARG_IS_BUF, resp1,  NS_ARG_IS_BUF, output_buffer, "<TERMINATION_STATUS>", "</TERMINATION_STATUS>", 1, NS_FROM_START, NS_SAVE_COMPLETE);

  if (strcmp(output_buffer,"SUCCESS") == 0)
    ns_end_transaction("LINE_ITEM_OVERRIDE", NS_AUTO_STATUS);
  else
    ns_end_transaction_as("LINE_ITEM_OVERRIDE", 0, "LINE_ITEM_OVERRIDE_FAILED");
  
  ns_page_think_time(5);

  //sending req for LINE_ITEM REMOVE command
  ns_start_transaction("LINE_ITEM_REMOVE"); 
  sprintf(req_file, "<TRANSACTION><FUNCTION_TYPE>LINE_ITEM</FUNCTION_TYPE><COMMAND>REMOVE</COMMAND><MAC_LABEL>P_109</MAC_LABEL><COUNTER>13</COUNTER><MAC>Zz5o7CzRF9KCNCRj7hNoWVBamFiA+7VdIH8Mc8mRKhQ=</MAC><RUNNING_SUB_TOTAL>20.40</RUNNING_SUB_TOTAL><RUNNING_TRANS_AMOUNT>20.40</RUNNING_TRANS_AMOUNT><RUNNING_TAX_AMOUNT>0.00</RUNNING_TAX_AMOUNT><LINE_ITEMS><MERCHANDISE><LINE_ITEM_ID>300003</LINE_ITEM_ID></MERCHANDISE></LINE_ITEMS></TRANSACTION>");
  
  ret1 = send_req(req_file, resp1, sock_fd);
  if(ret1 == -1){
      printf("ending txn for LINE_ITEM_REMOVE_WRITE_FAIL");
   ns_end_transaction_as("LINE_ITEM_REMOVE", 0, "LINE_ITEM_REMOVE_WRITE_FAIL");
   return (-1);
  }

  ns_save_searched_string(NS_ARG_IS_BUF, resp1,  NS_ARG_IS_BUF, output_buffer, "<TERMINATION_STATUS>", "</TERMINATION_STATUS>", 1, NS_FROM_START, NS_SAVE_COMPLETE);

  if(strcmp(output_buffer,"SUCCESS") == 0)
    ns_end_transaction("LINE_ITEM_REMOVE", NS_AUTO_STATUS);
  else
    ns_end_transaction_as("LINE_ITEM_REMOVE", 0, "LINE_ITEM_REMOVE_FAILED");
  
  ns_page_think_time(5);

  //Sending req for PAYMENT CAPTURE command
  ns_start_transaction("PAYMENT_CAPTURE");
  sprintf(req_file, "<TRANSACTION><FUNCTION_TYPE>PAYMENT</FUNCTION_TYPE><COMMAND>CAPTURE</COMMAND><MAC_LABEL>P_109</MAC_LABEL><COUNTER>19</COUNTER><MAC>4JGZrFnMX9PplQF5yALZ4RtWqbG2gebOcjgE2hHDrgY=</MAC><MANUAL_ENTRY>FALSE</MANUAL_ENTRY><TRANS_AMOUNT>21.41</TRANS_AMOUNT></TRANSACTION>");
  ret1 = send_req(req_file, resp1, sock_fd);
  if(ret1 == -1){
   ns_end_transaction_as("PAYMENT_CAPTURE", 0, "PAYMENT_CAPTURE_WRITE_FAIL");
   return (-1);
  }
  ns_save_searched_string(NS_ARG_IS_BUF, resp1,  NS_ARG_IS_BUF, output_buffer, "<RESULT>", "</RESULT>", 1, NS_FROM_START, NS_SAVE_COMPLETE);
  if (strcmp(output_buffer,"OK") == 0)
    ns_end_transaction("PAYMENT_CAPTURE", NS_AUTO_STATUS);
  else
    ns_end_transaction_as("PAYMENT_CAPTURE", 0, "PAYMENT_CAPTURE_FAILED");

  ns_page_think_time(5);

  //Sending req for PAYMENT CREDIT command
  ns_start_transaction("PAYMENT_CREDIT");
  sprintf(req_file, "<TRANSACTION><FUNCTION_TYPE>PAYMENT</FUNCTION_TYPE><COMMAND>CREDIT</COMMAND><MAC_LABEL>P_403</MAC_LABEL><COUNTER>120</COUNTER><MAC>XvHg2cgutxngYLNpvF+q7hY2e1z0vemYiZp1rNQI4gw=</MAC><MANUAL_ENTRY>FALSE</MANUAL_ENTRY><PAYMENT_TYPE>PRIV_LBL</PAYMENT_TYPE><CARD_TOKEN>775180990100</CARD_TOKEN><TRANS_AMOUNT>16.00</TRANS_AMOUNT></TRANSACTION>");
  
  ret1 = send_req(req_file, resp1, sock_fd);
  if(ret1 == -1){
      printf("ending txn for PAYMENT_CREDIT_WRITE_FAIL");
   ns_end_transaction_as("PAYMENT_CREDIT", 0, "PAYMENT_CREDIT_WRITE_FAIL");
   return (-1);
  }

  ns_save_searched_string(NS_ARG_IS_BUF, resp1,  NS_ARG_IS_BUF, output_buffer, "<TERMINATION_STATUS>", "</TERMINATION_STATUS>", 1, NS_FROM_START, NS_SAVE_COMPLETE);
  if (strcmp(output_buffer,"SUCCESS") == 0)
    ns_end_transaction("PAYMENT_CREDIT", NS_AUTO_STATUS);
  else
    ns_end_transaction_as("PAYMENT_CREDIT", 0, "PAYMENT_CREDIT_FAILED");
   
  ns_page_think_time(5);


  //Sending req for SESSION FINISH command
  ns_start_transaction("SESSION_FINISH");
  sprintf(req_file, "<TRANSACTION><FUNCTION_TYPE>SESSION</FUNCTION_TYPE><COMMAND>FINISH</COMMAND><MAC_LABEL>P_109</MAC_LABEL><COUNTER>22</COUNTER><MAC>iKMd+oPf8XF7A0Z+7fygsMPQ4nRpjaBihLX86BE+A/Q=</MAC></TRANSACTION>");
  
  ret1 = send_req(req_file, resp1, sock_fd);
  if(ret1 == -1){
      printf("ending txn for SESSION_FINISH_WRITE_FAIL");
   ns_end_transaction_as("SESSION_FINISH", 0, "SESSION_FINISH_WRITE_FAIL");
   return (-1);
  }

  ns_save_searched_string(NS_ARG_IS_BUF, resp1,  NS_ARG_IS_BUF, output_buffer, "<TERMINATION_STATUS>", "</TERMINATION_STATUS>", 1, NS_FROM_START, NS_SAVE_COMPLETE);

  if (strcmp(output_buffer,"SUCCESS") == 0)
    ns_end_transaction("SESSION_FINISH", NS_AUTO_STATUS);
  else
    ns_end_transaction_as("SESSION_FINISH", 0, "SESSION_FINISH_FAILED");
    ns_page_think_time(5);

  // Closing connection
  close(sock_fd);
}
