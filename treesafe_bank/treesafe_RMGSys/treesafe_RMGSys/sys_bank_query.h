#pragma once

#include "sys_connc_banksys_db.h"//���ݿ�Э��
//#include "treesate_cClient.h"//�û����罻��

/************************************************/
//ģ��7
//��������ϵͳ�Ľ�����ѯ
//��ģ����ducky���

//�����в�ѯһ�廯
//�������е������̶���,���粿����ʵ�ǲ��ɼ���
//�û�(Ҳ������Щ������),��һ������,��ʵ��ϣ���õ�һ�����
//����εõ�������,����ģ��7������
 /*********************************************************************************************************
** Function name:			sys_connc_bank_query
**
** Descriptions:			bank query system
**
** input parameters:	    bankDB_request_info* _req<i>
**							bankDB_result_info* _rlt<o>
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
void sys_connc_bank_query(bankDB_request_info* _req , bankDB_result_info* _rlt);