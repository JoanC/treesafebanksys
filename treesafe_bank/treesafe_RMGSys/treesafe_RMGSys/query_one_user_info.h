#include "query_user_info_array.h"
#include "sys_error_compute.h"
#include "database_mgr.h"

/******************************************/
//ģ��22
//��һ���û�����Ϣ���в�ѯ
#define ONE_USER_CARD_ID_LEN 19
struct query_user_one_info_input{
	char user_id[ONE_USER_CARD_ID_LEN];//�û���֤������
};


struct query_user_one_info_info{
	user_query_info user_info;
	sys_err err_info;//������Ϣ
};

struct query_user_one_info_modle{
	query_user_one_info_input* input;
	query_user_one_info_info rlt_info;
};

//22.2
//��ʼ�����ͷ�ģ��ģ��

void init_query_user_one_info_input(query_user_one_info_input* _input);

void init_query_user_one_info_info(query_user_one_info_info* _init);

