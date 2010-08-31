using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;


using System.Runtime.InteropServices;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization;
using ClientNet;
using System.Text;

namespace treesafe.Account
{
    public partial class Register : System.Web.UI.Page
    {

        protected void Page_Load(object sender, EventArgs e)
        {
         //   RegisterUser.ContinueDestinationPageUrl = Request.QueryString["ReturnUrl"];
        }

        /*与注册有关的结构体的声明*/
        [Serializable] // 指示可序列化
        [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
        public struct reg_basic_info
        {
            //性别
            public int reg_gender;
            //年龄
            public int reg_age;
            //身证号
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)] // 声明一个字符数组，大小为11
            public char[] reg_id;
            //用户密码
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
            public char[] reg_pwd;
            //用户真实姓名
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 51)]
            public char[] reg_basic_user_name;
            //电话号码
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 12)]
            public char[] reg_phone_num;
            //家庭地址
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
            public char[] reg_home_addr;
            public reg_basic_info(int _gender
                , int _age, string _id, string _pwd, string _name, string _tel, string _addr)
            {
                reg_age = _age;
                reg_gender = _gender;
                reg_id = _id.PadRight(19, '\0').ToCharArray();
                reg_pwd = _pwd.PadRight(16, '\0').ToCharArray();
                reg_basic_user_name = _name.PadRight(51, '\0').ToCharArray();
                reg_phone_num = _tel.PadRight(12, '\0').ToCharArray();
                reg_home_addr = _addr.PadRight(64, '\0').ToCharArray();
            }
        };

        [Serializable] // 指示可序列化
        [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
        struct reg_input_info
        {
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
            public char[] email_addr;
            public int is_pwd_corr;
            public reg_basic_info _basic_info;
            public reg_input_info(string _email, reg_basic_info _info)
            {
                email_addr = _email.PadRight(64, '\0').ToCharArray();
                _basic_info = _info;
                is_pwd_corr = 1;
            }
        }

        protected void RegisterUser_CreatedUser(object sender, EventArgs e)
        {
            
        }

        protected void CreateUserButton_Click(object sender, EventArgs e)
        {
            FormsAuthentication.SetAuthCookie(UserName.Text, false /* createPersistentCookie */);

            //创建网络接口
            web_net_client_mgr reg_net = new web_net_client_mgr();

            //所有读数据的代码都写到这里
            //这里是新的创建用户确认按钮提交的地方
            string _id = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(UserId.Text);
            string _pwd = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(Password.Text);
            string _name = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(UserName.Text);
            string _tel = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(PhoneNumber.Text);
            string _addr = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(HomeAddress.Text);
            string _email = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(Email.Text);
            
            reg_basic_info _info = new reg_basic_info(int.Parse(UserSex.Text),0, _id, _pwd, _name, _tel, _addr);
            reg_input_info _send = new reg_input_info(_email, _info);
            reg_net.send_command_data(1, _send);
            Response.Redirect("Login.aspx");

        }

    }
}
