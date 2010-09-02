#pragma once

#include "database_mgr.h"//���ݿ⴦��
#include "sys_error_compute.h"//������

//���ԱID����
#define RESEARCH_COMMIT_RESEARCHER_ID_LEN 19
//���Ա��������
#define RESEARCH_COMMIT_RESEARCHER_NAME_LEN 51
//���Ա�ĵ绰��ϵ��ʽ
#define RESEARCH_COMMIT_RESEARCHER_TEL_LEN 19

//���ύ����������ID
#define RESEARCH_COMMIT_APPLY_ID_LEN APPLY_ID

//���
#define RESEARCH_COMMIT_COMMENT 128



//ģ��9
//��˽���ύģ��


//�ύ��˱�������Ա������Ϣ
//������Щ�����Ա��д��
//���������Աid������ҳ���Զ����ɵ�

struct research_commit_input_info{
	//����������Ϣ
	char researcher_id[RESEARCH_COMMIT_RESEARCHER_ID_LEN];
	//���ύ������������Ϣ
	char research_apply_id[RESEARCH_COMMIT_APPLY_ID_LEN];
	//�д����ȷ��
	bool is_research_approved;//����Ƿ�ͨ��
	//������Ϣ���ע��
	char cust_research_info_comment[RESEARCH_COMMIT_COMMENT];
	//��ͥ��Ϣ��˹���
	//�ʲ���Ϣ��˹���
	//
};


//������Ϊ������ݷ��͵������
struct research_commit_info{
	bool is_commit_succ;//�ύ�Ƿ�ɹ�
	//����Ϣ
	//�ύ��˱��
	//...
	//�������...
	//������Ϣ
	sys_err err_info;
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
//���ɹ�(�Ƿ�ɹ��������ж�)ͨ����˵��������Ϣ��ȡ����
//���Ƶ���ʽ�������ṹ��(�Ӻ�ʽ1)
void research_commit_pad_data(const char* research_apply_id
	,sys_db_apply* _apply_info);

//�����õĽṹ����Ϣ�������ݿ���(�Ӻ�ʽ2)
void research_commit_save_apply(sys_db_apply* _apply_info);

/*********************************************/
//ģ��9.4
//sunni���
//���������research_apply_id
//����˱���ɾ���������
//��ѯ����ȷ����¼��_rlt��
void research_commit_delete_research_apply(const char* _research_apply_id , bool* _rlt);


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