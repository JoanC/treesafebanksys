#pragma once
#include "net.h"
/****************************************Copyright (c)**************************************************
**                         treesafe bank system                             
**
**                                
**
**--------------File Info-------------------------------------------------------------------------------
** File name:			banksys_net			
** Last modified Date:	2010-7-30
** Last Version:		0.4		
** Descriptions:		the net action of treesafe and banksys 		
**
**------------------------------------------------------------------------------------------------------
** Created by:			zhoujiayun
** Created date:		2010-7-1
** Version:				0.1
** Descriptions:		
**
********************************************************************************************************/
 
#include <winsock2.h>
#include <stdio.h>
//server socket struct

//网络结构体声明
//与银行系统相同
struct net_Server
{
	WSADATA		wsd;
	SOCKET sServer;   //server socket
	SOCKET sClient;
	SOCKADDR_IN	addrServ;
	sockaddr_in addrClient;
	BOOL bServerRunning;   //whether server is working
};

struct sys_Server{
	net_recieved_info rec;//接受到的数据
	net_send_info send;//发送的数据
	net_Server sys_server;
};




/*********************************************************************************************************
** Function name:			net_add_connect
**
** Descriptions:			add a connect to banksys		
**
** input parameters:		banksys_net *sServer------the banksys_net struct modules
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				zhoujiayun
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				zhoujiayun
** Modified date:			2010-7-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void net_add_connection(sys_Server *sServer);
/*********************************************************************************************************
** Function name:			net_release_connection
**
** Descriptions:			release a connection
**
** input parameters:		banksys_net *sServer------the banksys_net struct modules   
** Returned value:		
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				zhoujiayun
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				zhoujiayun
** Modified date:			2010-7-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
//release connection
void net_release_connection(sys_Server *sServer);
/*********************************************************************************************************
** Function name:			net_wait_for_request
**
** Descriptions:			wait for client to request
**
** input parameters:		banksys_net *sServer------the banksys_net struct modules
** Returned value:			NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				zhoujiayun
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				zhoujiayun
** Modified date:			2010-7-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void net_wait_for_request(sys_Server *sServer);
/*********************************************************************************************************
** Function name:			net_recieve_data
**
** Descriptions:			recieve net data
**
** input parameters:		banksys_net *sServer------the banksys_net struct modules
** Returned value:			NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				zhoujiayun
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				zhoujiayun
** Modified date:			2010-7-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void net_recieve_data(sys_Server *sServer);
/*********************************************************************************************************
** Function name:			net_send_data
**
** Descriptions:			send net data
**
** input parameters:		banksys_net *sServer------the banksys_net struct modules
** Returned value:			NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				zhoujiayun
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				zhoujiayun
** Modified date:			2010-7-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void net_send_data(sys_Server *sServer);

////////////////////////////////////////////////////////////////
/*********************************************************************************************************
** Function name:			net_recieve_frame
**
** Descriptions:			recieve from the mid
**
** input parameters:		banksys_mid* _mid------the banksys_mid struct modules
**                          banksys_net* sServer------the banksys_net struct modules
** Returned value:			NULL
**         
** Used global variables:	mid
** Calling modules:			NULL
**
** Created by:				zhoujiayun
** Created Date:			2010-7-28
**-------------------------------------------------------------------------------------------------------
** Modified by:				zhoujiayun
** Modified date:			2010-7-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void net_recieve_frame(sys_Server* sServer);

/*********************************************************************************************************
** Function name:			net_send_frame
**
** Descriptions:			send data to mid
**
** input parameters:		banksys_mid* _mid------the banksys_mid struct modules
**							banksys_net* sServer------the banksys_net struct modules
** Returned value:			NULL
**         
** Used global variables:	NULL
** Calling modules:			mid
**
** Created by:				zhoujiayun
** Created Date:			2010-7-28
**-------------------------------------------------------------------------------------------------------
** Modified by:				zhoujiayun
** Modified date:			2010-7-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void net_send_frame(sys_Server* sServer);

/*********************************************************************************************************
** Function name:			net_send_frame
**
** Descriptions:			send data to mid
**
** input parameters:		banksys_net* sServer------the banksys_net struct modules
**							
** Returned value:			NULL
**         
** Used global variables:	NULL
** Calling modules:			mid
**
** Created by:				zhoujiayun
** Created Date:			2010-8-3
**-------------------------------------------------------------------------------------------------------
** Modified by:				zhoujiayun
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
//void initNet(sys_Server* sServer);
DWORD WINAPI iAccpet(LPVOID p);