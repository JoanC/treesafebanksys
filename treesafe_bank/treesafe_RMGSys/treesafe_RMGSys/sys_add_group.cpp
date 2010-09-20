#include "stdafx.h"
#include "sys_add_group.h"
extern _ConnectionPtr* treesafe_db_connection ; 
/*
//31.1
void init_add_group_input(add_group_input* _init){
	init_group_info(&_init->group);
}

void init_add_group_info(add_group_info* _init){
	init_sys_err(&_init->err_info);
	_init->is_add_group_succ = true;
}

add_group_modle* init_add_group_modle(){
	//分配内存
	add_group_modle* _new
		= (add_group_modle*)malloc(sizeof(add_group_modle));
	//初始化信息
	init_add_group_input(&_new->input_info);
	init_add_group_info(&_new->rlt_info);
	return _new;
}

void add_group_release(add_group_modle* _release){
	free(_release);
}

//31.2
void add_group_copy_cmd(const char* _cmd,char* _info,int _cmd_len){
	memcpy(_info,_cmd,_cmd_len);
}

add_group_input* add_group_convert_cmd(char* _info){
	return (add_group_input*)_info;
}

add_group_input* add_group_get_cmd(const char* _cmd,int _cmd_len){
	char* _info = (char*)malloc(_cmd_len);
	add_group_copy_cmd(_cmd,_info,_cmd_len);
	return add_group_convert_cmd(_info);
}

*/
//31.3
bool add_group_db(group_info* _info)
{
	char buff_gid[GROUP_ID_LEN] ;

	return Get_max_group_id(treesafe_db_connection,buff_gid) 
           && IncreaseCharStr(buff_gid,GROUP_ID_LEN - 1) 
		   && Insert_group_info(treesafe_db_connection,_info,buff_gid) ;
}
	/*
//31.4
void add_group_generate_rlt(add_group_info* _info
	,char* _rlt,int* _rlt_len){
	*_rlt_len = sizeof(add_group_info);//获取长度
	memcpy(_rlt,_info,*_rlt_len);//复制信息
}

//31.5
void add_group_frame(const char* _cmd,int _cmd_len
	,char* _rlt,int* _rlt_len){
	//31.1
	add_group_modle* _frame
		= init_add_group_modle();
	//31.2
	_frame->input_info = *add_group_get_cmd(_cmd,_cmd_len);
	//31.3
	//...

	//31.4
	add_group_generate_rlt(&_frame->rlt_info,_rlt,_rlt_len);
	//释放模块
	add_group_release(_frame);
}
*/