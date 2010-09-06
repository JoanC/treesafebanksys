#pragma once

#include "sys_admin_employee_info.h"
#include "sys_error_compute.h"//������
#include "database_mgr.h"


extern _ConnectionPtr* treesafe_db_connection ;
//ģ��16
//ɾ����Ա��Ϣ

//�������Ϣ
//��ʵ���Ǹ���һ��idȥɾ���û�
struct delete_employee_input{
	char employee_id[EMPLOYEE_ID_LEN];//���֤����
};

//�����Ϣ
//��ʵ����һ���Ƿ�ɾ���ɹ��ı��
struct delete_employee_info{ 
	bool is_succ;//�Ƿ�ɾ���ɹ�
	sys_err err_info;//������Ϣ
};

//ģ��16������
struct delete_employee_modle{
	delete_employee_input input_info;
	delete_employee_info rlt_info;
};

/*******************************************/
//ģ��16.1
//��ʼ�����ͷ�ģ��
//��Jiraiya���


//��ʼ���������Ϣ
 /*********************************************************************************************************
** Function name:			init_delete_employee_input
**
** Descriptions:			init deltet employee input info
**
** input parameters:	    delete_employee_input* _init
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void init_delete_employee_input(delete_employee_input* _init);

//��ʼ�������¼��Ϣ
 /*********************************************************************************************************
** Function name:			init_delete_employee_info
**
** Descriptions:			init deltet employee info
**
** input parameters:	    delete_employee_info* _init
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void init_delete_employee_info(delete_employee_info* _init);

//��ʼ��ģ��16������
 /*********************************************************************************************************
** Function name:			init_delete_employee_modle
**
** Descriptions:			init deltet employee modle
**
** input parameters:	    NULL
** Returned value:		    delete_employee_modle*
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
delete_employee_modle* init_delete_employee_modle();

//�ͷ�ģ��
 /*********************************************************************************************************
** Function name:			release_delete_modle_employee
**
** Descriptions:			release delete employee info
**
** input parameters:	    delete_employee_modle* _release
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void release_delete_modle_employee(delete_employee_modle* _release);

/*********************************************/
//ģ��16.2
//����ָ��
//Jiraiya���

//16.2����ʽ
 /*********************************************************************************************************
** Function name:			delete_employee_get_cmd
**
** Descriptions:			get command
**
** input parameters:	    const char* _cmd
**							int _cmd_len
** Returned value:		    delete_employee_input*
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
delete_employee_input* delete_employee_get_cmd(const char* _cmd,int _cmd_len);

//��������
 /*********************************************************************************************************
** Function name:			delete_employee_copy_cmd
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
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void delete_employee_copy_cmd(const char* _cmd , char* _dest 
	, int _cmd_len);

//ת��ָ��
 /*********************************************************************************************************
** Function name:			delete_employee_convert_cmd
**
** Descriptions:			convert command
**
** input parameters:	    char* _info
** Returned value:		    delete_employee_input*
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
delete_employee_input* delete_employee_convert_cmd(char* _info);

/*********************************************/
//ģ��16.3
//���ݿ����
//sunni���
 /*********************************************************************************************************
** Function name:			delete_employee_from_database
**
** Descriptions:			delete employee info from db
**
** input parameters:	    const char* _id
**							bool* _rlt
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				sunni
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void delete_employee_from_database(const char* _id , bool* _rlt);

/*********************************************/
//ģ��16.4�ܽ�����Ϣ
//�����ת�����ַ�����Ϣ

 /*********************************************************************************************************
** Function name:			delete_employee_convert_rlt
**
** Descriptions:			convert result
**
** input parameters:	    delete_employee_info* _info
**							char* _rlt , int* _rlt_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void delete_employee_convert_rlt(delete_employee_info* _info , char* _rlt , int* _rlt_len);

/**********************************************/
//��Ϣɾ��ģ��
//ģ��16������ʽ
 /*********************************************************************************************************
** Function name:			delete_employee_frame
**
** Descriptions:			this main frame
**
** input parameters:	    const char* _cmd
**							int _cmd_len
**							char* _rlt
**							int* _rlt_len
** Returned value:		    delete_employee_input*
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-21
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void delete_employee_frame(const char* _cmd , int _cmd_len , char* _rlt , int* _rlt_len);
