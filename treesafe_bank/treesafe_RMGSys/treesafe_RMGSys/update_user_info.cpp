#include "stdafx.h"
#include "update_user_info.h"


//30.1
void init_update_user_input(update_user_input* _init){
	memset(_init->new_addr,'\0',UPDATE_USER_ADDR_LEN);
	memset(_init->new_email,'\0',UPDATE_USER_EMAIL_LEN);
	memset(_init->new_tel,'\0',UPDATE_USER_TEL_LEN);
}

void init_update_user_info(update_user_info* _init){
	init_sys_err(&_init->err_info);
}

update_user_modle* init_update_user_modle(){
	update_user_modle* _new_modle
		= (update_user_modle*)malloc(sizeof(update_user_modle));
	init_update_user_input(&_new_modle->input_info);
	init_update_user_info(&_new_modle->rlt_info);
	return _new_modle;
}

void release_update_user_modle(update_user_modle* _release){
	free(_release);
}

//30.2
void update_user_copy_cmd(const char* _cmd,char* _dest
	,int _cmd_len){
		memcpy(_dest,_cmd,_cmd_len);
}

update_user_modle* update_user_convert_cmd(char* _info){
	//ÖÐÎÄ½âÂë
	update_user_modle* _new_info = (update_user_modle*)_info;
	DECODE_UTF7_TO_ASC(_new_info->input_info.new_addr);
	DECODE_UTF7_TO_ASC(_new_info->input_info.new_email);
	DECODE_UTF7_TO_ASC(_new_info->input_info.new_tel);
	return _new_info;
}

