#include "stdafx.h"//Ԥ����
#include "sys_credit_compute.h"//���������Ĺ��ߺ�ʽ

//ģ��11
#define GET_SCORE_ID_LEN 19

struct get_score_input_info{
	int add_on_asset_score;
	int add_on_work_score;
	int add_on_society_score;
	int add_on_loan_score;
	char card_id[GET_SCORE_ID_LEN];
};

struct get_score_info{
	sys_err err_info;
};

struct get_score_modle{
	get_score_input_info input_info;
	get_score_info rlt_info;
};

/***********************************/
//��ʼ��ģ��ṹ
//11.1

void init_get_score_input_info(get_score_input_info* _init);

void init_get_score_info(get_score_info* _init);

get_score_modle* init_get_score_info();

/***********************************/
//11.2
//��ȡָ����Ϣ
void get_score_copy_cmd(const char* _cmd,char* _dest,int _cmd_len);

get_score_input_info* get_score_convert_cmd(char* _info);

get_score_input_info* get_score_get_cmd(const char* _cmd,int _cmd_len);
/***********************************/
//11.3
//������
void get_score_calcu(credit_sum* _score,event_wgt* _wgt,credit_scores* _rlt);

/************************************/
//11.4
//����������ķ����������ݿ���
void get_score_save_score(credit_scores* _rlt);

/*************************************/
void get_score_convert_rlt(get_score_info* _info,char* _rlt,int* _rlt_len);

//11.5
//����ʽ