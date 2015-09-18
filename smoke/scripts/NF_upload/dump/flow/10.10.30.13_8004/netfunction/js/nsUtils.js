
//-----------------------------------------------------------------------
//
//  Name   : nsUtils.js
//  Author : Prateek/Neeraj
//  Purpose: Analyze GUI utility JavaScript functions
//  Notes  :
//    None
//  Modification History:
//    02/15/05:Prateek:1.2.1 - Initial Version
//    5/16/05:Neeraj:1.2.2 - Added methods for table checks, delete and validations
//    1/31/06:Sudhir:1.4 - Added methods for update validations
//    14/07/14 : Sai Manohar - Added Method to Check Whether Browser is Chrome
//-----------------------------------------------------------------------


// This function is for submitting same JSP
function submitJSP(strOperName, strOperValue)
{
  document.frmMain.strOperName.value = strOperName;
  document.frmMain.strOperValue.value = strOperValue;
  document.frmMain.submit();
  
}

//check if elemment exist in Dom.
function isInDocument(el) 
{
  var html = document.body.parentNode;
  while (el) 
  {
    if (el === html) 
      return true;
      
    el = el.parentNode;
  }
  return false;
}

// Check duplicate key combination
function isDupRecord(key1, key2, key3, arr1, arr2, arr3, tableName, msgText)
{
var keyValue = key1;
  
  if(key2 != "")
    keyValue = keyValue + ", " + key2;
  if(key3 != "")
    keyValue = keyValue + ", " + key3;
    
  for(i = 0 ; i < arr1.length ; i++ )
  {
    if((key1 == arr1[i]) &&  ((key2 == "") || (key2 == arr2[i])) &&  ((key3 == "") || (key3 == arr3[i])))
    {
      if(msgText == "")
        alert("Record with same key (" + keyValue + ") already exists in the " + tableName + ". Please enter different value of key.");
      else
        alert(msgText);      
      return true;
    }
  }
  return false;
}

// Validate for delete 
function valForDelete(numRows, chkMain, chkArray, tableName)
{
  //alert(numRows);

  var flag = false;
  if(numRows == 0)
  {
    alert("No record is present");
    return false;
  }
  if((numRows == 1) && (chkArray.checked == false))
  {
    alert("No record(s) selected. Please select at least one record and try again.");
    return false;
  }

  if(numRows > 1)
  {
    for(var i = 0 ; i < numRows; i++)
    {
      //alert("chkArray[i] " + i);
      if(chkArray[i].checked == true)
      {
        flag = true;
        break;
      }
    }
    if(flag == false)
    {
      alert("No record(s) selected. Please select at least one record and try again.");
      return false;
    }  
  }
  if(chkMain.checked == true)
  {
    //if(confirm("Are you sure to delete all records of " + tableName + "?") == true) 
   if(confirm("Are you sure to delete all " + tableName + "?") == true) 
      return true;
   else
     return false;
    //changeAllChecks(numRows, chkMain, chkArray, tableName, false);
    //return false;
  }
  if(confirm("Are you sure to delete the selected record(s) ?") == true) 
    return true;
  else
    return false;
}

