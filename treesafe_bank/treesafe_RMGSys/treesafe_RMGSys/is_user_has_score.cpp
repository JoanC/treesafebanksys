#include "stdafx.h"
#include "is_user_has_score.h"


//ģ��28��ʵ���ļ�

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
	//��ʼ��
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

is_user_has_score_input* is_user_has_score_get_cmd(const char* _cmd,int _cmd_len){
	//���ָ��
	char* _info = (char*)malloc(_cmd_len);
	is_user_has_score_copy_cmd(_cmd,_info,_cmd_len);
	return is_user_has_score_convert_cmd(_info);
}


//ģ��28.3
//��sunni���
void is_user_has_score_get_data(char* _id , bool* _rlt)
{

}


//ģ��28.4
void is_user_has_score_convert_rlt(is_user_has_score_info* _info
	,char* _rlt,int* _rlt_len){
		*_rlt_len = sizeof(is_user_has_score_info);
		memcpy(_rlt,_info,*_rlt_len);
}

//ģ��28����ʽ
void is_user_has_score_frame(const char* _cmd , int _cmd_len
	,char* _rlt,int* _rlt_len){
		//��ʼ��
		is_user_has_score_modle* _frame
			= init_is_user_has_score_modle();
		//��ȡָ��
		_frame->input_info = *is_user_has_score_get_cmd(_cmd,_cmd_len);
		//28.3
		//...

		is_user_has_score_convert_rlt(&_frame->rlt_info,_rlt,_rlt_len);
		//�ͷ�ģ��
		release_is_user_has_score_modle(_frame);
}