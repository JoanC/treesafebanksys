#pragma once

#include "database_mgr.h"//数据库处理中心
#include "sys_error_compute.h"//错误处理模块

//模块8
//审核信息的提取模块
//如果该审核员正在审核,则返回这个申请的信息和状态
//功能:向一个审核员提交一个需要审核的申请


//输入信息
//从网页发过来一个审核员的id
struct research_exact_input_info{
	
}