// Validate for update 
function valForUpdate(numRows, chkMain, chkArray, tableName)
{
  var j = 0;
  var flag = false;
  
  if(numRows == 0)
  {
    alert("No record is present");
    return false;
  }
  
  if(numRows == 1)
  {
    if(chkArray.checked != true)
    {
      alert("No record selected. Please select record and try again."); 
      return false;
    }
    else  
      return true;
  }
   
  for(var i = 0 ; i < numRows; i++)
  {
    if(chkArray[i].checked == true)
    {
      j++;
      flag = true;     
    }
  }
  
  if(flag == false)
  {
    alert("No record selected. Please select one record and try again.");
    return false;
  }  
  if(j >= 2)
  {
    alert("Select only one record and try again."); 
    return false;
  }  
  return true;
}

 //Function to validate that only one checkbox is selected at a time
 function valForOneRowSelect(numRows, chkMain, chkArray, tableName)
 {
   var j = 0;
   var flag = false;
   if(numRows == 0)
   {
     alert("No record is present");
     return false;
   }
   
   if(numRows == 1)
   {
     if (chkArray.checked == false)
     {
       alert("No record(s) selected. Please select one record and try again.");
       return false;
     }
     else
       flag = true;
   }
   else
   {
     for(var i = 0 ; i < numRows; i++)
     {
       if(chkArray[i].checked == true)
       {
         j++;
         flag = true;
       }
     }
   }
 
   if(flag == false)
   {
     alert("No record selected. Please select one record and try again.");
      return false;
   }  
   if(j >= 2)
   {
     alert("Select only one record and try again."); 
      return false;
   } 
   return true;
   
   /*if(valForUpdate(numRows, chkMain, chkArray, tableName) == false)
      return;*/
}

 //Function to validate that only one checkbox is selected at a time
 function valForAtleastOneRowSelect(numRows, chkMain, chkArray, tableName)
 {
   var j = 0;
   var flag = false;
   if(numRows == 0)
   {
     alert("No record is present");
     return false;
   }

   if(numRows == 1)
   {
     if (chkArray.checked == false)
     {
       alert("No record(s) selected. Please select one record and try again.");
       return false;
     }
     else
       flag = true;
   }
   else
   {
     for(var i = 0 ; i < numRows; i++)
     {
       if(chkArray[i].checked == true)
       {
         j++;
         flag = true;
       }
     }
   }

   if(flag == false)
   {
     alert("No record selected. Please select one record and try again.");
      return false;
   }
   return true;

   /*if(valForUpdate(numRows, chkMain, chkArray, tableName) == false)
      return;*/
}

// To change checks to true or false
//In this function, we are checking tableName and browser type for dynamic table because chkArray work as array in IE and in firefox work as object. We are adding dynamic table row in editUser.jsp

function changeAllChecks(numRows, chkMain, chkArray, tableName, status)
{  
  chkMain.checked = status;

  if(numRows == 1)
  {
    if(tableName == "DynamicHTMLTable") 
    {
      if(getBrowserType() == "IE")
      {
        chkArray[0].checked = status;
      }
      else
        chkArray.checked = status;
    }
    else
    {
      chkArray.checked = status;
    }
  }
  if(numRows >1)
  {
    for(var k = 0; k < numRows; k++)
      chkArray[k].checked = status;
  }
} 
  
// In case of row highlighting feature this will clear the highlighting of rows if any
function changeToOriginalColor(arrSelectedRows)
{	
  while(arrSelectedRows.length > 0)
  {
    var rowId = arrSelectedRows.pop();
    //alert("rowId : " + rowId);
    var tr = document.getElementById('RowId' + rowId);
    //alert("tr : " + tr);
    tr.style.backgroundColor = tr.oldBackgroundColor;
  }
}

// This function will highlight the row selected by checkbox
// This will remove the mouse over and out highlighting functionality.

function changeColorOfSelectedRows(rowIdx, checkbox, arrSelectedRows)
{
 //alert("  checkbox.value " + checkbox.value);
  
  var tr = eval("document.getElementById(\"RowId" + rowIdx + "\")");
  
  if (checkbox.checked)
  {
    tr.oldBackgroundColor = tr.style.backgroundColor;
    tr.style.backgroundColor = "#FFCC00";
    //alert("element pushed : " + rowIdx);
		arrSelectedRows.push(rowIdx);
  	//alert("arrSelectedRows.length : " + arrSelectedRows.length);
  }
  else
  {
    tr.style.backgroundColor = tr.oldBackgroundColor;
  }
  
}

