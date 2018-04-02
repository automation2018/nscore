function validate()
{
    var x=document.slogin.uname;
    var y=x.value;
//	alert(x);
    if(y=="" || x==null||isNaN(y))
        {
            alert("Enter Valid Id");
            x.select();
            x.focus();
            return false;
        }
        else
            {
                return pvalidate();
            }
}
function pvalidate()
{
    var x=document.slogin.password;
    var y=x.value;
    if(y=="" || x==null)
        {
            alert("Password should not be empty");
            x.select();
            x.focus();
            return false;
        }
        else
            {
                return true;
            }
}