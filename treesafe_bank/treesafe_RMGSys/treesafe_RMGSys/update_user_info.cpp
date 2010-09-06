#include "stdafx.h"
#include "update_user_info.h"

extern _ConnectionPtr* treesafe_db_connection ; 
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

update_user_input* update_user_convert_cmd(char* _info){
	//中文解码
	update_user_input* _new_info = (update_user_input*)_info;
	DECODE_UTF7_TO_ASC(_new_info->new_addr);
	DECODE_UTF7_TO_ASC(_new_info->new_email);
	DECODE_UTF7_TO_ASC(_new_info->new_tel);
	return _new_info;
}

update_user_input* update_user_get_cmd(const char* _cmd
	,int _cmd_len){
		char* _info = (char*)malloc(_cmd_len);
		update_user_copy_cmd(_cmd,_info,_cmd_len);
		return update_user_convert_cmd(_info);
}

//30.3
//...sunni完成
void update_user_set_data(char* _card_id , update_user_input* _input)
{
	Update_user_info(treesafe_db_connection,_card_id,_input->new_addr,_input->new_email,_input->new_tel) ;
}

//30.4
// 转化数据
void update_user_convert_rlt(update_user_info* _info,char* _rlt,int* _rlt_len){
	*_rlt_len = sizeof(update_user_info);
	memcpy(_rlt,_info,*_rlt_len);
}

void update_user_frame(const char* _cmd , int _cmd_len , char* _rlt,int* _rlt_len){
	update_user_modle* _frame
		= init_update_user_modle();
	_frame->input_info = *update_user_get_cmd(_cmd,_cmd_len);
	//30.3
	//sunni 完成

	//30.4
	update_user_convert_rlt(&_frame->rlt_info,_rlt,_rlt_len);
	//30.5
	release_update_user_modle(_frame);
}