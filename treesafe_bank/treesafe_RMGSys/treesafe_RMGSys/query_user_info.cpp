#include "stdafx.h"

#include "query_user_info.h"

void init_user_query_info(user_query_info* _init){
	memset(_init->user_addr,'\0',USER_ADDR_LEN);
	memset(_init->user_card_id,'\0',USER_CARD_ID);
	memset(_init->user_name,'\0',USER_NAME_LEN);
	memset(_init->user_tel,'\0',USER_TEL_LEN);
	_init->
}