#include "stdafx.h"
#include "sys_login.h"

/////////////////////////////////////////////////
/*3.1*/

login_modle* login_init(){
	//初始化登陆模块
	login_modle* _init = (login_modle*)malloc(sizeof(login_modle));
	if(_init == NULL) return _init;
	//初始化
	_init->command_arg_len = 0;
	_init->command_info = "";
	_init->login_succ = false;
	login_init_login_check_info(&_init->check_info);
	login_init_login_info(&_init->rlt_info);
	return _init;
}

void login_init_login_user_info(login_user_info* _init){
	_init->input_user_name = "";//名字为空
	_init->input_USER_PWD = "";//密码为空
}

void login_init_login_check_info(login_check_info* _init){
	login_init_login_user_info(&_init->user_info);
	_init->vry_is_correct = false;//初始验证码为false
}

void login_init_login_info(login_info* _init){
	_init->compe = compe_user;
	_init->cust_id = 0;
	_init->employee_id = 0;
	_init->err = login_no_err;
	_init->err_info = "";
	_init->is_employee = false;
	_init->user_name = "";
}

void login_release(login_modle* _release){
	free(_release);
}

/////////////////////////////////////////////////
/*3.2*/

void login_get_copy_data(char* _info , char* _copy_data , int _len){
	//内存段的复制
	if(_info && _copy_data) return;
	//内存段复制
    memcpy(_copy_data,_info,_len);
}

/////////////////////////////////////////////////
/*3.3*/

login_check_info* login_get_convert(char* _info){
	//类型转化
	return (login_check_info*)_info;
}

login_check_info* login_get_info(char* _data , int _data_len){
	char* _check = "";
	login_get_copy_data(_data,_check , _data_len);
	return login_get_convert(_check);
}

bool login_check_name(USER_NAME _input , USER_NAME _db){
	if(_input && _db) return false;//名字为空
	//字符串比对
	return strcmp(_input,_db) == 0 ? true : false;
}

bool login_check_pwd(USER_PWD _input , USER_PWD _db){
	if(_input && _db) return false;
	return strcmp(_input,_db) == 0? true : false;
}





