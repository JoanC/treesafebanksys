// treesafe_RMGSys.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sys_login.h"
#include "treesate_cClient.h"

int _tmain(int argc, _TCHAR* argv[])
{
	cClient client;
	strcpy(client.buf,"12345678");
	InitClient(&client);
	CreateSocket(&client);
	Connect2Server(&client);
	/*login_input_info* input = 
		(login_input_info*)malloc(sizeof(login_input_info));
	login_info* info = 
		(login_info*)malloc(sizeof(login_info));
	login_frame(info,input);*/
	SendData(&client);
	ExitClient(&client);
	return 0;
}

