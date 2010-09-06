//ģ��6 -- ��ͨ�û�ע��ע��
/******************************************/
//��ģ�����������ͨ���û������ʽ
//����Ա����������������ڹ���Ա��(�����Ա)ģ�鹦����ʵ��
#pragma once

#include "sys_error_compute.h" 
#include "database_mgr.h"
//#include "sys_connc_banksys_db.h"
#include "sys_bank_query.h"


//�ۺ���Ϣ,��Ҫ���͸�����˵���Ϣ
struct reg_info{
	//�û���
	//�����ڽ��������"XXX,����!ע��ɹ�"
	REG_USER_ID user_name[REG_MAX_USER_NAME];
	sys_err reg_err;//ע������г��ֵĴ�����쳣
};

//ע����̵�����ģ��
struct reg_modle{
	bool reg_succ;//ע����̳ɹ�
	/*����������*/
	reg_input_info input_info;//�û��������Ϣ
	reg_basic_info db_query_from_bank;//������ϵͳ�����Ļ�����Ϣ
	reg_info info;//ע������е�����,Ҳ�ǽ������
};

/********************************************************/
//ģ��6.1
//Jiraiya���
//��¼��Ϣ�ĳ�ʼ��
//���¹�����Jiraiya���

//��ʼ��ע������ģ��
/*********************************************************************************************************
** Function name:			reg_init
**
** Descriptions:			initialize register information 
**
** input parameters:	    NULL                       
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
reg_modle* reg_init();
//�ͷ�����ģ��
/*********************************************************************************************************
** Function name:			reg_release
**
** Descriptions:			release register information
**
** input parameters:	    reg_modle* _release ------ register  modle                
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
void reg_release(reg_modle* _release);

//��ʼ��������Ϣ
/*********************************************************************************************************
** Function name:			reg_init_reg_basic_info
**
** Descriptions:			initilize the register basic info
**
** input parameters:	    reg_basic_info* _release ------ the register information needed released          
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
void reg_init_reg_basic_info(reg_basic_info* _init);

//��ʼ���û���Ҫ�������Ϣ
/*********************************************************************************************************
** Function name:			reg_init_reg_input_info
**
** Descriptions:			initilize the register basic info
**
** input parameters:	    reg_basic_info* _release ------ the register information needed released          
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
void reg_init_reg_input_info(reg_input_info* _init);

//��ʼ��ע����̵Ľ����Ϣ
/*********************************************************************************************************
** Function name:			reg_init_reg_info
**
** Descriptions:			initilize the register information
**
** input parameters:	    reg_info* _init ------ the register information needed initilized       
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
void reg_init_reg_info(reg_info* _init);

/*******************************************************/
//ģ��6.2
//Jiraiya���
//���û�UI����н���
//����һ������ת���Ĺ���,��cmd����Ϣת����input_info

/*6.2�ӹ���*/
//������Ϣ,����ָ���ֱ�ӸĶ�
/*********************************************************************************************************
** Function name:			reg_copy_cmd
**
** Descriptions:			copy the information
**
** input parameters:	    char* _release ---------- dest info       
**                          const char* _cmd_info --- source info
**                          int _len ---------------- the length of string
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
void reg_copy_cmd(char* _dst,const char* _cmd_info,int _len);
//����ת��,����һ��reg_input_info����,�������ƺ����Ϣת��
reg_input_info* reg_convert_cmd(char* _info);
//ģ��6.2����ʽ
reg_input_info* reg_get_info(const char* _cmd , int _len);//�����������Ϣ����Ϣ����

/******************************************************/
//6.3
//Эͬ���
//���û���������֤idͨ��net(client)�˷��͸�banksys,�����жβ�ѯ�Ƿ��д��˵���Ϣ
//���û��,����һ��������
//�����,����λ�û��������Ϣ������ϵͳ�������,�������reg_cust_info��

