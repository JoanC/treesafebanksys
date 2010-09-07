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

namespace treesafe.Workers
{
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
    public struct credit_scores_input
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
        public char[] card_id;
        public credit_scores_input(string _id)
        {
            card_id = _id.PadRight(19, '\0').ToCharArray();
        }
    }

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
    public struct credit_scores_rlt // 查询结果
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
        public char[] card_id;
        public float score_income;
        public float score_depos;
        public float score_repayment;
        public float score_fixed_assets_be_pledged;
        public float score_id_type;
        public float score_edu;
        public float score_marriage;
        public float score_loan_record;
        public float score_bad_social_record;
        public float score_auditor_edit;
        public credit_scores_rlt(string _id)
        {
            this.card_id = _id.PadRight(19, '\0').ToCharArray();
            score_income = 0;
            score_depos = 0;
            score_repayment = 0;
            score_fixed_assets_be_pledged = 0;
            score_id_type = 0;
            score_edu = 0;
            score_marriage = 0;
            score_loan_record = 0;
            score_bad_social_record = 0;
            score_auditor_edit = 0;
        }
    } ;
    public partial class WorkerOneUserDataPage : System.Web.UI.Page
    {

       

        protected void Page_Load(object sender, EventArgs e)
        {
            string _cust_id = Request.QueryString["id"];
            int _index = int.Parse(_cust_id);
            _cust_id = new string(WorkerUserDataPage._rlt._info[_index].user_card_id);
            credit_scores_input _input = new credit_scores_input(_cust_id);
            web_net_client_mgr _net = new web_net_client_mgr();
            credit_scores_rlt _rlt = new credit_scores_rlt("");
            _net.send_command_data(11, _input);
            try
            {
                  _rlt = (credit_scores_rlt)_net.recevie_data(_rlt.GetType());
            }
            catch (Exception)
            {
                WrongPage.wrong_msg = "与服务器连接失败!\n请检查网路问题并请重新登录";
                Server.Transfer("~/WrongPage.aspx", true);
            }
            
            display_score(_rlt);
            return;
        }

        public void display_score(credit_scores_rlt _info)
        {
            WeightIncome.Text = "" + _info.score_income;
            WeightDeposit.Text = "" + _info.score_depos;
            WeightLoan.Text = "" + _info.score_repayment;
            WeightMortagage.Text = "" + _info.score_fixed_assets_be_pledged;
            WeightID.Text = "" + _info.score_id_type;
            WeightEducation.Text = "" + _info.score_edu;
            WeightHome.Text = "" + _info.score_marriage;
            WeightLoanRecord.Text = "" + _info.score_loan_record;
            WeightSocietyRecord.Text = "" + _info.score_bad_social_record;
            WeightWork.Text = "" + _info.score_auditor_edit;
        }
    }
}