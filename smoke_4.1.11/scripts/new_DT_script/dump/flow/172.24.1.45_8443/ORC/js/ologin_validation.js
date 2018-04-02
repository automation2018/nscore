function validate()
{
    var x=document.ologin.uname;
    var y=x.value;
    if(y=="" || x==null|| isNaN(y))
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
    var x=document.ologin.password;
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