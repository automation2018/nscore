//-----------------------------------------------------------------------
//
//  Name   : adminUtils.js
//  Author : Jyoti
//  Purpose: Admin GUI utility JavaScript functions
//  Notes  :
//    None
//  Modification History:
//    01/15/09:Jyoti:3.2.2 - Initial Version
//-----------------------------------------------------------------------

function openRptWindow(url, win_name)
{
   var width = getWidth(.90);
   var height = getHeight(.80);
   var top = getWidth(.02);
   var left = getWidth(.05);   
   window.open(url, win_name, 'width=' + width + ',height=' + height + ',top=' + top + ',left=' + left + ',toolbar=no, location=0, directories=0, resizable=1, status=1, menubar=0, scrollbars=1');
}

// This function is for submitting same JSP
function submitJSP4(strOperName, strOperValue, strOperValue2, strOperValue3)
{
  document.frmMain.strOperName.value = strOperName;
  document.frmMain.strOperValue.value = strOperValue;
  document.frmMain.strOperValue2.value = strOperValue2;
  document.frmMain.strOperValue3.value = strOperValue3;

  document.frmMain.method = "POST"; // Make method POST so that all hidden variable and HTML fields go in the body
  document.frmMain.submit();
}

function validateUsername(userName)
{
  //var illegalChars = /\W/; // allow letters, numbers, and underscores
  userName.value = trimString (userName.value);

  if (userName.value == "")
  {
    alert("Please enter username.");
    userName.focus();
    return false;
  }
  
  else if ((userName.value.length < 1) || (userName.value.length > 24))
  {
    alert("User name should not be more than 24 characters.\n");
    userName.focus();
    return false;
  }
  var pattern = /^[a-zA-Z][a-zA-Z0-9_-]*$/;
  if (!userName.value.match(pattern))
  {    
    alert("Please enter valid user name.\r\nUser name must start with Alpha. \r\nAllowed characters are alpha, numeric and  special characters dash and underscore.");
    userName.focus();
    return false;
  }

  /*else if (illegalChars.test(userName.value))
  {
    alert("The username contains illegal characters.\n");
    userName.focus();
    return false;
  }
  */
  return true;
}

function validatePassword(password)
{
  var illegalChars = /[\W_]/; // allow only letters and numbers 

  if (password.value == "")
  {
    alert("Please enter password.\n");
    password.focus();
    return false;
  } 
  
  else if(password.value.length > 16)
  {
    alert("The password length must be between 1 to 16 character. \n");
    password.focus();
    return false;
  } 

  var pattern = /^[a-zA-Z][a-zA-Z0-9_.!+-]*$/;
  if (!password.value.match(pattern))
  {    
    alert("Please enter valid Password.\r\nPassword must start with Alpha. \r\nAllowed characters are alpha, numeric and  special characters _ - . !+.");
    password.focus();
    return false;
  }
  return true;
}

function validateEmail(emailAddress) 
{
  var tfld = trim(emailAddress.value); 
  // value of field with whitespace trimmed off
  var emailFilter = /^[^@]+@[^@.]+\.[^@]*\w\w$/ ;
  var illegalChars= /[\(\)\<\>\,\;\:\\\"\[\]]/ ;

  if (emailAddress.value == "") 
  {
    alert("Please enter email address.\n");
    emailAddress.focus();
    return false;
  }
  
  // validating email syntax and wellformness.
  
  var emailExp = /^[\w\-\.\+]+\@[a-zA-Z0-9\.\-]+\.[a-zA-z0-9]{2,4}$/;
  
  if(!emailAddress.value.match(emailExp))
  {
    alert("Please enter a valid email address.\n");
    emailAddress.focus();
    return false;
  }

  return true;
}
