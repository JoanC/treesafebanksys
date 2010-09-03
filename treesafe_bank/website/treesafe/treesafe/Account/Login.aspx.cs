﻿using System;
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


namespace treesafe.Account
{

    public partial class Login : System.Web.UI.Page
    {
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
        [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
        //一次登陆过程的信息记载
        public struct login_info
        {
            //用户权限
            public int compe; //权限
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
            public char[] user_id;		//用户id
            public sys_err login_err;		    //错误信息
            public login_info(int _compe , string _id , sys_err _err) {
                this.compe = _compe;
                this.user_id = _id.PadRight(19, '\0').ToCharArray();
                login_err = new sys_err(_err);
            }
        };

       public  static sys_err _err = new sys_err(0, "");
       public static login_info login_rlt = new login_info(-1, "",_err);

        protected void Page_Load(object sender, EventArgs e)
        {
            RegisterHyperLink.NavigateUrl = "Register.aspx?ReturnUrl=" + HttpUtility.UrlEncode(Request.QueryString["ReturnUrl"]);

            //在这里调用函数~判断用户权限~并决定用户进入的界面
            //在此处传值
            int destinationPage = login_rlt.compe;


            //0: 进入用户界面（农民）
            //1：进入操作员界面（前台工作人员）
            //2: 进入审核员界面
            //3：进入管理员权限（评定权值设定，人员调动）

            switch (destinationPage)
            {
                case 0:
                    LoginUser.DestinationPageUrl = String.Format("~/Users/UserRootPage.aspx?{0}", Request.QueryString.ToString());
                    Session["userright"] = "0";
                    break;
                case 1:
                    LoginUser.DestinationPageUrl = String.Format("~/Workers/WorkerRootPage.aspx?{0}", Request.QueryString.ToString());
                    Session["userright"] = "1";
                    break;
                case 2:
                    LoginUser.DestinationPageUrl = String.Format("~/Auditors/AuditorRootPage.aspx?{0}", Request.QueryString.ToString());
                    Session["userright"] = "2";
                    break;
                case 3:
                    LoginUser.DestinationPageUrl = String.Format("~/Admintrators/AdmintratorRootPage.aspx?{0}", Request.QueryString.ToString());
                    Session["userright"] = "3";
                    break;
                default:
                    Console.WriteLine("Default");
                    break;
            }
            //一次登陆结束后，将结果信息还原
            login_rlt.compe = -1;
            login_rlt.login_err.type = 0;
            login_rlt.login_err.info = "".ToCharArray();
            login_rlt.user_id = "".ToCharArray();
        }

        public void send_to_server(string _user_name, string _pwd)
        {
            /*用户姓名,中文转码*/
            _user_name = Chinese_Encode_Mgr.utf7_convert(_user_name);
            /*准备发送信息*/
            login_check_info _send_info = new login_check_info(_user_name, _pwd);
            web_net_client_mgr _net = new web_net_client_mgr();
            try
            {
                _net.send_command_data(0, _send_info);
            }
            catch (Exception)
            {
                WrongPage.wrong_msg = "与服务器连接失败!向服务器发送登录信息时失败！请检查网路问题并请重新登陆";
               // Server.Transfer("~/WrongPage.aspx", true);
            }
            try
            {
                login_rlt = (login_info)_net.recevie_data(login_rlt.GetType());
            }
            catch (Exception)
            {
                WrongPage.wrong_msg = "与服务器连接失败!从服务器接受信息时失败！请检查网路问题并请重新登陆";
                //Server.Transfer("~/WrongPage.aspx", true);
            }
            /*察看是否有错误信息*/
            if (login_rlt.login_err.type != 0)
            {
                WrongPage.wrong_msg = "用户名或密码错误,请注册或是重新登陆";
                //Server.Transfer("~/WrongPage.aspx", true);//跳转到错误页面
            }
            login_jump();
        }

        public void login_jump()
        {
            //0: 进入用户界面（农民）
            //1：进入操作员界面（前台工作人员）
            //2: 进入审核员界面
            //3：进入管理员权限（评定权值设定，人员调动）
            switch (login_rlt.compe)
            {
                case 0:
                    LoginUser.DestinationPageUrl = String.Format("~/Users/UserRootPage.aspx?{0}", Request.QueryString.ToString());
                    Session["userright"] = "0";
                    break;
                case 1:
                    LoginUser.DestinationPageUrl = String.Format("~/Workers/WorkerRootPage.aspx?{0}", Request.QueryString.ToString());
                    Session["userright"] = "1";
                    break;
                case 2:
                    LoginUser.DestinationPageUrl = String.Format("~/Auditors/AuditorRootPage.aspx?{0}", Request.QueryString.ToString());
                    Session["userright"] = "2";
                    break;
                case 3:
                    LoginUser.DestinationPageUrl = String.Format("~/Admintrators/AdmintratorRootPage.aspx?{0}", Request.QueryString.ToString());
                    Session["userright"] = "3";
                    break;
                default:
                    Console.WriteLine("Default");
                    break;
            }
        }
    }
}
