#pragma once

#include "database_mgr.h"//数据库处理中心
#include "sys_error_compute.h"//错误处理模块

//模块8
//审核信息的提取模块
//如果该审核员正在审核,则返回这个申请的信息和状态
//功能:向一个审核员提交一个需要审核的申请

#define RESEARCHER_ID_LEN 19
#define RESEARCH_APPLY_ID 19

//输入信息
//从网页发过来一个审核员的id
struct research_exact_input_info{
	char investigator_id[RESEARCHER_ID_LEN];
};

//该模块需要用到的审核员的一些属性
struct research_exact_investigator_prop{
	bool statu;//状态,可以是enum,true:空闲,free:正在审核
	//正在审核的申请id
	//该值初始化为null
	//如果审核员正在审核,则有值,否则保持是null
	char research_apply_id[APPLY_ID];
};

//这个将做为结果发送到网页层
struct research_exact_info{
	//申请编号
	char research_apply_id[RESEARCH_APPLY_ID];
	//待调查信息
	//...
	//当前调查结果
	//...
	//注释信息
	//...
	//错误信息
	sys_err err_info;
};


//审核信息抽取主模块
struct research_exact_modle{
	research_exact_input_info input_info;//输入
	//审核员属性
	research_exact_investigator_prop investigator_prop;
	research_exact_info rlt_info;//结果记录信息
};

/********************************************/
//8.1
//初始化和释放模块8的各个结构体\
//由Jiraiya完成

void research_exact_init_research_exact_input_info(research_exact_input_info* _init);

void research_exact_init_research_exact_investigator_prop(research_exact_investigator_prop* _init);

void research_exact_init_research_exact_info(research_exact_info* _init);

research_exact_modle* research_exact_init_research_exact_modle();

void release_research_exact_modle(research_exact_modle* _release);

/********************************************/
//模块8.2
//接收命令
//由Jiraiya完成

research_exact_input_info* research_exact_get_cmd(const char* _cmd , int _cmd_len);
//复制命令
void research_exact_copy_cmd(const char* _cmd , char* _dest , int _cmd_len);
//将复制的命令转化为模块可读的输入信息
research_exact_input_info* reasearch_exact_convert_cmd(char* _info);

/********************************************/
//模块8.3
//由sunni完成
//在数据库,审核员(雇员)表中,根据id查询这个审核员的部分信息
//将这些信息填入research_exact_investigator_prop结构体中

//目前确定的信息有,这个审核员的状态(是否在审核)
//以及(如果在审核的话),正在审的待审核申请项的research_apply_id

void research_exact_db_query_investigator_id(char* _id
	,research_exact_investigator_prop* _info);

/*********************************************/
//模块8.4
//模块8的核心部分
//由sunni完成
//自动从数据库的审核表中抽取一条
//将审核员状态改为"正在审核",先存入research_exact_db_query_investigator_id中,
//再存入数据库中
//将抽取的apply_id,
//先存入research_exact_db_query_investigator_id中
//再存入数据库中

//模块8.4的主函式
void research_exact_compute(char* __investigator_id
	,research_exact_investigator_prop* _prop);

//以下是模块8.4的子过程

//从数据库中抽取一个新的_id
void research_exact_apply_id(char* _new_research_id);

//将结果先填入数据结构中
//并在数据结构中更改状态
void research_exact_change_prop(char* _new_id
	,research_exact_investigator_prop* _prop);

//将数据结构中的信息存入数据库的相应位置中
void research_exact_save_prop(char* _investigator_id
	,research_exact_investigator_prop* _prop);


/*********************************************/
//模块8.5
//由sunni完成
//通过数据库,
//检索申请信息,并且填充research_exact_info的信息项
void research_exact_generate_rlt(resaearch_exact_info* _rlt_info);

/**********************************************/
//模块8.6
//由Jiraiya完成
//完成对结果信息的复制和转换
void research_exact_convert_rlt(research_exact_info* _info
	,char* _rlt , int* _len);

/**********************************************/
//模块8的主函式
void research_exact_frame(const char* _cmd
	,int _cmd_len,char* _rlt , int* _rlt_len);