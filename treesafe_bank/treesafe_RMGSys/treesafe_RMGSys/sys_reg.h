//模块6 -- 普通用户注册注册
/******************************************/
//此模块仅仅处理普通的用户处理程式
//而雇员的增加与减少则是在管理员的(管理雇员)模块功能中实现
#pragma once

#include "sys_error_compute.h"
#include "database_mgr.h"
#include "sys_connc_banksys_db.h"
#include "sys_error_compute.h"//错误处理

#define REG_MAX_USER_NAME idLen
#define REG_MAX_USER_PWD pwdLen
#define REG_MAX_USER_BANK_ID 19//十八位身份证号,加'\0'19
#define REG_MAX_ADDR 64//联系地址
#define REG_MAX_OTHER_STR_LEN 256

typedef char REG_USER_NAME;
typedef char REG_USER_PWD;
typedef char REG_USER_ID;
enum REG_GENDER_TYPE{male , female};


struct reg_basic_info{
	//登陆用户名
	REG_USER_ID reg_name[REG_MAX_USER_NAME];
	//用户密码
	REG_USER_PWD reg_pwd[REG_MAX_USER_PWD];
	//身份证号,18位
	REG_USER_ID reg_id[REG_MAX_USER_BANK_ID];
	//用户真实姓名
	char reg_basic_user_name[REG_MAX_USER_NAME];
	//性别
	REG_GENDER_TYPE reg_gender;
	//年龄
	int reg_age;
	//家庭住址
	char reg_home_addr[REG_MAX_ADDR];
};

struct reg_input_info{
	//用户注册所输入的相关信息
	//输入基本信息
	reg_basic_info basic_info;
	//其它的附加信息
	char email_addr[REG_MAX_ADDR];
	//密码两次验证是否正确
	bool is_pwd_vry_crr;
};

struct reg_cust_info{
	REG_USER_ID cust_id[REG_MAX_USER_BANK_ID];//身份id
	//...其它信息
};

//综合信息,即要发送给网络端的信息
struct reg_info{
	//用户名
	//用于在界面上输出"XXX,您好!注册成功"
	REG_USER_ID user_name[REG_MAX_USER_NAME];
	sys_err reg_err;//注册过程中出现的错误和异常
};

//注册过程的整体模块
struct reg_modle{
	bool reg_succ;//注册过程成功
	int command_len;//命令信息的长度
	char command_info[REG_MAX_OTHER_STR_LEN];//命令长度
	/*下面是数据*/
	reg_input_info input_info;//用户输入的信息
	reg_basic_info db_query_from_bank;//从银行系统调出的基础信息
	reg_info info;//注册过程中的数据,也是结果数据
};

/********************************************************/
//模块6.1
//Jiraiya完成
//登录信息的初始化
//以下过程由Jiraiya完成

//初始化注册整体模块
reg_modle* reg_init();
//释放整体模块
void reg_release(reg_modle* _release);

//初始化基本信息
void reg_init_reg_basic_info(reg_basic_info* _init);

//初始化用户将要输入的信息
void reg_init_reg_input_info(reg_input_info* _init);

//初始化用户信息
void reg_init_reg_cust_info(reg_cust_info* _init);

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
void reg_query_user(reg_cust_info* _cust_info);

//生成一个请求信息,_req
void reg_query_user_generate_req(bankDB_request_info* _req);
//查询结果,将结果转化为bankDB_result_cust_info
void reg_query_user_get_rlt(bankDB_result_cust_info* _db_rlt);
//根据_db_rlt,提取相关信息,填充到reg_cust_info中
void reg_query_user_convert_rlt(bankDB_result_cust_info* _db_rlt,reg_cust_info* _cust_info);

/********************************************************/
//6.4
//由Jiraiya完成
//数据对比,对比用户输入的基础信息和从银行调出的信息进行必要的比对
//比对项尚要商讨,比如联系电话可以不用验证
//目前先比对用户真实姓名,性别,年龄,家庭住址
bool reg_info_cmp(reg_basic_info* _input,reg_basic_info* _bank_data);

/********************************************************/
//6.5
//sunni完成
//将注册的用户填入到数据库中
//根据用户信息,将对应的登陆用的用户号和密码,以及身份证号
//内部的转化和扩充后存入db中
//只要存入基础信息即可
void reg_add_user_to_db(reg_basic_info* _info);

/********************************************************/
//6.5
//由Jiraiya完成
//注册结束后,将结果信息转化成将要发送的信息
void reg_generate_result(reg_info* _info , char* _rlt);
