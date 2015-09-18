
<!--
  Name    : corrServiceNames.jsp
  Author  : Ritesh Sharma
  Purpose : Show the all service perameter
  Date    :18/07/11
-->
<!--  
  Name   : correlationHeader.jspf
  Author : jyoti
  Purpose: This is for correlation GUI. It it to be included in all JSP
           on the top for for following :
           - Import of packages 
           - Initialization of beans and js
           - JSP variables which are common to all JSPs
  Notes  :
    None
  Modification History:
    29/03/10  : jyoti :3.6.2 -Initial Version

-->













<!-- This is required for firefox b'coz it does not refresh the screen.when we select the option then click on another tab or OK button after again open the same screen . It does not show the changed value means it takes value from the cache.when we reload the screen then it gives new value. -->


<link rel="stylesheet" href="../css/AdvancedNetstorm.css" type="text/css" media="all"/>
<link rel="stylesheet" href="../css/Netstorm.css" type="text/css" media="all"/>


<link rel="stylesheet" type="text/css" href="../yui/css/menu.css"/>
<link rel="stylesheet" type="text/css" href="../yui/css/menu.css"/>
<link rel="stylesheet" type="text/css" href="../yui/css/fonts-min.css" />
<link rel="stylesheet" type="text/css" href="../yui/css/container.css" />

<script type="text/javascript" src="../js/jquery-latest.js"></script>
<script language="javascript" src="corrSettingHints.js"></script>
<script language="javascript" src="../js/sortableTable.js"></script>
<script type="text/javascript" src="../js/jquery-impromptu.js"></script>
<link rel="stylesheet" type="text/css" href="../css/jquery-impromptu.css">
<script language="javascript" src="corrUtils.js"></script>

<script language="javascript" src="../js/sortableTable.js"></script>
<!----<script language="javascript" src="help.js"></script>--->
<script language="javascript" src="../js/nsUtils.js"></script>


   <script type="text/javascript" src="../js/prototype.js"></script>
   <script type="text/javascript" src="../js/fastinit.js"></script>
   <script type="text/javascript" src="../js/tablekit.js"></script>


<script language="javascript"  src="../js/tableEnhancement.js"></script>
<script language="javascript"  src="../js/tablePagination.js"></script>

<script language="javascript" src="../js/validation.js"></script>
<script language="javascript" src="corrValidateCondition.js"></script>
<script language="javascript" src="../js/nsStringUtils.js"></script>
<script language="javascript" src="../js/help.js"></script>

<script language="javascript" src="../yui/js/yahoo-dom-event.js"></script>
<script language="javascript" src="../yui/js/container_core-min.js"></script>
<script language="javascript" src="../yui/js/menu-min.js"></script>


<!-- Combo-handled YUI JS files: -->
<!--<script type="text/javascript" src="http://yui.yahooapis.com/combo?2.8.2r1/build/yahoo-dom-event/yahoo-dom-event.js"></script>
<script type="text/javascript" src="http://yui.yahooapis.com/combo?&2.8.2r1/build/container/container_core-min.js"></script>
<script type="text/javascript" src="http://yui.yahooapis.com/combo?2.8.2r1/build/menu/menu-min.js"></script>-->


<script language="javascript" src="../yui/js/yahoo-dom-event.js"></script>
<script language="javascript" src="../yui/js/container_core-min.js"></script>
<script language="javascript" src="../yui/js/menu-min.js"></script>

<script type="text/javascript" src="../yui/js/connection-min.js"></script>
<script type="text/javascript" src="../yui/js/animation-min.js"></script>
<script type="text/javascript" src="../yui/js/dragdrop-min.js"></script>
<script type="text/javascript" src="../yui/js/container-min.js"></script>


<script> YAHOO.namespace("example.container"); </script>

<script type="text/javascript">
<!--
// this is put up for help pop-up
// Override the default settings to point to the parent directory
//


//-->
</script>
<script language="javascript">






  





