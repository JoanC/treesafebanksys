#pragma once

#include "sys_admin_employee_info.h"
#include "sys_error_compute.h"//������

//ģ��16
//ɾ����Ա��Ϣ

//�������Ϣ
//��ʵ���Ǹ���һ��idȥɾ���û�
struct delete_employee_input{
	char employee_id[EMPLOYEE_ID_LEN];//���֤����
};

//�����Ϣ
//��ʵ����һ���Ƿ�ɾ���ɹ��ı��
struct delete_employee_info{
	bool is_succ;//�Ƿ�ɾ���ɹ�
	sys_err
};