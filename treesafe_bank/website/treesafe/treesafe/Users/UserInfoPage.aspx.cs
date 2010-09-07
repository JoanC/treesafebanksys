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

namespace treesafe.Users
{
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
    struct query_user_one_info_input
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
        char[] user_id;//用户的证件号码
        public query_user_one_info_input(string _id)
        {
            user_id = _id.PadRight(19, '\0').ToCharArray();
        }
    };

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
    struct query_user_one_info_info
    {
        user_query_info user_info;
        sys_err err_info;//错误信息
        public query_user_one_info_info(user_query_info _info)
        {
            err_info = new sys_err(0,"");
            user_info = new user_query_info("","",0,0,"","");
        }
    };

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
    public struct user_query_info
    {
        public int user_gender;//0男,1女
        public int user_age;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
        public char[] user_name;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
        public char[] user_card_id;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 12)]
        public char[] user_tel;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
        public char[] user_addr;
        public user_query_info(string _name,string _id,int _gender,int _age
            ,string _tel,string _addr)
        {
            this.user_name = _name.PadRight(19, '\0').ToCharArray();
            this.user_card_id = _id.PadRight(19, '\0').ToCharArray();
            this.user_gender = _gender;
            this.user_age = _age;
            this.user_tel = _tel.PadRight(12, '\0').ToCharArray();
            this.user_addr = _addr.PadRight(64, '\0').ToCharArray();
        }
    };
    public partial class UserInfoPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            //显示数据从这里调
            if (Session["userright"].ToString() != "0")
            {
            //    Server.Transfer("~/WrongPage.aspx", true);
            }


        }

        protected void ChangeUserInfoButton_Click(object sender, EventArgs e)
        {
            //打开更改用户联系信息页面
            //传参打开
            Response.Redirect("UserEditInfoPage.aspx?name=" + UserName.Text
                             + "&password="+UserPassword.Text
                             + "&id=" + UserID.Text
                             + "&address=" + UserAddress.Text
                             + "&phone=" + UserPhone.Text
                             + "&email=" + UserEmail.Text);
        }

        protected void ChangePasswordButton_Click(object sender, EventArgs e)
        {
            //打开更改用户登录密码页面
            //
            Session["currentpassword"] = UserPassword.Text.ToString();
            //传参打开
            Response.Redirect("~/ChangePassword.aspx?name=" + UserName.Text);
        }
    }
}