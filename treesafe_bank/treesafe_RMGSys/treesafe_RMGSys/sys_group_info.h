#pragma once
#include "sys_error_compute.h"//���������

#define MAX_GROUP_SIZE 6
#define GROUP_CUST_ID_LEN 19
#define GROUP_ID_LEN 11

struct group_member_info //���ݿ������
{
	char		cust_id[MAX_GROUP_SIZE][GROUP_CUST_ID_LEN] ; //id����
	int		num ;    //id���鳤��
} ;

bool init_group_member_info(group_member_info *_Outcome) ;
