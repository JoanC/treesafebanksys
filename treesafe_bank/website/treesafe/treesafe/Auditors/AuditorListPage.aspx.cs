using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace treesafe.Auditors
{
    public partial class AuditorListPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            //判断权限
            if (Session["userright"].ToString() != "2")
            {
             //   Server.Transfer("~/WrongPage.aspx", true);
            }

            //从服务器端读取农户的申请信息，并显示在对应页面控件上


        }

        protected void CheckBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        protected void CheckBox2_CheckedChanged(object sender, EventArgs e)
        {

        }

        protected void CheckBox3_CheckedChanged(object sender, EventArgs e)
        {

        }

        protected void CheckBox4_CheckedChanged(object sender, EventArgs e)
        {

        }

        protected void CommitApplicationButton_Click(object sender, EventArgs e)
        {
            //读取审核结果

           

            //跳转到申请成功界面
            if (CheckBox1.Checked && CheckBox2.Checked && CheckBox3.Checked && CheckBox4.Checked)
            { 
                //申请通过
                //跳转到打分界面
                Response.Redirect("AuditorGradePage.aspx?id=" + ApplicationIDNumber.Text);


                
            }
            else
            {
                //申请没有通过
                //跳转到审核成功界面
                Response.Redirect("AuditorCommitPage.aspx");
            }
        }
    }
}