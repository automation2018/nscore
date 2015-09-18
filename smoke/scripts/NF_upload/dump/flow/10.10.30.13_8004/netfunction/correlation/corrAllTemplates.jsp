<!--  
  Name    : corrAllTemplates.jsp
  Author  : Ritesh Sharma
  Purpose : 
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
var arrIndex = new Array();
var selectedRows=new Array();
var noOfSelectedRows = 0;
var arrTemplatesName = new Array()
var arrTemplateStatus = new Array()
var arrTemplateCondtion = new Array()

arrIndex[0] = '0'
arrTemplatesName[0] = 'test'
arrTemplateStatus[0] = 'active'
arrTemplateCondtion[0] = 'NA'
arrIndex[1] = '1'
arrTemplatesName[1] = 'Test'
arrTemplateStatus[1] = 'active'
arrTemplateCondtion[1] = 'CompleteRequestMatch'

  
var templateCount =2; 
var tableName = "Templates";
var shiftLastCheckVaue=null;//this value for multiple shift
var lastId=null;
var TotalTemplate = 2;;
var varProduct = "";
function onLoadFunction()
{

 if('' == "OKDetail" ||  '' == "delTemplate" || '' == "NotLoad"|| '' == "delTemplate")
  {  
    //parent.Left_Response.location.reload();
  }
  document.frmMain.Update.disabled = true;
  document.frmMain.Update.style.color = 'AEA0BF';
  document.frmMain.Delete.disabled = true; 
  document.frmMain.Delete.style.color = 'AEA0BF';  
  document.frmMain.Active.disabled = true;
  document.frmMain.Active.style.color = 'AEA0BF';
  
  //Check for Observer Group Users.
   
}

//Disable controls if user is of Observer group.
function disableControls()
{
  document.frmMain.Add.disabled = true;
  document.frmMain.Add.style.color = 'AEA0BF';
  
  document.frmMain.Delete.disabled = true;
  document.frmMain.Delete.style.color = 'AEA0BF';
  
  document.frmMain.Update.disabled = true;
  document.frmMain.Update.style.color = 'AEA0BF';
  
  document.frmMain.Active.disabled = true;
  document.frmMain.Active.style.color = 'AEA0BF';
}

 if('NF'=='NF')
    varProduct='NetFunction';
  else
    varProduct='NetOcean';
    
function getSelectedSelectedTemplates()
{
  var SelectedTemplate = "NotSelected";
  if(templateCount > 1)
  {
    for(var i = 0; i < templateCount; i++)
    {
      if(document.frmMain.chkRow[i].checked == true)
        SelectedTemplate = document.frmMain.chkRow[i].value; 
    }
  }
  else
    SelectedTemplate = document.frmMain.chkRow.value; 
  return(SelectedTemplate);
}

function clickAdd()
{
  submitJSP("addTemplate", "")
}

function getHeightTable()
{
  return getHeight(.45);
}

//if data is null the resizable will not be done
function getTableLengthtStatus()
{
  return false;
}


function clickUpdate()
{
 if(valForUpdate(templateCount, document.frmMain.chkMain, document.frmMain.chkRow, tableName) == false)
   return;

  submitJSP("updateTemplate", "");
}

function viewTemplateDetails(rowId)
{
  submitJSP("updateTemplate", rowId);
}

function clickCancel()
{
  window.top.close();  
}

//this function is used to check the all active template is selected or not.
function atleastOneActiveTemplate()
{
  var j = 0; 
  var checkStatus = false
  
  if(templateCount > 1)
  {
    for(var i = 0 ; i < templateCount; i++)
    {
      if(document.frmMain.chkRow[i].checked == false)
      { 
        if(arrTemplateStatus[parseInt(document.frmMain.chkRow[i].value)] == 'active')
          return false;
        else
          checkStatus = true;
      }
    }
  }
  
  if(templateCount == 1)
  {
    checkStatus = true;
  }
 
  return checkStatus;
}

function clickActive()
{
  if(document.frmMain.Active.value == 'Inactive')
  {
    if(atleastOneActiveTemplate() == true || getNoOfSelectedRows() == templateCount)
    { 
        alert("All active templates are selected, atleast one active template should be remain in Service.");
        return;
    }
    else if(getNoOfSelectedRows() > 1)
    { 
       // if(confirm("Are you sure to inactive the templates?") == false)
       //  return;
         
        submitJSP("activeTemplate", "inactive");
    }
    else
    {
      //if(confirm("Are you sure to inactive the '" + arrTemplatesName[getSelectedSelectedTemplates()] + "'?") == false)
      //  return 
         
       submitJSP("activeTemplate", "inactive");  
    }
  }
  else
  {
    if(doActiveTemplate() == false)
      return ;
    
  }
  
}

