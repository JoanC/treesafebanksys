#include "database_mgr.h"
#include "sys_error_compute.h"

#define UPDATE_PWD_USER_NAME_ID 19
#define UPDATE_PWD_LEN 16

struct update_pwd_input{
	char user_id[UPDATE_PWD_USER_NAME_ID];
	char new_user_pwd[UPDATE_PWD_LEN];
};

struct update_pwd_info{
	sys_err err_info;
};

struct update_pwd_modle{
	update_pwd_input input_info;
	update_pwd_info rlt_info;
};

//模块29
//修改用户密码

//29.1

void init_update_pwd_input(update_pwd_input* _init);

void init_update_pwd_input(update_pwd_input* _init);

update_pwd_modle* init_update_pwd_modle();

void release_update_pwd_modle(update_pwd_modle* _init);

//29.2

void update_pwd_copy_cmd(const char* _cmd , char* _dest ,int _cmd_len);

update_pwd_input* update_pwd_convert_cmd(char* _info);

update_pwd_input* update_pwd_get_cmd(const char* _cmd , int _cmd_len);

//29.3
//数据库操作
//待sunni完成

void update_pwd_set_