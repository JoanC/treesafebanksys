#include "stdafx.h"
#include "sys_login.h"
/////////////////////////////////////////////////
/*3.1*/

login_modle* login_init(){
	//初始化登陆模块
	login_modle* _init = (login_modle*)malloc(sizeof(login_modle));
	if(_init == NULL) return _init;
	//初始化个成员变量
	_init->command_arg_len = 0;
	memset(_init->command_info,'\0',MAX_OTHER_STR_LEN);
	_init->login_succ = false;
	login_init_login_check_info(&_init->check_info);
	login_init_login_info(&_init->rlt_info);
	login_init_login_user_info(&_init->db_query);
	return _init;
}

void login_init_login_user_info(login_user_info* _init){
	memset(_init->input_user_name,'\0',MAX_USER_NAME_LEN);
	memset(_init->input_user_pwd,'\0',MAX_USER_PWD_LEN);
}

void login_init_login_check_info(login_check_info* _init){
	login_init_login_user_info(&_init->user_info);
	_init->vry_is_correct = false;//初始验证码为false
}

void login_init_login_info(login_info* _init){
	_init->compe = compe_user;
	_init->cust_id = 0;
	_init->employee_id = 0;
//	_init->login_err.type = login_no_err;
//	memset(_init->err_info,'\0',MAX_OTHER_STR_LEN);
	//初始化错误信息结构体
	init_sys_err(&_init->login_err);
	_init->is_employee = false;
	memset(_init->user_name,'\0',MAX_USER_NAME_LEN);
}

void login_release(login_modle* _release){
	free(_release);
}

/////////////////////////////////////////////////
/*3.2*/

void login_get_copy_data(char* _info , char* _copy_data , int _len){
	//内存段复制
    memcpy(_copy_data,_info,_len);
}

/////////////////////////////////////////////////
/*3.3*/
void login_db_query(_ConnectionPtr *_pConn,USER_NAME *_user , login_user_info* _info , bool* _rlt)
{
	strcpy_s(_info->input_user_name, MAX_USER_NAME_LEN,_user) ;
	*_rlt = Password_inquiry(_pConn,_user,_info->input_user_pwd) ;
}
/////////////////////////////////////////////////

login_check_info* login_get_convert(char* _info){
	//类型转化
	return (login_check_info*)_info;
}

login_check_info* login_get_info(char* _data , int _data_len){
	char _check[MAX_OTHER_STR_LEN];
	memset(_check,'\0',MAX_OTHER_STR_LEN);
	login_get_copy_data(_data,_check , _data_len);
	return login_get_convert(_check);
}

bool login_check_name(USER_NAME* _db){
	return _db == "" ? true : false;//用户名是否存在
}

bool login_check_pwd(USER_PWD* _input , USER_PWD* _db){
	if(_input && _db) return false;
	return strcmp(_input,_db) == 0? true : false;
}

bool login_check(login_check_info* _input , login_user_info* _db){
	return !(login_check_name(_db->input_user_name)||
		login_check_pwd(_input->user_info.input_user_pwd,_db->input_user_pwd));
}


/////////////////////////////////////////////////
/*3.8*/
void login_err_mgr(sys_err_type _err_type,login_modle* _mld){
	_mld->login_succ = false;
	//db...查找错误信息,填充结构体
	//sys_err_search(&_mld->rlt_info.login_err);

	//将错误信息复制到模块的错误记录中去
	//strcpy(_mld->rlt_info.login_err.info,_temp_err_info);//字符串复制
}

/////////////////////////////////////////////////
/*3.9*/
void login_convert_rlt(login_info* _info , char* _rlt){
	//将结果复制在rlt中传出
	memcpy(_rlt,_info,sizeof(login_info));
}

/******************************************************/
//登陆模块的总流程
//Jiraiya整合
void login_frame(char* _command , int _arg_len , char* _rlt){
	//建立登陆模块
	login_modle* _login_frame = login_init();//初始化登陆模块
	_login_frame->check_info = *login_get_info(_command,_arg_len);
	if(!_login_frame->check_info.vry_is_correct){
		//登陆验证码错误
		//错误处理
		login_err_mgr(err_login_vry_uncmp,_login_frame);
		return;
	}
	//db...
	//这个过程中,就是_db_query的改动过程

	//以下是为了测试
	strcpy(_login_frame->db_query.input_user_name,"haha");
	strcpy(_login_frame->db_query.input_user_pwd,"123");


	//
	if(!login_check(&_login_frame->check_info,&_login_frame->db_query)){
		//用户名或密码不正确
		//错误处理...
		login_err_mgr(err_login_user_or_pwd_err,_login_frame);
		return;
	}

	//进行高级数据查询
	//调用模块3.5
	//得到login_info,即rlt_info
	//...

	//结果转化
	login_convert_rlt(&_login_frame->rlt_info,_rlt);

	//释放模块
	login_release(_login_frame);
}


