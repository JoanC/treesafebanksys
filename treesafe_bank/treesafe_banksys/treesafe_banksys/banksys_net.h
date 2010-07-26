#ifndef _BANKSYS_NET_H_
#define _BANKSYS_NET_H_

#include <winsock2.h>
#include"banksys_data_struct.h"


//server socket struct
struct Server
{
	SOCKET sServer;   //server socket
	BOOL bServerRunning;   //whether server is working
};

//recieve info
struct net_recieved_info
{
	size_t stRecPackSize;
	char* cRecieveInfo;
};

//send info
struct net_send_info{
	size_t stSendPackSize;
	char* cSendInfo;
};

struct banksys_net{
	net_recieved_info* rec;//接受到的数据
	net_send_info* send;//发送的数据
	Server banksys_server;
};

//add connection
void net_add_connection(banksys_net &sServer);

//release connection
void net_release_connection(banksys_net &sServer);

//wait for request
void net_wait_for_request(banksys_net &sServer);

//recieve net data(the size of data is less than 80 bytes)
void net_recieve_data(banksys_net &sServer);

//recieve net packet(the size of packet is greater than 80 bytes)
void NetRecievePacket(banksys_net &sServer);

//send net data(the size of data is less than 80 bytes)
void net_send_data(banksys_net &sServer);

//send net packet(the size of packet is greater than 80 bytes)
void NetSendPacket(banksys_net &sServer);
#endif
