//模块6 -- 普通用户注册注册
/******************************************/
//此模块仅仅处理普通的用户处理程式
//而雇员的增加与减少则是在管理员的(管理雇员)模块功能中实现
#include "sys_error_compute.h"
#include "database_mgr.h"
#include "treesate_cClient.h"//需要与银行子系统进行进行交互

#define REG_MAX_USER_NAME idlen
#define REG_MAX_USER_PWD pwdLen
#define REG_MAX_USER_BANK_ID 18//十八位身份证号
#define REG_MAX_OTHER_STR_LEN 128

typedef char REG_USER_NAME;
typedef char REG_USER_PWD;

struct reg_info{
	//用户注册所需的相关信息

};