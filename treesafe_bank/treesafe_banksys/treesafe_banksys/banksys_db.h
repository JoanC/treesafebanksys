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
** Function name:				ConnectDB
**
** Descriptions:					before using the database, you must call this function.
**
** input parameters:			pConn : _ConnectionPtr *
** Returned value:				bool :  return success or not
**         
** Used global variables:	
** Calling modules:			
**
** Created by:					Sun
** Created Date:				2010/7/27
**-------------------------------------------------------------------------------------------------------
** Modified by:					Sun
** Modified date:				2010/7/28
**-------------------------------------------------------------------------------------------------------
** Modified by:					Sun
** Modified date:				2010/8/2
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool ConnectDB(_ConnectionPtr *pConn) ;	   //connect the db



/*********************************************************************************************************
** Function name:			DisConnectDB			
**
** Descriptions:				after using the database,you should call this function to disconnect the databse
**
** input parameters:		pConn : _ConnectionPtr *
** Returned value:			
**         
** Used global variables:	 /
** Calling modules:			
**
** Created by:				Sun
** Created Date:			2010/7/27
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sun
** Modified date:			2010/7/28
**------------------------------------------------------------------------------------------------------
** Modified by:				Sun
** Modified date:			2010/8/2
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void DisconnectDB(_ConnectionPtr *pConn) ; //disconnect the db


/*********************************************************************************************************
** Function name:				Cust_info_inquiry
**
** Descriptions:					inquiry the customer's info
**
** input parameters:			pConn : _ConnectionPtr *
** Returned value:				void
**         
** Used global variables:	 /
** Calling modules:			
**
** Created by:					Sun
** Created Date:				2010/7/28
**-------------------------------------------------------------------------------------------------------
** Modified by:					Sun
** Modified date:				2010/8/2
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	Cust_info_inquiry(banksys_db *_rlt,_ConnectionPtr *_pConn) ;



/*********************************************************************************************************
** Function name:			Account_info_inquiry
**
** Descriptions:				inquiry the account info
**
** input parameters:		_rlt : banksys_db * , _pConn : _ConnectionPtr *
** Returned value:		
**         
** Used global variables:	 /
** Calling modules:			
**
** Created by:				Sun
** Created Date:			2010/7/28
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sun
** Modified date:			2010/8/2
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	Account_info_inquiry(banksys_db *_rlt,_ConnectionPtr *_pConn) ;


/*********************************************************************************************************
** Function name:			Loan_info_inquiry
**
** Descriptions:				inquiry the loan info
**
** input parameters:		_rlt : banksys_db *  ,  _pConn : _ConnectionPtr *
** Returned value:		
**         
** Used global variables:	 /
** Calling modules:			
**
** Created by:				Sun
** Created Date:			2010/7/28
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sun
** Modified date:			2010/8/2
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	Loan_info_inquiry(banksys_db *_rlt,_ConnectionPtr *_pConn) ;




/*********************************************************************************************************
** Function name:			InquiryResult
**
** Descriptions:		
**
** input parameters:		_rlt : banksys_db *,  _pConn : _ConnectionPtr *
** Returned value:		
**         
** Used global variables:	 /
** Calling modules:			
**
** Created by:				Sun
** Created Date:			2010/7/28
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sun
** Modified date:			2010/8/2
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	InquiryResult(banksys_db *_rlt,_ConnectionPtr *_pConn) ;