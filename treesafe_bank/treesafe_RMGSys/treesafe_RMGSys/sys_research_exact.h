#include "database_mgr.h"//数据库处理
#include "sys_error_compute.h"//错误处理

//模块8
//从数据库中抽取一个app_id
//目的在于交予审核员

struct research_exact_input_info{
	char research_work_id[EMPLOYEE_ID_LEN];//审核员工号
};

struct research_exact_info{
	char app_id[APPLY_ID];//返回的一个待审核申请的id
	sys_err err_info;//错误信息
};

struct research_exact_modle{
	research_exact_input_info input_info;
	research_exact_info rlt_info;
};

/*************************************/
//模块8.1
//由Jiraiya完成
//初始化各结构体
//初始化和释放模块


//初始化输入结构
void init_research_exact_input_info(research_exact_input_info* _init);

//初始化结果结构