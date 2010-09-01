﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe.Users
{
    public partial class ApplicationPageNext2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["userright"].ToString() != "0")
            {
             //   Server.Transfer("~/WrongPage.aspx", true);
            }

        }

        /*定义与用户UI的交互数据*/
        public static int apply_cust_mar_stu;
        public static int apply_cust_chd_num;
        public static int apply_cust_sps_card_type;
        public static int apply_cust_sps_edu;
        public static int apply_cust_is_sps_has_loan;
        public static string apply_cust_sps_name;
        public static string apply_cust_sps_card_id;
        public static string apply_cust_sps_work_unit;

        protected void CreateApplicationButton_Click(object sender, EventArgs e)
        {
            //将信息存入数据库。。。
            //使用方法同Register
            //（此处所使用方法和控件基本一致）



            //读取完成信息后，跳转到下一个页面继续申请表的填写
            Server.Transfer("~/Users/ApplicationPageNext3.aspx", true);
        }
    }
}