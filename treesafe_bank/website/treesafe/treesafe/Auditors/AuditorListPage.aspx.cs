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
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    struct research_commit_inoput_info
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 11)]
        public char[] app_id;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
        public char[] research_id;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
        public char[] cust_research_info_comment;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
        public char[] family_research_info_comment;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
        public char[] asset_research_info_comment;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
        public char[] loan_research_info_comment;
        public bool is_research_approved;

        public research_commit_inoput_info(string _research_id,bool _is_appr
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
        public static string research_id = "";
        public static string app_id = "";
        public static string cust_comm;
        public static string family_comm;
        public static string asset_comm;
        public static string loan_comm;
        public static bool is_cust_appr;
        public static bool is_family_appr;
        public static bool is_asset_appr;
        public static bool is_loan_appr;
        public static bool is_all_appr;

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
            is_cust_appr = !is_cust_appr;
        }

        protected void CheckBox2_CheckedChanged(object sender, EventArgs e)
        {
            is_asset_appr = !is_asset_appr;
        }

        protected void CheckBox3_CheckedChanged(object sender, EventArgs e)
        {
            is_family_appr = !is_family_appr;
        }

        protected void CheckBox4_CheckedChanged(object sender, EventArgs e)
        {
            is_loan_appr = !is_loan_appr;
        }

        protected void CommitApplicationButton_Click(object sender, EventArgs e)
        {
            //读取审核结果
            cust_comm = Chinese_Encode_Mgr.utf7_convert(Notes1.Text);
            asset_comm = Chinese_Encode_Mgr.utf7_convert(Notes2.Text);
            family_comm = Chinese_Encode_Mgr.utf7_convert(Notes3.Text);
            loan_comm = Chinese_Encode_Mgr.utf7_convert(Notes4.Text);
            is_all_appr =
                is_asset_appr && is_family_appr && is_loan_appr && is_cust_appr;
           
            //将审核结果发送到服务器
            web_net_client_mgr _commit_send =
                new web_net_client_mgr();
            //发送
            research_commit_inoput_info _send_commit_info
                = new research_commit_inoput_info(research_id,is_all_appr
                    ,cust_comm,family_comm,asset_comm,loan_comm);
            _commit_send.send_command_data(5,_send_commit_info);

            //跳转到申请成功界面
            if (is_all_appr )
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