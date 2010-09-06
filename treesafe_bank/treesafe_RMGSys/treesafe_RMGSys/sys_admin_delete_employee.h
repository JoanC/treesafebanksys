#pragma once

#include "sys_admin_employee_info.h"
#include "sys_error_compute.h"//错误处理
#include "database_mgr.h"


extern _ConnectionPtr* treesafe_db_connection ;
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
 /*********************************************************************************************************
** Function name:			init_delete_employee_input
**
** Descriptions:			init deltet employee input info
**
** input parameters:	    delete_employee_input* _init
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
void init_delete_employee_input(delete_employee_input* _init);

//初始化结果记录信息
 /*********************************************************************************************************
** Function name:			init_delete_employee_info
**
** Descriptions:			init deltet employee info
**
** input parameters:	    delete_employee_info* _init
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
void init_delete_employee_info(delete_employee_info* _init);

//初始化模块16的整体
 /*********************************************************************************************************
** Function name:			init_delete_employee_modle
**
** Descriptions:			init deltet employee modle
**
** input parameters:	    NULL
** Returned value:		    delete_employee_modle*
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
delete_employee_modle* init_delete_employee_modle();

//释放模块
 /*********************************************************************************************************
** Function name:			release_delete_modle_employee
**
** Descriptions:			release delete employee info
**
** input parameters:	    delete_employee_modle* _release
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
void release_delete_modle_employee(delete_employee_modle* _release);

/*********************************************/
//模块16.2
//接受指令
//Jiraiya完成

//16.2主函式
 /*********************************************************************************************************
** Function name:			delete_employee_get_cmd
**
** Descriptions:			get command
**
** input parameters:	    const char* _cmd
**							int _cmd_len
** Returned value:		    delete_employee_input*
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
delete_employee_input* delete_employee_get_cmd(const char* _cmd,int _cmd_len);

//复制命令
 /*********************************************************************************************************
** Function name:			delete_employee_copy_cmd
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
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void delete_employee_copy_cmd(const char* _cmd , char* _dest 
	, int _cmd_len);

//转化指令
 /*********************************************************************************************************
** Function name:			delete_employee_convert_cmd
**
** Descriptions:			convert command
**
** input parameters:	    char* _info
** Returned value:		    delete_employee_input*
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
delete_employee_input* delete_employee_convert_cmd(char* _info);

/*********************************************/
//模块16.3
//数据库操作
//sunni完成
 /*********************************************************************************************************
** Function name:			delete_employee_from_database
**
** Descriptions:			delete employee info from db
**
** input parameters:	    const char* _id
**							bool* _rlt
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				sunni
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void delete_employee_from_database(const char* _id , bool* _rlt);

/*********************************************/
//模块16.4总结结果信息
//将结果转化成字符串信息

 /*********************************************************************************************************
** Function name:			delete_employee_convert_rlt
**
** Descriptions:			convert result
**
** input parameters:	    delete_employee_info* _info
**							char* _rlt , int* _rlt_len
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
void delete_employee_convert_rlt(delete_employee_info* _info , char* _rlt , int* _rlt_len);

/**********************************************/
//信息删除模块
//模块16的主函式
 /*********************************************************************************************************
** Function name:			delete_employee_frame
**
** Descriptions:			this main frame
**
** input parameters:	    const char* _cmd
**							int _cmd_len
**							char* _rlt
**							int* _rlt_len
** Returned value:		    delete_employee_input*
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
void delete_employee_frame(const char* _cmd , int _cmd_len , char* _rlt , int* _rlt_len);
