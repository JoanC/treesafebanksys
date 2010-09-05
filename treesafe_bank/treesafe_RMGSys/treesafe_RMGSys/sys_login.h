/****************************************Copyright (c)**************************************************
**                                      treesafe bank system                             
**
**                                
**
**--------------File Info-------------------------------------------------------------------------------
** File name:			sus_login			
** Last modified Date:	2010-7-1
** Last Version:		0.4		
** Descriptions:		the login frame		
**
**------------------------------------------------------------------------------------------------------
** Created by:			Jiraiya
** Created date:		2010-8-14
** Version:				0.1
** Descriptions:		the login frame
**
********************************************************************************************************/
#pragma once

#include "sys_error_compute.h"
#include "database_mgr.h"
#define DEFAULT_INFO_LEN 64

//������ֵ��"sys_db_struct�ж���"
#define MAX_USER_NAME_LEN idLen
#define MAX_USER_PWD_LEN pwdLen

#define MAX_OTHER_STR_LEN 128

typedef char  USER_NAME ;//�û���
typedef char  USER_PWD;//����
//typedef  char* VRY_CODE;//��֤��
typedef bool VRY_RESULT;//��֤��ļ����


//��½ϵͳ

struct login_user_info{
	USER_NAME input_user_name[MAX_USER_NAME_LEN];//�û���
	USER_PWD input_user_pwd[MAX_USER_PWD_LEN];//�û�����
};


struct login_check_info{
	//�û���UI�������Ϣ
	login_user_info user_info;//�û���������

	//???�Ƿ�Ҫ�ڷ������м����֤��???////
	//VRY_CODE input_verify_code;//��֤��
	//VRY_CODE verify_code;//��ȷ��(UI)���ɵ���֤��
	//������õĻ���������Ҫ��һ�������
	bool vry_is_correct;//��֤��ļ�����
};

//һ�ε�½���̵���Ϣ����
struct login_info{
	//�û�Ȩ��
	login_competence		compe ;       													//Ȩ��
	USER_NAME				user_id[MAX_USER_NAME_LEN]	 ;		//�û�id
	sys_err						login_err ;													//������Ϣ
};

//����ģ��
struct login_modle{
	bool login_succ;//��½���̳ɹ�
	login_check_info check_info;
	login_user_info db_query;//���ݿ���3.3�еĲ���ģ��
	login_info rlt_info;
};


//ģ��3--��½
/*********************************************************/
//ģ�� 3.1 
//0.1 -- ģ���ʼ�����ͷ�
//���²�����Jiraiya���
login_modle* login_init();
/*********************************************************************************************************
** Function name:			login_release
**
** Descriptions:			release the login frane	
**
** input parameters:		login_modle* _release------the login_modle struct modules
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void login_release(login_modle* _release);

//�����ṹ��ĳ�ʼ������
/*********************************************************************************************************
** Function name:			login_init_login_user_info
**
** Descriptions:			Init the login user info
**
** input parameters:		login_user_info* _init------the login_user_info modle struct modules
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void login_init_login_user_info(login_user_info* _init);
/*********************************************************************************************************
** Function name:			login_init_login_check_info
**
** Descriptions:			Init the login check info
**
** input parameters:		login_check_info* _init------the login_check_info modle struct modules
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void login_init_login_check_info(login_check_info* _init);
/*********************************************************************************************************
** Function name:			login_init_login_info
**
** Descriptions:			Init the login info
**
** input parameters:		login_info* _init------the login_info modle struct modules
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void login_init_login_info(login_info* _init);

/********************************************************/
//������Jiraiya���
//ģ��3.2
//0.2 -- ������Ϣ����,��ģ��1����Ϣ�����sunni�ɼ�����Ϣ
//��UI�Ľ�����
//����������Ϣ
//�������Ͻ�����Ϣ
//����������,��ʵ����һ��copy,��һ�����ƺ�����ת���Ĺ���
/*********************************************************************************************************
** Function name:			login_get_copy_data
**
** Descriptions:			Init the login user info
**
** input parameters:		const char* _info------dest string
**                          char* _copy_data-------source string
**                          int _len---------------the length of string
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void login_get_copy_data(const char* _info , char* _copy_data , int _len);
/*********************************************************************************************************
** Function name:			login_get_convert
**
** Descriptions:			convert the information
**
** input parameters:		char* _info------the information needed converted
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
login_check_info* login_get_convert(char* _info);


/*********************************************************************************************************
** Function name:			login_get_info
**
** Descriptions:			get the login information
**
** input parameters:		const char* _data------the information 
**                          int _data_len ---------the length of information
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
login_check_info* login_get_info(const char* _data , int _data_len);//��ȡ����֤����Ϣ
/*******************************************************/
//������sunni���
//ģ��3.3
//0.3 -- ��ѯ
//////////////////////////////
//����0.2��username,���в�ѯ(��Ҫȥ�Ƚ�ֵ),������ѯ����洢��һ���ṹ��login_user_info��
//���û�в�ѯ�����û�,���_rlt����false

