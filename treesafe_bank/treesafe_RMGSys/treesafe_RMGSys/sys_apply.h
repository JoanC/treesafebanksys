#pragma once
#include "sys_apply_info.h"

//ģ��7

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

//�ͷ�ģ��
void apply_release(apply_modle* _mld);

/*******************************************************/
//ģ��7.2
//�������л�ȡ������Ϣ
// Jiraiya���
apply_input_info* apply_get_input_info(const char* _command , int _len);

//��������
void apply_get_copy_command(char* _dest , const char* _command , int _len);
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

//����,���������,Ҫ��"���״̬"
//"��˱�"�������ͬ
//���ģ������"�����"�ı���,���뵽"��˱���"
//��������ʱ���ע��
//��ģ��9��,�Ŵ�"��˱�"����ʽ����һ������,������"�����"

//Ϊ�����������Զ���ŵĴ���,Ҫ��һ�޶�
char* apply_save_generate_id();

//���������������˵ı���
void apply_save_to_research_table(char* _new_id , apply_input_info* _info);


/*********************************************************/
//ģ��7.6
//��Jiraiya���
//�������

void apply_convert_rlt(apply_info* _info , char* _rlt , int* _rlt_len);

/********************************************************/
//ģ��7.7
//��jiraiya���
//������
//...
void apply_err_compute(sys_err_type _type , apply_modle* _modle);

 
/*********************************************************/
//�������̵�����ʽ
void apply_frame(const char* _command , int _len , char* _rlt , int* _rlt_len);
