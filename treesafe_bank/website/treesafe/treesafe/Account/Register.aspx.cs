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

namespace treesafe.Account
{
    public partial class Register : System.Web.UI.Page
    {

        protected void Page_Load(object sender, EventArgs e)
        {
            RegisterUser.ContinueDestinationPageUrl = Request.QueryString["ReturnUrl"];
        }

        /*与注册有关的结构体的声明*/
        [Serializable] // 指示可序列化
        [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
        public struct reg_basic_info
        {
            //家庭住址
            //身份证号,18位
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
            public char[] reg_id;
            //REG_USER_ID reg_name[REG_MAX_USER_NAME];
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
            //性别
            public bool reg_gender;
            //年龄
            public int reg_age;
            //初始赋值函数
            public reg_basic_info(bool _gender , int _age
                ,string _id,string _pwd,string _name,string _tel,string _addr) {
                this.reg_gender =  true;
                this.reg_age = 0;
                this.reg_basic_user_name = _name.PadRight(51,'\0').ToCharArray();
                this.reg_home_addr = _addr.PadRight(64,'\0').ToCharArray();
                this.reg_id = _id.PadRight(19,'\0').ToCharArray();
                this.reg_phone_num = _tel.PadRight(12, '\0').ToCharArray();
                this.reg_pwd = _pwd.PadRight(16, '\0').ToCharArray();
            }
        };

        [Serializable] // 指示可序列化
        [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
        public struct reg_input_info 
        {
            //邮件地址
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
            public char[] reg_email_addr;
            //基本信息
            public reg_basic_info reg_basic;
            //密码是否正确
            public bool is_pwd_corr;
            /*初始化信息*/
            public reg_input_info(string _email,reg_basic_info _info) {
                this.is_pwd_corr = true;
                this.reg_email_addr = _email.PadRight(64, '\0').ToCharArray();
                this.reg_basic = _info;
            }
        };


        protected void RegisterUser_CreatedUser(object sender, EventArgs e)
        {
            //关于创建用户的函数在这里调
            //首先是检查数据
            //确认无误后，添加到数据库。
            //调用数据方法：类似于RegisterUser.UserName。可直接调用，具体名称欢迎参见.aspx。

            //以下添加代码由Jiraiya编写
            /*发送数据给服务器*/
            //创建网络接口
            web_net_client_mgr reg_net = new web_net_client_mgr();
            //读取输入的数据，并发送
            reg_basic_info _info = new reg_basic_info(false,18,"123456789123789"
                ,"1234567","haha","123456","江西");
            reg_input_info _send = new reg_input_info("bill002@yahoo.cn",_info);
            reg_net.send_command_data(1,_info);

            FormsAuthentication.SetAuthCookie(RegisterUser.UserName, false /* createPersistentCookie */);



            //下面的这段代码不要改，是界面显示用的。上面那句看不明白。。。。。。。。。不懂。。。。看着办吧。。
            string continueUrl = RegisterUser.ContinueDestinationPageUrl;
            if (String.IsNullOrEmpty(continueUrl))
            {
                continueUrl = "~/";
            }
            Response.Redirect(continueUrl);
        }

    }
}
