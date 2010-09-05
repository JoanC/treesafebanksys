#pragma once

#include "database_mgr.h"//数据库计算
#include "sys_error_compute.h"//错误处理

//模块19
//单个的雇员信息查询
//通过工号,查询一个雇员的具体信息

//雇员信息查询数据
typedef admin_employee_info employee_query_data;

//输入信息
struct employee_query_input_info{
	char work_id[19];//输入的雇员工号
};

//待发送的结果信息 
struct employee_query_info{
	employee_query_data query_data;//数据库查询结果
	//系统错误
	sys_err err_info;
};

//模块19的主模块结构体
struct employee_query_modle{
	//输入信息
	employee_query_input_info input_info;
	//查询过程中得到的结果信息
	employee_query_info rlt_info;
};

/***************************************/
//19.1
//初始化和释放模块及其数据
//Jiraiya完成
 /*********************************************************************************************************
** Function name:			init_employee_query_input_info
**
** Descriptions:			initialzie employee query input info
**
** input parameters:	    employee_query_input_info* _init
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void init_employee_query_input_info(employee_query_input_info* _init);
 /*********************************************************************************************************
** Function name:			init_employee_query_info
**
** Descriptions:			initialzie employee query info
**
** input parameters:	    employee_query_input_info* _init
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void init_employee_query_info(employee_query_info* _init);

 /*********************************************************************************************************
** Function name:			init_employee_query_modle
**
** Descriptions:			initialzie employee query modle
**
** input parameters:	    NULL
** Returned value:		    employee_query_modle*
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
employee_query_modle* init_employee_query_modle();

 /*********************************************************************************************************
** Function name:			release_employee_query_modle
**
** Descriptions:			release employee query modle
**
** input parameters:	    employee_query_modle*
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void release_employee_query_modle(employee_query_modle* _release);

/*****************************************/
//19.2
//复制并转化指令
//Jiraiya完成

//复制命令
 /*********************************************************************************************************
** Function name:			employee_query_copy_cmd
**
** Descriptions:			copy command
**
** input parameters:	    const char* _cmd 
							char* _dest
							int _cmd_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void employee_query_copy_cmd(const char* _cmd ,char* _dest, int _cmd_len);

//命令转化
//将指令中的数据读入到输入信息中
 /*********************************************************************************************************
** Function name:			employee_query_convert_cmd
**
** Descriptions:			convert command
**
** input parameters:	    char* _info 
** Returned value:		    employee_query_input_info*
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
employee_query_input_info* employee_query_convert_cmd(char* _info);

//19.2主函式
 /*********************************************************************************************************
** Function name:			employee_query_get_cmd
**
** Descriptions:			get command
**
** input parameters:	    char* _info 
** Returned value:		    const char* _cmd
**							int _cmd_len
** Used global variables:	employee_query_input_info*
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
employee_query_input_info* employee_query_get_cmd(const char* _cmd
	,int _cmd_len);

/*******************************************/
//19.3
//数据库查询
//sunni完成
//通过工号,将雇员的信息从数据库中调出
 /*********************************************************************************************************
** Function name:			employee_query_get_data
**
** Descriptions:			get employee info
**
** input parameters:	    const char* _work_id<>
**							employee_query_data* _info<o>
**							bool* _rlt<o>
** Returned value:		    const char* _cmd
**							int _cmd_len
** Used global variables:	employee_query_input_info*
** Calling modules:			NULL
**
** Created by:				suuni
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				sunni
** Modified date:			2010-8-15
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void employee_query_get_data(const char* _work_id
	,employee_query_data* _info,bool* _rlt);

/********************************************/
//19.4
//整合数据结果
//Jiraiya完成
//将查询结果转化为数据
 /*********************************************************************************************************
** Function name:			employee_query_convert_rlt
**
** Descriptions:			get command
**
** input parameters:	    employee_query_info* _info
**							char* _rlt
**							int* _rlt_len
** Returned value:		    const char* _cmd
**							int _cmd_len
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void employee_query_convert_rlt(employee_query_info* _info,
	char* _rlt , int* _rlt_len);

/*********************************************/
//模块19的主函式
 /*********************************************************************************************************
** Function name:			employee_query_frame
**
** Descriptions:			query frame
**
** input parameters:	    const char* _cmd
**							int _cmd_len
**							char* _rlt
**							int* _rlt_len
** Returned value:		    NULL
** Used global variables:	employee_query_input_info*
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void employee_query_frame(const char* _cmd , int _cmd_len
	,char* _rlt,int* _rlt_len);

