#pragma once

#include "sys_connc_banksys_db.h"
#include "sys_error_compute.h"
#include "sys_apply_info.h"

//ģ��18
//����������Ϣ��ѯ
//����:
//ͨ��һ��apply��id��,�ڴ���˱��в�ѯ��ص���Ϣ

typedef apply_input_info research_query_data;//��ѯ�Ľ����Ϣ

struct research_query_input_info{
	//�������Ϣ
	//�ӽ����ϴ���һ�������id����
	char app_id[APPLY_ID];//APPLY����Ϊ����11
};

struct research_query_info{
	//�����ѯ�Ľ����Ϣ
	research_query_data query_info;//�����Ϣ
	sys_err err_info;//������Ϣ
};

struct research_query_modle{
	//������Ϣ
	research_query_input_info input_info;
	//��ѯ�����Ϣ
	research_query_info rlt_info;
};

/****************************************/
//ģ��18.1
//ģ��ĳ�ʼ�����ͷ�ģ��
//Jiraiya���

//��ʼ������ģ��
void init_research_query_input_info(research_query_input_info* _init);

//��ʼ�����ģ��
void init_research_query_info(research_query_info* _init);

//��ʼ����ģ��
research_query_modle* init_research_query_modle();

//�ͷ���ģ��
void release_research_query_modle(research_query_modle* _release);

/*****************************************/
//ģ��18.2
//���Ʋ�����ָ��
//jiraiya���
void research_query_copy_cmd(const char* _cmd
	,char* _dest , int _cmd_len);

//ת���������������Ϣ
research_query_input_info* research_query_convert_cmd(char* _info);

//ģ��18.2����ʽ
research_query_input_info* research_query_get_cmd(const char* _cmd,int _cmd_len);

/*****************************************/
//ģ��18.3
//���ݿ��ѯ
//��sunni���
//�����������ݿ��е����ݵ�����,װ�ص��ṹ��_data��..

void research_query_get_data(const char* _app_id,research_query_data* _data);

/******************************************/
//ģ��18.4
//���Ͻ����Ϣ
//����ѯ���������ϵ����������
//��Jiraiya���

void research_query_convert_rlt(research_query_info* _info
	,char* _rlt , int* _rlt_len);

/*******************************************/
//ģ��18������ʽ
void research_query_frame(const char* _cmd,int _cmd_len
	,char* _rlt,int* _rlt_len);


