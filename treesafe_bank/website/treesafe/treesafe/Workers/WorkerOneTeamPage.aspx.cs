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

using treesafe.Users;
using treesafe.Workers;

using System.Web.UI.HtmlControls;

namespace treesafe.Workers
{
    public partial class WorkerOneTeamPage : System.Web.UI.Page
    {
        public user_query_info[] _info = new user_query_info[6];
        int m_len;
        protected void Page_Load(object sender, EventArgs e)
        {


            //一个个地读取数据
            int _chose = int.Parse(Request.QueryString["id"]);
            m_len = 0;

            for (int i = 0; i < 6; ++i)
            {
                //提取信息
                if (new string(WorkerTeamPage.m_groups.group[_chose].mem[i]._id) == "null".PadRight(19, '\0'))
                    continue;
                else {
                    ++m_len;
                }
                query_user_one_info_input _input = new query_user_one_info_input(
                    new string(WorkerTeamPage.m_groups.group[_chose].mem[i]._id));
                web_net_client_mgr _net = new web_net_client_mgr();
                query_user_one_info_info _rlt = new query_user_one_info_info((new sys_err(0, "")));
                _net.send_command_data(12, _input);
                _rlt = (query_user_one_info_info)_net.recevie_data(_rlt.GetType());
                _info[i] = _rlt.user_info;
            }

                //读取农户数据3
                GetLaborInfo();
        }

        protected void GetLaborInfo()
        {
            int row = 0;
            // 获得农户列表的项数（即*成功*提交申请表并*通过审核*的总人数）
            int numrows = m_len;
            //列表宽度，共7项内容
            int numcells = 7;
            for (int j = 0; j < numrows; j++)
            {
                HtmlTableRow r = new HtmlTableRow();



                if (row % 2 == 1)// 设置行的背景色
                    r.BgColor = "Gainsboro";
                row++;
                for (int i = 0; i < numcells; i++)
                {
                    HtmlTableCell c = new HtmlTableCell(); //创建单元格对象
                    switch (i) {
                        case 0: c.Controls.Add(new LiteralControl(("" + j))); break;
                        case 1: c.Controls.Add(new LiteralControl(new string(_info[j].user_name))); break;
                        case 2: c.Controls.Add(new LiteralControl(new string(_info[j].user_card_id))); break;
                        case 3: {
                            string _gender = _info[j].user_gender == 0 ? "男" : "女";
                            c.Controls.Add(new LiteralControl(_gender));
                        }break;
                        case 4: {
                            c.Controls.Add(new LiteralControl("" + _info[j].user_age));
                        }break;
                        case 5: {
                            c.Controls.Add(new LiteralControl(new string(_info[j].user_tel)));
                        } break;
                        case 6: {
                            c.Controls.Add(new LiteralControl(new string(_info[j].user_addr)));
                        }break;
                    };
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