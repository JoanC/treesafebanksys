#include "database_mgr.h"
#include "sys_error_compute.h"


#define UPDATE_USER_ADDR_LEN 64
#define UPDATE_USER_EMAIL_LEN 50
#define UPDATE_USER_TEL_LEN 12

struct update_user_input{
	//只能改家庭住址,联系电话,电子邮件
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

//模块30

//30.1
//修改客户的联系信息

//初始化各个数据

void init_update_user_input(update_user_input* _init);

void init_update_user_info(update_user_info* _init);

update_user_modle* init_update_user_modle();

void release_update_user_modle(update_user_modle* _release);

//30.2
//获取输入信息

void update_user_copy_cmd(const char* _cmd,char* _dest
	,int _cmd_len);

update_user_input* update_user_convert_cmd(char* _info);

update_user_input* update_user_get_cmd(const char* _cmd
	,int _cmd_len);

//30.3
//sunni完成

void update_user_set_data(char* _card_id , update_user_input* _input);

//30.4
void update_user_convert_rlt(update_user_info* _info,char* _rlt,int* _rlt_len);

//模块30主函式
void update_user_frame(const char* _cmd , int _cmd_len , char* _rlt,int* _rlt_len);

