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

using treesafe.Admintrators;

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
        [Serializable] // 指示可序列化
        [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
        public struct employee_query_input_info
        {
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 8)]
            public char[] work_id;//输入的雇员工号
            public employee_query_input_info(string _work_id)
            {
                work_id = _work_id.PadRight(8, '\0').ToCharArray();
            }
        };

        public admin_add_employee_input_info query_worker_info(string _work_id)
        {
            admin_employ_info _query_info
                = new admin_employ_info(0, 0, 0, "", "", "", "", "", "");
            /*最终的查询信息*/
            admin_add_employee_input_info _info
                = new admin_add_employee_input_info("", _query_info);
            //发送请求数据
            web_net_client_mgr _new_mgr =
                new web_net_client_mgr();
            employee_query_input_info _input = new employee_query_input_info(_work_id);
            _new_mgr.send_command_data(8,_input);
            return _info;
        }
    }
}