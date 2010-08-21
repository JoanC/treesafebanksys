// treesafe_RMGSys.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sys_login.h"
//#include "treesate_cClient.h"

//#include "sys_command.h"

#ifdef TEST_REG_MODLE
#include "sys_reg.h"
#endif

int _tmain(int argc, _TCHAR* argv[])
{

#ifdef TEST_BANK_SYS_CONNECTION
	/*********************/
	//银行子系统代码段
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


#ifdef TEST_REG_MODLE
	reg_input_info test_input;
	test_input.basic_info.reg_age = 20;
	strcpy(test_input.basic_info.reg_basic_user_name,"Amor");
	test_input.basic_info.reg_gender = female;
	strcpy(test_input.basic_info.reg_home_addr ,"江西省南昌市上海路");
	strcpy(test_input.basic_info.reg_id,"123456789123456789");
	strcpy(test_input.basic_info.reg_name,"my baby");
	strcpy(test_input.basic_info.reg_pwd,"xbx8206897");
	char cmd[256];
	char rlt[256];
	memcpy(cmd,&test_input,sizeof(reg_input_info));
	reg_frame(cmd,sizeof(reg_input_info),rlt);
#endif
	return 0;
}

