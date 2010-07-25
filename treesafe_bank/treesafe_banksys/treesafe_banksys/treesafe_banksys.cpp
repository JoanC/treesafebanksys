// treesafe_banksys.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "banksys_mid.h"

int _tmain(int argc, _TCHAR* argv[])
{
	banksys_mid* _mid = (banksys_mid*)malloc(sizeof(banksys_mid));
	net_recieved_info* _rec = (net_recieved_info*)malloc(sizeof(net_recieved_info));
	mid_get_data_from_net( _mid , _rec);
	return 0;
}

