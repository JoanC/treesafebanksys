#include "stdafx.h"
#include "sys_query_group.h"

void init_query_group_input(query_group_input* _init){
	//空初始化
	return;
}

void init_query_group_info(query_group_info* _init){
	//初始化分组数组信息
	init_sys_err(&_init->err_info);
	_init->group_num = 0;
	for(int i = 0 ; i < MAX_GROUP_INFO ; ++i){
		init_group_info(&_init->group[i]);
	}
}

query_group_modle* init_query_group_modle(){

}