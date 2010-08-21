#pragma once
//模块2

//所有子流程都要包含
#include "sys_login.h"//登陆的子流程
#include "sys_error_compute.h"//错误处理模块
#include "sys_reg.h"
#include "net.h"

typedef char* COMMAND_DATA;
#define SYS_CMD_MAX_RLT_SIZE 256

enum{
	//命令编号集合
	sys_cmd_login,//登录指令
	sys_cmd_reg,//注册指令
	sys_cmd_unexpect//未知命令(不可解析)
};

struct sys_net_data{
	int type;//命令类型
	int len;//命令长度
	COMMAND_DATA data;//命令中的数据
};

/************************************************/
//模块2
// 从net中的指令-->转化-->将要发送的数据
//接受过程的过渡模块
//该模块由Jiraiya和王组长完成

//该模块本质是一个协议
//每个模块解析网络层中传来的命令
//并将data发送到对应的子过程中去

/***********************************************/
//模块2.1
//初始化和释放sys_net_info
void sys_command_init_sys_net_data(sys_net_data* _init);
void sys_command_release_sys_net_data(sys_net_data* _release);

/************************************************/
//模块2.2
//0.2 -- 将网络的接受信息转化为命令信息
void sys_command_convert(net_recieved_info* _rev , sys_net_data* _cmd);

/************************************************/
//模块2.3
//0.1 -- 接受收网络服务层的数据,并且予以解析,并执行相应的子流程函式
//一个大的switch_case
//根据不同的命令参数,调用不同的处理函数
//运行指令的结果存在将要发送的一个net_datazhogn 
void sys_command(const sys_net_data* _command,char* _rlt,int* _rlt_len);


//模块2.3
//0.3不同的子处理函数

//登陆模块的处理函数2.3.1
void sys_command_login(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);

//注册模块子处理函式2.3.2
void sys_command_reg(const sys_net_data* _cmd , char* _rlt,int* _rlt_len);

//模块2.4
//未知命令的处理函式
void sys_command_err(const sys_net_data* _command,char* _rlt,int* _rlt_len);

//总体模块
void sys_command_run_frame(net_recieved_info* _rev , net_send_info* _send);
