using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe.Account
{
    public partial class Register : System.Web.UI.Page
    {

        protected void Page_Load(object sender, EventArgs e)
        {
            RegisterUser.ContinueDestinationPageUrl = Request.QueryString["ReturnUrl"];
        }

        protected void RegisterUser_CreatedUser(object sender, EventArgs e)
        {
            //关于创建用户的函数在这里调
            //首先是检查数据
            //确认无误后，添加到数据库。
            //调用数据方法：类似于RegisterUser.UserName。可直接调用，具体名称欢迎参见.aspx。


            FormsAuthentication.SetAuthCookie(RegisterUser.UserName, false /* createPersistentCookie */);



            //下面的这段代码不要改，是界面显示用的。上面那句看不明白。。。。。。。。。不懂。。。。看着办吧。。
            string continueUrl = RegisterUser.ContinueDestinationPageUrl;
            if (String.IsNullOrEmpty(continueUrl))
            {
                continueUrl = "~/";
            }
            Response.Redirect(continueUrl);
        }

    }
}
