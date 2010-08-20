#pragma once

#include "sys_error_compute.h"//������

//ģ��7
//���봦������
#define APPLY_CUST_ID_LEN 19 //���������֤�ų���
#define APPLY_CUST_NAME_LEN 51//��������

enum APPLY_GENDER_TYPE {male , female};

//����Ա�������Ϣ�ṹ
struct apply_custmor_info{
	//������(��Ա)����Ϣ
	//...�д��������ȷ��
	char cust_id[APPLY_CUST_ID_LEN];
	//����
	char cust_name[APPLY_CUST_NAME_LEN];
	//�Ա�
	APPLY_GENDER_TYPE cust_gender;
	//����
	int cust_age;
};

struct apply_loan_info{
	//��������������������Ϣ
	//...�д��������ȷ��
};

struct apply_input_info{
	//���������˵Ļ�����Ϣ
	apply_custmor_info input_basic_info;
	apply_loan_info input_loan_info;
};

//���봦���������Ϣ�ṹ
struct apply_info{
	//��Ҫ������������Ϣ
	//������Ϊ:
	//ֻ��Ҫ�ѶԱȻ�����Ϣʱ�Ĵ��󴫸���ǰ��ҳ��
	//���û�д���
	//���ʾ���������ڽ������...
	//�����Ǵ�����Ϣ,���������Ϣ��ʾno_err,��������ɹ�
	sys_err errInfo;//���봦���еĴ�����Ϣ
};

//���봦�������ģ��
struct apply_modle{
	apply_input_info input_info;//������Ϣ
	apply_custmor_info db_cust_info;//�����ݿ��ж������Ϣ
	apply_info rlt_info;//�洢��������е���Ϣ,��Ϊ��������������
};

/*******************************************************/
//��Jiraiya���
//7.1
//��ʼ������ģ��

//��ʼ���û���Ϣ
void apply_init_apply_custmor_info(apply_custmor_info* _init);

//��ʼ��������Ϣ
void apply_init_apply_loan_info(apply_loan_info* _init);

//��ʼ��������Ϣ
void apply_init_apply_input_info(apply_input_info* _init);

//��ʼ������Ĺ�����Ϣ
void apply_init_apply_info(apply_info* _init);

//��ʼ������ģ��
void apply_init_apply_modle(apply_modle* _init);

/*******************************************************/
//ģ��7.2
//�������л�ȡ������Ϣ
// Jiraiya���
apply_input_info* apply_get_input_info(char* _command , int _len);

//��������
void apply_get_copy_command(char* _dest , char* _command , int _len);
//������ת��Ϊ�û���������Ϣ
//��Ȼ,���������˫����Э��
apply_input_info* apply_get_convert_input(char* _data);

/******************************************************/
//ģ��7.3
//��sunni���
//�ӷ��տ���ϵͳ�����ݿ��е����û��Ļ�������
//����������һ��apply_custmor_info��
void apply_query_cust_info(apply_custmor_info* _rlt);

/******************************************************/
//ģ��7.4
//��jiraiya���
//���û��������Ϣ�����ݿ��������Ϣ���бȶ�

bool apply_check_cust_info(apply_custmor_info* _input 
	, apply_custmor_info* _db_query);

/*******************************************************/
//ģ��7.5
//��sunni���
//Ϊ��������Զ����,���������������ݱ�(research_info)��
//������е����ݻ����̶�

//Ϊ�����������Զ���ŵĴ���,Ҫ��һ�޶�
void apply_save_generate_id(char* _new_id);

//���������������˵ı���
void apply_save_to_research_table(char* _new_id , apply_input_info* _info);


/*********************************************************/
//ģ��7.6
//��Jiraiya���
//�������

void apply_err_

/********************************************************/
//ģ��7.7
//��jiraiya���
//������
//...
void apply_err_compute(sys_err_type _type , apply_modle* _modle);


/*********************************************************/
//�������̵�����ʽ
void apply_frame(char* _command , int _len , char* _rlt , int _rlt_len);
