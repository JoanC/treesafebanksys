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
	bool isSuccess;//�Ƿ�ɹ�
	//�û�Ȩ��
	login_competence compe;
	//�û���
	char* user_name;//�û���
	char* user_pwd;//�û�����
	char* verify_code;//��֤��

	//��½��Ϣ
	err_info err;//������Ϣ
	void* log_login;//��־��Ϣ
	void* report_login;//������Ϣ
	//...����
	bool is_employee;//��½���û��Ƿ��ǹ�Ա
	int cust_id;//������û�,��ô�û�id
	int employee_id;//����ǹ�Ա,��ô��Ա��id
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
void login_check_username(char* _name , err_info* _err , bool* _rlt);

//����û�����
//�������洢��err��
void login_check_pwd(char* _name , char* _pwd , err_info* _err , bool* _rlt);

//�����֤��
//�������洢��err��
void login_check_verify(char* _input , char* _verify , err_info* _err , bool* _rlt);

//��⺯��
//�����������̺���
//login_info �� input_info�����һ��
void login_check_info(login_info* _info , login_input_info* _input);

//�����Ϣ
//ǰ������û�����,������ȷ,����֤��ͨ��
void login_auto_add(login_info* _info,login_input_info* _input);

//��½�ɹ���,��תUI
//�����û�Ȩ�޵Ĳ�ͬ,���в�ͬ�Ľ�������
void login_jump(login_info* _info,void* _new_ui = 0);

//����½����
void login_frame(login_info* _info,login_input_info* _input);

//��½�еĴ�������
//������һ��Ҫ��ϸ
void login_err_occour(err_info* _err);

//�������Ӻ���
//��_err_occour�����еķ�֧С����
void login_err_user_unexsit();//�û�������

void login_err_pwd_unmatch();//�û��������

void login_err_verify_wrong();//��֤���������

