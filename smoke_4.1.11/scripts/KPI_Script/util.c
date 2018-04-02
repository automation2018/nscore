#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"
#define YES 1
#define NO 0

static void Fill_LoginDetail()
{
  ns_advance_param("UserPasswdFP");
  char userid[64 + 1]="";
  char pwd[64 + 1]="";
  char email[64 + 1]="";
  char textarea[64 + 1]="";
  snprintf(userid,64,"t1=%s",ns_eval_string("{uid}"));
  snprintf(pwd,64,"t2=%s",ns_eval_string("{pass}"));
  snprintf(email,64,"t3=%s",ns_eval_string("{emailid}"));
  snprintf(textarea,64,"t4=%s",ns_eval_string("{text}"));
  ns_set_form_body("LoginFormBlockSP","LoginDP",1,4,userid,pwd,email,textarea);
    
}
