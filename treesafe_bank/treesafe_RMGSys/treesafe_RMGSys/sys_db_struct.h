#pragma once

//登陆模块的信息查询
//登陆权限
//管理员,一般用户...
enum login_competence{
	compe_err	= -1 ,	
	compe_cust = 0 ,
	compe_operater = 1 ,
	compe_admin = 3,
	//...other competence
};


const size_t idLen			= 19 ;
const size_t pwdLen		= 16 ;
struct sys_db_login{
	char								user_id[idLen] ;
	char								login_pwd[pwdLen] ;
	login_competence		cmpt ;
};

//以下的结构体
//由Jiraiya添加
//用途在各个名字前做详细说明

//模块7,8要用的
//审核表
//即申请信息加各个信息是否正确(bit)和一个注释
//具体的你命名
struct sys_db_research{
	//审核申请的编号
	//各信息的原始数据(申请人id等)

	//各信息的是否正确
	//...

	//注释信息(1个即可)
	//...
};

//模块9使用的
//正式的申请信息
struct sys_db_apply{
	//正式申请的编号
	//各信息的最终数据(申请人id等)
	//...
};


//apply data struct
//申请处理流程

/*
//申请人基本信息
申请人姓名：
性别：
年龄：
证件类型：
证件号码：
家庭住址：            邮政编码：
住宅权属：□自有 □租赁 □其他
联系电话：
其他联系电话：
受教育状况：□硕士及以上 □本科 □大专 □高中 □初中及以下
*/

//以下定义了用户基础数据中的各个字符串的最大长度

#define APPLY_ID 11 //申请表号（自动生成）
#define APPLY_CUST_ID_LEN 19 //申请人身份证号长度
#define APPLY_CUST_NAME_LEN 51//姓名长度
#define APPLY_CARD_NUMBER_LEN 19//证件号码长度
#define APPLY_CUST_ADDR_LEN 51//家庭住址长度
#define APPLY_CUST_ZIP_CODE_LEN 7 //邮政编码长度
#define APPLY_CUST_TEL_LEN 11 //联系电话长度

enum APPLY_GENDER_TYPE {apply_info_male , apply_info_female};//性别值
enum APPLY_CARD_TYPE{id_card/*身份证*/,ｍilitary_card/*军人证*/};//证件类型
enum APPLY_CUST_HOUSING_TENURE{own/*自有*/,lease/*租赁*/,other/*其他*/};//住房权属

enum APPLY_CUST_EDUCATION_DEGREE{
	edu_master_and_above = 1,/*硕士及以上*/
	edu_undergraduate = 2 ,/*本科*/
	edu_college = 3 ,/*大专*/
	edu_high_school = 4 ,/*高中*/
	edu_primary_and_below = 5/*小学及以下*/
};//受教育程度

//操作员输入的信息结构
struct apply_custmor_info{
	char app_id[APPLY_ID] ;
	char cust_name[APPLY_CUST_NAME_LEN];//申请人信息
	APPLY_GENDER_TYPE cust_gender;//申请人性别
	int cust_age;//申请人年龄
	APPLY_CARD_TYPE cust_card_type;//证件类型
	char cust_id[APPLY_CARD_NUMBER_LEN];//证件id
	char cust_tel_num[APPLY_CUST_TEL_LEN];//联系电话
	char cust_other_tel_num[APPLY_CUST_TEL_LEN];//其他联系电话
	APPLY_CUST_EDUCATION_DEGREE cust_edu;//受教育情况

	//////////////////////////////////////////////////////////
	//紧急，加填到数据库中
	char cust_addr[APPLY_CUST_ADDR_LEN];//地址
	char cust_zip_code[APPLY_CUST_ZIP_CODE_LEN];//邮政编码
	APPLY_CUST_HOUSING_TENURE cust_house_type;//住宅权属
	//////////////////////////////////////////////////////////

};

/*
个人年收入：
家庭年收入:
是否有存款：
存款金额：活期（范围）
定期（范围）
是否有贷款：□是 □否
贷款总金额（范围）：
预计还清贷款日期（年月日）：
是否有已抵押的固定资产：□是 □否
如有未抵押的固定资产请选择并对其做出评估：
         •房地产
         •交通工具
         •生产设备
         •其他
从事行业：□种植业 □林业 □畜牧业 □渔业 □农、林、牧、渔服务业 
工作单位或经营内容：
职位：
*/

enum APPLY_DEPOSIT_TYPE{
	none_deposit/*无存款*/,
	has_deposit//有存款
};

