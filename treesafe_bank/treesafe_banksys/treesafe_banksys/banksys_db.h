#pragma  once
#include "banksys_data_struct.h"

/****************************************Copyright (c)**************************************************
**                         treesafe bank system                             
**
**                                
**
**--------------File Info-------------------------------------------------------------------------------
** File name:			
** Last modified Date:
** Last Version:		
** Descriptions: 		
**
**------------------------------------------------------------------------------------------------------
** Created by:			
** Created date:		
** Version:			
** Descriptions:		
**
********************************************************************************************************/

#ifndef _BANKSYS_DB_H_
#define _BANKSYS_DB_H_
//#include "banksys_data_struct.h"


#endif
#include<stdio.h>
#include<conio.h>

#import "C:\\Program Files\\Common Files\\System\\ado\\msado25.tlb" no_namespace rename("EOF","rsEOF")
/*********************************************************************************************************
** Function name:			ConnectDB
**
** Descriptions:		
**
** input parameters:		_ConnectionPtr *pConn
** Returned value:		bool :  return success or not
**         
** Used global variables:	
** Calling modules:			
**
** Created by:				S
** Created Date:		2010/7/27
**-------------------------------------------------------------------------------------------------------
** Modified by:				S
** Modified date:     2010/7/28
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool ConnectDB(_ConnectionPtr *pConn) ;	   //connect the db





/*********************************************************************************************************
** Function name:		DisConnectDB			
**
** Descriptions:		
**
** input parameters:		
** Returned value:		
**         
** Used global variables:	 /
** Calling modules:			
**
** Created by:			S
** Created Date:	 2010/7/27
**-------------------------------------------------------------------------------------------------------
** Modified by:			
** Modified date:	 
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void DisconnectDB(_ConnectionPtr *pConn) ; //disconnect the db


/*********************************************************************************************************
** Function name:			Cust_info_inquiry
**
** Descriptions:		
**
** input parameters:		
** Returned value:		
**         
** Used global variables:	 /
** Calling modules:			
**
** Created by:			S
** Created Date:	 2010/7/28
**-------------------------------------------------------------------------------------------------------
** Modified by:			
** Modified date:	 
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	Cust_info_inquiry(banksys_db *_rlt,_ConnectionPtr *_pConn) ;



/*********************************************************************************************************
** Function name:			Account_info_inquiry
**
** Descriptions:		
**
** input parameters:		
** Returned value:		
**         
** Used global variables:	 /
** Calling modules:			
**
** Created by:			S
** Created Date:	 2010/7/28
**-------------------------------------------------------------------------------------------------------
** Modified by:			
** Modified date:	 
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	Account_info_inquiry(banksys_db *_rlt,_ConnectionPtr *_pConn) ;


/*********************************************************************************************************
** Function name:			Loan_info_inquiry
**
** Descriptions:		
**
** input parameters:		
** Returned value:		
**         
** Used global variables:	 /
** Calling modules:			
**
** Created by:			S
** Created Date:	 2010/7/28
**-------------------------------------------------------------------------------------------------------
** Modified by:			
** Modified date:	 
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	Loan_info_inquiry(banksys_db *_rlt,_ConnectionPtr *_pConn) ;




/*********************************************************************************************************
** Function name:			InquiryResult
**
** Descriptions:		
**
** input parameters:		
** Returned value:		
**         
** Used global variables:	 /
** Calling modules:			
**
** Created by:			S
** Created Date:	 2010/7/28
**-------------------------------------------------------------------------------------------------------
** Modified by:			
** Modified date:	 
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	InquiryResult(banksys_db *_rlt,_ConnectionPtr *_pConn) ;