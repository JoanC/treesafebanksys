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

using treesafe.Users;


namespace treesafe.Workers
{
    public partial class WorkerApplicationPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["userright"].ToString() != "1")
            {
              //  Server.Transfer("~/WrongPage.aspx", true);
            }

        }

        protected void CreateApplicationButton_Click(object sender, EventArgs e)
        {
            /*开始读取信息*/
            //申请人信息
            int apply_cust_gender = int.Parse(ApplicationSex.Text);
            int apply_cust_age = int.Parse(ApplicationAge.Text);
            int apply_cust_card_type = int.Parse(ApplicationIDType.Text);
            int apply_cust_edu = int.Parse(ApplicationEducation.Text);
            int apply_cust_house_type = int.Parse(ApplicationHouseType.Text);
            string apply_cust_name = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationName.Text);
            string apply_cust_id = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationIDNumber.Text);
            string apply_cust_tel = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationPhoneNumber.Text);
            string apply_cust_other_tel = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationPhoneNumber1.Text);
            string apply_cust_addr = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationAddress.Text);
            string apply_cust_zip = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationPostCode.Text);
            //经济状况
            int apply_cust_pincome = int.Parse(ApplicationPersonIncome.Text);
            int apply_cust_fincome = int.Parse(ApplicationHomeIncome.Text);
            int apply_cust_dep_type = int.Parse(ApplicationIsHaveDeposit.Text);
            int apply_cust_reg_dep = int.Parse(ApplicationDepositFixed.Text);
            int apply_cust_dem_dep = int.Parse(ApplicationCurrentDepositLabel.Text); ;
            int apply_cust_is_has_loan = int.Parse(ApplicationIsHaveLoan.Text);
            int apply_cust_loan_sum = int.Parse(ApplicationLoanSum.Text);
            int apply_cust_loan_time = int.Parse(ApplicationLoanDeadline.Text);
            int apply_cust_is_has_fixed = int.Parse(ApplicationIsMortgage.Text);
            int apply_cust_fixed_type = int.Parse(ApplicationMortgage.Text);
            int apply_cust_industry = int.Parse(ApplicationIndustry.Text);
            string apply_cust_work_unit = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationWork.Text);
            string apply_cust_work_pos = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationPosition.Text);
            //家庭信息
            int apply_cust_mar_stu = int.Parse(ApplicationMarrige.Text);
            int apply_cust_chd_num = int.Parse(ApplicationChildrenNumber.Text);
            int apply_cust_sps_card_type = int.Parse(ApplicationMateIDType.Text);
            int apply_cust_sps_edu = int.Parse(ApplicationMateEducation.Text);
            int apply_cust_is_sps_has_loan = int.Parse(ApplicationMateIsHaveDeposit.Text);
            string apply_cust_sps_name = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationMateName.Text);
            string apply_cust_sps_card_id = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationMateIDNumber.Text);
            string apply_cust_sps_work_unit = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationMateWork.Text);
            //贷款信息
            int cust_loan_amount = int.Parse(ApplicationExpectLoanSum.Text);
            int cust_loan_deadline = int.Parse(ApplicationLoanTime.Text);
            int cust_loan_times = int.Parse(ApplicationLoanNumber.Text);
            int cust_is_want_msg = int.Parse(ApplicationIsMessage.Text);
            string cust_loan_comment = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationLoanNote.Text);
            Server.Transfer("~/Workers/WorkerFinishApplicationPage.aspx", true);
        }
    }
}