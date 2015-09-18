//-----------------------------------
//  Name   : corrUtils.js
//  Author : jyoti
//  Purpose: Correlation GUI utility JavaScript functions
//  Notes  :
//    None
//  Modification History:
//    30/03/10  : jyoti :3.6.2 -Initial Version
//----------------------------------------------

//This function for title
function genTitle(title, noStrUrl, sessionUrl)
{
  if((title == "Services") || (noStrUrl != ""))
    document.write(title);
  else if(sessionUrl != "") 
    document.write(title + " - " + sessionUrl);

}

// This function is for submitting same JSP
function submitJSP(strOperName, strOperValue)
{
  document.frmMain.strOperName.value = strOperName;
  document.frmMain.strOperValue.value = strOperValue;
  document.frmMain.submit();
}

//This fuction will as as startswith Function
//e.g:((variableNamesArr1.toLowerCase()).startsWith(variableNamesArr2.toLowerCase()))

String.prototype.startsWith = function(str)
{ 
    return (this.indexOf(str) === 0); 
} 

function isValidTemplateName(tempName)
{
   var pattern = /^[a-zA-Z][a-zA-Z0-9_]*$/;
  if(tempName.value == "")
  {
    alert("Template name cannot be empty.");
    tempName.focus();
    return false;
  }

  if (!tempName.value.match(pattern))
  {
    alert("Please enter valid template name.\r\nIt must start with alpha.\r\nOther allowed characters are alpha, numeric or underscore");
    tempName.focus();
    return false;
  }


  if(tempName.value.length > 64)
  {
    alert("Template name is of maximum 64 characters.");
    tempName.focus();
    return false;
  }
  
  return true;
}

function isValidServiceName(tempName)
{
  var pattern = /^[a-zA-Z][a-zA-Z0-9_]*$/;
  
  if(tempName.value == "")
  {
    alert("Service name cannot be empty.");
    tempName.focus();
    return false;
  }
  
  if (!tempName.value.match(pattern))
  {
    alert("Please enter valid service name.\r\nIt must start with alpha.\r\nOther allowed characters are alpha, numeric or underscore");
    tempName.focus();
    return false;
  }


  if(tempName.value.length > 64)
  {
    alert("Service name is of maximum 64 characters.");
    tempName.focus();
    return false;
  }
  
  return true;
}

function isValidURL(tempName)
{
  var pattern = /^[a-zA-Z][a-zA-Z0-9_]*$/;
  
  if(tempName.value == "")
  {
    alert("Service name cannot be empty.");
    tempName.focus();
    return false;
  }
  
  if (!tempName.value.match(pattern))
  {
    alert("Please enter valid URL.\r\nIt must start with alpha.\r\nOther allowed characters are alpha, numeric or underscore");
    tempName.focus();
    return false;
  }


  if(tempName.value.length > 64)
  {
    alert("URL is of maximum 64 characters.");
    tempName.focus();
    return false;
  }
  
  return true;
}

//checking floating number and number
function valFloatNumber(varValue)
{
  var arrParts = varValue.value.split('.'); 
  if(arrParts.length > 2) 
  { 
    alert("Please enter valid number");
    varValue.focus();
    return false;
  }
}

//Validation function for parameter name
function valParameterName(variableName)
{
  if(variableName.value == "")
  {
    alert("Enter parameter name.");
    variableName.focus();
    return false;
  }

  var pattern = /^[a-zA-Z][a-zA-Z0-9_]*$/;
  if (!variableName.value.match(pattern))
  {    
    alert("Please enter valid parameter name.\r\nParameter name must start with Alpha.\r\nAllowed characters are alpha, numeric and  underscore");
    variableName.focus();
    return false;
  }
 
  if(variableName.value.length > 64)
  {
    alert("Please enter parameter name is of maximum 64 characters.");
    variableName.focus();
    return false;
  }
  return true;
}

if(!Array.indexOf){
  Array.prototype.indexOf = function(obj){
   for(var i=0; i<this.length; i++){
    if(this[i]==obj){
     return i;
    }
   }
   return -1;
  }
}



