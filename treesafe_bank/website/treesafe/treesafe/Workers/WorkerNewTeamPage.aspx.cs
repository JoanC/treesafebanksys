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

namespace treesafe.Workers
{
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
    public struct group_mem_info
    {
        //组员信息
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
        public char[] _id;
    };
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
    public struct group_info
    {
        //组信息
        //组的信息由系统自动生成
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 11)]
        public char[] group_id;
        public int length;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 6)]
        public group_mem_info[] mem;
    };

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
    struct add_group_input
    {
        public group_info group;
    };



    public partial class WorkerNewTeamPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void NewTeamButton_Click(object sender, EventArgs e)
        {
            //读取数据
            add_group_input _input = new add_group_input();
            _input.group.group_id = "".PadRight(11, '\0').ToCharArray();

            _input.group.mem
                = new group_mem_info[6];
            _input.group.mem[0]._id =
                TeamLeader.Text.PadRight(19, '\0').ToCharArray();
            _input.group.mem[1]._id =
                TeamMember1.Text.PadRight(19, '\0').ToCharArray();
            _input.group.mem[2]._id =
                TeamMember2.Text.PadRight(19, '\0').ToCharArray();
            _input.group.mem[3]._id =
                TeamMember3.Text.PadRight(19, '\0').ToCharArray();
            _input.group.mem[4]._id =
                TeamMember4.Text.PadRight(19, '\0').ToCharArray();
            _input.group.mem[5]._id =
                TeamMember5.Text.PadRight(19, '\0').ToCharArray();
            //count the num:
            _input.group.length = 0;
            for (int i = 0; i < 6; ++i)
            {
                string _new = new string(_input.group.mem[i]._id);
                if (_new != "".PadRight(19, '\0'))
                {
                    ++_input.group.length;
                }
                else
                {
                    _input.group.mem[i]._id = "null".PadRight(19, '\0').ToCharArray();
                }
            }
            //发送信息
            web_net_client_mgr _net = new web_net_client_mgr();
            _net.send_command_data(19, _input);
            //跳转到联保小组界面
            Response.Redirect("WorkerTeamPage.aspx");
        }
    }
}