#pragma once
#include "sys_error_compute.h"



#define USER_NAME_LEN 19
#define USER_CARD_ID 19
#define USER_TEL_LEN 12//电话
#define USER_ADDR_LEN 64

enum user_query_gender{
	user_query_gender_male = 0,//男
	user_query_fender_female = 1 //女
};

struct user_query_info{
	//一个用户的基本信息
	char user_name[USER_NAME_LEN];//用户名
	char user_card_id[USER_CARD_ID];//身份证id
	user_query_gender user_gender;//用户性别
	int user_age;//用户年龄
	char user_tel[USER_TEL_LEN];//用户电话联系方式
	char user_addr[USER_ADDR_LEN];//用户地址
};

struct user_query_array_info{
	int user_num;
	user_query_info* user_array;
};

/***********************************/
//初始化函数

//初始化用户基本信息
void init_user_query_info(user_query_info* _init);

//初始化用户的数组信息
void init_user_query_array_info(int _size,user_query_array_info* _init);