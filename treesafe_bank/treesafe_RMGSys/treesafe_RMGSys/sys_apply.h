#pragma once
#include "sys_apply_info.h"

//模块7

/*******************************************************/
//由Jiraiya完成
//7.1
//初始化申请模块

//初始化用户信息
void apply_init_apply_custmor_info(apply_custmor_info* _init);

//初始化申请信息
void apply_init_apply_loan_info(apply_loan_info* _init);

//初始化输入信息
void apply_init_apply_input_info(apply_input_info* _init);

//初始化申请的过程信息
void apply_init_apply_info(apply_info* _init);

//初始化申请模块
void apply_init_apply_modle(apply_modle* _init);

//释放模块
void apply_release(apply_modle* _mld);

/*******************************************************/
//模块7.2
//从命令中获取可用信息
// Jiraiya完成
apply_input_info* apply_get_input_info(const char* _command , int _len);

//复制命令
void apply_get_copy_command(char* _dest , const char* _command , int _len);
//将命令转化为用户的输入信息
//当然,这个依赖于双方的协议
apply_input_info* apply_get_convert_input(char* _data);

/******************************************************/
//模块7.3
//由sunni完成
//从风险控制系统的数据库中调出用户的基础数据
//将数据填入一个apply_custmor_info中
void apply_query_cust_info(apply_custmor_info* _rlt);

/******************************************************/
//模块7.4
//由jiraiya完成
//将用户输入的信息与数据库调出的信息进行比对

bool apply_check_cust_info(apply_custmor_info* _input 
	, apply_custmor_info* _db_query);

/*******************************************************/
//模块7.5
//由sunni完成
//为这个申请自动编号,并存入待调查的数据表(research_info)中
//这个表中的内容还需商定

//对了,在这个表里,要有"审核状态"
//"审核表"和申请表不同
//这个模块生成"待审核"的表项,加入到"审核表中"
//所以命名时务必注意
//在模块9中,才从"审核表"中正式生成一个申请,并加入"申请表"

//为这个申请产生自动编号的代码,要独一无二
char* apply_save_generate_id();

//把这个申请存入待审核的表中
void apply_save_to_research_table(char* _new_id , apply_input_info* _info);


/*********************************************************/
//模块7.6
//由Jiraiya完成
//结果处理

void apply_convert_rlt(apply_info* _info , char* _rlt , int* _rlt_len);

/********************************************************/
//模块7.7
//由jiraiya完成
//错误处理
//...
void apply_err_compute(sys_err_type _type , apply_modle* _modle);

 
/*********************************************************/
//申请流程的主函式
void apply_frame(const char* _command , int _len , char* _rlt , int* _rlt_len);
