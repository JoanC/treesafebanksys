#include "stdafx.h"
#include "sys_query_group.h"
extern _ConnectionPtr* treesafe_db_connection ; 

//32.1
void init_query_group_input(query_group_input* _init){
	//空初始化
	return;
}

void init_query_group_info(query_group_info* _init){
	//初始化分组数组信息
	init_sys_err(&_init->err_info);
	_init->group_num = 0;
	for(int i = 0 ; i < MAX_GROUP_INFO ; ++i){
		init_group_info(&_init->group[i]);
	}
}

query_group_modle* init_query_group_modle(){
	//初始化模块信息
	query_group_modle* _new
		= (query_group_modle*)malloc(sizeof(query_group_modle));
	init_query_group_input(&_new->input_info);
	init_query_group_info(&_new->rlt_info);
    return _new;
}

void release_query_group_modle(query_group_modle* _release){
	free(_release);
}

//32.2
void query_group_copy_cmd(const char* _cmd
	,char* _info,int _cmd_len){
		memcpy(_info,_cmd,_cmd_len);//复制
}

query_group_input* query_convert_cmd(char* _info){
	return (query_group_input*)_info;
}

query_group_input* query_get_cmd(const char* _cmd,int _cmd_len){
	//复制指令
	char* _info = (char*)malloc(_cmd_len);
	query_group_copy_cmd(_cmd,_info,_cmd_len);
	return query_convert_cmd(_info);
}

//32.3

bool query_group_db(int *_rlt_num,group_info* _query_data)
{
	return Find_how_many_group(treesafe_db_connection,_rlt_num) 
		  && Get_all_group_info( treesafe_db_connection,_query_data,_rlt_num) ;
}

//32.4
void query_group_generate_rlt(query_group_info* _info
	,char* _rlt,int* _rlt_len){
		*_rlt_len = sizeof(query_group_info);
		memcpy(_rlt,_info,*_rlt_len);
}

//32主函式
void query_group_frame(const char* _cmd,int _cmd_len,
	char* _rlt,int* _rlt_len){
		//32.1
		//模块32的主模块
		query_group_modle* _frame
			= init_query_group_modle();
		//32.2
		_frame->input_info = *query_get_cmd(_cmd,_cmd_len);
		//32.3
		query_group_db(&_frame->rlt_info.group_num,_frame->rlt_info.group);
		//32.4
		query_group_generate_rlt(&_frame->rlt_info,_rlt,_rlt_len);
		//释放模块
		release_query_group_modle(_frame);
}