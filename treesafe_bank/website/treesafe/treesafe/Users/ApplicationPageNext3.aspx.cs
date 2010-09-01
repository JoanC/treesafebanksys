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
using ClientNet;
using Chinese_Encode;

namespace treesafe.Users
{

    public partial class ApplicationPageNext3 : System.Web.UI.Page
    {
        //用户信息结构体
        [Serializable] // 指示可序列化
        [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按0字节对齐
        struct apply_custmor_info
        {
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 11)]
            char[] app_id;//申请编号
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 51)]
            char[] cust_name;//申请人姓名
            int cust_gender;//性别
            int cust_age;//年龄
            int cust_card_type;//卡的类型
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
            char[] cust_card_id;//卡号
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 11)]
            char[] cust_tel;//电话号码
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 11)]
            char[] cust_other_tel;//其他联系电话
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 51)]
            char[] cust_addr;//家庭地址
            int cust_edu_degree;//受教育情况
            public apply_custmor_info(int _gender, int _age
                , int _card_type, int _edu, string _name
                , string _card_id, string _tel, string _other_tel,string _addr)
            {
                this.app_id = "".PadRight(11, '\0').ToCharArray();
                this.cust_age = _age;
                this.cust_card_id = _card_id.PadRight(19, '\0').ToCharArray();
                this.cust_card_type = _card_type;
                this.cust_edu_degree = _edu;
                this.cust_gender = _gender;
                this.cust_name = _name.PadRight(51, '\0').ToCharArray();
                this.cust_other_tel = _other_tel.PadRight(11, '\0').ToCharArray();
                this.cust_tel = _tel.PadRight(11, '\0').ToCharArray();
                this.cust_addr = _addr.PadRight(51, '\0').ToCharArray();
            }
        };

        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["userright"].ToString() != "0")
            {
                //Server.Transfer("~/WrongPage.aspx", true);
            }

        }

        protected void CreateApplicationButton_Click(object sender, EventArgs e)
        {
            //将信息存入数据库。。。
            //使用方法同Register
            //（此处所使用方法和控件基本一致）



            //读取完成信息后，将结束申请，并跳转回到用户主页。
            Server.Transfer("~/Users/UserFinishApplicationPage.aspx", true);
        }
    }
}