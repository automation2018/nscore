/*-----------------------------------------------------------------------------
    Name: flow
    Recorded By: netstorm
    Date of recording: 01/14/2014 09:51:58
    Flow details:
    Modification History:
-----------------------------------------------------------------------------*/

package com.cavisson.scripts.JTSScript40K;
import pacJnvmApi.NSApi;
public class flow implements NsFlow
{
    public int execute(NSApi nsApi) throws Exception
    {
        int status;
       
		//%Url
        status = nsApi.ns_web_url ("index_html",
            "URL=http://127.0.0.1/file_set/dir00000/class2_3.html",
        );

        return status;
    }
}
