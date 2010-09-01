using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe.Admintrators
{
    public partial class AdmintratorEditLaborPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            LaborID.Text = Session["userright"].ToString();
        }

        protected void NewLaborButton_Click(object sender, EventArgs e)
        {

        }
    }
}