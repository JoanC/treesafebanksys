#include "stdafx.h"
#include "query_user_info.h"
#include "query_user_info_array.h"
extern _ConnectionPtr *treesafe_db_connection ; 

//模块20的实现文件

//20.1
void init_user_querry_arr_info(user_query_arr_info* _init){
	//init_sys_err(&_init->err_info);
	_init->query_arr_info.user_num = 0;
	_init->query_arr_info.user_array = NULL;
}

user_query_arr_modle* init_user_query_arr_modle(){
	user_query_arr_modle* _new_modle
		= (user_query_arr_modle*)malloc(sizeof(user_query_arr_modle));
	init_user_querry_arr_info(&_new_modle->rlt_info);
	return _new_modle;
}

void release_user_query_arr_modle(user_query_arr_modle* _release){
	//先释放数组
	if(_release->rlt_info.query_arr_info.user_num == 0) return;
	if(_release->rlt_info.query_arr_info.user_array == NULL) return;
	//再释放整体模块
	free(_release);
}

//20.2
void user_query_copy_cmd(const char* _cmd , char* _dest, int _cmd_len){
	memcpy(_dest,_cmd,_cmd_len);
}

user_query_arr_input* user_query_convert_cmd(char* _info){
	return (user_query_arr_input*)_info;
}

user_query_arr_input* query_user_arr_get_cmd(const char* _cmd,int _cmd_len){
	char* _new_info = (char*)malloc(_cmd_len);
	user_query_copy_cmd(_cmd,_new_info,_cmd_len);
	return user_query_convert_cmd(_new_info);
}

//20.3

bool user_query_arr_count(int* _count) 
{
	return Find_how_many_passed_user(treesafe_db_connection,_count) ;
}

//20.4
bool user_query_arr(user_query_array_info* user_array,int* _arr_size) 
{
	return Find_all_passed_user(treesafe_db_connection,user_array,*_arr_size) ;
}

//20.5
void user_query_arr_convert_rlt(user_query_arr_info* _info,char* _rlt,int* _rlt_len){
	//先要去计算需要传输的数据的字节长度
	*_rlt_len
		= sizeof(user_query_arr_info) 
		+ _info->query_arr_info.user_num * sizeof(user_query_info);
	//复制结果信息
	memcpy(_rlt,_info,*_rlt_len);
}

//20主函式
void user_query_array_frame(const char* _cmd,int _cmd_len,char* _rlt,int* _rlt_len){
	//20.1
	//初始化主模块
	user_query_arr_modle* _frame = 
		init_user_query_arr_modle();
	//获取输入指令,20.2
	_frame->input_info
		= *query_user_arr_get_cmd(_cmd,_cmd_len);
	//20.3
	bool _query_num_rlt = 
		user_query_arr_count(&_frame->rlt_info.query_arr_info.user_num);
	//为数组申请内存
	init_user_query_array_info(_frame->rlt_info.query_arr_info.user_num
		,&_frame->rlt_info.query_arr_info);
	//20.4
	if(_query_num_rlt) user_query_arr(&_frame->rlt_info.query_arr_info
		,&_frame->rlt_info.query_arr_info.user_num);
	user_query_arr_convert_rlt(&_frame->rlt_info,_rlt,_rlt_len);
}
