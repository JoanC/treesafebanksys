#include "database_mgr.h"//���ݿ����
#include "sys_error_compute.h"//�������
#include "sys_credit_compute.h"

//ģ��26
//��ѯȨ��

struct query_weight_input_info{};//������

struct query_weight_info{
	sys_err err_info;//������Ϣ
	event_wgt wgt_info;//Ȩ����Ϣ 
};

struct query_weight_modle{
	query_weight_input_info
};

//26.1
//��ʼ��ģ���������Ϣ

void init_query_weight_input_info(query_weight_input_info* _init);

void init_query_weight_info(query_weight_info* _init);

query_weight_modle* init_query_weight_modle();

//26.2
//��ȡָ�����Ϣ

