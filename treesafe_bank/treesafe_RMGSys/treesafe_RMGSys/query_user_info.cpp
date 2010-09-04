#include "stdafx.h"

#include "query_user_info.h"

void init_user_query_info(user_query_info* _init){
	memset(_init->user_addr,'\0',USER_ADDR_LEN);
	memset(_init->user_card_id,'\0',USER_CARD_ID);
	memset(_init->user_name,'\0',USER_NAME_LEN);
	memset(_init->user_tel,'\0',USER_TEL_LEN);
	_init->user_gender = user_query_gender_male;
	_init->user_age = 0;
}

void init_user_query_array_info(int _size,user_query_array_info* _init){
	_init->user_num = _size;
	//为数组申请内存
	_init->user_array
		= (user_query_info*)malloc(sizeof(user_query_info) * _size);
	//为每个元素进行初始化设置
	for(int i = 0 ; i < _size ; ++i)
	{
		init_user_query_info(&_init->user_array[i]);
	}
}