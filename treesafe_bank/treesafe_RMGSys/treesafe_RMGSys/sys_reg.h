//模块6 -- 普通用户注册注册
/******************************************/
//此模块仅仅处理普通的用户处理程式
//而雇员的增加与减少则是在管理员的(管理雇员)模块功能中实现
#include "sys_error_compute.h"
#include "database_mgr.h"
#include "treesate_cClient.h"//需要与银行子系统进行进行交互

#define REG_MAX_USER_NAME idLen
#define REG_MAX_USER_PWD pwdLen
#define REG_MAX_USER_BANK_ID 18//十八位身份证号
#define REG_MAX_EMAIL_ADDR 32//联系邮箱地址
#define REG_MAX_OTHER_STR_LEN 128

typedef char REG_USER_NAME;
typedef char REG_USER_PWD;
typedef char REG_USER_ID;

struct reg_input_info{
	//用户注册所输入的相关信息
	//输入登陆用户名
	REG_USER_NAME reg_name[REG_MAX_USER_NAME];
	//输入的用户密码
	REG_USER_PWD reg_pwd[REG_MAX_USER_PWD];
	//密码两次验证是否正确
	bool is_pwd_vry_crr;
	//身份证号,18位
	REG_USER_ID reg_id[REG_MAX_USER_BANK_ID];
};

/********************************************************/
//模块3.1
//Jiraiya完成
//登录信息的初始化
//以下过程由Jiraiya完成

//初始化用户将要输入的信息
void reg_init_reg_input_info(reg_input_info* _info);

/*******************************************************/
//模块3.2
//Jiraiya完成
//与用户UI层进行交互
//这是一个类型转换的过程,将cmd的信息转换成input_info

//复制信息,避免指针的直接改动