function doActiveTemplate()
{
  var j = 0; 
 
  var unslectedActive = 0;
  var arrActSelectedIndex = new Array();
  var arrInactSelectedIndex = new Array();
  var arrInactiveWithCond = new Array();
  var unselectedInActiveWithCondition = 0;
  
  var slectedActive = 0;
  var selectedInActiveWithCondition = 0;
  
  if(templateCount > 1)
  {
    for(var i = 0 ; i < templateCount; i++)
    {
      if(document.frmMain.chkRow[i].checked == false)
      { 
        if(arrTemplateStatus[parseInt(document.frmMain.chkRow[i].value)] == 'active')
        {
          if(arrTemplateCondtion[parseInt(document.frmMain.chkRow[i].value)] == 'NA')
          {
           arrActSelectedIndex[unslectedActive] = document.frmMain.chkRow[i].value;
           unslectedActive++;
          }
          else
           unselectedInActiveWithCondition++;
        
        }
      }
    }
  }
  
  if(templateCount > 1)
  {
    for(var i = 0 ; i < templateCount; i++)
    {
      if(document.frmMain.chkRow[i].checked == true)
      { 
        if(arrTemplateStatus[parseInt(document.frmMain.chkRow[i].value)] == 'inactive')
        {
          if(arrTemplateCondtion[parseInt(document.frmMain.chkRow[i].value)] == 'NA')
          {
            arrInactSelectedIndex[slectedActive] = document.frmMain.chkRow[i].value;
            slectedActive++;
          }
          else
          {
            arrInactiveWithCond[selectedInActiveWithCondition] = document.frmMain.chkRow[i].value;
            selectedInActiveWithCondition++;
          }
          
        }
      }
    }
  }
  
  if(templateCount == 1)
  {
    if(document.frmMain.chkRow.checked == false)
    { 
      if(arrTemplateStatus[parseInt(document.frmMain.chkRow.value)] == 'active')
      {
        if(arrTemplateCondtion[0] == 'NA')
        {
          arrActSelectedIndex[unslectedActive] = document.frmMain.chkRow.value;
          unslectedActive++;
        }
        else
          unselectedInActiveWithCondition++;    
      }
    }
    else
    { 
      if(arrTemplateStatus[parseInt(document.frmMain.chkRow.value)] == 'inactive')
      {
        if(arrTemplateCondtion[0] == 'NA')
        {
          arrInactSelectedIndex[slectedActive] = document.frmMain.chkRow[i].value;
          slectedActive++;
        }
        else
        {
          arrInactiveWithCond[selectedInActiveWithCondition] = document.frmMain.chkRow.value;
          selectedInActiveWithCondition++; 
        }
      }
    
    }
  }
  
  
  if(unslectedActive == slectedActive && unslectedActive != 0 )
  {
     var inActTemp = arrTemplatesName[arrInactSelectedIndex[0]]; 
     
     for(var i  = 0 ; i <  arrInactiveWithCond.length ; i++)
     {
       inActTemp = inActTemp + "%%" + arrTemplatesName[arrInactiveWithCond[i]];
     }
     
     var activeTempl = arrTemplatesName[arrActSelectedIndex[0]];
     
     if(confirm("Other templates are already active without condition.\nPlease specify condition when this template should be selected for use  by "+ varProduct +".\nDo you want to make other template inactive and this template active ?") == false) 
       return false;
     else
      submitJSP("activeAndInactiveTemplate", activeTempl + ";" + inActTemp);
  } 
  else if(unslectedActive + slectedActive > 1 )
  { 
    alert("Only one template can be active without condition.");
    return false;
  }
  else
  {
    if(getNoOfSelectedRows() > 1)
    { 
      submitJSP("activeTemplate", "active");
    }
    else
    {
      submitJSP("activeTemplate", "active");  
    }
  }
   
}

