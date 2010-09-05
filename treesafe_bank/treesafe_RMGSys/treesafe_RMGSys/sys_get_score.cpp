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

struct get_score_modle{
	get_score_input_info input_info;
	get_score_info rlt_info;
};

/***********************************/
//初始化模块结构
//11.1

void init_get_score_input_info(get_score_input_info* _init);

void init_get_score_info(get_score_info* _init);

get_score_modle* init_get_score_info();

/***********************************/
//11.2
//获取指令信息
void get_score_copy_cmd(const char* _cmd,char* _dest,int _cmd_len);

get_score_input_info* get_score_convert_cmd(char* _info);

get_score_input_info* get_score_get_cmd(const char* _cmd,int _cmd_len);
/***********************************/
//11.3
//计算结果
void get_score_calcu(credit_sum* _score,event_wgt* _wgt,credit_scores* _rlt);

/************************************/
//11.4
//将计算出来的分数填入数据库中
void get_score_save_score(credit_scores* _rlt);

/*************************************/
void get_score_convert_rlt(get_score_info* _info,char* _rlt,int* _rlt_len);

//11.5
//主函式