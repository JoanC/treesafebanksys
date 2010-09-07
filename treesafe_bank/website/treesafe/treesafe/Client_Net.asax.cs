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
using System.Threading;

namespace ClientNet
{
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
    public struct sys_err
    {
        public int type;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
        public char[] info;
        public sys_err(int _err_type, string _err_info)
        {
            this.type = _err_type;
            this.info = _err_info.PadRight(128, '\0').ToCharArray();
        }
       public sys_err(sys_err _err)
        {
            //this.type = _err.type;
            //this.info = new char[128];
            //Array.Copy(_err.info, this.info, 128);
            this = _err;
        }
    };

        class web_net_client_mgr
        {
            //成员变量
            //默认是private
            public int BufSize = 80;
            [Serializable] // 指示可序列化
            [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
            public struct sys_net_data
            {
                public int type;//命令类型
                public int len;//命令长度
                [MarshalAs(UnmanagedType.ByValArray, SizeConst = 3048)]
                public char[] data;//命令中的数据
                public sys_net_data(char[] _data)
                {
                    this.type = 0;
                    this.len = 0;
                    this.data = new char[3048];
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
           // TcpClient m_client;//虚拟客户端
            Socket m_net_stream;//网络流



            public web_net_client_mgr(string _ip, int _server_port)
            {
                m_config = new net_config(_ip, _server_port);
            }

            public web_net_client_mgr() {
                StreamReader sr = new StreamReader(AppDomain.CurrentDomain.BaseDirectory + "\\Ipconfig.txt");
                string IpConfigxt = sr.ReadLine();
                string[] IpConfig = IpConfigxt.Split(':');
                int ip_port = Convert.ToInt32(IpConfig[1]);
                m_config = new net_config(IpConfig[0],ip_port);
                sr.Close();
            }

            public void config_client(string _server_ip, int _server_port)
            {
                //对客户端进行配置
                this.m_config.m_server_ip = _server_ip;
                this.m_config.m_port_num = _server_port;
            }

            private void connect_server()
            {
                //Thread.Sleep(1500);
               // this.m_client = new TcpClient(this.m_config.m_server_ip, this.m_config.m_port_num);
                this.m_net_stream = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                 for (int i = 0; i != 3; i++)
                {
                    try
                    {
                        this.m_net_stream.Connect(m_config.m_server_ip, m_config.m_port_num);
                    }
                    catch (Exception)
                    {

                    }
                    if (m_net_stream.Connected)
                        break;
                    Thread.Sleep(1000);
                }

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

            public object BytesToStruct(byte[] bytes, Type type)
            {
            //得到结构的大小
            int size = Marshal.SizeOf(type);
            //byte数组长度小于结构的大小
            if (size > bytes.Length)
            {
                //返回空
                return null;
            }
            //分配结构大小的内存空间
            IntPtr structPtr = Marshal.AllocHGlobal(size);
            //将byte数组拷到分配好的内存空间
            Marshal.Copy(bytes, 0, structPtr, size);
            //将内存空间转换为目标结构
            object obj = Marshal.PtrToStructure(structPtr, type);
            //释放内存空间
            Marshal.FreeHGlobal(structPtr);
            //返回结构
            return obj;
           }

            public static int bytesToInt(byte[] bytes)
            {
                int addr = bytes[0] & 0xFF;
                addr |= ((bytes[1] << 8) & 0xFF00);
                addr |= ((bytes[2] << 16) & 0xFF0000);
                return addr;
            }

            public void send_command_data(int _cmd_type, object _obj_data)
            {
                //连接服务器
                 this.connect_server();
                //数据
                //将结构体(对象)数据序列化
                 if (!m_net_stream.Connected)
                     return;
                byte[] _send_msg = this.StructToBytes(_obj_data);
                //将byte转化为char[]
                char[] _send_temp_string = Encoding.ASCII.GetChars(_send_msg);
                sys_net_data _send = new sys_net_data(_send_temp_string);
                //命令类型
                _send.type = _cmd_type;
                //命令信息长度
                _send.len = Marshal.SizeOf(_obj_data);

             	if(_send.len <= BufSize)
	            {
		          byte[] dataLen = Encoding.UTF8.GetBytes("01");
                  //包个数
                  this.m_net_stream.Send(dataLen, 0, dataLen.Length,SocketFlags.None );
                  //网络数据
                  this.m_net_stream.Send(StructToBytes(_send), 0, Marshal.SizeOf(_send),SocketFlags.None);
                  //关闭连接
	            }
	            else
	            {
                  byte[] dataLen = Encoding.UTF8.GetBytes("99");
                  byte[] dataSend = StructToBytes(_send);
                  int iCount = Marshal.SizeOf(_send) / BufSize + 1;
                  int iLastPackageSize = Marshal.SizeOf(_send) - BufSize * (iCount - 1);

                  string _num;
                  if (iCount > 10) _num = "" + iCount;
                  else _num = "0" + iCount;
                  dataLen = Encoding.UTF8.GetBytes(_num);

		          this.m_net_stream.Send(dataLen,0,dataLen.Length,SocketFlags.None);
		          for(int i =0;i < iCount;i++)
		          {
                      if (i == iCount - 1) {
                          this.m_net_stream.Send(dataSend,i*BufSize,iLastPackageSize,SocketFlags.None);
                      }
                      else this.m_net_stream.Send(dataSend,i * BufSize,BufSize,SocketFlags.None);
      	          }
	            }  
            }
               public object recevie_data(Type _obj_type)
               {
                    int iCount = 99;
                    byte[] cCount = System.BitConverter.GetBytes(iCount);
                   
                   this.m_net_stream.Receive(cCount, 0, cCount.Length, SocketFlags.None);
  
                   
                   char[] _temp_num = Encoding.ASCII.GetChars(cCount);
                   string _num_str = new string(_temp_num);
                   iCount = Convert.ToInt32(_num_str);

                   	byte[] buffer = new byte[iCount * BufSize];
                    int iRltLen = 0;
                    for(int i=0; i!=iCount; i++)
                    {
                            iRltLen += this.m_net_stream.Receive(buffer, iRltLen, BufSize, SocketFlags.None);

	                }
                    //关闭连接1
                    this.m_net_stream.Send(Encoding.UTF8.GetBytes("OK"), 0, 2, SocketFlags.None);
                    this.m_net_stream.Close();
                    object _obj_data = BytesToStruct(buffer,_obj_type);
                    return _obj_data;
               }
              
    }
}
