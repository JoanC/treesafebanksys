#pragma once

#include "stdafx.h"
#include "sys_frame.h"

//��Ϊ��ҳ�ķ�����
extern sys_Server server_of_website;


//��Ϊ������ϵͳ�ķ��ͻ���
extern sys_Client client_of_bank;

void sys_frame_work(){
	net_recieve_frame(&server_of_website);
	sys_command_run_frame(&server_of_website.rec
		,&server_of_website.send);
	net_send_frame(&server_of_website);
} 