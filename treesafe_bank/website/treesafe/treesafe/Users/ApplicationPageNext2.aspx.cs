using System;
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
        public static int apply_cust_mar_stu = 0;
        public static int apply_cust_chd_num = 0;
        public static int apply_cust_sps_card_type = 0;
        public static int apply_cust_sps_edu = 0;
        public static int apply_cust_is_sps_has_loan = 0;
        public static string apply_cust_sps_name = "";
        public static string apply_cust_sps_card_id = "";
        public static string apply_cust_sps_work_unit ="";

        protected void CreateApplicationButton_Click(object sender, EventArgs e)
        {
            //将信息存入数据库。。。
            //使用方法同Register
            //（此处所使用方法和控件基本一致）
            apply_cust_mar_stu = int.Parse(ApplicationMarrige.Text);
            if (apply_cust_mar_stu == 0) Server.Transfer("~/Users/ApplicationPageNext3.aspx", true);
            apply_cust_chd_num = int.Parse(ApplicationChildrenNumber.Text);
            apply_cust_sps_name = 
                Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationMateName.Text);
            apply_cust_sps_card_id =
                Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationMateIDNumber.Text);
            apply_cust_sps_work_unit =
                Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationMateWork.Text);
            apply_cust_sps_edu = int.Parse(ApplicationMateEducation.Text);
            apply_cust_is_sps_has_loan = int.Parse(ApplicationMateIsHaveDeposit.Text);

            //读取完成信息后，跳转到下一个页面继续申请表的填写
            Server.Transfer("~/Users/ApplicationPageNext3.aspx", true);
        }
    }
}