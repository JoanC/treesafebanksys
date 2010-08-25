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

namespace treesafe.Account
{

    public partial class Login : System.Web.UI.Page
    {
        class web_net_client_mgr
        {
            //成员变量
            //默认是private
            [Serializable] // 指示可序列化
            [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
            public struct sys_net_data
            {
                public int type;//命令类型
                public int len;//命令长度
                [MarshalAs(UnmanagedType.ByValArray, SizeConst = 512)]
                public char[] data;//命令中的数据
                public sys_net_data(char[] _data)
                {
                    this.type = 0;
                    this.len = 0;
                    this.data = new char[512];
                    Array.Copy(_data, data, _data.Length);
                }
            };
            struct net_config
            {
                public int m_port_num;
                public string m_server_ip;
                public net_config(string _ip, int _port)
                {
                    m_port_num = _port;
                    m_server_ip = _ip;
                }
            };
            net_config m_config;//网络配置数据结构
            TcpClient m_client;//虚拟客户端
            NetworkStream m_net_stream;//网络流

            public web_net_client_mgr(string _ip, int _server_port)
            {
                m_config = new net_config(_ip, _server_port);
            }

            public void config_client(string _server_ip, int _server_port)
            {
                //对客户端进行配置
                this.m_config.m_server_ip = _server_ip;
                this.m_config.m_port_num = _server_port;
            }

            private void connect_server()
            {
                this.m_client = new TcpClient(this.m_config.m_server_ip, this.m_config.m_port_num);
                this.m_net_stream = this.m_client.GetStream();
            }

            private byte[] StructToBytes(object obj)
            {
                //得到结构体的大小
                int size = Marshal.SizeOf(obj);
                //创建byte数组
                byte[] bytes = new byte[size];
                //分配结构体大小的内存空间
                IntPtr structPtr = Marshal.AllocHGlobal(size);
                //将结构体拷到分配好的内存空间
                Marshal.StructureToPtr(obj, structPtr, false);
                //从内存空间拷到byte数组
                Marshal.Copy(structPtr, bytes, 0, size);
                //释放内存空间
                Marshal.FreeHGlobal(structPtr);
                //返回byte数组
                return bytes;
            }

            public void send_command_data(int _cmd_type, object _obj_data)
            {
                //连接服务器
                this.connect_server();
                //数据
                //将结构体(对象)数据序列化
                byte[] _send_msg = this.StructToBytes(_obj_data);
                //将byte转化为char[]
                char[] _send_temp_string = Encoding.ASCII.GetChars(_send_msg);
                sys_net_data _send = new sys_net_data(_send_temp_string);
                //命令类型
                _send.type = _cmd_type;
                //命令信息长度
                _send.len = Marshal.SizeOf(_obj_data);

                //???????????????????
                //包的个数??
                byte[] data = Encoding.UTF8.GetBytes("07");
                this.m_net_stream.Write(data, 0, data.Length);
                //将网络数据发出
                this.m_net_stream.Write(StructToBytes(_send), 0, Marshal.SizeOf(_send));
                //关闭连接
                this.m_client.Close();
            }
        };

        [Serializable] // 指示可序列化
        [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
        public struct login_check_info
        {
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)] // 声明一个字符数组，大小为11
            public char[] name;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
            public char[] pass;
            public bool is_vry_right;

            public login_check_info(string user, string pass) // 初始化
            {
                this.name = user.PadRight(19, '\0').ToCharArray();
                this.pass = pass.PadRight(16, '\0').ToCharArray();
                this.is_vry_right = true;
            }
        };

        protected void Page_Load(object sender, EventArgs e)
        {
            RegisterHyperLink.NavigateUrl = "Register.aspx?ReturnUrl=" + HttpUtility.UrlEncode(Request.QueryString["ReturnUrl"]);
           
            //在这里调用函数~判断用户权限~并决定用户进入的界面
            //在此处传值

            uint destinationPage = 0;

            //0: 进入用户界面（农民）
            //1：进入操作员界面（前台工作人员）
            //2: 进入审核员界面
            //3：进入管理员权限（评定权值设定，人员调动）

            switch (destinationPage)
            {
                case 0:
                    LoginUser.DestinationPageUrl = String.Format("~/UserRootPage.aspx?{0}", Request.QueryString.ToString());
                    break;
                case 1:
                    LoginUser.DestinationPageUrl = String.Format("~/WorkerRootPage.aspx?{0}", Request.QueryString.ToString());
                    break;
                case 2:
                    LoginUser.DestinationPageUrl = String.Format("~/AuditorRootPage.aspx?{0}", Request.QueryString.ToString());
                    break;
                case 3:
                    LoginUser.DestinationPageUrl = String.Format("~/AdmintratorRootPage.aspx?{0}", Request.QueryString.ToString());
                    break;
                default:
                    Console.WriteLine("Default");
                    break;
            }
        }

        public void send_to_server(string _user_name, string _pwd) {
            login_check_info _send_info = new login_check_info(_user_name, _pwd);
            web_net_client_mgr _net = new web_net_client_mgr("127.0.0.1", 4999);
            _net.send_command_data(0,_send_info);
        }

    }
}
