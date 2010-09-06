#include "sys_apply_info.h"
#include "database_mgr.h"//数据库操作
#include "sys_error_compute.h"//错误信息

//模块27
//检测一个用户是否有申请信息
#define USER_HAS_APP_ID_LEN 19

struct user_has_app_input{
	char card_id[USER_HAS_APP_ID_LEN];
};

//27.1
//初始化系统

void init_