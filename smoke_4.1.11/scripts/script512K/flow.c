#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow()
{
    ns_web_url("Static512K",
    "METHOD=GET",
    "URL=http://127.0.0.1/file_set/dir00000/class512K_1.html"
    );
}
