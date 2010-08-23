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
};

/********************************************/
//8.1
//初始化和释放模块8的各个结构体


/********************************************/
//模块8.2
//接收命令
void research_exact_copy_cmd(const char* _cmd , char* _dest , int _cmd_len);


