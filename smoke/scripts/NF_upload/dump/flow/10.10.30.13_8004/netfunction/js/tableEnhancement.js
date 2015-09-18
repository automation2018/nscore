//---------------------------------------------
//  Name   : tableEnhancement.js
//  Author : Ritesh Sharma
//  Purpose: Table header sliding
//  	   - Shift control selection
//  Notes  :    None
//  Keywords:
//    Read-only: None
//    Read/Write: None
//  Modification History:
//    7/12/11:Ritesh:3.7.8 - Initial Version
//----------------------------------------------


//It change color when mouse over on the row
function overMouse(rowIdx)
{
  var tr = eval("document.getElementById(rowIdx)");
  tr.oldBackgroundColor = tr.style.backgroundColor;
  tr.style.backgroundColor = "#DBECFB";
}

//Back to original color on mouse out
function outMouse(rowIdx)
{
  var tr = eval("document.getElementById( rowIdx)");
  tr.style.backgroundColor = tr.oldBackgroundColor;
}

// This function will highlight the row selected by checkbox
//add functionality to retain color on mouse over and out
function changeColorOfSelectedRowsByCheck(rowIdx, checkbox, arrSelectedRows)
{
  var tr = eval("document.getElementById(\"RowId" + rowIdx + "\")");
  //alert(rowIdx)
 if(checkbox.checked)
  {
    tr.style.backgroundColor = "#DBECFB";
    tr.oldBackgroundColor=tr.style.backgroundColor;
    //alert("element pushed : " + rowIdx);
    arrSelectedRows.push(rowIdx);
    //alert("arrSelectedRows.length : " + arrSelectedRows.length);
  }
  else
  {
    if(rowIdx%2)
    {
      tr.style.backgroundColor = "white"
      tr.oldBackgroundColor = 'white';
    }
    else
    {
      tr.style.backgroundColor = "#f7fcff"
      tr.oldBackgroundColor = '#f7fcff';
    }
  }
}


// This function will highlight the row selected by checkbox
//add functionality to retain color on mouse over and out


//when call main check box, it will change all color of each row
//when call main check box, it will change all color of each row
function changeAllChecksByChangeColor(numRows, chkMain, chkArray, tableName, status, arrSelectedRows)
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
      changeColorOfSelectedRowsByCheck(1,chkArray,arrSelectedRows);
    }
    
    
    
  }
  if(numRows >1)
  {
    for(i=1, k = 0; k < numRows; k++,i++)
    {
      chkArray[k].checked = status;
      
      if(chkArray[k].checked )
        changeColorOfSelectedRowsByCheck(i,chkArray[k],arrSelectedRows);
      else
        changeAllToOriginalColor(arrSelectedRows)
    }
  }
}  

function changeAllChecksByChangeColorReplay(numRows, chkMain, chkArray, tableName, status, arrSelectedRows)
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
      changeColorOfSelectedRowsByCheck(chkArray.value,chkArray,arrSelectedRows);
    }
  }
  if(numRows >1)
  {
    for(i=1, k = 0; k < numRows; k++,i++)
    {
      chkArray[k].checked = status;
      
      if(chkArray[k].checked )
        changeColorOfSelectedRowsByCheck(chkArray[k].value,chkArray[k],arrSelectedRows);
      else
        changeAllToOriginalColorReplay(chkArray[k].value,chkArray[k],arrSelectedRows)
    }
  }
}

function changeAllChecksByChangeColorNO(numRows, chkMain, chkArray, tableName, status, arrSelectedRows)
{ 
  chkMain.checked = status;

  if(numRows == 1)
  {
    if(tableName == "DynamicHTMLTable") 
    {
      if(getBrowserType() == "IE")
      {
        chkArray[0].checked = status;
        changeColorOfSelectedRowsByCheck(0,chkArray[0],arrSelectedRows);
      }
      else
      {
        chkArray.checked = status;
        changeColorOfSelectedRowsByCheck(0,chkArray[0],arrSelectedRows);
       } 
    }
    else
    {
      chkArray.checked = status;
      changeColorOfSelectedRowsByCheck(0,chkArray,arrSelectedRows);
    }
  }
  if(numRows >1)
  {
    for(i=0, k = 0; k < numRows; k++,i++)
    {
      chkArray[k].checked = status;
      
      if(chkArray[k].checked )
        changeColorOfSelectedRowsByCheck(i,chkArray[k],arrSelectedRows);
      else
        changeAllToOriginalColor(arrSelectedRows)
    }
  }
}   




