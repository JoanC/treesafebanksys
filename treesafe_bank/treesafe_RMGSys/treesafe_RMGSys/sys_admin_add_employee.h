#pragma once

#include "database_mgr.h"//���ݿ⴦��ʽ
#include "sys_error_compute.h"//������

//ģ��15
//����Ա���� -- ��ӹ�Ա
//�������һ����Ա

#include "sys_admin_employee_info.h"


#define ADD_EMPLOYEE_COMMENT_LEN 201

extern _ConnectionPtr* treesafe_db_connection ;
//��ӹ�Աʱ�������Ϣ

struct add_employee_input{
	admin_employee_info employ_basic_info;
	char comment[ADD_EMPLOYEE_COMMENT_LEN];
};


//��ӹ�Ա�Ľ����Ϣ
struct add_employee_info{
	bool is_succ;//����Ƿ�ɹ�
	sys_err err_info;//������Ϣ
};

struct add_employee_modle{
	add_employee_input input_info;//������Ϣ
	add_employee_info rlt_info;//�����¼��Ϣ
};


/*****************************************/
//ģ��15.1
//���ݽṹ��ʼ�����ͷ�
//Jiraiya���

//��ʼ���������Ϣ
 /*********************************************************************************************************
** Function name:			init_add_employee_input
**
** Descriptions:			init add employee input info
**
** input parameters:	    add_employee_input* _init
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void init_add_employee_input(add_employee_input* _init);

//��ʼ����ӹ�Ա�Ľ����¼��Ϣ
 /*********************************************************************************************************
** Function name:			init_add_employee_info
**
** Descriptions:			init add employee info
**
** input parameters:	    add_employee_input* _init
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void init_add_employee_info(add_employee_info* _init);

//��ʼ����ӹ�Ա����ģ��
 /*********************************************************************************************************
** Function name:			init_add_employee_modle
**
** Descriptions:			init add employee info main frame
**
** input parameters:	    NULL
** Returned value:		    add_employee_modle*
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
add_employee_modle* init_add_employee_modle();

//�ͷ�ģ��
 /*********************************************************************************************************
** Function name:			release_add_employee_modle
**
** Descriptions:			release add employee info main frame
**
** input parameters:	    add_employee_modle* _release
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void release_add_employee_modle(add_employee_modle* _release);

/******************************************/
//ģ��15.2
//Jiraiya���
//����ָ����Ϣ
//�����ܵ�ָ��ת�����������Ϣ
//Jiraiya���

//����ָ����Ϣ
 /*********************************************************************************************************
** Function name:			add_employee_copy_cmd
**
** Descriptions:			copy command
**
** input parameters:	    const char* _cmd 
**							char* _dest 
**							int _cmd_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void add_employee_copy_cmd(const char* _cmd , char* _dest , int _cmd_len);

//ת��ָ��,����ת��Ϊ�������Ϣ
 /*********************************************************************************************************
** Function name:			add_employee_convert_cmd
**
** Descriptions:			convert command
**
** input parameters:	    char* info
** Returned value:		    add_employee_input
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
add_employee_input* add_employee_convert_cmd(char* _info);

//15.2�ܺ�ʽ
//ת�����Ҹ���ָ��
 /*********************************************************************************************************
** Function name:			add_employee_get_Cmd
**
** Descriptions:			get command
**
** input parameters:	    const char* _cmd
**							int _cmd_len
** Returned value:		    add_employee_input
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
add_employee_input* add_employee_get_cmd(const char* _cmd,int _cmd_len);

/********************************************/
//15.3
//sunni���
//���ݿ����
//��������Ϣ������������Ա���*��¼����(�������ű�!!)
 /*********************************************************************************************************
** Function name:			add_employee_to_db
**
** Descriptions:			add employee info to database
**
** input parameters:	    add_employee_input* _input_info
**							bool *_rlt
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void add_employee_to_db(add_employee_input* _input_info, bool *_rlt);

/*********************************************/
//15.4
//��Jiraiya���
//���Ͻ����Ϣ,����ת��Ϊ�ַ���
 /*********************************************************************************************************
** Function name:			add_employee_convert_result
**
** Descriptions:			convert_result
**
** input parameters:	    add_employee_info* _info
**							char* _rlt
**							int* _rlt_len
** Returned value:		    add_employee_input
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void add_employee_covert_result(add_employee_info* _info
	,char* _rlt , int* _rlt_len);

/***********************************************/
//ģ��15����ʽ
 /*********************************************************************************************************
** Function name:			add_employee_frame
**
** Descriptions:			modle main frame
**
** input parameters:	    const char* _cmd
**							int _cmd_len
**							char* _rlt , int* _rlt_len
**							char* _rlt
**							int* _rlt_len
** Returned value:		    add_employee_input
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-8-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void add_employee_frame(const char* _cmd , int _cmd_len
	,char* _rlt , int* _rlt_len);
