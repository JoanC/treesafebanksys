using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe.Users
{
    public partial class UserEditInfoPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            /*
             *  Response.Redirect("UserEditInfoPage.aspx?name=" + UserName.Text
                             + "&id=" + UserID.Text
                             + "&address=" + UserAddress.Text
                             + "&phone=" + UserPhone.Text
                             + "&email=" + UserEmail.Text);
             * */
            UserName.Text = Request.QueryString["name"];
            UserID.Text = Request.QueryString["id"];
            UserAddress.Text = Request.QueryString["address"];
            UserPhone.Text = Request.QueryString["phone"];
            UserEmail.Text = Request.QueryString["email"];
            UserPassword.Text=Request.QueryString["password"];

        }

        protected void ChangeUserInfoButton_Click(object sender, EventArgs e)
        {
            //读取更改信息




            //返回用户信息页面
            Response.Redirect("UserInfoPage.aspx");

        }
    }
}