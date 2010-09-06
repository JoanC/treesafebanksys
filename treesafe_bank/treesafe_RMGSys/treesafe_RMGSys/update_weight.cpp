#include "stdafx.h"

#include "update_weight.h"

//模块25的实现文件

void init_update_weight_input(update_weight_input* _init){
DEBUG_UPDATE_WEIGHT("init_update_weight_input\n");
	//无初始化函数
}

void init_update_weight_info(update_weight_info* _init){
DEBUG_UPDATE_WEIGHT("init_update_weight_info\n");
	init_sys_err(&_init->err_info);
}


update_weight_modle* init_update_weight_info(){
DEBUG_UPDATE_WEIGHT("init_update_weight_info\n");
	update_weight_modle* _new_modle
		= (update_weight_modle*)malloc(sizeof(update_weight_modle));
	init_update_weight_input(&_new_modle->input_info);
	init_update_weight_info(&_new_modle->rlt_info);
	return _new_modle;
}

void release_update_weight_modle(update_weight_modle* _release){
DEBUG_UPDATE_WEIGHT("release_update_weight_modle\n");
	free(_release);
}

//25.2
void update_weight_copy_cmd(const char* _cmd,char* _dest,int _cmd_len){
DEBUG_UPDATE_WEIGHT("update_weight_copy_cmd\n");
	memcpy(_dest,_cmd,_cmd_len);
}

update_weight_input* update_weight_convert_cmd(char* _info){
DEBUG_UPDATE_WEIGHT("update_weight_convert_cmd\n");
	return (update_weight_input*)_info;
}

update_weight_input* update_weight_get_cmd(const char* _cmd , int _cmd_len){
DEBUG_UPDATE_WEIGHT("update_weight_get_cmd\n");
	char* _new_info = (char*)malloc(sizeof(update_weight_input));
	update_weight_copy_cmd(_cmd,_new_info,_cmd_len);
	return update_weight_convert_cmd(_new_info);
}

//25.3
//待实现
void update_weight_set_data(event_wgt* _new_data) 
{
	SaveEventWeight(_new_data) ;
}

void update_weight_convert_rlt(update_weight_info* _info,
	char* _rlt , int* _rlt_len){
DEBUG_UPDATE_WEIGHT("update_weight_convert_rlt\n");
		*_rlt_len = sizeof(update_weight_info);
		memcpy(_rlt,_info,*_rlt_len);
}

void update_weight_frame(const char* _cmd , int _cmd_len 
	, char* _rlt , int* _rlt_len){
DEBUG_UPDATE_WEIGHT("update_weight_frame\n");
		update_weight_modle* _frame
			= init_update_weight_info();
		_frame->input_info = *update_weight_get_cmd(_cmd,_cmd_len);
		//25.3
		//待sunni完成
		update_weight_convert_rlt(&_frame->rlt_info,
			_rlt,_rlt_len);
		release_update_weight_modle(_frame);
}