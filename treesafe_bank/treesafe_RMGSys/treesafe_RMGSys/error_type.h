#pragma once
//��������

/////////////////////////////////////////////////////
//��½�������
enum err_type_login{
	none,
	username_err,
	pwd_err,
	verifycode_err
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
	none
	//...
};

struct err_apply{
	bool isSuccess;
	void* errInfo;
	//...
};

