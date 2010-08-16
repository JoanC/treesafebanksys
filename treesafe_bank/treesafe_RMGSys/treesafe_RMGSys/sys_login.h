#pragma once

#include "error_type.h"

#define DEFAULT_INFO_LEN 64

typedef char* USER_NAME ;//用户名
typedef char*  USER_PWD;//密码
//typedef  char* VRY_CODE;//验证码
typedef bool* VRY_RESULT;//验证码的检测结果


//登陆系统

//登陆权限
//管理员,一般用户...
enum login_competence{
	compe_admin,
	compe_user
	//...other competence
};

enum login_err_type{
	login_no_err,
	login_user_not_eixt,
	login_pwd_not_correct,
	login_vry_not_correct,
	login_server_err
};

struct login_user_info{
	USER_NAME input_user_name;//用户名
	USER_PWD input_user_pwd;//用户密码
};


struct login_check_info{
	//用户从UI输入的信息
	login_user_info user_info;//用户名和密码

	//???是否要在服务器中检查验证码???////
	//VRY_CODE input_verify_code;//验证码
	//VRY_CODE verify_code;//正确的(UI)生成的验证码
	//如果不用的话，则至少要有一个检查结果
	bool vry_is_correct;//验证码的检测情况
};

//一次登陆过程的信息记载
struct login_info{
	//用户权限
	login_competence compe;
	//用户名
	char* user_name;//用户名
	//...其他
	bool is_employee;//登陆的用户是否是雇员
	int cust_id;//如果是用户,那么用户id
	int employee_id;//如果是雇员,那么雇员的id

	//错误信息
	//????这里是否合并成一个结构体??//
	login_err_type err;
	char* err_info;//错误信息
};

//整体模块
struct login_modle{
	bool login_succ;
	int command_arg_len;//网络数据的长度
	char* command_info;//指令的信息
	login_check_info check_info;
	login_info rlt_info;
};


//模块3--登陆
/*********************************************************/
//模块 3.1 
//0.1 -- 模块初始化与释放
//以下部分由Jiraiya完成
login_modle* login_init();
void login_release(login_modle* _release);

//各个结构体的初始化函数
void login_init_login_user_info(login_user_info* _init);
void login_init_login_check_info(login_check_info* _init);
void login_init_login_info(login_info* _init);

/********************************************************/
//以下由Jiraiya完成
//模块3.2
//0.2 -- 输入信息整合,将模块1的信息整理成sunni可见的信息
//与UI的交互层
//整合输入信息
//从网络上接受信息
/*

void login_get_username(USER_NAME _name , char* _info);//从ui上获取用户名
void login_get_pwd(USER_PWD _pwd , char* _info);//获取密码
//void login_get_input_verify(VRY_CODE _vry , char* _info);//获取输入的验证码
//void login_get_verify(VRY_CODE _vry , char* _info);//获取正确的验证码
void login_get_vry_result(VRY_RESULT _vry_rlt);//得到验证码的结果
*/

//整合总流程,其实就是一个copy,即一个复制和类型转换的过程
void login_get_copy_data(char* _info , char* _copy_data , int _len);
login_check_info* login_get_convert(char* _info);
login_check_info* login_get_info(char* _data , int _data_len);//获取待验证的信息
/*******************************************************/
//以下由sunni完成
//模块3.3
//0.3 -- 查询
//////////////////////////////
//根据0.2的username,进行查询(不要去比较值),并将查询结果存储在一个结构体login_user_info中
//如果没有查询到该用户,结果_rlt返回false

//这个查询可能有子过程,由sunni自行设计

void login_db_query(USER_NAME _user , login_user_info* _info , bool* _rlt);

/******************************************************/
//以下由Jiraiya完成
//模块3.4
//0.4 -- 验证
//根据0.2的整合信息和0.3的查询信息,进行验证
//成功说明登陆成功,否则失败,如果失败
bool login_check_name(USER_NAME _db);
bool login_check_pwd(USER_PWD _input , USER_PWD _db);
//void login_check_vry(VRY_CODE _input , VRY_CODE _ui , login_err_type _type);
bool login_check(login_check_info* _input , login_user_info* _db);
/******************************************************/
//以下由sunni完成
//模块3.5
//0.5 -- 如果登陆成功,根据正确的用户名密码,进行高级信息查询处理,
//并将登陆信息存入login_info
//如果成功,则进行该模块的处理

//具体的login_info就要看sunni怎么定了
void login_db_summery(login_user_info* _user_info , login_info* _info);

/******************************************************/
//以下有sunni完成
//模块3.6
//0.6 -- 如果登陆失败
//根据错误编码进行错误信息的查询
void login_db_err_query(login_err_type _err , char* _err_info);

/******************************************************/
//以下是Jiraiya完成
//模块3.7
//0.8将结果信息发送给发送过渡层
void login_summer_send_info(login_info* _info);

/******************************************************/
//登陆模块的总流程
//Jiraiya整合
void login_frame(char* _command , int _arg_len);