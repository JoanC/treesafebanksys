#pragma once
//��������
//���������Գ�������ʽ��¼

enum err_type{
	//��½ģ��Ĵ���
 ERR_LOGIN_USER_UNEXIST,//�û�������ȷ
 ERR_LOGIN_PED_UNMATCHED,//�������
 ERR_LOGIN_VERIFY_WRONG//��֤�����
};


//�ڶ��ַ���,��error��Ϣ����db��ͳһ����
struct err_info{
	int err_id;
	char* err_tip;
};

//����id��ѯ������Ϣ
void err_search_info(err_type _err_id , err_info* _err_rlt);

/*
/////////////////////////////////////////////////////
//��½�������
enum err_info_login{
	login_success,
	login_username_err,
	login_pwd_err,
	login_verifycode_err
	//...��������
};

struct err_info{
	err_info_login errType;
	bool isSuccess;
	void* errInfo;//������Ϣ
};

/////////////////////////////////////////////////////
//���봦���еĴ������ͺ���Ϣ
enum err_info_apply{
	apply_success,
	apply_info_missing
	//...
};

struct err_type{
	bool isSuccess;
	void* errInfo;
	//...
};*/