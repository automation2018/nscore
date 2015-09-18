//-----------------------------------------------------------------------
//
//  Name   : corrSettingHints.js
//  Author : Jyoti
//  Purpose: Correlation GUI Setting Hints JavaScript functions
//  Notes  :
//    None
//  Modification History:
//    30/03/10  : jyoti :3.6.2 -Initial Version
//-----------------------------------------------------------------------

var msg = "";  

// HTML part
function htmlHints()
{
  
  document.write("<tr><td><br></td></tr>");
  document.write(" <table border = '1' frame = 'box' rules = 'none' class = table width = '98%' align = 'center' cellspacing = 0 cellpadding = 0>"); 
  document.write("<tr><td><br></td></tr>");  
  document.write("<tr><td align = 'center'><div id = 'txtDescription'  style='width: 95%;' style = 'margin-left:2%'><b>Description:</b> To see hints click mouse on any item.");
  document.write("</div></td></tr>");
  document.write("<tr><td><br></td></tr>");
  document.write("</table>");
}

function showTxtDescription(msg)
{
  msg = "<b>Description:</b> " + msg;
  document.getElementById("txtDescription").innerHTML = msg;
}

function showDesciption(val)
{  
  htmlHints();

  var msg = "";
  
  if(val == "randomNum")
  {
    msg = "Random Number replaces the parameter with a random number. User can set a range of numbers by specifying minimum and maximum values. User can use the Random Number parameter type to sample your system's behavior within a possible range of values.";//<br><br><b>Minimum:</b> It is the starting number of range in between we need to get the random number.<br><br><b>Maximum:</b> It is the ending number of range in between we need to get the random number.<br><br><b>Format:</b> It is to define the format of random number to be generated.<br><br><b>Updated Value On:</b> This property has two options<br><br><b>&nbsp;&nbsp;&nbsp;&nbsp;Session:</b> In this option value of the parameter is set once for each service request. It does not depend on how many times this parameter is used in response template.<br><br><b>&nbsp;&nbsp;&nbsp;&nbsp;Use:</b> In this option value of the parameter is set every time it is used in the response template.";
  }

  if(val == "searchParam")
  {
    msg = "Request parameters are used to hold the values for composing service responses. The values for a Request parameter can be assigned from the content of incoming service requests.";
  }
  
  if(val == "scratchArrayParam")
  {
      msg = "Scratch Array parameters are used to set values in call back methods based on the size given. These array parameter are declared and then used in response and/or conditions.";
  }
  if(val == "fileParam")
  {
    msg = "Datasets are used to source the values from text files. In Datasets multiple set names can be defined separated by \",\"." ;
  } 
  
  if(val == "dateTime")
  {
    msg = "Date/Time replaces the parameter with the current date and/or time. To specify a date/time format, you can select a format from the format list or specify your own format.";// <br><br><b>Format:</b> This is to define the format of date/time by selecting one from the available list of formats.<br><br><b>Offset:</b> Offset in days from current day. It can be 0, positive number or negetive number.<br><br><b>Updated Value On:</b> This property has two options<br><br><b>&nbsp;&nbsp;&nbsp;&nbsp;Session:</b> In this option value of the parameter is set once for each service request. It does not depend on how many times this parameter is used in response template.<br><br><b>&nbsp;&nbsp;&nbsp;&nbsp;Use:</b> In this option value of the parameter is set every time it is used in the response template. ";
  } 

  if(val == "uniqNum")
  {
    msg = "Unique Number replaces the parameter with a unique number.";//<br><br><b>Format:</b> It is to define the format of unique number to be generated.<br><br><b>Updated Value On:</b> This property has two options<br><br><b>&nbsp;&nbsp;&nbsp;&nbsp;Session:</b> In this option value of the parameter is set once for each service request. It does not depend on how many times this parameter is used in response template.<br><br><b>&nbsp;&nbsp;&nbsp;&nbsp;Use:</b> In this option value of the parameter is set every time it is used in the response template. ";
  } 

  if(val == "queryParam")
  {
    msg = "URL Query parameters are used to hold the values for composing service responses.  The value for a URL Query parameter can be assigned from the query string of URL of incoming service requests.";    
  } 

  if(val == "scratchParam")
  {
    msg = "Scratch parameters (also called declare parameters) are used to set values in call back methods. These parameters are declared and then used in response and/or conditions.";
  } 

  if(val == "indexFileParam")
  {
    msg = "Indexed Datasets are specialized data sets where values provided in data files can be selected based on an index value. The index can be assigned from any other parameter e.g. a customer id from an incoming request can be used to select a row of values in data file for discount codes. In Indexed Datasets multiple set names can be defined separated by \",\".";//<br><br><b>Data File Name:</b> This property is used to define the file name from where the values need to take. Data file should have index parameter value as first field.<br><br><b>Index Parameter:</b> This is to select the parameter name from the list of available parameters to assign the index.";
  } 

  if(val == "randamString")
  {
    msg = "Random String replaces the parameter with a random string. User can set a range for number of characters in string by specifying minimum and maximum values. User can use the Random String parameter type to sample your system's behavior within a possible range of values.";//<br><br><b>Minimum:</b> It is to define the minimum number of characters in Random String.<br><br><b>Maximum:</b> It is to define the maximum number of characters in Random String.<br><br><b>Character Set:</b> It is to define characters to be used in Random String. Characters can be defined either individually i.e. \"aghe\" or range i.e. \"A-Z\".<br><br><b>Updated Value On:</b> This property has two options<br><br><b>&nbsp;&nbsp;&nbsp;&nbsp;Session:</b> In this option value of the parameter is set once for each service request. It does not depend on how many times this parameter is used in response template.<br><br><b>&nbsp;&nbsp;&nbsp;&nbsp;Use:</b> In this option value of the parameter is set every time it is used in the response template.";
  } 
  
  if(val == "cookieParam")
  {
     msg = "Cookie parameters are used to hold the values for composing service responses. The values for a cookie parameter can be assigned from the cookie coming in the request.";
  } 
  
  if(val == "xmlParam")
  {
    msg = "XML Parameters are initialized as a result of parsing a HTTP request containing XML document.";
  } 

  if(val == "decodeContent")
  {
    msg = "This option is to identify whether the contents of request are in encoded form or not and to set the keep alive timeout";
  } 
  
  if(val == "httpHeader")
  {
    //msg = "Include any HTTP headers here which need to be sent with all responses";
    msg = "HTTP headers allow you to send additional HTTP headers in the response";
  } 
  if(val == "ServiceParameter")
    {
      msg = "Showing all parameters defined in service with the parameter type and important specification";
  } 
  showTxtDescription(msg);
}
