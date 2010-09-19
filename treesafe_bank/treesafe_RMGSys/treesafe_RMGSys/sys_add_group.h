#pragma once 
#include "sys_group_info.h"
#include "database_mgr.h"


//添加分组信息

struct add_group_input{
	group_info group;
};

struct add_group_info{
	bool is_add_group_succ;//增加分组是否成功
	sys_err err_info;
};

struct add_group_modle{
	add_group_input input_info;//输入信息
	add_group_info rlt_info;//结果信息
};

/*****************************************/
//模块31
//31.1
//初始化信息
void init_add_group_input(add_group_input* _init);

void init_add_group_info(add_group_info* _init);

add_group_modle* init_add_group_modle();

void add_group_release(add_group_modle* _release);
/******************************************/
//31.2
//获取指令

//复制指令
void add_group_copy_cmd(const char* _cmd,char* _info,int _cmd_len);

add_group_input* add_group_convert_cmd(char* _info);

add_group_input* add_group_get_cmd(const char* _cmd,int _cmd_len);

/********************************************/
//31.3
//运行数据库
//sunni完成

//1.自动生成一个group_id
//2.以group_id做为主健,将分组信息存入数据库中
bool add_group_db(group_info* _info);

/**********************************************/
//31.4
//整合数据信息
void add_group_generate_rlt(add_group_info* _info,char* _rlt,int* _rlt_len);

/**********************************************/
//模块31主函式
void add_group_frame(const char* _cmd,int _cmd_len,char* _rlt,int* _rlt_len);


