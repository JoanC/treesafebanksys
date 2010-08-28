#pragma once

#include "sys_admin_employee_info.h"
#include "sys_error_compute.h"//错误处理

//模块16
//删除雇员信息

//传入的信息
//其实就是根据一个id去删除用户
struct delete_employee_input{
	char employee_id[EMPLOYEE_ID_LEN];//身份证号码
};

//结果信息
//其实就是一个是否删除成功的标记
struct delete_employee_info{
	bool is_succ;//是否删除成功
	sys_err err_info;//错误信息
};

//模块16的整体
struct delete_employee_modle{
	delete_employee_input input_info;
	delete_employee_info rlt_info;
};

/*******************************************/
//模块16.1
//初始化和释放模块
//由Jiraiya完成


//初始化输入的信息
void init_delete_employee_input(delete_employee_input* _init);

//初始化结果记录信息
void init_delete_employee_info(delete_employee_info* _init);

//初始化模块16的整体
delete_employee_modle* init_delete_employee_modle();

/*********************************************/
//模块16.2
//接受指令
//Jiraiya完成

//16.2主函式
delete_employee_input* delete_employee_get_cmd(const char* _cmd,int _cmd_len);

//复制命令
void delete_employee_copy_cmd(const char* _cmd , char* _dest 
	, int _cmd_len);

//转化指令
delete_employee_input* delete_employee_convert_cmd(char* _info);

/*********************************************/
//模块16.3
//数据库操作
//sunni完成

void delete_employee_from_database(const char* _id , bool* _rlt);

/*********************************************/
//模块16.4总结结果信息
//将结果转化成字符串信息

void delete_employee_convert_rlt(delete_employee_info* _info , char* _rlt , int* _rlt_len);

/**********************************************/
//信息删除模块
//模块16的主函式
void delete_employee_frame(const char* _cmd , int _cmd_len , char* _rlt , int* _rlt_len);
