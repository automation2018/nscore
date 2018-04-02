#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "../../include/ns_string.h"



static int p;

static char buffer[2048];

void flow1()

{

 ns_web_url(0); // index_html
 ns_web_url(1); // login
 ns_web_url(2); // reservation
 ns_web_url(3); // findflight
 ns_web_url(4); // findflight_2
char tmp_buf[2048];



p=atoi(ns_eval_string("{NumPass}"));

int i;

char f[]="firstname";

char l[]="lastname";

tmp_buf[0]=0;

buffer[0]=0;

for (i = 1; i < p+1; i++)

{

strcat(buffer, tmp_buf);

}

ns_save_string(buffer,"buffer");

 ns_web_url(5); // findflight_3
 ns_web_url(6); // welcome
}

