#include "stdafx.h"
#include "sys_login.h"

char* login_ui_get_username(){
	//��ui�ϻ�ȡ�û���
	char* _user_name = "";
#ifdef DEBUG_INFO
	printf("get user name from login ui\n");
#endif
	return _user_name;
}
char* login_ui_get_pwd(){
	//��ȡ����
	char* _pwd = "";
#ifdef DEBUG_INFO
	printf("get user pwd from login ui\n");
#endif
	return _pwd;
}
char* login_ui_get_input_verify(){
	//��ȡ�������֤��
	char* _input_verify = "";
#ifdef DEBUG_INFO
	printf("get input verify from login ui\n");
#endif
	return _input_verify;
}
char* login_ui_get_verify(){
	//��ȡ��ȷ����֤��
	char* _verify_code = "";
#ifdef DEBUG_INFO
	printf("get verify code from login ui\n");
#endif
	return _verify_code;
}

void login_get_input_info(login_input_info* _input){
	//���������Ϣ
#ifdef DEBUG_INFO
	printf("get info from the login UI\n");
#endif
	//������û���
	_input->input_user_name 
		= login_ui_get_username();
	//���������
	_input->input_user_pwd
		= login_ui_get_pwd();
	//�������֤��
	_input->input_verify_code
		= login_ui_get_input_verify();
	//��ȷ��(UI�Զ����ɵ�)��֤��
	_input->verify_code
		= login_ui_get_verify();
	//����������Ϣ...
	//add
	//...
}

void login_check_username(char* _name , err_login* _err){
	//����û���
    //�������洢��err��
	bool isExsit;
#ifdef DEBUG_INFO
	printf("connect to database\n");
	printf("check if this user exist\n");
#endif
	// DB��ѯ
	if(!isExsit){
		//����û�������
		_err->isSuccess = false;
		_err->errType = login_username_err;
	}
}

//������
void login_err_occour(login_info* _info){

}