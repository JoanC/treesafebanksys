enum APPLY_GENDER_TYPE {apply_info_male , apply_info_female};

//申请处理流程
#define APPLY_CUST_ID_LEN 19 //申请人身份证号长度
#define APPLY_CUST_NAME_LEN 51//姓名长度

//操作员输入的信息结构
struct apply_custmor_info{
	//申请人(社员)的信息
	//...有待王亦可来确定
	char cust_id[APPLY_CUST_ID_LEN];
	//姓名
	char cust_name[APPLY_CUST_NAME_LEN];
	//性别
	APPLY_GENDER_TYPE cust_gender;
	//年龄
	int cust_age;
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