#include "stdafx.h"
#include "sys_apply.h"

//7.1
//��ʼ��
void apply_init_apply_custmor_info(apply_custmor_info* _init){
	_init->cust_age = 18;
	_init->cust_gender = male;
	strcpy(_init->cust_id,"000000000000000000");
	strcpy(_init->cust_name,"");
}

void apply_init_apply_loan_info(apply_loan_info* _init){
	//��ʼ����������
}

void apply_init_apply_input_info(apply_input_info* _init){
	apply_init_apply_custmor_info(&_init->input_basic_info);
	apply_init_apply_loan_info(&_init->input_loan_info);
}

void apply_init_apply_info(apply_info* _init){
	//��ʼ��������Ϣ
	init_sys_err(&_init->errInfo);
	//��ʼ��������Ϣ...
}

//7.2
//��ȡ������Ϣ
void apply_get_copy_command(char* _dest , char* _command,int _len){
	//��Ϣ����
	memcpy(_dest,_command,_len);
}

apply_input_info* apply_get_convert_input(char* _data){
	return (apply_input_info*)_data;
}

apply_input_info* apply_get_input_info(char* _command , int _len){
	//��Ϣ����
	char _info[sizeof(apply_input_info)];
	apply_get_copy_command(_info,_command,_len);
	return apply_get_convert_input(_info);
}

//7.3
void apply_query_cust_info(apply_custmor_info* _rlt){
	//��ѯ���
}