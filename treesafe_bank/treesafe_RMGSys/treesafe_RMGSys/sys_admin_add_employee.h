#pragma once

#include "database_mgr.h"//���ݿ⴦��ʽ
#include "sys_error_compute.h"//������

//ģ��15
//����Ա���� -- ��ӹ�Ա
//�������һ����Ա

#include "sys_admin_employee_info.h"


#define ADD_EMPLOYEE_COMMENT_LEN 51


//��ӹ�Աʱ�������Ϣ
struct add_employee_input{
	admin_employee_info employ_basic_info;
	char comment[ADD_EMPLOYEE_COMMENT_LEN];
};


//��ӹ�Ա�Ľ����Ϣ
struct add_employee_info{
	bool is_succ;//����Ƿ�ɹ�
	sys_err err_info;//������Ϣ
};

struct add_employee_modle{
	add_employee_input input_info;//������Ϣ
	add_employee_info rlt_info;//�����¼��Ϣ
};


/*****************************************/
//ģ��15.1
//���ݽṹ��ʼ�����ͷ�
//Jiraiya���

//��ʼ���������Ϣ
void init_add_employee_input(add_employee_input* _init);

//��ʼ����ӹ�Ա�Ľ����¼��Ϣ
void init_add_employee_info(add_employee_info* _init);

//��ʼ����ӹ�Ա����ģ��
add_employee_modle* init_add_employee_modle();

//�ͷ�ģ��
void release_add_employee_modle(add_employee_modle* _release);

/******************************************/
//ģ��15.2
//����ָ����Ϣ
//�����ܵ�ָ��ת�����������Ϣ
//Jiraiya���

//����ָ����Ϣ
void add_employee_copy_cmd(const char* _cmd , char* _dest , int _cmd_len);

//ת��ָ��,����ת��Ϊ�������Ϣ
add_employee_input* add_employee_convert_cmd(char* _info);

//15.2�ܺ�ʽ
//ת�����Ҹ���ָ��
add_employee_input* add_employee_get_cmd(const char* _cmd,int _cmd_len);

/********************************************/
//15.3
//sunni���
//���ݿ����
//��������Ϣ������������Ա���*��¼����(�������ű�!!)
void add_employee_to_db(add_employee_input* _input_info);

/*********************************************/
//15.4
//��Jiraiya���
//���Ͻ����Ϣ,����ת��Ϊ�ַ���
void add_employee_covert_result(add_employee_info* _info
	,char* _rlt , int* _rlt_len);

/***********************************************/
//ģ��15����ʽ
void add_employee_frame(const char* _cmd , int _cmd_len
	,char* _rlt , int* _rlt_len);
