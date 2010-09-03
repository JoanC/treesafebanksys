using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe.Workers
{
    public partial class WorkerRootPage : System.Web.UI.Page
    {


        protected void Page_Load(object sender, EventArgs e)
        {
          //读入操作员基本信息，直接可用如下方法赋值
          //  WorkerPosition.Text = "dfsf";



            if (Session["userright"].ToString() != "1")
            {
         //       Server.Transfer("~/WrongPage.aspx", true);
            }
        }
        public void query_worker_info()
        {

        }
    }
}