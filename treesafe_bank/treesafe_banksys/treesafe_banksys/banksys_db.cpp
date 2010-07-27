#include "stdafx.h"
#include "banksys_db.h"

void ConnectDB(_ConnectionPtr &pConn)
{
	::CoInitialize(0);
	pConn.CreateInstance(__uuidof(Connection));
	pConn->ConnectionString = "Provider=SQLOLEDB.1;Password=111;Persist Security Info=True;User ID=test_user;Initial Catalog=test;Data Source=10.60.37.204";
	pConn ->ConnectionTimeout = 5;
	pConn ->CursorLocation = adUseServer;
	pConn ->Open("","","",-1);
//	printf("数据库连接成功\r\n");
}
void DisconnectDB(_ConnectionPtr &pConn)
{
	pConn->Close();
	pConn.Release();
	::CoUninitialize();
}