enum APPLY_PERSON_INCOME_RANGE{
	//个人收入范围(年)
	pincome_down_2000,//2000以下
	pincome_2000_to_5000,//2000到5000
	pincome_5000_to_8000,//5000到8000
	pincome_8000_to_1w,//8000到1w
	pincome_1w_to_15q,//1w到1.5w
	pincome_15q_to_2w,//1.5w到2w
	pincome_up_2w//2w以上
};

enum APPLY_FAMILY_INCOME_RANGE{
	//家庭收入范围
	fincome_down_2000,//2000以下
	fincome_2000_to_5000,//2000到5000
	fincome_5000_to_1w,//5000到1w
	fincome_1w_to_3w,//1w到3w
	fincome_3w_to_5w,//3w到5w
	fincome_5w_to_10w,//5w到10w
	fincome_up_10w//10w以上
};

enum APPLY_DEPOSIT_RANGE{
	//存款范围
	deposit_none_range,//空范围(无存款)
	deposit_down_2000,//2000以下
	deposit_2000_to_5000,//5000以下
	deposit_5000_to_8000,//5000-8000
	deposit_8000_to_1w,//8000-1w
	deposit_1w_to_2w,//1w-2w
	deposit_2w_to_5w,//2w-5w
	deposit_up_5w//5w以上
};

enum APPLY_LOAN_RANGE{
	//贷款范围
	loan_none_range,//空范围(无存款)
	loan_down_2000,//2000以下
    loan_2000_to_5000,//5000以下
	loan_5000_to_8000,//5000-8000
	loan_8000_to_1w,//8000-1w
	loan_1w_to_2w,//1w-2w
	loan_2w_to_5w,//2w-5w
	loan_up_5w//5w以上
};

enum APPLY_LOAN_TIME{
	//换贷款的时间范围
	apply_time_none,//无
	apply_time_down_6m,//6个月以下
	apply_time_6m_to_12m,//6个月 - 12个月
	apply_time_12m_to_24m,//12个月-24个月
	apply_time_up_24m//24个月以上
};

enum APPLY_UNSECURED_FIXED_ASSETS{
	//未抵押的固定资产类型
	asset_house,//房地产
	asset_factory,//工作厂房
	asset_peronal_transport,//个人交通工具
	asset_transport,//运输工具
	asset_production_equipment,//生产设备
	asset_other//其它
};

enum APPLY_INDUSTRY_TYPE{
	//从事行业
	farm_industry_plant,//种植页
	farm_industry_fish,//渔业
	farm_industry_forestry, //林业
	farm_industry_livestock,//畜牧业
	farm_industry_fruit_vegetables,//水果蔬菜
	farm_industry_ornamental_horticulture,//观赏园艺
	farm_industry_agricultural_corporation,//农资企业
	farm_industry_agricultural_machinery,//农业器械
	farm_industry_processing_storage,//加工贮藏
	farm_industry_foodstuffs,//粮油食品
	farm_industry_transportation,//交通运输
	farm_industry_biotechnology,//生物技术
	farm_industry_genetics,//基因工程
	farm_industry_other//其他行业
};

#define APPLY_WORK_UINT_LEN  51//工作单位长度
#define APPLY_WORK_POSITION_LEN 51 //工作职务

struct apply_cust_asset_info{
	char app_id[APPLY_ID] ;
	APPLY_PERSON_INCOME_RANGE cust_personal_annual_income;//个人年收入
	APPLY_FAMILY_INCOME_RANGE cust_family_annual_income;//家庭年收入
	APPLY_DEPOSIT_TYPE cust_deposit_type;//是否有存款以及存款类型
	//这两个金额存入数据库中
	///////////////////////////////////////////////////////////////////
	APPLY_DEPOSIT_RANGE cust_regular_deposit;//定期存款金额(范围)
	APPLY_DEPOSIT_RANGE cust_demand_deposit;//活期存款额(范围)
	///////////////////////////////////////////////////////////////////
	//以上两个加上
	//
	bool does_cust_have_loan;//是否有贷款
	APPLY_LOAN_RANGE cust_loan_sum;//贷款总金额(范围)
	APPLY_LOAN_TIME cust_loan_time;//经过多少shijian后还款
	////////////////////////////////////////////////////////////
	bool is_has_fixed_asset;//是否有固定资产
	////////////////////////////////////////////////////////////
	APPLY_UNSECURED_FIXED_ASSETS cust_unsecured_fixed_asset;//固定资产类型
	APPLY_INDUSTRY_TYPE cust_industry;//从事行业
	char cust_work_unit[APPLY_WORK_UINT_LEN];//工作单位
	char cust_work_pos[APPLY_WORK_POSITION_LEN];//工作职位
	//-->这个(存款范围)不要了~	
	//------------------------------------------------
	APPLY_DEPOSIT_RANGE cust_deposit_range;//存款范围
	//------------------------------------------------
//为了保持程序运行,这个先留着
};


