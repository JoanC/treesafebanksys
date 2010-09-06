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
    struct event_wgt
    {
        float income;
        float depos;
        float repayment;
        float fixed_assets_be_pledged;
        float id_type;
        float edu;
        float marriage;
        float loan_record;
        float social_record;
        float auditor_edit;
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
    struct query_weight_info
    {
        sys_err err_info;//错误信息
        event_wgt wgt_info;//权重信息 
    };


    public partial class AdmintratorRiskManagementPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["userright"].ToString() != "3")
            {
            //    Server.Transfer("~/WrongPage.aspx", true);
            }

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