// This function will highlight the row selected by checkbox
// // This will remove the mouse over and out highlighting functionality.
//
  function changeColorOfSelectedRowsForTestSuite(rowIdx, checkbox, arrSelectedRows)
  {
    //alert("  checkbox.value " + checkbox.value + "rowIDx " + rowIdx);
    var tr = eval("document.getElementById(\"RowId" + rowIdx + "\")");
    if (checkbox.checked)
    {
      tr.oldBackgroundColor = tr.style.backgroundColor;
      tr.style.backgroundColor = "#DBECFB";
      
      //alert("element pushed : " + rowIdx);
      arrSelectedRows.push(rowIdx);
      //alert("arrSelectedRows.length : " + arrSelectedRows.length);
    }
    
    else                               
    {
      tr.style.backgroundColor = tr.oldBackgroundColor;
    }
  }  
                                                      
//This function uncheck the main check and check row on refresh.

function changeAllChecksOnRefrefresh(numRows, chkMain, chkArray, tableName, status)
{  
  chkMain.checked = status;
  if(numRows == 1)
  {
    if(tableName == "DynamicHTMLTable") 
    {
      if(getBrowserType() == "IE")
      {
        chkArray[0].checked = false;
        chkMain.checked = false;
      }
      else
      {
        chkArray.checked = false;
        chkMain.checked  = false; 
      }
    }
    else
    {
      chkArray.checked = false;
    }
  }
  if(numRows >1)
  {
    chkMain.checked = false;
    for(var k = 0; k < numRows; k++)
      chkArray[k].checked = false;
  }
}

//function to check whether browser is chrome
function isBrowserChrome()
{
 var chromeStr = navigator.userAgent.toLowerCase().indexOf('chrome');
 if(chromeStr == -1)
   return false;
 else
   return true;
} 

function uncheckReadOnly(numRows, chkArray)
{
  for(var k = 0; k < chkArray.length; k++)
  {
    if(chkArray.length == 1)
    {
      if(document.frmMain.chkRow.disabled == true)
        document.frmMain.chkRow.checked = false;    
    }
    else
    {
      if(document.frmMain.chkRow[k].disabled == true)
        document.frmMain.chkRow[k].checked = false;
    }
  }
}

// Change Main check based on the click on row check box
//In this function, we are checking tableName and browser type for dynamic table because chkArray work as array in IE and in firefox work as object. We are adding dynamic table row in editUser.jsp

function changeMainCheck(numRows, chkMain, chkArray, tableName)
{
  var flag = false;
  
  if(chkMain.checked == true)
    chkMain.checked = false; 
   
  if(numRows == 1)
  { 
    if(tableName == "DynamicHTMLTable")
    {
      if(getBrowserType() == "IE")
      {
        if(chkArray[0].checked == true)
          chkMain.checked = true;
      }
      else if(chkArray.checked == true)
        chkMain.checked = true;
    }
    else
    {
      if(chkArray.checked == true)
        chkMain.checked = true;
    }
  }
  if(numRows  > 1)
  {
    flag = false 
    for(i =0; i < numRows; i++)
    {
      
      if(chkArray[i].checked == false)
        flag = true ;
    }
    if(flag == false )
    {
      chkMain.checked = true;
    }
  }
}

// To copy checked status from one check to another
function copyChk(numSrc, idxSrc, chkArrSrc, numDest, idxDest, chkArrDest)
{
  if(numSrc == 1)
  {
    if(numDest == 1)
      chkArrDest.checked = chkArrSrc.checked;
    else
      chkArrDest[idxDest].checked = chkArrSrc.checked;    
  }
  else
  {
    if(numDest == 1)
      chkArrDest.checked = chkArrSrc[idxSrc].checked;
    else
      chkArrDest[idxDest].checked = chkArrSrc[idxSrc].checked;      
  }
}

function getOneCheckStatus(numRows, chkArray, index)
{
  if((numRows == 1) && (chkArray.checked == false))
    return(false);
  else if((numRows > 1) && (chkArray[index].checked == false))
    return(false);
  return(true);
}

function setOneCheckStatus(numRows, chkArray, index, status)
{
  if(numRows == 1)
    chkArray.checked = status;
  else
    chkArray[index].checked = status;
}

// Function to remove duplicate elements from an array
function removeDuplicateElementfromArray(arrayName)
{
  var newArray=new Array();
  label:for(var i=0; i<arrayName.length;i++ )
  {
    for(var j=0; j<newArray.length;j++ )
    {
      if(newArray[j]==arrayName[i]) 
        continue label;
    }
    newArray[newArray.length] = arrayName[i];
  }
  return newArray;
}

