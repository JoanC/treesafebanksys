#include "stdafx.h"
#include "sys_login.h"

char* login_ui_get_username(){
	//从ui上获取用户名
	char* _user_name = "";
#ifdef DEBUG_LOGIN_INFO
	printf("get user name from login ui\n");
#endif
	return _user_name;
}
char* login_ui_get_pwd(){
	//获取密码
	char* _pwd = "";
#ifdef DEBUG_LOGIN_INFO
	printf("get user pwd from login ui\n");
#endif
	return _pwd;
}
char* login_ui_get_input_verify(){
	//获取输入的验证码
	char* _input_verify = "";
#ifdef DEBUG_LOGIN_INFO
	printf("get input verify from login ui\n");
#endif
	return _input_verify;
}
char* login_ui_get_verify(){
	//获取正确的验证码
	char* _verify_code = "";
#ifdef DEBUG_LOGIN_INFO
	printf("get verify code from login ui\n");
#endif
	return _verify_code;
}

void login_get_input_info(login_input_info* _input){
	//填充输入信息
#ifdef DEBUG_LOGIN_INFO
	printf("get info from the login UI\n");
#endif

#ifdef DEBUG_LOGIN_INFO
	printf("get user_name\n");
#endif
	//输入的用户名
	_input->input_user_name 
		= login_ui_get_username();
#ifdef DEBUG_LOGIN_INFO
	printf("get password...\n");
#endif
	//输入的密码
	_input->input_user_pwd
		= login_ui_get_pwd();
#ifdef DEBUG_LOGIN_INFO
	printf("get input-verify code...\n");
#endif
	//输入的验证码
	_input->input_verify_code
		= login_ui_get_input_verify();
#ifdef DEBUG_LOGIN_INFO
	printf("get true verify code...\n");
#endif
	//正确的(UI自动生成的)验证码
	_input->verify_code
		= login_ui_get_verify();
	//其它输入信息...
	//add
	//...
}

void login_check_username(char* _name , err_info* _err , bool* _rlt){
	//检查用户名
    //错误结果存储在err中
	bool isExsit = false;
#ifdef DEBUG_LOGIN_INFO
	printf("connect to database\n");
	printf("check if this user exist\n");
#endif
	// DB查询
	//更改isExist
#ifdef DEBUG_LOGIN_INFO
	printf("connect to database\n");
	printf("check if this user exist\n");
#endif
	if(!isExsit){
		//如果用户不存在
#ifdef DEBUG_LOGIN_INFO
	printf("the user is not exist!\n");
	printf("user not exist error!\n");
#endif
	   err_search_info(ERR_LOGIN_USER_UNEXIST,_err);//查询错误信息
	   login_err_occour(_err);//错误处理函数
#ifdef DEBUG_LOGIN_INFO
	printf("login fail !\n");
	printf("return the false result\n");
#endif
		*_rlt = false;//返回错误的结果
		return;
	}
	else{
		//用户存在,用户身份认证通过
#ifdef DEBUG_LOGIN_INFO
	printf("user exsit!\n");
	printf("user check access !\n");
	printf("return the true result!\n");
#endif
	   *_rlt = true;//返回正确结果
	   return;
	}
}

void login_check_pwd(char* _name , char* _pwd , err_info* _err , bool* _rlt){
	//检查用户密码
   //错误结果存储在err中
	bool isTrue = false;//密码是否正确

}