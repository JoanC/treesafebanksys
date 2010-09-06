#include "stdafx.h"
#include "is_user_have_apply.h"

//模块27的实现文件

//27.1
void init_user_has_app_input(user_has_app_input* _init){
	memset(_init->card_id,'\0',USER_HAS_APP_ID_LEN);
}

void init_user_has_app_info(user_has_app_info* _init){
	init_sys_err(&_init->err_info);
	_init->user_has_app = false;
}

user_has_app_modle* init_user_has_app_modle(){
	user_has_app_modle* _new_modle
		= (user_has_app_modle*)malloc(sizeof(user_has_app_modle));
	init_user_has_app_input(&_new_modle->input_info);
	init_user_has_app_info(&_new_modle->rlt_info);
	return _new_modle;
}

void release_user_has_app_modle(user_has_app_modle* _release){
	free(_release);
}

//27.2
void user_has_app_copy_cmd(const char* _cmd , char* _dest , int _cmd_len){
	memcpy(_dest,_cmd,_cmd_len);
}

user_has_app_input* user_has_app_convert_cmd(char* _info){
	return (user_has_app_input*)_info;
}

user_has_app_input* user_has_app_get_cmd(const char* _cmd  , int _cmd_len){
		char* _info = (char*)malloc(_cmd_len);
		user_has_app_copy_cmd(_cmd,_info,_cmd_len);
		return user_has_app_convert_cmd(_info);
}

//27.3
//待sunni去完成


//27.4
void user_has_app_convert_rlt(user_has_app_info* _info
	,char* _rlt,int* _rlt_len){
		*_rlt_len = sizeof(user_has_app_info);
		memcpy(_rlt,_info,*_rlt_len);
}

void user_has_app_frame(const char* _cmd,int _cmd_len,
	char* _rlt , int* _rlt_len){
		//初始化模块信息
		user_has_app_modle* _frame
			= (user_has_app_modle*)malloc(sizeof(user_has_app_modle));
		_frame->input_info = *user_has_app_get_cmd(_cmd,_cmd_len);
		//27.3
		//有待sunni完成

		//27.4
		user_has_app_convert_rlt(&_frame->rlt_info,_rlt,_rlt_len);
		//释放
		release_user_has_app_modle(_frame);
}