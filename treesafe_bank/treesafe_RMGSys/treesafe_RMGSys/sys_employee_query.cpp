#include "stdafx.h"
#include "sys_employee_query.h"

//ģ��19��ʵ���ļ�


//19.1
//����������Ϣ
void init_employee_query_input_info(employee_query_input_info* _init){
	strcpy(_init->work_id,"");
}


void init_employee_query_info(employee_query_info* _init){
	//��ʼ����Ա��Ϣ
	init_admin_employee_info(&_init->query_data);
	//��ʼ��������Ϣ
	init_sys_err(&_init->err_info);
}

employee_query_modle* init_employee_query_modle(){
	//���ٲ���ʼ��ģ��
	employee_query_modle* _new_modle
		= (employee_query_modle*)malloc(sizeof(employee_query_modle));
	//��ʼ����������ģ��
	//��ʼ������ģ��
	init_employee_query_input_info(&_new_modle->input_info);
	//��ʼ�������Ϣ
	init_employee_query_info(&_new_modle->rlt_info);
	//���ؽ��ָ��
	return _new_modle;
}


//19.2

void employee_query_copy_cmd(const char* _cmd , char* _dest , int _cmd_len){
		//��������
		memcpy(_dest,_cmd,_cmd_len);
}

employee_query_input_info* employee_query_convert_cmd(char* _info){
	//������ת��Ϊ������Ϣ
	return (employee_query_input_info*)_info;
}

employee_query_input_info* employee_query_get_cmd(const char* _cmd
	,int _cmd_len){
		//19.2����ʽ
		//���ٿռ�
		char* _new_info = 
			(char*)malloc(_cmd_len);
		//����
		employee_query_copy_cmd(_cmd,_new_info,_cmd_len);
		//ת��
		return employee_query_convert_cmd(_new_info);
}

//19.3


//19.4
void employee_query_convert_rlt(employee_query_info* _info,
	char* _rlt , int* _rlt_len){
	   //ת�����
	*_rlt_len = sizeof(employee_query_info);

}

