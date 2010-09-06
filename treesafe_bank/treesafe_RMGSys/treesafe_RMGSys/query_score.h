#include "sys_credit_compute.h"
#include "database_mgr.h"
#include "sys_error_compute.h"
//ģ��21
//��ѯ���˵ķ���
#define QUERY_SCORE_CARD_ID_LEN 19

struct query_score_input_info{
	char card_id[QUERY_SCORE_CARD_ID_LEN];//19λ��֤���ų���
};

struct query_score_info{
	credit_scores rlt_score;
	sys_err err_info;
};

struct query_score_modle{
	query_score_input_info input_info;
	query_score_info rlt_info;
};

/*********************************************/
//21.1
//��ʼ��21.1ģ��
//��ʼ�����ͷ�ģ��

void init_query_score_input_info(query_score_input_info* _init);

void init_query_score_info(query_score_info* _init);

query_score_modle* init_query_score_modle();

void release_query_score_modle(query_score_modle* _release);

/*********************************************/
//21.2
//��ȡָ��
//����21ģ�������ָ��ת���ɿɶ�������
void query_score_copy_cmd(const char* _cmd,char* _dest,int _cmd_len);

query_score_input_info* query_score_convert_cmd(char* _info);

query_score_input_info* query_score_get_cmd(const char* _cmd,int _cmd_len);

/*********************************************/
//21.3
//���ݿ����
bool query_score_db(char* _cust_id,credit_scores* _db_rlt) ;

/*********************************************/
//21.4
//�����Ϣת��

void query_score_rlt_convert(query_score_info* _info , char* _rlt , int* _rlt_len);

//ģ��21����ʽ
void query_score_frame(const char* _cmd , int _cmd_len , char* _rlt , int* _rlt_len);