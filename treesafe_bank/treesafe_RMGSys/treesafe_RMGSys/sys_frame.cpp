#pragma once

#include "stdafx.h"
#include "sys_frame.h"

//作为网页的服务器
extern sys_Server server_of_website;


//作为银行子系统的服客户端
extern sys_Client client_of_bank;

void sys_frame_work(){
	net_recieve_frame(&server_of_website);
	sys_command_run_frame(&server_of_website.rec
		,&server_of_website.send);
	net_send_frame(&server_of_website);
} 