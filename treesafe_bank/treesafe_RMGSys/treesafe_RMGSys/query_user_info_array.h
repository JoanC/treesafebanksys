#pragma once

#include "query_user_info.h"
#include "database_mgr.h"
#include "sys_error_compute.h"

//ģ��20
//��ѯ����ӵ�д����ũ����Ϣ
//���� ���Ѿ����ڱ����ͨ����ũ����Ϣ


struct user_query_arr_input{};//�սṹ��

struct user_query_arr_info{
	//sys_err err_info;
	user_query_array_info query_arr_info;//������Ϣ
};//�����Ϣ

struct user_query_arr_modle{
	user_query_arr_input input_info;
	user_query_arr_info rlt_info;
};

//20.1
//jiraiya ���
//��ʼ���ṹ��
//��ʼ��ģ��20����ģ��
 /*********************************************************************************************************
** Function name:			init_user_query_arr_modle
**
** Descriptions:			initialize user query arr modle
**
** input parameters:	    NULL
** Returned value:		    user_query_arr_modle
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-8-23
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
user_query_arr_modle* init_user_query_arr_modle();

//�ͷ�ģ��
 /*********************************************************************************************************
** Function name:			release_user_query_arr_modle
**
** Descriptions:			release usert query arr modle
**
** input parameters:	    user_query_arr_modle* _release
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-8-23
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void release_user_query_arr_modle(user_query_arr_modle* _release);

//20.2
//��ȡָ��
//����ָ��
 /*********************************************************************************************************
** Function name:			user_query_copy_cmd
**
** Descriptions:			copy command
**
** input parameters:	    const char* _cmd
**							char* _dest
**							int _cmd_len
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-8-23
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void user_query_copy_cmd(const char* _cmd , char* _dest, int _cmd_len);

//ת��ָ��
 /*********************************************************************************************************
** Function name:			user_query_convert_cmd
**
** Descriptions:			convert  command
**
** input parameters:	    char* _info
** Returned value:		    user_query_arr_input*
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-8-23
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
user_query_arr_input* user_query_convert_cmd(char* _info);
 /*********************************************************************************************************
** Function name:			query_user_arr_get_cmd
**
** Descriptions:			get command
**
** input parameters:	    const char* _cmd
**							int _cmd_len
** Returned value:		    user_query_arr_input
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-8-23
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
user_query_arr_input* query_user_arr_get_cmd(const char* _cmd,int _cmd_len);

//20.3
//sunni���
//�õ�����ũ�������,��Щ�˵��������б����ͨ��������
//���������һ��������
 /*********************************************************************************************************
** Function name:			user_query_arr_count
**
** Descriptions:			query user array counnt
**
** input parameters:	    int * _count
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-8-23
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool user_query_arr_count(int* _count) ;

//20.4
//sunni���
//�õ�һ������
//�����д����Щũ�����Ϣ
//�������һ��ָ����
 /*********************************************************************************************************
** Function name:			user_query_arr
**
** Descriptions:			query user array 
**
** input parameters:	    ser_query_arr_info* user_array
**							int* _arr_size
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-8-23
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool user_query_arr(user_query_arr_info* user_array,int* _arr_size) ;

//20.5
//ת���������
 /*********************************************************************************************************
** Function name:			user_query_arr_connvert_rlt
**
** Descriptions:			connvert reuslt
**
** input parameters:	    user_query_arr_info* _info
**							char* _rlt
**							int* _rlt_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraiya
** Created Date:			2010-8-23
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraiya
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void user_query_arr_convert_rlt(user_query_arr_info* _info,char* _rlt,int* _rlt_len);


//ģ��20������ʽ
 /*********************************************************************************************************
** Function name:			user_query_arry_frame
**
** Descriptions:			query user array frame
**
** input parameters:	    const char* _cmd ----- command
**							int _cmd_len --------- command length
**							char* _rlt ----------- result
**							int* _rlt_len -------- result length
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-8-23
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-8-23
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void user_query_array_frame(const char* _cmd,int _cmd_len,char* _rlt,int* _rlt_len);