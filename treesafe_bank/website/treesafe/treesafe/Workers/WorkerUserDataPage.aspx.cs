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
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
    public struct user_query_array_info
    {
        public int user_num;
        //[MarshalAs(UnmanagedType.ByValArray, SizeConst = 1 * 124)]
        public byte[] user_array;
        public user_query_array_info(int _num)
        {
            user_num = _num;
            user_array = new byte[_num * 124];
        }
    };

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
    public struct user_query_arr_info
    {
        //public char[] info;
        public int _num;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 30)]
        public user_query_info[] _info;
        public user_query_arr_info(string _info)
        {
            _num = 0;
            this._info = new user_query_info[30];
            // info = _info.ToCharArray();
        }
    };//结果信息


    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
    struct user_query_arr_input { };

    public partial class WorkerUserDataPage : System.Web.UI.Page
    {
        public static user_query_arr_info _rlt;
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["userright"].ToString() != "1")
            {
                //    Server.Transfer("~/WrongPage.aspx", true);
            }

            _rlt = GetUserInfoBuff();
            //读取农户数据3
            GetLaborInfo(_rlt);
        }

        protected user_query_arr_info GetUserInfoBuff()
        {
            /*发送指令*/
            web_net_client_mgr _net = new web_net_client_mgr();
            user_query_arr_input _input = new user_query_arr_input();
            _net.send_command_data(9, _input);
            user_query_arr_info _info = new user_query_arr_info("");
            _info = (user_query_arr_info)_net.recevie_data(_info.GetType());
            return _info;
        }

        protected void GetLaborInfo(user_query_arr_info _rlt)
        {
            int row = 0;
            // 获得农户列表的项数（即*成功*提交申请表并*通过审核*的总人数）
            int numrows = _rlt._num;
            //列表宽度，共8项内容
            int numcells = 6;
            for (int j = 0; j < numrows; j++)
            {
                HtmlTableRow r = new HtmlTableRow();

                // if (row % 2 == 1)// 设置行的背景色
                //     r.BgColor = "Gainsboro";
                user_query_info _person = _rlt._info[j];

                row++;
                for (int i = 0; i < numcells; i++)
                {
                    HtmlTableCell c = new HtmlTableCell(); //创建单元格对象
                    //c.Controls.Add(new LiteralControl("行： " + (j + 1).ToString() + ", 单元格： " + (i + 1).ToString()));
                    string _gender = _person.user_gender == 0 ? "男" : "女";
                    string _age = "" + _person.user_age;
                    switch (i)
                    {
                        case 0: c.Controls.Add(new LiteralControl(new string(_person.user_name))); break;
                        case 1: c.Controls.Add(new LiteralControl(new string(_person.user_card_id))); break;
                        case 2: c.Controls.Add(new LiteralControl(_gender)); break;
                        case 3: c.Controls.Add(new LiteralControl(_age)); break;
                        case 4: c.Controls.Add(new LiteralControl(new string(_person.user_tel))); break;
                        case 5: c.Controls.Add(new LiteralControl(new string(_person.user_addr))); break;
                    }

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