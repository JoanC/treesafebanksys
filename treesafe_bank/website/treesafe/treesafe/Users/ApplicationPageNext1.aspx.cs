﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe.Users
{
    public partial class ApplicationPageNext1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            
        }

        protected void CreateApplicationButton_Click(object sender, EventArgs e)
        {
            //将信息存入数据库。。。
            //使用方法同Register
            //（此处所使用方法和控件基本一致）
            


            //读取完成信息后，跳转到下一个页面继续申请表的填写
            Server.Transfer("~/Users/ApplicationPageNext2.aspx", true);
        }
    }
}