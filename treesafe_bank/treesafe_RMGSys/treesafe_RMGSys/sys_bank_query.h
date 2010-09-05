#pragma once

#include "sys_connc_banksys_db.h"//数据库协议
//#include "treesate_cClient.h"//用户网络交互

/************************************************/
//模块7
//与银行子系统的交互查询
//该模块由ducky完成

//将所有查询一体化
//对于所有的子流程而言,网络部分其实是不可见的
//用户(也就是那些子流程),给一个请求,其实就希望得到一个结果
//而如何得到这个结果,就是模块7所做的
 /*********************************************************************************************************
** Function name:			sys_connc_bank_query
**
** Descriptions:			bank query system
**
** input parameters:	    bankDB_request_info* _req<i>
**							bankDB_result_info* _rlt<o>
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
void sys_connc_bank_query(bankDB_request_info* _req , bankDB_result_info* _rlt);