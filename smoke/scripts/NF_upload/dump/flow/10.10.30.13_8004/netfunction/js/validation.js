// Neeraj

// Neeraj - Controller jsp files use valEnteredKeyND in some cases which should be valEnteredKeyN. To be changed later


//This method check browser type and get event
function checkBrowser(event)
{
  if((navigator.appName.indexOf("Microsoft")>-1) || (navigator.appName.indexOf("MSIE")>-1))
  {    
    var enteredKey = event.keyCode;
    //alert(enteredKey);
  }
  else
  {    
    var enteredKey = event.which;  
    //alert(enteredKey);
  }
  
  return enteredKey;
}

// Validates entered key is  Alpha, Numeric, - or _ or .
// ANP == AlphaNumeric Plus - or _ or .
//Variable enteredKey == 0 is used for leftarrowkey,rightarrowkey,del
function valEnteredKeyANP(event)
{ 
  var enteredKey = checkBrowser(event);
  
  if((enteredKey >= 48 && enteredKey <= 57)||(enteredKey >= 65 && enteredKey<= 90)||(enteredKey >= 97 && enteredKey <= 122)||(enteredKey == 95)||(enteredKey == 45)||(enteredKey == 58)||(enteredKey == 46)||(enteredKey == 8)||(enteredKey == 0)) 
// if((enteredKey >= '0' && enteredKey <= '9')||(enteredKey >= 'A' && enteredKey<= 'Z')||(enteredKey >= 'a' && enteredKey <= 'z')||(enteredKey == '_')||(enteredKey == '-')||(enteredKey == ':')||(enteredKey == '.')||(enteredKey == 8)) 
  {     
    return true;
  }
  else
  {     
    return false;
  }
}


// Validates entered key is  Alpha, Numeric, - or _ 
// AN == AlphaNumeric Plus - or _ 
//Variable enteredKey == 0 is used for leftarrowkey,rightarrowkey,del
function valEnteredKeyAN(event)
{ 
  var enteredKey = checkBrowser(event);

  if((enteredKey >= 48 && enteredKey <= 57)||(enteredKey >= 65 && enteredKey<= 90)||(enteredKey >= 97 && enteredKey <= 122)||(enteredKey == 95)||(enteredKey == 45)||(enteredKey == 58)||(enteredKey == 8)||(enteredKey == 0))  
// if((enteredKey >= '0' && enteredKey <= '9')||(enteredKey >= 'A' && enteredKey<= 'Z')||(enteredKey >= 'a' && enteredKey <= 'z')||(enteredKey == '_')||(enteredKey == '-')||(enteredKey == ':')||(enteredKey == 8)) 
  {     
    return true;
  }
  else
  {     
    return false;
  }
}


// Validates entered key is  Numeric or .
// ND == Numeric or Decimal
function valEnteredKeyND(event)
{
  var enteredKey = checkBrowser(event);

  if((enteredKey >= 48 && enteredKey <= 57)||(enteredKey == 0) ||(enteredKey == 8)||(enteredKey == 46))
    return true;
  else
    return false;
}

// Validates entered key is  Numeric
// N == Numeric
function valEnteredKeyN(event)
{
  var enteredKey = checkBrowser(event);

  if((enteredKey >= 48 && enteredKey <= 57) ||(enteredKey == 0)|| (enteredKey == 8))
    return true;    
  else
    return false;
}

//Validates entered key is numeric if label is Count else entered key should be all except pipe
function valEnteredKeyNORAEP(event,varLabelId)
{
  var enteredKey = checkBrowser(event);
  var label = varLabelId.value;
 
  if(label.indexOf("Count") > -1)
  {
    if((enteredKey >= 48 && enteredKey <= 57) ||(enteredKey == 0)|| (enteredKey == 8))
      return true;    
    else
      return false;
  }
  else
  {
    if(enteredKey != 124)    
      return true;
    else     
      return false;
  }
}

