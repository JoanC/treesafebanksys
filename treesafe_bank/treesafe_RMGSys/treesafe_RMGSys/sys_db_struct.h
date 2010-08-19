#pragma once

//登陆模块的信息查询
//登陆权限
//管理员,一般用户...
enum login_competence{
	compe_err	= 0 ,	
	compe_cust = 1 ,
	compe_operater = 2 ,
	compe_admin = 3,
	//...other competence
};


const size_t idLen			= 19 ;
const size_t pwdLen		= 16 ;
struct sys_db_login{
	char								user_id[idLen] ;
	char								login_pwd[pwdLen] ;
	login_competence		cmpt ;
};