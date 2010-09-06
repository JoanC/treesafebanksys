#include "sys_credit_compute.h"
#include "database_mgr.h"
#include "sys_error_compute.h"
//模块21
//查询个人的分数
#define QUERY_SCORE_CARD_ID_LEN 19

struct query_score_input_info{
	char card_id[QUERY_SCORE_CARD_ID_LEN];//19位的证件号长度
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
//初始化21.1模块
//初始化与释放模块

void init_query_score_input_info(query_score_input_info* _init);

void init_query_score_info(query_score_info* _init);

query_score_modle* init_query_score_modle();

void release_query_score_modle(query_score_modle* _release);

/*********************************************/
//21.2
//获取指令
//并将21模块的输入指令转化成可读的数据
void query_score_copy_cmd(const char* _cmd,char* _dest,int _cmd_len);

query_score_input_info* query_score_convert_cmd(char* _info);

query_score_input_info* query_score_get_cmd(const char* _cmd,int _cmd_len);

/*********************************************/
//21.3
//数据库计算
bool query_score_db(char* _cust_id,credit_scores* _db_rlt) ;

/*********************************************/
//21.4
//结果信息转化

void query_score_rlt_convert(query_score_info* _info , char* _rlt , int* _rlt_len);

//模块21主函式
void query_score_frame(const char* _cmd , int _cmd_len , char* _rlt , int* _rlt_len);