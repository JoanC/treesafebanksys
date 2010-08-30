#pragma once
#include "sys_admin_employee_info.h" 
//数据库总管理函数
//为所有模块提供接口
//以表(table)为基础设计struct的结构
#include "sys_db_struct.h"
#include<stdio.h>
#include<conio.h>
#include "sys_error_compute.h"//错误处理
#import "C:\\Program Files\\Common Files\\System\\ado\\msado25.tlb" no_namespace rename("EOF","rsEOF")

#define PWD_LEN 16
#define REG_MAX_USER_NAME 19
#define REG_MAX_REAL_USER_NAME 51
#define REG_MAX_USER_PWD 16
#define REG_MAX_USER_BANK_ID 19//十八位身份证号,加'\0'19
#define REG_MAX_ADDR 64//联系地址
#define REG_MAX_OTHER_STR_LEN 256
#define REG_MAX_PHONE_NUM_LEN 12

typedef char REG_USER_NAME;
typedef char REG_USER_PWD;
typedef char REG_USER_ID;
enum REG_GENDER_TYPE{reg_info_male , reg_info_female};


struct reg_basic_info{
	//性别
	REG_GENDER_TYPE reg_gender;
	//年龄
	int reg_age;
	//家庭住址
	//身份证号,18位
	REG_USER_ID reg_id[REG_MAX_USER_BANK_ID];
	//REG_USER_ID reg_name[REG_MAX_USER_NAME];
	//用户密码
	REG_USER_PWD reg_pwd[REG_MAX_USER_PWD];
	//用户真实姓名
	char reg_basic_user_name[REG_MAX_REAL_USER_NAME];
	char reg_phone_num[REG_MAX_PHONE_NUM_LEN] ;
	char reg_home_addr[REG_MAX_ADDR];
};

struct reg_input_info{
	//用户注册所输入的相关信息
    //其它的附加信息
	char email_addr[REG_MAX_ADDR];
	//输入基本信息
	reg_basic_info basic_info;
	//密码两次验证是否正确
	bool is_pwd_vry_crr;
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
	/*下面是数据*/
	reg_input_info input_info;//用户输入的信息
	reg_basic_info db_query_from_bank;//从银行系统调出的基础信息
	reg_info info;//注册过程中的数据,也是结果数据
};

const char CSFileName[] = "ConnStrs.txt" ;
const size_t connStrLen = 241  ; // max 3 lines
char *	GetIP() ;
bool GetConnStr(int index,char *outcome) ;
//index means in which line of the connStr.txt.
bool ConnectDB(_ConnectionPtr *pConn) ;

void DisconnectDB(_ConnectionPtr *pConn) ;

bool	Password_inquiry(_ConnectionPtr *_pConn,char *user_name , char *pwd_rlt) ;

void	Summery_inquiry(_ConnectionPtr *_pConn,char *user_name,sys_db_login *user_info) ;

bool	add_new_to_Tab_Login(_ConnectionPtr *_pConn,reg_input_info *_reg_info) ;

bool	add_new_to_Tab_Cust(_ConnectionPtr *_pConn,reg_input_info *_reg_info) ;

bool	add_new_employee(_ConnectionPtr *_pConn,admin_employee_info *emp_info,char *_comment) ;

bool delete_employee(_ConnectionPtr *_pConn,const char *employee_id) ;

bool	Apply_cust_info_query(_ConnectionPtr *_pConn,apply_custmor_info* _rlt) ;
	//for 7.3