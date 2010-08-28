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

delete_employee_modle* init_delete_employee_modle(){
	//初始化模块16的整体
	//分配内存
	delete_employee_modle* _new_modle
		= (delete_employee_modle*)malloc(sizeof(delete_employee_modle));
	//初始化各个数据块
	init_delete_employee_input(&_new_modle->input_info);
	init_delete_employee_info(&_new_modle->rlt_info);
	return _new_modle;
}


//16.2

delete_employee_input* delete_employee_get_cmd(const char* _cmd,int _cmd_len){
	//删除雇员的接受命令主函式
	char* _info = (char*)malloc(_cmd_len);
	delete_employee_copy_cmd(_cmd,_info,_cmd_len);
	return delete_employee_convert_cmd(_info);
}

//接受指令
void delete_employee_copy_cmd(const char* _cmd , char* _dest 
	, int _cmd_len){
	//复制命令
	memcpy(_dest,_cmd,_cmd_len);
}


delete_employee_input* delete_employee_convert_cmd(char* _info){
	//强制转化指令
	return (delete_employee_input*)_info;
}

//16.3
//...
//待sunni去完成


//16.4
//...
void delete_employee_convert_rlt(delete_employee_info* _info , char* _rlt , int* _rlt_len){
	
}


void delete_employee_frame(const char* _cmd , int _cmd_len , char* _rlt , int* _rlt_len){
    //16.1
	//初始化模块
	delete_employee_modle* _frame
		=(delete_employee_modle*)malloc(sizeof(delete_employee_modle));
	//16.2
	//获取指令
	_frame->input_info = *delete_employee_get_cmd(_cmd,_cmd_len);
}