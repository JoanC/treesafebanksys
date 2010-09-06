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
bool query_score_db(char* _cust_id,credit_scores* _db_rlt)
{
	return  Get_credit_scores(treesafe_db_connection,_db_rlt,_cust_id) ;
}

//21.4
void query_score_rlt_convert(query_score_info* _info , char* _rlt , int* _rlt_len){
	*_rlt_len = sizeof(query_score_info);
	memcpy(_rlt,_info,*_rlt_len);
}

//模块21主函式
void query_score_frame(const char* _cmd , int _cmd_len , char* _rlt , int* _rlt_len){
	//初始化模块
	query_score_modle* _modle
		= init_query_score_modle();
	//21.2
	//输入信息的获取
	_modle->input_info = *query_score_get_cmd(_cmd,_cmd_len);
	//21.3
	//数据库查询
	//query_score_db();
	//21.4
	//转化结果
	query_score_rlt_convert(&_modle->rlt_info,_rlt,_rlt_len);
	//21.1
	//释放模块
	release_query_score_modle(_modle);
}