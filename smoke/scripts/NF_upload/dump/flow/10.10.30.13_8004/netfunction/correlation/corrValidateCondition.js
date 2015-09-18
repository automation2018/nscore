//---------------------------------------
//  Name    : corrEditRespTemp.jsp
//  Author  : Ritesh Sharma 
//  Purpose : To validate Template Condition. Following function will validtae the below conditions
//          : 1. It will check start and close paranthesis will be set according to given template condition if not then alert will be come
//          : 2. It will check after closing paranthesis , it should the end of template condition ot any operator should be there
//          : 3. Then remove all the start and end paranthesis except in between double qoutes value
//          : 4. The every condition will split based on AND or Or and store into an Array.
//          : 5. Then every condition pop form array and test the condition
//          : 6. In conditon we find left and right parts  based on operators > , < , <= , >= , = ,!= , IN , NOT_IN
//          : 7. Ther validate left and right part validate saparetly.
//          : 8. In left part start with variable and find the varriable and check it is exist ot not . AND left can contains any math operator split with that 
//          :    operator and check next varriable can be string , neumeric value or variable. As it is validate right part of condition
//
//
//  Modification History:
//  Notes   : None
//---------------------------------------

 
  newLineCount = 1;
 
/*
 * This function will remove all paraenthesis except if paraenthesis exist in between double qoutes.
 */
function removeParenthesis(str)
{
  var count = 1; //used for removing '(' and ')' between ""
  var finalStr = "";
  
  var str = ReplaceAll(str, "(String)", "")
  
  for(var i = 0; i < str.length; i++)
  {
    if(str.charAt(i) == '"')
    {
      if(count%2 == 0 && str.charAt(i-1) == '\\')
        continue;
      count++;
    }
    
    if((count%2 != 0) && (str.charAt(i) == '(' || str.charAt(i) == ')'))
    {
      finalStr += " ";
    }
    else
      finalStr += str.charAt(i);
  }
  
  str = finalStr;
  
  return str;
}

/*
 * This function checks start and close parenthesis is in right format or not
 */
 
function chkParanthesis(str)
{
  var count = 1; //used for removing '(' and ')' between ""
  var finalStr = "";
  
  for(var i = 0; i < str.length; i++)
  {
    if(str.charAt(i) == '"')
    {
      if(count%2 == 0 && str.charAt(i-1) == '\\')
        continue;
      count++;
    }
      
    if((count%2 == 0) && (str.charAt(i) == '(' || str.charAt(i) == ')'))
      continue;
    else
      finalStr += str.charAt(i);
  }
    
  if(count%2 == 0)
  {
    return "String literal is not properly closed by a double-quote.";
  }
  
  str = finalStr;
   
  var leftParaIndex = -1;
  var rightParaIndex = -1;
  leftParaIndex = str.indexOf("(");
  rightParaIndex = str.indexOf(")");
  
  if(leftParaIndex < 0 && rightParaIndex < 0)
  {
    return "";
  }
  else if((leftParaIndex < 0 && rightParaIndex >= 0) || (leftParaIndex >= 0 && rightParaIndex < 0))
  {
    return "Syntax error, insert proper \"\(\" or \"\)\" to complete BlockStatements.";
  }
  else
  {
    while(leftParaIndex < rightParaIndex && leftParaIndex >= 0 && rightParaIndex >= 0)
    {
      str = str.replace("(", "");
      str = str.replace(")", "");
   
      leftParaIndex = str.indexOf("(");
      rightParaIndex = str.indexOf(")");
    }
    
    if((leftParaIndex < 0 && rightParaIndex >= 0) || (leftParaIndex >= 0 && rightParaIndex < 0) || (leftParaIndex > rightParaIndex))
    {
      return "Syntax error, insert proper \"\(\" or \"\)\" to complete BlockStatements.";
    }
    else
    {
      return "";
    }
  }  
}

/*
 * This function check that after every ')' their should be ')' or any mathOper or LogicalOper
 */
 