/*
家庭情况资料
婚姻状况：□已婚 □未婚
子女人数：
配偶姓名：
配偶身份证号：
配偶工作单位（工作情况）：
配偶受教育程度：□硕士及以上 □本科 □大专 □高中 □初中及以下
配偶是否有已申请贷款：□是 □否
*/

enum APPLY_CUST_MARITAL_STATUS{
	//婚姻情况
	is_married,/*已婚*/
	not_married,/*未婚*/
	divorced,/*离异*/
	spouse_die/*丧偶*/
};

struct apply_cust_family_info{
	char app_id[APPLY_ID] ;
	APPLY_CUST_MARITAL_STATUS cust_marital_status;//申请人的婚姻状况
	int cust_children_num;//子女人数
	char cust_spouse_name[APPLY_CUST_NAME_LEN];//陪偶姓名
	APPLY_CARD_TYPE cust_apouse_card_type;//配偶的卡类型
	char cust_spouse_card_id[APPLY_CARD_NUMBER_LEN];//配偶的卡号
	char cust_spouse_work_unit[APPLY_WORK_UINT_LEN];//配偶的工作单位
	APPLY_CUST_EDUCATION_DEGREE cust_spouse_edu_degree;//配偶的受教育程度
	bool does_cust_spouse_has_loan;//配偶是否有贷款
};

/*
申请金额：人民币   元
期限：   月
贷款用途：
贷款次数：□首次贷款 □多次贷款

申贷项目可行性说明：

是否希望接收我们的短信通知：□是 □否
*/

//??????????????
//贷款用途是否要选择性?

#define APPLY_LOAN_COMMENT 1024


enum APPLY_LOAN_INDUSTRY{
	loan_industry_other//其他用途
};

enum APPLY_LOAN_TIMES{
	//申请人过往的贷款次数
	loan_times_first,//第一次贷款
	loan_times_multiple//多次贷款
};

enum APPLY_MESSAGE{
	cust_want_msg,//需要短信
	cust_not_want_msg//用户不需要短信
};

struct apply_loan_info{
	//贷款信息
	char app_id[APPLY_ID] ;
	APPLY_LOAN_RANGE loan_application_amount;//贷款金额(范围)
	int loan_dead_line;//还款期限(单位为月份)
	APPLY_LOAN_TIMES loan_times;//申请人的贷款次数
	char loan_comment[APPLY_LOAN_COMMENT];//贷款的使用说明
    ///////////////////////////////////////////
	APPLY_MESSAGE is_want_msg;
	///////////////////////////////////////////
};

struct apply_input_info{
	//输入申请人的基本信息
	apply_custmor_info input_basic_info;
	//输入资产信息
	apply_cust_asset_info input_asset_info;
	//输入家庭信息
	apply_cust_family_info input_fammily_info;
	//与贷款相关的其它信息
	apply_loan_info input_loan_info;
};

typedef apply_input_info apply_db_info;

//提交审核报告的审核员输入信息
//以下有些是审核员填写的
//而比如审核员id则是网页端自动生成的
//审核员ID长度
#define RESEARCH_COMMIT_RESEARCHER_ID_LEN 19
//审核员姓名长度
#define RESEARCH_COMMIT_RESEARCHER_NAME_LEN 51
//审核员的电话联系方式
#define RESEARCH_COMMIT_RESEARCHER_TEL_LEN 19

//被提交的审核申请的ID
#define RESEARCH_COMMIT_APPLY_ID_LEN APPLY_ID

//审核
#define RESEARCH_COMMIT_COMMENT 128

struct research_commit_input_info{
	//被提交的申请的相关信息
	char research_apply_id[RESEARCH_COMMIT_APPLY_ID_LEN];
	//申请的相关信息
	char researcher_id[RESEARCH_COMMIT_RESEARCHER_ID_LEN];
	//有待亦可确定
	bool is_research_approved;//审核是否通过
	//个人信息审核注释
	char cust_research_info_comment[RESEARCH_COMMIT_COMMENT];
	//家庭信息审核过程
	char family_research_info_comment[RESEARCH_COMMIT_COMMENT];
	//资产信息审核过程
	char asset_research_info_comment[RESEARCH_COMMIT_COMMENT];
	//贷款信息
	char loan_research_info_comment[RESEARCH_COMMIT_COMMENT];
};
