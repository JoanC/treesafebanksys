/****************************************Copyright (c)**************************************************
**                         treesafe bank system                             
**
**                                
**
**--------------File Info-------------------------------------------------------------------------------
** File name:			banksys_mid.h
** Last modified Date:	2010-7-24
** Last Version:		1.0
** Descriptions: 银行子系统的中继器接口的声明		
**
**------------------------------------------------------------------------------------------------------
** Created by:			Jiraiya
** Created date:		2004-02-02
** Version:				1.0
** Descriptions:		The original version
**
********************************************************************************************************/


#ifndef _BANKSYS_MID_H_
#define _BANKSYS_MID_H_

#include "banksys_data_struct.h"
#include "banksys_macro.h"
//#include "sys_Server.h"
//#include "banksys_db.h"

//中间过渡模块

/*********************************************************************************************************
** Function name:  mid_get_data_from_net
**
** Descriptions:	 中继器从网络层中获取接受的数据
**
** input parameters:	
**                banksys_mid* _mid : 中继器模块的结构体
**                sys_Server* _net : 网络模块的结构体
** Returned value:	 void(none)
**         
** Used global variables:	none
** Calling modules:  调用了网络模块
**
** Created by:				Jiraiya    wanjunya.jiraiya@gmail.com
** Created Date:		2010-7-26
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void mid_get_data_from_net(banksys_mid* _mid , sys_Server* _net);
//从数据库中接受数据
/*********************************************************************************************************
** Function name:		mid_get_data_from_db
**
** Descriptions:		中继器从数据库中读取结果数据
**
** input parameters:		
**                banksys_mid* _mid : 中继器模块的结构体
**                banksys_db* _net : 数据库模块的结构体
** Returned value:		none
**         
** Used global variables:	none
** Calling modules:	数据模块(db)
**
** Created by:				Jiraiya    wanjunya.jiraiya@gmail.com
** Created Date:		2010-7-26	
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void mid_get_data_from_db(banksys_mid* _mid , banksys_db* _db);
//向数据库中发送数据
/*********************************************************************************************************
** Function name:		mid_send_data_to_db
**
** Descriptions:		向数据库输出请求数据
**
** input parameters:		
**                        banksys_mid* _mid :　 中继器模块结构体
**                        banksys_db* _db :　数据库模块结构体
** Returned value:		none
**         
** Used global variables:	none
** Calling modules:		调用了数据库模块
**
** Created by:				Jiraiya    wanjunya.jiraiya@gmail.com
** Created Date:		2010-7-2
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void mid_send_data_to_db(banksys_mid* _mid ,banksys_db* _db);
//向网络中发送数据
/*********************************************************************************************************
** Function name:			mid_send_data_to_net
**
** Descriptions:		向网络层发送将要被发送的数据
**
** input parameters:		
**                banksys_mid* _mid : 中继器模块的结构体
**                banksys_db* _net : 数据库模块的结构体
** Returned value:		none
**         
** Used global variables:	none
** Calling modules:		调用了网络模块
**
** Created by:				Jiraiya    wanjunya.jiraiya@gmail.com
** Created Date:		2010-7-2
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void mid_send_data_to_net(banksys_mid* _mid , sys_Server* _net , int _len);
//将从网络中接受的数据转化为向数据库的请求
/*********************************************************************************************************
** Function name:		mid_convert_rec_to_req
**
** Descriptions:	 将从网络中得到的接收数据转化为数据库可读的
**
** input parameters:	
**                      net_recieved_info* _rec  :  网络层接收的信息
**                      bankDB_request_info* _req : 数据库可读的请求信息
** Returned value:		none
**         
** Used global variables:	none
** Calling modules:	none
**
** Created by:				Jiraiya    wanjunya.jiraiya@gmail.com
** Created Date:		2010-7-26		
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void mid_convert_rec_to_req(net_recieved_info* _rec , bankDB_request_info* _req);
//将从数据库接受的运行结果数据转化为数据
/*********************************************************************************************************
** Function name:		mid_convert_rlt_to_send
**
** Descriptions:		将数据库的结果信息转化为将要被网络层发送的数据
**
** input parameters:	 
**                       bankDB_result_info* _rlt : 数据库结果信息 
**                       net_send_info* _send : 网络层将要发送的信息
** Returned value:	 (void) none
**         
** Used global variables:	none
** Calling modules:		none
**
** Created by:				Jiraiya    wanjunya.jiraiya@gmail.com
** Created Date:		2010-7-26	
**-------------------------------------------------------------------------------------------------------
** Modified by: Jiraiya 
** Modified date: 2010-8-31
**add len to copy the memmory
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void mid_convert_rlt_to_send(bankDB_result_info* _rlt , net_send_info* _send , int _len);
/*********************************************************************************************************
** Function name:		mid_recieve_frame
**
** Descriptions:		一次从net中接受数据,并把数据传给db的过程
**
** input parameters:		
**                           sys_Server* _net : 网络模块,从这里接受接收的数据
**                           banksys_mid* _mid : 中继器模块
**                           banksys_db* _db : 数据库模块,把请求模块发送到这里
** Returned value:	   void (none)
**         
** Used global variables: none
** Calling modules:		数据库模块和网络模块
**
** Created by:				Jiraiya    wanjunya.jiraiya@gmail.com
** Created Date:		2010-7-26		
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void mid_recieve_frame(sys_Server* _net,
	banksys_mid* _mid ,banksys_db* _db);
/*********************************************************************************************************
** Function name:		mid_send_frame
**
** Descriptions:		一次从db中接受数据,并把数据传给net的过程
**
** input parameters:  
**                        sys_Server* _net :　网络模块，向这里发送信息
**	                       banksys_mid* _mid：中继器模块
**                        banksys_db* _db : 数据库模块,从这里接受数据库的结果信息
** Returned value:		none
**         
** Used global variables:	none
** Calling modules:	数据库模块和网络模块
**
** Created by:				Jiraiya    wanjunya.jiraiya@gmail.com
** Created Date:		2010-7-26	
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void mid_send_frame(sys_Server* _net,
	banksys_mid* _mid ,banksys_db* _db);

#endif