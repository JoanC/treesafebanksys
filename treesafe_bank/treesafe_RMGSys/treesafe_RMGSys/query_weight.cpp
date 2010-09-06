#include "stdafx.h"
#include "query_weight.h"

//ģ��26��ʵ���ļ�
//26.1

void init_query_weight_input_info(query_weight_input_info* _init){
	//Ŀǰ����ṹ��Ϊ��
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
//sunni�����


//26.4
//ת�������Ϣ
void query_weight_convert_rlt(query_weight_info* _info
	,char* _rlt , int* _rlt_len){
		*_rlt_len = sizeof(query_weight_info);
		memcpy(_rlt,_info,*_rlt_len);
}


//����ʽ��Ϣ

void query_weight_frame(const char* _cmd , int _cmd_len
	,char* _rlt,int* _rlt_len){
		//��ʼ����ʽ
		query_weight_modle* _frame
			= (query_weight_modle*)malloc(sizeof(query_weight_modle));
		//��ȡ������Ϣ
		_frame->input_info = *query_weight_get_cmd(_cmd,_cmd_len);
		//����26.3ģ��
		//�д�sunniȥ���

		//����26.4ģ��
		query_weight_convert_rlt(&_frame->rlt_info,_rlt,_rlt_len);
		release_query_weight_modle(_frame);
}