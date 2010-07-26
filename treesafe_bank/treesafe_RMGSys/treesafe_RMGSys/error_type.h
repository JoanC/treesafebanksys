#pragma once
//错误类型

/////////////////////////////////////////////////////
//登陆错误代码
enum err_type_login{
	none,
	username_err,
	pwd_err,
	verifycode_err
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
	none
	//...
};

struct err_apply{
	bool isSuccess;
	void* errInfo;
	//...
};

