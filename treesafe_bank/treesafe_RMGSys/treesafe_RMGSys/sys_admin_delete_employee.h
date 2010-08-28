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
	sys_err err_info;//������Ϣ
};

//ģ��16������
struct delete_employee_modle{
	delete_employee_input input_info;
	delete_employee_info rlt_info;
};

/*******************************************/
//ģ��16.1
//��ʼ�����ͷ�ģ��
//��Jiraiya���


//��ʼ���������Ϣ
void init_delete_employee_input(delete_employee_input* _init);

//��ʼ�������¼��Ϣ
void init_delete_employee_info(delete_employee_info* _init);

//��ʼ��ģ��16������
delete_employee_modle* init_delete_employee_modle();

/*********************************************/
//ģ��16.2
//����ָ��
//Jiraiya���

//16.2����ʽ
delete_employee_input* delete_employee_get_cmd(const char* _cmd,int _cmd_len);

//��������
void delete_employee_copy_cmd(const char* _cmd , char* _dest 
	, int _cmd_len);

//ת��ָ��
delete_employee_input* delete_employee_convert_cmd(char* _info);

/*********************************************/
//ģ��16.3
//���ݿ����
//sunni���

void delete_employee_from_database(const char* _id , bool* _rlt);

/*********************************************/
//ģ��16.4�ܽ�����Ϣ
//�����ת�����ַ�����Ϣ

void delete_employee_convert_rlt(delete_employee_info* _info , char* _rlt , int* _rlt_len);

/**********************************************/
//��Ϣɾ��ģ��
//ģ��16������ʽ
void delete_employee_frame(const char* _cmd , int _cmd_len , char* _rlt , int* _rlt_len);
