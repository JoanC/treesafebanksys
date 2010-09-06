#include "stdafx.h"
#include "is_user_has_score.h"


//模块28的实现文件

void init_is_user_has_score_input(is_user_has_score_input* _init){
	memset(_init->card_id,'\0',IS_USER_HAS_SCORE_ID_LEN);
}

void init_is_user_has_score_info(is_user_has_score_info* _init){
	init_sys_err(&_init->err_info);
	_init->user_has_score = false;
}

is_user_has_score_modle* init_is_user_has_score_modle(){
	is_user_has_score_modle* _new_modle
		= (is_user_has_score_modle*)malloc(sizeof(is_user_has_score_modle));
	//初始化
	init_is_user_has_score_input(&_new_modle->input_info);
	init_is_user_has_score_info(&_new_modle->rlt_info);
	return _new_modle;
}

void release_is_user_has_score_modle(is_user_has_score_modle* _release){
	free(_release);
}

//28.2
void is_user_has_score_copy_cmd(const char* _cmd,char* _dest,int _cmd_len){
	memcpy(_dest,_cmd,_cmd_len);
}

is_user_has_score_input* is_user_has_score_convert_cmd(char* _info){
	return (is_user_has_score_input*)_info;
}

is_user_has_score_input* is_user_has_score_get_cmp(const char* _cmd,int _cmd_len){
	//获得指令

}