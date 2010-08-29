using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe.Users
{
    public partial class UserInfoPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            //显示数据从这里调
            if (Session["userright"].ToString() != "0")
            {
                Server.Transfer("~/WrongPage.aspx", true);
            }
        }

        protected void ChangeUserInfoButton_Click(object sender, EventArgs e)
        {

        }
    }
}