var arrSelectedRows = new Array(); // Array to store indexes of rows that are selected by the user
var arrParameterNames = new Array()
var shiftLastCheckVaue=null;//this value for multiple shift
var lastId=null;
var arrIndex=new Array();
var selectedRows=new Array();


  
var ServiceParameterCount =  '0'; 
var tableName = "Service Parameters";
function onLoadFunction()
{
  document.frmMain.Update.disabled = true;
  document.frmMain.Update.style.color = 'AEA0BF';
  document.frmMain.Delete.disabled = true;
  document.frmMain.Delete.style.color = 'AEA0BF';
  
  //Check for Observer Group Users.
   
  
}

//Disable controls if user is of Observer group.
function disableControls()
{
  document.frmMain.Update.disabled = true;
  document.frmMain.Update.style.color = '#AEA0BF';
  
  document.frmMain.Delete.disabled = true;
  document.frmMain.Delete.style.color = '#AEA0BF';
  
}

function viewTemplate()
{
 var varUrl = '/cavisson.com'
 var varServiceName  = 'test'
 varHost = 'default'
 openTemplateWin(varUrl, varHost, varServiceName)
}

function openTemplateWin(varUrl, varHost, varServiceName)
{
  var varTemplateUrl = "corrRespTemplateMain.jsp?strTemplateUrl="+varUrl+"&strFld1="+varUrl+"&strFld2="+varHost+"&strFld3="+varServiceName;
  
  if (window.top!=window.self) 
  {
    window.top.location = varTemplateUrl;
  }
}


var checkrow=null;
function clickUpdate()
{
   if(valForUpdate(ServiceParameterCount, document.frmMain.chkMain, document.frmMain.chkRow, tableName) == false)
     return;
     
   if(arrParameterNames[checkrow]=='Scratch')
      submitJSP("updateSVar", "");
   else if(arrParameterNames[checkrow]=='Random Number')   
      submitJSP("updateRandomNumber", "");
   else if(arrParameterNames[checkrow]=='Query')   
      submitJSP("updateQVar", "");
   else if(arrParameterNames[checkrow]=='Dataset')   
      submitJSP("updateFileParam", "");
   else if(arrParameterNames[checkrow]=='Indexed Dataset')   
      submitJSP("updateIndexFileParam", "");
   else if(arrParameterNames[checkrow]=='Date Time')   
      submitJSP("updateDateTimeParam", "");
   else if(arrParameterNames[checkrow]=='Random String')   
      submitJSP("updateRandomString", "");
   else if(arrParameterNames[checkrow]=='Unique Number')   
      submitJSP("updateUniqueNum", "");
   else if(arrParameterNames[checkrow]=='Cookie')   
      submitJSP("updateCookieVar", "");  
   else if(arrParameterNames[checkrow]=='XML')   
      submitJSP("updateXMlVar", ""); 
   else if(arrParameterNames[checkrow]=='Scratch Array')   
      submitJSP("updateScratchArray", ""); 
   else if(arrParameterNames[checkrow] == "Search")
      submitJSP("updateSearchVar", "");
   else if(arrParameterNames[checkrow] == "Request Body")
      submitJSP("updateRequestVar", "");
   else
      submitJSP("updateIndexedDataSourceVar", "");
      
}


function clickCancel()
{
  window.top.close();
}

function clickDelete()
{
  if(valForDelete(ServiceParameterCount, document.frmMain.chkMain, document.frmMain.chkRow, tableName) == false)
    return;

  submitJSP("delServiceParam", "")
}

function disableButton(updatecopy)
{ 
 document.frmMain.Copy.disabled = updatecopy;
 
 }

function clickChkMain()
{ 
 // document.frmMain.Update.disabled = true;
 if(document.frmMain.chkMain.checked)
  {
    document.frmMain.Update.disabled = true;
    document.frmMain.Update.style.color = 'AEA0BF';
    document.frmMain.Delete.disabled = false;
    document.frmMain.Delete.style.color = '';
      //alert(queryCount)
    if(ServiceParameterCount == '0')
     {
        document.frmMain.Delete.disabled = true;
        document.frmMain.Delete.style.color = 'AEA0BF';
     }
    if(ServiceParameterCount == '1')
     {
        document.frmMain.Update.disabled = false;
        document.frmMain.Update.style.color = '';
       // document.frmMain.Delete.disabled = false;
     }
   }
  else
    {
      document.frmMain.Update.disabled = true;
      document.frmMain.Update.style.color = 'AEA0BF';
      document.frmMain.Delete.disabled = true;
      document.frmMain.Delete.style.color = 'AEA0BF';
    }
 
  // Clear highlighting on all rows
 //changeToOriginalColor(arrSelectedRows);
   shiftLastCheckVaue=null;
    
   changeAllChecksByChangeColorNO(ServiceParameterCount, document.frmMain.chkMain, document.frmMain.chkRow, "" , document.frmMain.chkMain.checked,arrSelectedRows);
  

 // changeAllChecks(ServiceParameterCount, document.frmMain.chkMain, document.frmMain.chkRow, "" , document.frmMain.chkMain.checked);
 
 //Check for Observer Group Users.
  
}

