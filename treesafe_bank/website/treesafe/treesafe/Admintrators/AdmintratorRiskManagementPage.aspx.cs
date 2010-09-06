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


namespace treesafe.Admintrotors
{
    /*权重查询流程的输入输出结构*/
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按0字节对齐
    struct query_weight_input_info { };//空

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按0字节对齐
    public struct event_wgt
    {
        public float income;
        public float depos;
        public float repayment;
        public float fixed_assets_be_pledged;
        public float id_type;
        public float edu;
        public float marriage;
        public float loan_record;
        public float social_record;
        public float auditor_edit;
        public event_wgt(string _pad)
        {
            income = 0;
            depos = 0;
            repayment = 0;
            fixed_assets_be_pledged = 0;
            id_type = 0;
            edu = 0;
            marriage = 0;
            loan_record = 0;
            social_record = 0;
            auditor_edit = 0;
        }
    } ;

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
    public struct query_weight_info
    {
        public sys_err err_info;//错误信息
        public event_wgt wgt_info;//权重信息 
        public query_weight_info(string _pad) 
        {
            err_info = new sys_err(0,"");
            wgt_info = new event_wgt("");
        }
    };


    public partial class AdmintratorRiskManagementPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["userright"].ToString() != "3")
            {
            //    Server.Transfer("~/WrongPage.aspx", true);
            }
            query_weight_info _query_rlt = query_weight();
            diplay_wgt(_query_rlt.wgt_info);
        }

        public query_weight_info query_weight() 
        {
            query_weight_info _rlt = new query_weight_info("");
            web_net_client_mgr _net = new web_net_client_mgr();
            _net.send_command_data(13,(new query_weight_input_info()));
            _rlt = (query_weight_info)_net.recevie_data(_rlt.GetType());
            return _rlt;
        }

        public void diplay_wgt(event_wgt _info) 
        {
            WeightIncome.Text = "" + _info.income * 100;
            WeightDeposit.Text = "" + _info.depos * 100;
            WeightLoan.Text = "" + _info.repayment * 100;
            WeightMortagage.Text = "" + _info.fixed_assets_be_pledged * 100;
            WeightID.Text = "" + _info.id_type * 100;
            WeightEducation.Text = "" + _info.edu * 100;
            WeightHome.Text = "" + _info.marriage * 100;
            WeightLoanRecord.Text = "" + _info.loan_record * 100;
            WeightSocietyRecord.Text = "" + _info.social_record * 100;
            WeightWork.Text = "" + _info.auditor_edit * 100;
        }

        protected void EditWeightButton_Click(object sender, EventArgs e)
        {
            //将本页9个参数传参
            //Response.Redirect("Add_xmbz.aspx?id="+rid+" && bzid="+rid);

            Response.Redirect("AdmintratorEditRiskPage.aspx?income="+ WeightIncome.Text
                              + "&deposit=" + WeightDeposit.Text
                              + "&loan=" + WeightLoan.Text
                              + "&mortagage=" + WeightMortagage.Text
                              + "&id=" + WeightID.Text
                              + "&education=" + WeightEducation.Text
                              + "&home=" + WeightHome.Text
                              + "&loanrecord=" + WeightLoanRecord.Text
                              + "&societyrecord=" + WeightSocietyRecord.Text
                              + "&work=" + WeightWork.Text);
        }
    }
}