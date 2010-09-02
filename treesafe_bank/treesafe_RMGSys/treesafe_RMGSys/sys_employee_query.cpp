#include "stdafx.h"
#include "sys_employee_query.h"

//模块19的实现文件


//19.1
//复制输入信息
void init_employee_query_input_info(employee_query_input_info* _init){
	strcpy(_init->work_id,"");
}


void init_employee_query_info(employee_query_info* _init){
	//初始化雇员信息
	init_admin_employee_info(&_init->query_data);
	//初始化错误信息
	init_sys_err(&_init->err_info);
}

employee_query_modle* init_employee_query_modle(){
	//开辟并初始化模块
	employee_query_modle* _new_modle
		= (employee_query_modle*)malloc(sizeof(employee_query_modle));
	//初始化各个数据模块
	//初始化输入模块
	init_employee_query_input_info(&_new_modle->input_info);
	//初始化结果信息
	init_employee_query_info(&_new_modle->rlt_info);
	//返回结果指针
	return _new_modle;
}


//19.2

void employee_query_copy_cmd(const char* _cmd , char* _dest , int _cmd_len){
		//复制命令
		memcpy(_dest,_cmd,_cmd_len);
}

employee_query_input_info* employee_query_convert_cmd(char* _info){
	//将命令转化为输入信息
	return (employee_query_input_info*)_info;
}

employee_query_input_info* employee_query_get_cmd(const char* _cmd
	,int _cmd_len){
		//19.2主函式
		//开辟空间
		char* _new_info = 
			(char*)malloc(_cmd_len);
		//复制
		employee_query_copy_cmd(_cmd,_new_info,_cmd_len);
		//转化
		return employee_query_convert_cmd(_new_info);
}

//19.3


//19.4
void employee_query_convert_rlt(employee_query_info* _info,
	char* _rlt , int* _rlt_len){
	   //转化结果
	*_rlt_len = sizeof(employee_query_info);

}

