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
	login_competence compe;
	//用户名
	char* user_name;//用户名
	char* user_pwd;//用户密码
	char* verify_code;//验证码

	//登陆信息
	err_login err;//错误信息
	void* log_login;//日志信息
	void* report_login;//报表信息
	//...其他
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
void login_check_username(char* _name , err_login* _err);

//检查用户密码
//错误结果存储在err中
void login_check_pwd(char* _name , char* _pwd , err_login* _err);

//检查验证码
//错误结果存储在err中
void login_check_verify(char* _input , char* _vertfy , err_login* _err);

//检测函数
//把三个检测过程合起
//login_info 和 input_info结合在一起
void login_check_info(login_info* _info , login_input_info* _input);

//填充其它信息
//如果用户存在,密码正确,且验证码通过
//则把其它跟这个用户有关的信息
void login_auto_add(login_info* _info);

//出错处理
void login_err_occour(login_info* _info);

//登陆成功后,跳转UI
//根据用户权限的不同,会有不同的界面跳出
void login_jump(login_info* _info,void* _new_ui);

//主登陆流程
void login_frame(login_info* _info);


