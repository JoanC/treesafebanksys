using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe.Workers
{
    public partial class WorkerHelpPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["userright"].ToString() != "1")
            {
           //     Server.Transfer("~/WrongPage.aspx", true);
            }

        }
    }
}