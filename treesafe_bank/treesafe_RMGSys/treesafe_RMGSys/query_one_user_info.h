#include "query_user_info_array.h"
#include "sys_error_compute.h"
#include "database_mgr.h"

/******************************************/
//模块22
//对一个用户的信息进行查询
#define ONE_USER_CARD_ID_LEN 19
struct query_user_one_info_input{
	char user_id[ONE_USER_CARD_ID_LEN];//用户的证件号码
};


struct query_user_one_info_info{
	user_query_info user_info;
	sys_err err_info;//错误信息
};

struct query_user_one_info_modle{
	query_user_one_info_input* input;
	query_user_one_info_info rlt_info;
};

//22.2
//初始化和释放模块模块

void init_query_user_one_info_input(query_user_one_info_input* _input);

void init_query_user_one_info_info(query_user_one_info_info* _init);

