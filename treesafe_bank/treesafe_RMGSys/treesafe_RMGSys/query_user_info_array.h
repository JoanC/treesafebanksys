#pragma once

#include "query_user_info.h"
#include "database_mgr.h"
#include "sys_error_compute.h"

//模块20
//查询所有拥有贷款的农民信息
//条件 ：已经存在被审核通过的农民信息


struct user_query_arr_input{};//空结构体

struct user_query_arr_info{
//	sys_err err_info;
	user_query_array_info query_arr_info;//数组信息
};//结果信息

struct user_query_arr_modle{
	user_query_arr_input input_info;
	user_query_arr_info rlt_info;
};

//20.1
//jiraiya 完成
//初始化结构体
//初始化模块20的主模块

user_query_arr_modle* init_user_query_arr_modle();

//释放模块
void release_user_query_arr_modle(user_query_arr_modle* _release);

//20.2
//获取指令
//复制指令
void user_query_copy_cmd(const char* _cmd , char* _dest, int _cmd_len);

//转化指令
user_query_arr_input* user_query_convert_cmd(char* _info);

user_query_arr_input* query_user_arr_get_cmd(const char* _cmd,int _cmd_len);

//20.3
//sunni完成
//得到所有农民的人数,这些人的条件是有被审核通过的申请
//结果保存在一个数字中
bool user_query_arr_count(int* _count) ;

//20.4
//sunni完成
//得到一个数组
//数组中存放这些农民的信息
//结果存入一个指针中
bool user_query_arr(user_query_arr_info* user_array,int* _arr_size) ;

//20.5
//转化结果数据
void user_query_arr_convert_rlt(user_query_arr_info* _info,char* _rlt,int* _rlt_len);


//模块20的主函式
void user_query_array_frame(const char* _cmd,int _cmd_len,char* _rlt,int* _rlt_len);