#pragma once
//��������

/////////////////////////////////////////////////////
//��½�������
enum err_type_login{
	login_success,
	login_username_err,
	login_pwd_err,
	login_verifycode_err
	//...��������
};

struct err_login{
	err_type_login errType;
	bool isSuccess;
	void* errInfo;//������Ϣ
};

/////////////////////////////////////////////////////
//���봦���еĴ������ͺ���Ϣ
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

