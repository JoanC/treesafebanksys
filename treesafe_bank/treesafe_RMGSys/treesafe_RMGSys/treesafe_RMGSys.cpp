// treesafe_RMGSys.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "treesate_cClient.h"

#include "sys_command.h"

int _tmain(int argc, _TCHAR* argv[])
{
#ifdef TEST_BANK_SYS_CONNECTION
	/*********************/
	银行子系统代码段
	struct bankDB_request_info
	{
	int		type ;
	char		id[19] ;
	
};
	bankDB_request_info* test = new bankDB_request_info;
	strcpy(test->id,"123456789123456789");
	test->type = 1;
	cClient client;
	memset(client.buf,' ',sizeof(client.buf));
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
#endif
	login_check_info _test;
	strcpy(_test.user_info.input_user_name,"haha");
	strcpy(_test.user_info.input_user_pwd ,"123");
	_test.vry_is_correct = true;

     char _command[128];
	 char _rlt[128];
     memcpy(_command,&_test,sizeof(_test));

	sys_net_data cmd;
	cmd.type = sys_cmd_login;
	cmd.len = sizeof(login_check_info);

	sys_command(&cmd,_rlt);

	return 0;
}

