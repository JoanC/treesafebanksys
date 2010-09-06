#include "stdafx.h"
#include "update_pwd.h"

void init_update_pwd_input(update_pwd_input* _init){
	memset(_init->user_id,'\0',UPDATE_PWD_USER_NAME_ID);
	memset(_init->new_user_pwd,'\0',UPDATE_PWD_LEN);
}

void init_update_pwd_info(update_pwd_info* _init){
	init_sys_err(&_init->err_info);
}

update_pwd_modle* init_update_pwd_modle(){
	update_pwd_modle* _new_modle
		= (update_pwd_modle*)malloc(sizeof(update_pwd_modle));
	init_update_pwd_input(&_new_modle->input_info);
	init_update_pwd_info(&_new_modle->rlt_info);
	return _new_modle;
}

void release_update_pwd_modle(update_pwd_modle* _init){
	free(_init);
}

//29.2
void update_pwd_copy_cmd(const char* _cmd , char* _dest ,int _cmd_len){
	memcpy(_dest,_cmd,_cmd_len);
}

update_pwd_input* update_pwd_convert_cmd(char* _info){
	return (update_pwd_input*)_info;
}

update_pwd_input* update_pwd_get_cmd(const char* _cmd , int _cmd_len){
	char* _info = (char*)malloc(_cmd_len);
	update_pwd_copy_cmd(_cmd,_info,_cmd_len);
	return (update_pwd_input*)_info;
}

//29.3
//...


//29.4
void update_pwd_convert_rlt(update_pwd_info* _info,
	char* _rlt , int* _rlt_len){
		*_rlt_len = sizeof(update_pwd_info);
		memcpy(_rlt,_info,*_rlt_len);
}

//Ä£¿é29
void update_pwd_frame(const char* _cmd , int _cmd_len ,
	char* _rlt , int* _rlt_len){
		update_pwd_modle* _frame
			= (update_pwd_modle*)malloc(sizeof(update_pwd_modle));
		_frame->input_info = *update_pwd_get_cmd(_cmd,_cmd_len);
		//29.3
		//...

		update_pwd_convert_rlt(&_frame->rlt_info,_rlt,_rlt_len);
		release_update_pwd_modle(_frame);
}