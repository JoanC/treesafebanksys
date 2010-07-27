#include "stdafx.h"
#include "sys_login.h"

char* login_ui_get_username(){
	//��ui�ϻ�ȡ�û���
	char* _user_name = "";
#ifdef DEBUG_LOGIN_INFO
	printf("get user name from login ui\n");
#endif
	return _user_name;
}
char* login_ui_get_pwd(){
	//��ȡ����
	char* _pwd = "";
#ifdef DEBUG_LOGIN_INFO
	printf("get user pwd from login ui\n");
#endif
	return _pwd;
}
char* login_ui_get_input_verify(){
	//��ȡ�������֤��
	char* _input_verify = "";
#ifdef DEBUG_LOGIN_INFO
	printf("get input verify from login ui\n");
#endif
	return _input_verify;
}
char* login_ui_get_verify(){
	//��ȡ��ȷ����֤��
	char* _verify_code = "";
#ifdef DEBUG_LOGIN_INFO
	printf("get verify code from login ui\n");
#endif
	return _verify_code;
}

void login_get_input_info(login_input_info* _input){
	//���������Ϣ
#ifdef DEBUG_LOGIN_INFO
	printf("get info from the login UI\n");
#endif

#ifdef DEBUG_LOGIN_INFO
	printf("get user_name\n");
#endif
	//������û���
	_input->input_user_name 
		= login_ui_get_username();
#ifdef DEBUG_LOGIN_INFO
	printf("get password...\n");
#endif
	//���������
	_input->input_user_pwd
		= login_ui_get_pwd();
#ifdef DEBUG_LOGIN_INFO
	printf("get input-verify code...\n");
#endif
	//�������֤��
	_input->input_verify_code
		= login_ui_get_input_verify();
#ifdef DEBUG_LOGIN_INFO
	printf("get true verify code...\n");
#endif
	//��ȷ��(UI�Զ����ɵ�)��֤��
	_input->verify_code
		= login_ui_get_verify();
	//����������Ϣ...
	//add
	//...
}

void login_check_username(char* _name , err_info* _err , bool* _rlt){
	//����û���
    //�������洢��err��
	bool isExsit = false;
#ifdef DEBUG_LOGIN_INFO
	printf("connect to database\n");
	printf("check if this user exist\n");
#endif
	// DB��ѯ
	//����isExist
#ifdef DEBUG_LOGIN_INFO
	printf("connect to database\n");
	printf("check if this user exist\n");
#endif
	if(!isExsit){
		//����û�������
#ifdef DEBUG_LOGIN_INFO
	printf("the user is not exist!\n");
	printf("user not exist error!\n");
#endif
	   err_search_info(ERR_LOGIN_USER_UNEXIST,_err);//��ѯ������Ϣ
	   login_err_occour(_err);//��������
#ifdef DEBUG_LOGIN_INFO
	printf("login fail !\n");
	printf("return the false result\n");
#endif
		*_rlt = false;//���ش���Ľ��
		return;
	}
	else{
		//�û�����,�û������֤ͨ��
#ifdef DEBUG_LOGIN_INFO
	printf("user exsit!\n");
	printf("user check access !\n");
	printf("return the true result!\n");
#endif
	   *_rlt = true;//������ȷ���
	   return;
	}
}

void login_check_pwd(char* _name , char* _pwd , err_info* _err , bool* _rlt){
	//����û�����
   //�������洢��err��
	bool isTrue = false;//�����Ƿ���ȷ
#ifdef DEBUG_LOGIN_INFO
	printf("connect to database\n");
	printf("check if this the password of the user is true\n");
#endif
	//db������
	if(!isTrue){
		//���벻��ȷ
#ifdef DEBUG_LOGIN_INFO
	printf("password can't match!\n");
	printf("login fail!\n");
#endif
#ifdef DEBUG_LOGIN_INFO
	printf("error occour! manage error...\n");
#endif
	    err_search_info(ERR_LOGIN_PED_UNMATCHED,_err);//��Ѱ������Ϣ
		login_err_occour(_err);//������
	    *_rlt = false;//������
		return;
	}
	else{
		//������ȷ
#ifdef DEBUG_LOGIN_INFO
	printf("password match access!\n");
#endif
	    *_rlt = true;
		return;
	}
}


void login_check_verify(char* _input , char* _verify , err_info* _err , bool* _rlt){
	//�����֤��
    //�������洢��err��
#ifdef DEBUG_LOGIN_INFO
	printf("check verify code...\n");
#endif
	if(!strcmp(_input,_verify)){
		//��֤�����
#ifdef DEBUG_LOGIN_INFO
		printf("verify code check access...\n");
#endif
		*_rlt = true;
		return;
	}
	else{
		//��֤��ʧ��
#ifdef DEBUG_LOGIN_INFO
		printf("verify code check error!...\n");
#endif
		//���Ҵ�����Ϣ
		err_search_info(ERR_LOGIN_VERIFY_WRONG,_err);
		login_err_occour(_err);//��������
		*_rlt = false;
		return;
	}
}

void login_check_info(login_info* _info , login_input_info* _input){
	//���������Ϣ
	login_check_username(_input->input_user_name
		,&_info->err,&_info->isSuccess);//��֤�û���
	if(!_info->isSuccess) return;
	//��֤����
	login_check_pwd(_input->input_user_name,
		_input->input_user_pwd,&_info->err,&_info->isSuccess);
	if(!_info->isSuccess) return;
	//��֤��Ƚ�
	login_check_verify(_input->input_verify_code,
		_input->verify_code,&_info->err,&_info->isSuccess);
}

void login_auto_add(login_info* _info,login_input_info* _input){
	//�����Ϣ
    //ǰ������û�����,������ȷ,����֤��ͨ��
	if(!_info->isSuccess) return;//��½���ɹ��򷵻�
#ifdef DEBUG_LOGIN_INFO
	printf("save the user information...\n");
#endif
	//�����û�����
	_info->user_name = _input->input_user_name;
	_info->user_pwd = _input->input_user_pwd;
	_info->verify_code = _input->input_verify_code;
	//�������ݿ⣬���Ҷ�Ӧ��Ȩ�޼�����
#ifdef DEBUG_LOGIN_INFO
	printf("connect to the database...\n");
	printf("search the comperence of the user...\n");
	//...
#endif
	//compe...
	//Add code here...
}

void login_err_occour(err_info* _err){
	//��½ģ�������
	//...
}