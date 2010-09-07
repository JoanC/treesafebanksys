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
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    struct update_user_input
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
        char[] user_id;
        //只能改家庭住址,联系电话,电子邮件
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
        char[] new_addr;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 50)]
        char[] new_email;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 12)]
        char[] new_tel;
        public update_user_input(string _id, string _addr, string _email
            , string _tel) 
        {
            user_id = _id.PadRight(19, '\0').ToCharArray();
            new_addr = _addr.PadRight(64, '\0').ToCharArray();
            new_email = _email.PadRight(50, '\0').ToCharArray();
            new_tel = _tel.PadRight(12,'\0').ToCharArray();
        }
    };

    public partial class UserEditInfoPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            /*
             *  Response.Redirect("UserEditInfoPage.aspx?name=" + UserName.Text
                             + "&id=" + UserID.Text
                             + "&address=" + UserAddress.Text
                             + "&phone=" + UserPhone.Text
                             + "&email=" + UserEmail.Text);
             * */
            if (!this.IsPostBack)
            {
                UserName.Text = Request.QueryString["name"];
                UserID.Text = Request.QueryString["id"];
                UserAddress.Text = Request.QueryString["address"];
                UserPhone.Text = Request.QueryString["phone"];
                UserEmail.Text = Request.QueryString["email"];
                UserPassword.Text = Request.QueryString["password"];
            }

        }

        protected void ChangeUserInfoButton_Click(object sender, EventArgs e)
        {
            //读取更改信息
            string _new_addr = Chinese_Encode_Mgr.utf7_convert(UserAddress.Text);
            string _new_phone = Chinese_Encode_Mgr.utf7_convert(UserPhone.Text);
            string _new_email = Chinese_Encode_Mgr.utf7_convert(UserEmail.Text);
            string _new_id = new string(Account.Login.login_rlt.user_id);
            update_user_input _input
                = new update_user_input(_new_id
                    ,_new_addr,_new_email,_new_phone);
            web_net_client_mgr _net = new web_net_client_mgr();
            _net.send_command_data(17, _input);

            //返回用户信息页面
            Response.Redirect("UserInfoPage.aspx");

        }
    }
}