#pragma once

#include "database_mgr.h"//���ݿ⴦��
#include "sys_error_compute.h"//������

//ģ��8
//�����ݿ��г�ȡһ��app_id
//Ŀ�����ڽ������Ա

struct research_exact_input_info{
	char research_work_id[EMPLOYEE_ID_LEN];//���Ա����
};

struct research_exact_info{
	char app_id[APPLY_ID];//���ص�һ������������id
	sys_err err_info;//������Ϣ
};

struct research_exact_modle{
	research_exact_input_info input_info;
	research_exact_info rlt_info;
};

/*************************************/ 
//ģ��8.1
//��Jiraiya���
//��ʼ�����ṹ��
//��ʼ�����ͷ�ģ��


//��ʼ������ṹ
void init_research_exact_input_info(research_exact_input_info* _init);

//��ʼ������ṹ
void init_research_exact_info(research_exact_info* _init);

//��ʼ������ģ��
research_exact_modle* init_research_exact_modle();

//�ͷ�ģ��
void release_research_exact_info(research_exact_modle* _release);

/*************************************/
//ģ��8.2
//�õ�ָ��
//��Jiraiya���

//����ָ��
void research_copy_cmd_data(const char* _cmd,char* _dest,int _cmd_len);

//ת��ָ��
//�������Ľ�������͵�ǿ��ת��
research_exact_input_info* research_convert_cmd(char* _info);

//��ȡָ��
//8.2����ʽ
research_exact_input_info* research_get_cmd(const char* _cmd,
	int _cmd_len);

/***************************************/
//ģ��8.3
//���ݿ����
//��sunni���
//�����ݿ��ж�ȡһ���µ�app_id
//��app_id��û����˹���,Ҳ���Ƕ�ӦֵΪfalse��

void research_exact_app_id(char* _new_app_id);


/*****************************************/
//ģ��8.4
//���Ͻ����Ϣ
//��Jiraiya���

void research_exact_convert_rlt(research_exact_info* _info,
	char* _rlt , int* _rlt_len);

//ģ��8����ʽ
void research_exact_frame(const char* _cmd ,int _cmd_len
	, char* _rlt , int* _rlt_len);
