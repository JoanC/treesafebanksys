#define EMPLOYEE_ID_LEN 19
#define EMPLOYEE_NAME_LEN 51
#define EMPLOYEE_TEL_LEN 16
#define EMPLOYEE_ADDR_LEN 51
#define EMPLOYEE_PWD_LEN 18
enum admin_mgr_gender{employee_male,employee_female};

//雇员的种类
//审核员或者操作员
//管理员有权添加这两种雇员
enum admin_employee_type{
	employ_type_operator,//操作员
	employ_type_investigator//审核(调查)员
};

//雇员信息
struct admin_employee_info{
	admin_employee_type employee_type;//雇员类型
	char employee_id[EMPLOYEE_ID_LEN];//雇员的身份证号
	char employee_name[EMPLOYEE_NAME_LEN];//雇员的姓名;
	admin_mgr_gender employee_gender;//雇员性别
	int employee_age;//雇员的年龄
	char employee_addr[EMPLOYEE_ADDR_LEN];//雇员的地址
};