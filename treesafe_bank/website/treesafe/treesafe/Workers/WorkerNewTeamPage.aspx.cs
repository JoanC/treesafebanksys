using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe.Workers
{
    public partial class WorkerNewTeamPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void NewTeamButton_Click(object sender, EventArgs e)
        {
            //读取数据







            //跳转到联保小组界面
            Response.Redirect("WorkerTeamPage.aspx");
        }
    }
}