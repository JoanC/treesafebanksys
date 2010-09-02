using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using treesafe;

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

namespace treesafe.Auditors
{
    /*
    struct research_commit_input_info{
	//被提交的申请的相关信息
	char research_apply_id[RESEARCH_COMMIT_APPLY_ID_LEN];
	//申请的相关信息
	char researcher_id[RESEARCH_COMMIT_RESEARCHER_ID_LEN];
	//有待亦可确定
	bool is_research_approved;//审核是否通过
	//个人信息审核注释
	char cust_research_info_comment[RESEARCH_COMMIT_COMMENT];
	//家庭信息审核过程
	char family_research_info_comment[RESEARCH_COMMIT_COMMENT];
	//资产信息审核过程
	char asset_research_info_comment[RESEARCH_COMMIT_COMMENT];
	//贷款信息
	char loan_research_info_comment[RESEARCH_COMMIT_COMMENT];
};*/
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    struct research_commit_inoput_info
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 11)]
        public char[] app_id;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
        public char[] research_id;
        public int is_research_approved;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
        public char[] cust_research_info_comment;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
        public char[] family_research_info_comment;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
        public char[] asset_research_info_comment;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
        public char[] loan_research_info_comment;

        public research_commit_inoput_info(string _research_id,int _is_appr
            ,string _cust_comm,string _family_comm,string _asset_comm,string _loan_comm)
        {
            app_id = "".PadRight(11, '\0').ToCharArray();
            research_id = _research_id.PadRight(19, '\0').ToCharArray();
            is_research_approved = _is_appr;
            cust_research_info_comment = 
                _cust_comm.PadRight(128,'\0').ToCharArray();
            family_research_info_comment = 
                _family_comm.PadRight(128,'\0').ToCharArray();
            asset_research_info_comment = 
                _asset_comm.PadRight(128,'\0').ToCharArray();
            loan_research_info_comment = 
                _loan_comm.PadRight(128,'\0').ToCharArray();
        }
    }


    public partial class AuditorListPage : System.Web.UI.Page
    {
        public static string research_id;
        public static string app_id;
        public static string cust_comm;
        public static string family_comm;
        public static string asset_comm;
        public static string loan_comm;
        public static int is_cust_appr;
        public static int is_family_appr;
        public static int is_asset_appr;
        public static int is_loan_appr;
        public static int is_loan

        protected void Page_Load(object sender, EventArgs e)
        {
            //判断权限
            if (Session["userright"].ToString() != "2")
            {
             //   Server.Transfer("~/WrongPage.aspx", true);
            }

            //从服务器端读取农户的申请信息，并显示在对应页面控件上

        }

        protected void CheckBox1_CheckedChanged(object sender, EventArgs e)
        {
            is_cust_appr = int.Parse(CheckBox1.Text);
        }

        protected void CheckBox2_CheckedChanged(object sender, EventArgs e)
        {

        }

        protected void CheckBox3_CheckedChanged(object sender, EventArgs e)
        {

        }

        protected void CheckBox4_CheckedChanged(object sender, EventArgs e)
        {

        }

        protected void CommitApplicationButton_Click(object sender, EventArgs e)
        {
            //读取审核结果

           

            //跳转到申请成功界面
            if (CheckBox1.Checked && CheckBox2.Checked && CheckBox3.Checked && CheckBox4.Checked)
            { 
                //申请通过
                //跳转到打分界面
                Response.Redirect("AuditorGradePage.aspx?id=" + ApplicationIDNumber.Text);


                
            }
            else
            {
                //申请没有通过
                //跳转到审核成功界面
                Response.Redirect("AuditorCommitPage.aspx");
            }
        }
    }
}