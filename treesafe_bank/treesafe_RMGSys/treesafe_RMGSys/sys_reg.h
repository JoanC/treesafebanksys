//模块6 -- 普通用户注册注册
/******************************************/
//此模块仅仅处理普通的用户处理程式
//而雇员的增加与减少则是在管理员的(管理雇员)模块功能中实现
#include "sys_error_compute.h"
#include "database_mgr.h"
#include "treesate_cClient.h"//需要与银行子系统进行进行交互
#include "sys_connc_banksys_db.h"

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

struct reg_cust_info{
	REG_USER_ID cust_id[REG_MAX_USER_BANK_ID];//身份id

};

/********************************************************/
//模块6.1
//Jiraiya完成
//登录信息的初始化
//以下过程由Jiraiya完成

//初始化用户将要输入的信息
void reg_init_reg_input_info(reg_input_info* _info);

/*******************************************************/
//模块6.2
//Jiraiya完成
//与用户UI层进行交互
//这是一个类型转换的过程,将cmd的信息转换成input_info

/*6.2子过程*/
//复制信息,避免指针的直接改动
void reg_copy_cmd(char* _dst,char* _cmd_info,int _len);
//类型转换,返回一个reg_input_info类型,即将复制后的信息转化
void reg_convert_cmd(char* _cmd);
//模块3.3主函式
void reg_get_info(char* _cmd , int _len);//输入命令的信息和信息长度

/******************************************************/
//6.3
//协同完成
//将用户输入的身份证id通过net(client)端发送给banksys,在银行段查询是否有此人的信息
//如果没有,返回一个错误结果
//如果有,把这位用户的相关信息从银行系统里调出来,并填充在reg_cust_info中

//由于ducky的接受函数尚未写好,所以这里看看,我觉得还需设计一个模块,把这个过程封
//在一个主函式里,见sys_connc_bank

void 
