#include "stdafx.h"
#include "sys_reg.h"
/*

/**********************************/
//模块6的实现文件

//6.1 初始化与释放

void reg_init_reg_basic_info(reg_basic_info* _init){
	//初始化基本信息
	//初始用户名
	strcpy(_init->reg_name,"");
	//初始化用户密码
	strcpy(_init->reg_pwd,"");
	//初始化身份证号,十八位0
	strcpy(_init->reg_id,"000000000000000000");
	//初始化真实姓名
	strcpy(_init->reg_basic_user_name,"");
	//初始化性别,男
	_init->reg_gender = male;
	//初始化年龄,18
	_init->reg_age = 18;
	//家庭住址
	strcpy(_init->reg_home_addr,"");
}

void reg_init_reg_input_info(reg_input_info* _init){
	//初始化输入信息
	//设置基本信息块
	reg_init_reg_basic_info(&_init->basic_info);
	//设置其它附加信息,这里以电子邮件为例
	strcpy(_init->email_addr,"");
	//设置密码双次验证的正确性,初始置为false
	_init->is_pwd_vry_crr = false;
}

void reg_init_reg_info(reg_info* _init){
	//初始化注册过程信息
	//初始化错误信息
	init_sys_err(&_init->reg_err);
	strcpy(_init->user_name,"");
}

reg_modle* reg_init(){
	//初始化注册模块
	//分配内存
	reg_modle* _new_modle = 
		(reg_modle*)malloc(sizeof(reg_modle));
	//注册是否成功
	_new_modle->reg_succ = false;
	//初始化各数据块
	reg_init_reg_input_info(&_new_modle->input_info);
	reg_init_reg_basic_info(&_new_modle->db_query_from_bank);
	reg_init_reg_info(&_new_modle->info);
	return _new_modle;
}