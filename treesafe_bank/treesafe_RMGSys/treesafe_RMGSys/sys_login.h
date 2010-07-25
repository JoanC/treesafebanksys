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
void login_check_username(login_info* _login , char* _name , bool* _rlt);

//����û�����
//����洢��rlt��
//������ȷ��Ϊtrue
//����Ϊfalse
void login_check_pwd(login_info* login , char* _name , char* _pwd , bool* _rlt);

//�����֤��
void login_check_verify(login_info* _login ,char* _input , char* _vertfy , bool* _rlt);

//������
void login_err_occour(login_info* _info);

//��½�ɹ���,��ת
void login_jump(login_competence* _compe);

//����½����
void login_frame(login_info* _info);

