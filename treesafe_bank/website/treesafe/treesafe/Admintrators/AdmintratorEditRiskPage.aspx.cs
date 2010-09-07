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

namespace treesafe.Admintrators
{
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按0字节对齐
    public struct event_wgt
    {
        public int income;
        public int depos;
        public int repayment;
        public int fixed_assets_be_pledged;
        public int id_type;
        public int edu;
        public int marriage;
        public int loan_record;
        public int social_record;
        public int auditor_edit;
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
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    struct update_weight_input
    {
        public event_wgt new_wgt;//新的权重
        public update_weight_input(string _pad)
        {
            new_wgt = new event_wgt("");
        }
    };

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    struct update_weight_info
    {
        public sys_err err_info;
        public update_weight_info(string _pad) 
        {
            err_info = new sys_err(0,_pad);
        }
    };

    public partial class AdmintratorEditRiskPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            //从显示权重页面读入数据
            if (Session["riskpage"].ToString() == "0")
            {
                WeightIncome.Text = Request.QueryString["income"];
                WeightDeposit.Text = Request.QueryString["deposit"];
                WeightLoan.Text = Request.QueryString["loan"];
                WeightMortagage.Text = Request.QueryString["mortagage"];
                WeightID.Text = Request.QueryString["id"];
                WeightEducation.Text = Request.QueryString["education"];
                WeightHome.Text = Request.QueryString["home"];
                WeightLoanRecord.Text = Request.QueryString["loanrecord"];
                WeightSocietyRecord.Text = Request.QueryString["societyrecord"];
                WeightWork.Text = Request.QueryString["work"];
                Session["riskpage"] = "1";
            }
        }

        protected void FinishEditWeightButton_Click(object sender, EventArgs e)
        {
            //读取页面数据
            //存储数据
            web_net_client_mgr _net = new web_net_client_mgr();
           // _net.send_command_data(14,);
            event_wgt _data = get_data();
            update_weight_input _input = new update_weight_input("");
            _input.new_wgt = _data;
            _net.send_command_data(14,_input);
            update_weight_info _rlt = new update_weight_info("");
            try
            {
                   _rlt = (update_weight_info)_net.recevie_data(_rlt.GetType());
            }
            catch (Exception)
            {
                WrongPage.wrong_msg = "与服务器连接失败!\n请检查网路问题并请重新登录";
                Server.Transfer("~/WrongPage.aspx", true);
            }
            
            //返回权重显示页面
            Session["riskpage"] = "0";
            Response.Redirect("AdmintratorRiskManagementPage.aspx");
        }

        protected event_wgt get_data()
        {
            event_wgt _data = new event_wgt("");
            _data.income = int.Parse(WeightIncome.Text);
            _data.depos = int.Parse(WeightDeposit.Text);
            _data.repayment = int.Parse(WeightLoan.Text);
            _data.fixed_assets_be_pledged
                = int.Parse(WeightMortagage.Text);
            _data.id_type = int.Parse(WeightID.Text);
            _data.edu = int.Parse(WeightEducation.Text);
            _data.marriage = int.Parse(WeightHome.Text);
            _data.loan_record = int.Parse(WeightLoanRecord.Text);
            _data.social_record = int.Parse(WeightSocietyRecord.Text);
            _data.auditor_edit = int.Parse(WeightWork.Text);
            return _data;
        }

