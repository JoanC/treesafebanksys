// treesafe_RMGSys.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sys_login.h"
#include "treesate_cClient.h"

int _tmain(int argc, _TCHAR* argv[])
{
	struct bankDB_request_info{
	int		type ;
	char								id[19] ;
};

	bankDB_request_info* test = new bankDB_request_info;
	test->type = 1;
	strcpy(test->id,"100000000000000000");

	cClient client;
	memset(client.buf,'\0',sizeof(*client.buf));
	memcpy(client.buf,test,sizeof(*test));

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

