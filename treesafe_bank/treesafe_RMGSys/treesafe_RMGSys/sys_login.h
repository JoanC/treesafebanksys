#include "error_type.h"

//��½ϵͳ

//��½Ȩ��
//����Ա,һ���û�...
enum login_competence{
	admin,
	user
	//...other competence
};

struct login_info{
	//��½��Ϣ�洢
	login_competence compe;
	//�û���
	char* user_name;//�û���
	char* user_pwd;//�û�����
	char* verify_code;//��֤��
	//��½��Ϣ
	err_login err;//������Ϣ
	void* log_login;//��־��Ϣ
	void* report_login;//������Ϣ
	//...����
};

//����û���
//����洢��rlt��
//�û���������Ϊtrue
//����Ϊfalse
void login_check_username(char* _name , bool* _rlt);