function clickChkRow(checkEvent,id)
{ 


   var noOfSelectedRows =  getNoOfSelectedRows()
    if(noOfSelectedRows == '1')
    {
      document.frmMain.Update.disabled = false;
      document.frmMain.Update.style.color = '';
      document.frmMain.Delete.disabled = false;
      document.frmMain.Delete.style.color = '';
    }
    else if(noOfSelectedRows > '1' || noOfSelectedRows == 0)
    {
      document.frmMain.Update.disabled = true;
      document.frmMain.Update.style.color = 'AEA0BF';
      if(noOfSelectedRows >= 1)
      {
        document.frmMain.Delete.disabled = false;
        document.frmMain.Delete.style.color = '';
      }
      else
      {
        document.frmMain.Delete.disabled = true;
        document.frmMain.Delete.style.color = 'AEA0BF';
      }
    }
  
   
 checkrow=checkEvent.value;
//put the shiftLastCheckVaue as ckecked checkbox and in else condition  shiftLastCheckVaue is null
 
 if(checkEvent.checked)
   shiftLastCheckVaue=checkEvent;
 else
   shiftLastCheckVaue=null;
  
  lastId=id;
  
  changeMainCheck(ServiceParameterCount, document.frmMain.chkMain, document.frmMain.chkRow, "");
  
  //Check for Observer Group Users.
   
  
}

function getNoOfSelectedRows()
{
  var j = 0; 
  if(ServiceParameterCount > 1)
  {
    for(var i = 0 ; i < ServiceParameterCount; i++)
    {
      if(document.frmMain.chkRow[i].checked == true)
      {
        j++;
      }
    }
  }
  else
  {
    if(document.frmMain.chkRow.checked == true)
    {
      document.frmMain.Update.disabled = false;
      document.frmMain.Update.style.color = '';
      document.frmMain.Delete.disabled = false;
      document.frmMain.Delete.style.color = '';
      j =-1;
    }
  }
  //alert("nnnnnnnnn"+j);
  return j;
}

function setupTableSort()
{
  var st = new SortableTable(document.getElementById("showServieNameParameter"),["None", "String","String", "String","String"]);
  SortableTable.prototype.addSortType("String", SortableTable.toUpperCase);
  SortableTable.prototype.addSortType("String", SortableTable.toUpperCase);
  SortableTable.prototype.addSortType("String", SortableTable.toUpperCase);
  
  
  restoreCheckBoxesForSorting(st);
}



function viewSearchParamDetails(rowId)
{ 
  submitJSP("updateSearchVar", rowId)

}
function viewScratchParamDetails(rowId)
{ 
  submitJSP("updateSVar",rowId);
}

function viewRandomNumDetails(rowId)
{
  submitJSP("updateRandomNumber",rowId);

}

function viewQueryParamDetails(rowId)
{
  submitJSP("updateQVar", rowId)

}

function viewFileParamDetails(rowId)
{
  submitJSP("updateFileParam", rowId)
}

function viewIndexFileParamDetails(rowId)
{
  submitJSP("updateIndexFileParam", rowId)
}

function viewDateParamDetails(rowId)
{
  submitJSP("updateDateTimeParam", rowId)
}

function viewRandomStringDetails(rowId)
{
  submitJSP("updateRandomString", rowId)
}
function viewUniqueNumDetails(rowId)
{
  submitJSP("updateUniqueNum", rowId)
}

function viewCookieDetails(rowId)
{
  submitJSP("updateCookieVar", rowId)
}

function viewScratchArrayDetails(rowId)
{
  submitJSP("updateScratchArray", rowId)
}

