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

add_employee_modle* init_add_employee_modle(){
	//初始化添加雇员的总模块
	//分配内存..
	add_employee_modle* _new_modle = 
		(add_employee_modle*)malloc(sizeof(add_employee_modle));
	//初始化模块
	//输入信息初始化
	init_add_employee_input(&_new_modle->input_info);
	//结果记录信息
	init_add_employee_info(&_new_modle->rlt_info);
	return _new_modle;
}


//15.2

void add_employee_copy_cmd(const char* _cmd , char* _dest , int _cmd_len){
	//复制命令信息
	memcpy(_dest,_cmd,_cmd_len);
}

add_employee_input* add_employee_convert_cmd(char* _info){
	//转化命令成为输入数据
	return (add_employee_input*)_info;
}

add_employee_input* add_employee_get_cmd(const char* _cmd,
	char* _dest , int _cmd_len){
	//转化并且复制指令
	char* _info = (char*)malloc;

}