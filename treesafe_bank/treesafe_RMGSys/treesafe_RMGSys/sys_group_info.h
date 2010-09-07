#pragma once
#include "sys_error_compute.h"//���������

#define MAX_GROUP_SIZE 6
#define GROUP_CUST_ID_LEN 19
#define GROUP_ID_LEN 11

struct group_mem_info{
	//��Ա��Ϣ
	char _id[GROUP_CUST_ID_LEN];
};

struct group_info{
	//����Ϣ
	char group_id[GROUP_ID_LEN];
	int length;
    group_mem_info mem[MAX_GROUP_SIZE];
};

void init_group_mem_info(group_mem_info* _init);

void init_group_info(group_info* _init);