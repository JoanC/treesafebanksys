using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe.Workers
{
    public partial class WorkerFinishApplicationPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void ButtonFinishApplication_Click(object sender, EventArgs e)
        {
            Server.Transfer("~/Workers/WorkerRootPage.aspx", true);
        }
    }
}