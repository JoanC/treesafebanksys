//模块6 -- 普通用户注册注册
/******************************************/
//此模块仅仅处理普通的用户处理程式
//而雇员的增加与减少则是在管理员的(管理雇员)模块功能中实现
#pragma once

#include "sys_error_compute.h" 
#include "database_mgr.h"
//#include "sys_connc_banksys_db.h"
#include "sys_bank_query.h"


//综合信息,即要发送给网络端的信息
struct reg_info{
	//用户名
	//用于在界面上输出"XXX,您好!注册成功"
	REG_USER_ID user_name[REG_MAX_USER_NAME];
	sys_err reg_err;//注册过程中出现的错误和异常
};

//注册过程的整体模块
struct reg_modle{
	bool reg_succ;//注册过程成功
	/*下面是数据*/
	reg_input_info input_info;//用户输入的信息
	reg_basic_info db_query_from_bank;//从银行系统调出的基础信息
	reg_info info;//注册过程中的数据,也是结果数据
};

/********************************************************/
//模块6.1
//Jiraiya完成
//登录信息的初始化
//以下过程由Jiraiya完成

//初始化注册整体模块
/*********************************************************************************************************
** Function name:			reg_init
**
** Descriptions:			initialize register information 
**
** input parameters:	    NULL                       
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
reg_modle* reg_init();
//释放整体模块
/*********************************************************************************************************
** Function name:			reg_release
**
** Descriptions:			release register information
**
** input parameters:	    reg_modle* _release ------ register  modle                
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
void reg_release(reg_modle* _release);

//初始化基本信息
/*********************************************************************************************************
** Function name:			reg_init_reg_basic_info
**
** Descriptions:			initilize the register basic info
**
** input parameters:	    reg_basic_info* _release ------ the register information needed released          
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
void reg_init_reg_basic_info(reg_basic_info* _init);

//初始化用户将要输入的信息
/*********************************************************************************************************
** Function name:			reg_init_reg_input_info
**
** Descriptions:			initilize the register basic info
**
** input parameters:	    reg_basic_info* _release ------ the register information needed released          
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
void reg_init_reg_input_info(reg_input_info* _init);

//初始化注册过程的结果信息
/*********************************************************************************************************
** Function name:			reg_init_reg_info
**
** Descriptions:			initilize the register information
**
** input parameters:	    reg_info* _init ------ the register information needed initilized       
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
void reg_init_reg_info(reg_info* _init);

/*******************************************************/
//模块6.2
//Jiraiya完成
//与用户UI层进行交互
//这是一个类型转换的过程,将cmd的信息转换成input_info

/*6.2子过程*/
//复制信息,避免指针的直接改动
/*********************************************************************************************************
** Function name:			reg_copy_cmd
**
** Descriptions:			copy the information
**
** input parameters:	    char* _release ---------- dest info       
**                          const char* _cmd_info --- source info
**                          int _len ---------------- the length of string
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
void reg_copy_cmd(char* _dst,const char* _cmd_info,int _len);
//类型转换,返回一个reg_input_info类型,即将复制后的信息转化
reg_input_info* reg_convert_cmd(char* _info);
//模块6.2主函式
reg_input_info* reg_get_info(const char* _cmd , int _len);//输入命令的信息和信息长度

/******************************************************/
//6.3
//协同完成
//将用户输入的身份证id通过net(client)端发送给banksys,在银行段查询是否有此人的信息
//如果没有,返回一个错误结果
//如果有,把这位用户的相关信息从银行系统里调出来,并填充在reg_cust_info中

