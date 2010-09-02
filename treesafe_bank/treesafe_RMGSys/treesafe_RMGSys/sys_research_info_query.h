#pragma once

#include "sys_connc_banksys_db.h"
#include "sys_error_compute.h"
#include "sys_apply_info.h"

//模块18
//审核申请的信息查询
//功能:
//通过一个apply的id号,在待审核表中查询相关的信息

typedef apply_input_info research_query_data;//查询的结果信息

struct research_query_input_info{
	//输入的信息
	//从界面上传输一个申请的id号码
	char app_id[APPLY_ID];//APPLY定义为长度11
};

struct research_query_info{
	//申请查询的结果信息
	research_query_data query_info;//结果信息
	sys_err err_info;//错误信息
};

struct research_query_modle{
	//输入信息
	research_query_input_info input_info;
	//查询结果信息
	research_query_info rlt_info;
};

/****************************************/
//模块18.1
//模块的初始化和释放模块
//Jiraiya完成

//初始化输入模块
void init_research_query_input_info(research_query_input_info* _init);

//初始化结果模块
void init_research_query_info(research_query_info* _init);

//初始化主模块
research_query_modle* init_research_query_modle();

//释放主模块
void release_research_query_modle(research_query_modle* _release);

/*****************************************/
//模块18.2
//复制并解析指令
//jiraiya完成
void research_query_copy_cmd(const char* _cmd
	,char* _dest , int _cmd_len);

//转化并解码输入的信息
research_query_input_info* research_query_convert_cmd(char* _info);

//模块18.2主函式
research_query_input_info* research_query_get_cmd(const char* _cmd,int _cmd_len);

/*****************************************/
//模块18.3
//数据库查询
//由sunni完成
//本函数将数据库中的数据调出来,装载到结构体_data中..

void research_query_get_data(const char* _app_id,research_query_data* _data);

/******************************************/
//模块18.4
//整合结果信息
//将查询的数据整合到结果数据中
//由Jiraiya完成

void research_query_convert_rlt(research_query_info* _info
	,char* _rlt , int* _rlt_len);

/*******************************************/
//模块18的主函式
void research_query_frame(const char* _cmd,int _cmd_len
	,char* _rlt,int* _rlt_len);


