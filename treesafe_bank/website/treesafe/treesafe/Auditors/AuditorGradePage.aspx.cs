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

namespace treesafe.Auditors
{
    [Serializable] // 指示可序列化
    [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
    public struct get_score_input_info 
    {
        int asset_score;
        int work_score;
        int society_score;
        int loan_score;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
        public char[] card_id;//返回的一个待审核申请的id
        public get_score_input_info(int _ass, int _work, int _soci, int _loan, string _id) {
            asset_score = _ass;
            work_score = _work;
            society_score = _soci;
            loan_score = _loan;
            card_id = _id.PadRight(19, '\0').ToCharArray();
        }
    }

    public partial class AuditorGradePage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            UserID.Text = Request.QueryString["id"];
        }

        protected void CommitApplicationGradeButton_Click(object sender, EventArgs e)
        {
            //读取信息
            get_score_input_info _input
                = new get_score_input_info(int.Parse(ApplicationMortgageGrade.Text),
                    int.Parse(ApplicationWorkGrade.Text)
                    ,int.Parse(ApplicationSocietyRecord.Text)
                    ,int.Parse(ApplicationLoanGrade.Text)
                    ,"0000000000");
            web_net_client_mgr _net = new web_net_client_mgr();
            _net.send_command_data(10,_input);
            //结束评分，跳转到成功界面
            Response.Redirect("AuditorCommitPage.aspx");
        }
    }
}