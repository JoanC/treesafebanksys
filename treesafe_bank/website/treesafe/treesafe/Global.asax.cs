using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.SessionState;

namespace treesafe
{
    public class Global : System.Web.HttpApplication
    {

        void Application_Start(object sender, EventArgs e)
        {
            // Code that runs on application startup

        }

        void Application_End(object sender, EventArgs e)
        {
            //  Code that runs on application shutdown

        }

        void Application_Error(object sender, EventArgs e)
        {
            // Code that runs when an unhandled error occurs

        }

        void Session_Start(object sender, EventArgs e)
        {
            // Code that runs when a new session is started
            Session["userright"] = "-1";


            //控制用户界面数据处理
            Session["userapplication"] = "0";
            Session["userrisk"] = "0";

            //防止数据重复提交
            Session["riskpage"] = "0";


            //用户更改密码保护
            Session["changepassword"] = "0";


            //更改密码时，传递现有密码
            Session["currentpassword"] = "0";


            //useridcard
            Session["useridcard"] = "0";
            
        }

        void Session_End(object sender, EventArgs e)
        {
            // Code that runs when a session ends. 
            // Note: The Session_End event is raised only when the sessionstate mode
            // is set to InProc in the Web.config file. If session mode is set to StateServer 
            // or SQLServer, the event is not raised.

        }

    }
}
