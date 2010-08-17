//模块2
#include "treesafe_cServer.h"

//所有子流程都要包含
#include "sys_login.h"//登陆的子流程

typedef char* COMMAND_DATA;

enum{
	//命令编号集合
	sys_cmd_login,//登录指令
	sys_cmd_unexpect//未知命令(不可解析)
};
#pragma once

/************************************************/
//模块2
//接受过程的过渡模块
//该模块由Jiraiya和王组长完成

//该模块本质是一个协议
//每个模块解析网络层中传来的命令
//并将data发送到对应的子过程中去
//该模块与发送无关

//模块2.1
//0.1 -- 接受收网络服务层的数据,并且予以解析
//一个大的switch_case
//根据不同的命令参数,调用不同的处理函数
void sys_command(const sys_net_data* _command);


//模块2.2
//0.2不同的子处理函数

//登陆模块的处理函数2.2.1
void sys_command_login(const sys_net_data* _cmd);

//模块2.3
//未知命令的处理函式
void sys_command_err(const sys_net_data* _command);
