#pragma once
#include "sys_error_compute.h"
#include "sys_db_struct.h"

/***********************************************/
//初始化函数
//所有结构体的初始化函数

//初始化用户信息 
/*********************************************************************************************************
** Function name:			apply_init_apply_customer_info
**
** Descriptions:			initialize apply information
**
** input parameters:	    apply_customer_info* _init -------------------- apply customer info
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-20
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_init_apply_custmor_info(apply_custmor_info* _init);

//初始化用户资产信息
/*********************************************************************************************************
** Function name:			apply_init_apply_customer_assets_info
**
** Descriptions:			initialize apply assets information
**
** input parameters:	    apply_cust_asset_info* _init -------------------- apply customer asset info
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-20
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_init_apply_custmor_assets_info(apply_cust_asset_info* _init);

//初始化用户家庭信息
/*********************************************************************************************************
** Function name:			apply_init_apply_customer_family_info
**
** Descriptions:			initialize apply customer family info
**
** input parameters:	    apply_cust_family_info* _init -------------------- customer family infomation
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-20
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_init_apply_custmor_family_info(apply_cust_family_info* _init);

//初始化贷款信息
/*********************************************************************************************************
** Function name:			apply_init_apply_loan_info
**
** Descriptions:			initialize apply loan information
**
** input parameters:	    apply_loan_info* _init -------------------- apply loan inforamtion
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-20
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_init_apply_loan_info(apply_loan_info* _init);

//初始化输入信息
/*********************************************************************************************************
** Function name:			apply_init_apply_input_info
**
** Descriptions:			initialize apply input information
**
** input parameters:	    apply_input_info* _init -------------------- apply input information
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-20
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_init_apply_input_info(apply_input_info* _init);
