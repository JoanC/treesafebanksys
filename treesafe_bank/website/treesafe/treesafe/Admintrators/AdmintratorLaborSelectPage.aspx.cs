using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe.Admintrators
{
    public partial class AdmintratorLaborSelectPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            //c=此处获得了该雇员的工号
            LaborID.Text = Request.QueryString["id"];

            //在此调用改用户的其他信息资料
        }

        protected void DeleteButton_Click(object sender, EventArgs e)
        {
            //在此调用从数据库删除该雇员信息的函数


            //刷新父页面,关闭该窗口并返回主界面
           
            Response.Write("<script language='javascript'>window.opener.location.reload()</script>");
            Response.Write("<script language='javascript'>window.close();</script>");
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            //window.open(url, "", "Scrollbars=yes,Toolbar=no,Location=no,Direction=no,Resizeable=yes,   Width=" + iWidth + " ,Height=" + iHeight + ",top=" + iTop + ",left=" + iLeft)
            //"AdmintratorLaborSelectPage.aspx?id="+dataID

            //跳转到修改雇员信息界面
            Session["userright"] = LaborID.Text;
            Response.Redirect("AdmintratorEditLaborPage.aspx");
         //   window.location.href = "fieldDefine.do?method=findAllFieldDefineByTable&sysname= " + sys + "&tablename= " + encodeURIComponent(tab); 
            //"", "Scrollbars=yes,Toolbar=no,Location=no,Direction=no,Resizeable=yes,   Width=" + iWidth + " ,Height=" + iHeight + ",top=" + iTop + ",left=" + iLeft
           // Response.Write("<script language='javascript'>window.location='AdmintratorEditLaborPage.aspx'?id="+LaborID.Text+"</script>");
            //Response.Write("<script language='javascript'>window.open('AdmintratorEditLaborPage.aspx?id=" + LaborID.Text +"','',Scrollbars=yes,Toolbar=no,Location=no,Direction=no,Resizeable=yes</script>");

        }
    }
}