﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;

namespace treesafe.Workers
{
    public partial class WorkerTeamPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["userright"].ToString() != "1")
            {
           //     Server.Transfer("~/WrongPage.aspx", true);
            }


            //读取联保小组数据
            GetLaborInfo();

        }
        protected void GetLaborInfo()
        {
            int row = 0;
            // 获得联保小组列表的项数（即现有联保小组数量）
            int numrows = 5;
            //列表宽度，共8项内容
            int numcells = 8;
            for (int j = 0; j < numrows; j++)
            {
                HtmlTableRow r = new HtmlTableRow();



                if (row % 2 == 1)// 设置行的背景色
                    r.BgColor = "Gainsboro";
                row++;
                for (int i = 0; i < numcells; i++)
                {
                    HtmlTableCell c = new HtmlTableCell(); //创建单元格对象
                    c.Controls.Add(new LiteralControl("行： " + (j + 1).ToString() + ", 单元格： " + (i + 1).ToString()));
                    r.Cells.Add(c); //添加该单元格对象
                }



                r.Attributes.Add("onclick", "Ck(this," + j + ")");
                r.Attributes.Add("onmousemove", "Move(this)");
                r.Attributes.Add("ondblclick", "DbCK(me)");
                r.Attributes.Add("onmouseout", "Out(this)");


                LaborTable.Rows.Add(r);//添加行对
            }
        }

        protected void AddTeamButton_Click(object sender, EventArgs e)
        {
            //增加联保小组界面
            Response.Redirect("WorkerNewTeamPage.aspx");
        }
    }
}