//由于ducky的接受函数尚未写好,所以这里看看,我觉得还需设计一个模块,把这个过程封
//在一个主函式里,见sys_connc_bank
/*********************************************************************************************************
** Function name:			reg_query_user
**
** Descriptions:			query register user
**
** input parameters:	    char* _query_id --------------------- query ID
**                          reg_basic_info* _rlt_cust_info ------ customer information
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
void reg_query_user(char* _query_id,reg_basic_info* _rlt_cust_info);

//生成一个请求信息,_req
/*********************************************************************************************************
** Function name:			reg_query_user_generate_req
**
** Descriptions:			generate request
**
** input parameters:	    char* _cust_id --------------------- customer ID
**                          bankDB_request_info* _req ---------- requset information
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
void reg_query_user_generate_req(char* _cust_id,bankDB_request_info* _req);
//查询结果,将结果转化为bankDB_result_cust_info
/*********************************************************************************************************
** Function name:			reg_query_user_get_rlt
**
** Descriptions:			get query resutl
**
** input parameters:	    bankDB_request_info* _req --------------------- query ID
**                          bankDB_result_info* _db_rlt ------ customer information
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
void reg_query_user_get_rlt(bankDB_request_info* _req , bankDB_result_info* _db_rlt);
//根据_db_rlt,提取相关信息,填充到reg_cust_info中
/*********************************************************************************************************
** Function name:			reg_query_user_convert_rlt
**
** Descriptions:			convert query result
**
** input parameters:	    bankDB_result_info* _db_rlt -------------------- result information
**							reg_basic_info* _cust_info --------------------- customer information
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
void reg_query_user_convert_rlt(bankDB_result_info* _db_rlt,reg_basic_info* _cust_info);

/********************************************************/
//6.4
//由Jiraiya完成
//数据对比,对比用户输入的基础信息和从银行调出的信息进行必要的比对
//比对项尚要商讨,比如联系电话可以不用验证
//目前先比对用户真实姓名,性别,年龄,家庭住址
/*********************************************************************************************************
** Function name:			reg_info_cmp
**
** Descriptions:			compare the register information
**
** input parameters:	    reg_basic_info* _input -------------------- result information
**							reg_basic_info* _bank_data --------------------- customer information
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
bool reg_info_cmp(reg_basic_info* _input,reg_basic_info* _bank_data);

/********************************************************/
//6.5
//sunni完成
//将注册的用户填入到数据库中
//根据用户信息,将对应的登陆用的用户号和密码,以及身份证号
//内部的转化和扩充后存入db中
/*********************************************************************************************************
** Function name:			reg_add_user_to_db
**
** Descriptions:			add user information to database
**
** input parameters:	    reg_input_info* _info -------------------- input user information
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
bool reg_add_user_to_db(reg_input_info* _info);

/********************************************************/
//6.6
//由Jiraiya完成
//注册结束后,将结果信息转化成将要发送的信息
/*********************************************************************************************************
** Function name:			reg_generate_result
**
** Descriptions:			generate register result
**
** input parameters:	    reg_modle* _mld -------------------- input user information
**                          char* _rlt ------------------------- result
**                          int* _rlt_length ------------------- result length
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
void reg_generate_result(reg_modle* _mld , char* _rlt , int* _rlt_len);
/*********************************************************************************************************
** Function name:			reg_summery_rlt_data
**
** Descriptions:			summery result data
**
** input parameters:	    reg_modle* _mld -------------------- register modle
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
void reg_summery_rlt_data(reg_modle* _mld);//整理数据
/********************************************************/
//6.7
//由Jiraiya完成
//注册过程中的错误处理函式
/*********************************************************************************************************
** Function name:			reg_error_compute
**
** Descriptions:			add user information to database
**
** input parameters:	    sys_err_type _type -------------------- error type
**                          reg_modle* _modle --------------------- register modle
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
void reg_error_compute(sys_err_type _type , reg_modle* _modle);
/********************************************************/
//模块6主函式
//由Jiraiya完成
/*********************************************************************************************************
** Function name:			reg_frame
**
** Descriptions:			register frame
**
** input parameters:	    const char* _command -------------------- command
**                          int _art_len ---------------------------- command length
**                          char* _rlt ------------------------------ reuslt
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
void reg_frame(const char* _command , int _arg_len , char* _rlt , int* _rlt_len);
