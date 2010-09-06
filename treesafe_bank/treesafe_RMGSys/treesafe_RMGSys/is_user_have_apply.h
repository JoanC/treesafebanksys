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

void user_has_app_copy_cmd(const char* _cmd , char* _dest , int _cmd_len);

//数据转化
user_has_app_input* user_has_app_convert_cmd(char* _info);

//获取指令主函式
user_has_app_input* user_has_app_get_cmd(const char* _cmd
	,int _cmd_len);

//27.3
//待sunni完成
//数据库查询

void user_has_app_get_data(char* _card_id , bool* _rlt);


//27.4
//结果信息的转化
void user_has_app_convert_rlt(user_has_app_info* _info
	,char* _rlt,int* _rlt_len);

//模块27的主函式
void user_has_app_frame(const char* _cmd,int _cmd_len,
	);