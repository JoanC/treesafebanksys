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
            //    Server.Transfer("~/WrongPage.aspx", true);
            }
        }

        protected void ChangeUserInfoButton_Click(object sender, EventArgs e)
        {
            //打开更改用户联系信息页面
            //传参打开
            Response.Redirect("UserEditInfoPage.aspx?name=" + UserName.Text
                             + "&password="+UserPassword.Text
                             + "&id=" + UserID.Text
                             + "&address=" + UserAddress.Text
                             + "&phone=" + UserPhone.Text
                             + "&email=" + UserEmail.Text);
        }

        protected void ChangePasswordButton_Click(object sender, EventArgs e)
        {
            //打开更改用户登录密码页面
            //传参打开
            Response.Redirect("UserChangePassword.aspx?name=" + UserName.Text
                              + "&password=" +UserPassword.Text);
        }
    }
}