function chkOperAfterPara(str)
{
  var count = 1; //used for removing '(' and ')' between ""
  var finalStr = "";
  
  str = ReplaceAll(str, "(String)", "")
  
  for(var i = 0; i < str.length; i++)
  {
    if(str.charAt(i) == '"')
    {
      if(count%2 == 0 && str.charAt(i-1) == '\\')
        continue;
      count++;
    }
      
    if((count%2 == 0) && (str.charAt(i) == '(' || str.charAt(i) == ')'))
      continue;
    else
      finalStr += str.charAt(i);
  }
  
  str = finalStr;
  
  var oprators = "+-*/=><AOIN%)";//A for AND, O for OR, I for IN, N for NOT_IN
  var tmpStr = "";
  var chkOper = false;
  
  var i = 0;
  
  for(i = 0; i < str.length; i++)
  {
    if(str.charAt(i) == ' ')
        continue;
      
    tmpStr = str.charAt(i) + "";
   
  
    if(chkOper && !oprators.contains(tmpStr))
    {
      return "Syntax error, Operator expected after paranthesis.";
    }
      
    if(chkOper && oprators.contains(tmpStr))
    {
      if(str.charAt(i) == 'O')
      {
        if((i+1 >= str.length))
        {
          return "Syntax error on token \"" + str.charAt(i) + "\", delete this token.";
        }
        else if(str.charAt(i+1) != 'R')
        {
          return "Syntax error on token \"" + str.charAt(i)  + str.charAt(i+1) + "\", delete this token.";
        }
        else 
        {
          if((i+2) >= str.length)
          {
            return "Syntax error on token \"OR\", Expression expected after this token.";
          }
          else if((str.charAt(i+2) != ' ' && str.charAt(i+2) != '('))
          {
            return "Syntax error on token \"OR\", Expression expected after this token.";
          }
        }
        
        chkOper = false;
      }
      else if(str.charAt(i) == 'A')
      {
        if((i+1) >= str.length)
        {
          return "Syntax error on token \"" + str.charAt(i) + "\", delete this token.";
        }
        else if(str.charAt(i+1) != 'N')
        {
          return "Syntax error on token \"" + str.charAt(i) + str.charAt(i+1) + "\", delete this token.";
        }
        else if((i+2) >= str.length)
        {
          return "Syntax error on token \"" + str.charAt(i) + str.charAt(i+1) + "\", delete this token.";
        }
        else if(str.charAt(i+2) != 'D')
        {
          return "Syntax error on token \"" + str.charAt(i) + str.charAt(i+1) + str.charAt(i+2) +  "\", delete this token.";
        }
        else
        {
          if((i+3) >= str.length)
          {
            return "Syntax error on token \"AND\", Expression expected after this token.";
          }
          else if(str.charAt(i+3) != ' ' && str.charAt(i+3) != '(')
          {
            return "Syntax error on token \"AND\", Expression expected after this token.";
          }
        }
        chkOper = false;
      }
      else if(str.charAt(i) == 'I')
      {
        if((i+1 >= str.length))
        {
          return "Syntax error on token \"" + str.charAt(i) + "\", delete this token.";
        }
        else if(str.charAt(i+1) != 'N')
        {
          return "Syntax error on token \"" + str.charAt(i) + str.charAt(i) + "\", delete this token.";
        }
        else
        {
          if((i+2) >= str.length)
          {
            return "Syntax error on token \"IN\", Expression expected after this token.";
          }
          else if((str.charAt(i+2) != ' ' && str.charAt(i+2) != '('))
          {
            return "Syntax error on token \"IN\", Expression expected after this token.";
          }
        }
        chkOper = false;
      }
      else if(str.charAt(i) == 'N')
      {
        if((i+6) >= str.length)
        {
	  return "Syntax error on token \"" + str.substring(i , str.length) + "\", delete this token.";
        }
        else if(str.substring(i,i+6) != "NOT_IN")
        {
          return "Syntax error on token \"" + str.substring(i , i+6) + "\", delete this token.";
        }
        else if((i+7) >= str.length)
        {
          return "Syntax error on token \"NOT_IN\", Expression expected after this token.";
        }
        else if(str.charAt(i+7) != ' ' && str.charAt(i+7) != '(') 
        {
          return "Syntax error on token \"NOT_IN\", Expression expected after this token.";
        }
        chkOper = false;
      }
      else
      {
        chkOper = false;
      }
    }
     
    if(str.charAt(i) == ')')
      chkOper = true;
    else if(str.charAt(i) == '(')
    {
      if(i == 0)
        continue;
            
      for(var j = i; j >= 0; j--)
      {
        if(str.charAt(j-1) == ' ')
          continue;
              
        if("+-*/=><%(DRN".contains(str.charAt(j-1) + ""))
        {
          if(str.charAt(j-1) == 'D')
          {
                 
            if((j-4) >= 0 && (str.substring(j-4, j) == " AND" || str.substring(j-4, j) == "\)AND") )
            {
              break;
            }
            else
            {
              return "Syntax error, Operator expected before openning paranthesis.";
            }
          }
          else if(str.charAt(j-1) == 'R')
          {   
            if((j-3) >= 0 && (str.substring(j-3, j) == " OR" || str.substring(j-3, j) == "\)OR"))
            {
              break;
            }
            else
            {
              return "Syntax error, Operator expected before openning paranthesis.";
            }
          }
          else if(str.charAt(j-1) == 'N')
          {
                
            if((j-3) >= 0 && (str.substring(j-3, j) == " IN" || str.substring(j-3, j) == "\)IN"))
            {
              break;
            }
            else if((j-7) >= 0 && (str.substring(j-7, j) == " NOT_IN" || str.substring(j-7, j) == "\)NOT_IN"))
            {
              break;
            }
            else
            {
              return "Syntax error, Operator expected before openning paranthesis.";
            }
          }
          else
          {
            break;
          }
        }
        else
        {
          return "Syntax error, Operator expected before openning paranthesis.";
        }
      }
    }
  }
   
  if( i == str.length)
     return "";
}

String.prototype.contains = function(it) { return this.indexOf(it) != -1; };

/*
 * This function will split the conditions based on AND or OR and store into in an array
 */
 
