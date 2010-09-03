using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

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



namespace treesafe.Users
{

    public partial class UserApplicationPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["userright"].ToString() != "0")
            {
            //    Server.Transfer("~/WrongPage.aspx", true);
            }

        }

        protected void BeginApplication_Click(object sender, EventArgs e)
        {
            Server.Transfer("~/Users/ApplicationPage.aspx", true);
        }
    }
}