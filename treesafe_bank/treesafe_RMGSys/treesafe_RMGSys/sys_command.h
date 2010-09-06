#pragma once
//ģ��2

//���������̶�Ҫ����
#include "sys_error_compute.h"//������ģ��
#include "net.h"//�����
#include "sys_login.h"//��½��������
#include "sys_reg.h"//ע���ӹ���
#include "sys_apply.h"//�����ӹ���
#include "sys_admin_add_employee.h"//���ӹ�Ա
#include "sys_admin_delete_employee.h"//ɾ����Ա
#include "research_commit.h"//�ύ��˽��
#include "sys_research_info_query.h"//��ѯ���������Ϣ
#include "sys_research_exact.h"//��ȡ�����Ϣid
#include "sys_employee_query.h"//��ѯ��Ա�Ļ�����Ϣ
#include "query_user_info_array.h"//��ѯ���е��û���Ϣ
#include "sys_get_score.h"//�洢,��������
#include "query_score.h"//��ѯ����
#include "query_one_user_info.h"//��ѯ���˵Ļ�����Ϣ


typedef char* COMMAND_DATA;
#define SYS_CMD_MAX_RLT_SIZE 128*128
#define SYS_CMD_MAX_SIZE 3072

enum{
	//�����ż���
	sys_cmd_login = 0,//��¼ָ��
	sys_cmd_reg = 1,//ע��ָ��
	sys_cmd_apply = 2,//�ύ����ָ��
	sys_cmd_add_employee = 3,//���ӹ�Ա
	sys_cmd_delete_employee = 4,//ɾ����Ա
	sys_cmd_commit_research = 5,//���ύ�����Ϣ
	sys_cmd_query_research = 6,//��ѯ���������Ϣ
	sys_cmd_exact_research = 7,//��ȡһ���µ�(δ����˵�)app_id
	sys_cmd_query_employee = 8,//�����¹�Ա����Ϣ
	sys_cmd_query_user_array = 9,//��ѯ���е��û���Ϣ
	sys_cmd_get_user_score = 10,//�洢���������
	sys_cmd_query_user_score = 11,//��ȡ�û��ķ���
	sys_cmd_query_one_user_info = 12,//��ѯһ���û�����Ϣ
	sys_cmd_unexpect = -1//δ֪����(���ɽ���)
};  

struct sys_net_data{
	int type;//��������
	int len;//�����
	char data[SYS_CMD_MAX_SIZE];//�����е�����
};

/************************************************/
//ģ��2
// ��net�е�ָ��-->ת��-->��Ҫ���͵�����
//���ܹ��̵Ĺ���ģ��
//��ģ����Jiraiya�����鳤���

//��ģ�鱾����һ��Э��
//ÿ��ģ�����������д���������
//����data���͵���Ӧ���ӹ�����ȥ

/***********************************************/
//ģ��2.1
//��ʼ�����ͷ�sys_net_info
void sys_command_init_sys_net_data(sys_net_data* _init);
void sys_command_release_sys_net_data(sys_net_data* _release);

/************************************************/
//ģ��2.2
//0.2 -- ������Ľ�����Ϣת��Ϊ������Ϣ
void sys_command_convert(net_recieved_info* _rev , sys_net_data* _cmd);

/************************************************/
//ģ��2.3
//0.3 -- �������������������,�������Խ���,��ִ����Ӧ�������̺�ʽ
//һ�����switch_case
//���ݲ�ͬ���������,���ò�ͬ�Ĵ�����
//����ָ��Ľ�����ڽ�Ҫ���͵�һ��net_datazhogn 
void sys_command(const sys_net_data* _command,char* _rlt,int* _rlt_len);


//ģ��2.4
//0.4��ͬ���Ӵ�����

//��½ģ��Ĵ�����2.4.1
 /*********************************************************************************************************
** Function name:			sys_command_login
**
** Descriptions:			login command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiaraya
** Created Date:			2010-8-30
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiaraya
** Modified date:			2010-8-31
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void sys_command_login(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);

//ע��ģ���Ӵ���ʽ2.4.2
 /*********************************************************************************************************
** Function name:			sys_command_reg
**
** Descriptions:			register command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
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
void sys_command_reg(const sys_net_data* _cmd , char* _rlt,int* _rlt_len);

//����ģ����Ӵ���ʽ2.4.3
 /*********************************************************************************************************
** Function name:			sys_command_apply
**
** Descriptions:			apply command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt,int* _rlt_len
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
void sys_command_apply(const sys_net_data* _cmd , char* _rlt,int* _rlt_len);

//���ӹ�Աģ�����Ӻ�ʽ2.4.4
 /*********************************************************************************************************
** Function name:			sys_command_add_employee
**
** Descriptions:			add employee command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
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
void sys_command_add_employee(const sys_net_data* _cmd , char* _rlt,int* _rlt_len);

//ɾ����Ա�Ӻ�ʽ2.4.5
 /*********************************************************************************************************
** Function name:			sys_command_delete_employee
**
** Descriptions:			delete employee command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
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
void sys_command_delete_employee(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);

//�ύ��˽���Ӻ�ʽ2.4.6
 /*********************************************************************************************************
** Function name:			sys_command_commit_research
**
** Descriptions:			commit research command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
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
void sys_command_commit_research(const sys_net_data* _cmd, char* _rlt,int* _rlt_len);

//��ѯ���������Ϣ��������Ӻ�ʽ2.4.7
 /*********************************************************************************************************
** Function name:			sys_command_query_research
**
** Descriptions:			query research command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
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
void sys_command_query_research(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);

//��ȡ�����Ϣ�����Ӻ�ʽ2.5.8
 /*********************************************************************************************************
** Function name:			sys_command_exact_research
**
** Descriptions:			exact research command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
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
void sys_command_exact_research(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);

//��ѯ��Ա�Ĵ���ʽ2.5.9
 /*********************************************************************************************************
** Function name:			sys_command_query_employee
**
** Descriptions:			query_employee command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
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
void sys_command_query_employee(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);

//��ѯ�û����鴦��ʽ2.5.10
 /*********************************************************************************************************
** Function name:			sys_command_query_user_array
**
** Descriptions:			query user array command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
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
void sys_command_query_user_array(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);
 /*********************************************************************************************************
** Function name:			sys_command_get_score
**
** Descriptions:			get and calcu the user score command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
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
//2.5.11
void sys_command_get_score(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);

/*********************************************************************************************************
** Function name:			sys_command_get_score
**
** Descriptions:			get and calcu the user score command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
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
//2.5.12
void sys_command_query_user_score(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);

/*********************************************************************************************************
** Function name:			sys_command_get_score
**
** Descriptions:			get and calcu the user score command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
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
//2.5.13
void sys_command_query_one_user_info(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);


//ģ��2.5
//δ֪����Ĵ���ʽ
 /*********************************************************************************************************
** Function name:			sys_command_err
**
** Descriptions:			error command
**
** input parameters:	    const sys_net_data* _cmd
							char* _rlt
							int* _rlt_len
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
void sys_command_err(const sys_net_data* _command,char* _rlt,int* _rlt_len);

//����ģ��
 /*********************************************************************************************************
** Function name:			sys_command_run_frame
**
** Descriptions:			run command frame
**
** input parameters:	    net_recieved_info* _rev <i>
							net_send_info* _send <o>
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
void sys_command_run_frame(net_recieved_info* _rev , net_send_info* _send);