        protected void WeightIncomeAdd_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightIncome.Text);

            if (_first == 100)
            {
                return;
            }
            else
            {
              
                if (WeightWork.Text != "0")
                {
                    int _last = int.Parse(WeightWork.Text);
                    WeightIncome.Text = (_first + 1).ToString();
                    WeightWork.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightSocietyRecord.Text != "0")
                {
                    int _last = int.Parse(WeightSocietyRecord.Text);
                    WeightIncome.Text = (_first + 1).ToString();
                    WeightSocietyRecord.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightLoanRecord.Text != "0")
                {
                    int _last = int.Parse(WeightLoanRecord.Text);
                    WeightIncome.Text = (_first + 1).ToString();
                    WeightLoanRecord.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightHome.Text != "0")
                {
                    int _last = int.Parse(WeightHome.Text);
                    WeightIncome.Text = (_first + 1).ToString();
                    WeightHome.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightEducation.Text != "0")
                {
                    int _last = int.Parse(WeightEducation.Text);
                    WeightIncome.Text = (_first + 1).ToString();
                    WeightEducation.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightID.Text != "0")
                {
                    int _last = int.Parse(WeightID.Text);
                    WeightIncome.Text = (_first + 1).ToString();
                    WeightID.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightMortagage.Text != "0")
                {
                    int _last = int.Parse(WeightMortagage.Text);
                    WeightIncome.Text = (_first + 1).ToString();
                    WeightMortagage.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightLoan.Text != "0")
                {
                    int _last = int.Parse(WeightLoan.Text);
                    WeightIncome.Text = (_first + 1).ToString();
                    WeightLoan.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightDeposit.Text != "0")
                {
                    int _last = int.Parse(WeightDeposit.Text);
                    WeightIncome.Text = (_first + 1).ToString();
                    WeightDeposit.Text = (_last - 1).ToString();
                    return;
                }
            }
        }

        protected void WeightIncomeSub_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightIncome.Text);
            int _last = int.Parse(WeightWork.Text);
            if (_first == 0)
            {
                return;
            }
            else
            {
                WeightIncome.Text = (_first - 1).ToString();
                WeightWork.Text = (_last + 1).ToString();
            }
           
        }

        protected void WeightDepositAdd_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightDeposit.Text);

            if (_first == 100)
            {
                return;
            }
            else
            {

                if (WeightWork.Text != "0")
                {
                    int _last = int.Parse(WeightWork.Text);
                    WeightDeposit.Text = (_first + 1).ToString();
                    WeightWork.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightSocietyRecord.Text != "0")
                {
                    int _last = int.Parse(WeightSocietyRecord.Text);
                    WeightDeposit.Text = (_first + 1).ToString();
                    WeightSocietyRecord.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightLoanRecord.Text != "0")
                {
                    int _last = int.Parse(WeightLoanRecord.Text);
                    WeightDeposit.Text = (_first + 1).ToString();
                    WeightLoanRecord.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightHome.Text != "0")
                {
                    int _last = int.Parse(WeightHome.Text);
                    WeightDeposit.Text = (_first + 1).ToString();
                    WeightHome.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightEducation.Text != "0")
                {
                    int _last = int.Parse(WeightEducation.Text);
                    WeightDeposit.Text = (_first + 1).ToString();
                    WeightEducation.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightID.Text != "0")
                {
                    int _last = int.Parse(WeightID.Text);
                    WeightDeposit.Text = (_first + 1).ToString();
                    WeightID.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightMortagage.Text != "0")
                {
                    int _last = int.Parse(WeightMortagage.Text);
                    WeightDeposit.Text = (_first + 1).ToString();
                    WeightMortagage.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightLoan.Text != "0")
                {
                    int _last = int.Parse(WeightLoan.Text);
                    WeightDeposit.Text = (_first + 1).ToString();
                    WeightLoan.Text = (_last - 1).ToString();
                    return;
                }
            }
        }

        protected void WeightDepositSub_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightDeposit.Text);
            int _last = int.Parse(WeightWork.Text);
            if (_first == 0)
            {
                return;
            }
            else
            {
                WeightDeposit.Text = (_first - 1).ToString();
                WeightWork.Text = (_last + 1).ToString();
            }

        }

        protected void WeightLoanAdd_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightLoan.Text);

            if (_first == 100)
            {
                return;
            }
            else
            {

                if (WeightWork.Text != "0")
                {
                    int _last = int.Parse(WeightWork.Text);
                    WeightLoan.Text = (_first + 1).ToString();
                    WeightWork.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightSocietyRecord.Text != "0")
                {
                    int _last = int.Parse(WeightSocietyRecord.Text);
                    WeightLoan.Text = (_first + 1).ToString();
                    WeightSocietyRecord.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightLoanRecord.Text != "0")
                {
                    int _last = int.Parse(WeightLoanRecord.Text);
                    WeightLoan.Text = (_first + 1).ToString();
                    WeightLoanRecord.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightHome.Text != "0")
                {
                    int _last = int.Parse(WeightHome.Text);
                    WeightLoan.Text = (_first + 1).ToString();
                    WeightHome.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightEducation.Text != "0")
                {
                    int _last = int.Parse(WeightEducation.Text);
                    WeightLoan.Text = (_first + 1).ToString();
                    WeightEducation.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightID.Text != "0")
                {
                    int _last = int.Parse(WeightID.Text);
                    WeightLoan.Text = (_first + 1).ToString();
                    WeightID.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightMortagage.Text != "0")
                {
                    int _last = int.Parse(WeightMortagage.Text);
                    WeightLoan.Text = (_first + 1).ToString();
                    WeightMortagage.Text = (_last - 1).ToString();
                    return;
                }
            }
        }

        protected void WeightLoanSub_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightLoan.Text);
            int _last = int.Parse(WeightWork.Text);
            if (_first == 0)
            {
                return;
            }
            else
            {
                WeightLoan.Text = (_first - 1).ToString();
                WeightWork.Text = (_last + 1).ToString();
            }

        }

        protected void WeightMortagageAdd_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightMortagage.Text);

            if (_first == 100)
            {
                return;
            }
            else
            {

                if (WeightWork.Text != "0")
                {
                    int _last = int.Parse(WeightWork.Text);
                    WeightMortagage.Text = (_first + 1).ToString();
                    WeightWork.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightSocietyRecord.Text != "0")
                {
                    int _last = int.Parse(WeightSocietyRecord.Text);
                    WeightMortagage.Text = (_first + 1).ToString();
                    WeightSocietyRecord.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightLoanRecord.Text != "0")
                {
                    int _last = int.Parse(WeightLoanRecord.Text);
                    WeightMortagage.Text = (_first + 1).ToString();
                    WeightLoanRecord.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightHome.Text != "0")
                {
                    int _last = int.Parse(WeightHome.Text);
                    WeightMortagage.Text = (_first + 1).ToString();
                    WeightHome.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightEducation.Text != "0")
                {
                    int _last = int.Parse(WeightEducation.Text);
                    WeightMortagage.Text = (_first + 1).ToString();
                    WeightEducation.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightID.Text != "0")
                {
                    int _last = int.Parse(WeightID.Text);
                    WeightMortagage.Text = (_first + 1).ToString();
                    WeightID.Text = (_last - 1).ToString();
                    return;
                }
            }
        }

        protected void WeightMortagageSub_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightMortagage.Text);
            int _last = int.Parse(WeightWork.Text);
            if (_first == 0)
            {
                return;
            }
            else
            {
                WeightMortagage.Text = (_first - 1).ToString();
                WeightWork.Text = (_last + 1).ToString();
            }

        }

        protected void WeightIDAdd_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightID.Text);

            if (_first == 100)
            {
                return;
            }
            else
            {

                if (WeightWork.Text != "0")
                {
                    int _last = int.Parse(WeightWork.Text);
                    WeightID.Text = (_first + 1).ToString();
                    WeightWork.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightSocietyRecord.Text != "0")
                {
                    int _last = int.Parse(WeightSocietyRecord.Text);
                    WeightID.Text = (_first + 1).ToString();
                    WeightSocietyRecord.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightLoanRecord.Text != "0")
                {
                    int _last = int.Parse(WeightLoanRecord.Text);
                    WeightID.Text = (_first + 1).ToString();
                    WeightLoanRecord.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightHome.Text != "0")
                {
                    int _last = int.Parse(WeightHome.Text);
                    WeightID.Text = (_first + 1).ToString();
                    WeightHome.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightEducation.Text != "0")
                {
                    int _last = int.Parse(WeightEducation.Text);
                    WeightID.Text = (_first + 1).ToString();
                    WeightEducation.Text = (_last - 1).ToString();
                    return;
                }
            }
        }

        protected void WeightIDSub_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightID.Text);
            int _last = int.Parse(WeightWork.Text);
            if (_first == 0)
            {
                return;
            }
            else
            {
                WeightID.Text = (_first - 1).ToString();
                WeightWork.Text = (_last + 1).ToString();
            }

        }

        protected void WeightEducationAdd_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightEducation.Text);

            if (_first == 100)
            {
                return;
            }
            else
            {

                if (WeightWork.Text != "0")
                {
                    int _last = int.Parse(WeightWork.Text);
                    WeightEducation.Text = (_first + 1).ToString();
                    WeightWork.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightSocietyRecord.Text != "0")
                {
                    int _last = int.Parse(WeightSocietyRecord.Text);
                    WeightEducation.Text = (_first + 1).ToString();
                    WeightSocietyRecord.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightLoanRecord.Text != "0")
                {
                    int _last = int.Parse(WeightLoanRecord.Text);
                    WeightEducation.Text = (_first + 1).ToString();
                    WeightLoanRecord.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightHome.Text != "0")
                {
                    int _last = int.Parse(WeightHome.Text);
                    WeightEducation.Text = (_first + 1).ToString();
                    WeightHome.Text = (_last - 1).ToString();
                    return;
                }
            }
        }

        protected void WeightEducationSub_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightEducation.Text);
            int _last = int.Parse(WeightWork.Text);
            if (_first == 0)
            {
                return;
            }
            else
            {
                WeightEducation.Text = (_first - 1).ToString();
                WeightWork.Text = (_last + 1).ToString();
            }

        }

        protected void WeightHomeAdd_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightHome.Text);

            if (_first == 100)
            {
                return;
            }
            else
            {

                if (WeightWork.Text != "0")
                {
                    int _last = int.Parse(WeightWork.Text);
                    WeightHome.Text = (_first + 1).ToString();
                    WeightWork.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightSocietyRecord.Text != "0")
                {
                    int _last = int.Parse(WeightSocietyRecord.Text);
                    WeightHome.Text = (_first + 1).ToString();
                    WeightSocietyRecord.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightLoanRecord.Text != "0")
                {
                    int _last = int.Parse(WeightLoanRecord.Text);
                    WeightHome.Text = (_first + 1).ToString();
                    WeightLoanRecord.Text = (_last - 1).ToString();
                    return;
                }
            }
        }

        protected void WeightHomeSub_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightHome.Text);
            int _last = int.Parse(WeightWork.Text);
            if (_first == 0)
            {
                return;
            }
            else
            {
                WeightHome.Text = (_first - 1).ToString();
                WeightWork.Text = (_last + 1).ToString();
            }

        }

        protected void WeightLoanRecordAdd_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightLoanRecord.Text);

            if (_first == 100)
            {
                return;
            }
            else
            {

                if (WeightWork.Text != "0")
                {
                    int _last = int.Parse(WeightWork.Text);
                    WeightLoanRecord.Text = (_first + 1).ToString();
                    WeightWork.Text = (_last - 1).ToString();
                    return;
                }
                if (WeightSocietyRecord.Text != "0")
                {
                    int _last = int.Parse(WeightSocietyRecord.Text);
                    WeightLoanRecord.Text = (_first + 1).ToString();
                    WeightSocietyRecord.Text = (_last - 1).ToString();
                    return;
                }
            }
        }

        protected void WeightLoanRecordSub_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightLoanRecord.Text);
            int _last = int.Parse(WeightWork.Text);
            if (_first == 0)
            {
                return;
            }
            else
            {
                WeightLoanRecord.Text = (_first - 1).ToString();
                WeightWork.Text = (_last + 1).ToString();
            }

        }

        protected void WeightSocietyRecordAdd_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightSocietyRecord.Text);

            if (_first == 100)
            {
                return;
            }
            else
            {

                if (WeightWork.Text != "0")
                {
                    int _last = int.Parse(WeightWork.Text);
                    WeightSocietyRecord.Text = (_first + 1).ToString();
                    WeightWork.Text = (_last - 1).ToString();
                    return;
                }
            }
        }

        protected void WeightSocietyRecordSub_Click(object sender, ImageClickEventArgs e)
        {
            int _first = int.Parse(WeightSocietyRecord.Text);
            int _last = int.Parse(WeightWork.Text);
            if (_first == 0)
            {
                return;
            }
            else
            {
                WeightSocietyRecord.Text = (_first - 1).ToString();
                WeightWork.Text = (_last + 1).ToString();
            }

        }

        protected void WeightWorkAdd_Click(object sender, ImageClickEventArgs e)
        {

        }

        protected void WeightWorkSub_Click(object sender, ImageClickEventArgs e)
        {

        }
    }
        
}