//����ducky�Ľ��ܺ�����δд��,�������￴��,�Ҿ��û������һ��ģ��,��������̷�
//��һ������ʽ��,��sys_connc_bank
/*********************************************************************************************************
** Function name:			reg_query_user
**
** Descriptions:			query register user
**
** input parameters:	    char* _query_id --------------------- query ID
**                          reg_basic_info* _rlt_cust_info ------ customer information
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
void reg_query_user(char* _query_id,reg_basic_info* _rlt_cust_info);

//����һ��������Ϣ,_req
/*********************************************************************************************************
** Function name:			reg_query_user_generate_req
**
** Descriptions:			generate request
**
** input parameters:	    char* _cust_id --------------------- customer ID
**                          bankDB_request_info* _req ---------- requset information
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
void reg_query_user_generate_req(char* _cust_id,bankDB_request_info* _req);
//��ѯ���,�����ת��ΪbankDB_result_cust_info
/*********************************************************************************************************
** Function name:			reg_query_user_get_rlt
**
** Descriptions:			get query resutl
**
** input parameters:	    bankDB_request_info* _req --------------------- query ID
**                          bankDB_result_info* _db_rlt ------ customer information
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
void reg_query_user_get_rlt(bankDB_request_info* _req , bankDB_result_info* _db_rlt);
//����_db_rlt,��ȡ�����Ϣ,��䵽reg_cust_info��
/*********************************************************************************************************
** Function name:			reg_query_user_convert_rlt
**
** Descriptions:			convert query result
**
** input parameters:	    bankDB_result_info* _db_rlt -------------------- result information
**							reg_basic_info* _cust_info --------------------- customer information
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
void reg_query_user_convert_rlt(bankDB_result_info* _db_rlt,reg_basic_info* _cust_info);

/********************************************************/
//6.4
//��Jiraiya���
//���ݶԱ�,�Ա��û�����Ļ�����Ϣ�ʹ����е�������Ϣ���б�Ҫ�ıȶ�
//�ȶ�����Ҫ����,������ϵ�绰���Բ�����֤
//Ŀǰ�ȱȶ��û���ʵ����,�Ա�,����,��ͥסַ
/*********************************************************************************************************
** Function name:			reg_info_cmp
**
** Descriptions:			compare the register information
**
** input parameters:	    reg_basic_info* _input -------------------- result information
**							reg_basic_info* _bank_data --------------------- customer information
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
bool reg_info_cmp(reg_basic_info* _input,reg_basic_info* _bank_data);

/********************************************************/
//6.5
//sunni���
//��ע����û����뵽���ݿ���
//�����û���Ϣ,����Ӧ�ĵ�½�õ��û��ź�����,�Լ����֤��
//�ڲ���ת������������db��
/*********************************************************************************************************
** Function name:			reg_add_user_to_db
**
** Descriptions:			add user information to database
**
** input parameters:	    reg_input_info* _info -------------------- input user information
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
bool reg_add_user_to_db(reg_input_info* _info);

/********************************************************/
//6.6
//��Jiraiya���
//ע�������,�������Ϣת���ɽ�Ҫ���͵���Ϣ
/*********************************************************************************************************
** Function name:			reg_generate_result
**
** Descriptions:			generate register result
**
** input parameters:	    reg_modle* _mld -------------------- input user information
**                          char* _rlt ------------------------- result
**                          int* _rlt_length ------------------- result length
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
void reg_generate_result(reg_modle* _mld , char* _rlt , int* _rlt_len);
/*********************************************************************************************************
** Function name:			reg_summery_rlt_data
**
** Descriptions:			summery result data
**
** input parameters:	    reg_modle* _mld -------------------- register modle
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
void reg_summery_rlt_data(reg_modle* _mld);//��������
/********************************************************/
//6.7
//��Jiraiya���
//ע������еĴ�����ʽ
/*********************************************************************************************************
** Function name:			reg_error_compute
**
** Descriptions:			add user information to database
**
** input parameters:	    sys_err_type _type -------------------- error type
**                          reg_modle* _modle --------------------- register modle
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
void reg_error_compute(sys_err_type _type , reg_modle* _modle);
/********************************************************/
//ģ��6����ʽ
//��Jiraiya���
/*********************************************************************************************************
** Function name:			reg_frame
**
** Descriptions:			register frame
**
** input parameters:	    const char* _command -------------------- command
**                          int _art_len ---------------------------- command length
**                          char* _rlt ------------------------------ reuslt
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
void reg_frame(const char* _command , int _arg_len , char* _rlt , int* _rlt_len);
