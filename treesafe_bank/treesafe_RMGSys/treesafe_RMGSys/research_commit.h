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
#define RESEARCH_COMMIT_APPLY_ID_LEN APPLY_ID

//审核
#define RESEARCH_COMMIT_COMMENT 128



//模块9
//审核结果提交模块


//提交审核报告的审核员输入信息
//以下有些是审核员填写的
//而比如审核员id则是网页端自动生成的

struct research_commit_input_info{
	//申请的相关信息
	char researcher_id[RESEARCH_COMMIT_RESEARCHER_ID_LEN];
	//被提交的申请的相关信息
	char research_apply_id[RESEARCH_COMMIT_APPLY_ID_LEN];
	//有待亦可确定
	bool is_research_approved;//审核是否通过
	//个人信息审核注释
	char cust_research_info_comment[RESEARCH_COMMIT_COMMENT];
	//家庭信息审核过程
	//资产信息审核过程
	//
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
//将成功(是否成功不用你判断)通过审核的申请的信息提取出来
//复制到正式的申请表结构中(子函式1)
void research_commit_pad_data(const char* research_apply_id
	,sys_db_apply* _apply_info);

//将填充好的结构体信息存入数据库中(子函式2)
void research_commit_save_apply(sys_db_apply* _apply_info);

/*********************************************/
//模块9.4
//sunni完成
//根据输入的research_apply_id
//从审核表中删除这个表项
//查询的正确与否记录在_rlt中
void research_commit_delete_research_apply(const char* _research_apply_id , bool* _rlt);


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