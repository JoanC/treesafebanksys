#pragma once
#include "database_mgr.h"
#include "sys_error_compute.h"

//ģ��20
//��ѯ����ӵ�д����ũ����Ϣ
//���� ���Ѿ����ڱ����ͨ����ũ����Ϣ

#define USER_NAME_LEN 19
#define USER_CARD_ID 19
#define USER_TEL_LEN 12//�绰

enum user_query_gender{
	user_query_gender_male = 0,//��
	user_query_fender_female = 1 //Ů
};

struct user_query_info{
	//һ���û��Ļ�����Ϣ
	char user_name[USER_NAME_LEN];//�û���
	char user_card_id[USER_CARD_ID];//���֤id
	user_query_gender user_query;//�û��Ա�
	int user_age;//�û�����
	char user_tel[USER_TEL_LEN];//�û��绰��ϵ��ʽ
	char user_addr[REG_MAX_ADDR];//�û���ַ
};

struct user_query_array_info{
	int user_num;
	user_query_info* user_array;
};

