/*-----------------------------------------------------------------------------

    Name: flow
    Recorded By: anupam
    Date of recording: 03/12/2014 02:51:06
    Flow details:
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

#define NS_DECODE_TRIPLETS 1 
#define SECRET_KEY "111111111111111111111111" 

void get_decoded_captcha() { 
    char output[32];
	char *encrypted_captcha ; 
    
	encrypted_captcha = ns_eval_string("{searchvar_%ApiValue}");
	int status = ns_decode_3des(SECRET_KEY, encrypted_captcha, output, 32, NS_DECODE_TRIPLETS); 
	
	printf("######encrypted_captcha is %s\n",encrypted_captcha);
	printf("######status is %d\n",status);
	
	ns_save_string(encrypted_captcha, "SearchVarHdr");
	ns_save_string(output, "DecryptedCaptchaDP");
		
	if (status == -1) 
		return ;
}
 

void flow()
{
    ns_web_url ("page1",
        "URL=http://127.0.0.1/encrypt_url_dir/encrypt_url.html"
    );

	get_decoded_captcha();
	
    ns_web_url ("page2",
		"URL=http://127.0.0.1/encrypt_url_dir/vishal.html",
		"HEADER=CaptchaDecoded: {DecryptedCaptchaDP}", 
		"HEADER=CaptchaSearched: {SearchVarHdr}", 
	);
}
