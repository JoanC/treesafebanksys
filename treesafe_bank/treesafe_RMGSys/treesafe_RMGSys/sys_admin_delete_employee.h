#pragma once

#include "sys_admin_employee_info.h"
#include "sys_error_compute.h"//错误处理

//模块16
//删除雇员信息

//传入的信息
//其实就是根据一个id去删除用户
struct delete_employee_input{
	char employee_id[EMPLOYEE_ID_LEN];//身份证号码
};

//结果信息
//其实就是一个是否删除成功的标记
struct delete_employee_info{
	bool is_succ;//是否删除成功
	sys_err
};