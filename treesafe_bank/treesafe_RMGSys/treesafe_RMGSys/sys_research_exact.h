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