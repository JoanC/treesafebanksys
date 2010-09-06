#pragma once
//模块2

//所有子流程都要包含
#include "sys_error_compute.h"//错误处理模块
#include "net.h"//网络层
#include "sys_login.h"//登陆的子流程
#include "sys_reg.h"//注册子过程
#include "sys_apply.h"//申请子过程
#include "sys_admin_add_employee.h"//增加雇员
#include "sys_admin_delete_employee.h"//删除雇员
#include "research_commit.h"//提交审核结果
#include "sys_research_info_query.h"//查询审核申请信息
#include "sys_research_exact.h"//抽取审核信息id
#include "sys_employee_query.h"//查询雇员的基本信息
#include "query_user_info_array.h"//查询所有的用户信息
#include "sys_get_score.h"//存储,计算数据
#include "query_score.h"//查询分数
#include "query_one_user_info.h"//查询单人的基础信息


typedef char* COMMAND_DATA;
#define SYS_CMD_MAX_RLT_SIZE 128*128
#define SYS_CMD_MAX_SIZE 3072

enum{
	//命令编号集合
	sys_cmd_login = 0,//登录指令
	sys_cmd_reg = 1,//注册指令
	sys_cmd_apply = 2,//提交申请指令
	sys_cmd_add_employee = 3,//增加雇员
	sys_cmd_delete_employee = 4,//删除雇员
	sys_cmd_commit_research = 5,//。提交审核信息
	sys_cmd_query_research = 6,//查询审核申请信息
	sys_cmd_exact_research = 7,//抽取一个新的(未被审核的)app_id
	sys_cmd_query_employee = 8,//查找新雇员的信息
	sys_cmd_query_user_array = 9,//查询所有的用户信息
	sys_cmd_get_user_score = 10,//存储并计算分数
	sys_cmd_query_user_score = 11,//获取用户的分数
	sys_cmd_query_one_user_info = 12,//查询一个用户的信息
	sys_cmd_unexpect = -1//未知命令(不可解析)
};  

struct sys_net_data{
	int type;//命令类型
	int len;//命令长度
	char data[SYS_CMD_MAX_SIZE];//命令中的数据
};

/************************************************/
//模块2
// 从net中的指令-->转化-->将要发送的数据
//接受过程的过渡模块
//该模块由Jiraiya和王组长完成

//该模块本质是一个协议
//每个模块解析网络层中传来的命令
//并将data发送到对应的子过程中去

/***********************************************/
//模块2.1
//初始化和释放sys_net_info
void sys_command_init_sys_net_data(sys_net_data* _init);
void sys_command_release_sys_net_data(sys_net_data* _release);

/************************************************/
//模块2.2
//0.2 -- 将网络的接受信息转化为命令信息
void sys_command_convert(net_recieved_info* _rev , sys_net_data* _cmd);

/************************************************/
//模块2.3
//0.3 -- 接受收网络服务层的数据,并且予以解析,并执行相应的子流程函式
//一个大的switch_case
//根据不同的命令参数,调用不同的处理函数
//运行指令的结果存在将要发送的一个net_datazhogn 
void sys_command(const sys_net_data* _command,char* _rlt,int* _rlt_len);


//模块2.4
//0.4不同的子处理函数

//登陆模块的处理函数2.4.1
 /*********************************************************************************************************
** Function name:			sys_command_login
**
** Descriptions:			login command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-30
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-31
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void sys_command_login(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);

//注册模块子处理函式2.4.2
 /*********************************************************************************************************
** Function name:			sys_command_reg
**
** Descriptions:			register command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void sys_command_reg(const sys_net_data* _cmd , char* _rlt,int* _rlt_len);

//申请模块的子处理函式2.4.3
 /*********************************************************************************************************
** Function name:			sys_command_apply
**
** Descriptions:			apply command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt,int* _rlt_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void sys_command_apply(const sys_net_data* _cmd , char* _rlt,int* _rlt_len);

//增加雇员模处理子函式2.4.4
 /*********************************************************************************************************
** Function name:			sys_command_add_employee
**
** Descriptions:			add employee command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void sys_command_add_employee(const sys_net_data* _cmd , char* _rlt,int* _rlt_len);

//删除雇员子函式2.4.5
 /*********************************************************************************************************
** Function name:			sys_command_delete_employee
**
** Descriptions:			delete employee command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void sys_command_delete_employee(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);

//提交审核结果子函式2.4.6
 /*********************************************************************************************************
** Function name:			sys_command_commit_research
**
** Descriptions:			commit research command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void sys_command_commit_research(const sys_net_data* _cmd, char* _rlt,int* _rlt_len);

//查询审核申请信息结果处理子函式2.4.7
 /*********************************************************************************************************
** Function name:			sys_command_query_research
**
** Descriptions:			query research command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void sys_command_query_research(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);

//抽取审核信息处理子函式2.5.8
 /*********************************************************************************************************
** Function name:			sys_command_exact_research
**
** Descriptions:			exact research command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void sys_command_exact_research(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);

//查询雇员的处理函式2.5.9
 /*********************************************************************************************************
** Function name:			sys_command_query_employee
**
** Descriptions:			query_employee command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void sys_command_query_employee(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);

//查询用户数组处理函式2.5.10
 /*********************************************************************************************************
** Function name:			sys_command_query_user_array
**
** Descriptions:			query user array command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void sys_command_query_user_array(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);
 /*********************************************************************************************************
** Function name:			sys_command_get_score
**
** Descriptions:			get and calcu the user score command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
//2.5.11
void sys_command_get_score(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);

/*********************************************************************************************************
** Function name:			sys_command_get_score
**
** Descriptions:			get and calcu the user score command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
//2.5.12
void sys_command_query_user_score(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);

/*********************************************************************************************************
** Function name:			sys_command_get_score
**
** Descriptions:			get and calcu the user score command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
//2.5.13
void sys_command_query_one_user_info(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);


//模块2.5
//未知命令的处理函式
 /*********************************************************************************************************
** Function name:			sys_command_err
**
** Descriptions:			error command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void sys_command_err(const sys_net_data* _command,char* _rlt,int* _rlt_len);

//总体模块
 /*********************************************************************************************************
** Function name:			sys_command_run_frame
**
** Descriptions:			run command frame
**
** input parameters:	    net_recieved_info* _rev <i>
							net_send_info* _send <o>
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void sys_command_run_frame(net_recieved_info* _rev , net_send_info* _send);
