#include "stdafx.h"
#include "treesate_cClient.h"



//init client
void InitClient(sys_Client* client)
{

	if (WSAStartup(MAKEWORD(2,2),&client->sys_net.wsd) !=0)
	{
		printf("WSAStartup failed!\n");
		return;
	}
}

//create socket 
void CreateSocket(sys_Client* client)
{
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
	int retVal;
	client->sys_net.servAddr.sin_family = AF_INET;
	client->sys_net.servAddr.sin_addr.s_addr = inet_addr(BANKIP);
	client->sys_net.servAddr.sin_port = htons(port);
	int nServAddlen = sizeof(client->sys_net.servAddr);
	retVal = connect(client->sys_net.sHost,(LPSOCKADDR)&client->sys_net.servAddr,sizeof(client->sys_net.servAddr));
	if (SOCKET_ERROR == retVal)
	{
		printf("connect failed!\n");
		closesocket(client->sys_net.sHost);
		WSACleanup();
		return;
	}
	printf("connect OK");
}

//send data
void SendData(sys_Client* client)
{
	int retVal;
	retVal = send(client->sys_net.sHost,client->send.cNetDataInfo,client->send.stNetDataLength,0);
	if (SOCKET_ERROR == retVal)
	{
		closesocket(client->sys_net.sHost);
		WSACleanup();
		return;
	}

		int reVal;
	if(client->send.stNetDataLength <= PackageSize)
	{
		char temp[] = "01";
		reVal = send(client->sys_net.sHost,temp,sizeof(temp),0);
		reVal = send(client->sys_net.sHost,client->send.cNetDataInfo,client->send.stNetDataLength,0);	
	}
	else
	{
		char temp[] =  "99";
		int iCount = client->send.stNetDataLength / PackageSize + 1;
		int iLastPackageSize = client->send.stNetDataLength - PackageSize * iCount;
		_itoa(iCount,temp,10);
		reVal = send(client->sys_net.sHost,temp,sizeof(temp),0);
		while(iCount--)
		{
			reVal = send(client->sys_net.sHost,client->send.cNetDataInfo,PackageSize,0);
			client->send.cNetDataInfo += PackageSize;
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
	char cCount[] = "99";
	int reVal = recv(client->sys_net.sHost,cCount,sizeof(cCount),0);
	int iCount = atoi(cCount);
	client->rec.cNetDataInfo = (char*)malloc(sizeof(char)*PackageSize*iCount);
	client->rec.stNetDataLength = PackageSize*iCount;
	memset(client->rec.cNetDataInfo,'\0',client->rec.stNetDataLength);
	for(int i = 0;i!=iCount;i++)
	{
		char tempPack[PackageSize];
		reVal = recv(client->sys_net.sHost,tempPack,PackageSize,0);
		memcpy(client->rec.cNetDataInfo + iCount*PackageSize,tempPack,PackageSize);
	}
	if(SOCKET_ERROR == reVal)
	{
		printf("recv failed!\n");
		closesocket(client->sys_net.sHost);
		WSACleanup();
		return;
	}
}

//exit client
void ExitClient(sys_Client* client)
{
	closesocket(client->sys_net.sHost);
	WSACleanup();
	return;
}