//when call main check box, it will change all color of each row

/*for multiple selected checkbox by Shift+click & ctrl+click*/
function shiftCheck(lastRowId,currentRowId,checkbox,eventt,lastvalue,arrCkeckboxValue)
{ 
  flag = false;  //checking first and last checkbox checked or not
  var start, end; //storing start index and end index of check box
  flag=eventt; //set flag true for its coming from Shift+click or ctrl+click
  
  //if we select next checkbox, the value previous and next checkbox will not be same
  //so it will enter in this condition
  if (flag && lastvalue != null && lastvalue != checkbox)
  {
    //setting plus getting index of checkbox 
    //case 1 : user select from current checkbox
    //case 2 : from previous checkbox
    for (var i = 0; i < checkbox.form.elements.length; i++)
    {
      if (checkbox.form.elements[i] == checkbox) //getting the index of current checkbox 
      {
	start = checkbox;
	end = lastvalue;
	currentIndex = i;
	break;
      }
      else if (checkbox.form.elements[i] == lastvalue) // getting the index of previous checkbox
      {
	start = lastvalue;
	end = checkbox;
	currentIndex = i;
	break;
      }
    }
    
       if(currentRowId<lastRowId) 
         changeColor=++currentRowId;
       else
         changeColor=++lastRowId;
         //alert(currentRowId+"and"+lastRowId);
    //checking all the row between start and end index between
    
    for ( currentIndex += 1; currentIndex < checkbox.form.elements.length && checkbox.form.elements[currentIndex] != end; currentIndex++)
    {
      
      if (checkbox.form.elements[currentIndex].type == "checkbox"&&checkbox.form.elements[currentIndex].checked==false) 
      {
       checkbox.form.elements[currentIndex].checked = checkbox.checked;
       change=parseInt(arrCkeckboxValue.indexOf(checkbox.form.elements[currentIndex].value)); 
       changeColorOfSelectedRowsByCheck(change,checkbox,arrSelectedRows); 
       
       //checkbox.value=arrCkeckboxValue[ changeColor];
       changeColor++;
      }
     // checkbox.value=arrCkeckboxValue[currentRowId];
    }
   //for(i=changeColor;i<=)
   // lastvalue = end;
    
  }
  else
  {
    lastvalue = checkbox; //first time it will come in this condition and store the value of selected checkbox
    lastRowId=lastRowId;
    //alert(lastRowId);
  }
  flag = false;

}


// when unchecked the main checkbox then all row will be on original color
function changeAllToOriginalColor(arrSelectedRows)
{	

 while(arrSelectedRows.length > 0)
  {
    
  var rowId = arrSelectedRows.pop();
  var tr = document.getElementById('RowId' + rowId);

  //for change color in previous behaviour		
  if(rowId%2)
    {
      tr.style.backgroundColor = "white"
      tr.oldBackgroundColor = 'white';
    }
  else
    {
      tr.style.backgroundColor = "#f7fcff";
      tr.oldBackgroundColor = '#f7fcff';
    }
   }
}

function changeAllToOriginalColorReplay(rowId, checkbox,arrSelectedRows)
{
  var tr = document.getElementById('RowId' + rowId);
  arrSelectedRows.pop();
  //for change color in previous behaviour		
  if(rowId%2)
  {
    tr.style.backgroundColor = "white"
    tr.oldBackgroundColor = 'white';
  }
  else
  {
    tr.style.backgroundColor = "#f7fcff";
    tr.oldBackgroundColor = '#f7fcff';
  }
}

function getStyleCursor()
{
  if(getBrowserType() == "IE")
  {
   return 'hand';
  }
  else
    return 'pointer';
}


//convert the pixel into percent according to the browser width
function getColumnWidthPixel(pixel)
{
 var w=GetWidth()
 w=w*(.98);
 var value=(pixel*100)/w;
 return value;
}

//return the browser width relative window
function GetWidth()
{
 var x = 0;
 if (self.innerHeight)
 {
   x = self.innerWidth;
 }
 else if (document.documentElement && document.documentElement.clientHeight)
 {
   x = document.documentElement.clientWidth;
 }
 else if (document.body)
 {
   x = document.body.clientWidth;
 }
 return parseInt(x);
}


 
