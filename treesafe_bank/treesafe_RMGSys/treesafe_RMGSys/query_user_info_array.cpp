#include "stdafx.h"
#include "query_user_info.h"
#include "query_user_info_array.h"

//20.1
//user_query_arr_modle* init_user_query_arr_modle(){

//}

void init_user_querry_arr_info(user_querry_arr_info* _init){
	init_sys_err(&_init->err_info);
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