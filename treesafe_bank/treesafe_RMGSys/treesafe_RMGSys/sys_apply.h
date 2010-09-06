#pragma once
#include "sys_apply_info.h"
#include "database_mgr.h"
//模块7
//申请处理的所有信息结构
struct apply_info{
	//即要传给网络层的信息
	//个人认为:
	//只需要把对比基本信息时的错误传给当前的页面
	//如果没有错误 
	//则表示该申请正在进行审核...
	//下面是错误信息,如果错误信息显示no_err,则是申请成功
	bool is_succ;//是否成功
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

//初始化申请模块
/*********************************************************************************************************
** Function name:			apply_init_apply_modle
**
** Descriptions:			initialize apply modle
**
** input parameters:	    apply_modle* _init -------------------- apply modle
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_init_apply_modle(apply_modle* _init);

//释放模块
/*********************************************************************************************************
** Function name:			reg_release
**
** Descriptions:			release register information
**
** input parameters:	    apply_modle* _mld -------------------- apply modle
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_release(apply_modle* _mld);

/*******************************************************/
//模块7.2
//从命令中获取可用信息
// Jiraiya完成
/*********************************************************************************************************
** Function name:			apply_get_input_info
**
** Descriptions:			get input information
**
** input parameters:	    const char* _command -------------------- command
**                          int _len -------------------------------- command length
** Returned value:		    apply_input_info ------------------------ input informtion
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
apply_input_info* apply_get_input_info(const char* _command , int _len);

//复制命令
/*********************************************************************************************************
** Function name:			apply_get_copy_command
**
** Descriptions:			copy get command
**
** input parameters:	    char* _dest -------------------- dest string
**                          const char* _command ----------- source string
**                          int _len ----------------------- string length
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_get_copy_command(char* _dest , const char* _command , int _len);
//将命令转化为用户的输入信息
//当然,这个依赖于双方的协议
/*********************************************************************************************************
** Function name:			reg_add_user_to_db
**
** Descriptions:			add user information to database
**
** input parameters:	    char* _data -------------------- convert data
** Returned value:		    apply_input_info --------------- input apply info
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
apply_input_info* apply_get_convert_input(char* _data);

/******************************************************/
//模块7.3
//由sunni完成
//从风险控制系统的数据库中调出用户的基础数据
//将数据填入一个apply_custmor_info中
/*********************************************************************************************************
** Function name:			apply_query_cust_info
**
** Descriptions:			query the customer information
**
** input parameters:	    apply_customer_info* _rlt -------------------- query result
**                          bool *_isSucceeded --------------------------- whether has errors
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				sunni
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_query_cust_info(apply_custmor_info* _rlt,bool *_isSucceeded) ;

/******************************************************/
//模块7.4
//由jiraiya完成
//将用户输入的信息与数据库调出的信息进行比对
/*********************************************************************************************************
** Function name:			apply_check_cust_info
**
** Descriptions:			check customer infomation
**
** input parameters:	    apply_customer_info* _input -------------------- input user information
**                          apply_customer_info* _db_query ----------------- database query 
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Sunni
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
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
//不需要单独使用，会在apply_save_to_research_table()里调用
/*********************************************************************************************************
** Function name:			apply_save_generate_id
**
** Descriptions:			save generate ID
**
** input parameters:	    char* _outcome -------------------- outcome information
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool apply_save_generate_id(char *_outcome) ;

//把这个申请存入待审核的表中
/*********************************************************************************************************
** Function name:			apply_save_to_research_table
**
** Descriptions:			save the apply info to research table
**
** input parameters:	    apply_input_info* _info -------------------- input apply information
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool apply_save_to_research_table(apply_input_info* _info) ; 


/*********************************************************/
//模块7.6
//由Jiraiya完成
//结果处理
/*********************************************************************************************************
** Function name:			apply_convert_rlt
**
** Descriptions:			convert result 
**
** input parameters:	    apply_info* _info ---------- apply information
**                          char* _rlt ----------------- result
**                          int* _rlt_len -------------- reuslt length
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_convert_rlt(apply_info* _info , char* _rlt , int* _rlt_len);

/********************************************************/
//模块7.7
//由jiraiya完成
//错误处理
//...
/*********************************************************************************************************
** Function name:			apply_err_compute
**
** Descriptions:			compute error
**
** input parameters:	    sys_err_type _type -------------------- error type
**                          apply_modle* _modle ------------------- apply modle
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_err_compute(sys_err_type _type , apply_modle* _modle);

/********************************************/
//7.8
//检测数据冲突
//主要是贷款,存款的有无判断
/*********************************************************************************************************
** Function name:			appy_check_input_data
**
** Descriptions:			check input data
**
** input parameters:	    apply_input_info* _input -------------------- input apply information
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool appy_check_input_data(apply_input_info* _input);

 
/*********************************************************/
//申请流程的主函式
/*********************************************************************************************************
** Function name:			apply_frame
**
** Descriptions:			apply frame
**
** input parameters:	    const char* _command -------------------- command
**                          int _len -------------------------------- length
**                          char* _rlt ------------------------------ result
**                          int* _rlt_len --------------------------- result length
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_frame(const char* _command , int _len , char* _rlt , int* _rlt_len) ;