function splitFromANDandOR(str)
{
  var count = 1; //this is used for ingnoring between ""
  var index = 0; //This is used to keep track of splited str
  var i = 0;
  
  for(i = 0; i < str.length; i++)
  {
    if(str.charAt(i) == '"')
    {
      if(count%2 == 0 && str.charAt(i-1) == '\\')
        continue;
      count++;
    }
    
    if(str.charAt(i) == ' ')
      continue;
      
    if(i != 0 && count % 2 != 0 && (str.charAt(i) == 'A' || str.charAt(i) == 'O') && (str.charAt(i-1) == ' ' || str.charAt(i-1) == ')'))
    {
      if(str.charAt(i) == 'A')
      {
        tmpStr = str.substring(i, i+3);
        
        if(tmpStr == "AND"  && (i+3) < str.length && (str.charAt(i+3) == ' ' || str.charAt(i+3) == '('))
        {
          var strLeft = str.substring(index, i);
          
          if(trimString(strLeft) == "")
          {
            return "Syntax error on token \"AND\", delete this token.";
          }
          else
          {   
            arrCondition.push(trimString(strLeft));
            index = i + 3;
            i = i + 3;
          }
        }
        else if(tmpStr == "AND" && (i+3) >= str.length)
        {
          return "Syntax error on token \"AND\", delete this token.";
        }
      }
      else if(str.charAt(i) == 'O')
      {
        var tmpStr = str.substring(i, i+2);
        
        if(tmpStr == "OR" && (i+2) < str.length && (str.charAt(i+2) == ' ' || str.charAt(i+2) == '('))
        {
          var strLeft = str.substring(index, i);
          
          if(trimString(strLeft) == "")
          {
            return "Syntax error on token \"OR\", delete this token.";
          }
          else
          {
            arrCondition.push(trimString(strLeft));
            index = i + 2;
            i = i + 2;
          }
        }
        else if(tmpStr == "OR" && (i+2) >= str.length)
        {
          return "Syntax error on token \"OR\", delete this token.";
        }
      }
    }
  }
  if(i == str.length)
  {
    var strLeft = str.substring(index, i);
     
    if(trimString(strLeft) == "" && index == 0)
    {
      return "Syntax error, condition is missing.";
    }
    else if(trimString(strLeft) == "")
    {
      return "Syntax error on token \"AND\" or \"OR\", delete this token";
    }
    else
    {
      arrCondition.push(trimString(strLeft)); 
    }
  }
  
  return "";
}

/*
 * This function will test every condition from array and also extact left and right part
 */
 
function testCondition()
{
  for(var j = 0; j < arrCondition.length; j++)
  {
    var condStr = trimString(arrCondition[j]);
    var count = 1; //used for do nothing  between ""
    var leftStr = "";
    var rightStr = "";
    var OperExp = "><=!IN"; // I for IN and N for NOT_IN
    var operFound = false;
      
    for(var i = 0; i < condStr.length; i++)
    {
      if(condStr.charAt(i) == '"')
      {
        if(count%2 == 0 && condStr.charAt(i-1) == '\\')
          continue;
        count++;
      }
        
      tmpStr = condStr.charAt(i) + "";
      
      if(count%2 == 1 && OperExp.contains(tmpStr) && i != 0)
      {
        if(condStr.charAt(i) == '>' || condStr.charAt(i) == '<' || condStr.charAt(i) == '!' || condStr.charAt(i) == '=')
        {
          if((i+1) >= condStr.length)
          {
            
            if(condStr.charAt(i) == '!')
              return "Syntax error on token \"!\", != expected.";
            else
              return "Syntax error  on token \""+ condStr.charAt(i)+ "\", Expression expected after this token.";
           
          }
          else if(condStr.charAt(i+1) == '=')
          {
            if((i+2) >= condStr.length)
            {
              return "Syntax error on token \""+ condStr.charAt(i) + condStr.charAt(i+1)+ "\", Expression expected after this token.";
            }
            
            leftStr = trimString(condStr.substring(0, i));
           
            if(leftStr == "")
            {
              return "Syntax error on token \""+ condStr.charAt(i) + condStr.charAt(i+1)+ "\", Expression expected before this token.";
            }
            else if(validateLeftRight(leftStr))
            {
              return "Syntex error, only one conditional operator required in condition.";
            }
            else
            { 
              var errMsg = validateLeft(leftStr, true);
              if(errMsg != "")
                return errMsg;
            }
          
            rightStr = trimString(condStr.substring(i+2, condStr.length));
            
            if(rightStr == "")
            {
              return "Syntax error on token \""+ condStr.charAt(i) + condStr.charAt(i+1)+ "\", Expression expected after this token.";
            }
            else if(validateLeftRight(rightStr))
            {
              return "Syntex error, only one conditional operator required in condition.";
            }
            else
            {
              var errMsg = validateLeft(rightStr, false);
	      if(errMsg != "")
                return errMsg;
                
            }
            
            operFound = true;
            break;
          }
          else if(condStr.charAt(i) != '!')
          {
            leftStr = trimString(condStr.substring(0, i));
            rightStr = trimString(condStr.substring(i+1, condStr.length));
            
            if(leftStr == "")
            {
              return "Syntax error on token \""+ condStr.charAt(i) + "\", Expression expected before this token.";
            }
            else if(validateLeftRight(leftStr))
            {
              return "Syntex error, only one conditional operator required in condition.";
            }
            else
            {
              var errMsg = validateLeft(leftStr, true);
	      if(errMsg != "")
                return errMsg;
            }
         
            if(rightStr == "")
            {
              return "Syntax error on token \""+ condStr.charAt(i) + condStr.charAt(i+1)+ "\", Expression expected after this token.";
            }
            else if(validateLeftRight(rightStr))
            {
              return "Syntex error, only one conditional operator required in condition.";
            }
            else
            {
              var errMsg = validateLeft(rightStr, false);
	      if(errMsg != "")
                return errMsg;
            }
            operFound = true;
            break;
          }
        }
        else if(condStr.charAt(i) == 'I')
        {
          if(condStr.charAt(i-1) == ' ' && (i+3) < condStr.length && condStr.charAt(i+1) == 'N' && condStr.charAt(i+2) == ' ')//test after IN that why i+3
          {
            leftStr = trimString(condStr.substring(0, i));
            rightStr = trimString(condStr.substring(i+2, condStr.length));
     
            if(leftStr == "")
            {
              return "Syntax error on token \""+ condStr.charAt(i) + condStr.charAt(i+1)+ "\", Expression expected before this token.";
            }
            else
            {
              var errMsg = validateLeft(leftStr, true);
	      if(errMsg != "")
                return errMsg;
            }
            if(rightStr == "")
            {
              return "Syntax error on token \""+ condStr.charAt(i) + condStr.charAt(i+1)+ "\", Expression expected after this token.";
            }
            else if(validateLeftRight(rightStr))
            {
              return "Syntex error, only one conditional operator required in condition.";
            }
            else
            {
              var errMsg = validateRightForINandNOT_IN(rightStr);
	      if(errMsg != "")
                return errMsg;
            }
            operFound = true;
            break;
          }
          else if(condStr.charAt(i-1) == ' ' && (i+2) >= condStr.length && condStr.charAt(i+1) == 'N')//test after IN that why i+3
          {
            return "Syntax error on token \""+ condStr.charAt(i) + condStr.charAt(i+1)+ "\", Expression expected after this token.";
          }
        }
        else if(condStr.charAt(i) == 'N')
        {
          if(condStr.charAt(i-1) == ' ' && (i+7) < condStr.length && condStr.substring(i, i+6) == "NOT_IN" && condStr.charAt(i+6) == ' ')
          {
            leftStr = trimString(condStr.substring(0, i));
            rightStr = trimString(condStr.substring(i+6, condStr.length));
          
            if(leftStr == "")
            {
              return "Syntax error on token \""+ condStr.substring(i, i+6)+ "\", Expression expected before this token.";
            }
            else
            {
              var errMsg = validateLeft(leftStr, true);
	      	if(errMsg != "")
              return errMsg;
            }
            if(rightStr == "")
            {
              return "Syntax error on token \""+condStr.substring(i, i+6)+ "\", Expression expected before this token.";
            }
            else if(validateLeftRight(rightStr))
            {
              return "Syntex error, only one conditional operator required in condition.";
            }
            else
            {
              var errMsg = validateRightForINandNOT_IN(rightStr);
	      if(errMsg != "")
                return errMsg;
            }
            operFound = true;
            break;
          }
          else if(condStr.charAt(i-1) == ' ' && (i+6) == condStr.length && condStr.substring(i, i+6) == "NOT_IN")
          {
            return "Syntax error on token \""+condStr.substring(i, i+6)+ "\", Expression expected before this token.";
          }
        }
      }
      else if(count%2 == 1 && i == 0 && ("<>=".contains(tmpStr) || condStr.startsWith("IN ") || condStr.startsWith("NOT_IN ")))
      {
        return "Syntex error, condition is missing.";
      }
    }
    if(!operFound)
    {
      return "Syntex error, conditional operator not found.";
    }
  }
  
  return "";
}

