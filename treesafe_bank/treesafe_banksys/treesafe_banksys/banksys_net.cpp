#include "stdafx.h"

#include "banksys_net.h"
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

//add connection
void net_add_connection(banksys_net &sServer)
{
	int reVal;
	unsigned long u1 = 1;
	reVal = ioctlsocket(sServer.banksys_server.sServer, FIONBIO,(unsigned long*)&u1);
	if (SOCKET_ERROR == reVal)
		return;
}

//release connection
void net_release_connection(banksys_net &sServer)
{
	WSACleanup();
}

//wait for request
void net_wait_for_request(banksys_net &sServer)
{
	int reVal;
	reVal = listen(sServer.banksys_server.sServer,SOMAXCONN);
	if (SOCKET_ERROR == reVal)
		return;
}

//recieve net data(the size of data is less than 80 bytes)
void net_recieve_data(banksys_net &sServer)
{
	int reVal;
	reVal = recv(sServer.banksys_server.sServer,sServer.rec.cRecieveInfo,sServer.rec.stRecPackSize,0);
}


//send net data(the size of data is less than 80 bytes)
void net_send_data(banksys_net &sServer)
{
	int reVal;
	reVal = send(sServer.banksys_server.sServer,sServer.send.cSendInfo,sServer.send.stSendPackSize,0);
}
