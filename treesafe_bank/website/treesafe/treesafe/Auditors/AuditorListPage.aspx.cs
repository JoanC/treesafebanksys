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
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 8)]
        public char[] research_id;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 129)]
        public char[] cust_research_info_comment;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 129)]
        public char[] family_research_info_comment;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 129)]
        public char[] asset_research_info_comment;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 129)]
        public char[] loan_research_info_comment;
        public bool is_research_approved;

        public research_commit_input_info(string _app_id ,string _research_id,bool _is_appr
            ,string _cust_comm,string _family_comm,string _asset_comm,string _loan_comm)
        {
            app_id = _app_id.PadRight(11, '\0').ToCharArray();
            research_id = _research_id.PadRight(8, '\0').ToCharArray();
            is_research_approved = _is_appr;
            cust_research_info_comment = 
                _cust_comm.PadRight(129,'\0').ToCharArray();
            family_research_info_comment = 
                _family_comm.PadRight(129,'\0').ToCharArray();
            asset_research_info_comment = 
                _asset_comm.PadRight(129,'\0').ToCharArray();
            loan_research_info_comment = 
                _loan_comm.PadRight(129,'\0').ToCharArray();
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
            apply_cust_family_info _fami = new apply_cust_family_info(0,0,0,0,false,0,"","","");
            apply_cust_asset_info _asset = new apply_cust_asset_info(0,0,0,0,0,false,0,0,false,0,0,"","");
            query_info = new apply_input_info(_cust,_asset,_fami,_loan);
            err_info = new sys_err(err_type,"");
        }
    };

    public partial class AuditorListPage : System.Web.UI.Page
    {
        public static string research_id = "";
        public static string app_id;
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
            if (this.IsPostBack == false)
            {
                research_exact_info _exact_info = exact_research("");
                app_id = new string(_exact_info.app_id);
                research_query_info _query_info = query_research(app_id);
                display_all_info(_query_info);
            }
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

        protected void display_all_info(research_query_info _info)
        {
            //申请人信息
            ApplicationName.Text = new string(_info.query_info.cust_info.cust_name);
            ApplicationAge.Text = Convert.ToString(_info.query_info.cust_info.cust_age);
            ApplicationSex.Text = _info.query_info.cust_info.cust_gender == 1 ? "男" : "女";
            ApplicationIDType.Text = _info.query_info.cust_info.cust_card_type == 0 ? "身份证" : "军人证";
            ApplicationIDNumber.Text = new string(_info.query_info.cust_info.cust_card_id);
            
            ApplicationAddress.Text = new string(_info.query_info.cust_info.cust_addr);
            ApplicationPostCode.Text = new string(_info.query_info.cust_info.cust_zip);
            ApplicationPhoneNumber.Text = new string(_info.query_info.cust_info.cust_tel);
            ApplicationPhoneNumber1.Text = new string(_info.query_info.cust_info.cust_other_tel);
            string _house_type = "";
            switch (_info.query_info.cust_info.cust_house_type)
            {
                case 0: { _house_type = "自有"; } break;
                case 1: { _house_type = "租赁"; } break;
                case 2: { _house_type = "其他"; } break;
            }
            ApplicationHouseType.Text = _house_type;
            string _edu = "";
            switch(_info.query_info.cust_info.cust_edu_degree)
            {
                case 0:{ _edu = "初中及以下";}break;
                case 1:{_edu = "高中及职业技术学校";}break;
                case 2:{_edu = "本科及大专院校";}break;
                case 3: { _edu = "研究生及以上"; } break;
            }
            ApplicationEducation.Text = _edu;
            /*显示经济情况*/
            string _p_inc = "";
            switch (_info.query_info.asset_info.cust_personal_annual_income) 
            {
                case 0: { _p_inc = "2000元以下";}break;
                case 1: { _p_inc = "2000~5000元";}break;
                case 2: { _p_inc = "5000~8000元";}break;
                case 3: { _p_inc = "8000元~10000元";}break;
                case 4: { _p_inc = "10000~15000元";}break;
                case 5: { _p_inc = "15000~20000元";}break;
                case 6: { _p_inc = "2万元以上";}break;
            }
            ApplicationPersonIncome.Text = _p_inc;
            string _f_inc = "";
            switch (_info.query_info.asset_info.cust_family_annual_income)
            {
                case 0: { _f_inc = "2000元"; } break;
                case 1: { _f_inc = "2000~5000元"; } break;
                case 2: { _f_inc = "5000~1万元"; } break;
                case 3: { _f_inc = "1~3万元"; } break;
                case 4: { _f_inc = "3~5万元"; } break;
                case 5: { _f_inc = "5~10万元"; } break;
                case 6: { _f_inc = "10万元以上"; } break;
            }
            ApplicationHomeIncome.Text = _f_inc;
            ApplicationIsHaveDeposit.Text =
                _info.query_info.asset_info.cust_deposit_type == 1 ? "有" : "无";
            string _reg_dep = "";
            switch (_info.query_info.asset_info.cust_regular_deposit)
            {
                case 0: { _reg_dep = "无存款"; } break;
                case 1: { _reg_dep = "2000元以下"; } break;
                case 2: { _reg_dep = "2000~5000元"; } break;
                case 3: { _reg_dep = "5000~8000元"; } break;
                case 4: { _reg_dep = "8000~1万元"; } break;
                case 5: { _reg_dep = "1万~2万元"; } break;
                case 6: { _reg_dep = "5万元以上"; } break;
            }
            ApplicationDepositFixed.Text = _reg_dep;
            string _dem_dep = "";
            switch (_info.query_info.asset_info.cust_demand_deposit)
            {
                case 0: { _dem_dep= "无存款";}break;
                case 1: { _dem_dep= "2000元以下";}break;
                case 2: { _dem_dep= "2000~5000元";}break;
                case 3: { _dem_dep= "5000~8000元";}break;
                case 4: { _dem_dep= "8000~1万元";}break;
                case 5: {_dem_dep= "1万~2万元";}break;
                case 6: {_dem_dep= "2万~5万元";}break;
                case 7: { _dem_dep = "5万元以上"; } break;
            }
            ApplicationCurrentDeposit.Text = _dem_dep;
            ApplicationIsHaveLoan.Text = 
                (_info.query_info.asset_info.cust_is_has_loan == true) ? "有" : "无";
            string _loan_sum = "";
            switch (_info.query_info.asset_info.cust_loan_sum)
            {
                case 0: { _loan_sum = "无"; } break;
                case 1: { _loan_sum = "2000元以下"; } break;
                case 2: { _loan_sum = "2000~5000元"; } break;
                case 3: { _loan_sum = "5000~8000元"; } break;
                case 4: { _loan_sum = "8000~1万元"; } break;
                case 5: { _loan_sum = "1~2万元"; } break;
                case 6: { _loan_sum = "2~5万元"; } break;
                case 7: { _loan_sum = "5万元以上"; } break;
            }
            ApplicationLoanSum.Text = _loan_sum;
            string _loan_time = "";
            switch (_info.query_info.asset_info.cust_loan_time)
            {
                case 0: { _loan_time = "无"; } break;
                case 1: { _loan_time = "6个月内"; } break;
                case 2: { _loan_time = "6个月~12个月"; } break;
                case 3: { _loan_time = "12个月~24个月"; } break;
                case 4: { _loan_time = "24个月以上"; } break;
            }
            ApplicationLoanDeadline.Text = _loan_time;
            ApplicationIsMortgage.Text =
                (_info.query_info.asset_info.cust_is_has_fixed_asset == true) ? "有" : "无";
            string _fixed_ass = "";
            switch (_info.query_info.asset_info.cust_unsecured_fixed_asset)
            {
                case 0: { _fixed_ass = "住宅"; } break;
                case 1: { _fixed_ass = "工作建筑（厂房）"; } break;
                case 2: { _fixed_ass = "个人交通工具"; } break;
                case 3: { _fixed_ass = "运输工具"; } break;
                case 4: { _fixed_ass = "生产设备"; } break;
                case 5: { _fixed_ass = "其他"; } break;
            }
            ApplicationMortgage.Text = _fixed_ass;
            string _industry = "";
            switch (_info.query_info.asset_info.cust_industry)
            {
                case 0: { _industry = "作物种植"; } break;
                case 1: { _industry = "水产渔业"; } break;
                case 2: { _industry = "林业苗木"; } break;
                case 3: { _industry = "畜牧养殖"; } break;
                case 4: { _industry = "果树蔬菜"; } break;
                case 5: { _industry = "观赏园艺"; } break;
                case 6: { _industry = "农资企业"; } break;
                case 7: { _industry = "农业机械"; } break;
                case 8: { _industry = "加工贮藏"; } break;
                case 9: { _industry = "粮油食品"; } break;
                case 10: { _industry = "交通运输"; } break;
                case 11: { _industry = "生物技术"; } break;
                case 12: { _industry = "遗传育种"; } break;
                case 13: { _industry = "其他"; } break;
            }
            ApplicationIndustry.Text = _industry;
            ApplicationWork.Text =
                new string(_info.query_info.asset_info.cust_work_unit);
            ApplicationPosition.Text =
                new string(_info.query_info.asset_info.cust_work_position);
            /*申请人家庭情况*/
            string _mer_stu = "";
            switch (_info.query_info.family_info.cust_marital_status)
            {
                case 0: { _mer_stu = "未婚"; } break;
                case 1: { _mer_stu = "已婚"; } break;
                case 2: { _mer_stu = "离异"; } break;
                case 4: { _mer_stu = "丧偶"; } break;
            }
            ApplicationMarrige.Text = _mer_stu;
            ApplicationChildrenNumber.Text
                = Convert.ToString(_info.query_info.family_info.cust_children_num);
            ApplicationMateName.Text =
                new string(_info.query_info.family_info.cust_spouse_name);
            ApplicationMateIDType.Text =
                (_info.query_info.family_info.cust_apouse_card_type == 0) ? "身份证" : "军人证";
            ApplicationMateIDNumber.Text
                = new string(_info.query_info.family_info.cust_spouse_card_id);
            ApplicationMateWork.Text
                = new string(_info.query_info.family_info.cust_spouse_work_unit);
            string _spo_edu = "";
            switch (_info.query_info.family_info.cust_spouse_edu_degree)
            {
                case 0: { _spo_edu = "初中及以下"; } break;
                case 1: { _spo_edu = "高中及职业技术学校"; } break;
                case 2: { _spo_edu = "本科及大专院校"; } break;
                case 3: { _spo_edu = "研究生及以上"; } break;
            }
            ApplicationMateEducation.Text = _spo_edu;
            ApplicationMateIsHaveDeposit.Text
                = (_info.query_info.family_info.cust_spouse_is_has_loan == true) ? "有" : "无";
            /*申请贷款情况调查*/
            string _loan_rag = "";
            switch (_info.query_info.loan_info.loan_application_amount)
            {
                case 0: { _loan_rag = "无"; } break;
                case 1: { _loan_rag = "2000元以下"; } break;
                case 2: { _loan_rag = "2000~5000元"; } break;
                case 3: { _loan_rag = "5000~8000元"; } break;
                case 4: { _loan_rag = "8000~1万元"; } break;
                case 5: { _loan_rag = "1~2万元"; } break;
                case 6: { _loan_rag = "2~5万元"; } break;
                case 7: { _loan_rag = "5万元以上"; } break;
            }
            ApplicationExpectLoanSum.Text = _loan_rag;
            ApplicationLoanTime.Text =
                Convert.ToString(_info.query_info.loan_info.loan_dead_line) + " 月";
            ApplicationLoanNumber.Text
                = (_info.query_info.loan_info.loan_times == 0) ? "首次贷款" : "非首次贷款";
            ApplicationLoanNote.Text
                = new string(_info.query_info.loan_info.loan_comment);
            ApplicationIsMessage.Text
                = (_info.query_info.loan_info.is_want_msg == 1) ? "是" : "否";
        }

        protected void CommitApplicationButton_Click(object sender, EventArgs e)
        {
            //读取审核结果
            cust_comm = (Notes1.Text != "") ? Chinese_Encode_Mgr.utf7_convert(Notes1.Text) : "null";
            asset_comm = (Notes2.Text != "") ? Chinese_Encode_Mgr.utf7_convert(Notes2.Text) : "null";
            family_comm = (Notes3.Text != "") ? Chinese_Encode_Mgr.utf7_convert(Notes3.Text) : "null";
            loan_comm = (Notes4.Text != "") ? Chinese_Encode_Mgr.utf7_convert(Notes4.Text) : "null";
            is_all_appr =
                is_asset_appr && is_family_appr && is_loan_appr && is_cust_appr;
           
            //将审核结果发送到服务器
            web_net_client_mgr _commit_send =
                new web_net_client_mgr();
            //发送
            research_commit_input_info _send_commit_info
                = new research_commit_input_info(app_id,research_id,is_all_appr
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