#pragma once
#include "sys_error_compute.h"//错误处理代码

#define MAX_GROUP_SIZE 6
#define GROUP_CUST_ID_LEN 19
#define GROUP_ID_LEN 11

struct group_mem_info{
	//组员信息
	char _id[GROUP_CUST_ID_LEN];
};

struct group_info{
	//组信息
	char group_id[GROUP_ID_LEN];
	int length;
    group_mem_info mem[MAX_GROUP_SIZE];
};

void init_group_mem_info(group_mem_info* _init);

void init_group_info(group_info* _init);