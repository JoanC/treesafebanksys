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