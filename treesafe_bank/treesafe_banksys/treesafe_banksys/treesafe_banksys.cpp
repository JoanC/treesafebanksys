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
		banksys_frame_send(pframe);
		banksys_frame_deallocate(pframe);
	}
	return 0;
}

