#include "database_mgr.h"
#include "sys_error_compute.h"

//模块28
//查找一个用户是否有分数信息
//(风险评估系统)
#define IS_USER_HAS_SCORE_ID_LEN 19

struct is_user_has_score_input{
	char card_id[IS_USER_HAS_SCORE_ID_LEN];
};

struct is_user_has_score_info{
	bool user_has_score;//true 表示有数据(有风险评估信息)
	sys_err err_info;//错误信息
};

struct is_user_has_score_modle{
	is_user_has_score_input input_info;
	is_user_has_score_info rlt_info;
};

//模块28.1
//初始化释放模块

void init_is_user_has_score_input(is_user_has_score_input* _init);

void init_is_user_has_score_info(is_user_has_score_info* _init);

is_user_has_score_modle* init_is_user_has_score_modle();

void release_is_user_has_score_modle(is_user_has_score_modle* _release);

//模块28.2
//获取指令



