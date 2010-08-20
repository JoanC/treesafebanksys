#include "stdafx.h"
#include "sys_command.h"


//模块2.1
void sys_command(const sys_net_data* _command,char* _rlt , int* _rlt_len){
	int _command_type = _command->type;//获取命令的类型
	//协议分析
	switch (_command_type){
	case(sys_cmd_login):{
		//调用登录处理子函数
		sys_command_login(_command,_rlt , _rlt_len);
						}break;
	case(sys_cmd_reg):{
		//调用登录处理子函数
		sys_command_reg(_command,_rlt,_rlt_len);
					  }break;
	case(sys_cmd_unexpect):{
		sys_command_err(_command,_rlt,_rlt_len);
						   }break;
	default:
		sys_command_err(_command,_rlt,_rlt_len);
	}
}

//模块2.2
//2.2.1 登陆处理
void sys_command_login(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
	//调用登陆主函式
	login_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2,2,2 注册处理
void sys_command_reg(const sys_net_data* _cmd , char* _rlt,int* _rlt_len){
	reg_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

void sys_command_err(const sys_net_data* _command,char* _rlt,int* _rlt_len){

}