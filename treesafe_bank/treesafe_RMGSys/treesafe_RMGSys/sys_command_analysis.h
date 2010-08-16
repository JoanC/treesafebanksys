//模块2
#include "treesafe_cServer.h"

typedef char* COMMAND_DATA;

enum{
	//命令编号集合
	sys_cmd_login //登录指令
};

//接受过程的过渡模块
//该模块由Jiraiya和王组长完成

//该模块本质是一个协议
//每个模块解析网络层中传来的命令
//并将data发送到对应的子过程中去
//该模块与发送无关

//接受收网络服务层的数据,并且予以解析
//一个大的switch_case
//根据不同的命令参数,调用不同的处理函数
void sys_command(const sys_net_data* _command);

//不同的子处理函数

//登陆模块的处理函数
void sys_command_login(COMMAND_DATA _data);