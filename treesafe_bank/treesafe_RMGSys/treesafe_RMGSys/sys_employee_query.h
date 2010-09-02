#pragma once

#include "database_mgr.h"//���ݿ����
#include "sys_error_compute.h"//������

//ģ��19
//�����Ĺ�Ա��Ϣ��ѯ
//ͨ������,��ѯһ����Ա�ľ�����Ϣ

//��Ա��Ϣ��ѯ����
typedef admin_employee_info employee_query_data;

//������Ϣ
struct employee_query_input_info{
	char work_id[EMPLOYEE_WORK_ID_LEN];//����Ĺ�Ա����
};

//�����͵Ľ����Ϣ
struct employee_query_info{
	employee_query_data query_data;//���ݿ��ѯ���
	//ϵͳ����
	sys_err err_info;
};

//ģ��19����ģ��ṹ��
struct employee_query_modle{
	//������Ϣ
	employee_query_input_info input_info;
	//��ѯ�����еõ��Ľ����Ϣ
	employee_query_info rlt_info;
};

/***************************************/
//19.1
//��ʼ�����ͷ�ģ�鼰������

void init_employee_query_input_info(employee_query_input_info* _init);

void init_employee_query_info(employee_query_info* _init);

employee_query_modle* init_employee_query_modle();

/*****************************************/
//19.2
//���Ʋ�ת��ָ��


//��������
void employee_query_copy_cmd(const char* _cmd , int _cmd_len,
	char* _rlt , int* _rlt_len);

//����ת��
//��ָ���е����ݶ��뵽������Ϣ��
employee_query_input_info* employee_query_convert_cmd(char* _info);





