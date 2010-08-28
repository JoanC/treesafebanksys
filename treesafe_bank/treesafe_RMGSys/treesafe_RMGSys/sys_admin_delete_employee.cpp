#include "stdafx.h"
#include "sys_admin_delete_employee.h"

//模块16的实现文件

//16.1

void init_delete_employee_input(delete_employee_input* _init){
	//初始化输入的信息
	//初始化身份证号为空
	strcpy(_init->employee_id,"");
}

void init_delete_employee_info(delete_employee_info* _init){
	//初始化结果记录信息
	_init->is_succ = true;
	//初始化错误信息
	init_sys_err(&_init->err_info);
}