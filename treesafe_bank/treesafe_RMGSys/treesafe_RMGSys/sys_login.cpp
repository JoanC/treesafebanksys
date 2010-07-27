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
#ifdef DEBUG_LOGIN_INFO
	printf("connect to database\n");
	printf("check if this the password of the user is true\n");
#endif
	//db处理函数
	if(!isTrue){
		//密码不正确
#ifdef DEBUG_LOGIN_INFO
	printf("password can't match!\n");
	printf("login fail!\n");
#endif
#ifdef DEBUG_LOGIN_INFO
	printf("error occour! manage error...\n");
#endif
	    err_search_info(ERR_LOGIN_PED_UNMATCHED,_err);//搜寻错误信息
		login_err_occour(_err);//错误处理
	    *_rlt = false;//错误结果
		return;
	}
	else{
		//密码正确
#ifdef DEBUG_LOGIN_INFO
	printf("password match access!\n");
#endif
	    *_rlt = true;
		return;
	}
}


void login_check_verify(char* _input , char* _verify , err_info* _err , bool* _rlt){
	//检查验证码
    //错误结果存储在err中
#ifdef DEBUG_LOGIN_INFO
	printf("check verify code...\n");
#endif
	if(!strcmp(_input,_verify)){
		//验证码相等
#ifdef DEBUG_LOGIN_INFO
		printf("verify code check access...\n");
#endif
		*_rlt = true;
		return;
	}
	else{
		//验证码失败
#ifdef DEBUG_LOGIN_INFO
		printf("verify code check error!...\n");
#endif
		//查找错误信息
		err_search_info(ERR_LOGIN_VERIFY_WRONG,_err);
		login_err_occour(_err);//错误处理函数
		*_rlt = false;
		return;
	}
}

void login_check_info(login_info* _info , login_input_info* _input){
	//检查输入信息
	login_check_username(_input->input_user_name
		,&_info->err,&_info->isSuccess);//验证用户名
	if(!_info->isSuccess) return;
	//验证密码
	login_check_pwd(_input->input_user_name,
		_input->input_user_pwd,&_info->err,&_info->isSuccess);
	if(!_info->isSuccess) return;
	//验证码比较
	login_check_verify(_input->input_verify_code,
		_input->verify_code,&_info->err,&_info->isSuccess);
}

void login_auto_add(login_info* _info,login_input_info* _input){
	//填充信息
    //前提如果用户存在,密码正确,且验证码通过
	if(!_info->isSuccess) return;//登陆不成功则返回
#ifdef DEBUG_LOGIN_INFO
	printf("save the user information...\n");
#endif
	//记载用户数据
	_info->user_name = _input->input_user_name;
	_info->user_pwd = _input->input_user_pwd;
	_info->verify_code = _input->input_verify_code;
	//连接数据库，查找对应的权限及其它
#ifdef DEBUG_LOGIN_INFO
	printf("connect to the database...\n");
	printf("search the comperence of the user...\n");
	//...
#endif
	//compe...
	//Add code here...
}

void login_err_occour(err_info* _err){
	//登陆模块错误处理
	//...
}