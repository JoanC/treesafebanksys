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

};

//
