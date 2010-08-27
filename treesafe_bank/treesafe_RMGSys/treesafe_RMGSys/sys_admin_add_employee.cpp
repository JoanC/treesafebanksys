#include "stdafx.h"
#include "sys_admin_add_employee.h"

//模块15 -- 管理员添加雇员模块的实现

//15.1
//初始化模块

void init_add_employee_input(add_employee_input* _init){
	//初始化输入信息
	init_admin_employee_info(&_init->employ_basic_info);
	strcpy(_init->comment,"");//初始化注释信息
}

void init_add_employee_info(add_employee_info* _init){
	//初始化添加雇员的结果记录信息
	//初始化已成功
	//遇到错误时才会将这个值变为true
	_init->is_succ = true;
	//初始化错误信息
	init_sys_err(&_init->err_info);
}