function valEnteredKeyNColon(event)
{
  var enteredKey = checkBrowser(event);

  if((enteredKey >= 48 && enteredKey <= 57) ||(enteredKey == 0)|| (enteredKey == 8)|| (enteredKey == 58))
    return true;    
  else
    return false;
}

// Validates entered key is  all inputs including space except | .
// AEP == AllExceptPipe.
//Variable enteredKey == 0 is used for leftarrowkey,rightarrowkey,del
function valEnteredKeyAEP(event)
{ 
  var enteredKey = checkBrowser(event);

  if(enteredKey != 124) 
  {     
    return true;
  }
  else
  {     
    return false;
  }
}

//space not allowed
function valEnteredKeyNoSpace(event)
{
  var enteredKey = checkBrowser(event);
  if((enteredKey != 32))
    return true;    
  else
    return false;
}


// Validates entered key is  Alpha, Numeric, - or _ or . or ! or +.
// ANHUDEP == Alpha Numeric Hyphen Underscore Dot Exclamation Plus.
//Variable enteredKey == 0 is used for leftarrowkey,rightarrowkey,del
function valEnteredKeyANHUDEP(event)
{ 
  var enteredKey = checkBrowser(event);

  if((enteredKey >= 48 && enteredKey <= 57)||(enteredKey >= 65 && enteredKey<= 90)||(enteredKey >= 97 && enteredKey <= 122)||(enteredKey == 95)||(enteredKey == 45) ||(enteredKey == 46)||(enteredKey == 8)||(enteredKey == 0)||(enteredKey ==  33) || (enteredKey == 43))
  {     
    return true;
  }
  else
  {     
    return false;
  }
}

// Validates entered key is  Alpha, space
// N == A-Z, a-z 1-9  _ 
function valEnteredKeyANUnderscoreSpaceDash(event)
{ 
  
  var enteredKey = checkBrowser(event);
  
  if((enteredKey >= 48 && enteredKey <= 57)||(enteredKey >= 65 && enteredKey<= 90)||(enteredKey >= 97 && enteredKey <= 122)||(enteredKey == 95)||(enteredKey == 8)||(enteredKey == 0) || (enteredKey == 32) || (enteredKey == 45)) 
  {     
    return true;
  }
  else
  {     
    return false;
  }
}

function isNumeric(value)
{
  var invalidReqExp = /[^\d]/;
  return (!invalidReqExp.test(value));
}

/*Function start Here To restrict NetworkIp,StartIp,EndIp,Gateway 
  for entering only number and dot.
*/
function fillNumValidation(event)
{
  var enteredKey = checkBrowser(event);  

  if((keyPress>=48 && keyPress<=57)||(keyPress == 46)|| (keyPress == 0)|| (keyPress == 8))
    return true;
  else 
    return false;
}

// Validates entered key is  Numeric
// N == Numeric, +, -
function valEnteredKeyNPNSIGN(event)
{
  var enteredKey = checkBrowser(event);

  if((enteredKey >= 48 && enteredKey <= 57) ||(enteredKey == 0)|| (enteredKey == 8) || (enteredKey == '45') || (enteredKey == '43'))
    return true;    
  else
    return false;
}

// Validates entered key is  Alpha
// N == A-Z, a-z -
function valEnteredKeyALPHA(event)
{
  var enteredKey = checkBrowser(event);
  if((enteredKey >= 65 && enteredKey<= 90)||(enteredKey >= 97 && enteredKey <= 122) || (enteredKey == 8) || (enteredKey == 0) || (enteredKey == 45))
    return true;    
  else
    return false;
}

// Validates entered key is  Alpha
// N == A-Z, a-z 1-9 _-. space
function valEnteredKeyANUSPACE(event)
{
  var enteredKey = checkBrowser(event);
  if((enteredKey >= 65 && enteredKey<= 90)||(enteredKey >= 97 && enteredKey <= 122) || (enteredKey == 8) || (enteredKey == 0) || (enteredKey >= 48 && enteredKey <= 57) ||(enteredKey == 0)|| (enteredKey == 46) || (enteredKey == '45') || (enteredKey == '95')  || (enteredKey == '32'))
    return true;    
  else
    return false;
}

