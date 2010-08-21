#include "stdafx.h"

#include "treesafe_cServer.h"
//#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

//add connection
void net_add_connection(sys_Server *sServer)
{
	int retVal;
	if(WSAStartup(MAKEWORD(2,2),&sServer->sys_server.wsd)!=0)
	{
		MessageBox(NULL,L"ÍøÂç³õÊ¼»¯´íÎó£¡",L"´íÎóÐÅÏ¢",MB_OK);
		return;
	}

	sServer->sys_server.sServer = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(INVALID_SOCKET == sServer->sys_server.sServer)
	{
		printf("socket failed!\n");
		WSACleanup();
		return;
	}



	sServer->sys_server.addrServ.sin_family = AF_INET;
	sServer->sys_server.addrServ.sin_port = htons(4999);
	sServer->sys_server.addrServ.sin_addr.s_addr = INADDR_ANY;
	retVal = bind(sServer->sys_server.sServer,(LPSOCKADDR)&sServer->sys_server.addrServ,sizeof(SOCKADDR_IN));
	if(SOCKET_ERROR == retVal)
	{
		printf("bind failed!");
		closesocket(sServer->sys_server.sServer);
		WSACleanup();
		return;
	}
}

//release connection
void net_release_connection(sys_Server *sServer)
{
#ifdef DEBUG_NET_INFO
	printf("release server socket!\n");
#endif
	WSACleanup();
}

//wait for request
void net_wait_for_request(sys_Server *sServer)
{
	int retVal;
#ifdef DEBUG_NET_INFO
	printf("wait for client!\n");
#endif
	retVal = listen(sServer->sys_server.sServer,1);
	if (SOCKET_ERROR == retVal)
	{
		printf("listen failed!\n");
		closesocket(sServer->sys_server.sServer);
		WSACleanup();
		return;
	}
	
	int addrClientlen = sizeof(sServer->sys_server.addrClient);
	sServer->sys_server.sClient = accept(sServer->sys_server.sServer,(sockaddr FAR*)&sServer->sys_server.addrClient,&addrClientlen);
	if(INVALID_SOCKET == sServer->sys_server.sClient)
	{
		printf("accept failed!\n");
		closesocket(sServer->sys_server.sServer);
		WSACleanup();
		return;
	}
}

//recieve net data(the size of data is less than 80 bytes)
void net_recieve_data(sys_Server* sServer)
{
#ifdef DEBUG_NET_INFO
	printf("start to recevie data!\n");
#endif
	int reVal;
	reVal = recv(sServer->sys_server.sClient,sServer->rec.cNetDataInfo,sServer->rec.stNetDataLength,0);
	if(SOCKET_ERROR == reVal)
	{
		printf("recv failed!\n");
		closesocket(sServer->sys_server.sServer);
		closesocket(sServer->sys_server.sClient);
		WSACleanup();
		return;
	}
#ifdef DEBUG_NET_INFO
	printf("end receive data!\n");
#endif
}


//send net data(the size of data is less than 80 bytes)
void net_send_data(sys_Server* sServer)
{
#ifdef DEBUG_NET_INFO
	printf("start to send data!\n");
#endif
	int reVal;
	reVal = send(sServer->sys_server.sServer,sServer->send.cNetDataInfo,sServer->send.stNetDataLength,0);
#ifdef DEBUG_NET_INFO
	printf("end send data!\n");
#endif
}

void net_recieve_frame(sys_Server* sServer)
{
	net_add_connection(sServer);
	net_wait_for_request(sServer);
//	initNet(sServer);
	net_recieve_data(sServer);
	net_release_connection(sServer);
}

void net_send_frame(sys_Server* sServer)
{
	net_add_connection(sServer);
	net_wait_for_request(sServer);
//	initNet(sServer);
	net_send_data(sServer);
	net_release_connection(sServer);
}