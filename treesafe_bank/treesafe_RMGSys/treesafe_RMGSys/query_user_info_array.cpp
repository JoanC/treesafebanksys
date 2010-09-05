#include "stdafx.h"
#include "query_user_info.h"
#include "query_user_info_array.h"
extern _ConnectionPtr *treesafe_db_connection ; 
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
	//���ͷ�����
	if(_release->rlt_info.query_arr_info.user_num == 0) return;
	if(_release->rlt_info.query_arr_info.user_array == NULL) return;
	//���ͷ�����ģ��
	free(_release);
}
bool user_query_arr_count(int* _count) 
{
	return Find_how_many_passed_user(treesafe_db_connection,_count) ;
}
bool user_query_arr(user_query_array_info* user_array,int* _arr_size) 
{
	return Find_all_passed_user(treesafe_db_connection,user_array,*_arr_size) ;
}

//20.5
void user_query_arr(user_query_array_info* _info,char* _rlt,int* _rlt_len){
	//��Ҫȥ������Ҫ��������ݵ��ֽڳ���
	*_rlt_len
		= sizeof(user_query_array_info) 
		+ _info->user_num * sizeof(user_query_info);
	//���ƽ����Ϣ
	memcpy(_rlt,_info,*_rlt_len);
}

//20����ʽ
void user_query_array_frame(const char* _cmd,int _cmd_len,char* _rlt,int _rlt_len){
	//20.1
	//��ʼ����ģ��
	user_query_arr_modle* _frame = 
		init_user_query_arr_modle();
}
