#include "error_type.h"

//登陆系统

//登陆权限
//管理员,一般用户...
enum login_competence{
	admin,
	user
	//...other competence
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

//检查用户名
//错误结果存储在err中
void login_check_username(login_info* _login , char* _name , err_login* _err);

//检查用户密码
//错误结果存储在err中
void login_check_pwd(login_info* login , char* _name , char* _pwd , err_login* _err);

//检查验证码
//错误结果存储在err中
void login_check_verify(login_info* _login ,char* _input , char* _vertfy , err_login* _err);

//出错处理
void login_err_occour(login_info* _info);

//登陆成功后,跳转UI
void login_jump(login_info* _info,void* _new_ui);

//主登陆流程
void login_frame(login_info* _info);


