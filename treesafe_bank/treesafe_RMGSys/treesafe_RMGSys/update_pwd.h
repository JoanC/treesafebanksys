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
