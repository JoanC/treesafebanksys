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
	query_user_one_info_input input;
	query_user_one_info_info rlt_info;
};

//22.1
//初始化和释放模块模块

void init_query_user_one_info_input(query_user_one_info_input* _init);

void init_query_user_one_info_info(query_user_one_info_info* _init);

query_user_one_info_modle* init_query_user_one_info_modle();

void release_query_user_one_info_modle(query_user_one_info_modle* _release);
//22.2
//接受指令

void query_user_one_copy_cmd(const char* _cmd , char* _dest , int _cmd_len);

query_user_one_info_input* query_user_one_convert_cmd(char* _info);

query_user_one_info_input* query_user_one_get_cmd(const char* _cmd,int _cmd_len);

//22.3
//运行数据库

bool query_user_one_get_data(char* _cust_id , user_query_info* _rlt);

//22.4
//整合结果数据
void query_user_one_convert_rlt_info(query_user_one_info_info* _info
	, char* _rlt,int* _rlt_len);

//22.5
//模块22的主函式

void query_user_one_frame(const char* _cmd , int _cmd_len , char* _rlt , int* _rlt_len);