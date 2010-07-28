#include "stdafx.h"
#include "banksys_db.h"

const char c_strConenctionString[] = "Provider=SQLOLEDB.1;Password=111;Persist Security Info=True;User ID=test_user;Initial Catalog=test;Data Source=10.60.37.204" ;

bool ConnectDB(_ConnectionPtr *pConn)
{
	::CoInitialize(0);
	pConn->CreateInstance(__uuidof(Connection));
	(*pConn)->ConnectionString = c_strConenctionString ;
	(*pConn) ->ConnectionTimeout = 10 ;
	(*pConn)->CursorLocation = adUseServer;
	//setting param...
	(*pConn) ->Open("","","",-1) ;
	//open it 

	return true ; //return success or not
}
void DisconnectDB(_ConnectionPtr *pConn)
{
	(*pConn)->Close();
	pConn->Release();
	::CoUninitialize();
}

bool	InquiryResult(banksys_db *_rlt)
{

	return true ;
}
