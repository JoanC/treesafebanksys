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

namespace treesafe.Admintrators
{
    /*有关雇员信息的结构体*/
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
    public struct admin_employ_info
    {
        public int empl_type;//雇员的类型
        public int empl_age;//年龄
        public int empl_gender;//雇员性别

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
        public char[] empl_id;//雇员的证件号码
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 8)]
        public char[] empl_work_id;//雇员的工号
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 51)]
        public char[] empl_name;//雇员的姓名
        //地址
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 51)]
        public  char[] empl_addr;
        //电子邮件
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 51)]
        public char[] empl_email;
        //电话号码
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 11)]
        public char[] empl_tel;

        public admin_employ_info(int _type,int _gender,int _age
            ,string _id,string _work_id,string _name,string _addr,string _email,string _tel) 
        {
            this.empl_type = _type;
            this.empl_id = _id.PadRight(19, '\0').ToCharArray();
            this.empl_work_id = _work_id.PadRight(8, '\0').ToCharArray();
            this.empl_name = _name.PadRight(51,'\0').ToCharArray();
            this.empl_gender = _gender;
            this.empl_age = _age;
            this.empl_addr = _addr.PadRight(51, '\0').ToCharArray();
            this.empl_email = _email.PadRight(51, '\0').ToCharArray();
            this.empl_tel = _tel.PadRight(11, '\0').ToCharArray();
        }
    };

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    public struct admin_add_employee_input_info
    {
        public admin_employ_info _info;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 201)]
        public char[] _comment;
        public admin_add_employee_input_info(string _com , admin_employ_info _info)
        {
            this._info = _info;
            this._comment = _com.PadRight(201, '\0').ToCharArray();
        }
    }

    public partial class AdmintratorNewLaborPage : System.Web.UI.Page
    {

        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void NewLaborButton_Click(object sender, EventArgs e)
        {
            /*整理网络*/
            web_net_client_mgr _net_mgr = new web_net_client_mgr();
            
            /*整理UI的交互信息*/
            /*工号*/
            string _work_id = Chinese_Encode_Mgr.utf7_convert(LaborID.Text);
            /*雇员类型*/
            int _type = int.Parse(LaborType.Text);
            /*雇员姓名*/
            string _name = Chinese_Encode_Mgr.utf7_convert(LaborName.Text);
            /*雇员证件号码*/
            string _card_id = Chinese_Encode_Mgr.utf7_convert(LaborIDNumber.Text);
            /*雇员性别*/
            int _gender = int.Parse(LaborSex.Text);
            //雇员年龄
            int _age = int.Parse(LaborAge.Text);
            //雇员地址
            string _addr = Chinese_Encode_Mgr.utf7_convert(LaborAddress.Text);
            //雇员电子邮件
            string _emial = Chinese_Encode_Mgr.utf7_convert(LaborEmail.Text);
            //电话号码
            string _tel = Chinese_Encode_Mgr.utf7_convert(LaborPhoneNumber.Text);
            //注释信息
            string _comment = Chinese_Encode_Mgr.utf7_convert(LaborNotes.Text);

            /*生成发送信息*/
            admin_employ_info _info =
                new admin_employ_info(_type,_gender,_age
                    ,_card_id,_work_id,_name,_addr,_emial,_tel);
            admin_add_employee_input_info _send_info=
                new admin_add_employee_input_info(_comment,_info);
            _net_mgr.send_command_data(3,_send_info);



            //关闭窗口
            FinishNewLabor();
        }
        protected void FinishNewLabor()
        {
            //刷新父页面,关闭该窗口并返回主界面

            Response.Write("<script language='javascript'>window.opener.location.reload()</script>");
            Response.Write("<script language='javascript'>window.close();</script>");
        }
    }
}