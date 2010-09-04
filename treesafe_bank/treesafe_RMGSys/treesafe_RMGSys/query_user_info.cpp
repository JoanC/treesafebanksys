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
	//Ϊ���������ڴ�
	_init->user_array
		= (user_query_info*)malloc(sizeof(user_query_info) * _size);
	//Ϊÿ��Ԫ�ؽ��г�ʼ������
	for(int i = 0 ; i < _size ; ++i)
	{
		init_user_query_info(&_init->user_array[i]);
	}
}