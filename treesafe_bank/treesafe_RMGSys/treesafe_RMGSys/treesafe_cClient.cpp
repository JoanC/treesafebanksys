#include "stdafx.h"
#include "treesate_cClient.h"



//init client
void InitClient(sys_Client* client)
{

	if (WSAStartup(MAKEWORD(2,2),&client->sys_net.wsd) !=0)
	{
		printf("WSAStartup failed!\n");
		return;
	}
}

//create socket 
void CreateSocket(sys_Client* client)
{
	client->sys_net.sHost = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (INVALID_SOCKET == client->sys_net.sHost)
	{
		printf("socket failed!\n");
		WSACleanup();
		return;
	}
}


//connect to server
void Connect2Server(sys_Client* client,char* ConnectIP,short port)
{
	int retVal;
	client->sys_net.servAddr.sin_family = AF_INET;
	client->sys_net.servAddr.sin_addr.s_addr = inet_addr(BANKIP);
	client->sys_net.servAddr.sin_port = htons(port);
	int nServAddlen = sizeof(client->sys_net.servAddr);
	retVal = connect(client->sys_net.sHost,(LPSOCKADDR)&client->sys_net.servAddr,sizeof(client->sys_net.servAddr));
	if (SOCKET_ERROR == retVal)
	{
		printf("connect failed!\n");
		closesocket(client->sys_net.sHost);
		WSACleanup();
		return;
	}
	printf("connect OK");
}

//send data
void SendData(sys_Client* client)
{
	int retVal;
	retVal = send(client->sys_net.sHost,client->send.cNetDataInfo,client->send.stNetDataLength,0);
	if (SOCKET_ERROR == retVal)
	{
		closesocket(client->sys_net.sHost);
		WSACleanup();
		return;
	}
}


//rec data
void RecData(sys_Client* client)
{
	int reVal;
	reVal = recv(client->sys_net.sHost,client->rec.cNetDataInfo,client->rec.stNetDataLength,0);
}

//exit client
void ExitClient(sys_Client* client)
{
	closesocket(client->sys_net.sHost);
	WSACleanup();
	return;
}

