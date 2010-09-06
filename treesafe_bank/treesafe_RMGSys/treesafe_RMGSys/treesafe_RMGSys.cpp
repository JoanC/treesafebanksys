// treesafe_RMGSys.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "treesate_cClient.h"

//#include "sys_command.h"

#include "sys_frame.h"
#include "database_mgr.h"

#ifdef TEST_RESEARCH_EXACT_MODLE
#include "sys_research_exact.h"
#endif 

#ifdef TEST_REG_MODLE
#include "sys_reg.h"
#endif

//作为网页的服务器
sys_Server server_of_website;


//作为银行子系统的服客户端
sys_Client client_of_bank;


//风险系统的数据库连接指针
_ConnectionPtr* treesafe_db_connection;



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
	sys_Client client;
	memset(client.send.,' ',sizeof(client.buf));
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
	treesafe_db_connection = 
		(_ConnectionPtr*)calloc(sizeof(_ConnectionPtr),1);
	//	ConnectDB(treesafe_db_connection);

	reg_input_info test_input;
	test_input.basic_info.reg_age = 20;
	strcpy(test_input.basic_info.reg_basic_user_name,"Amor");
	test_input.basic_info.reg_gender = reg_info_female;
	strcpy(test_input.basic_info.reg_home_addr ,"江西省南昌市上海路");
	strcpy(test_input.basic_info.reg_id,"123456789123456789");
	strcpy(test_input.basic_info.reg_basic_user_name,"my baby");
	strcpy(test_input.basic_info.reg_pwd,"xbx8206897");
	strcpy(test_input.basic_info.reg_phone_num,"13805123684") ;
	char cmd[256];
	char rlt[256];
	int len = 0;
	memcpy(cmd,&test_input,sizeof(reg_input_info));
	reg_frame(cmd,sizeof(reg_input_info),rlt,&len);

	//	DisconnectDB(treesafe_db_connection);
	free(treesafe_db_connection);
#endif

#ifdef TEST_RESEARCH_EXACT_MODLE
	char rlt[256];
	char cmd[256] = "";
	int rlt_len = 0;
	research_exact_frame(cmd,12,rlt,&rlt_len);
#endif

	treesafe_db_connection = new _ConnectionPtr;
	ConnectDB(treesafe_db_connection);
	while(1){
		server_of_website.rec.cNetDataInfo =NULL;
		server_of_website.send.cNetDataInfo = NULL;
		sys_frame_work();
		if(server_of_website.rec.cNetDataInfo != NULL){
			free(server_of_website.rec.cNetDataInfo);
		}
		if(server_of_website.send.cNetDataInfo != NULL){
			free(server_of_website.send.cNetDataInfo);
		}
	}
	DisconnectDB(treesafe_db_connection);
	delete (treesafe_db_connection);
	return 0;
}

