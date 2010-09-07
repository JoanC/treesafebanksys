#include "stdafx.h"
#include "sys_group_info.h"

void init_group_mem_info(group_mem_info* _init){
	memset(_init->_id,'\0',GROUP_CUST_ID_LEN);
}

void init_group_info(group_info* _init){
	_init->length = 0;
	memset(_init->group_id,'\0',GROUP_ID_LEN);
	for(int i = 0 ; i < MAX_GROUP_SIZE ; ++i){
		init_group_mem_info(&_init->mem[i]);
	}
}