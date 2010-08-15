#include "stdafx.h"

#include "banksys_net.h"
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

//add connection
void net_add_connection(banksys_net *sServer)
{
	int retVal;
	if(WSAStartup(MAKEWORD(2,2),&sServer->banksys_server.wsd)!=0)
	{
		printf("WSAStartup failed!\n");
		return;
	}

	sServer->banksys_server.sServer = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(INVALID_SOCKET == sServer->banksys_server.sServer)
	{
		printf("socket failed!\n");
		WSACleanup();
		return;
	}



	sServer->banksys_server.addrServ.sin_family = AF_INET;
	sServer->banksys_server.addrServ.sin_port = htons(4999);
	sServer->banksys_server.addrServ.sin_addr.s_addr = INADDR_ANY;
	retVal = bind(sServer->banksys_server.sServer,(LPSOCKADDR)&sServer->banksys_server.addrServ,sizeof(SOCKADDR_IN));
	if(SOCKET_ERROR == retVal)
	{
		printf("bind failed!");
		closesocket(sServer->banksys_server.sServer);
		WSACleanup();
		return;
	}
}

//release connection
void net_release_connection(banksys_net *sServer)
{
#ifdef DEBUG_NET_INFO
	printf("release server socket!\n");
#endif
	WSACleanup();
}

//wait for request
void net_wait_for_request(banksys_net *sServer)
{
	int retVal;
#ifdef DEBUG_NET_INFO
	printf("wait for client!\n");
#endif
	retVal = listen(sServer->banksys_server.sServer,1);
	if (SOCKET_ERROR == retVal)
	{
		printf("listen failed!\n");
		closesocket(sServer->banksys_server.sServer);
		WSACleanup();
		return;
	}
	
	int addrClientlen = sizeof(sServer->banksys_server.addrClient);
	sServer->banksys_server.sClient = accept(sServer->banksys_server.sServer,(sockaddr FAR*)&sServer->banksys_server.addrClient,&addrClientlen);
	if(INVALID_SOCKET == sServer->banksys_server.sClient)
	{
		printf("accept failed!\n");
		closesocket(sServer->banksys_server.sServer);
		WSACleanup();
		return;
	}
}

//recieve net data(the size of data is less than 80 bytes)
void net_recieve_data(banksys_net* sServer)
{
#ifdef DEBUG_NET_INFO
	printf("start to recevie data!\n");
#endif
	int reVal;
	reVal = recv(sServer->banksys_server.sClient,sServer->rec.cRecieveInfo,128,0);
	if(SOCKET_ERROR == reVal)
	{
		printf("recv failed!\n");
		closesocket(sServer->banksys_server.sServer);
		closesocket(sServer->banksys_server.sClient);
		WSACleanup();
		return;
	}
#ifdef DEBUG_NET_INFO
	printf("end receive data!\n");
#endif
}


//send net data(the size of data is less than 80 bytes)
void net_send_data(banksys_net* sServer)
{
#ifdef DEBUG_NET_INFO
	printf("start to send data!\n");
#endif-
	int reVal;
	reVal = send(sServer->banksys_server.sServer,sServer->send.cSendInfo,sServer->send.stSendPackSize,0);
#ifdef DEBUG_NET_INFO
	printf("end send data!\n");
#endif
}

void net_recieve_frame(banksys_net* sServer)
{
	net_add_connection(sServer);
	net_wait_for_request(sServer);
	initNet(sServer);
	net_recieve_data(sServer);
	net_release_connection(sServer);
}

void net_send_frame(banksys_net* sServer)
{
	net_add_connection(sServer);
	net_wait_for_request(sServer);
	initNet(sServer);
	net_send_data(sServer);
	net_release_connection(sServer);
}

void initNet(banksys_net* sServer)
{
	sServer->rec.stRecPackSize = BUF_SIZE;
	sServer->rec.cRecieveInfo = (char*)malloc(sizeof(char)*BUF_SIZE);
	sServer->send.stSendPackSize = BUF_SIZE;
	sServer->send.cSendInfo = (char*)malloc(sizeof(char)*BUF_SIZE);
	memset(sServer->rec.cRecieveInfo,'\0',sizeof(sServer->rec.stRecPackSize));

}

