using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe.Admintrators
{
    public partial class AdmintratorEditRiskPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void FinishEditWeightButton_Click(object sender, EventArgs e)
        {
            //刷新父页面,关闭该窗口并返回主界面

            Response.Write("<script language='javascript'>window.opener.location.reload()</script>");
            Response.Write("<script language='javascript'>window.close();</script>");
        }
    }
}