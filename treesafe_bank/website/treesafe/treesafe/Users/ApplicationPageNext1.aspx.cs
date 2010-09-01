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

    public partial class ApplicationPageNext1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["userright"].ToString() != "0")
            {
              //  Server.Transfer("~/WrongPage.aspx", true);
            }
            
        }
       

        protected void CreateApplicationButton_Click(object sender, EventArgs e)
        {
            //使用方法同Register
            //（此处所使用方法和控件基本一致）
            //把第一步信息传输到主申请信息中
            

            //读取完成信息后，跳转到下一个页面继续申请表的填写
            Server.Transfer("~/Users/ApplicationPageNext2.aspx", true);
        }
    }
}