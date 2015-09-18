//-----------------------------------------------------------------------
//
//  Name   : nsStringUtils.js
//  Author : Jyoti
//  Purpose: Utility JavaScript functions for handling strings
//  Notes  :
//    None
//  Modification History:
//    02/25/09 - Initial Version
//-----------------------------------------------------------------------

// This function is also in rptUtilsBean.java as this is now done in JSP code
function urlSubString(arrString)
{
  if(arrString.indexOf('?') != -1)
    arrString = arrString.substring(0, arrString.indexOf('?')) + "...";
  // Check for : from index 6 to skip http: or https:
  else if(arrString.indexOf(':', 6) != -1)
    arrString = arrString.substring(0, arrString.indexOf(':', 6)) + "...";
  
  if(arrString.length > 64)
    arrString = arrString.substring(0, 64) + "...";
  
  return arrString;
}

function trimString (str) 
{
  str = this != window? this : str;
  return str.replace(/^\s+/g, '').replace(/\s+$/g, '');
}

function trim(s)
{
  return s.replace(/^\s+|\s+$/, '');
} 

// JavaScript sees numbers with leading zeros as octal values, so strip zeros
function stripZeros(inputStr) 
{
  var result = inputStr
  while (result.substring(0,1) == "0")
  {
    result = result.substring(1,result.length)
  }
  return result
}

// Encode string for URL support
function scapeURL(strURL)
{
  var encodedStrURL=escape(strURL);

  encodedStrURL=encodedStrURL.replace("+", "%2B");
  encodedStrURL=encodedStrURL.replace("/", "%2F"); 

  return encodedStrURL;
}

function replaceAll(varb, replaceThis, replaceBy)
{
  newvarbarray=varb.split(replaceThis);
  newvarb=newvarbarray.join(replaceBy); 
  return newvarb;
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

//This function check decimal upto 3 place
function checkFloatValue(floatValue)
{
  checkFloatValueEx(floatValue, "");
}

//this method allow only numeric and dot value
//In case user copy paste value in IE
function valIntValue(object, keyName)
{  
  var pattern = /^[0-9]*$/;
  if (!object.value.match(pattern))
  { 
    if(keyName != "false")   
     alert("Please enter valid number.");
    object.focus();
    return false;
  }
   
  return true;
}

//this method allow only numeric and dot value
//In case user copy paste value in IE
function valFloatValue(object, keyName)
{  
  var pattern = /^[0-9.]*$/;
  if (!object.value.match(pattern))
  {    
    alert("Please enter valid number.");
    object.focus();
    return false;
  }
  
  return true;
}

//This function validate mix max value
function valMinMaxRange(object, keyName, min, max)
{
  if(keyName == "")
    keyName = "Value";
    
  if(object.value == "")
  {
    alert("Please enter value");
    object.focus()
    return false;
  }
  
  if(valFloatNumber(object) == false)
    return false;
    
  if((object.value < parseInt(min)) || (object.value > parseInt(max)))
  {
    alert(keyName + "should not be less than " + min + " or greater than " + max);
    object.focus()
    return false;
  }
  return true;
}

//This function validate float number, copy paste, range (in case of seconds)
function valIntSecondsValue(object, keyName)
{
  if(keyName == "")
    keyName = "Value";

  if(object.value == "")
  {
    alert("Please enter value");
    object.focus()
    return false;
  }
  
  if(valFloatValue(object, keyName) == false)
    return false;
    
  if(valFloatNumber(object) == false)
    return false;
    
  if((object.value < .001) || (object.value > 2147483))
  {
    alert(keyName + "should not be less than .001 or greater than 2147483");
    object.focus()
    return false;
  }
  return true;
}

//This function check decimal upto 3 place
function checkFloatValueEx(floatValue, field_name)
{

  if(valFloatNumber(floatValue) == false)
    return false;

  var arrSplitValue = floatValue.value.split(".");
  
  if(arrSplitValue.length > 1)
  {
    if(arrSplitValue[1] == "")
    {
      floatValue.value = arrSplitValue[0];
    }
  }
  
  if(floatValue.value.match(/^\d+(?:\.\d{0,3})?$/))
  {
  }
  else
  {
    alert("Upto to three decimal places allowed in the field " + field_name);
    floatValue.focus();
    return false;
  }  
  return true;
}


//this method allow values of it's values type
//In case user copy paste value in 
function valValidateName(object , Key)
{  
  var numberPattern = /^[0-9]+$/;         
  var numberWithStarPattern = /^[0-9*]+$/;  
 
  if(Key == 'numberValidation')
  {
    if (!object.value.match(numberPattern))
    {    
      alert("Please enter valid number");
      object.focus();
      return false;
    }
  }
  
  else if(Key == 'numberWithStarValidation')
  {
    if (!object.value.match(numberWithStarPattern))
    {    
      alert("In special character * and Number would be allowed only.");
      object.focus();
      return false;
    }  
  }
  return true;
}