#pragma once
#include "sys_apply_info.h"
#include "database_mgr.h"
//ģ��7
//���봦���������Ϣ�ṹ
struct apply_info{
	//��Ҫ������������Ϣ
	//������Ϊ:
	//ֻ��Ҫ�ѶԱȻ�����Ϣʱ�Ĵ��󴫸���ǰ��ҳ��
	//���û�д��� 
	//���ʾ���������ڽ������...
	//�����Ǵ�����Ϣ,���������Ϣ��ʾno_err,��������ɹ�
	bool is_succ;//�Ƿ�ɹ�
	sys_err errInfo;//���봦���еĴ�����Ϣ
};

//���봦�������ģ��
struct apply_modle{
	apply_input_info input_info;//������Ϣ
	apply_custmor_info db_cust_info;//�����ݿ��ж������Ϣ
	apply_info rlt_info;//�洢��������е���Ϣ,��Ϊ��������������
};

/*******************************************************/
//��Jiraiya���
//7.1
//��ʼ������ģ��

//��ʼ������ģ��
/*********************************************************************************************************
** Function name:			apply_init_apply_modle
**
** Descriptions:			initialize apply modle
**
** input parameters:	    apply_modle* _init -------------------- apply modle
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_init_apply_modle(apply_modle* _init);

//�ͷ�ģ��
/*********************************************************************************************************
** Function name:			reg_release
**
** Descriptions:			release register information
**
** input parameters:	    apply_modle* _mld -------------------- apply modle
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_release(apply_modle* _mld);

/*******************************************************/
//ģ��7.2
//�������л�ȡ������Ϣ
// Jiraiya���
/*********************************************************************************************************
** Function name:			apply_get_input_info
**
** Descriptions:			get input information
**
** input parameters:	    const char* _command -------------------- command
**                          int _len -------------------------------- command length
** Returned value:		    apply_input_info ------------------------ input informtion
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
apply_input_info* apply_get_input_info(const char* _command , int _len);

//��������
/*********************************************************************************************************
** Function name:			apply_get_copy_command
**
** Descriptions:			copy get command
**
** input parameters:	    char* _dest -------------------- dest string
**                          const char* _command ----------- source string
**                          int _len ----------------------- string length
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_get_copy_command(char* _dest , const char* _command , int _len);
//������ת��Ϊ�û���������Ϣ
//��Ȼ,���������˫����Э��
/*********************************************************************************************************
** Function name:			reg_add_user_to_db
**
** Descriptions:			add user information to database
**
** input parameters:	    char* _data -------------------- convert data
** Returned value:		    apply_input_info --------------- input apply info
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
apply_input_info* apply_get_convert_input(char* _data);

/******************************************************/
//ģ��7.3
//��sunni���
//�ӷ��տ���ϵͳ�����ݿ��е����û��Ļ�������
//����������һ��apply_custmor_info��
/*********************************************************************************************************
** Function name:			apply_query_cust_info
**
** Descriptions:			query the customer information
**
** input parameters:	    apply_customer_info* _rlt -------------------- query result
**                          bool *_isSucceeded --------------------------- whether has errors
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				sunni
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_query_cust_info(apply_custmor_info* _rlt,bool *_isSucceeded) ;

/******************************************************/
//ģ��7.4
//��jiraiya���
//���û��������Ϣ�����ݿ��������Ϣ���бȶ�
/*********************************************************************************************************
** Function name:			apply_check_cust_info
**
** Descriptions:			check customer infomation
**
** input parameters:	    apply_customer_info* _input -------------------- input user information
**                          apply_customer_info* _db_query ----------------- database query 
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Sunni
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool apply_check_cust_info(apply_custmor_info* _input 
	, apply_custmor_info* _db_query);

/*******************************************************/
//ģ��7.5
//��sunni���
//Ϊ��������Զ����,���������������ݱ�(research_info)��
//������е����ݻ����̶�

//����,���������,Ҫ��"���״̬"
//"��˱�"�������ͬ
//���ģ������"�����"�ı���,���뵽"��˱���"
//��������ʱ���ע��
//��ģ��9��,�Ŵ�"��˱�"����ʽ����һ������,������"�����"

//Ϊ�����������Զ���ŵĴ���,Ҫ��һ�޶�
//����Ҫ����ʹ�ã�����apply_save_to_research_table()�����
/*********************************************************************************************************
** Function name:			apply_save_generate_id
**
** Descriptions:			save generate ID
**
** input parameters:	    char* _outcome -------------------- outcome information
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool apply_save_generate_id(char *_outcome) ;

//���������������˵ı���
/*********************************************************************************************************
** Function name:			apply_save_to_research_table
**
** Descriptions:			save the apply info to research table
**
** input parameters:	    apply_input_info* _info -------------------- input apply information
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool apply_save_to_research_table(apply_input_info* _info) ; 


/*********************************************************/
//ģ��7.6
//��Jiraiya���
//�������
/*********************************************************************************************************
** Function name:			apply_convert_rlt
**
** Descriptions:			convert result 
**
** input parameters:	    apply_info* _info ---------- apply information
**                          char* _rlt ----------------- result
**                          int* _rlt_len -------------- reuslt length
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_convert_rlt(apply_info* _info , char* _rlt , int* _rlt_len);

/********************************************************/
//ģ��7.7
//��jiraiya���
//������
//...
/*********************************************************************************************************
** Function name:			apply_err_compute
**
** Descriptions:			compute error
**
** input parameters:	    sys_err_type _type -------------------- error type
**                          apply_modle* _modle ------------------- apply modle
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_err_compute(sys_err_type _type , apply_modle* _modle);

/********************************************/
//7.8
//������ݳ�ͻ
//��Ҫ�Ǵ���,���������ж�
/*********************************************************************************************************
** Function name:			appy_check_input_data
**
** Descriptions:			check input data
**
** input parameters:	    apply_input_info* _input -------------------- input apply information
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool appy_check_input_data(apply_input_info* _input);

 
/*********************************************************/
//�������̵�����ʽ
/*********************************************************************************************************
** Function name:			apply_frame
**
** Descriptions:			apply frame
**
** input parameters:	    const char* _command -------------------- command
**                          int _len -------------------------------- length
**                          char* _rlt ------------------------------ result
**                          int* _rlt_len --------------------------- result length
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-16
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-9-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void apply_frame(const char* _command , int _len , char* _rlt , int* _rlt_len) ;
