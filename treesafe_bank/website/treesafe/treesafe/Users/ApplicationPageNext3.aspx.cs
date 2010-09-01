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
            int cust_edu_degree;//受教育情况
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 51)]
            char[] cust_addr;//家庭地址
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 7)]
            char[] cust_zip;//邮政编码
            int cust_house_type;//住宅权属
            public apply_custmor_info(int _gender, int _age
                , int _card_type, int _edu,int _house, string _name
                , string _card_id, string _tel, string _other_tel,string _addr,string _zip)
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
        /*
  	char app_id[APPLY_ID] ;
	APPLY_PERSON_INCOME_RANGE cust_personal_annual_income;//个人年收入
	APPLY_FAMILY_INCOME_RANGE cust_family_annual_income;//家庭年收入
	APPLY_DEPOSIT_TYPE cust_deposit_type;//是否有存款以及存款类型
	//这两个金额存入数据库中
	APPLY_DEPOSIT_RANGE cust_regular_deposit;//定期存款金额(范围)
	APPLY_DEPOSIT_RANGE cust_demand_deposit;//活期存款额(范围)
	//以上两个加上
	//
	bool does_cust_have_loan;//是否有贷款
	APPLY_LOAN_RANGE cust_loan_sum;//贷款总金额(范围)
	APPLY_LOAN_TIME cust_loan_time;//经过多少shijian后还款
	APPLY_UNSECURED_FIXED_ASSETS cust_unsecured_fixed_asset;//固定资产类型
	APPLY_INDUSTRY_TYPE cust_industry;//从事行业
	char cust_work_unit[APPLY_WORK_UINT_LEN];//工作单位
	char cust_work_pos[APPLY_WORK_POSITION_LEN];//工作职位
	//-->这个(存款范围)不要了~	
	APPLY_DEPOSIT_RANGE cust_deposit_range;//存款范围
//为了保持程序运行,这个先留着
};*/
        [Serializable] // 指示可序列化
        [StructLayout(LayoutKind.Sequential, Pack = 0)] // 按0字节对齐
        struct apply_cust_asset_info
        {
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 11)]
            char[] app_id;//申请id
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
                this.app_id = "".PadRight(11,'\0').ToCharArray();
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
                this.cust_work_position = _pos.PadRight(51,'\0').ToCharArray();
                this.cust_work_unit = _unit.PadRight(51,'\0').ToCharArray();
            }
        }


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
                    ,ApplicationPage.apply_cust_edu,
                    ApplicationPage.apply_cust_house_type,
                    ApplicationPage.apply_cust_name,
                    ApplicationPage.apply_cust_id,
                    ApplicationPage.apply_cust_tel,
                    ApplicationPage.apply_cust_other_tel,
                    ApplicationPage.apply_cust_addr,
                    ApplicationPage.apply_cust_zip);
            //读取完成信息后，将结束申请，并跳转回到用户主页。
            Server.Transfer("~/Users/UserFinishApplicationPage.aspx", true);
        }
    }
}