function clickDelete()
{   
 
  if(atleastOneActiveTemplate() == true || getNoOfSelectedRows() == templateCount)
  { 
    alert("All active templates are selected, atleast one active template should be remain in Service.");
    return;
  }
  else if(getNoOfSelectedRows() > 1)
  { 
    if(confirm("Are you sure to delete selected templates?") == false)
     return;
     
    submitJSP("delTemplate", "");
  }
  else
  {
    if(confirm("Are you sure to delete template '" + arrTemplatesName[getSelectedSelectedTemplates()] + "'?") == false)
     return 
     
    submitJSP("delTemplate", "");  
  }
 
}

//this function is used to check the all active template is selected or not.
function selectedActiveTemplate()
{
  var j = 0; 
  var checkStatus = "NA";
  var active = "";
  var inactive = "";
  
  if(templateCount > 1)
  {
    for(var i = 0 ; i < templateCount; i++)
    {
      if(document.frmMain.chkRow[i].checked == true)
      { 
        if(arrTemplateStatus[parseInt(document.frmMain.chkRow[i].value)] == 'active')
          active = active +  "active";
        else
          inactive = inactive + "inactive";
      }
    }
  }
  
  
  if(templateCount == 1)
  {
    checkStatus = "";
  }
  
  if((active == "") && (inactive  != ""))
  {
    checkStatus = "inactive";
  }
  else if((active != "") && (inactive  == ""))
  {
    checkStatus = "active";
  }
  else
   checkStatus = "NA"
   
  return checkStatus;
}

function clickChkMain()
{ 

  if(document.frmMain.chkMain.checked)
  {
    document.frmMain.Update.disabled = true;
    document.frmMain.Update.style.color = 'AEA0BF';
    document.frmMain.Delete.disabled = true;
    document.frmMain.Delete.style.color = 'AEA0BF';
  
    if(templateCount == '1')
    {
      document.frmMain.Update.disabled = false;
      document.frmMain.Update.style.color = '';
    }
    
    var checkStatus = selectedActiveTemplate();
    
     // alert(selectedActiveTemplate());
    if (checkStatus == "active" )
    {
      document.frmMain.Active.value = "Active";
      document.frmMain.Active.disabled = true;
      document.frmMain.Active.style.color = 'AEA0BF';
      //alert("atleast one template is active");
    }
    else if(checkStatus=="inactive")
    {
      document.frmMain.Active.disabled = true;
      document.frmMain.Active.style.color = 'AEA0BF';
    }
    else
    {
      document.frmMain.Active.value = "Active";   
      document.frmMain.Active.disabled = true;
      document.frmMain.Active.style.color = 'AEA0BF';
    }
  }
  else
  {
    document.frmMain.Update.disabled = true;
    document.frmMain.Update.style.color = 'AEA0BF';
    document.frmMain.Delete.disabled = true;
    document.frmMain.Delete.style.color = 'AEA0BF';
    document.frmMain.Active.value = "Active";
    document.frmMain.Active.disabled = true;
    document.frmMain.Active.style.color = 'AEA0BF';
  }
 
 shiftLastCheckVaue=null;
  
 changeAllChecksByChangeColorNO(templateCount, document.frmMain.chkMain, document.frmMain.chkRow, "" , document.frmMain.chkMain.checked,arrSelectedRows);
 
 //Check for Observer Group Users.
  
}


