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
    update_weight_input* _new_info = (update_weight_input*)_info;
	return _new_info;
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

void convet_from_int_to_float(wgt_int* _int ,event_wgt* _float){
	_float->auditor_edit = (float)_int->auditor_edit / (float)100;
	_float->depos = (float)_int->depos / (float)100;
	_float->edu = (float)_int->edu / (float)100;
	_float->fixed_assets_be_pledged = (float)_int->fixed_assets_be_pledged / (float)100;
	_float->id_type = (float)_int->id_type / (float)100;
	_float->income = (float)_int->income / (float)100;
	_float->loan_record = (float)_int->loan_record / (float)100;
	_float->marriage = (float)_int->marriage / (float)100;
	_float->repayment = (float)_int->repayment / (float)100;
	_float->social_record = (float)_int->social_record / (float)100;
}

void update_weight_frame(const char* _cmd , int _cmd_len 
	, char* _rlt , int* _rlt_len){
DEBUG_UPDATE_WEIGHT("update_weight_frame\n");
		update_weight_modle* _frame
			= init_update_weight_info();
		_frame->input_info = *update_weight_get_cmd(_cmd,_cmd_len);
		
		convet_from_int_to_float(&_frame->input_info.new_wgt,&_frame->new_wgt);
		//25.3
		update_weight_set_data(&_frame->new_wgt);

		update_weight_convert_rlt(&_frame->rlt_info,
			_rlt,_rlt_len);
		release_update_weight_modle(_frame);
}