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

using treesafe.Workers;
using treesafe.Account;
namespace treesafe.Users
{
    public partial class UserRiskEvaluationPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["userright"].ToString() != "0")
            {
            //    Server.Transfer("~/WrongPage.aspx", true);
            }
            string _cust_id = new string(treesafe.Account.Login.login_rlt.user_id);
            credit_scores_rlt _info = new credit_scores_rlt(_cust_id);
            credit_scores_input _input = new credit_scores_input(_cust_id);
            web_net_client_mgr _net = new web_net_client_mgr();
            _net.send_command_data(11,_input);
            _info = (credit_scores_rlt)_net.recevie_data(_info.GetType());
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