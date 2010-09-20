#pragma once

#include "sys_group_info.h"
#include "database_mgr.h"
#include "sys_error_compute.h"

//模块32
//查询一个小组的信息
#define MAX_GROUP_INFO 25

struct query_group_input{
	//空
};

struct query_group_info{
	int group_num;
	sys_err err_info;
	group_info group[MAX_GROUP_INFO];//分组的信息
};

struct query_group_modle{
	query_group_input input_info;
	query_group_info rlt_info;
};

//32.1
//初始化模块
void init_query_group_input(query_group_input* _init);

void init_query_group_info(query_group_info* _init);

query_group_modle* init_query_group_modle();

void release_query_group_modle(query_group_modle* _release);

//32.2
//接受指令
void query_group_copy_cmd(const char* _cmd
	,char* _info,int _cmd_len);

query_group_input* query_convert_cmd(char* _info);

query_group_input* query_get_cmd(const char* _cmd,int _cmd_len);

//32.3
//数据库操作
//1.查找出所有的分组
//2.将分组的个数载入到int中
//3.所有的分组信息则以数组的形式存于指针中


void query_group_db(int* _rlt_num,group_info* _query_data);

//32.4
//生成结果信息
void query_group_generate_rlt(query_group_info* _info
	,char* _rlt,int* _rlt_len);

//模块32的主函式
void query_group_frame(const char* _cmd,int _cmd_len,
	char* _rlt,int* _rlt_len);