function viewXMLDetails(rowId)
{
  submitJSP("updateXMlVar", rowId)
}

function viewIndexedDataSourceDetails(rowId)
{
  submitJSP("updateIndexedDataSourceVar", rowId)
}

function viewRequestDetails(rowId)
{
  submitJSP("updateRequestVar", rowId)
}


// provide the height of the table to tablekit.js for resizing
function getHeightTable()
{
  return getHeight(.35);
}

//if data is null the resizable will not be done
function getTableLengthtStatus()
{
 if(0<= 0)
  return true;
 else
  return false;
}

function getWidthColumn(percent)
{
  var w=parseInt(window.screen.availWidth);
  w=w*(.95);
  var value=(w*percent)/100;
  return value;
}

function getCookie(c_name)
{
//alert("get cookie");
var i,x,y,ARRcookies=document.cookie.split(";");
//alert(ARRcookies);
for (i=0;i<ARRcookies.length;i++)
{
  x=ARRcookies[i].substr(0,ARRcookies[i].indexOf("="));
  y=ARRcookies[i].substr(ARRcookies[i].indexOf("=")+1);
  x=x.replace(/^\s+|\s+$/g,"");
  if (x==c_name)
  {
    //alert(unescape(y))
    if(unescape(y) == "null" || unescape(y) == ""){
      return '3%%10%%10%%59';}
    else
    {  //alert(y)
      return unescape(y);
    }  
  }
 }
   
 return '3%%10%%10%%59';
}

function setCookie(c_name,exdays)
{ 
  table = document.getElementById("showServieNameParameter");
  //alert(getBrowserType())
  if(getBrowserType() == "IE")
    value=getColumnWidthPixel(table.rows[0].cells[0].offsetWidth+3)+"%%"+getColumnWidthPixel(table.rows[0].cells[1].offsetWidth)+"%%"+getColumnWidthPixel(table.rows[0].cells[2].offsetWidth)+"%%"+getColumnWidthPixel(table.rows[0].cells[3].offsetWidth);
  else 
    value=getColumnWidthPixel(table.rows[0].cells[0].offsetWidth+3)+"%%"+getColumnWidthPixel(table.rows[0].cells[1].offsetWidth-2)+"%%"+getColumnWidthPixel(table.rows[0].cells[2].offsetWidth-2)+"%%"+getColumnWidthPixel(table.rows[0].cells[3].offsetWidth-2);
  var exdate=new Date();
  exdate.setDate(exdate.getDate() + exdays);
  var c_value=escape(value) + ((exdays==null) ? "" : "; expires="+exdate.toUTCString());
  //alert(c_value);
  document.cookie=c_name + "=" + c_value;
}

