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
	query_weight_input_info
};

//26.1
//初始化模块和数据信息

void init_query_weight_input_info(query_weight_input_info* _init);

void init_query_weight_info(query_weight_info* _init);

query_weight_modle* init_query_weight_modle();

//26.2
//获取指令及其信息

