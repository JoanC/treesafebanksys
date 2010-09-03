using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe.Users
{
    public partial class UserChangePassword : System.Web.UI.Page
    {
        string password = "";
        protected void Page_Load(object sender, EventArgs e)
        {
            UserName.Text = Request.QueryString["name"];
            password = Request.QueryString["password"];
        }

        protected void ChangeUserPasswordButton_Click(object sender, EventArgs e)
        {
            if(Session["changepassword"].ToString()=="3")
            {
                Session["changepassword"] = "0";
                Response.Redirect("UserRootPage.aspx");
            }

            if (password != UserOldPassword.Text)
            {
                //session+1
                int help = int.Parse(Session["changepassword"].ToString());
                help = help + 1;
                Session["changepassword"] = help.ToString();

                //弹出警告框
               // Response.Write("<script>alert('你输入的原密码错误！')</script>");
            }
            else
            {
                //将数据读入数据库


                //跳转页面至个人信息页面
                Response.Redirect("UserInfoPage.aspx");
            }
        }
    }
}