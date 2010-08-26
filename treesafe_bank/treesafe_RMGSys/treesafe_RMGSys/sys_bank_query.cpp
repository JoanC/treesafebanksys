#include "stdafx.h"
#include "treesate_cClient.h"
#include "sys_bank_query.h"

void sys_connc_bank_query(bankDB_request_info* _req , bankDB_result_info* _rlt){
	//cClient client;
	//InitClient(&client);
	//CreateSocket(&client);
	//Connect2Server(&client);
	//memcpy(client.buf,(char*)_req,sizeof(bankDB_request_info));
	//SendData(&client);
	//RecData(&client);
	//memcpy((char*)_rlt,client.buf,sizeof(client.buf));
	//ExitClient(&client);
	sys_Client treesafe_client;
	InitClient(&treesafe_client);
	
	//?????????????
	treesafe_client.send.cNetDataInfo = (char*)malloc(sizeof(bankDB_request_info));
	//

	CreateSocket(&treesafe_client);
	Connect2Server(&treesafe_client,BANKIP,BANKPORT);
	memcpy(treesafe_client.send.cNetDataInfo,(char*)_req,sizeof(bankDB_request_info));
	SendData(&treesafe_client);
	RecData(&treesafe_client);
	memcpy((char*)_rlt,treesafe_client.send.cNetDataInfo,treesafe_client.send.stNetDataLength);
}