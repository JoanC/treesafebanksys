#pragma once

#include "database_mgr.h"//���ݿ⴦������
#include "sys_error_compute.h"//������ģ��

//ģ��8
//�����Ϣ����ȡģ��
//��������Ա�������,�򷵻�����������Ϣ��״̬
//����:��һ�����Ա�ύһ����Ҫ��˵�����

#define RESEARCHER_ID_LEN 19
#define RESEARCH_APPLY_ID 19

//������Ϣ
//����ҳ������һ�����Ա��id
struct research_exact_input_info{
	char investigator_id[RESEARCHER_ID_LEN];
};

//��ģ����Ҫ�õ������Ա��һЩ����
struct research_exact_investigator_prop{
	bool statu;//״̬,������enum,true:����,free:�������
	//������˵�����id
	//��ֵ��ʼ��Ϊnull
	//������Ա�������,����ֵ,���򱣳���null
	char research_apply_id[APPLY_ID];
};

//�������Ϊ������͵���ҳ��
struct research_exact_info{
	//������
	char research_apply_id[RESEARCH_APPLY_ID];
	//��������Ϣ
	//...
	//��ǰ������
	//...
	//ע����Ϣ
	//...
	//������Ϣ
	sys_err err_info;
};


//�����Ϣ��ȡ��ģ��
struct research_exact_modle{
	research_exact_input_info input_info;//����
	//���Ա����
	research_exact_investigator_prop investigator_prop;
	research_exact_info rlt_info;//�����¼��Ϣ
};

/********************************************/
//8.1
//��ʼ�����ͷ�ģ��8�ĸ����ṹ��\
//��Jiraiya���

void research_exact_init_research_exact_input_info(research_exact_input_info* _init);

void research_exact_init_research_exact_investigator_prop(research_exact_investigator_prop* _init);

void research_exact_init_research_exact_info(research_exact_info* _init);

research_exact_modle* research_exact_init_research_exact_modle();

void release_research_exact_modle(research_exact_modle* _release);

/********************************************/
//ģ��8.2
//��������
//��Jiraiya���

research_exact_input_info* research_exact_get_cmd(const char* _cmd , int _cmd_len);
//��������
void research_exact_copy_cmd(const char* _cmd , char* _dest , int _cmd_len);
//�����Ƶ�����ת��Ϊģ��ɶ���������Ϣ
research_exact_input_info* reasearch_exact_convert_cmd(char* _info);

/********************************************/
//ģ��8.3
//��sunni���
//�����ݿ�,���Ա(��Ա)����,����id��ѯ������Ա�Ĳ�����Ϣ
//����Щ��Ϣ����research_exact_investigator_prop�ṹ����

//Ŀǰȷ������Ϣ��,������Ա��״̬(�Ƿ������)
//�Լ�(�������˵Ļ�),������Ĵ�����������research_apply_id

void research_exact_db_query_investigator_id(char* _id
	,research_exact_investigator_prop* _info);

/*********************************************/
//ģ��8.4
//ģ��8�ĺ��Ĳ���
//��sunni���
//�Զ������ݿ����˱��г�ȡһ��
//�����Ա״̬��Ϊ"�������",�ȴ���research_exact_db_query_investigator_id��,
//�ٴ������ݿ���
//����ȡ��apply_id,
//�ȴ���research_exact_db_query_investigator_id��
//�ٴ������ݿ���

//ģ��8.4������ʽ
void research_exact_compute(char* __investigator_id
	,research_exact_investigator_prop* _prop);

//������ģ��8.4���ӹ���

//�����ݿ��г�ȡһ���µ�_id
void research_exact_apply_id(char* _new_research_id);

//��������������ݽṹ��
//�������ݽṹ�и���״̬
void research_exact_change_prop(char* _new_id
	,research_exact_investigator_prop* _prop);

//�����ݽṹ�е���Ϣ�������ݿ����Ӧλ����
void research_exact_save_prop(char* _investigator_id
	,research_exact_investigator_prop* _prop);


/*********************************************/
//ģ��8.5
//��sunni���
//ͨ�����ݿ�,
//����������Ϣ,�������research_exact_info����Ϣ��
void research_exact_generate_rlt(resaearch_exact_info* _rlt_info);

/**********************************************/
//ģ��8.6
//��Jiraiya���
//��ɶԽ����Ϣ�ĸ��ƺ�ת��
void research_exact_convert_rlt(research_exact_info* _info
	,char* _rlt , int* _len);

/**********************************************/
//ģ��8������ʽ
void research_exact_frame(const char* _cmd
	,int _cmd_len,char* _rlt , int* _rlt_len);