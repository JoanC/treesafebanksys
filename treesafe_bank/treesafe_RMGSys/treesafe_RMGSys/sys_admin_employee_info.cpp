#include "stdafx.h"
#include "sys_admin_employee_info.h"

void init_admin_employee_info(admin_employee_info* _init){
	//初始化雇员类型,默认为操作员
	_init->employee_type = employ_type_operator;
	strcpy(_init->employee_id,"");//身份证号初始为空
	strcpy(_init->employee_name,"");//雇员姓名初始为空
	_init->employee_gender = employee_male;//性别初始化男性
	_init->employee_age = 0;//初始化年龄
	strcpy(_init->employee_addr,"");//初始化地址,为空
}