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


