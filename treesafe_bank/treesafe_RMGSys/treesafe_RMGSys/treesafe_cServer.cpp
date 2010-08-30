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
		//MessageBox(NULL,L"ÍøÂç³õÊ¼»¯´íÎó£¡",L"´íÎóÐÅÏ¢",MB_OK);
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
	sServer->sys_server.addrServ.sin_port = BANKPORT;
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

void net_recieve_data(sys_Server* sServer)
{
#ifdef DEBUG_NET_INFO
	printf("start to recevie data!\n");
#endif
	int reVal;
	char cCount[] = "99";
	reVal = recv(sServer->sys_server.sClient,cCount,sizeof(cCount)-1,0);
	int iCount = atoi(cCount);
	sServer->rec.cNetDataInfo = (char*)malloc(sizeof(char)*PackageSize*iCount);
	sServer->rec.stNetDataLength = PackageSize*iCount;
	memset(sServer->rec.cNetDataInfo,'\0',sServer->rec.stNetDataLength);
	for(int i = 0;i!=iCount;i++)
	{
		char tempPack[PackageSize];
		reVal = recv(sServer->sys_server.sClient,tempPack,PackageSize,0);
		memcpy(sServer->rec.cNetDataInfo + i*PackageSize,tempPack,PackageSize);
	}
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
	if(sServer->send.stNetDataLength <= PackageSize)
	{
		char temp[] = "01";
		reVal = send(sServer->sys_server.sClient,temp,sizeof(temp),0);
		reVal = send(sServer->sys_server.sClient,sServer->send.cNetDataInfo,sServer->send.stNetDataLength,0);	
	}
	else
	{
		char temp[] =  "99";
		int iCount = sServer->send.stNetDataLength / PackageSize + 1;
		int iLastPackageSize = sServer->send.stNetDataLength - PackageSize * (iCount-1);
		_itoa(iCount,temp,10);
		reVal = send(sServer->sys_server.sClient,temp,sizeof(temp),0);
		
		char* _temp_send_ptr = sServer->send.cNetDataInfo;

		while(iCount--)
		{
			reVal = send(sServer->sys_server.sClient,_temp_send_ptr,PackageSize,0);
			_temp_send_ptr += PackageSize;
		}
	}
	if(SOCKET_ERROR == reVal)
	{
		printf("recv failed!\n");
		closesocket(sServer->sys_server.sServer);
		closesocket(sServer->sys_server.sClient);
		WSACleanup();
		return;
	}
#ifdef DEBUG_NET_INFO
	printf("end send data!\n");
#endif
}

void net_recieve_frame(sys_Server* sServer)
{
	net_add_connection(sServer);
	net_wait_for_request(sServer);
	net_recieve_data(sServer);
//	net_release_connection(sServer);
}

void net_send_frame(sys_Server* sServer)
{
//	net_add_connection(sServer);
//	net_wait_for_request(sServer);
	net_send_data(sServer);
	net_release_connection(sServer);
}