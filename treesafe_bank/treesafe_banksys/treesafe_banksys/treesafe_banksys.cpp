// treesafe_banksys.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "banksys_db.h"
#include "banksys_net.h"
#include "banksys_mid.h"

int _tmain(int argc, _TCHAR* argv[])
{
	printf("-------------------------\n");
	printf("banksys compute...\n");
	printf("-------------------------\n");
	banksys_net* net_layer = (banksys_net*)malloc(sizeof(banksys_net));
	banksys_db* db_layer = (banksys_db*)malloc(sizeof(banksys_db));
	banksys_mid* mid = (banksys_mid*)malloc(sizeof(banksys_mid));
	
	//net...
	//mid...
	//mid_recieve_frame(net_layer , mid , db_layer);

	//db....
	_ConnectionPtr *pConn = new _ConnectionPtr;
	ConnectDB(pConn);
	banksys_db _rlt  ;
	_rlt.req.type = CUST_INFO ;
	strcpy_s(_rlt.req.id	,"123456789123456789") ;
	InquiryResult(&_rlt,pConn);

	//mid...
	//mid_send_frame(net_layer , mid , db_layer);

	//net...
	
	free(net_layer);
	free(db_layer);
	free(mid);
	return 0;
}

