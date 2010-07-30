#include "stdafx.h"

#include "banksys_net.h"
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

//add connection
void net_add_connection(banksys_net *sServer)
{
	int reVal;
	unsigned long u1 = 1;
#ifdef DEBUG_NET_INFO
	printf("init server socket!\n");
#endif
	reVal = ioctlsocket(sServer->banksys_server.sServer, FIONBIO,(unsigned long*)&u1);
	if (SOCKET_ERROR == reVal)
		return;
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
#ifdef DEBUG_NET_INFO
	printf("wait for client!\n");
#endif
	int reVal;
	reVal = listen(sServer->banksys_server.sServer,SOMAXCONN);
	if (SOCKET_ERROR == reVal)
		return;
}

//recieve net data(the size of data is less than 80 bytes)
void net_recieve_data(banksys_net* sServer)
{
#ifdef DEBUG_NET_INFO
	printf("start to recevie data!\n");
#endif
	int reVal;
	reVal = recv(sServer->banksys_server.sServer,sServer->rec.cRecieveInfo,sServer->rec.stRecPackSize,0);
#ifdef DEBUG_NET_INFO
	printf("end receive data!\n");
#endif
}


//send net data(the size of data is less than 80 bytes)
void net_send_data(banksys_net* sServer)
{
#ifdef DEBUG_NET_INFO
	printf("start to send data!\n");
#endif
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
	net_recieve_data(sServer);
	net_release_connection(sServer);
}

void net_send_frame(banksys_net* sServer)
{
	net_add_connection(sServer);
	net_wait_for_request(sServer);
	net_send_data(sServer);
	net_release_connection(sServer);
}

