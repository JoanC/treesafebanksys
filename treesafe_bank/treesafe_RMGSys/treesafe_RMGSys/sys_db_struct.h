#pragma once

//登陆模块的信息查询
const size_t idLen = 19 ;
const size_t pwdLen = 16 ;

struct sys_db_login{
	char cust_id[idLen] ;
	char login_pwd[pwdLen] ;
	bool is_employee ;
	char employee_id[idLen] ;
};