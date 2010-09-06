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


namespace treesafe.Admintrators
{
    /*删除数据*/
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按1字节对齐
    public struct delete_employee_input
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
        char[] employee_id;//身份证号码
        public delete_employee_input(string _id)
        {
            employee_id=  _id.PadRight(19, '\0').ToCharArray();
        }
    };

//结果信息
//其实就是一个是否删除成功的标记
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按0字节对齐
    public struct delete_employee_info
    {
        bool is_succ;//是否删除成功
        sys_err err_info;//错误信息
        public delete_employee_info(bool _is_succ)
        {
            is_succ = _is_succ;
            err_info = new sys_err(0,"");
        }
    };

    /*更改数据*/
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    public struct update_employee_input{
    [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
	char[] card_id;//原号码信息
	public admin_employ_info new_info;//新输入的信息
    public update_employee_input(string _id)
    {
        card_id = _id.PadRight(19,'\0').ToCharArray();
        new_info = new admin_employ_info(0,0,0,"","","","","","");
    }
};

    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    public struct update_employee_info
    {
        sys_err err_info;//错误信息
        public update_employee_info(string _pad)
        {
            err_info = new sys_err(0, "");
        }
    };

    public partial class AdmintratorLaborSelectPage : System.Web.UI.Page
    {
        public static delete_employee_input _input_delete;
        public static update_employee_input _input_update;

        protected void Page_Load(object sender, EventArgs e)
        {
            //c=此处获得了该雇员的工号
            LaborID.Text = Request.QueryString["id"];
            //在页面上方显示当前雇员id
            LabelName.Text = "当前雇员ID：" + LaborID.Text;

            _input_delete = new delete_employee_input(LaborID.Text);
            _input_update = new update_employee_input(LaborID.Text);
            //在此调用改用户的其他信息资料

        }

        protected void DeleteButton_Click(object sender, EventArgs e)
        {
            //在此调用从数据库删除该雇员信息的函数
            /////////////////////////////////
            //以下代码尚未测试
            web_net_client_mgr _net = new web_net_client_mgr();
            _net.send_command_data(4, _input_delete);
            /////////////////////////////////

            //刷新父页面,关闭该窗口并返回主界面
           
            Response.Write("<script language='javascript'>window.opener.location.reload()</script>");
            Response.Write("<script language='javascript'>window.close();</script>");
        }

        protected void EditLaborButton_Click(object sender, EventArgs e)
        {
            //在此调用从数据库更改该雇员信息的函数
            /////////////////////////////////////
            //以下代码尚未测试
            //更新信息
            web_net_client_mgr _net = new web_net_client_mgr();
            _net.send_command_data(16,_input_update);

            //刷新父页面,关闭该窗口并返回主界面

            Response.Write("<script language='javascript'>window.opener.location.reload()</script>");
            Response.Write("<script language='javascript'>window.close();</script>");
        }
    }
}