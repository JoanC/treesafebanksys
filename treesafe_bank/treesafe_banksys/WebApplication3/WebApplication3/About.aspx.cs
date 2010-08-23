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


namespace WebApplication3
{   
    class web_net_client_mgr { 
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
        struct net_config {
            public int m_port_num;
            public string m_server_ip;
            public net_config(string _ip , int _port) {
                m_port_num = _port;
                m_server_ip = _ip;
            }
        };
        net_config m_config;//网络配置数据结构
        TcpClient m_client;//虚拟客户端
        NetworkStream m_net_stream;//网络流

        public web_net_client_mgr(string _ip , int _server_port){
            m_config = new net_config(_ip,_server_port);
        }

        public void config_client(string _server_ip , int _server_port){
            //对客户端进行配置
            this.m_config.m_server_ip = _server_ip;
            this.m_config.m_port_num = _server_port;
        }

        private void connect_server() {
            this.m_client = new TcpClient(this.m_config.m_server_ip,this.m_config.m_port_num);
            this.m_net_stream = this.m_client.GetStream();
        }

        private byte[] StructToBytes(object obj) {
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

        public void send_command_data(int _cmd_type,object _obj_data) {
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

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
   struct reg_basic_info{
       //性别
      public bool reg_gender;
      //年龄
      public int reg_age;
     //身份证号,18位.加'\0',19
     [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
	public char[] reg_id;
	//用户密码,协议为16
     [MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
	public char[] reg_pwd;
      [MarshalAs(UnmanagedType.ByValArray, SizeConst = 51)]
	//用户真实姓名,协议为51
	public char[] reg_basic_user_name;
	//家庭住址,协议为64
    [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
	public char[] reg_home_addr;
    public reg_basic_info(string _id, string _pwd, string _name, string _addr, int _age, bool _gender) { 
        //初始化各成员变量
        this.reg_id = _id.PadRight(19,'\0').ToCharArray();
        this.reg_pwd = _pwd.PadRight(16,'\0').ToCharArray();
        this.reg_basic_user_name = _name.PadRight(51,'\0').ToCharArray();
        this.reg_home_addr = _addr.PadRight(64, '\0').ToCharArray();
        this.reg_age = _age;
        this.reg_gender = _gender;
    }
};

    struct reg_input_info{
	//用户注册所输入的相关信息
    //其它的附加信息
    [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
    public char[] email_addr;
	//输入基本信息
	public reg_basic_info basic_info;
	//密码两次验证是否正确
	public bool is_pwd_vry_crr;
};

    public partial class About : System.Web.UI.Page
    {
       

        protected void Page_Load(object sender, EventArgs e)
        {
             
        }
        protected void SaveNewPass()
        {
          //  reg_input_info _reg_test;
            //_reg_test.basic_info = new reg_basic_info("1234","1234","haha","here",10,true);
            //string _email = "bill002@yahoo.cn";
            //_reg_test.email_addr = _email.PadRight(64, '\0').ToCharArray();
            //_reg_test.is_pwd_vry_crr = false;
            web_net_client_mgr _test = new web_net_client_mgr("127.0.0.1",4999); 
            login_check_info login_input = new login_check_info("haha","KOKO");
            _test.send_command_data(0,login_input);
        }
        protected void Button1_Click(object sender, EventArgs e)
        {
            SaveNewPass();
        }
    }
}
