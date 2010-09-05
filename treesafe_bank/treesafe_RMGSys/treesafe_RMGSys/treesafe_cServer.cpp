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
	Sleep(1500);
#endif
	closesocket(sServer->sys_server.sServer);
	closesocket(sServer->sys_server.sClient);
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
//	CreateThread(NULL,0,iAccpet,&sServer,0,NULL);
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
	reVal = recv(sServer->sys_server.sClient,cCount,strlen(cCount),0);
	int iCount = atoi(cCount);
	sServer->rec.cNetDataInfo = (char*)malloc(sizeof(char)*PackageSize*iCount);
	sServer->rec.stNetDataLength = PackageSize*iCount;
	memset(sServer->rec.cNetDataInfo,'\0',sServer->rec.stNetDataLength);
	int i;
	for(i = 0;i!=iCount;i++)
	{
		char tempPack[PackageSize] = {'\0'};
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
	printf("rec:%s\n",sServer->rec.cNetDataInfo);
#endif
}


//send net data(the size of data is less than 80 bytes)
void net_send_data(sys_Server* sServer)
{
#ifdef DEBUG_NET_INFO
	printf("start to setiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiind data!\n");
#endif
	int reVal;
	if(sServer->send.stNetDataLength <= PackageSize)
	{
		char temp[] = "01";
		reVal = send(sServer->sys_server.sClient,temp,strlen(temp),0);
		reVal = send(sServer->sys_server.sClient,sServer->send.cNetDataInfo,sServer->send.stNetDataLength,0);	
	}
	else
	{
		char temp[] =  "99";
		int iCount = sServer->send.stNetDataLength / PackageSize + 1;
		int iLastPackageSize = sServer->send.stNetDataLength - PackageSize * (iCount-1);
		_itoa(iCount,temp,10);
		int iLen = strlen(temp);
		char temp2[] = "00"; 
		iLen == 1?memcpy(&temp2[1],temp,strlen(temp)):memcpy(temp2,temp,sizeof(temp));
		reVal = send(sServer->sys_server.sClient,temp2,strlen(temp2),0);
		char* _temp_send_ptr = sServer->send.cNetDataInfo;
		while(iCount--)
		{
			if(iCount == 0)
				reVal = send(sServer->sys_server.sClient,_temp_send_ptr,iLastPackageSize,0);
			else
				reVal = send(sServer->sys_server.sClient,_temp_send_ptr,PackageSize,0);
			_temp_send_ptr += PackageSize;
		}
	}
	printf("wait for OK1!\n");
	//char cRev[] = "UN";
	//int iRltLen = 0;
	//while(iRltLen <=2)
	//{
	//	iRltLen += recv(sServer->sys_server.sClient,cRev,strlen(cRev),0);
	//} 
	//sys_Server _temp;
	//_temp.rec.cNetDataInfo = (char*)malloc(10);
	//net_recieve_data(&_temp);
	printf("client is ok!\n");
	if(SOCKET_ERROR == reVal)
	{
		printf("send failed!\n");
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
	Sleep(2000);
//	net_recieve_data(sServer);
}

void net_send_frame(sys_Server* sServer)
{
	net_send_data(sServer);
	net_release_connection(sServer);
}

DWORD WINAPI iAccpet(LPVOID p)
{
	AllocConsole();
	printf("accept\n");
	sys_Server* sServer;
    MoveMemory(&sServer,p,sizeof(sServer));
	int addrClientlen = sizeof(sServer->sys_server.addrClient);
	sServer->sys_server.sClient = accept(sServer->sys_server.sServer,(sockaddr FAR*)&sServer->sys_server.addrClient,&addrClientlen);
	net_recieve_data(sServer);
	net_send_data(sServer);
	printf("Another Rec:%s",sServer->rec.cNetDataInfo);
	return 0;
}