/*
 * This function check any Operators present or not.
 */
 
function validateLeftRight(condStr)
{
  count = 1;
  
  for( var i = 0; i < condStr.length; i++)
  {
    if(condStr.charAt(i) == '"')
    {
      if(count%2 == 0 && condStr.charAt(i-1) == '\\')
        continue;
      count++;
    }
    
    tmpStr = condStr.charAt(i) + "";
    
    if(count%2 == 1 && "<>=!".contains(tmpStr))
    {
      if(condStr.charAt(i) == '!' && condStr.charAt(i+1) != '=')
          continue;
      return true;
        
    }
    else if(count%2 == 1 && "IN".contains(tmpStr))
    {
      if(i == 0 && (condStr.startsWith("IN ") || condStr.startsWith("NOT_IN ")))
      {
        return true;
      }
      if(i == 0 && (condStr == "IN" || condStr == "NOT_IN"))
      {
        return true;
      }
      else if(condStr.charAt(i) == 'I' && condStr.charAt(i-1) == ' ' && (i+2) < condStr.length && condStr.charAt(i+1) == 'N' && condStr.charAt(i+2) == ' ')
      {
        return true;
      }
      else if(condStr.charAt(i) == 'I' && condStr.charAt(i-1) == ' ' && (i+1) < condStr.length && condStr.charAt(i+1) == 'N' && (i+2) >= condStr.length)
      {
        return true;
      }
      else if(condStr.charAt(i) == 'N' && (i+7) < condStr.length && condStr.substring(i, i+7) == "NOT_IN ")
      {
        return true;
      }
      else if(condStr.charAt(i) == 'N' && (i+6) == condStr.length && condStr.substring(i, i+6) == "NOT_IN")
      {
        return true;
      }
    }
  }
  
  return false;
}
  
/*
 * This function check the left and right part of the condition 
 * if any math operator is find then split with math operator and validate left variable and right variable
 */
 
