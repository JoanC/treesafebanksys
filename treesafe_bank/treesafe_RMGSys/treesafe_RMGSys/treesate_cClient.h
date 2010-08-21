#ifndef _CCLIENT_H_
#define _CCLIENT_H_
/****************************************Copyright (c)**************************************************
**                         treesafe bank system                             
**
**                                
**
**--------------File Info-------------------------------------------------------------------------------
** File name:			cClient			
** Last modified Date:	2010-8-2
** Last Version:		0.2		
** Descriptions:		the net action of treesafe and banksys 		
**
**------------------------------------------------------------------------------------------------------
** Created by:			zhoujiayun
** Created date:		2010-7-30
** Version:				0.1
** Descriptions:		
**
********************************************************************************************************/

#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

const int BUF_SIZE = 80;

struct cClient
{
	WSADATA			wsd;
	SOCKET			sHost;
	SOCKADDR_IN		servAddr;
	char			buf[BUF_SIZE];
};

/*********************************************************************************************************
** Function name:			InitClient
**
** Descriptions:			init the client		
**
** input parameters:		cClient* client------the cCLient struct modules
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				zhoujiayun
** Created Date:			2010-7-30
**-------------------------------------------------------------------------------------------------------
** Modified by:				zhoujiayun
** Modified date:			2010-8-1
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void InitClient(cClient* client);

/*********************************************************************************************************
** Function name:			CreateSocket
**
** Descriptions:			create socket		
**
** input parameters:		cClient* client------the cCLient struct modules
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				zhoujiayun
** Created Date:			2010-7-30
**-------------------------------------------------------------------------------------------------------
** Modified by:				zhoujiayun
** Modified date:			2010-8-1
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void CreateSocket(cClient* client);

/*********************************************************************************************************
** Function name:			Connect2Server
**
** Descriptions:			add a connect to server		
**
** input parameters:		cClient* client------the cCLient struct modules
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				zhoujiayun
** Created Date:			2010-7-30
**-------------------------------------------------------------------------------------------------------
** Modified by:				zhoujiayun
** Modified date:			2010-8-1
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void Connect2Server(cClient* client);

/*********************************************************************************************************
** Function name:			SendData
**
** Descriptions:			send data to server		
**
** input parameters:		cClient* client------the cCLient struct modules
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				zhoujiayun
** Created Date:			2010-7-30
**-------------------------------------------------------------------------------------------------------
** Modified by:				zhoujiayun
** Modified date:			2010-8-2
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void SendData(cClient* client);

/*********************************************************************************************************
** Function name:			RecData
**
** Descriptions:			recevie data to server		
**
** input parameters:		cClient* client------the cCLient struct modules
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				zhoujiayun
** Created Date:			2010-7-30
**-------------------------------------------------------------------------------------------------------
** Modified by:				zhoujiayun
** Modified date:			2010-8-2
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void RecData(cClient* client);
/*********************************************************************************************************
** Function name:			ExitClient
**
** Descriptions:			exit client	
**
** input parameters:		cClient* client------the cCLient struct modules
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				zhoujiayun
** Created Date:			2010-7-30
**-------------------------------------------------------------------------------------------------------
** Modified by:				zhoujiayun
** Modified date:			2010-7-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void ExitClient(cClient* client);

#endif