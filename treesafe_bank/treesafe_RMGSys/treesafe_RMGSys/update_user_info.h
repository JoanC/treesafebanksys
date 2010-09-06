#include "database_mgr.h"
#include "sys_error_compute.h"


#define UPDATE_USER_ADDR_LEN 64
#define UPDATE_USER_EMAIL_LEN 50
#define UPDATE_USER_TEL_LEN 12

struct update_user_info_input{
	//只能改家庭住址,联系电话,电子邮件
	char new_addr[UPDATE_USER_ADDR_LEN];
	char new_email[UPDATE_USER_EMAIL_LEN];
	char new_tel[UPDATE_USER_TEL_LEN];
};

struct update_user_info_info{
	sys_err err_info;
};

struct update_user_info{
	update_user_info_input input_info;
	update_user_info_info rlt_info;
};

//模块30
//修改客户的联系信息

//