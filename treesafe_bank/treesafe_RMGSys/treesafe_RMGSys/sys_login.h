#include "error_type.h"

//登陆系统

//登陆权限
//管理员,一般用户...
enum login_competence{
	admin,
	user
	//...other competence
};

struct login_input_info{
	//用户从UI输入的信息
	char* input_user_name;//用户名
	char* input_user_pwd;//用户密码
	char* input_verify_code;//验证码
	char* verify_code;//正确的(UI)生成的验证码
};

struct login_info{
	//登陆信息存储
	bool isSuccess;//是否成功
	//用户权限
	login_competence compe;
	//用户名
	char* user_name;//用户名
	char* user_pwd;//用户密码
	char* verify_code;//验证码

	//登陆信息
	err_info err;//错误信息
	void* log_login;//日志信息
	void* report_login;//报表信息
	//...其他
	bool is_employee;//登陆的用户是否是雇员
	int cust_id;//如果是用户,那么用户id
	int employee_id;//如果是雇员,那么雇员的id
};

//从UI中取得输入信息
//与UI的交互层
char* login_ui_get_username();//从ui上获取用户名
char* login_ui_get_pwd();//获取密码
char* login_ui_get_input_verify();//获取输入的验证码
char* login_ui_get_verify();//获取正确的验证码
//整合输入信息
//填入_input结构体中
void login_get_input_info(login_input_info* _input);

//检查用户名
//错误结果存储在err中
void login_check_username(char* _name , err_info* _err , bool* _rlt);

//检查用户密码
//错误结果存储在err中
void login_check_pwd(char* _name , char* _pwd , err_info* _err , bool* _rlt);

//检查验证码
//错误结果存储在err中
void login_check_verify(char* _input , char* _verify , err_info* _err , bool* _rlt);

//检测函数
//把三个检测过程合起
//login_info 和 input_info结合在一起
void login_check_info(login_info* _info , login_input_info* _input);

//填充信息
//前提如果用户存在,密码正确,且验证码通过
void login_auto_add(login_info* _info,login_input_info* _input);

//登陆成功后,跳转UI
//根据用户权限的不同,会有不同的界面跳出
void login_jump(login_info* _info,void* _new_ui = 0);

//主登陆流程
void login_frame(login_info* _info,login_input_info* _input);

//登陆中的错误处理函数
//错误处理一定要仔细
void login_err_occour(err_info* _err);

//错误处理子函数
//在_err_occour函数中的分支小函数
void login_err_user_unexsit();//用户不存在

void login_err_pwd_unmatch();//用户密码错误

void login_err_verify_wrong();//验证码输入错误

