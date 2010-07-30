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
#ifndef _BANKSYS_NET_H_
#define _BANKSYS_NET_H_


#include"banksys_data_struct.h"


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
void net_add_connection(banksys_net *sServer);
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
void net_release_connection(banksys_net *sServer);
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
void net_wait_for_request(banksys_net *sServer);
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
void net_recieve_data(banksys_net *sServer);
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
// send net data(the size of data is less than 80 bytes)
void net_send_data(banksys_net *sServer);

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
void net_recieve_frame(banksys_mid* _mid,banksys_net* sServer);

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
void net_send_frame(banksys_mid* _mid,banksys_net* sServer);

#endif
