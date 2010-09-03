using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using treesafe;
using treesafe.Users;

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
    public struct research_exact_input_info{
    [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
	public char[] research_work_id;//审核员工号
    public research_exact_input_info(string _work_id)
    {
        research_work_id = _work_id.PadRight(19,'\0').ToCharArray();
    }
};
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    public struct research_exact_info 
    { 
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 11)]
        public char[] app_id;//返回的一个待审核申请的id
	    sys_err err_info;//错误信息
        public research_exact_info(string _app_id)
        {
            err_info = new sys_err(0,"");
            app_id = _app_id.PadRight(11,'\0').ToCharArray();
        }
    }

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    public struct research_commit_input_info
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

        public research_commit_input_info(string _research_id,bool _is_appr
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

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    public struct research_query_input_info
    {
	//输入的信息
	//从界面上传输一个申请的id号码
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 11)]
        public char[] app_id;//APPLY定义为长度11
        public research_query_input_info(string _app_id)
        {
            app_id = _app_id.PadRight(11, '\0').ToCharArray();
        }
    }

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    public struct research_query_info
    {
        //申请查询的结果信息
        public apply_input_info query_info;//结果信息
        public sys_err err_info;//错误信息
        public research_query_info(int err_type)
        {
            apply_loan_info _loan = new apply_loan_info(0,0,0,0,"");
            apply_custmor_info _cust = new apply_custmor_info(0,0,0,0,0,"","","","","","");
            apply_cust_family_info _fami = new apply_cust_family_info(0,0,0,0,0,0,"","","");
            apply_cust_asset_info _asset = new apply_cust_asset_info(0,0,0,0,0,0,0,0,0,0,0,"","");
            query_info = new apply_input_info(_cust,_asset,_fami,_loan);
            err_info = new sys_err(err_type,"");
        }
    };

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
            //发送抽取app_id的指令,并收取信息
           // research_exact_info _rlt_result = exact_research("");
            //从服务器端读取农户的申请信息，并显示在对应页面控件上
            research_exact_info _exact_info = exact_research("");
            string _app_id = new string(_exact_info.app_id);
            research_query_info _query_info = query_research(_app_id);
        }

        protected research_exact_info exact_research(string _work_id)
        {
            web_net_client_mgr _exact_net =new web_net_client_mgr();
            research_exact_input_info _input = new research_exact_input_info(_work_id);
            //发送信息
            try
            {
                _exact_net.send_command_data(7, _input);
            }
            catch (Exception)
            {
                WrongPage.wrong_msg = "与服务器连接失败!\n向服务器发送research_exact请求失败\n,请检查网路问题并请重新登录";
                Server.Transfer("~/WrongPage.aspx", true);
            }
            //获取信息
            research_exact_info _rlt = new research_exact_info("");
            try
            {
                _rlt = (research_exact_info)_exact_net.recevie_data(_rlt.GetType());
            }
            catch (Exception)
            {
                WrongPage.wrong_msg = "与服务器连接失败!\n在抽取新的待审核信息时发生网络错误,请检查网路问题并请重新登录";
                Server.Transfer("~/WrongPage.aspx", true);
            }
            return _rlt;
        }

        protected research_query_info query_research(string _app_id)
        {
            research_query_input_info _input = new research_query_input_info(_app_id);
            web_net_client_mgr _query_net= new web_net_client_mgr();
            research_query_info _rlt = new research_query_info(0);
            //发送请求
            try
            {
                _query_net.send_command_data(6, _input);
            }
            catch (Exception)
            {
                WrongPage.wrong_msg = "与服务器连接失败!\n向服务器发送research_query请求失败\n,请检查网路问题并请重新登录";
                Server.Transfer("~/WrongPage.aspx", true);
            }
            //接受资料
            try
            {
                _rlt = (research_query_info)_query_net.recevie_data(_rlt.GetType());
            }
            catch (Exception)
            {
                WrongPage.wrong_msg = "与服务器连接失败!\n在读取待审核信息时发生网络错误,请检查网路问题并请重新登录";
                Server.Transfer("~/WrongPage.aspx", true);
            }
            return _rlt;
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
            research_commit_input_info _send_commit_info
                = new research_commit_input_info(research_id,is_all_appr
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