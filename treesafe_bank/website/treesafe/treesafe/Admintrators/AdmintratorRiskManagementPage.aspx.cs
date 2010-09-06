using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe.Admintrotors
{


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