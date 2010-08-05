// treesafe_banksys.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "banksys_frame.h"

int _tmain(int argc, _TCHAR* argv[])
{
	printf("-------------------------\n");
	printf("banksys compute...\n");
	printf("-------------------------\n");
	while(1){
		banksys_frame* pframe = banksys_frame_allocate();
		banksys_frame_recieve(pframe);
		printf("%s\n",pframe->sys_net->rec.cRecieveInfo);
		banksys_frame_send(pframe);
		banksys_frame_deallocate(pframe);
	}
	banksys_net server;
	net_add_connection(&server);
	net_wait_for_request(&server);
	net_recieve_data(&server);
	printf("%s\n",server.rec.cRecieveInfo);
	/*net_recieve_frame(&server);
	printf("%s\n",server.rec.cRecieveInfo);*/
	return 0;
}