function showFileParam()
{ 
  var wdh = new Array();
  wdh = getCookie('widthOfServiceParameter').split("%%");
  
  document.write("<table cellpadding=0 cellspacing=0 width=98% valign=top border=0 align=center>");
  document.write("<tr><td><table border=0 width=100%> <tr><td align=right></td></tr></table></td></tr><tr><td>");

  document.write("<table  cellpadding='0' border=0 cellspacing='0' class='scrollbarColorChange' width=100%><tr><td class=''></td></tr><tr> <td align='center' valign='top'><table width='95%' cellpadding='0' cellspacing='0'>");

  document.write("<table cellpadding=0  cellspacing=0 width=100% valign=top align=center border=0>");
  document.write("<tr><td><div id='ScrollablePane' STYLE='overflow:auto; width:100%; height:" + getHeight(.35) + "px; border:1px solid #DFE9F7;'>");
  document.write("<table  style='table-layout:fixed' class='resizable' border=0 id=showServieNameParameter cellpadding=0 cellspacing=0  width=100% align=center>");
  document.write("<thead id='pfh'>");
  document.write("<tr class=tableHeaderLockedEnhance >");
  document.write("<th width="+wdh[0]+"%  class='tableCell' align=left  onmouseOver=setCookie('widthOfServiceParameter',1)><input type = checkbox name = chkMain onclick = 'clickChkMain();' value='1'></th>");
  document.write("<th width="+wdh[1]+"% title='Click to sort on Name' class='tableCell' align=left nowrap onmouseOver=setCookie('widthOfServiceParameter',1)><b style='cursor:"+getStyleCursor()+"'>&nbsp;&nbsp;Name</b></th>");
  document.write("<th width="+wdh[2]+"% class='tableCell' title='Click to sort on Type' align=left nowrap onmouseOver=setCookie('widthOfServiceParameter',1)><b style='cursor:"+getStyleCursor()+"'>&nbsp;&nbsp;Type</b></th>");
  document.write("<th width="+wdh[3]+"%  class='tableCell' title='Click to sort on Specification' align=left nowrap onmouseOver=setCookie('widthOfServiceParameter',1)><b style='cursor:"+getStyleCursor()+"'>&nbsp;&nbsp;Specification</b></th>");
  
  
  document.write("</tr>");
  
  document.write("</thead>");
  
  
  document.write("<tbody>");
  
  document.write("</tbody>");  

  setupTableSort();
  document.write("</table>");
  document.write("</td></tr>");

  document.write("<tr><td valign=top align=center>");
  document.write("<br>");

  
  
  document.write("<input type=Button class=button style='width:60;' value = 'Update' name = 'Update' onclick = 'clickUpdate();'>&nbsp;");  
  
  document.write("<input type=Button class=button style='width:60;' value = 'Delete' name = 'Delete' onclick = 'clickDelete();'>&nbsp;"); 
  // document.write("<input type=Button class=button style='width:60;' value = 'Close' name = 'Close' onclick = 'clickCancel();'>&nbsp;");
  
  document.write("</td></tr>");
  document.write("</table>");
  document.write("</td></tr>");
  document.write("<tr><td>&nbsp;</td></tr>");
  document.write("</table>");
  document.write("<tr><td>&nbsp;</td></tr>");
  document.write("</table></td></tr></table>");  
}

</script>


<!--  
  Name   : correlationHeader.htmlf
  Author : Jyoti
  Purpose: This file is for correlation GUI.It it to be included in all JSP
           on the top for for following :
           - Import of packages 
           - Initialization of beans and js
           - JSP variables which are common to all JSPs

  Modification History:
    29/03/10  : jyoti :3.6.2 -Initial Version
    15/02/12  : Manish:3.8.2 -Initial Version
  Notes  :
      None
-->

<html>
<head>
<link rel="stylesheet" href="../css/AdvancedNetstorm.css" type="text/css" media="all"/>
<link rel="stylesheet" href="../css/Netstorm.css" type="text/css" media="all"/>
<title>NetFunction (Controller_Proxy) - Service Parameters</title>

<link rel="stylesheet" type="text/css" href="../yui/css/menu.css"/>
<link rel="stylesheet" type="text/css" href="../yui/css/menu.css"/>
<link rel="stylesheet" type="text/css" href="../yui/css/fonts-min.css" />
<link rel="stylesheet" type="text/css" href="../yui/css/container.css" />


<style type="text/css">

div.yui-b p {
  margin: 0 0 .5em 0;
  color: #999;
}

div.yui-b p strong {
  font-weight: bold;
  color: #000;
}

div.yui-b p em {
  color: #000;
}

h1 {
  font-weight: bold;
  margin: 0 0 1em 0;
  padding: .25em .5em;
  background-color: #ccc;
}

#productsandservices {
  margin: 0 0 0px 0;
}

</style>


<!-- This method creating a menu with option.--->
<!-----------------------Start ----------------->


<script type="text/javascript">

/*
     Initialize and render the MenuBar when its elements are ready
     to be scripted.
*/

YAHOO.util.Event.onContentReady("productsandservices", function () {

/*
  Instantiate a MenuBar:  The first argument passed to the constructor
  is the id for the Menu element to be created, the second is an
   object literal of configuration properties.
*/

    var oMenuBar = new YAHOO.widget.MenuBar("productsandservices", {
                                                autosubmenudisplay: true,
                                                hidedelay: 750,
                                                lazyload: true});

/*
     Call the "render" method with no arguments since the
     markup for this MenuBar instance is already exists in
     the page.
*/

    oMenuBar.render();

});

function openSetting()
{
  window.open("../admin/setting.jsp", 'settings');
}

