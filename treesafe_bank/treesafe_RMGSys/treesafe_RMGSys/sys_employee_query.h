#pragma once

#include "database_mgr.h"//数据库计算
#include "sys_error_compute.h"//错误处理

//模块19
//单个的雇员信息查询
//通过工号,查询一个雇员的具体信息

//雇员信息查询数据
typedef admin_employee_info employee_query_data;

//输入信息
struct employee_query_input_info{
	char work_id[EMPLOYEE_WORK_ID_LEN];//输入的雇员工号
};

//待发送的结果信息
struct employee_query_info{
	employee_query_data query_data;//数据库查询结果
	//系统错误
	sys_err err_info;
};

//模块19的主模块结构体
struct employee_query_

/***************************************/
//19.1
//初始化和释放模块及其数据

void init_employee_query_input_info(employee_query_input_info* _init);

void init_employee_query_info(employee_query_info* _init);

