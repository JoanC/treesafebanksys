#pragma once

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
void init_research_exact_info(research_exact_info* _init);

//初始化整体模块
research_exact_modle* init_research_exact_modle();

//释放模块
void release_research_exact_info(research_exact_modle* _release);

/*************************************/
//模块8.2
//得到指令
//由Jiraiya完成

//复制指令
void research_copy_cmd_data(const char* _cmd,char* _dest,int _cmd_len);

//转化指令
//包括中文解码和类型的强制转换
research_exact_input_info* research_convert_cmd(char* _info);

//获取指令
//8.2主函式
research_exact_input_info* research_get_cmd(const char* _cmd,
	int _cmd_len);

/***************************************/
//模块8.3
//数据库访问
//由sunni完成
//从数据库中读取一个新的app_id
//次app_id是没被审核过的,也就是对应值为false的

void research_exact_app_id(char* _new_app_id);


/*****************************************/
//模块8.4
//整合结果信息
//由Jiraiya完成

void research_exact_convert_rlt(research_exact_info* _info,
	char* _rlt , int* _rlt_len);

//模块8主函式
void research_exact_frame(const char* _cmd ,int _cmd_len
	, char* _rlt , int* _rlt_len);
