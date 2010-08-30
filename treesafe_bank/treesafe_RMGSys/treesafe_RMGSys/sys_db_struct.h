#pragma once

//登陆模块的信息查询
//登陆权限
//管理员,一般用户...
enum login_competence{
	compe_err	= -1 ,	
	compe_cust = 0 ,
	compe_operater = 1 ,
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

//以下的结构体
//由Jiraiya添加
//用途在各个名字前做详细说明

//模块7,8要用的
//审核表
//即申请信息加各个信息是否正确(bit)和一个注释
//具体的你命名
struct sys_db_research{
	//审核申请的编号
	//各信息的原始数据(申请人id等)

	//各信息的是否正确
	//...

	//注释信息(1个即可)
	//...
};

//模块9使用的
//正式的申请信息
struct sys_db_apply{
	//正式申请的编号
	//各信息的最终数据(申请人id等)
	//...
};