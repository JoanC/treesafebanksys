#pragma once
#include "database_mgr.h"
#include "sys_error_compute.h"

//模块20
//查询所有拥有贷款的农民信息
//条件 ：已经存在被审核通过的农民信息

#define USER_NAME_LEN 19
#define USER_CARD_ID 19
#define USER_TEL_LEN 12//电话

enum user_query_gender{
	user_query_gender_male = 0,//男
	user_query_fender_female = 1 //女
};

struct user_query_info{
	//一个用户的基本信息
	char user_name[USER_NAME_LEN];//用户名
	char user_card_id[USER_CARD_ID];//身份证id
	user_query_gender user_query;//用户性别
	int user_age;//用户年龄
	char user_tel[USER_TEL_LEN];//用户电话联系方式
	char user_addr[REG_MAX_ADDR];//用户地址
};

struct user_query_array_info{
	int user_num;
	user_query_info* user_array;
};

