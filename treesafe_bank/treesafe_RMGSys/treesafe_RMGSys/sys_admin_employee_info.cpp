#include "stdafx.h"
#include "sys_admin_employee_info.h"

void init_admin_employee_info(admin_employee_info* _init){
	//��ʼ����Ա����,Ĭ��Ϊ����Ա
	_init->employee_type = employ_type_operator;
	memset(_init->employee_id,'\0',EMPLOYEE_ID_LEN);//���֤�ų�ʼΪ��
	memset(_init->employee_name,'\0',EMPLOYEE_NAME_LEN);//��Ա������ʼΪ��
	_init->employee_gender = employee_male;//�Ա��ʼ������
	_init->employee_age = 0;//��ʼ������
	memset(_init->employee_addr,'\0',EMPLOYEE_NAME_LEN);//��ʼ����ַ,Ϊ��
	memset(_init->employee_tel,'\0',EMPLOYEE_TEL_LEN);//��ʼ���绰����
	memset(_init->employee_comment,'\0',EMPLOYEE_COMM_LEN);
	memset(_init->employee_email,'\0',EMPLOYEE_EMAIL_ADDR_LEN);
}