function validateLeft( str, left)
{
  var operExp = "+-*/%";
  vars = "";
  
  index = 0;
  count = 1; //this is used for ingnoring between ""
  
  for(var i = 0; i < str.length; i++)
  {
    if(str.charAt(i) == ' ')
      continue;
  
    if(str.charAt(i) == '"')
    {
      if(count%2 == 0 && str.charAt(i-1) == '\\')
        continue;
      count++;
    }
        
    if(count%2 != 0 && operExp.contains(str.charAt(i) + ""))
    {
      if((i+1) >= str.length || operExp.contains(str.charAt(i+1) + ""))
      {
        return "Syntax error on token \""+ str.charAt(i) + "\", Expression expected after this token.";
      }
      else
      {
        vars = trimString(str.substring(index, i));
          
        if(vars == "")
        {
          return "Syntax error on token \""+ str.charAt(i) + "\", Expression expected before this token.";
        }
        else if(index == 0 && left)
        {  
	  if(arrVariableName.indexOf(trimString(vars)) < 0)
	  {
	    return "Parameter " + vars + " is not available in service.";
          }
        }
        else
        {
          if(vars.startsWith("\"") && vars.endsWith("\""))
	  {
	    for(var k = 1; k < vars.length-1; k++)
	    {
	      if(vars.charAt(k) == '"' && vars.charAt(k-1) != '\\')
	      {
	        return "String literal is not properly closed by a double-quote.";
	      }
            }
	  }
	  else if(vars.startsWith("\"") && !vars.endsWith("\""))
	  {
	    return "Parameter " + vars + " is not available in service.";
	  }
	  else if(!isNaN(vars))
	  {
	   
	  }
	  else 
	  {
            if(arrVariableName.indexOf(trimString(vars)) < 0)
	    {
	      return "Parameter " + vars + " is not available in service.";
	    }
          }
        }
        index = i+1;
      }
    }
  }
  
  vars = str.substring(index, str.length);
  
  if(vars == "")
  {
    return "Syntex error, expression expected after operator ";
  }
  else if(index == 0 && left)
  {
    if(arrVariableName.indexOf(trimString(vars)) < 0)
    {
      return "Parameter " + vars + " is not available in service.";
    }
  }
  else
  {
    if(vars.startsWith("\"") && vars.endsWith("\""))
    {   
      for(var k = 1; k < vars.length-1; k++)
      {
        if(vars.charAt(k) == '"' && vars.charAt(k-1) != '\\')
     	{
     	  return "String literal is not properly closed by a double-quote.";
     	}
      }
    }
    else if(vars.startsWith("\"") && !vars.endsWith("\""))
    {
      return "String literal is not properly closed by a double-quote.";
    }
    else if(!isNaN(vars))
    {
      
    }
    else 
    {
      if(arrVariableName.indexOf(trimString(vars)) < 0)
      {
        return "Parameter " + vars + " is not available in service.";
      }
    }
  }
  
  return "";
}
  
/*
 * This function checks the right part of NOT_IN and IN operator
 * 
 */
function validateRightForINandNOT_IN(str)
{ 
  if(str.startsWith("\"") && str.endsWith("\""))
  {
    for(var k = 1; k < str.length-1; k++)
    {
      if(str.charAt(k) == '"' && str.charAt(k-1) != '\\')
      {
        return "String literal is not properly closed by a double-quote.";
      }
    }
  }
  else if(str.startsWith("\"") && !str.endsWith("\""))
  {
    return "String literal is not properly closed by a double-quote.";
  }
  else
  {
    arrStr = str.split(",");
    
    for(var i = 0 ; i < arrStr.length ; i++)
    {
      if(isNaN(arrStr[i]))
      {
        //alert( arrStr[i] + " is not a numeric value.")
        return arrStr[i] + " is not a numeric value.";
      }
    }
  }
  
  return "";
}

/*
 * This function validate the conditional logic.
 */
function parseAndValidateIfElseCond(str)
{ 
  var firstIndex = 0;
   
  for(var i = 0; i < str.length; i++)
  {
    if(str.charAt(i) == ' ')
    {
      firstIndex++;
      continue;
    }
     
    if(str.charAt(i) == '\n')
    {
      newLineCount++;
      firstIndex++;
    }
    else
      break;
  }
   
  str = str.substring(firstIndex, str.length);
   
  str = trimString(str)
   
  str = str + " ";
   
  if(str.startsWith("If ") || str.startsWith("If(") || str.startsWith("If\n"))
  {
    var count = 1; // used to do nothing between " ".
    var index = 0; //used to get one condition or statement.
    var findIfFlag = false;
     
    for(var i = 0; i < str.length; i++)
    {
      if(str.charAt(i) == '"')
      {
        if(count%2 == 0 && str.charAt(i) == '"' && str.charAt(i-1) == '\\')
          continue;
        count++;
      }
         
      if(count%2 == 1 && str.charAt(i) == 'E' && !findIfFlag)
      {
        if(str.charAt(i-1) == ' ' || str.charAt(i-1) == '\n')
        {
          if((i+5) <= str.length && (str.substring(i, i+5) == "Else " || str.substring(i, i+5) == "Else\n"))
          {
            var newLineFlag = false;
             
            for(var j = i - 1; j >= 0; j--)
            {
              if(str.charAt(j) == ' ')
                continue;
                 
              if(str.charAt(j) == '\n')
              {
                newLineFlag = true;
                break;
              }
               
              if(str.charAt(j) != '\n')
                break;
            }
             
            var conditionStr = str.substring(index, i);
              
            if(validateIfElseCondition(conditionStr, false) == false)
              return false
                 
            findIfFlag = true;
            index = i+4;
               
            if(!newLineFlag)
            {
              alert("Line " + newLineCount + ": \"Else\" should start from new line.");
              return false;
            }
          }
        }
      }
         
      if(count%2 == 1 && str.charAt(i) == 'I' && i !=0)
      {
        if(str.charAt(i-1) == ' ' || str.charAt(i-1) == '\n')
        {
          if((i+3) <= str.length && (str.substring(i, i+3) == "If " || str.substring(i, i+3) == "If(" || str.substring(i, i+3) == "If\n"))
          {
            var newLineFlag = false;
             
            for(var j = i - 1; j >= 0; j--)
            {
              if(str.charAt(j) == ' ')
                continue;
                 
              if(str.charAt(j) == '\n')
              {
                newLineFlag = true;
                break;
              }
               
              if(str.charAt(j) == 'e')
              {
                if((j-4)>0 && (str.substring(j-4, j+1) == " Else" || str.substring(j-4, j+1) == "\nElse"))
                {
                  newLineFlag = true;
                }
                break;
              }
              if(str.charAt(j) != '\n')
                break;
            }
               
            findIfFlag = false;
            var conditionStr = str.substring(index, i);
               
            if(validateIfElseCondition(conditionStr, false) == false)
              return false;
                 
            index = i;
               
            if(!newLineFlag)
            {
              alert("Line " + newLineCount + ": \"If\" should start from new line.");
              return false; 
            }
          }
        }
      }
    }
       
    var conditionStr = str.substring(index, str.length);
      
    if(validateIfElseCondition(conditionStr, true) == false)
      return false;
  }
  else
  {
    alert("Line " + newLineCount + ": Condition block should start with \"If\" statement.");
    return false;
  }
}
  
