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

        /*与用户UI的交互信息*/
        public static int apply_cust_pincome;
        public static int apply_cust_fincome;
        public static int apply_cust_dep_type;
        public static int apply_cust_reg_dep;
        public static int apply_cust_dem_dep;
        public static int apply_cust_is_has_loan;
        public static int apply_cust_loan_sum;
        public static int apply_cust_loan_time;
        public static int apply_cust_is_has_fixed;
        public static int apply_cust_fixed_type;
        public static int apply_cust_industry;
        public static string apply_cust_work_unit;
        public static string apply_cust_work_pos;


        protected void CreateApplicationButton_Click(object sender, EventArgs e)
        {
            //使用方法同Register
            //（此处所使用方法和控件基本一致）
            //把第一步信息传输到主申请信息中
            apply_cust_pincome = int.Parse(ApplicationPersonIncome.Text);
            apply_cust_fincome = int.Parse(ApplicationHomeIncome.Text);
            apply_cust_dep_type = int.Parse(ApplicationIsHaveDeposit.Text);
            apply_cust_reg_dep = int.Parse(ApplicationDepositFixed.Text);
            apply_cust_dem_dep = int.Parse(ApplicationCurrentDeposit.Text);
            apply_cust_is_has_loan = int.Parse(ApplicationIsHaveLoan.Text);
            apply_cust_loan_sum = int.Parse(ApplicationLoanSum.Text);
            apply_cust_loan_time = int.Parse(ApplicationLoanDeadline.Text);
            apply_cust_is_has_fixed = int.Parse(ApplicationIsMortgage.Text);
            apply_cust_fixed_type = int.Parse(ApplicationMortgage.Text);
            apply_cust_industry = int.Parse(ApplicationIndustry.Text);
            apply_cust_work_unit = 
                Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationWork.Text);
            apply_cust_work_pos =
                Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationPosition.Text);
            //读取完成信息后，跳转到下一个页面继续申请表的填写
            Server.Transfer("~/Users/ApplicationPageNext2.aspx", true);
        }
    }
}