function clickChkRow(checkEvent,id)
{
  document.frmMain.Active.value = "Active";
  document.frmMain.Active.disabled = true;
  document.frmMain.Active.style.color = 'AEA0BF';
  
  var checkStatus = selectedActiveTemplate();

  var noOfSelectedRows =  getNoOfSelectedRows()
  if(noOfSelectedRows == '1')
  {
    document.frmMain.Update.disabled = false;
    document.frmMain.Update.style.color = '';
    document.frmMain.Delete.disabled = false;
    document.frmMain.Delete.style.color = '';

    //only for one checked row
    if(checkStatus == "active" )
    {
      document.frmMain.Active.value = "Inactive";  
      document.frmMain.Active.disabled = false;
      document.frmMain.Active.style.color = '';
    }
    else if(checkStatus == "inactive")
    { 
      document.frmMain.Active.value = "Active";
      document.frmMain.Active.disabled = false;
      document.frmMain.Active.style.color = '';
    }
    else
    {
      document.frmMain.Active.value = "Active";
      document.frmMain.Active.disabled = true;
      document.frmMain.Active.style.color = 'AEA0BF';
    }
    
    if(templateCount == noOfSelectedRows)
    {
      document.frmMain.Delete.disabled = true;
      document.frmMain.Delete.style.color = 'AEA0BF';
    }
    
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
    
    //alert(cheakStatus);
    if(checkStatus == "active" )
     {
      document.frmMain.Active.value = "Inactive";  
      document.frmMain.Active.disabled = false;
      document.frmMain.Active.style.color = '';
     }
     else if(checkStatus == "inactive")
     { 
       document.frmMain.Active.value = "Active";
       document.frmMain.Active.disabled = false;
       document.frmMain.Active.style.color = '';
     }
     else
     {
       document.frmMain.Active.value = "Active";
       document.frmMain.Active.disabled = true;
       document.frmMain.Active.style.color = 'AEA0BF';
     } 
     
     if(templateCount == noOfSelectedRows)
     {
       document.frmMain.Delete.disabled = true;
       document.frmMain.Delete.style.color = 'AEA0BF';
     }
    
  }
 //put the shiftLastCheckVaue as ckecked checkbox and in else condition  shiftLastCheckVaue is null
  
   if(checkEvent.checked)
   shiftLastCheckVaue=checkEvent;
   
   else
   shiftLastCheckVaue=null;
  
   lastId=id;
   changeMainCheck(templateCount, document.frmMain.chkMain, document.frmMain.chkRow, "");
   
   //Check for Observer Group Users.
    
  }

