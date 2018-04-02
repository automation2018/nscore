#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

extern int init_script();
extern int exit_script();
typedef void FlowReturn;

extern FlowReturn flow();

void runlogic()
{
  init_script();
  flow();
  ns_exit_session();
}

