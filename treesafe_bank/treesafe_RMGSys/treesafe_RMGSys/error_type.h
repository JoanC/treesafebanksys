#pragma once
//错误类型
//错误类型以常数的形式记录
#define ERR_LOGIN_USER_UNEXIST 0

//第二种方法,把error信息放入db中统一管理
struct err_info{
	int err_id;
	char* err_tip;
};

//根据id查询错误信息
void err_search_info(int _err_id , err_info* _err_rlt);

/*
/////////////////////////////////////////////////////
//登陆错误代码
enum err_info_login{
	login_success,
	login_username_err,
	login_pwd_err,
	login_verifycode_err
	//...其它错误
};

struct err_info{
	err_info_login errType;
	bool isSuccess;
	void* errInfo;//错误信息
};

/////////////////////////////////////////////////////
//申请处理中的错误类型和信息
enum err_info_apply{
	apply_success,
	apply_info_missing
	//...
};

struct err_apply{
	bool isSuccess;
	void* errInfo;
	//...
};*/