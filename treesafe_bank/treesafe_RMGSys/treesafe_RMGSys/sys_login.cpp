#include "stdafx.h"
#include "sys_login.h"

extern _ConnectionPtr* database_connection;

/////////////////////////////////////////////////
/*3.1*/

login_modle* login_init(){
	//��ʼ����½ģ��
	login_modle* _init = (login_modle*)malloc(sizeof(login_modle));
	DEBUG_LOGIN_PRINT("init the login modle");
	if(_init == NULL) return _init;
	//��ʼ������Ա����
	//_init->command_arg_len = 0;
	//memset(_init->command_info,'\0',MAX_OTHER_STR_LEN);
	_init->login_succ = false;
	login_init_login_check_info(&_init->check_info);
	login_init_login_info(&_init->rlt_info);
	login_init_login_user_info(&_init->db_query);
	DEBUG_LOGIN_PRINT("init done...");
	return _init;
}

void login_init_login_user_info(login_user_info* _init){
	DEBUG_LOGIN_PRINT("init the login_user_info...");
	memset(_init->input_user_name,'\0',MAX_USER_NAME_LEN);
	memset(_init->input_user_pwd,'\0',MAX_USER_PWD_LEN);
}

void login_init_login_check_info(login_check_info* _init){
	DEBUG_LOGIN_PRINT("init the login_check_info...");
	login_init_login_user_info(&_init->user_info);
	_init->vry_is_correct = false;//��ʼ��֤��Ϊfalse
}

void login_init_login_info(login_info* _init){
	DEBUG_LOGIN_PRINT("init the login_info...");
	_init->compe = compe_cust;
//	_init->cust_id = 0;
//	_init->employee_id = 0;
//	_init->login_err.type = login_no_err;
//	memset(_init->err_info,'\0',MAX_OTHER_STR_LEN);
	//��ʼ��������Ϣ�ṹ��
	init_sys_err(&_init->login_err);
//	_init->is_employee = false;
	memset(_init->user_id,'\0',MAX_USER_NAME_LEN);
}

void login_release(login_modle* _release){
	DEBUG_LOGIN_PRINT("release the login_modle...");
	free(_release);
}

/////////////////////////////////////////////////
/*3.2*/

void login_get_copy_data(char* _info , char* _copy_data , int _len){
	//�ڴ�θ���
	DEBUG_LOGIN_PRINT("copy command data ...");
    memcpy(_copy_data,_info,_len);
}

/////////////////////////////////////////////////
/*3.3*/
void login_db_query(_ConnectionPtr *_pConn,USER_NAME *_user , login_user_info* _info , bool* _rlt)
{
	DEBUG_LOGIN_PRINT("get login data from database ...");
	strcpy_s(_info->input_user_name, MAX_USER_NAME_LEN,_user) ;
	*_rlt = Password_inquiry(_pConn,_user,_info->input_user_pwd) ;
}
/////////////////////////////////////////////////

login_check_info* login_get_convert(char* _info){
	//����ת��
	DEBUG_LOGIN_PRINT("convert string to login_check_info ... ");
	return (login_check_info*)_info;
}

login_check_info* login_get_info(char* _data , int _data_len){
	DEBUG_LOGIN_PRINT("get the login_check_info ... ");
	char _check[MAX_OTHER_STR_LEN];
	memset(_check,'\0',MAX_OTHER_STR_LEN);
	login_get_copy_data(_data,_check , _data_len);
	return login_get_convert(_check);
}

bool login_check_name(USER_NAME* _db){
	DEBUG_LOGIN_PRINT("check user name ...");
	return _db == "" ? true : false;//�û����Ƿ����
}

bool login_check_pwd(USER_PWD* _input , USER_PWD* _db){
	//if(_input && _db) return false;
	DEBUG_LOGIN_PRINT("check user password ...");
	return strcmp(_input,_db) == 0? true : false;
}

bool login_check(login_check_info* _input , login_user_info* _db){
	DEBUG_LOGIN_PRINT("check user's name and password ...");
	return !(login_check_name(_db->input_user_name)||
		login_check_pwd(_input->user_info.input_user_pwd,_db->input_user_pwd));
}
/////////////////////////////////////////////////
/*3.5*/
void login_db_summery(_ConnectionPtr *_pConn,login_user_info* _user_info , login_info* _info)
{
	DEBUG_LOGIN_PRINT("query more data from database ...");
	sys_db_login temp ;
	Summery_inquiry(_pConn, _user_info->input_user_name,&temp) ;

	_info->compe = temp.cmpt ;
	strcpy_s(_info->user_id ,MAX_USER_NAME_LEN ,temp.user_id ) ;
}

/////////////////////////////////////////////////
/*3.8*/
void login_err_mgr(sys_err_type _err_type,login_modle* _mld){
	DEBUG_LOGIN_PRINT("error occured");
	_mld->login_succ = false;
	//db...���Ҵ�����Ϣ,���ṹ��
	sys_err_search(&_mld->rlt_info.login_err);
}

/////////////////////////////////////////////////
/*3.9*/
void login_convert_rlt(login_info* _info , char* _rlt , int* _rlt_len){
	//�����������rlt�д���
	DEBUG_LOGIN_PRINT("convert the result (login_info) to the string");
	memcpy(_rlt,_info,sizeof(login_info));
	//���Ⱦ���login_info�ĳ���
	*_rlt_len = sizeof(login_info);
}

/******************************************************/
//��½ģ���������
//Jiraiya����
void login_frame(char* _command , int _arg_len , char* _rlt , int* _rlt_len){
	DEBUG_LOGIN_PRINT("login start ... ");
	//������½ģ��
	login_modle* _login_frame = login_init();//��ʼ����½ģ��
	_login_frame->check_info = *login_get_info(_command,_arg_len);
	if(!_login_frame->check_info.vry_is_correct){
		//��½��֤�����
		//������
		login_err_mgr(err_login_vry_uncmp,_login_frame);
		return;
	}
	//db...
	//���������,����_db_query�ĸĶ�����
	//����ģ��3.3
	//��ģ����Ҫ�޸�,����������,��ò�Ҫ����_ConnectionPtr,����г
    

	//������Ϊ�˲���
	strcpy(_login_frame->db_query.input_user_name,"haha");
	strcpy(_login_frame->db_query.input_user_pwd,"123");


	//
	if(!login_check(&_login_frame->check_info,&_login_frame->db_query)){
		//�û��������벻��ȷ
		//������...
		login_err_mgr(err_login_user_or_pwd_err,_login_frame);
		return;
	}

	//���и߼����ݲ�ѯ
	//����ģ��3.5
	//�õ�login_info,��rlt_info
	//...


	//���ת��
	login_convert_rlt(&_login_frame->rlt_info,_rlt,_rlt_len);

	//�ͷ�ģ��
	login_release(_login_frame);

	DEBUG_LOGIN_PRINT("login end ...");
}


