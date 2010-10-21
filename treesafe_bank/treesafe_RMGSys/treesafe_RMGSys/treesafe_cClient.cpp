#include "stdafx.h"
#include "treesate_cClient.h"

//init client
void InitClient(sys_Client* client)
{
DEBUG_NET_PRINT("Init CLient\n");
	if (WSAStartup(MAKEWORD(2,2),&client->sys_net.wsd) !=0)
	{
		printf("WSAStartup failed!\n");
		return;
	}
}

//create socket 
void CreateSocket(sys_Client* client)
{
DEBUG_NET_PRINT("Client:create socket\n");
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
DEBUG_NET_PRINT("Connect to server\n");
	int retVal;
	client->sys_net.servAddr.sin_family = AF_INET;
	client->sys_net.servAddr.sin_addr.s_addr = inet_addr(BANKIP);
	client->sys_net.servAddr.sin_port = port;
	int nServAddlen = sizeof(client->sys_net.servAddr);
	retVal = connect(client->sys_net.sHost,(LPSOCKADDR)&client->sys_net.servAddr,sizeof(client->sys_net.servAddr));
	if (SOCKET_ERROR == retVal)
	{
		printf("connect failed!\n");
		closesocket(client->sys_net.sHost);
		WSACleanup();
		return;
	}
}

//send data
void SendData(sys_Client* client)
{
DEBUG_NET_PRINT("Client:send data\n");
	int reVal;
	if(client->send.stNetDataLength <= PackageSize)
	{
		char temp[] = "01";
		reVal = send(client->sys_net.sHost,temp,strlen(temp),0);
		reVal = send(client->sys_net.sHost,client->send.cNetDataInfo,client->send.stNetDataLength,0);	
	}
	else
	{
		char temp[] =  "99";
		int iCount = client->send.stNetDataLength / PackageSize + 1;
		int iLastPackageSize = client->send.stNetDataLength - PackageSize * (iCount-1);
		_itoa(iCount,temp,10);
		int iLen = strlen(temp);
		char temp2[] = "00"; 
		iLen == 1?memcpy(&temp2[1],temp,strlen(temp)):memcpy(temp2,temp,sizeof(temp));
		reVal = send(client->sys_net.sHost,temp2,strlen(temp2),0);
		char* _temp_send_ptr = client->send.cNetDataInfo;
		while(iCount--)
		{
			reVal = send(client->sys_net.sHost,_temp_send_ptr,PackageSize,0);
			_temp_send_ptr += PackageSize;
		}
	}
	if(SOCKET_ERROR == reVal)
	{
		printf("recv failed!\n");
		closesocket(client->sys_net.sHost);
		WSACleanup();
		return;
	}
}


//rec data
void RecData(sys_Client* client)
{
DEBUG_NET_PRINT("Client:recevie data\n");
	char cCount[] = "99";
	int reVal = recv(client->sys_net.sHost,cCount,strlen(cCount),0);
	int iCount = atoi(cCount);
	client->rec.cNetDataInfo = (char*)malloc(sizeof(char)*PackageSize*iCount);
	client->rec.stNetDataLength = PackageSize*iCount;
	memset(client->rec.cNetDataInfo,'\0',client->rec.stNetDataLength);
	int i;
	for(i = 0;i!=iCount;i++)
	{
		char tempPack[PackageSize] = {'\0'};
		reVal = recv(client->sys_net.sHost,tempPack,PackageSize,0);
		memcpy(client->rec.cNetDataInfo + i*PackageSize,tempPack,PackageSize);
	}
	if(SOCKET_ERROR == reVal)
	{
		printf("recv failed!\n");
		closesocket(client->sys_net.sHost);
		WSACleanup();
		return;
	}
	printf("Rec:%s",client->rec.cNetDataInfo);
}

//exit client
void ExitClient(sys_Client* client)
{
DEBUG_NET_PRINT("Client:Exit client!\n");
	closesocket(client->sys_net.sHost);
	WSACleanup();
	return;
}

