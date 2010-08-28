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

#define APPLY_CUST_ID_LEN 19 //申请人身份证号长度
#define APPLY_CUST_NAME_LEN 51//姓名长度
#define APPLY_CARD_NUMBER_LEN 19//证件号码长度
#define APPLY_CUST_ADDR_LEN 51//家庭住址长度
#define APPLY_CUST_ZIP_CODE_LEN 7 //邮政编码长度
#define APPLY_CUST_TEL_LEN 19 //联系电话长度

enum APPLY_GENDER_TYPE {apply_info_male , apply_info_female};//性别值
enum APPLY_CARD_TYPE{id_card/*身份证*/,ｍilitary_card/*军人证*/};//证件类型
enum APPLY_CUST_HOUSING_TENURE{own/*自有*/,lease/*租赁*/,other/*其他*/};//住房权属
enum APPLY_CUST_EDUCATION_DEGREE{
	master_and_above,/*硕士及以上*/
	undergraduate,/*本科*/
	college,/*大专*/
	high_school,/*高中*/
	primary_and_below/*小学及以下*/
};//受教育程度

//操作员输入的信息结构
struct apply_custmor_info{
	char cust_name[APPLY_CUST_NAME_LEN];//申请人信息
	APPLY_GENDER_TYPE cust_gender;//申请人性别
	int cust_age;//申请人性别
	APPLY_CARD_TYPE cust_card_type;//证件类型
	char cust_id[APPLY_CARD_NUMBER_LEN];//证件id
	char cust_tel_num[APPLY_CUST_TEL_LEN];//联系电话
	char cust_other_tel_num[APPLY_CUST_TEL_LEN];//其他联系电话
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

//

enum APPLY_DEPOSIT_TYPE{none_deposit/*无存款*/,
	regular_deposit/*定期存款*/,
	demand_deposit/*活期存款*/
};

enum APPLY_DEPOSIT_RANGE{//存款范围
	none_range//空范围
};

enum APPLY_UNSECURED_FIXED_ASSETS{
	//未抵押的固定资产类型
};

struct apply_cust_asset_info{
	int cust_personal_annual_income;//个人年收入
	int cust_family_annual_income;//家庭年收入
	APPLY_DEPOSIT_TYPE cust_deposit_type;//是否有存款以及存款类型
	APPLY_DEPOSIT_RANGE cust_deposit_range;//存款范围
	bool cust_is_has_loan;//是否有贷款
	int cust_loan_sum;//贷款总金额
	int cust_loan_time;//经过多少年后还款
	APPLY_UNSECURED_FIXED_ASSETS cust_unsecured_fixed_asset;//固定资产类型
};


struct apply_loan_info{
	//与联保申请的其它相关信息
	//...有待王亦可来确定
};

struct apply_input_info{
	//输入申请人的基本信息
	apply_custmor_info input_basic_info;
	//与贷款相关的其它信息
	apply_loan_info input_loan_info;
};

//申请处理的所有信息结构
struct apply_info{
	//即要传给网络层的信息
	//个人认为:
	//只需要把对比基本信息时的错误传给当前的页面
	//如果没有错误
	//则表示该申请正在进行审核...
	//下面是错误信息,如果错误信息显示no_err,则是申请成功
	sys_err errInfo;//申请处理中的错误信息
};

//申请处理的整体模块
struct apply_modle{
	apply_input_info input_info;//输入信息
	apply_custmor_info db_cust_info;//从数据库中读入的信息
	apply_info rlt_info;//存储申请过程中的信息,作为结果传到网络层中
};