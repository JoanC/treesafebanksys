#include "database_mgr.h"
#include "sys_error_compute.h"

//ģ��28
//����һ���û��Ƿ��з�����Ϣ
//(��������ϵͳ)
#define IS_USER_HAS_SCORE_ID_LEN 19

struct is_user_has_score_input{
	char card_id[IS_USER_HAS_SCORE_ID_LEN];
};

struct is_user_has_score_info{
	bool user_has_score;//true ��ʾ������(�з���������Ϣ)
	sys_err err_info;//������Ϣ
};

struct is_user_has_score_modle{
	is_user_has_score_input input_info;
	is_user_has_score_info rlt_info;
};

//ģ��28.1
//��ʼ���ͷ�ģ��

void init_is_user_has_score_input(is_user_has_score_input* _init);

void init_is_user_has_score_info(is_user_has_score_info* _init);

is_user_has_score_modle* init_is_user_has_score_modle();

void release_is_user_has_score_modle(is_user_has_score_modle* _release);

//ģ��28.2
//��ȡָ��



