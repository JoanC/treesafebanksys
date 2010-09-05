#pragma once

#include "database_mgr.h"//数据库处理函式
#include "sys_error_compute.h"//错误处理

//模块15
//管理员操作 -- 添加雇员
//用于添加一个雇员

#include "sys_admin_employee_info.h"


#define ADD_EMPLOYEE_COMMENT_LEN 201

extern _ConnectionPtr* treesafe_db_connection ;
//添加雇员时填入的信息

struct add_employee_input{
	admin_employee_info employ_basic_info;
	char comment[ADD_EMPLOYEE_COMMENT_LEN];
};


//添加雇员的结果信息
struct add_employee_info{
	bool is_succ;//添加是否成功
	sys_err err_info;//错误信息
};

struct add_employee_modle{
	add_employee_input input_info;//输入信息
	add_employee_info rlt_info;//结果记录信息
};


/*****************************************/
//模块15.1
//数据结构初始化和释放
//Jiraiya完成

//初始化输入的信息
 /*********************************************************************************************************
** Function name:			init_add_employee_input
**
** Descriptions:			init add employee input info
**
** input parameters:	    add_employee_input* _init
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void init_add_employee_input(add_employee_input* _init);

//初始化添加雇员的结果记录信息
 /*********************************************************************************************************
** Function name:			init_add_employee_info
**
** Descriptions:			init add employee info
**
** input parameters:	    add_employee_input* _init
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void init_add_employee_info(add_employee_info* _init);

//初始化添加雇员的总模块
 /*********************************************************************************************************
** Function name:			init_add_employee_modle
**
** Descriptions:			init add employee info main frame
**
** input parameters:	    NULL
** Returned value:		    add_employee_modle*
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
add_employee_modle* init_add_employee_modle();

//释放模块
 /*********************************************************************************************************
** Function name:			release_add_employee_modle
**
** Descriptions:			release add employee info main frame
**
** input parameters:	    add_employee_modle* _release
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void release_add_employee_modle(add_employee_modle* _release);

/******************************************/
//模块15.2
//Jiraiya完成
//接受指令信息
//将接受的指令转化成输入的信息
//Jiraiya完成

//复制指令信息
 /*********************************************************************************************************
** Function name:			add_employee_copy_cmd
**
** Descriptions:			copy command
**
** input parameters:	    const char* _cmd 
**							char* _dest 
**							int _cmd_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void add_employee_copy_cmd(const char* _cmd , char* _dest , int _cmd_len);

//转化指令,将其转化为输入的信息
 /*********************************************************************************************************
** Function name:			add_employee_convert_cmd
**
** Descriptions:			convert command
**
** input parameters:	    char* info
** Returned value:		    add_employee_input
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
add_employee_input* add_employee_convert_cmd(char* _info);

//15.2总函式
//转化并且复制指令
 /*********************************************************************************************************
** Function name:			add_employee_get_Cmd
**
** Descriptions:			get command
**
** input parameters:	    const char* _cmd
**							int _cmd_len
** Returned value:		    add_employee_input
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
add_employee_input* add_employee_get_cmd(const char* _cmd,int _cmd_len);

/********************************************/
//15.3
//sunni完成
//数据库添加
//将输入信息的相关项填入雇员表和*登录表中(填入两张表!!)
 /*********************************************************************************************************
** Function name:			add_employee_to_db
**
** Descriptions:			add employee info to database
**
** input parameters:	    add_employee_input* _input_info
**							bool *_rlt
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void add_employee_to_db(add_employee_input* _input_info, bool *_rlt);

/*********************************************/
//15.4
//由Jiraiya完成
//整合结果信息,将其转化为字符串
 /*********************************************************************************************************
** Function name:			add_employee_convert_result
**
** Descriptions:			convert_result
**
** input parameters:	    add_employee_info* _info
**							char* _rlt
**							int* _rlt_len
** Returned value:		    add_employee_input
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void add_employee_covert_result(add_employee_info* _info
	,char* _rlt , int* _rlt_len);

/***********************************************/
//模块15主函式
 /*********************************************************************************************************
** Function name:			add_employee_frame
**
** Descriptions:			modle main frame
**
** input parameters:	    const char* _cmd
**							int _cmd_len
**							char* _rlt , int* _rlt_len
**							char* _rlt
**							int* _rlt_len
** Returned value:		    add_employee_input
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void add_employee_frame(const char* _cmd , int _cmd_len
	,char* _rlt , int* _rlt_len);
