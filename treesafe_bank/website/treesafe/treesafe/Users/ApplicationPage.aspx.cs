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
    public partial class ApplicationPage : System.Web.UI.Page
    {

        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["userright"].ToString() != "0")
            {
              //  Server.Transfer("~/WrongPage.aspx", true);
            }

        }
         // 定义申请处理中的全局变量
        public static int apply_cust_gender;
        public static int apply_cust_age;
        public static int apply_cust_card_type;
        public static int apply_cust_edu;
        public static int apply_cust_house_type;
        public static string apply_cust_name;
        public static string apply_cust_id;
        public static string apply_cust_tel;
        public static string apply_cust_other_tel;
        public static string apply_cust_addr;
        public static string apply_cust_zip;

        protected void CreateApplicationButton_Click(object sender, EventArgs e)
        {
            //将信息存入数据库。。。
            //使用方法同Register
            //（此处所使用方法和控件基本一致）

            //填充全局变量
            apply_cust_name = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationName.Text);//姓名
            apply_cust_age = int.Parse(ApplicationAge.Text);//年龄
            apply_cust_gender = int.Parse(ApplicationSex.Text);//性别
            apply_cust_card_type = int.Parse(ApplicationIDType.Text);//证件类型
            apply_cust_id = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationIDNumber.Text);//证件号码
            //家庭住址
            apply_cust_addr = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationAddress.Text);
            //邮政编码
            apply_cust_zip = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationPostCode.Text);
            //住宅权属
            apply_cust_house_type = int.Parse(ApplicationHouseType.Text);
            //电话
            apply_cust_tel = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationPhoneNumber.Text);
            //其他电话
            apply_cust_other_tel = Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationPhoneNumber1.Text);
            //受教育情况
            apply_cust_edu = int.Parse(ApplicationEducation.Text);

            //读取完成信息后，跳转到下一个页面继续申请表的填写
            Server.Transfer("~/Users/ApplicationPageNext1.aspx", true);
        }
    }
}