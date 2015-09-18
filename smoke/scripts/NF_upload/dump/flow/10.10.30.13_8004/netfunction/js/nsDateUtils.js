//-----------------------------------------------------------------------
//
//  Name   : nsDateUtils.js
//  Author : Jyoti
//  Purpose: Utility JavaScript functions for Date/Time
//  Notes  :
//    None
//  Modification History:
//    02/25/09 - Initial Version
//-----------------------------------------------------------------------

var dtCh= "/";
var minYear=1900;
var maxYear=2100;

function isInteger(s)
{
  var i;
  for (i = 0; i < s.length; i++)
  {   
    // Check that current character is number.
    var c = s.charAt(i);
    if (((c < "0") || (c > "9"))) 
      return false;
  }
  // All characters are numbers.
  return true;
}

function stripCharsInBag(s, bag)
{
  var i;
  var returnString = "";
  // Search through string's characters one by one.
  // If character is not in bag, append to returnString.
  for (i = 0; i < s.length; i++)
  {   
    var c = s.charAt(i);
    if (bag.indexOf(c) == -1) returnString += c;
  }
  return returnString;
}

function daysInFebruary (year)
{
  // February has 29 days in any year evenly divisible by four,
  // EXCEPT for centurial years which are not also divisible by 400.
  return (((year % 4 == 0) && ( (!(year % 100 == 0)) || (year % 400 == 0))) ? 29 : 28 );
}

function DaysArray(n) 
{
  for (var i = 1; i <= n; i++)
  {
    this[i] = 31
    if (i==4 || i==6 || i==9 || i==11) {this[i] = 30}
    if (i==2) {this[i] = 29}
  } 
  return this
}

function isDate(dtStr)
{
  var daysInMonth = DaysArray(12)
  var pos1=dtStr.indexOf(dtCh)
  var pos2=dtStr.indexOf(dtCh,pos1+1)
  var strMonth=dtStr.substring(0,pos1)
  var strDay=dtStr.substring(pos1+1,pos2)
  var strYear=dtStr.substring(pos2+1)
  strYr=strYear
  if (strDay.charAt(0)=="0" && strDay.length>1) strDay=strDay.substring(1)
  if (strMonth.charAt(0)=="0" && strMonth.length>1) strMonth=strMonth.substring(1)
  for (var i = 1; i <= 3; i++) {
    if (strYr.charAt(0)=="0" && strYr.length>1) strYr=strYr.substring(1)
  }
  month=parseInt(strMonth)
  day=parseInt(strDay)
  year=parseInt(strYr)
  if (pos1==-1 || pos2==-1){
    alert("The date format should be : mm/dd/yyyy")
    return false
  }
  if (strMonth.length<1 || month<1 || month>12){
    alert("Please enter a valid month")
    return false
  }
  if (strDay.length<1 || day<1 || day>31 || (month==2 && day>daysInFebruary(year)) || day > daysInMonth[month]){
    alert("Please enter a valid day")
    return false
  }
  if (strYear.length != 4 || year==0 || year<minYear || year>maxYear){
    alert("Please enter a valid 4 digit year between "+minYear+" and "+maxYear)
    return false
  }
  if (dtStr.indexOf(dtCh,pos2+1)!=-1 || isInteger(stripCharsInBag(dtStr, dtCh))==false){
    alert("Please enter a valid date")
    return false
  }
  return true
}

function verifyDate(dateInput)
{
  var dt = dateInput;
  if (isDate(dt)==false)
  {
    return false;
  }
  return true;
}

// Here we are validating time
function verifyTime(Timevalue, type)
{
  if(verifyTimeFormat(Timevalue, type, "")  == false)
    return false;
}

function verifyTimeFormat(Timevalue, type, format)
{
  var TimePattern = /^(\d{2,})\:(\d{2,2})\:(\d{2,2})$/;
  var Array1 = Timevalue.match(TimePattern);
   
  if (Array1 == null)
  {
    alert(type+ " Time is not a valid. Enter " + type + "Time in HH:MM:SS");
    return false; // fix bug for object as null
  }
 
  if (Array1[1].length > 3)
  {
    alert("Please enter " +type+ " Time hour(HH) <= 3 digits.");
    return false; 
  }

  //check for Absolute format
  if(format == "Absolute")
  {
    thisSegment = Array1[1];    
    if (thisSegment > 23)
    {
      alert("HH should be any number from 00 to 23");
      return false;
    }  
  }
    
  for (i = 2; i <= 3; i++)
  {
    thisSegment = Array1[i];    
    if (thisSegment > 59)
    {
      alert("MM and SS should be any number from 00 to 59");
      return false;
    }       
  }
  return true;
}

//This function convert time in seconds.
function timeInSecond(tempTime)
{
  var tempTime1 = tempTime.split(":");
  tempTime1 = (Math.abs(eval(tempTime1[0]* 60 * 60)) + Math.abs(eval(tempTime1[1] * 60)) + Math.abs(eval(tempTime1[2])));

  return tempTime1;
}

//This function convert time (ms) to string.
function timeInMilliSecToString(strTime)
{
  var hh, mm, ss, msec, temp, time;
  time = parseInt(strTime);
  msec = time%1000;
  time = (time - msec)/1000;
  hh = parseInt(time/3600);
  time = time%3600;
  mm = parseInt(time/60);
  time = time%60;
  ss = parseInt(time);
  return(appendStringToTime(hh,mm,ss,msec));
}


// Converts time in HH:MM:SS to milli-seconds:Richa Shastri 28/04/2012
function convStrToMilliSec(timeStr)
{
  var milliSecTmp = "";
  if(timeStr != "")
  {
    temp = timeStr.split(":");
    var hourTmp = parseInt(Math.abs(temp[0]));
    var minuteTmp =parseInt(Math.abs(temp[1]));
    var secTmp = parseInt(Math.abs(temp[2]));
    secTmp = hourTmp*3600 + minuteTmp*60 + secTmp;
    milliSecTmp = secTmp*1000;
    return milliSecTmp;
  }
  else

    return milliSecTmp;
}
  
