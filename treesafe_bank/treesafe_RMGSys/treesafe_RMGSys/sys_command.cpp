#include "stdafx.h"
#include "sys_command.h"

//模块2.1
void sys_command_convert(net_recieved_info* _rev , sys_net_data* _cmd){
	//生成的结构体必然会比rev长
	//_cmd->data = (COMMAND_DATA)malloc(_rev->stNetDataLength);
	strcpy(_cmd->data,"");
	//内存复制,转化
    memcpy(_cmd,_rev->cNetDataInfo,sizeof(sys_net_data));
}

void sys_command_init_sys_net_data(sys_net_data* _init){
	//_init->data = NULL;
	_init->len = 0;
	_init->type = sys_cmd_unexpect;
}
void sys_command_release_sys_net_data(sys_net_data* _release){
	//if(_release->data != NULL) free(_release->data);
	free(_release);
}

//模块2.2
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

//模块2.3
//2.3.1 登陆处理
void sys_command_login(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
	//调用登陆主函式
	login_frame(&_cmd->data[0],_cmd->len,_rlt,_rlt_len);
}

//2.3.2 注册处理
void sys_command_reg(const sys_net_data* _cmd , char* _rlt,int* _rlt_len){
	//reg_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//模块2.4
void sys_command_err(const sys_net_data* _command,char* _rlt,int* _rlt_len){

}

void sys_command_run_frame(net_recieved_info* _rev , net_send_info* _send){
	//2.1 -- 初始化网络数据块
	sys_net_data* _cmd_info
		= (sys_net_data*)malloc(sizeof(sys_net_data));
	char rlt[SYS_CMD_MAX_RLT_SIZE];
	int _len = 0;
	sys_command_init_sys_net_data(_cmd_info);

	//2.2 -- 转化
	sys_command_convert(_rev,_cmd_info);

	//2.3解析并运行子流程模块
	sys_command(_cmd_info,rlt,&_len);

	//生成要发送的信息
	_send->netType = NETDATA;//...
	_send->stNetDataLength = _len;
	//生成信息
	if(_len != 0){
		_send->cNetDataInfo = (char*)malloc(_len);
		memcpy(_send->cNetDataInfo,rlt,_len);
	}
	//释放
	sys_command_release_sys_net_data(_cmd_info);
}