//�����ѯ�������ӹ���,��sunni�������

/*********************************************************************************************************
** Function name:			login_db_query
**
** Descriptions:			login database query
**
** input parameters:		USER_NAME *_user --------- the user name
**                          login_user_info *_info---- the user information
**                          bool *rlt ---------------- whether database query success
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Sunni
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-8-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void login_db_query(USER_NAME *_user , login_user_info* _info , bool* _rlt);

/******************************************************/
//������Jiraiya���
//ģ��3.4
//0.4 -- ��֤
//����0.2��������Ϣ��0.3�Ĳ�ѯ��Ϣ,������֤ 
//�ɹ�˵����½�ɹ�,����ʧ��,���ʧ��
/*********************************************************************************************************
** Function name:			login_check_name
**
** Descriptions:			check the login name
**
** input parameters:		USER_NAME *_db --------- the user name
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Sunni
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-8-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool login_check_name(USER_NAME* _db);
/*********************************************************************************************************
** Function name:			login_check_name
**
** Descriptions:			check the login name
**
** input parameters:		USER_NAME *_db --------- the user name
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Sunni
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-8-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool login_check_pwd(USER_PWD* _input , USER_PWD* _db);
//void login_check_vry(VRY_CODE _input , VRY_CODE _ui , login_err_type _type);
/*********************************************************************************************************
** Function name:			login_check
**
** Descriptions:			check the login information
**
** input parameters:		login_check_info *_input ----- source information
**                          login_user_info* _db --------- user login information                          
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Sunni
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-8-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool login_check(login_check_info* _input , login_user_info* _db);
/******************************************************/
//������sunni���
//ģ��3.5
//0.5 -- �����½�ɹ�,������ȷ���û�������,���и߼���Ϣ��ѯ����,
//������½��Ϣ����login_info
//����ɹ�,����и�ģ��Ĵ���

//�����login_info��Ҫ��sunni��ô����
/*********************************************************************************************************
** Function name:			login_check
**
** Descriptions:			check the login information
**
** input parameters:		login_check_info *_input ----- source information
**                          login_user_info* _db --------- user login information                          
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Sunni
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-8-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void login_db_summery(login_user_info* _user_info , login_info* _info);

/******************************************************/
//������sunni���
//ģ��3.6
//0.6 -- �����½ʧ��
//���ݴ��������д�����Ϣ�Ĳ�ѯ
//void login_db_err_query(login_err_type _err , char* _err_info);

/******************************************************/
//������Jiraiya���
//ģ��3.7
//0.7�������Ϣ���͸����͹��ɲ�
/*********************************************************************************************************
** Function name:			login_summer_send_info
**
** Descriptions:			check the login information
**
** input parameters:		login_check_info *_input ----- source information
**                          login_user_info* _db --------- user login information                          
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Sunni
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-8-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void login_summer_send_info(login_info* _info);

/******************************************************/
//������Jiraiya���
//ģ��3.8
//0.8���е�½�����еĴ�����

/*********************************************************************************************************
** Function name:			login_err_mgr
**
** Descriptions:			login error message
**
** input parameters:		sys_err_type _err_type ----- error type
**                          lgoin_modle* _mld --------- login modle                        
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Sunni
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-8-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void login_err_mgr(sys_err_type _err_type,login_modle* _mld);

/******************************************************/
//������Jiraiya���
//ģ��3.9
//0.9�����ս�����д���
/*********************************************************************************************************
** Function name:			login_convert_rlt
**
** Descriptions:			check the login information
**
** input parameters:		login_info *_input ----- source information
**                          char* _rlt ------------- result
**                          int* _rlt_len ---------- result length                          
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void login_convert_rlt(login_info* _info , char* _rlt , int* _rlt_len);

/******************************************************/
//��½ģ���������
//Jiraiya����
/*********************************************************************************************************
** Function name:			login_frame
**
** Descriptions:			login frame
**
** input parameters:		const char* _command ----- source information
**                          int _arg_len ------------- argument length
**                          char* _rlt --------------- result          
**                          int* _rlt_len ------------ result length
** Returned value:		    NULL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-18
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-8-30
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void login_frame(const char* _command , int _arg_len , char* _rlt , int* _rlt_len);