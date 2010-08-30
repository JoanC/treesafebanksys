#pragma once
#include "sys_apply_info.h"
#include "database_mgr.h"
//ģ��7
//���봦���������Ϣ�ṹ
struct apply_info{
	//��Ҫ������������Ϣ
	//������Ϊ:
	//ֻ��Ҫ�ѶԱȻ�����Ϣʱ�Ĵ��󴫸���ǰ��ҳ��
	//���û�д���
	//���ʾ���������ڽ������...
	//�����Ǵ�����Ϣ,���������Ϣ��ʾno_err,��������ɹ�
	bool is_succ;//�Ƿ�ɹ�
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
void apply_query_cust_info(apply_custmor_info* _rlt,bool *_isSucceeded) ;

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
void apply_frame(const char* _command , int _len , char* _rlt , int* _rlt_len) ;
