using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe.Account
{
    public partial class Login : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            RegisterHyperLink.NavigateUrl = "Register.aspx?ReturnUrl=" + HttpUtility.UrlEncode(Request.QueryString["ReturnUrl"]);
           
            //在这里调用函数~判断用户权限~并决定用户进入的界面

            LoginUser.DestinationPageUrl = String.Format("~/About.aspx?{0}", Request.QueryString.ToString());

        }
    }
}