function validateIfElseCondition(str, isEnd)
{
  var count = 1; // used to do nothing between " ".
  var firstIndex = 0;
  var elseSetNewLineFlag = false;
    
  for(var i = 0; i < str.length; i++)
  {
    if(str.charAt(i) == ' ')
    {
      firstIndex++;
      continue;
    }
  
    if(str.charAt(i) == '\n')
    {
      elseSetNewLineFlag = true;
      newLineCount++;
    }
        
    if(str.charAt(i) != '\n')
      break;
    firstIndex++;
  }
      
  str = str.substring(firstIndex, str.length);
      
  var index = 0; //used to get one condition or statement.
  var ifCondFlag = false;
  var setFound = false;
    
  for(var i = 0; i < str.length; i++)
  {
    if(str.charAt(i) == '"')
    {
      if(count%2 == 0 && str.charAt(i) == '"' && str.charAt(i-1) == '\\')
        continue;
      count++;
    }
  
    if(str.charAt(i) == '\n' && ifCondFlag)
    {
      newLineCount++;
      continue;
    }
       
    if(count%2 == 1 && str.charAt(i) == 'I' && !ifCondFlag)
    {
      if(i == 0 || str.charAt(i-1) == ' ' || str.charAt(i-1) == '\n')
        {
          if((i+3) <= str.length && (str.substring(i, i+3) == "If " || str.substring(i, i+3) == "If(" || str.substring(i, i+3) == "If\n"))
          {
            index = i;
            ifCondFlag = true;
          }
        }
      }
        
      if(count%2 == 1 && str.charAt(i) == 'S' && ifCondFlag)
      {
        if(str.charAt(i-1) == ' ' || str.charAt(i-1) == '\n' || str.charAt(i-1) == ')')
        {
          if((i+4) <= str.length && str.substring(i, i+4) == "Set ")
          {
            var newLineFlag = false;
            
            for(var j = i - 1; j >= 0; j--)
            {
              if(str.charAt(j) == ' ')
                  continue;
                  
              if(str.charAt(j) == '\n')
              {
                newLineFlag = true;
                break;
              }
              
              if(str.charAt(j) != '\n')
                break;
            }
            if(newLineFlag)
            {
              setFound = true;
              var ifCondStr = str.substring(index, i);
               
              if(validateConditionForIfAndSet(ifCondStr, true) == false)
                return false;
                
              index = i;
              break;
            }
            else
            {
              alert("Line " + newLineCount + ": Statement should start from new line.");
              return false;
            }
          }
        }
      }
    }

    var lineNum = newLineCount;
    
    for(var i = str.length - 1; i >= 0; i--)
    {
      if(str.charAt(i) == ' ')
        continue;
        
      if(str.charAt(i) == '\n')
        lineNum--;
        
      if(str.charAt(i) != '\n')
          break;
    }
    
    //check for set presence after if statement.
    if(ifCondFlag && !setFound)
    {
      if(validateConditionForIfAndSet(str, true) == false)
        return false;
        
      alert("Line  " + lineNum + ": Statement is missing.");
      return false;
    }
      
    var setCondStr = str.substring(index, str.length);
    
    if(trimString(setCondStr) == "" && !ifCondFlag && isEnd)
    {
      alert("Line " + lineNum + ": Statement is missing.");
      return false;
    }
    else if( trimString(setCondStr) == "")
      return true;
    else if(trimString(setCondStr)!= "")
    {
      if(!ifCondFlag)
      {
        if(!elseSetNewLineFlag)
        {
          alert("Line " + newLineCount + ": Statement should start from new line.");
          return false;
        }
      }
      if(validateConditionForIfAndSet(setCondStr, false) == false)
      {
        return false;
      } 
    }
    
    return true;
  }
  
  function validateConditionForIfAndSet(str, ifCondFlag)
  {
    var lineNum = newLineCount; //used only in case of if condition means when ifCondFlag is true.
    var count = 1; // used to do nothing between " ".
    var firstIndex = 0; //used to get first index of condition after trimming new lines.
    
    //calculate first index.
    for(var i = 0; i < str.length; i++)
    {
      //in case of if it can start like this if\n\n\n(a + b > c) set a = b
      if(ifCondFlag)
      {
        if(i < 2)
          continue;
      }
        
      if(str.charAt(i) == ' ')
      {
        firstIndex++;
        continue;
      }
 
      if(str.charAt(i) == '\n')
        firstIndex++;
        
      if(str.charAt(i) != '\n')
        break;
        
    }
    
    
    //calculate lineNum in case of if only because we have to find the location of if.
    if(ifCondFlag)
    {
      
      for(var i = str.length -1; i >= 0; i--)
      {
        if(str.charAt(i) == ' ')
          continue;
  
        if(str.charAt(i) == '\n')
        {
          lineNum--;
        }
      }
    }
    
    var tempLineNum = lineNum ;
    
    if(ifCondFlag)
    {
      var conditionStr = str.substring(2, str.length); //2 added for removing if
      
      for(var h =0; h < conditionStr.length ; h++ )
      {
      	if(conditionStr.charAt(h) == '\n')
      	  tempLineNum = tempLineNum + 1;
      }
      
      var removeLineCount = 0;
      
      for(var h = conditionStr.length -1 ; h > 0; h--)
      {
        if(conditionStr.charAt(h) == ' ')
          continue;
            
        if(conditionStr.charAt(h) == '\n')
          removeLineCount++;
                   
        if(conditionStr.charAt(h) != '\n' && conditionStr.charAt(h) != ' ')
          break;   
      }
      
      tempLineNum = tempLineNum - removeLineCount;
      
      conditionStr = trimString(str.substring(firstIndex+2, str.length)); //2 added for removing if 
      
      if(trimString(conditionStr.replace("(", "").replace(")", "")) == "")
      {
        alert("Line " + lineNum + ": Syntax error on token \"If\", Expression expected after this token");
        return false;
      }
      else
      {
        var Total_line_For_Condition = lineNum ;
        
	if(lineNum != tempLineNum )
	{
	
          Total_line_For_Condition = lineNum + "-" + tempLineNum; 
        }
              
        if(conditionStr.startsWith("(") && conditionStr.endsWith(")"))
        {
          arrCondition = new Array();
          
          conditionStr = ReplaceAll(conditionStr , "\n" , " ")
          
          conditionStr = trimString(conditionStr);
	
	  var errMsg = "";
	  
	  errMsg = chkParanthesis(conditionStr);
	    
	  if(errMsg != "")
	  {
	    alert("Line " + Total_line_For_Condition + ": " + errMsg);
	    return false;
	  }
	   
	  errMsg = chkOperAfterPara(conditionStr);
	  
	  if(errMsg != "")
	  {
	    alert("Line " + Total_line_For_Condition + ": " + errMsg);
	    return false;
	  }
	    
	  conditionStr = removeParenthesis(conditionStr)
	   
	  errMsg = splitFromANDandOR(conditionStr) ;
	    
	  if(errMsg != "")
	  {
	    alert("Line " + Total_line_For_Condition + ": " + errMsg);
	    while(arrCondition != "")
	    { 
	      arrCondition.pop();
	    }
	      
	    return false;
          }
          errMsg = testCondition();
	    
	  if(errMsg != "")
	  {
	    alert("Line " + Total_line_For_Condition + ": " + errMsg);
	    return false;
	  }
	    
          return true;
        }
        else
        {
          alert("Line " + Total_line_For_Condition + ": " + " Syntax error, insert proper \"\(\" or \"\)\" to complete BlockStatements.");
          return false;
        }
      }
    }
    else
    {
      var setStatementStr = str.substring(firstIndex, str.length);
      if(trimString(setStatementStr) == "")
      {
        alert("Line " + lineNum + ": Statement is missing.");
        return false
      }
      else
      {
        //validate for set condition.
        if(validateSetStatements(setStatementStr, lineNum) == false)
          return false;
      }
    }
    
    return true;
  }
  
  function validateSetStatements(str,  lineNum)
  {
    var count = 1;
    var index = 0;
    for(var i = 0; i < str.length; i++)
    {
      if(str.charAt(i) == '"')
      {
        if(count%2 == 0 && str.charAt(i) == '"' && (i-1) >= 0 && str.charAt(i-1) == '\\')
          continue;
        count++;
      }
        
      if(str.charAt(i) == '\n')
      {
        lineNum++;
        newLineCount++;
      }
        
      if(count%2 == 1 && str.charAt(i) == 'S' && i !=0)
      {
        if(str.charAt(i-1) == ' ' || str.charAt(i-1) == '\n' || str.charAt(i-1) == ')')
        {
          if(((i+4) <= str.length && str.substring(i, i+4) == "Set ") || (i+3) == str.length  && str.substring(i, i+3) == "Set")
          {
            var newLineFlag = false;
            
            for(var j = i - 1; j >= 0; j--)
            {
              if(str.charAt(j) == ' ')
                continue;
                
              if(str.charAt(j) == '\n')
              {
                newLineFlag = true;
                break;
              }
              
              if(str.charAt(j) != '\n')
                break;
            }
            if(newLineFlag)
            {
              var sigleSetStat = str.substring(index, i);
              
              if(sigleSetState(sigleSetStat, lineNum) == false)
                return false;
                
              index = i;
            }
            else
            {
              alert("Line " + lineNum + ": Statement should start from new Line.");
              return false;
            }
          }
        }
      }
    }
    
    var sigleSetStat = str.substring(index, str.length);
    
    if(sigleSetState(sigleSetStat, lineNum) == false)
      return false;
      
    return true;
 }
    
