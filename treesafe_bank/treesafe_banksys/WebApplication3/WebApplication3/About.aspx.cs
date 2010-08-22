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
     /*
        public static MemoryStream SerializeOject(object SOject)
        {
            MemoryStream memoryStream = new MemoryStream();
            IFormatter formatter = new BinaryFormatter();
            formatter.Serialize(memoryStream, SOject);
            memoryStream.Close();
            return memoryStream;
        }*/
    /*
        public byte[] SerializeObject(object pObj)
        {
            if (pObj == null)
                return null;
            System.IO.MemoryStream _memory = new System.IO.MemoryStream();
            BinaryFormatter formatter = new BinaryFormatter();
            formatter.Serialize(_memory, pObj);
            _memory.Position = 0;
            byte[] read = new byte[_memory.Length];
            _memory.Read(read, 0, read.Length);
            _memory.Close();
            return read;
        }

*/


    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    public struct sys_net_data
    {
        public int type;//命令类型
        public int len;//命令长度
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 80)]
        public char[] data;//命令中的数据
        public sys_net_data(char[] _data) {
            this.type = 0;
            this.len = 0;
            this.data = new char[80];
            Array.Copy(_data,data,_data.Length);
        }
    };

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    public struct login_check_info
    {
        /*
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 10)] // 声明一个字符数组，大小为11
        public char[] user_name;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 10)]
        public char[] input_pwd ;//密码
        public bool is_vry_right;//验证码是否正确

        public login_check_info(string _user , string pwd) { 
            user_name = _user.ToCharArray();
            input_pwd = pwd.ToCharArray();
            is_vry_right = false;
        }*/
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 18)] // 声明一个字符数组，大小为11
        public char[] name;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 50)]
        public char[] pass;
        public bool is_vry_right;

        public login_check_info(string user, string pass) // 初始化
        {
            this.name = user.PadRight(18, '\0').ToCharArray();
            this.pass = pass.PadRight(50, '\0').ToCharArray();
            this.is_vry_right = true;
        }
    };

    public partial class About : System.Web.UI.Page
    {
        /*
        public static byte[] StructToBytes(object structObj)
        {
            //得到结构体的大小
            int size = Marshal.SizeOf(structObj);
            //创建byte数组
            byte[] bytes = new byte[size];
            //分配结构体大小的内存空间
            IntPtr structPtr = Marshal.AllocHGlobal(size);
            //将结构体拷到分配好的内存空间
            Marshal.StructureToPtr(structObj, structPtr, false);
            //从内存空间拷到byte数组
            Marshal.Copy(structPtr, bytes, 0, size);
            //释放内存空间
            Marshal.FreeHGlobal(structPtr);
            //返回byte数组
            return bytes;
        }*/

        public byte[] StructToBytes(object obj)
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

        protected void Page_Load(object sender, EventArgs e)
        {
             
        }
        protected void SaveNewPass()
        {
            login_check_info login_input = new login_check_info("haha","KOKO");
            byte[] Message = StructToBytes(login_input); // 将结构转换成字节数组

            string _temp = "";
            for (int i = 0; i < Message.Length; ++i) {
                 _temp += Convert.ToString(Message[i]); 
            }

            char[] cChar = Encoding.ASCII.GetChars(Message);

            sys_net_data _test_send = new sys_net_data(cChar);
            
            _test_send.type = 0;
            _test_send.len = Message.Length;

            TcpClient client;
            NetworkStream netstream;
            string _serverip = "127.0.0.1";
            int _port = 4999;

            client = new TcpClient(_serverip, _port);
            netstream = client.GetStream();

            byte[] data = Encoding.UTF8.GetBytes("01");
            netstream.Write(data, 0, data.Length);
           // byte[] data2 = Encoding.UTF8.GetBytes();
           // int size = Marshal.SizeOf(send_data);
            netstream.Write(StructToBytes(_test_send), 0, Marshal.SizeOf(_test_send));
         //   _test.Serialize(netstream,input_info);

            client.Close();
        }
        protected void Button1_Click(object sender, EventArgs e)
        {
            SaveNewPass();
        }
    }
}
