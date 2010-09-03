#pragma once

#include "database_mgr.h"//���ݿ⴦��
#include "sys_error_compute.h"//������

//ģ��9
//��˽���ύģ��

//������Ϊ������ݷ��͵������
struct research_commit_info{
	bool is_commit_succ;//�ύ�Ƿ�ɹ�
	sys_err err_info;//������Ϣ
};


//�������ύģ��
struct research_commit_modle{
	research_commit_input_info input_info;
	research_commit_info rlt_info;
};

/*******************************************/
//ģ��9.1
//��ʼ�����ͷ�ģ��
//��Jiraiya���

//��ʼ������ύ��������Ϣ
void research_commit_init_research_commit_input_info(research_commit_input_info* _init);

//��ʼ�������¼��Ϣ
void research_commit_init_research_commit_info(research_commit_info* _init);

//��ʼ������ύģ����Ϣ
research_commit_modle* research_commit_init_research_commoit_modle();

//�ͷ�ģ��
void release_research_commit_modle(research_commit_modle* _release);

/**********************************************/
//9.2
//Jiraiya ���
//����Ľ����͸���

//9.2����ʽ,��ȡ������Ϣ,��������ȡ������Ϣ
research_commit_input_info* research_commit_get_cmd(const char* _cmd
	,int _cmd_len);

//����������Ϣ
//�������������Ϣ���Ƶ�_dest��
void research_commit_copy_cmd(const char* _cmd,char* _dest,int _cmd_len);

//ת��
//���ַ�����Ϣת��Ϊ�û��������Ϣ
research_commit_input_info* research_commit_convert_input(char* _info);

/**********************************************/
//9.3
//sunni���
//���ṹ����Ϣ�������ݿ���
//���һϵ����Ӧ����
//����1 : �����app_id����˽������,һ��bool�ĸ�comment
//����2 : �����app_id�µ�true/false�ĵ� �� һ��bool
bool	research_commit_save_apply(research_commit_input_info* _apply_info);

/**********************************************/
//ģ��9.5
//Jiraiya���
//���ɽ����Ϣ
void research_commit_convert_rlt(research_commit_info* _rlt_info
	,char* _rlt , int* _rlt_len);


/**********************************************/
//ģ��9������ʽ
void research_commit_frame(const char* _cmd , int _cmd_len
	,char* _rlt , int* _rlt_len);