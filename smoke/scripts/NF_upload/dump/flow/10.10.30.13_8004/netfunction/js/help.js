//---------------------------------------------------------------------------
//
//  Name   : help.js
//  Author : Prateek/Neeraj
//  Purpose: Controller GUI Online Help functions
//  Notes  :
//    None
//  Modification History:
//    02/15:05:Prateek:1.2.1 - Initial Version
//
//---------------------------------------------------------------------------

function openPerPageHelp()
{
  var helpId = window.open("/help/NetstormOnLineHelp.htm", "NetstormPerPageOnLineHelp", "toolbars=no, location=no, directories=no, status=no, menubar=no, scrollbars=yes, resizable=yes, copyhistory=no, left=50, top=50");
  helpId.focus();
}

function openFullHelp()
{
  var helpId = window.open("/help/NetstormOnLineHelp.htm", "NetstormOnLineHelp", "toolbars=no, location=no, directories=no, status=no, menubar=no, scrollbars=yes, resizable=yes, copyhistory=no, left=50, top=50");
  helpId.focus();
}