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
research_query_modle init_research_query_modle();

