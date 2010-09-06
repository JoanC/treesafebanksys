#include "stdafx.h"
#include "query_one_user_info.h"


//22.1
void init_query_user_one_info_input(query_user_one_info_input* _init){
	memset(_init->user_id,'\0',ONE_USER_CARD_ID_LEN);
}

void init_query_user_one_info_info(query_user_one_info_info* _init){
	init_sys_err(&_init->err_info);
	init_user_query_info(&_init->user_info);
}

query_user_one_info_modle* init_query_user_one_info_modle(){
	query_user_one_info_modle* _new_modle;
	_new_modle = 
		(query_user_one_info_modle*)malloc(sizeof(query_user_one_info_modle));
	init_query_user_one_info_input(&_new_modle->input);
	init_query_user_one_info_info(&_new_modle->rlt_info);
	return _new_modle;
}


//22.2
void query_user_one_copy_cmd(const char* _cmd , char* _dest , int _cmd_len){
	memcpy(_dest,_cmd,_cmd_len);
}

query_user_one_info_input* query_user_one_convert_cmd(char* _info){
	return (query_user_one_info_input*)_info;
}

query_user_one_info_input* query_user_one_get_cmd(const char* _cmd,int _cmd_len){
	char* _new_info = (char*)malloc(_cmd_len);
	query_user_one_copy_cmd(_cmd,_new_info,_cmd_len);
	return query_user_one_convert_cmd(_new_info);
}

//22.3
//sunniÍê³É
