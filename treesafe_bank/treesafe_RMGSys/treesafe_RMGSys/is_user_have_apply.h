#include "sys_apply_info.h"
#include "database_mgr.h"//���ݿ����
#include "sys_error_compute.h"//������Ϣ

//ģ��27
//���һ���û��Ƿ���������Ϣ
#define USER_HAS_APP_ID_LEN 19

struct user_has_app_input{
	char card_id[USER_HAS_APP_ID_LEN];
};

struct user_has_app_info{
	bool user_has_app;//true��ʾ��,false��ʾû��
	sys_err err_info;
};

struct user_has_app_modle{
	user_has_app_input input_info;
	user_has_app_info rlt_info;
};

//27.1
//��ʼ��ϵͳ

//��ʼ��������Ϣ
void init_user_has_app_input(user_has_app_input* _init);
//��ʼ�������Ϣ
void init_user_has_app_info(user_has_app_info* _init);
//��ʼ��27����ģ��
user_has_app_modle* init_user_has_app_modle();
//�ͷ�ģ������ݽṹ
void release_user_has_app_modle(user_has_app_modle* _release);


//27.2
//ָ�����

void user_has_app_copy_cmd();