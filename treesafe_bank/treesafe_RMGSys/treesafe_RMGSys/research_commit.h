#pragma once

#include "database_mgr.h"//数据库处理
#include "sys_error_compute.h"//错误处理

//模块9
//审核结果提交模块

//将会做为结果数据发送到网络端
struct research_commit_info{
	bool is_commit_succ;//提交是否成功
	sys_err err_info;//错误信息
};


//申请结果提交模块
struct research_commit_modle{
	research_commit_input_info input_info;
	research_commit_info rlt_info;
};

/*******************************************/
//模块9.1
//初始化和释放模块
//由Jiraiya完成

//初始化审核提交的输入信息
void research_commit_init_research_commit_input_info(research_commit_input_info* _init);

//初始化结果记录信息
void research_commit_init_research_commit_info(research_commit_info* _init);

//初始化审核提交模块信息
research_commit_modle* research_commit_init_research_commoit_modle();

//释放模块
void release_research_commit_modle(research_commit_modle* _release);

/**********************************************/
//9.2
//Jiraiya 完成
//命令的解析和复制

//9.2主函式,获取命令信息,并从中提取输入信息
research_commit_input_info* research_commit_get_cmd(const char* _cmd
	,int _cmd_len);

//复制命令信息
//将传入的命令信息复制到_dest中
void research_commit_copy_cmd(const char* _cmd,char* _dest,int _cmd_len);

//转化
//将字符串信息转化为用户输入的信息
research_commit_input_info* research_commit_convert_input(char* _info);

/**********************************************/
//9.3
//sunni完成
//将结构体信息存入数据库中
//完成一系列相应操作
//操作1 : 将这个app_id的审核结果存入,一个bool四个comment
//操作2 : 将这个app_id下的true/false改掉 ， 一个bool
bool	research_commit_save_apply(research_commit_input_info* _apply_info);

/**********************************************/
//模块9.5
//Jiraiya完成
//生成结果信息
void research_commit_convert_rlt(research_commit_info* _rlt_info
	,char* _rlt , int* _rlt_len);


/**********************************************/
//模块9的主函式
void research_commit_frame(const char* _cmd , int _cmd_len
	,char* _rlt , int* _rlt_len);