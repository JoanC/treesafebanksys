#include "error_type.h"

//��½ϵͳ

//��½Ȩ��
//����Ա,һ���û�...
enum login_competence{
	admin,
	user
	//...other competence
};

struct login_input_info{
	//�û���UI�������Ϣ
	char* input_user_name;//�û���
	char* input_user_pwd;//�û�����
	char* input_verify_code;//��֤��
	char* verify_code;//��ȷ��(UI)���ɵ���֤��
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

//��UI��ȡ��������Ϣ
//��UI�Ľ�����
char* login_ui_get_username();//��ui�ϻ�ȡ�û���
char* login_ui_get_pwd();//��ȡ����
char* login_ui_get_input_verify();//��ȡ�������֤��
char* login_ui_get_verify();//��ȡ��ȷ����֤��
//����������Ϣ
//����_input�ṹ����
void login_get_input_info(login_input_info* _input);

//����û���
//�������洢��err��
void login_check_username(char* _name , err_login* _err);

//����û�����
//�������洢��err��
void login_check_pwd(char* _name , char* _pwd , err_login* _err);

//�����֤��
//�������洢��err��
void login_check_verify(char* _input , char* _vertfy , err_login* _err);

//��⺯��
//�����������̺���
//login_info �� input_info�����һ��
void login_check_info(login_info* _info , login_input_info* _input);

//���������Ϣ
//����û�����,������ȷ,����֤��ͨ��
//�������������û��йص���Ϣ
void login_auto_add(login_info* _info);

//������
void login_err_occour(login_info* _info);

//��½�ɹ���,��תUI
//�����û�Ȩ�޵Ĳ�ͬ,���в�ͬ�Ľ�������
void login_jump(login_info* _info,void* _new_ui);

//����½����
void login_frame(login_info* _info);


