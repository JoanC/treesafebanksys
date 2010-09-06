#include "stdafx.h"
#include "query_score.h"


//21.1

//初始化输入信息
void init_query_score_input_info(query_score_input_info* _init){
	memcpy(_init->card_id,'\0',QUERY_SCORE_CARD_ID_LEN);
}

void init_query_score_info(query_score_info* _init){
	init_sys_err(&_init->err_info);
}

query_score_modle* init_query_score_modle(){
	//分配内存
	query_score_modle* _new_modle = 
		(query_score_modle*)malloc(sizeof(query_score_modle));
	//初始化数据
	init_query_score_input_info(&_new_modle->input_info);
	init_query_score_info(&_new_modle->rlt_info);
	return _new_modle;
}

void release_query_score_modle(query_score_modle* _release){
	free(_release);
}

//21.2
void query_score_copy_cmd(const char* _cmd,char* _dest,int _cmd_len){
	memcpy(_dest,_cmd,_cmd_len);
}


query_score_input_info* query_score_convert_cmd(char* _info){
	return (query_score_input_info*)_info;
}

query_score_input_info* query_score_get_cmd(const char* _cmd,int _cmd_len){
	char* _new_info = (char*)malloc(_cmd_len);
	query_score_copy_cmd(_cmd,_new_info,_cmd_len);
	return query_score_convert_cmd(_new_info);
}

//21.3


//21.4
void query_score_rlt_convert(query_score_info* _info , char* _rlt , int* _rlt_len){
	*_rlt_len = sizeof(query_score_info);
	memcpy(_rlt,_info,*_rlt_len);
}