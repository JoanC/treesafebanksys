using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using treesafe;
using treesafe.Users;

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

using System.Web.UI.HtmlControls;


namespace treesafe.Workers
{
    /*以下定义的是协议结构体*/
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    public struct user_query_array_info
    {
        public int user_num;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 100)]
        public user_query_info[] user_array;
        public user_query_array_info(int _num)
        {
            user_num = _num;
            user_array = new user_query_info[100];
        }
    };

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    public struct user_query_arr_info
    {
        public user_query_array_info query_arr_info;//数组信息
        public sys_err err_info;
        public user_query_arr_info()
        {
            query_arr_info = new user_query_array_info(0);
            err_info = new sys_err(0,"");
        }
    };//结果信息

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    struct user_query_arr_input { };

    public partial class WorkerUserDataPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["userright"].ToString() != "1")
            {
            //    Server.Transfer("~/WrongPage.aspx", true);
            }

            user_query_arr_info _rlt = GetUserInfoArr();

            //读取农户数据
            GetLaborInfo();
        }

        protected user_query_arr_info GetUserInfoArr()
        {
            user_query_arr_info _info = new user_query_arr_info();
            /*发送指令*/
            web_net_client_mgr _net = new web_net_client_mgr();
            user_query_arr_input _input = new user_query_arr_input();
            _net.send_command_data(9, _input);
            _net.recevie_data(_info.GetType());
            return _info;
        }

        protected void GetLaborInfo()
        {
            int row = 0;
            // 获得农户列表的项数（即*成功*提交申请表并*通过审核*的总人数）
            int numrows = 10;
            //列表宽度，共8项内容
            int numcells = 6;
            for (int j = 0; j < numrows; j++)
            {
                HtmlTableRow r = new HtmlTableRow();



                if (row % 2 == 1)// 设置行的背景色
                    r.BgColor = "Gainsboro";
                row++;
                for (int i = 0; i < numcells; i++)
                {
                    HtmlTableCell c = new HtmlTableCell(); //创建单元格对象
                    c.Controls.Add(new LiteralControl("行： " + (j + 1).ToString() + ", 单元格： " + (i + 1).ToString()));
                    r.Cells.Add(c); //添加该单元格对象
                }



                r.Attributes.Add("onclick", "Ck(this," + j + ")");
                r.Attributes.Add("onmousemove", "Move(this)");
                r.Attributes.Add("ondblclick", "DbCK(me)");
                r.Attributes.Add("onmouseout", "Out(this)");


                LaborTable.Rows.Add(r);//添加行对
            }
        }
    }
}