function sigleSetState(str, lineNum)
{
  for(var i = str.length - 1; i >= 0; i--)
  {  
    if(str.charAt(i) == ' ')
      continue;
 
    if(str.charAt(i) == '\n')
    {
      lineNum--;
    }
  }
     
  if(!str.startsWith("Set "))
  {
    alert("Line " + lineNum + ": Syntex error at token "+ str.replace("\n", " ") + " delete this token.");
    return false;
   }
   
   str = str.substring(3, str.length);
   
   str = trimString(str);
   
   if(str == "" )
   {
     alert("Line "+lineNum +": Statement is missing.");
     return false;
   }
     
   for(var i = 0; i < str.length; i++)
   {
     if(str.charAt(i) == '"')
     {
       if(count%2 == 0 && str.charAt(i) == '"' && (i - 1) >= 0 && str.charAt(i-1) == '\\')
         continue;
       count++;
     }
     
     if(count%2 == 0)
     {
       alert("Line " + lineNum + ": String literal is not properly closed by a double-quote.");
       return false;
     }
       
     if(count%2 == 1 && str.charAt(i) == '=')
     {
       var leftStr = trimString(str.substring(0, i));
       var righStr = trimString(str.substring(i+1, str.length));
         
       if(leftStr == "")
       {
         alert("Line " + lineNum + ": Syntax error  on token \"=\", Expression expected before this token.");
         return false;
       }
       else
       {
         if(arrVariableName.indexOf(leftStr) < 0)
	 {
	   alert("Line " + lineNum + ": Parameter " + leftStr + " is not available in Service.")
	   return false;
	 }
	 
       }
       
       if(righStr == "")
       {
         alert("Line " + lineNum + ": Syntax error  on token \"=\", Expression expected after this token.");
         return false;
       }
        
       var arrTmp = righStr.split("\n");
         
       if(arrTmp.length > 1)
       {
         var errorStr = "";
         
         for(var k = 1; k < arrTmp.length; k++)
         {
           if(trimString(arrTmp[k]) != "")
           {
             errorStr = trimString(arrTmp[k]);
             break;
           }
         }
         for(var k = 0; k < leftStr.length; k++)
         {
           if(leftStr.charAt(k) == '\n')
             lineNum++;
         }
         for(var k = 0; k < righStr.length; k++)
         {
           if(righStr.substring(k, righStr.length) == errorStr || righStr.substring(k, righStr.length).startsWith(errorStr))
             break;
             
           if(righStr.charAt(k) == '\n')
             lineNum++;
         }
         
         alert("Line " + lineNum + ": Syntex error at token \""+ errorStr + "\" delete this token.");
         return false;
       }
       else
       {
         if(righStr.startsWith("\"") && righStr.endsWith("\""))
         {
           for(var k = 1; k < righStr.length-1; k++)
	   {
	     if(righStr.charAt(k) == '"' && righStr.charAt(k-1) != '\\')
	     {
	       alert("Line " + lineNum + ": String literal is not properly closed by a double-quote.");
	       return false;
	     }
           }
         }
         else if(righStr.startsWith("RandomList"))
         {
           var listStr = trimString(righStr.substring(10, righStr.length));
           
           if(listStr.startsWith("(") && listStr.endsWith(")"))
           {
             listStr = ReplaceAll( listStr , "\(", "");
             listStr = ReplaceAll( listStr , "\)", "");
             var arrList = listStr.split(",");
             //for(var j = 0; j < arrList.length; j++)
             //{
             //  alert("validate for numeric:- " +arrList[j]);
             //}
           }
           else
           {
             alert("Line " + lineNum + ": Syntax error, insert proper \"\(\" or \"\)\" to complete BlockStatements.");
             return false;
           }
         }
         else if(righStr.startsWith("Random"))
         {
           var listStr = trimString(righStr.substring(6, righStr.length));
           
           if(listStr.startsWith("(") && listStr.endsWith(")"))
           {
             listStr = ReplaceAll( listStr , "\(", "");
             listStr = ReplaceAll( listStr , "\)", "");
             var arrList = listStr.split(",");
             
             for( j = 0; j < arrList.length; j++)
             {
               if(isNaN(trimString(arrList[j])))
               {
                 alert("Line " + lineNum + ": Enter numeric value.")
                 return false;
               }
             }
           }
           else
           {
             alert("Line " + lineNum + ": Syntax error, insert proper \"\(\" or \"\)\" to complete BlockStatements.");
             return false;
           }
         }
         else if(righStr == "Unique\(\)")
         {
           
         }
         else if(righStr == "Sysvar\(cav_cur_date\)")
         {
           
         }
         else
         {
           if(arrVariableName.indexOf(righStr) < 0)
           {
             alert("Line " + lineNum + ": Parameter " + righStr + " is not available in Service.")
             return false;
           }
         }
       }
       
       break;
     }
       
     if(i == str.length - 1)
     {
       alert("Line "+lineNum + ": Assignment operator is missing.");
       return false;
     }
   }
   
   return true;
 }
  
 
  
 
