#pragma once
#include "sys_error_compute.h"



#define USER_NAME_LEN 19
#define USER_CARD_ID 19
#define USER_TEL_LEN 12//�绰
#define USER_ADDR_LEN 64

enum user_query_gender{
	user_query_gender_male = 0,//��
	user_query_fender_female = 1 //Ů
};

struct user_query_info{
	//һ���û��Ļ�����Ϣ
	int user_gender;//�û��Ա�
	int user_age;//�û�����
	char user_name[USER_NAME_LEN];//�û���
	char user_card_id[USER_CARD_ID];//���֤id
	char user_tel[USER_TEL_LEN];//�û��绰��ϵ��ʽ 
	char user_addr[USER_ADDR_LEN];//�û���ַ
};

struct user_query_array_info{
	int user_num;
	user_query_info user_array[30];
};

/***********************************/
//��ʼ������

//��ʼ���û�������Ϣ
 /*********************************************************************************************************
** Function name:			init_user_query_info
**
** Descriptions:			query user info
**
** input parameters:	    user_query_info* _init<o>
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
void init_user_query_info(user_query_info* _init);

//��ʼ���û���������Ϣ
 /*********************************************************************************************************
** Function name:			init_user_query_array_info
**
** Descriptions:			initialize user array info
**
** input parameters:	    int _size<i>
**							user_query_array_info* _init<o>
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
void init_user_query_array_info(int _size,user_query_array_info* _init);