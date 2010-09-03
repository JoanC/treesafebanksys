using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe.Auditors
{
    public partial class AuditorGradePage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            UserID.Text = Request.QueryString["id"];
        }

        protected void CommitApplicationGradeButton_Click(object sender, EventArgs e)
        {
            //读取信息

            //结束评分，跳转到成功界面
            Response.Redirect("AuditorCommitPage.aspx");
        }
    }
}