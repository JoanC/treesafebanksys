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