#pragma once
//错误类型

/////////////////////////////////////////////////////
//登陆错误代码
enum err_type_login{
	login_success,
	login_username_err,
	login_pwd_err,
	login_verifycode_err
	//...其它错误
};

struct err_login{
	err_type_login errType;
	bool isSuccess;
	void* errInfo;//错误信息
};

/////////////////////////////////////////////////////
//申请处理中的错误类型和信息
enum err_type_apply{
	apply_success,
	apply_info_missing
	//...
};

struct err_apply{
	bool isSuccess;
	void* errInfo;
	//...
};

