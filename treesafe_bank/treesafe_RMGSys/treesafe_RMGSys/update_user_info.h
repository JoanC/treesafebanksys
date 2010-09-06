#include "database_mgr.h"
#include "sys_error_compute.h"


#define UPDATE_USER_ADDR_LEN 64
#define UPDATE_USER_EMAIL_LEN 50
#define UPDATE_USER_TEL_LEN 12

struct update_user_input{
	//ֻ�ܸļ�ͥסַ,��ϵ�绰,�����ʼ�
	char new_addr[UPDATE_USER_ADDR_LEN];
	char new_email[UPDATE_USER_EMAIL_LEN];
	char new_tel[UPDATE_USER_TEL_LEN];
};

struct update_user_info{
	sys_err err_info;
};

struct update_user_modle{
	update_user_input input_info;
	update_user_info rlt_info;
};

//ģ��30

//30.1
//�޸Ŀͻ�����ϵ��Ϣ

//��ʼ����������

void init_update_user_input(update_user_input* _init);

void init_update_user_info(update_user_info* _init);

update_user_modle* init_update_user_modle();

void release_update_user_modle(update_user_modle* _release);

//30.2
//��ȡ������Ϣ

void update_user_copy_cmd(const char* _cmd,char* _dest
	,int _cmd_len);

update_user_input* update_user_convert_cmd(char* _info);

update_user_input* update_user_get_cmd(const char* _cmd
	,int _cmd_len);

//30.3
//sunni���

void update_user_set_data(char* _card_id , update_user_input* _input);

//30.4
void update_user_convert_rlt(update_user_info* _info,char* _rlt,int* _rlt_len);

//ģ��30����ʽ
void update_user_frame(const char* _cmd , int _cmd_len , char* _rlt,int* _rlt_len);

