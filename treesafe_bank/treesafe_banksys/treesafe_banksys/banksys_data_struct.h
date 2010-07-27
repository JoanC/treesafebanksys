#ifndef _BANKSYS_DATA_STRUCT_H_
#define _BANKSYS_DATA_STRUCT_H_

//存放了所有数据结构体 
#include <winsock2.h>
//server socket struct

struct net_Server
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
	net_recieved_info rec;//接受到的数据
	net_send_info send;//发送的数据
	net_Server banksys_server;
};



/////////////////////////////////////////////////////////
//数据库模块
//将请求数据发送给数据库
//数据中包括了请求与请求的相关数据
struct bankDB_request_info{
	int type;
	int index;
};

//结果数据
//输出的数据都存入其中
struct bankDB_result_info{
	void* data;
};

struct banksys_db{
	bankDB_request_info req;//数据库DB的请求数据
	bankDB_result_info rlt;//DB结果信息
	//...
};

/////////////////////////////////////////////////////////
//mid 模块
struct banksys_mid{
	bool isDbComplete;//将发送的
	net_recieved_info rec;//从网络接口中接受到的数据
	net_send_info send;//转化后，将要发送的数据
	bankDB_request_info req;//发送给数据库DB的请求数据
	bankDB_result_info rlt;//从数据库接受的DB结果信息
};

#endif