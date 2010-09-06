#include "stdafx.h"
#include "employee_query_array.h"

//模块23实现文件
extern _ConnectionPtr* treesafe_db_connection ; 

//23.1
void init_query_employee_array_input(query_employee_array_input* _init){
DEBUG_QUERY_ARRAY_PRINT("init_query_employee_array_input");
	//no member now
}

void init_query_employee_array_info(query_employee_array_info* _init){
DEBUG_QUERY_ARRAY_PRINT("init_query_employee_array_info");
	_init->num = 0;
	for(int i = 0 ; i < MAX_EMPLOYEE_NUM ; ++i){
		init_admin_employee_info(&_init->employee_arr[i]);
	}
}

query_employee_modle* init_query_employee_modle(){
DEBUG_QUERY_ARRAY_PRINT("init_query_employee_modle");
	query_employee_modle* _new_modle
		= (query_employee_modle*)malloc(sizeof(query_employee_modle));
	init_query_employee_array_input(&_new_modle->input);
	init_query_employee_array_info(&_new_modle->rlt_info);
	return _new_modle;
}

void release_query_employee_arr_modle(query_employee_modle* _release){
DEBUG_QUERY_ARRAY_PRINT("release_query_employee_arr_modle");
	free(_release);
}

//23.2
void query_employee_arr_copy_cmd(const char* _cmd,
	char* _dest , int _cmd_len){
DEBUG_QUERY_ARRAY_PRINT("query_employee_arr_copy_cmd");
		memcpy(_dest,_cmd,_cmd_len);
}

query_employee_array_input* query_employee_arr_convert_cmd(char* _info){
DEBUG_QUERY_ARRAY_PRINT("query_employee_arr_convert_cmd");
	return (query_employee_array_input*)_info;
}

query_employee_array_input* query_employee_arr_get_cmd(const char* _cmd
	,int _cmd_len){
DEBUG_QUERY_ARRAY_PRINT("query_employee_arr_get_cmd");
		char* _new_info = (char*)malloc(_cmd_len);
		query_employee_arr_copy_cmd(_cmd,_new_info,_cmd_len);
		return query_employee_arr_convert_cmd(_new_info);
}

//23.3
bool query_employee_arr_get_num(int* _count)
{
	DEBUG_QUERY_ARRAY_PRINT("query_employee_arr_get_num");
	return  Find_how_many_employee(treesafe_db_connection,_count) ;
}
//待sunni完成
bool query_employee_arr_get_data(admin_employee_info* _arr,int _Count)
{
	DEBUG_QUERY_ARRAY_PRINT("query_employee_arr_get_data");
	return Get_all_emplo_info(treesafe_db_connection,_arr,_Count) ;
}

//23.4

void query_employee_arr_convert_rlt(query_employee_array_info* _info,
	char* _rlt , int* _rlt_len){
DEBUG_QUERY_ARRAY_PRINT("query_employee_arr_convert_rlt");
		*_rlt_len = sizeof(query_employee_array_info);
		memcpy(_rlt,_info,*_rlt_len);
}


void query_employee_arr_frame(const char* _cmd , int _cmd_len,
	char* _rlt , int* _rlt_len){
DEBUG_QUERY_ARRAY_PRINT("query_employee_arr_frame");
		query_employee_modle* _frame
			= (query_employee_modle*)malloc(sizeof(query_employee_modle));
		_frame->input = *query_employee_arr_get_cmd(_cmd,_cmd_len);
		//调用23.3模块

		//23.4
		query_employee_arr_convert_rlt(&_frame->rlt_info,
			_rlt,_rlt_len);
		release_query_employee_arr_modle(_frame);
}

