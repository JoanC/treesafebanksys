#include "stdafx.h"
#include "sys_bank_query.h"
#include "treesate_cClient.h"
#include "net.h"


extern sys_Client client_of_bank;

void sys_connc_bank_query(bankDB_request_info* _req , bankDB_result_info* _rlt){
	//cClient client;

	//CreateSocket(&client);
	//Connect2Server(&client);
	//memcpy(client.buf,(char*)_req,sizeof(bankDB_request_info));
	//SendData(&client);
	//RecData(&client);
	//memcpy((char*)_rlt,client.buf,sizeof(client.buf));
	//ExitClient(&client);
	//?????????????
	client_of_bank.send.cNetDataInfo = (char*)malloc(sizeof(bankDB_request_info));
	client_of_bank.rec.cNetDataInfo = (char*)malloc(sizeof(bankDB_result_info));
	client_of_bank.send.stNetDataLength = sizeof(bankDB_request_info);
	//
	//
	memcpy(client_of_bank.send.cNetDataInfo,_req,sizeof(bankDB_request_info));
	
	InitClient(&client_of_bank);
	CreateSocket(&client_of_bank);
	Connect2Server(&client_of_bank,BANKIP,4999);
	SendData(&client_of_bank);
	RecData(&client_of_bank);
}