using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe
{
    public partial class WrongPage : System.Web.UI.Page
    {
        public static string wrong_msg;

        protected void Page_Load(object sender, EventArgs e)
        {
            WrongMsg.Text = wrong_msg;
            wrong_msg = "";
        }
    }
}