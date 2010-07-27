#include "stdafx.h"
#include "sys_login.h"

char* login_ui_get_username(){
	//从ui上获取用户名
	char* _user_name = "";
#ifdef DEBUG_INFO
	printf("get user name from login ui\n");
#endif
	return _user_name;
}
char* login_ui_get_pwd(){
	//获取密码
	char* _pwd = "";
#ifdef DEBUG_INFO
	printf("get user pwd from login ui\n");
#endif
	return _pwd;
}
char* login_ui_get_input_verify(){
	//获取输入的验证码
	char* _input_verify = "";
#ifdef DEBUG_INFO
	printf("get input verify from login ui\n");
#endif
	return _input_verify;
}
char* login_ui_get_verify(){
	//获取正确的验证码
	char* _verify_code = "";
#ifdef DEBUG_INFO
	printf("get verify code from login ui\n");
#endif
	return _verify_code;
}

void login_get_input_info(login_input_info* _input){
	//填充输入信息
#ifdef DEBUG_INFO
	printf("get info from the login UI\n");
#endif
	//输入的用户名
	_input->input_user_name 
		= login_ui_get_username();
	//输入的密码
	_input->input_user_pwd
		= login_ui_get_pwd();
	//输入的验证码
	_input->input_verify_code
		= login_ui_get_input_verify();
	//正确的(UI自动生成的)验证码
	_input->verify_code
		= login_ui_get_verify();
	//其它输入信息...
	//add
	//...
}

void login_check_username(char* _name , err_login* _err){
	//检查用户名
    //错误结果存储在err中
	bool isExsit;
#ifdef DEBUG_INFO
	printf("connect to database\n");
	printf("check if this user exist\n");
#endif
	// DB查询
	if(!isExsit){
		//如果用户不存在
		_err->isSuccess = false;
		_err->errType = login_username_err;
	}
}

//出错处理
void login_err_occour(login_info* _info){

}