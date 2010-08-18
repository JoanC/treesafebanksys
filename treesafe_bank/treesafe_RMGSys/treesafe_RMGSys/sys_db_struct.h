#pragma once

//登陆模块的信息查询
const size_t idLen = 19 ;
const size_t pwdLen = 16 ;


//登陆权限
//管理员,一般用户...
enum login_competence{
	compe_admin,
	compe_user
	//...other competence
};

struct sys_db_login{
	char cust_id[idLen] ;
	char login_pwd[pwdLen] ;
	bool is_employee ;
	char employee_id[idLen] ;
};