function setCookieForlogOut(c_name,exdays)
{
value = null;
var exdate=new Date();
exdate.setDate(exdate.getDate() + exdays);
var c_value=escape(value) + ((exdays==null) ? "" : "; expires="+exdate.toUTCString());
//alert(c_value);
document.cookie=c_name + "=" + c_value;
}

function openLogout()
{
 setCookieForlogOut("width",1);
 submitJSP("logout", "");
}

function openNFUserHelp()
{	
  var helpId = window.open("/NFGuide/WebHelp/NFUserGuide.htm", "NetstormOnLineHelp", "toolbars=no, location=no, directories=no, status=no, menubar=no, scrollbars=yes, resizable=yes, copyhistory=no, left=50, top=50");
  helpId.focus();
}

function openNFTutorialHelp()
{	
  var helpId = window.open("/NFTutorial/WebHelp/NetFunctionTutorial.htm", "NetstormOnLineHelp1", "toolbars=no, location=no, directories=no, status=no, menubar=no, scrollbars=yes, resizable=yes, copyhistory=no, left=50, top=50");
  helpId.focus();
}
 
function openNFCAPI()
{	
  var helpId = window.open("/NFCApi/WebHelp/HPDCApiReq.htm", "NetstormOnLineHelp1", "toolbars=no, location=no, directories=no, status=no, menubar=no, scrollbars=yes, resizable=yes, copyhistory=no, left=50, top=50");
  helpId.focus();
}

function openNFAgentAPI()
{	
  var helpId = window.open("/clientAPIdocs/index.html", "NetstormOnLineHelp", "toolbars=no, location=no, directories=no, status=no, menubar=no, scrollbars=yes, resizable=yes, copyhistory=no, left=50, top=50");
  helpId.focus();
}

function openNFAbout()
{	
  var helpId = window.open("../admin/about.jsp", "NetstormOnLineHelp", "toolbars=no, location=no, directories=no, status=no, menubar=no, scrollbars=yes, resizable=no, copyhistory=no, width=600,height=300 left=50, top=50");
  helpId.focus();
}

function openwsdlWin()
{
  var width = 900;
  var height = 300;
  var left = parseInt((screen.availWidth/2) - (width/2));
  var top = parseInt((screen.availHeight/2) - (height/2));
  var windowFeatures = "width=" + width + ",height=" + height + ",status,resizable,left=" + left + ",top=" + top + "screenX=" + left + ",screenY=" + top  + ",scrollbars=1"; 
  //myWindow = window.open("corrPageHelp.jsp?help=fileParam",'',windowFeatures);
  var wsdlWin = window.open("../correlation/corrAddWSDLFile.jsp?destFile=&rowId=0&mode=service&redirectFile=corrServices.jsp", "WSDLService", windowFeatures);
  wsdlWin.focus();
}

</script>
</head>

<body class="yui-skin-sam" onload="onLoadFunction()" >

<form name="frmMain" method="post">
<input type="hidden" name="strOperName" value="">
<input type="hidden" name="strOperValue" value="">



   <!--<table width="100%" align = center border="1" cellpadding="0" cellspacing="0" style =height:6% id="header">-->
       <table border="0" width="100%" style='height:6%;background-color:#F2F2F2; background-repeat:repeat-x;' >
 <!--<tr><td  align="center" border = "1">&nbsp;</td> </tr>-->
     
     <tr><td align="center" colspan="4">
      <!--<table width="100%" border="0" cellpadding="0" cellspacing="0">-->
      <table border="0" width="100%" style='height:6%;background-color:#F2F2F2;background-repeat:repeat-x;' >
         
         <tr><td colspan="2" align="left" class="screenTitleWithout" title = '/cavisson.com'><b><script> genTitle("Service Parameters","","test (/cavisson.com)"); </script></b></td></tr>
         
      </table>
  </td></tr>
</table>
<table border="0" width="100%">





<tr><td>  
<script>showFileParam();</script>
</td></tr>

<script>showDesciption('ServiceParameter');</script>

<!--  
  Name   : correlationFooter.htmlf
  Author : jyoti
  Purpose: For closing tags
           <Fill details here>
  Notes  :
    None
  Modification History:
    29/03/10  : jyoti :3.6.2 -Initial Version

-->



<!-- Check for Observer Group Users. -->

</form>
</body>
</html>

