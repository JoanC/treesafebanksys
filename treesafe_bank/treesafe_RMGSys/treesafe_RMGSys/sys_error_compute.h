#pragma once

//模块4 全局错误处理
//此模块由sunni完成

//此模块高度独立，在数据库中，通过错误类型去检索错误信息
//错误信息的最大容量为MAX_ERR_INFO

#define MAX_ERR_INFO 128 //这个可再定

//模块4.1
//错误类型编码
//这个将随着项目的开发不断地增加
//编码命名 err_模块名称_错误原因
//一个枚举类型
enum sys_err_type{
	//未知错误
	err_unknow,
	//登陆过程中将会遇到的错误
	err_login_user_or_pwd_err,//用户名或密码不对
	err_login_vry_uncmp//验证码不匹配
};