// Function to find out the browser type
function getBrowserType()
{
  if((navigator.appName.indexOf("Microsoft") > -1) || (navigator.appName.indexOf("MSIE") > -1))
  {
  
    
    return("IE");
  } 
  else
  {
    //alert("Firefox");
    return("Firefox");
  } 
}

function calPercentage(value, total)
{
  var per = parseInt(value * 100)/parseInt(total);
  // next lines are to make sure per is upto 2 decimal points
  per = per * 100;
  per = Math.round(per);
  per = per/100;
  
  return per; 
}

function getWidth(value)
{
  return (parseInt(window.screen.availWidth) * value);
}

function getHeight(value)
{
  return (parseInt(window.screen.availHeight) * value);
}

//these functions highlight the row when we pass/hover on current row
function over(row)
{
   row.oldBackgroundColor = row.style.backgroundColor;
  row.style.backgroundColor = 'FFFFCC';
}

function out(row)
{
  row.style.backgroundColor = row.oldBackgroundColor;
}

// This function is defined as we added this in header.jspf.
// This is dummy function to resolve this.
// If JSP need to do any work, add this function in JSP also.
function onUnLoadFunction() {}

function onBeforeUnLoadFunction() {}

//This function is used to replace all dot(.) to underscore(_)
function ReplaceAll(Source, stringToFind, stringToReplace)
{
  var temp = Source;
  var index = temp.indexOf(stringToFind);
  while(index != -1)
  {
    temp = temp.replace(stringToFind,stringToReplace);
    index = temp.indexOf(stringToFind);
  }
  return temp;
}

//This function is used to add host name with with window name
function getWindowNameForHost(windowName)
{
  var hostNameWithPort = window.location.host;
  
  //Here we are getting hostname without port
  hostNameWithPort = location.hostname;
  hostNameWithPort = ReplaceAll(hostNameWithPort, ".", "");
  hostNameWithPort = ReplaceAll(hostNameWithPort, "-", "");
  
  windowName = hostNameWithPort + "" + windowName;
  windowName = ReplaceAll(windowName, ",", "");
  //alert("  windowName  " + windowName);

  return windowName;
}

//This function is used to open window with different host
function openWindowNameForHost(url, windowName, windowParams)
{
  if((windowName == '_self') || (windowName == '_blank'))
    windowName = windowName;
  else  
    windowName = getWindowNameForHost(windowName);
  //alert("Test window name --  " + windowName);
  myWindow = window.open(url, windowName, windowParams);
  myWindow.focus();
}

function closeWindow()
{
  //var browserName = navigator.appName;
  //var browserVer = parseInt(navigator.appVersion);

  var ie7 = (document.all && !window.opera && window.XMLHttpRequest) ? true : false;  

  if (ie7) 
  {     
    //This method is required to close a window without any prompt for IE7
    window.open('','_parent','');
    window.close();
  }
  else 
  {
    //This method is required to close a window without any prompt for IE6
    //this.focus();
    self.opener = this;
    self.close();
  }
}

String.prototype.startsWith = function(str)
{ 
    return (this.indexOf(str) === 0); 
} 

//This function send request and get response without load whole page
function postRequest(strURL, sendParameter, formOperation) 
{
  //alert(strURL);
  var xmlHttp;
  if (window.XMLHttpRequest) 
  {
    // Mozilla, Safari, ...
       
    try 
    {
      xmlHttp = new XMLHttpRequest();
    } 
    catch (ex) 
    {
      xmlHttp = new window.ActiveXObject("Microsoft.XMLHTTP");
    }
  }
  else if (window.ActiveXObject)
  {
    // IE
    var xmlHttp = new ActiveXObject("Microsoft.XMLHTTP");
  }

  //opening conection to the server
  xmlHttp.open('POST', strURL, true);
  
  //content type is text/html
  xmlHttp.setRequestHeader('Content-Type', 'text/html');
  
  //if ready state is 4 means response are coming
  //you can add other condition, check success 200
  xmlHttp.onreadystatechange = function() 
  {
    if (xmlHttp.readyState == 4) 
    {
      //getting response
      getResponse(xmlHttp.responseText, sendParameter, formOperation);
    }
  }
  xmlHttp.send(sendParameter);
}

