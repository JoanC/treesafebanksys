#include "sys_apply_info.h"
#include "database_mgr.h"//数据库操作
#include "sys_error_compute.h"//错误信息

//模块27
//检测一个用户是否有申请信息
#define USER_HAS_APP_ID_LEN 19

struct user_has_app_input{
	char card_id[USER_HAS_APP_ID_LEN];
};

struct user_has_app_info{
	bool user_has_app;//true表示有,false表示没有
	sys_err err_info;
};

struct user_has_app_modle{
	user_has_app_input input_info;
	user_has_app_info rlt_info;
};

//27.1
//初始化系统

//初始化输入信息
void init_user_has_app_input(user_has_app_input* _init);
//初始化结果信息
void init_user_has_app_info(user_has_app_info* _init);
//初始化27整体模块
user_has_app_modle* init_user_has_app_modle();
//释放模块和数据结构
void release_user_has_app_modle(user_has_app_modle* _release);


//27.2
//指令接受

void user_has_app_copy_cmd();