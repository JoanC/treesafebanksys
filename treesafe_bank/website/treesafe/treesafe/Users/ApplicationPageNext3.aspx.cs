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
            char[] app_id;//申请id,为空,其值在服务器段赋予
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
            int cust_edu_degree;//受教育情况
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 51)]
            char[] cust_addr;//家庭地址
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 7)]
            char[] cust_zip;//邮政编码
            int cust_house_type;//住宅权属
            public apply_custmor_info(int _gender, int _age
                , int _card_type, int _edu, int _house, string _name
                , string _card_id, string _tel, string _other_tel, string _addr, string _zip)
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
                this.cust_zip = _zip.PadRight(7, '\0').ToCharArray();
                this.cust_house_type = _house;
            }
        };

        //用户资产情况信息
        [Serializable] // 指示可序列化
        [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按0字节对齐
        struct apply_cust_asset_info
        {
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 11)]
            char[] app_id;//申请id,为空,其值在服务器段赋予
            int cust_personal_annual_income;//个人年收入
            int cust_family_annual_income;//家庭年收入
            int cust_deposit_type;//存款类型,0表示没有存款
            int cust_regular_deposit;//定期存款金额
            int cust_demand_deposit;//活期存款额
            int cust_is_has_loan;//是否有贷款
            int cust_loan_sum;//贷款总金额
            int cust_loan_time;//多少时间返还
            int cust_is_has_fixed_asset;//是否有固定资产
            int cust_unsecured_fixed_asset;//固定资产类型
            int cust_industry;//从事行业
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 51)]
            char[] cust_work_unit;//工作单位
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 51)]
            char[] cust_work_position;//工作职位

            //-------------------------------------------------------
            int _pad;//
            //-------------------------------------------------------
            public apply_cust_asset_info(int _pincome, int _fincome,
             int _dep_type, int _reg_dep, int _dem_dep,
                int _is_has_loan, int _loan_sum, int _loan_time,
                   int _is_has_fixed, int _fixed_type, int _industry,
            string _unit, string _pos)
            {
                this._pad = 0;
                this.app_id = "".PadRight(11, '\0').ToCharArray();
                this.cust_demand_deposit = _dem_dep;
                this.cust_deposit_type = _dep_type;
                this.cust_family_annual_income = _fincome;
                this.cust_industry = _industry;
                this.cust_is_has_fixed_asset = _is_has_fixed;
                this.cust_is_has_loan = _is_has_loan;
                this.cust_loan_sum = _loan_sum;
                this.cust_loan_time = _loan_time;
                this.cust_personal_annual_income = _pincome;
                this.cust_regular_deposit = _reg_dep;
                this.cust_unsecured_fixed_asset = _fixed_type;
                this.cust_work_position = _pos.PadRight(51, '\0').ToCharArray();
                this.cust_work_unit = _unit.PadRight(51, '\0').ToCharArray();
            }
        }

        //申请人的家庭信息
        [Serializable] // 指示可序列化
        [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按0字节对齐
        struct apply_cust_family_info
        {
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 11)]
            public char[] app_id;//申请id,为空,其值在服务器赋予
            public int cust_marital_status;//婚姻情况
            public int cust_children_num;//子女人数
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 51)]
            public char[] cust_spouse_name;//陪偶姓名
            /////////////////////////////////////////////////
            //这里界面要加!? 就是配偶的卡号类型
            public int cust_apouse_card_type;//卡类型
            ////////////////////////////////////////////////
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 19)]
            public char[] cust_spouse_card_id;//配偶的卡号
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 51)]
            public char[] cust_spouse_work_unit;//配偶的工作单位
            public int cust_spouse_edu_degree;//配偶的受教育程度
            public int cust_spouse_is_has_loan;//配偶是否有贷款
            public apply_cust_family_info(int _mar_stu, int _chd_num
                , int _sps_card_type, int _sps_edu, int _is_sps_has_loan
                , string _sps_name, string _sps_card_id, string _sps_work_unit)
            {
                this.cust_apouse_card_type = 0;
                this.app_id = "".PadRight(11, '\0').ToCharArray();
                this.cust_apouse_card_type = _sps_card_type;
                this.cust_children_num = _chd_num;
                this.cust_marital_status = _mar_stu;
                this.cust_spouse_card_id = _sps_card_id.PadRight(19, '\0').ToCharArray();
                this.cust_spouse_edu_degree = _sps_edu;
                this.cust_spouse_is_has_loan = _is_sps_has_loan;
                this.cust_spouse_name = _sps_name.PadRight(51, '\0').ToCharArray();
                this.cust_spouse_work_unit = _sps_work_unit.PadRight(51, '\0').ToCharArray();
            }
        };

        [Serializable] // 指示可序列化
        [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按0字节对齐
        struct apply_loan_info
        {
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 11)]
            public char[] app_id;//申请id,为空,其值在服务器赋予
            int loan_application_amount;//贷款金额
            int loan_dead_line;//还款期限(单位为月份)
            int loan_times;//申请人的贷款次数;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 1024)]
            char[] loan_comment;//注释信息
            int is_want_msg;//是否需要短信提示
            public apply_loan_info(int _amount, int _deadline, int _loan_times
                , int _is_want_msg, string _loan_comment)
            {
                this.app_id = "".PadRight(11,'\0').ToCharArray();
                this.is_want_msg = _is_want_msg;
                this.loan_application_amount = _amount;
                this.loan_comment = _loan_comment.PadRight(1024,'\0').ToCharArray();
                this.loan_dead_line = _deadline;
                this.loan_times = _loan_times;
            }
        }

        public int cust_loan_amount;
        public int cust_loan_deadline;
        public int cust_loan_times;
        public int cust_is_want_msg;
        public string cust_loan_comment;

        /*
         * void apply_init_apply_input_info(apply_input_info* _init){
	//初始化输入信息
	apply_init_apply_custmor_info(&_init->input_basic_info);
	apply_init_apply_custmor_assets_info(&_init->input_asset_info);
	apply_init_apply_custmor_family_info(&_init->input_fammily_info);
	apply_init_apply_loan_info(&_init->input_loan_info);
}
*/
        [Serializable] // 指示可序列化
        [StructLayout(LayoutKind.Sequential, Pack = 1)] // 按1字节对齐
        struct apply_input_info
        {
            apply_custmor_info cust_info;
            apply_cust_asset_info asset_info;
            apply_cust_family_info family_info;
            apply_loan_info loan_info;
            public apply_input_info(apply_custmor_info _cust,
               apply_cust_asset_info _asset,apply_cust_family_info _family,apply_loan_info _loan)
            {
                this.asset_info = _asset;
                this.cust_info = _cust;
                this.family_info = _family;
                this.loan_info = _loan;
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
            /*从第一个界面读取信息*/
            apply_custmor_info _cust_info
                = new apply_custmor_info(ApplicationPage.apply_cust_gender,
                    ApplicationPage.apply_cust_age,
                    ApplicationPage.apply_cust_card_type
                    , ApplicationPage.apply_cust_edu,
                    ApplicationPage.apply_cust_house_type,
                    ApplicationPage.apply_cust_name,
                    ApplicationPage.apply_cust_id,
                    ApplicationPage.apply_cust_tel,
                    ApplicationPage.apply_cust_other_tel,
                    ApplicationPage.apply_cust_addr,
                    ApplicationPage.apply_cust_zip);
            /*从第二个界面读取信息*/
            apply_cust_asset_info _asset_info
                = new apply_cust_asset_info(ApplicationPageNext1.apply_cust_pincome,
                    ApplicationPageNext1.apply_cust_fincome,
                    ApplicationPageNext1.apply_cust_dep_type,
                    ApplicationPageNext1.apply_cust_reg_dep,
                    ApplicationPageNext1.apply_cust_dem_dep,
                    ApplicationPageNext1.apply_cust_is_has_loan,
                    ApplicationPageNext1.apply_cust_loan_sum,
                    ApplicationPageNext1.apply_cust_loan_time,
                    ApplicationPageNext1.apply_cust_is_has_fixed,
                    ApplicationPageNext1.apply_cust_fixed_type,
                    ApplicationPageNext1.apply_cust_industry,
                    ApplicationPageNext1.apply_cust_work_unit,
                    ApplicationPageNext1.apply_cust_work_pos);
            /*从第三个界面读取信息*/
            apply_cust_family_info _family_info
                = new apply_cust_family_info(ApplicationPageNext2.apply_cust_mar_stu,
                    ApplicationPageNext2.apply_cust_chd_num,
                    ApplicationPageNext2.apply_cust_sps_card_type,
                    ApplicationPageNext2.apply_cust_sps_edu,
                    ApplicationPageNext2.apply_cust_is_sps_has_loan,
                    ApplicationPageNext2.apply_cust_sps_name,
                    ApplicationPageNext2.apply_cust_sps_card_id,
                    ApplicationPageNext2.apply_cust_sps_work_unit);
            /*从第四个界面(即本界面)读取数据*/
            cust_loan_amount = int.Parse(ApplicationExceptLoanSum.Text);
            cust_loan_deadline = int.Parse(ApplicationLoanTime.Text);
            cust_loan_times = int.Parse(ApplicationLoanNumber.Text);
            cust_loan_comment =
                Chinese_Encode.Chinese_Encode_Mgr.utf7_convert(ApplicationLoanNote.Text);
            cust_is_want_msg = int.Parse(ApplicationIsMessage.Text);
            apply_loan_info _loan_info =
                new apply_loan_info(cust_loan_amount,cust_loan_deadline,cust_loan_times,cust_is_want_msg,cust_loan_comment);
            /*整理总信息*/
            apply_input_info _input_info =
                new apply_input_info(_cust_info,_asset_info,_family_info,_loan_info);
            /*发送数据*/
            web_net_client_mgr _net_mgr = new web_net_client_mgr();
            //2表示提交申请的命令
            _net_mgr.send_command_data(2,_input_info);


            //读取完成信息后，将结束申请，并跳转回到用户主页。
            Server.Transfer("~/Users/UserFinishApplicationPage.aspx", true);
        }
    }
}