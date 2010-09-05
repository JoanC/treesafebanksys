#include "stdafx.h"//预编译
#include "sys_credit_compute.h"//信用评级的工具函式

//模块11
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