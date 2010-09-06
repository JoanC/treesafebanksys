#include "database_mgr.h"//数据库计算
#include "sys_error_compute.h"//错误计算
#include "sys_credit_compute.h"

//模块26
//查询权重

struct query_weight_input_info{};//空数组

struct query_weight_info{
	sys_err err_info;//错误信息
	event_wgt wgt_info;//权重信息 
};

struct query_weight_modle{
	query_weight_input_info input_info;
	query_weight_info rlt_info;
};

//26.1
//初始化模块和数据信息

void init_query_weight_input_info(query_weight_input_info* _init);

void init_query_weight_info(query_weight_info* _init);

query_weight_modle* init_query_weight_modle();

void release_query_weight_modle(query_weight_modle* _release);

//26.2
//获取指令及其信息

void query_weight_copy_cmd(const char* _cmd , char* _dest 
	, int _cmd_len);

query_weight_input_info* query_weight_convert_cmd(char* _info);

query_weight_input_info* query_weight_get_cmd(const char* _cmd ,
	int _cmd_len);

//26.3
//数据库读取操作

void query_weight_get_data(event_wgt* _data);

//26.4
//整合结果信息
void query_weight_convert_rlt(query_weight_info* _info
	,char* _rlt , int* _rlt_len);

//模块26的主函式
void query_weight_frame(const char* _cmd , int _cmd_len
	,char* _rlt,int* _rlt_len);