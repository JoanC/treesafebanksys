#include "stdafx.h"
#include "research_commit.h"

//模块9 -- 审核信息结果提交模块的实现代码

//9.1 初始化与释放模块

void research_commit_init_research_commit_input_info(research_commit_input_info* _init){
	//初始化审核提交的输入信息
	//审核员的id,初始为空
	strcpy(_init->researcher_id,"");
	//审核员的姓名,初始为空
	strcpy(_init->researcher_name,"");
	//被提交的审核申请编号,初始为空
	strcpy(_init->research_apply_id,"");
	//审核员的联系电话号,初始为空
	strcpy(_init->research_tel,"");
	
	//各种信息的审核结果(true/false)
	//细节待定

	//审核的最终结果,初始值为false
	_init->is_research_approved = false;
}

void research_commit_init_research_commit_info(research_commit_info* _init){
	//初始化结果记录信息
	//初始化错误信息
	init_sys_err(&_init->err_info);
	//提交是否成功,初始为true,(中间出问题后,会改为false)...
	_init->is_commit_succ
}