function portValidation(object)
{
  var port = object.value;

  if((port < 1) || (port > 65536))
  {
    alert("Port range should be lie between 1 to 65536");
    object.focus();
    return false;
  }
  return true;
}

//This function send request and get response without load whole page
function postRequestToSendLargeData(strURL, sendParameter, formOperation) 
{
  //alert(strURL);
  var xmlHttp;
  if (window.XMLHttpRequest) 
  {
    // Mozilla, Safari, ...
    var xmlHttp = new XMLHttpRequest();
  }
  else if (window.ActiveXObject)
  {
    // IE
    var xmlHttp = new ActiveXObject("Microsoft.XMLHTTP");
  }

  //opening conection to the server
  xmlHttp.open('POST', strURL, true);
  
  //content type is text/html
  xmlHttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");

  xmlHttp.setRequestHeader("Content-length", sendParameter.length);
  
  //if ready state is 4 means response are coming
  //you can add other condition, check success 200
  xmlHttp.onreadystatechange = function() 
  {
    if (xmlHttp.readyState == 4) 
    {
      //getting response
      getResponse(xmlHttp.responseText, sendParameter, formOperation);
    }
  }
 
  xmlHttp.send(sendParameter);
}

// In case of row highlighting feature this will clear the highlighting of rows if any
function changeToOriginalColorForRequestAndResponse(arrSelectedRows)
{	
  while(arrSelectedRows.length > 0)
  {
    var rowId = arrSelectedRows.pop();
    //alert("rowId : " + rowId);
    var tr = document.getElementById('RowId' + rowId);
    //alert("tr : " + tr);
    
    if(rowId%2 == 0)
    { 
      if(parseInt(labelRequestResponse.substring(1)) - 1 == rowId )
      {
        tr.style.backgroundColor = "#CED6EC";
        tr.oldBackgroundColor = '#CED6EC';
      }      
      else
      {
        tr.style.backgroundColor = "#FFFFF9"
        tr.oldBackgroundColor = '#FFFFF9';
      }
    } 
    else
    {
      if(parseInt(labelRequestResponse.substring(1)) - 1 == rowId )
      {
        tr.style.backgroundColor = "#CED6EC";
        tr.oldBackgroundColor = '#CED6EC';
      }    
      else
      {
        tr.style.backgroundColor = "#FFF9EC";
        tr.oldBackgroundColor = '#FFF9EC';
      }
    }  
     
  }
}

// This function will highlight the row selected by checkbox
// This will remove the mouse over and out highlighting functionality.

function changeColorOfSelectedRowsForRequestAndResponse(rowIdx, checkbox, arrSelectedRows)
{
  var tr = eval("document.getElementById(\"RowId" + rowIdx + "\")");
  
  if (checkbox.checked)
  {
    
    if(parseInt(labelRequestResponse.substring(1)) - 1 == rowIdx )
      tr.style.backgroundColor = "#CED6EC";
    else
      tr.style.backgroundColor = "#FFCC00";
      
    tr.oldBackgroundColor=tr.style.backgroundColor;
    arrSelectedRows.push(rowIdx);
   
  }
  else
  {
    if(parseInt(labelRequestResponse.substring(1)) - 1 == rowIdx )
    {
      tr.style.backgroundColor = "#CED6EC";
    }      
    else
    {
      if(rowIdx%2 == 0)
      { 
        tr.style.backgroundColor = "#FFFFF9"
        tr.oldBackgroundColor = '#FFFFF9';
      } 
      else
      {
        tr.style.backgroundColor = "#FFF9EC";
        tr.oldBackgroundColor = '#FFF9EC';
      }  
    
    }
  }
  
}
