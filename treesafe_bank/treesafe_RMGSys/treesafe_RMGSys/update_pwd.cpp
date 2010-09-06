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
