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
using treesafe.Admintrators;

namespace treesafe.Admintrotors
{
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按0字节对齐
    public struct query_employee_array_input { };

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按0字节对齐
    public struct query_employee_array_info{
	public int num;//个数
    [MarshalAs(UnmanagedType.ByValArray, SizeConst = 15)]
	public admin_employ_info[] employee_arr;
    public query_employee_array_info(int _num) 
    {
        num = _num;
        employee_arr = new admin_employ_info[15];
    }
};

    public partial class AdmintratorLaborManagementPage : System.Web.UI.Page
    {
        public static query_employee_array_info _rlt
            =  new query_employee_array_info(0);

        protected void Page_Load(object sender, EventArgs e)
        {
            //判断权限
            if (Session["userright"].ToString() != "3")
            {
                //Server.Transfer("~/WrongPage.aspx", true);
            }

            //
            ButtonAddWorker.Attributes.Add("onclick","ShowDialog('AdmintratorNewLaborPage.aspx')");


            ////////////////////////////////////////
            /////////////
            
            web_net_client_mgr _net = new web_net_client_mgr();
            query_employee_array_input _input = new query_employee_array_input();
            _net.send_command_data(15,_input);
            _rlt = (query_employee_array_info)_net.recevie_data(_rlt.GetType());

            
            //读取雇员数据
            GetLaborInfo();

        }

        protected void GetLaborInfo()
        {
            int row = 0;
            // 获得雇员列表的项数（即雇员总人数）
            int numrows = _rlt.num;
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
                  //  c.Controls.Add(new LiteralControl("行： " + (j + 1).ToString() + ", 单元格： " + (i + 1).ToString()));
                    string _work_type = _rlt.employee_arr[j].empl_type == 0 ? "操作员" : "审核员";
                    string _work_gender = _rlt.employee_arr[j].empl_gender == 0 ? "男" : "女";
                    switch (i)
                    {
                        case 0: c.Controls.Add(new LiteralControl(new string(_rlt.employee_arr[j].empl_work_id))); break;
                        case 1: c.Controls.Add(new LiteralControl(_work_type)); break;
                        case 2:  c.Controls.Add(new LiteralControl(new string(_rlt.employee_arr[j].empl_name))); break;
                        case 3:  c.Controls.Add(new LiteralControl(new string(_rlt.employee_arr[j].empl_id) )); break;
                        case 4: c.Controls.Add(new LiteralControl(_work_gender)); break;
                        case 5:  c.Controls.Add(new LiteralControl(new string(_rlt.employee_arr[j].empl_tel) )); break;
                        case 6:  c.Controls.Add(new LiteralControl(new string(_rlt.employee_arr[j].empl_addr) )); break;
                        case 7: c.Controls.Add(new LiteralControl(new string(_rlt.employee_arr[j].empl_email))); break;
                    }
                    r.Cells.Add(c); //添加该单元格对象
                }

                

                r.Attributes.Add("onclick", "Ck(this,"+j+")");
                r.Attributes.Add("onmousemove", "Move(this)");
                r.Attributes.Add("ondblclick", "DbCK(me)");
                r.Attributes.Add("onmouseout", "Out(this)");


                LaborTable.Rows.Add(r);//添加行对

            }

        }
    }
}