function getNoOfSelectedRows()
{
  var j = 0; 
  if(templateCount > 1)
  {
    for(var i = 0 ; i < templateCount; i++)
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

  return j;
}

function setupTableSort()
{
  var st = new SortableTable(document.getElementById("showSelectedTemplateId"),
    ["None", "String", "String","String", "Number", "Number", "Number"]);
  SortableTable.prototype.addSortType("String", SortableTable.toUpperCase);
  SortableTable.prototype.addSortType("String", SortableTable.toUpperCase);
  SortableTable.prototype.addSortType("String", SortableTable.toUpperCase);  
  restoreCheckBoxesForSorting(st);
}

function getWidthColumn(percent)
{
  var w=parseInt(window.screen.availWidth);
  w=w*(.98);
  var value=(w*percent)/100;
  return value;
}

function getCookie(c_name)
{

var i,x,y,ARRcookies=document.cookie.split(";");
for (i=0;i<ARRcookies.length;i++)
{
  x=ARRcookies[i].substr(0,ARRcookies[i].indexOf("="));
  y=ARRcookies[i].substr(ARRcookies[i].indexOf("=")+1);
  x=x.replace(/^\s+|\s+$/g,"");
  if (x==c_name)
  {
    if(unescape(y) == "null" || unescape(y) == ""){
      return '3%%30%%10%%50%%7';}
    else
    {  
      return unescape(y);
    }  
  }
}
   
  return '3%%30%%10%%50%%7';
}

function setCookie(c_name,exdays)
{
 
  table = document.getElementById("showSelectedTemplateId");
  //alert(getBrowserType())
  if(getBrowserType() == "IE")
    value=getColumnWidthPixel(table.rows[0].cells[0].offsetWidth+3)+"%%"+getColumnWidthPixel(table.rows[0].cells[1].offsetWidth)+"%%"+getColumnWidthPixel(table.rows[0].cells[2].offsetWidth)+'%%'+getColumnWidthPixel(table.rows[0].cells[3].offsetWidth)+'%%'+getColumnWidthPixel(table.rows[0].cells[4].offsetWidth);
  else 
    value=getColumnWidthPixel(table.rows[0].cells[0].offsetWidth+3)+"%%"+getColumnWidthPixel(table.rows[0].cells[1].offsetWidth-2)+"%%"+getColumnWidthPixel(table.rows[0].cells[2].offsetWidth-2)+'%%'+getColumnWidthPixel(table.rows[0].cells[3].offsetWidth-2)+'%%'+getColumnWidthPixel(table.rows[0].cells[4].offsetWidth-2);
  var exdate=new Date();
  exdate.setDate(exdate.getDate() + exdays);
  var c_value=escape(value) + ((exdays==null) ? "" : "; expires="+exdate.toUTCString());
  //alert(c_value);
  document.cookie=c_name + "=" + c_value;
}

function editCell(cell,i)
{
  if (document.all)
  {
    cell.innerHTML =
    '<INPUT ' + ' ID="editCellNotes"' + ' ONCLICK="event.cancelBubble = true;" title="Press ENTER to apply change."' + 
    ' VALUE="' + (parseInt(arrIndex[i]) +1) + '"' + 'onBlur="undoChangesNotes(this.parentElement, '+i+');"' + 'onKeypress="return valEntered_Valid_Number(this.parentElement, event, this.value, '+i+');"' + 
    ' SIZE="4"' +
    '>';
    
    document.all.editCellNotes.focus();
    document.all.editCellNotes.select();
  }
  else if (document.getElementById) 
  {
    cell.normalize();
    var input = document.createElement('INPUT');
    
    input.setAttribute('value', parseInt(arrIndex[i]) +1);
    input.setAttribute('size', "4");
    input.setAttribute('title', "Press ENTER to apply change.");
    input.onblur = function(evt){ undoChangesNotes(this.parentNode,i); return;};
    
    input.onkeypress = function (e) {
      e || (e = window.event);
      if (valEntered_Valid_Number(this.parentNode,e,this.value,i));
    }    
    
 
    input.onclick = function (evt) 
    { 
      evt.cancelBubble = true;
      if (evt.stopPropagation)
        evt.stopPropagation();
    };
    cell.replaceChild(input, cell.firstChild);
    input.focus();
    input.select();
  }
}

function undoChangesNotes(cell, i)
{
  
  if (document.all)
  {
    cell.innerText = parseInt(arrIndex[i])+1;
  }
  else if (document.getElementById)
    cell.replaceChild(document.createTextNode(parseInt(arrIndex[i])+1), cell.firstChild);
  
}

function setCell (cell, value, i) 
{

  if (document.all)
  {
    if(value > arrIndex.length)
    { 
      cell.innerText = parseInt(arrIndex[i]) +1;
      alert("Sequence must be less then tolal number of response template.")
      return;
    }
    
    cell.innerText = value;
  }  
  else if (document.getElementById)
  {
    //cell.replaceChild(document.createTextNode(value), cell.firstChild);
  }  
  
  submitJSP("changeSequence", arrTemplatesName[i] + "%%" + value);
}

function valIntValueCheck(object)
{  

  var pattern = /^[1-9]*$/;
  if (!object.match(pattern))
  {    
    return false;
  }
   
  return true;
}

function valEntered_Valid_Number(cell, event, value, i)
{
  if((navigator.appName.indexOf("Microsoft")>-1) || (navigator.appName.indexOf("MSIE")>-1))
  {    
    var enteredKey = event.keyCode;
  }
  else
  {    
    var enteredKey = event.which;  
  }

  if(enteredKey == 13)
  {
    var pattern = /^[|'"]*$/;

    if(value == "")
      setCell(cell,parseInt(arrIndex[i]) +1,i); 
 
    else if (valIntValueCheck(value) == false)
    {    
      alert("Please enter valid sequence.\r\n"); 
      
      if(arrIndex.length > 1)
      {
        if(!document.frmMain.chkRow[i].checked)
        {
        rowIdx = "RowId" + i;
        var tr = eval("document.getElementById( rowIdx)");
        if(i%2==0)
          tr.style.backgroundColor = 'F7FCFF';
        else
          tr.style.backgroundColor = 'white';
        }  
      }
      else
      {  
        if(!document.frmMain.chkRow.checked)
        {
	  rowIdx = "RowId" + i;
	  var tr = eval("document.getElementById( rowIdx)");
	  if(i%2==0)
	    tr.style.backgroundColor = 'F7FCFF';
	  else
	   tr.style.backgroundColor = 'white';
        }  
      
      }
        
      return false;
    }
    else if(value > arrIndex.length)
    { 
      //cell.replaceChild(document.createTextNode(parseInt(arrIndex[i])+1), cell.firstChild);
      alert("Sequence can not be more than " + (arrIndex.length) + " (Total number of response templates).")
      rowIdx = "RowId" + i;
      if(arrIndex.length > 1)
      {
        if(!document.frmMain.chkRow[i].checked)
        {
        rowIdx = "RowId" + i;
        var tr = eval("document.getElementById( rowIdx)");
        if(i%2==0)
          tr.style.backgroundColor = 'F7FCFF';
        else
          tr.style.backgroundColor = 'white';
        }  
      }
      else
      {  
        if(!document.frmMain.chkRow.checked)
        {
	  rowIdx = "RowId" + i;
	  var tr = eval("document.getElementById( rowIdx)");
	  if(i%2==0)
	    tr.style.backgroundColor = 'F7FCFF';
	  else
	   tr.style.backgroundColor = 'white';
        }  
      
      }      return;
    }
    else
      setCell(cell,value,i); 
  }
}

function showSelectedTemplate()
{ 
  var wdh = new Array();
  wdh = getCookie('showSelectedTemplateId').split("%%");
  '3%%30%%10%%50%%7';
  document.write("<table cellpadding=0 cellspacing=0 width=98% valign=top border=0 align=center>");
  document.write("<tr><td><table border=0 width=100%> <tr><td align=left style = 'font-size:9px; color: #6F6FD0 ; font-weight: bold; text-align:left'>&nbsp;&nbsp;&nbsp;&nbsp;Sequence shows the order in which the conditions will be evaluated. Template with first matching condition is used for response. Default template \(one without condition\) is used if no other conditions match.</td></tr></table></td></tr><tr><td>");

  document.write("<table  cellpadding='0' cellspacing='0' class='scrollbarColorChange' width=100%><tr><td class=''></td></tr><tr> <td align='center' valign='top'><table width='98%' cellpadding='0' cellspacing='0'>");

  document.write("<table cellpadding=0 cellspacing=0 width=98% valign=top align=center border=0>");
  document.write("<tr><td><div id='ScrollablePane' STYLE='overflow:auto; width:100%; height:" + getHeight(.35) + "px; border:1px solid #DFE9F7;'>");
  document.write("<table style='{table-layout:fixed}' class='resizable' border=0 id=showSelectedTemplateId cellpadding=0 cellspacing=0  width=100% align=center>");
  document.write("<thead id='pfh'>");
  document.write("<tr class = tableHeaderLockedEnhance >");
  document.write("<th width=3% class='tableCell'  align=left  onmouseOver=setCookie('showSelectedTemplateId',1)><input type = checkbox name = chkMain onclick = 'clickChkMain();' value='1'></th>");
  document.write("<th width=30% class='tableCell'  align=left title='Click to sort on Template Name' nowrap onmouseOver=setCookie('showSelectedTemplateId',1)><b style='cursor:"+getStyleCursor()+"'>&nbsp;&nbsp;Template&nbsp;Name</b></th>");
  document.write("<th width=10% class='tableCell'  align=left title='Click to sort on Status' nowrap onmouseOver=setCookie('showSelectedTemplateId',1)><b style='cursor:"+getStyleCursor()+"'>&nbsp;&nbsp;Status</b></th>");
 
  document.write("<th width=7% class='tableCell'  align=right title='Click to sort on Sequence' nowrap onmouseOver=setCookie('showSelectedTemplateId',1)><b style='cursor:"+getStyleCursor()+"'>&nbsp;&nbsp;Sequence&nbsp;</b></th>");
   
  document.write("<th width=50% class='tableCell'  align=left title='Click to sort on Condtition' nowrap onmouseOver=setCookie('showSelectedTemplateId',1)><b style='cursor:"+getStyleCursor()+"'>&nbsp;&nbsp;Condition</b></th>");
  
  document.write("</thead>");
  
  
        document.write("<tr id=\"RowId" + 0 + "\" class = tableRowEvenNew onmouseout=outMouse(id) onmouseover=overMouse(id)>");
      
      document.write("<td width="+wdh[0]+" class='tableCell' align = left ><input type='checkbox' name='chkRow'  value = 0 onclick = \"changeColorOfSelectedRowsByCheck(" + 0 + ",this,arrSelectedRows);if(event.shiftKey||event.ctrlKey)shiftCheck(lastId," +0+ ",this,event.shiftKey||event.ctrlKey,shiftLastCheckVaue,arrIndex);clickChkRow(this,'0');\"></input></td>");
  
      //document.write("<td class='tableCell' align=left>&nbsp;&nbsp;test</td>");
      document.write("<td  width="+wdh[1]+" class='tableCell' align=left nowrap>&nbsp;&nbsp;<a href=javascript:viewTemplateDetails('0')>test</a></td>");
      
      document.write("<td width="+wdh[2]+" nowrap class='tableCell' align=left >&nbsp;active&nbsp;</td>");
      
      document.write("<td  align='right' style='overflow:hidden;text-overflow:ellipsis'  title = 'Click to edit' class='tableCell' onclick='editCell(this,0)'>1&nbsp;&nbsp;</td>");
      if('NA' == 'NA' && 'active' == 'active')
        document.write("<td  style='overflow:hidden;text-overflow:ellipsis;font-size:9px; color: #6F6FD0 ; font-weight:bold; text-align:left'class='tableCell'  align=left nowrap title='--default template--'  ><i>&nbsp;&nbsp;--default template--</i></td>");
      else  
      {
        var conditionTemp = ReplaceAll('NA' , "\\n" , "<br/>&nbsp;")
        document.write("<td  style='overflow:hidden;text-overflow:ellipsis' class='tableCell'  align=left nowrap title=\"NA\">&nbsp;&nbsp;" + conditionTemp + "</td>");
      }
      
      document.write("</tr>");
    
        document.write("<tr id=\"RowId" + 1 + "\" class = tableRowOddNew onmouseout=outMouse(id) onmouseover=overMouse(id)>");
      
      document.write("<td width="+wdh[0]+" class='tableCell' align = left ><input type='checkbox' name='chkRow'  value = 1 onclick = \"changeColorOfSelectedRowsByCheck(" + 1 + ",this,arrSelectedRows);if(event.shiftKey||event.ctrlKey)shiftCheck(lastId," +1+ ",this,event.shiftKey||event.ctrlKey,shiftLastCheckVaue,arrIndex);clickChkRow(this,'1');\"></input></td>");
  
      //document.write("<td class='tableCell' align=left>&nbsp;&nbsp;Test</td>");
      document.write("<td  width="+wdh[1]+" class='tableCell' align=left nowrap>&nbsp;&nbsp;<a href=javascript:viewTemplateDetails('1')>Test</a></td>");
      
      document.write("<td width="+wdh[2]+" nowrap class='tableCell' align=left >&nbsp;active&nbsp;</td>");
      
      document.write("<td  align='right' style='overflow:hidden;text-overflow:ellipsis'  title = 'Click to edit' class='tableCell' onclick='editCell(this,1)'>2&nbsp;&nbsp;</td>");
      if('CompleteRequestMatch' == 'NA' && 'active' == 'active')
        document.write("<td  style='overflow:hidden;text-overflow:ellipsis;font-size:9px; color: #6F6FD0 ; font-weight:bold; text-align:left'class='tableCell'  align=left nowrap title='--default template--'  ><i>&nbsp;&nbsp;--default template--</i></td>");
      else  
      {
        var conditionTemp = ReplaceAll('CompleteRequestMatch' , "\\n" , "<br/>&nbsp;")
        document.write("<td  style='overflow:hidden;text-overflow:ellipsis' class='tableCell'  align=left nowrap title=\"CompleteRequestMatch\">&nbsp;&nbsp;" + conditionTemp + "</td>");
      }
      
      document.write("</tr>");
    
  
  
  document.write("<tbody>");
  
  document.write("</tbody>");  

  setupTableSort();
  document.write("</table>");
  document.write("</td></tr>");

  document.write("<tr><td valign=top align=center>");
  document.write("<br>");

  document.write("<input type=Button class=button style='width:60;' value = 'Add' name = 'Add' onclick = 'clickAdd();'>&nbsp;");  
  document.write("<input type=Button class=button style='width:60;' value = 'Delete' name = 'Delete' onclick = 'clickDelete();'>&nbsp;");  
  document.write("<input type=Button class=button style='width:60;' value = 'Update' name = 'Update' onclick = 'clickUpdate();'>&nbsp;");  
  // document.write("<input type=Button class=button style='width:60;' value = 'Close' name = 'Close' onclick = 'clickCancel();'>&nbsp;");
  document.write("<input type=Button class=button style='width:60;' value = 'Active' name = 'Active' onclick = 'clickActive();'>&nbsp;");

  
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
<title>NetFunction (Controller_Proxy) - All Templates</title>

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
         
         <tr><td colspan="2" align="left" class="screenTitleWithout" title = '/cavisson.com'><b><script> genTitle("All Templates","","test (/cavisson.com)"); </script></b></td></tr>
         
      </table>
  </td></tr>
</table>
<table border="0" width="100%">


<tr><td>  
<script>showSelectedTemplate();</script>
</td></tr>

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

