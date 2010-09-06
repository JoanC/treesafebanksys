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
	query_weight_input_info input_info;
	query_weight_info rlt_info;
};

//26.1
//��ʼ��ģ���������Ϣ

void init_query_weight_input_info(query_weight_input_info* _init);

void init_query_weight_info(query_weight_info* _init);

query_weight_modle* init_query_weight_modle();

void release_query_weight_modle(query_weight_modle* _release);

//26.2
//��ȡָ�����Ϣ

void query_weight_copy_cmd(const char* _cmd , char* _dest 
	, int _cmd_len);

query_weight_input_info* query_weight_convert_cmd(char* _info);

query_weight_input_info* query_weight_get_cmd(const char* _cmd ,
	int _cmd_len);

//26.3
//���ݿ��ȡ����

void query_weight_get_data(event_wgt* _data);

//26.4
//���Ͻ����Ϣ
void query_weight_convert_rlt(query_weight_info* _info
	,char* _rlt , int* _rlt_len);

//ģ��26������ʽ
void query_weight_frame(const char* _cmd , int _cmd_len
	,char* _rlt,int* _rlt_len);