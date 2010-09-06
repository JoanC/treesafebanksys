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

void is_user_has_score_copy_cmd(const char* _cmd,char* _dest,int _cmd_len);

is_user_has_score_input* is_user_has_score_convert_cmd(char* _info);

is_user_has_score_input* is_user_has_score_get_cmd(const char* _cmd,int _cmd_len);


//ģ��28.3
//sunni���
void is_user_has_score_get_data(char* _id , bool* _rlt);


//ģ��28.4
//�������ת��
void is_user_has_score_convert_rlt(is_user_has_score_info* _info
	,char* _rlt,int* _rlt_len);

//ģ��28����ʽ
void is_user_has_score_frame(const char* _cmd , int _cmd_len
	,char* _rlt,int* _rlt_len);


