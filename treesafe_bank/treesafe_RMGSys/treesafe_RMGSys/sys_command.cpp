#include "stdafx.h"
#include "sys_command.h"


//模块2.1
void sys_command(const sys_net_data* _command){
	int _command_type = _command->type;//获取命令的类型
	//协议分析
	switch (_command_type){
	case(sys_cmd_login):{
		//调用登录处理子函数
		sys_command_login(_command);
						}break;
	case(sys_cmd_unexpect):{
		sys_command_err(_command);
						   }break;
	default:
		sys_command_err(_command);
	}
}

//模块2.2
//2.2.1 登陆处理
void sys_command_login(const sys_net_data* _cmd){
	//调用登陆主函式
}