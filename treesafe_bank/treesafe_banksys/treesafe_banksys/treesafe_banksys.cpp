// treesafe_banksys.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "banksys_db.h"
#include "banksys_net.h"
#include "banksys_mid.h"

int _tmain(int argc, _TCHAR* argv[])
{
	printf("-------------------------\n");
	printf("mid compute...\n");
	printf("-------------------------\n");
	banksys_net* net_layer = (banksys_net*)malloc(sizeof(banksys_net));
	banksys_db* db_layer = (banksys_db*)malloc(sizeof(banksys_db));
	banksys_mid* mid = (banksys_mid*)malloc(sizeof(banksys_mid));
	mid_recieve_frame(net_layer , mid , db_layer);
	mid_send_frame(net_layer , mid , db_layer);
	free(net_layer);
	free(db_layer);
	free(mid);
	return 0;
}

