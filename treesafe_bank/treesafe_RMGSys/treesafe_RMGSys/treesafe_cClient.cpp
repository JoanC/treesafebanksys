#include "StdAfx.h"
#include "treesate_cClient.h"



//init client
void InitClient(cClient* client)
{

	if (WSAStartup(MAKEWORD(2,2),&client->wsd) !=0)
	{
		printf("WSAStartup failed!\n");
		return;
	}

}

//create socket
void CreateSocket(cClient* client)
{
	client->sHost = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (INVALID_SOCKET == client->sHost)
	{
		printf("socket failed!\n");
		WSACleanup();
		return;
	}
}


//connect to server
void Connect2Server(cClient* client)
{
	int retVal;
	client->servAddr.sin_family = AF_INET;
	client->servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	client->servAddr.sin_port = htons((short)4999);
	int nServAddlen = sizeof(client->servAddr);
	retVal = connect(client->sHost,(LPSOCKADDR)&client->servAddr,sizeof(client->servAddr));
	if (SOCKET_ERROR == retVal)
	{
		printf("connect failed!\n");
		closesocket(client->sHost);
		WSACleanup();
		return;
	}
}

//send data
void SendData(cClient* client)
{
	int retVal;
	ZeroMemory(client->buf,BUF_SIZE);
	retVal = send(client->sHost,client->buf,strlen(client->buf),0);
	if (SOCKET_ERROR == retVal)
	{
		closesocket(client->sHost);
		WSACleanup();
		return;
	}
}


//rec data
void RecData(cClient* client)
{
	int reVal;
	reVal = recv(client->sHost,client->buf,sizeof(client->buf),0);
}

//exit client
void ExitClient(cClient* client)
{
	closesocket(client->sHost);
	WSACleanup();
	return;
}

