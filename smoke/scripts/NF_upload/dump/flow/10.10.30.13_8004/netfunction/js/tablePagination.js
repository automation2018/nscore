function overMouseForService(rowIdx)
{ 
  var tr = eval("document.getElementById(rowIdx)");
  tr.oldBackgroundColor = tr.style.backgroundColor;
  if(arrURLState[parseInt(rowIdx.substring(5))] != 'disabled')
    tr.style.backgroundColor = "#DBECFB";
  else
    tr.style.backgroundColor = "#EBEBEB";
}

//Back to original color on mouse out
function outMouseForService(rowIdx)
{
  var tr = eval("document.getElementById( rowIdx)");
  tr.style.backgroundColor = tr.oldBackgroundColor;
}

function changeColorOfSelectedRowsByCheckForPaging(rowIdx, checkbox, arrSelectedRows, startIndex)
{
  var tr = eval("document.getElementById(\"RowId" + (rowIdx + parseInt(startIndex)) + "\")");

  if(checkbox.checked)
  {
    if(arrURLState[rowIdx + parseInt(startIndex)] != 'disabled')
      tr.style.backgroundColor = "#DBECFB";
    else
      tr.style.backgroundColor = "#EBEBEB";
      
    tr.oldBackgroundColor = tr.style.backgroundColor; 
  }
  else
  { 
    if(rowIdx%2)
    {
      if(arrURLState[rowIdx + parseInt(startIndex)] == 'disabled')
      {
        tr.style.backgroundColor = '#EBEBEB';
        tr.oldBackgroundColor = '#EBEBEB';
      }
      else
      {
        tr.style.backgroundColor = 'white';
        tr.oldBackgroundColor = 'white';
      }  
    }
    else
    {
      if(arrURLState[rowIdx + parseInt(startIndex)] == 'disabled')
      {
        tr.style.backgroundColor = '#EBEBEB';
        tr.oldBackgroundColor = '#EBEBEB';
      }
      else
      {
        tr.style.backgroundColor = "#f7fcff"
        tr.oldBackgroundColor = '#f7fcff';
      }
    }
  }
}

function statusSelectionRows(checkbox,id)
{  
  if(checkbox.checked)
  {
    selectedRows.push(id);
  }
  else
  {
    selectedRows.pop();
  }
}

function changeAllChecksByChangeColorForPaging(numRows, chkMain, chkArray, tableName, status, arrSelectedRows, startIndex)
{ 
  chkMain.checked = status;
  if(numRows == 1)
  {
    if(tableName == "DynamicHTMLTable") 
    {
      if(getBrowserType() == "IE")
      {
        chkArray[0].checked = status;
        changeColorOfSelectedRowsByCheckForPaging(0,chkArray[0],arrSelectedRows,startIndex);
      }
      else
      {
        chkArray.checked = status;
       changeColorOfSelectedRowsByCheckForPaging(0,chkArray[0],arrSelectedRows,startIndex);
      }  
    }
    else
    {
      chkArray.checked = status;
      changeColorOfSelectedRowsByCheckForPaging(0,chkArray,arrSelectedRows,startIndex);
    }
  }
  if(numRows >1)
  {
    for(i=0, k = 0; k < numRows; k++,i++)
    {
      chkArray[k].checked = status;
      
      if(chkArray[k].checked )
      {
        changeColorOfSelectedRowsByCheckForPaging(i,chkArray[k],arrSelectedRows,startIndex);
      }  
      else
        changeAllToOriginalColorForPaging(arrSelectedRows,startIndex)
      arrSelectedRows.push(k);
        
    }
  }
}   

/*for multiple selected checkbox by Shift+click & ctrl+click*/
function shiftCheckForPaging(lastRowId,currentRowId,checkbox,eventt,lastvalue,arrCkeckboxValue)
{ 
  // alert(arrCkeckboxValue.length);
  
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
       change=parseInt(checkbox.form.elements[currentIndex].value);
       changeColorOfSelectedRowsByCheckForPaging(change,checkbox,arrSelectedRows,'0'); 
       checkbox.value=arrCkeckboxValue[ changeColor];
       changeColor++;
      }
      checkbox.value=arrCkeckboxValue[currentRowId];
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

function changeAllToOriginalColorForPaging(arrSelectedRows,startIndex)
{
  var rowId=0;
  while(arrSelectedRows.length >0)
  {
  
    selectedRows.pop();
    rowId = arrSelectedRows.pop();
  
    var tr = document.getElementById('RowId' + (rowId + parseInt(startIndex)));
    
    //for change color in previous behaviour		
    if(rowId%2)
    { 
      
      if(arrURLState[rowId + parseInt(startIndex)] == 'disabled')
      {
        tr.style.backgroundColor = '#EBEBEB';
        tr.oldBackgroundColor = '#EBEBEB';
      }
      else
      {
        tr.style.backgroundColor = "white";
        tr.oldBackgroundColor = 'white';
      }
    }
    else
    {
      if(arrURLState[rowId + parseInt(startIndex)] == 'disabled')
      {
        tr.style.backgroundColor = '#EBEBEB';
        tr.oldBackgroundColor = '#EBEBEB';
      }
      else
      {
        tr.style.backgroundColor = "#f7fcff";
        tr.oldBackgroundColor = '#f7fcff';
      }
    }
  }
}