#include "stdafx.h"
#include "sys_admin_delete_employee.h"

//ģ��16��ʵ���ļ�

//16.1

void init_delete_employee_input(delete_employee_input* _init){
	//��ʼ���������Ϣ
	//��ʼ�����֤��Ϊ��
	strcpy(_init->employee_id,"");
}

void init_delete_employee_info(delete_employee_info* _init){
	//��ʼ�������¼��Ϣ
	_init->is_succ = true;
	//��ʼ��������Ϣ
	init_sys_err(&_init->err_info);
}

delete_employee_modle* init_delete_employee_modle(){
	//��ʼ��ģ��16������
	//�����ڴ�
	delete_employee_modle* _new_modle
		= (delete_employee_modle*)malloc(sizeof(delete_employee_modle));
	//��ʼ���������ݿ�
	init_delete_employee_input(&_new_modle->input_info);
	init_delete_employee_info(&_new_modle->rlt_info);
	return _new_modle;
}


void release_delete_modle_employee(delete_employee_modle* _release){
	free(_release);
}

//16.2

delete_employee_input* delete_employee_get_cmd(const char* _cmd,int _cmd_len){
	//ɾ����Ա�Ľ�����������ʽ
	char* _info = (char*)malloc(_cmd_len);
	delete_employee_copy_cmd(_cmd,_info,_cmd_len);
	return delete_employee_convert_cmd(_info);
}

//����ָ��
void delete_employee_copy_cmd(const char* _cmd , char* _dest 
	, int _cmd_len){
	//��������
	memcpy(_dest,_cmd,_cmd_len);
}


delete_employee_input* delete_employee_convert_cmd(char* _info){
	//ǿ��ת��ָ��
	return (delete_employee_input*)_info;
}

//16.3
//...
void delete_employee_from_database(const char* _id , bool* _rlt)
{
	*_rlt = delete_employee(treesafe_db_connection,_id) ;
}


//16.4
//...
void delete_employee_convert_rlt(delete_employee_info* _info , char* _rlt , int* _rlt_len){
	
}


void delete_employee_frame(const char* _cmd , int _cmd_len , char* _rlt , int* _rlt_len){
    //16.1
	//��ʼ��ģ��
	delete_employee_modle* _frame
		=(delete_employee_modle*)malloc(sizeof(delete_employee_modle));
	//16.2
	//��ȡָ��
	_frame->input_info = *delete_employee_get_cmd(_cmd,_cmd_len);
	//16.3
	//...

	//16.4
	delete_employee_convert_rlt(&_frame->rlt_info,_rlt,_rlt_len);

	//�ͷ�ģ��
	release_delete_modle_employee(_frame);
}