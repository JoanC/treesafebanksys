#include "sys_apply_info.h"
#include "database_mgr.h"//���ݿ����
#include "sys_error_compute.h"//������Ϣ

//ģ��27
//���һ���û��Ƿ���������Ϣ
#define USER_HAS_APP_ID_LEN 19

struct user_has_app_input{
	char card_id[USER_HAS_APP_ID_LEN];
};

//27.1
//��ʼ��ϵͳ

void init_