// Validates entered key is  Alpha
// N == A-Z, a-z 1-9 -
function valEnteredKeyANDASH(event)
{
  var enteredKey = checkBrowser(event);
  
  if((enteredKey >= 65 && enteredKey<= 90)||(enteredKey >= 97 && enteredKey <= 122) || (enteredKey == 8) || (enteredKey == 0) || (enteredKey >= 48 && enteredKey <= 57) ||(enteredKey == 0)|| (enteredKey == '45') || (enteredKey == '32'))
    return true;    
  else
    return false;
}

// Validates entered key is  Alpha
// N == A-Z, a-z 1-9 - without space
function valEnteredKeyANHYPHEN(event)
{
  var enteredKey = checkBrowser(event);
  
  if((enteredKey >= 65 && enteredKey<= 90)||(enteredKey >= 97 && enteredKey <= 122) || (enteredKey == 8) || (enteredKey == 0) || (enteredKey >= 48 && enteredKey <= 57) ||(enteredKey == 0)|| (enteredKey == '45'))
    return true;    
  else
    return false;
}

// Validates entered key is  Alpha
// N == A-Z, a-z 1-9  _ 
function valEnteredKeyANUnderscore(event)
{ 
  
  var enteredKey = checkBrowser(event);
  
  if((enteredKey >= 48 && enteredKey <= 57)||(enteredKey >= 65 && enteredKey<= 90)||(enteredKey >= 97 && enteredKey <= 122)||(enteredKey == 95)||(enteredKey == 8)||(enteredKey == 0)) 
  {     
    return true;
  }
  else
  {     
    return false;
  }
}



// Validates entered key is  Alpha
// N == A-Z, a-z 1-9 - : _ .
function valEnteredKeyANDCUDOT(event)
{
  var enteredKey = checkBrowser(event);
  
  if((key >= 65 && key<= 90)||(key >= 97 && key <= 122) || (key == '45') || (key == '58') || (key >= 48 && key <= 57) || (key == '95') || (key == '46') || (key == '8')|| (key == '0'))
    return true;    
  else
    return false;
}

function valEnteredKeyANDashUnderscore(event)
{ 
  
  var enteredKey = checkBrowser(event);
  
  if((enteredKey >= 48 && enteredKey <= 57)||(enteredKey >= 65 && enteredKey<= 90)||(enteredKey >= 97 && enteredKey <= 122)||(enteredKey == 95)||(enteredKey == 45)||(enteredKey == 8)||(enteredKey == 0)) 
  {     
    return true;
  }
  else
  {     
    return false;
  }
}

function valDelimeter(event)
{ 
  var enteredKey = checkBrowser(event);
  //alert(enteredKey);
  if(!((enteredKey == 92)||(enteredKey == 32)||(enteredKey == 39)||(enteredKey == 59) ||(enteredKey ==34) ||(enteredKey == 45) ||(enteredKey == 61))) 
  {     
    return true;
  }
  else
  {     
    return false;
  }
}

// Validates entered key is not comma
function valEnteredKeyAllExceptComma(event)
{
  var enteredKey = checkBrowser(event);

  if(enteredKey != 44)
    return true;
  else
    return false;
}

/*
  Function end here to restrict ip
*/

function valEnteredKeyANUnderscoreAndDOT(event)
{ 
  var enteredKey = checkBrowser(event);
  
  if((enteredKey >= 48 && enteredKey <= 57)||(enteredKey >= 65 && enteredKey<= 90)||(enteredKey >= 97 && enteredKey <= 122)||(enteredKey == 95)||(enteredKey == 8)||(enteredKey == 0) || (enteredKey == 46)|| (enteredKey == 45)) 
  {     
    return true;
  }
  else
  {     
    return false;
  }
}

