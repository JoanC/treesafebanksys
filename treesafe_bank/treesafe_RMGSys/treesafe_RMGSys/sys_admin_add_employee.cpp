#include "stdafx.h"
#include "sys_admin_add_employee.h"

//ģ��15 -- ����Ա��ӹ�Աģ���ʵ��

//15.1
//��ʼ��ģ��

void init_add_employee_input(add_employee_input* _init){
	//��ʼ��������Ϣ
	init_admin_employee_info(&_init->employ_basic_info);
	strcpy(_init->comment,"");//��ʼ��ע����Ϣ
}

void init_add_employee_info(add_employee_info* _init){
	//��ʼ����ӹ�Ա�Ľ����¼��Ϣ
	//��ʼ���ѳɹ�
	//��������ʱ�ŻὫ���ֵ��Ϊtrue
	_init->is_succ = true;
	//��ʼ��������Ϣ
	init_sys_err(&_init->err_info);
}

add_employee_modle* init_add_employee_modle(){
	//��ʼ����ӹ�Ա����ģ��
	//�����ڴ�..
	add_employee_modle* _new_modle = 
		(add_employee_modle*)malloc(sizeof(add_employee_modle));
	//��ʼ��ģ��
	//������Ϣ��ʼ��
	init_add_employee_input(&_new_modle->input_info);
	//�����¼��Ϣ
	init_add_employee_info(&_new_modle->rlt_info);
	return _new_modle;
}


//15.2

void add_employee_copy_cmd(const char* _cmd , char* _dest , int _cmd_len){
	//����������Ϣ
	memcpy(_dest,_cmd,_cmd_len);
}

add_employee_input* add_employee_convert_cmd(char* _info){
	//ת�������Ϊ��������
	return (add_employee_input*)_info;
}

add_employee_input* add_employee_get_cmd(const char* _cmd,
	char* _dest , int _cmd_len){
	//ת�����Ҹ���ָ��
	char* _info = (char*)malloc;

}