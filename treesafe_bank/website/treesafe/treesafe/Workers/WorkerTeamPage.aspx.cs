using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using treesafe;

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
    /*所有分组的信息集合*/
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
    public struct query_group_input
    {
        //空
    };

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
    public struct query_group_info
    {
        public int group_num;
        sys_err err_info;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 25)]
        public group_info[] group;//分组的信息
    };

    public partial class WorkerTeamPage : System.Web.UI.Page
    {

        static public query_group_info m_groups;

        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["userright"].ToString() != "1")
            {
           //     Server.Transfer("~/WrongPage.aspx", true);
            }

            //读取分组数据
            query_group_input _input = new query_group_input();
            web_net_client_mgr _net = new web_net_client_mgr();
            _net.send_command_data(20,_input);
            m_groups = (query_group_info)_net.recevie_data(m_groups.GetType());

            //读取联保小组数据
            GetLaborInfo();
        }
        protected void GetLaborInfo()
        {
            int row = 0;
            // 获得联保小组列表的项数（即现有联保小组数量）
            int numrows = m_groups.group_num;
            //列表宽度，共8项内容
            int numcells = 8;
            for (int j = 0; j < numrows; j++)
            {
                HtmlTableRow r = new HtmlTableRow();



                if (row % 2 == 1)// 设置行的背景色
                    r.BgColor = "Gainsboro";
                row++;
                for (int i = 0; i < numcells; i++)
                {
                    HtmlTableCell c = new HtmlTableCell(); //创建单元格对象

                    switch (i)
                    {
                        case 0: c.Controls.Add(new LiteralControl(new string(m_groups.group[j].group_id))); break;
                        case 1: c.Controls.Add(new LiteralControl(new string(m_groups.group[j].mem[0]._id))); break;
                        case 2: c.Controls.Add(new LiteralControl(new string(m_groups.group[j].mem[1]._id))); break;
                        case 3: c.Controls.Add(new LiteralControl(new string(m_groups.group[j].mem[2]._id))); break;
                        case 4: c.Controls.Add(new LiteralControl(new string(m_groups.group[j].mem[3]._id))); break;
                        case 5: c.Controls.Add(new LiteralControl(new string(m_groups.group[j].mem[4]._id))); break;
                        case 6: c.Controls.Add(new LiteralControl(new string(m_groups.group[j].mem[5]._id))); break;
                        case 7: c.Controls.Add(new LiteralControl("暂不支持")); break;
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

        protected void AddTeamButton_Click(object sender, EventArgs e)
        {
            //增加联保小组界面
            Response.Redirect("WorkerNewTeamPage.aspx");
        }
        
        //查询分组的信息

    }
}