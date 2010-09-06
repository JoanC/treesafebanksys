#include "stdafx.h"
#include "query_weight.h"

//模块26的实现文件
//26.1

void init_query_weight_input_info(query_weight_input_info* _init){
	//目前这个结构体为空
}

void init_query_weight_info(query_weight_info* _init){
	init_sys_err(&_init->err_info);
}

query_weight_modle* init_query_weight_modle(){
	query_weight_modle* _new_modle
		= (query_weight_modle*)malloc(sizeof(query_weight_modle));
	init_query_weight_input_info(&_new_modle->input_info);
	init_query_weight_info(&_new_modle->rlt_info);
	return _new_modle;
}

void release_query_weight_modle(query_weight_modle* _release){
	free(_release);
}

//26.2
void query_weight_copy_cmd(const char* _cmd , char* _dest 
	, int _cmd_len){
		memcpy(_dest,_cmd,_cmd_len);
}

query_weight_input_info* query_weight_convert_cmd(char* _info){
	return (query_weight_input_info*)_info;
}

query_weight_input_info* query_weight_get_cmd(const char* _cmd ,
	int _cmd_len){
		char* _info = (char*)malloc(_cmd_len);
		query_weight_copy_cmd(_cmd,_info,_cmd_len);
		return query_weight_convert_cmd(_info);
}

//26.3
//sunni待完成


//26.4
//转化结果信息
void query_weight_convert_rlt(query_weight_info* _info
	,char* _rlt , int* _rlt_len){
		*_rlt_len = sizeof(query_weight_info);
		memcpy(_rlt,_info,*_rlt_len);
}


//主函式信息

void query_weight_frame(const char* _cmd , int _cmd_len
	,char* _rlt,int* _rlt_len){
		//初始化函式
		query_weight_modle* _frame
			= (query_weight_modle*)malloc(sizeof(query_weight_modle));
		//读取输入信息
		_frame->input_info = *query_weight_get_cmd(_cmd,_cmd_len);
		//调用26.3模块
		//有待sunni去玩陈

		//调用26.4模块
		query_weight_convert_rlt(&_frame->rlt_info,_rlt,_rlt_len);
		release_query_weight_modle(_frame);
}