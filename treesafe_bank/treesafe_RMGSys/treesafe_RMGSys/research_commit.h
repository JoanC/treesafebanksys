#pragma once

#include "database_mgr.h"//数据库处理
#include "sys_error_compute.h"//错误处理

//审核员ID长度
#define RESEARCH_COMMIT_RESEARCHER_ID_LEN 19
//审核员姓名长度
#define RESEARCH_COMMIT_RESEARCHER_NAME_LEN 51
//审核员的电话联系方式
#define RESEARCH_COMMIT_RESEARCHER_TEL_LEN 19

//被提交的审核申请的ID
#define RESEARCH_COMMIT_APPLY_ID_LEN 19



//模块9
//审核结果提交模块


//提交审核报告的审核员输入信息
//以下有些是审核员填写的
//而比如审核员id则是网页端自动生成的

struct research_commit_input_info{
	//审核员的相关信息
	char researcher_id[RESEARCH_COMMIT_RESEARCHER_ID_LEN];
	char researcher_name[RESEARCH_COMMIT_RESEARCHER_NAME_LEN];
	char research_tel[RESEARCH_COMMIT_RESEARCHER_TEL_LEN];
	//被提交的申请的相关信息
	char research_apply_id[RESEARCH_COMMIT_APPLY_ID_LEN];
	//各种bool或是枚举变量
	//...
	//有待亦可确定
	bool is_research_approved;//审核是否通过
	//...
};


//将会做为结果数据发送到网络端
struct research_commit_info{
	bool is_commit_succ;//提交是否成功
	//表单信息
	//提交审核编号
	//...
	//这个再议...
	//错误信息
	sys_err err_info;
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
//sunni完成
//将成功(是否成功不用你判断)通过审核的申请的信息提取出来
//复制到正式的申请表结构中(子函式1)
void research_commit_pad_data(const char* research_apply_id
	,sys_db_apply* _apply_info);

//将填充好的结构体信息存入数据库中(子函式2)
void research_commit_save_apply(sys_db_apply* _apply_info);

/*********************************************/
//模块9.3
//sunni完成
//根据输入的research_apply_id
//从审核表中删除这个表项
//查询的正确与否记录在_rlt中
void research_commit_delete_research_apply(const char* _research_apply_id , bool* _rlt);


/**********************************************/
//模块9.4
//Jiraiya完成
//生成结果信息
void research_commit_convert_rlt(research_commit_info* _rlt);


/**********************************************/
//模块9的主函式
void research_commit_frame(const char* _cmd , int _cmd_len
	,char* _rlt , int* _rlt_len);