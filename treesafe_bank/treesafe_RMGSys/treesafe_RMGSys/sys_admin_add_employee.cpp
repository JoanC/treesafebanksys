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

void release_add_employee_modle(add_employee_modle* _release){
	free(_release);
}
//15.2

void add_employee_copy_cmd(const char* _cmd , char* _dest , int _cmd_len){
	//复制命令信息
	memcpy(_dest,_cmd,_cmd_len);
}

add_employee_input* add_employee_convert_cmd(char* _info){
	//转化命令成为输入数据
	add_employee_input* _new_info = (add_employee_input*)_info;

	//进行中文解码utf7解码
	DECODE_UTF7_TO_ASC(_new_info->comment);
	DECODE_UTF7_TO_ASC(_new_info->employ_basic_info.employee_addr);
	DECODE_UTF7_TO_ASC(_new_info->employ_basic_info.employee_email);
	DECODE_UTF7_TO_ASC(_new_info->employ_basic_info.employee_id);
	DECODE_UTF7_TO_ASC(_new_info->employ_basic_info.employee_name);
	DECODE_UTF7_TO_ASC(_new_info->employ_basic_info.employee_tel);
	DECODE_UTF7_TO_ASC(_new_info->employ_basic_info.employee_work_id);
	return _new_info;
}

add_employee_input* add_employee_get_cmd(const char* _cmd,int _cmd_len){
	//转化并且复制指令
	char* _info = (char*)malloc(_cmd_len);
	//复制命令
	add_employee_copy_cmd(_cmd,_info,_cmd_len);
	//转化指令
	return add_employee_convert_cmd(_info);
}

//15.3
void add_employee_to_db(add_employee_input* _input_info, bool *_rlt)
{
	*_rlt = add_new_employee(treesafe_db_connection,&(_input_info->employ_basic_info),_input_info->comment) ;
//	reg_basic_info _info_add_to_login ;
//	_info_add_to_login.reg_id = _input_info->employ_basic_info.employee_id ;

}

//15.4
void add_employee_covert_result(add_employee_info* _info
	,char* _rlt , int* _rlt_len){
	memcpy(_rlt,_info,sizeof(add_employee_info));
	*_rlt_len = sizeof(add_employee_info);
}


//模块15的主函式
void add_employee_frame(const char* _cmd , int _cmd_len
	,char* _rlt , int* _rlt_len){
	//15.1
	//初始化模块
	add_employee_modle* _new_frame = init_add_employee_modle();
	//15.2
	//接受指令信息
	_new_frame->input_info = *add_employee_get_cmd(_cmd,_cmd_len);
	//15.3
	//...
	bool _db_rlt = false;
	add_employee_to_db(&_new_frame->input_info,&_db_rlt);

	//15.4
	add_employee_covert_result(&_new_frame->rlt_info,_rlt,_rlt_len);

	//释放模块
	release_add_employee_modle(_new_frame);
}