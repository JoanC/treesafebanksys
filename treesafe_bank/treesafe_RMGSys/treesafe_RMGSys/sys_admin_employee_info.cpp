#include "stdafx.h"
#include "sys_admin_employee_info.h"

void init_admin_employee_info(admin_employee_info* _init){
	//��ʼ����Ա����,Ĭ��Ϊ����Ա
	_init->employee_type = employ_type_operator;
	strcpy(_init->employee_id,"");//���֤�ų�ʼΪ��
	strcpy(_init->employee_name,"");//��Ա������ʼΪ��
	_init->employee_gender = employee_male;//�Ա��ʼ������
	_init->employee_age = 0;//��ʼ������
	strcpy(_init->employee_addr,"");//��ʼ����ַ,Ϊ��
}