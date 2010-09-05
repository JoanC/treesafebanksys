using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using System.IO;
using System.Net;
using System.Net.Sockets;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Runtime.InteropServices;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization;
using ClientNet;
using Chinese_Encode;



namespace treesafe.Users
{

    public partial class UserApplicationPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            //判断权限
            if (Session["userright"].ToString() != "0")
            {
            //    Server.Transfer("~/WrongPage.aspx", true);
            }

            //判断是否已经提交申请表，如果已经提交申请表，自动跳到申请结束界面。
            //下面的代码只能判断该次访问
            if (Session["userapplication"].ToString() == "1")
            {
                Server.Transfer("UserFinishApplicationPage.aspx", true);
            }
            else
            {
                //此处判断当前用户是否提交申请。
            }


        }

        protected void BeginApplication_Click(object sender, EventArgs e)
        {
            Server.Transfer("~/Users/ApplicationPage.aspx", true);
        }
    }
}