//This function convert time (ms) to seconds.
function timeInMilliSecToSecString(strTime)
{
  if(strTime != "NA")
  {
    var hh, mm, ss, msec, temp, time;
    time = parseInt(strTime);
    //msec = time%1000;
    time = (time)/1000;
    hh = parseInt(time/3600);
    time = time%3600;
    mm = parseInt(time/60);
    time = time%60;
    ss = parseInt(time);

    if(mm < 10)
      mm = "0" + mm;
    if(ss < 10)
      ss = "0" + ss;

    return(hh + ":" + mm + ":" + ss);
  }
  else
    return strTime;
}

// This need to be replaced be timeInMilliSecToString after checking with Anil
function convertMilliToSec(value)
{
  return (timeInMilliSecToString(value));
}

//this function append 0 in front. For example if time 0:1:10 it convert to 00:01:10
function appendStringToTime(hh,mm,ss,msec)
{
  if (msec < 10)
    msec = "0" + msec;
  if(msec < 100)
    msec = "0" + msec;
  if(mm < 10)
    mm = "0" + mm;
  if(ss < 10)
    ss = "0" + ss;
  return(hh + ":" + mm + ":" + ss + "." + msec);
}

//Convert Milli-Seconds Decimal up to 3 Decimal
function convToMilliSecs(Time)
{
  if (Time.indexOf (".") == -1) Time += ".000";
  else Time += "000";
  
  var re = /\d*.\d\d\d/;
  Time = re.exec(Time);
  Time = Time*1000;
  return Time;
}

// This method format the time in HH:MM:SS. For example
// if time = 0:1:001 it change the format into 00:01:01
// if time = 0000:0012:1 => 00:12:01
function formatTime(hh_in, mm_in, ss_in)
{
  // Convert into numeric to remove leading 0 (e.g. 0001 to 1)
  // Use base 10 otherwise parseInt treats 0012 in octal
  var hh_num = parseInt(hh_in, 10);
  var mm_num = parseInt(mm_in, 10);
  var ss_num = parseInt(ss_in, 10);
  var temp;

  if (hh_num < 10)  
    temp = "0" + hh_num + ":";
  else 
    temp = hh_num + ":";
  if(mm_num < 10)
    temp = temp + "0" + mm_num + ":";
  else 
    temp = temp + mm_num + ":";
  if(ss_num < 10)
    temp = temp + "0" + ss_num;
  else 
    temp = temp + ss_num;
  return (temp);
}

//validate the time in HH:MM:SS format.
//e.g 00:11:33
function validateTimeHHMMSS(time)
{
  var varTime = time.value;
  // var timeExpression =/^(\d{2}):(\d{2})\s{0,1}$/;
  var timeExpression = /^(\d{2,})\:(\d{2,2}):(\d{2,2})$/;
  var valresult = varTime.match(timeExpression); 
  
  if (valresult==null)
  { 
    alert("Time entry is invalid. Please enter a valid time in HH:MM:SS format (e.g. 09:03:00)"); 
    time.focus(); 
    return false;
  } 
  
  if (valresult[1] > 23)
  {
    alert("Hour(HH) should be any number from 00 to 23");
    time.focus();
    return false;
  }  

  if (valresult[2] > 59)
  {
    alert("Minute(MM)  should be any number from 00 to 59");
    time.focus();
    return false;
  } 
  if (valresult[3] > 59)
  {
    alert("Second(SS)  should be any number from 00 to 59");
    time.focus();
    return false;
  } 
  return true;
}

// for validating date for SchedulerManagement GUI : Manish Gupta
function isValidDate(dtStr)
{
  var date = new Date();
  var CurYear = date.getFullYear() ; 
  
  var daysInMonth = DaysArray(12)
  var pos1=dtStr.indexOf(dtCh)
  var pos2=dtStr.indexOf(dtCh,pos1+1)
  var strMonth=dtStr.substring(0,pos1)
  var strDay=dtStr.substring(pos1+1,pos2)
  var strYear=dtStr.substring(pos2+1)
  strYr=strYear
  if (strDay.charAt(0)=="0" && strDay.length>1) strDay=strDay.substring(1)
  if (strMonth.charAt(0)=="0" && strMonth.length>1) strMonth=strMonth.substring(1)
  for (var i = 1; i <= 3; i++) {
    if (strYr.charAt(0)=="0" && strYr.length>1) strYr=strYr.substring(1)
  }
  month=parseInt(strMonth)
  day=parseInt(strDay)
  year=parseInt(strYr)
  if (pos1==-1 || pos2==-1){
    alert("The date format should be : mm/dd/yyyy")
    return false
  }
  if (strMonth.length<1 || month<1 || month>12){
    alert("Please enter a valid month")
    return false
  }
  if (strDay.length<1 || day<1 || day>31 || (month==2 && day>daysInFebruary(year)) || day > daysInMonth[month]){
    alert("Please enter a valid day")
    return false
  }
  if (strYear.length != 4 || year==0 || year< CurYear){
    alert("Invalid Date !\nThe start date should be from today onwards only!");
    return false
  }
  if (dtStr.indexOf(dtCh,pos2+1)!=-1 || isInteger(stripCharsInBag(dtStr, dtCh))==false){
    alert("Please enter a valid date")
    return false
  }
  return true
}

function verifyDateForScheduleMngmnt(dateInput)
{
  var dt = dateInput;
  if (isValidDate(dt)==false)
  {
    return false;
  }
  return true;
}

