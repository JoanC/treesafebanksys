#pragma once
#include "sys_error_compute.h"//错误处理代码

#define MAX_GROUP_SIZE 6
#define GROUP_CUST_ID_LEN 19
#define GROUP_ID_LEN 11

struct group_member_info //数据库操作用
{
	char		cust_id[MAX_GROUP_SIZE][GROUP_CUST_ID_LEN] ; //id数组
	int		num ;    //id数组长度
} ;

bool init_group_member_info(group_member_info *_Outcome) ;
