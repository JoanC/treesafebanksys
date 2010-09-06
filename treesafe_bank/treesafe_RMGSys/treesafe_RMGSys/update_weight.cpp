#include "stdafx.h"

#include "update_weight.h"

//模块25的实现文件

void init_update_weight_input(update_weight_input* _init){
	//无初始化函数
}

void init_update_weight_info(update_weight_info* _init){
	init_sys_err(&_init->err_info);
}


update_weight_modle* init_update_weight_info(){
	update_weight_modle* _new_modle
		= (update_weight_modle*)malloc(sizeof(update_weight_modle));
	init_update_weight_input(&_new_modle->input_info);
	init_update_weight_info(&_new_modle->rlt_info);
	return _new_modle;
}

void release_update_weight_modle(update_weight_modle* _release){
	free(_release);
}

//25.2
void update_weight_copy_cmd(const char* _cmd,char* _dest,int _cmd_len){
	memcpy(_dest,_cmd,_cmd_len);
}

update_weight_input* update_weight_convert_cmd(char* _info){
	return (update_weight_input*)_info;
}

update_weight_input* update_weight_get_cmd(const char* _cmd , int _cmd_len){
	char* _new_info = (char*)malloc(sizeof(update_weight_input));
	update_weight_copy_cmd(_cmd,_new_info,_cmd_len);
	return update_weight_convert_cmd(_new_info);
}

//25.3
//待实现

void update_weight_convert_rlt(update_weight_info* _info,
	char* _rlt , int* _rlt_len){
		*_rlt_len = sizeof(update_weight_info);
		memcpy(_rlt,_info,*_rlt_len);
}

void update_weight_frame(const char* _cmd , int _cmd_len 
	, char* _rlt , int* _rlt_len){
		update_weight_modle* _frame
			= init_update_weight_info();

}