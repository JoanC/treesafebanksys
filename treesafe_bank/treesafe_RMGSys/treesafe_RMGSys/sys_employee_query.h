#pragma once

#include "database_mgr.h"//���ݿ����
#include "sys_error_compute.h"//������

//ģ��19
//�����Ĺ�Ա��Ϣ��ѯ
//ͨ������,��ѯһ����Ա�ľ�����Ϣ

//��Ա��Ϣ��ѯ����
typedef admin_employee_info employee_query_data;

//������Ϣ
struct employee_query_input_info{
	char work_id[19];//����Ĺ�Ա����
};

//�����͵Ľ����Ϣ 
struct employee_query_info{
	employee_query_data query_data;//���ݿ��ѯ���
	//ϵͳ����
	sys_err err_info;
};

//ģ��19����ģ��ṹ��
struct employee_query_modle{
	//������Ϣ
	employee_query_input_info input_info;
	//��ѯ�����еõ��Ľ����Ϣ
	employee_query_info rlt_info;
};

/***************************************/
//19.1
//��ʼ�����ͷ�ģ�鼰������
//Jiraiya���
 /*********************************************************************************************************
** Function name:			init_employee_query_input_info
**
** Descriptions:			initialzie employee query input info
**
** input parameters:	    employee_query_input_info* _init
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void init_employee_query_input_info(employee_query_input_info* _init);
 /*********************************************************************************************************
** Function name:			init_employee_query_info
**
** Descriptions:			initialzie employee query info
**
** input parameters:	    employee_query_input_info* _init
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void init_employee_query_info(employee_query_info* _init);

 /*********************************************************************************************************
** Function name:			init_employee_query_modle
**
** Descriptions:			initialzie employee query modle
**
** input parameters:	    NULL
** Returned value:		    employee_query_modle*
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
employee_query_modle* init_employee_query_modle();

 /*********************************************************************************************************
** Function name:			release_employee_query_modle
**
** Descriptions:			release employee query modle
**
** input parameters:	    employee_query_modle*
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void release_employee_query_modle(employee_query_modle* _release);

/*****************************************/
//19.2
//���Ʋ�ת��ָ��
//Jiraiya���

//��������
 /*********************************************************************************************************
** Function name:			employee_query_copy_cmd
**
** Descriptions:			copy command
**
** input parameters:	    const char* _cmd 
							char* _dest
							int _cmd_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void employee_query_copy_cmd(const char* _cmd ,char* _dest, int _cmd_len);

//����ת��
//��ָ���е����ݶ��뵽������Ϣ��
 /*********************************************************************************************************
** Function name:			employee_query_convert_cmd
**
** Descriptions:			convert command
**
** input parameters:	    char* _info 
** Returned value:		    employee_query_input_info*
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
employee_query_input_info* employee_query_convert_cmd(char* _info);

//19.2����ʽ
 /*********************************************************************************************************
** Function name:			employee_query_get_cmd
**
** Descriptions:			get command
**
** input parameters:	    char* _info 
** Returned value:		    const char* _cmd
**							int _cmd_len
** Used global variables:	employee_query_input_info*
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
employee_query_input_info* employee_query_get_cmd(const char* _cmd
	,int _cmd_len);

/*******************************************/
//19.3
//���ݿ��ѯ
//sunni���
//ͨ������,����Ա����Ϣ�����ݿ��е���
 /*********************************************************************************************************
** Function name:			employee_query_get_data
**
** Descriptions:			get employee info
**
** input parameters:	    const char* _work_id<>
**							employee_query_data* _info<o>
**							bool* _rlt<o>
** Returned value:		    const char* _cmd
**							int _cmd_len
** Used global variables:	employee_query_input_info*
** Calling modules:			NULL
**
** Created by:				suuni
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				sunni
** Modified date:			2010-8-15
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void employee_query_get_data(const char* _work_id
	,employee_query_data* _info,bool* _rlt);

/********************************************/
//19.4
//�������ݽ��
//Jiraiya���
//����ѯ���ת��Ϊ����
 /*********************************************************************************************************
** Function name:			employee_query_convert_rlt
**
** Descriptions:			get command
**
** input parameters:	    employee_query_info* _info
**							char* _rlt
**							int* _rlt_len
** Returned value:		    const char* _cmd
**							int _cmd_len
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void employee_query_convert_rlt(employee_query_info* _info,
	char* _rlt , int* _rlt_len);

/*********************************************/
//ģ��19������ʽ
 /*********************************************************************************************************
** Function name:			employee_query_frame
**
** Descriptions:			query frame
**
** input parameters:	    const char* _cmd
**							int _cmd_len
**							char* _rlt
**							int* _rlt_len
** Returned value:		    NULL
** Used global variables:	employee_query_input_info*
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-15
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-18
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void employee_query_frame(const char* _cmd , int _cmd_len
	,char* _rlt,int* _rlt_len);

