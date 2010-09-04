#pragma once

#include "string.h"
//模块4 全局错误处理
//此模块由sunni完成

//此模块高度独立，在数据库中，通过错误类型去检索错误信息
//错误信息的最大容量为MAX_ERR_INFO

#define MAX_ERR_INFO 128 //这个 可再定

//模块4.1
//错误类型编码
//这个将随着项目的开发不断地增加
//编码命名 err_模块名称_错误原因
//一个枚举类型
enum sys_err_type{
	err_no_err = 0,//无错误
	err_unknow = 9,//不可解析错误
	//登陆过程中将会遇到的错误
	err_login_user_or_pwd_err = 1,//用户名或密码不对
	err_login_vry_uncmp = 2,//验证码不匹配
	err_login_db_err = 3,//数据库访问错误
	//注册过程中会遇到的错误
	err_reg_vry_pwd_err = 4,//密码确认出错
	err_reg_info_check_wrong = 5,//与银行中的数据比对时出错
	err_reg_info_db_wrong=6,//数据库操作失败
	//在申请处理时会遇到的错误
	err_apply_info_chech_wrong = 7,//基础信息核对有错
	err_apply_info_no_user = 8//无此用户
};

//错误信息结构体
struct sys_err{
	sys_err_type type;
	char info[MAX_ERR_INFO];
};



//错误信息结构体的初始化函数
void init_sys_err(sys_err* _err);




//模块4.2
//错误信息查找
//根据错误编码号,查找错误信息
void sys_err_search(sys_err* _err);