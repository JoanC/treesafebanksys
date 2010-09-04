#include "stdafx.h"
#include "sys_admin_employee_info.h"

void init_admin_employee_info(admin_employee_info* _init){
	//初始化雇员类型,默认为操作员
	_init->employee_type = employ_type_operator;
	memset(_init->employee_id,'\0',EMPLOYEE_ID_LEN);//身份证号初始为空
	memset(_init->employee_name,'\0',EMPLOYEE_NAME_LEN);//雇员姓名初始为空
	_init->employee_gender = employee_male;//性别初始化男性
	_init->employee_age = 0;//初始化年龄
	memset(_init->employee_addr,'\0',EMPLOYEE_NAME_LEN);//初始化地址,为空
	memset(_init->employee_tel,'\0',EMPLOYEE_TEL_LEN);//初始化电话号码
	memset(_init->employee_comment,'\0',EMPLOYEE_COMM_LEN);
	memset(_init->employee_email,'\0',EMPLOYEE_EMAIL_ADDR_LEN);
}