#ifndef _BANKSYS_DB_H_
#define _BANKSYS_DB_H_
#include "banksys_data_struct.h"


#endif
#include<stdio.h>
#include<conio.h>

#import "C:\\Program Files\\Common Files\\System\\ado\\msado25.tlb" no_namespace rename("EOF","ENDOFRS")
/*********************************************************************************************************
** Function name:			
**
** Descriptions:		
**
** input parameters:		
** Returned value:		
**         
** Used global variables:	
** Calling modules:			
**
** Created by:				
** Created Date:		
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void ConnectDB(_ConnectionPtr &pConn) ;	   //connect the db
/*********************************************************************************************************
** Function name:			
**
** Descriptions:		
**
** input parameters:		
** Returned value:		
**         
** Used global variables:	
** Calling modules:			
**
** Created by:				
** Created Date:		
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void DisconnectDB(_ConnectionPtr &pConn) ; //disconnect the db