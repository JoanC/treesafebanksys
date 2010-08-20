#pragma once

#include "sys_error_compute.h"//错误处理

//模块7
//申请处理流程
#define APPLY_CUST_ID_LEN 19 //申请人身份证号长度
#define APPLY_CUST_NAME_LEN 51//姓名长度

enum APPLY_GENDER_TYPE {male , female};

//操作员输入的信息结构
struct apply_custmor_info{
	//申请人(社员)的信息
	//...有待王亦可来确定
	char cust_id[APPLY_CUST_ID_LEN];
	//姓名
	char cust_name[APPLY_CUST_NAME_LEN];
	//性别
	APPLY_GENDER_TYPE cust_gender;
	//年龄
	int cust_age;
};

struct apply_loan_info{
	//与联保申请的其它相关信息
	//...有待王亦可来确定
};

struct apply_input_info{
	//输入申请人的基本信息
	apply_custmor_info input_basic_info;
	apply_loan_info input_loan_info;
};

//申请处理的所有信息结构
struct apply_info{
	//即要传给网络层的信息
	//个人认为:
	//只需要把对比基本信息时的错误传给当前的页面
	//如果没有错误
	//则表示该申请正在进行审核...
	//下面是错误信息,如果错误信息显示no_err,则是申请成功
	sys_err errInfo;//申请处理中的错误信息
};

//申请处理的整体模块
struct apply_modle{
	apply_input_info input_info;//输入信息
	apply_custmor_info db_cust_info;//从数据库中读入的信息
	apply_info rlt_info;//存储申请过程中的信息,作为结果传到网络层中
};

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

/*******************************************************/
//模块7.2
//从命令中获取可用信息
// Jiraiya完成
apply_input_info* apply_get_input_info(char* _command , int _len);

//复制命令
void apply_get_copy_command(char* _dest , char* _command , int _len);
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

//为这个申请产生自动编号的代码,要独一无二
void apply_save_generate_id(char* _new_id);

//把这个申请存入待审核的表中
void apply_save_to_research_table(char* _new_id , apply_input_info* _info);


/*********************************************************/
//模块7.6
//由Jiraiya完成
//结果处理

void apply_err_

/********************************************************/
//模块7.7
//由jiraiya完成
//错误处理
//...
void apply_err_compute(sys_err_type _type , apply_modle* _modle);


/*********************************************************/
//申请流程的主函式
void apply_frame(char* _command , int _len , char* _rlt , int _rlt_len);
