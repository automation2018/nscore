/*-----------------------------------------------------------------------------
    Name: Runlogic
    Created By: Saloni Tyagi
    Date of creation: 03/14/2013 02:15:09
    Flow details:
        This file is runlogic file, start point for script excecution.
        
    Modification History:
-----------------------------------------------------------------------------*/

//extern FlowReturn Flow();

//package scriptfile;
//Start - List of used flows in the runlogic
//flow flowObj = new flow();
//End - List of used flows in the runlogic

package com.cavisson.scripts.JTSScript40K;


import pacJnvmApi.NSApi;

public class runlogic
{
 
  public int runFlow(NSApi nsApi)  throws Exception
  {
    try
    { 
      flow flowObj = new flow();
      flowObj.execute(nsApi);
    }
    catch(Exception e)
    {
      e.printStackTrace();
      return -1;
    }
    return 0;
  }

  public void execute(NSApi nsApi) throws Exception
  {
    //init script
    int initStatus = init_script.execute(nsApi);

    //Execute flow
    runFlow(nsApi);
    
    //exit script
    nsApi.ns_end_session();
  }
  
  
}
