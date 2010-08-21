#pragma once

//该模块最后协调完成
//协调网络和命令调用
//Jiraiya完成

#include "treesafe_cServer.h"
#include "treesate_cClient.h"
#include "sys_command.h"

//网络全局变量

//作为网页的服务器
sys_Server server_of_website;


//作为银行子系统的服客户端
sys_Client client_of_bank;


void sys_frame_work();
