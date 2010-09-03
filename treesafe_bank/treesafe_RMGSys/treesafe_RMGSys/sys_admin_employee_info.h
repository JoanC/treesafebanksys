#pragma once

#define EMPLOYEE_ID_LEN 19
#define EMPLOYEE_NAME_LEN 51
#define EMPLOYEE_TEL_LEN 12
#define EMPLOYEE_ADDR_LEN 51
#define EMPLOYEE_PWD_LEN 18
#define EMPLOYEE_COMM_LEN 257
#define EMPLOYEE_WORK_ID_LEN 8 //雇员工号 
#define EMPLOYEE_EMAIL_ADDR_LEN 51 //电子邮件地址的长度

enum admin_mgr_gender{employee_male,employee_female};

//雇员的种类
//审核员或者操作员
//管理员有权添加这两种雇员
enum admin_employee_type{
	employ_type_operator = 0 ,//操作员
	employ_type_investigator = 1 ,//审核(调查)员
};

//雇员信息
struct admin_employee_info{
	admin_employee_type employee_type;//雇员类型
	int employee_age;//雇员的年龄
    admin_mgr_gender employee_gender;//雇员性别
	char employee_id[EMPLOYEE_ID_LEN];//雇员的身份证号
	char employee_work_id[EMPLOYEE_WORK_ID_LEN];//雇员工号
	char employee_name[EMPLOYEE_NAME_LEN];//雇员的姓名;
	char employee_addr[EMPLOYEE_ADDR_LEN];//雇员的地址
	char employee_email[EMPLOYEE_EMAIL_ADDR_LEN];//雇员电子邮件地址
	char employee_tel[EMPLOYEE_TEL_LEN];//电话号码
	char employee_comment[EMPLOYEE_COMM_LEN] ; //职员信息
};

//初始化函数
void init_admin_employee_info(admin_employee_info* _init);
