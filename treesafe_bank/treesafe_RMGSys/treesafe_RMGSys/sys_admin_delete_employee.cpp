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