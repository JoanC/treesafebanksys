#include "error_type.h"

typedef char* USER_NAME ;//�û���
typedef char*  USER_PWD;//����
typedef  char* VRY_CODE;//��֤��

//��½ϵͳ

//��½Ȩ��
//����Ա,һ���û�...
enum login_competence{
	admin,
	user
	//...other competence
};

enum login_err_type{
	login_no_err,
	login_user_not_eixt,
	login_pwd_not_correct,
	login_vry_not_correct,
	login_server_err
};

struct login_user_info{
	USER_NAME input_user_name;//�û���
	USER_PWD input_USER_PWDd;//�û�����
};

struct login_check_info{
	//�û���UI�������Ϣ
	login_user_info user_info;//�û���������
	VRY_CODE input_verify_code;//��֤��
	VRY_CODE verify_code;//��ȷ��(UI)���ɵ���֤��
};

//һ�ε�½���̵���Ϣ����
struct login_info{
	//�û�Ȩ��
	login_competence compe;
	//�û���
	char* user_name;//�û���
	//...����
	bool is_employee;//��½���û��Ƿ��ǹ�Ա
	int cust_id;//������û�,��ô�û�id
	int employee_id;//����ǹ�Ա,��ô��Ա��id
};

struct login_send{
	bool is_suceess;
	login_info login_info;
	int err_num;//�����
	char* err_info;//������Ϣ
};

//ģ��1--��½
/*********************************************************/
//ģ�� 1.1 
//0.1 -- ������ܲ���
//���²�����ducky���
//ͨ��soket��UI��ȡ��������Ϣ
//��Ϣ��byte����ʽ����_info,�����Ϊ_rlt
void login_net_get_info(char* _info,bool* _rlt);
/********************************************************/
//������Jiraiya���
//ģ��1.2
//0.2 -- ������Ϣ����,��ģ��1����Ϣ�����sunni�ɼ�����Ϣ
//��UI�Ľ�����
//����������Ϣ
//�������Ͻ�����Ϣ
void login_get_username(USER_NAME _name , char* _info);//��ui�ϻ�ȡ�û���
void login_get_pwd(USER_PWD _pwd , char* _info);//��ȡ����
void login_get_input_verify(VRY_CODE _vry , char* _info);//��ȡ�������֤��
void login_get_verify(VRY_CODE _vry , char* _info);//��ȡ��ȷ����֤��
//����������
void login_get_info(login_check_info* _check , char* _info);//��ȡ����֤����Ϣ
/*******************************************************/
//������sunni���
//ģ��1.3
//0.3 -- ��ѯ
//////////////////////////////
//����0.2��username,���в�ѯ(��Ҫȥ�Ƚ�ֵ),������ѯ����洢��һ���ṹ��login_user_info��
//���û�в�ѯ�����û�,���_rlt����false

//�����ѯ�������ӹ���,��sunni�������

void login_db_query(USER_NAME _user , login_user_info* _info , bool* _rlt);

/******************************************************/
//������Jiraiya���
//ģ��1.4
//0.4 -- ��֤
//����0.2��������Ϣ��0.3�Ĳ�ѯ��Ϣ,������֤
//�ɹ�˵����½�ɹ�,����ʧ��,���ʧ��
bool login_check(login_check_info* _input , login_user_info* _db);
bool login_check_name(USER_NAME _input , USER_NAME _db);
bool login_check_pwd(USER_PWD _input , USER_PWD _db);
void login_check_vry(VRY_CODE _input , VRY_CODE _ui , login_err_type _type);

/******************************************************/
//������sunni���
//ģ��1.5
//0.5 -- �����½�ɹ�,������ȷ���û�������,���и߼���Ϣ��ѯ����,
//������½��Ϣ����login_info
//����ɹ�,����и�ģ��Ĵ���

//�����login_info��Ҫ��sunni��ô����
void login_db_summery(login_user_info* _user_info , login_info* _info);

/******************************************************/
//������sunni���
//ģ��1.6
//0.6 -- �����½ʧ��
//���ݴ��������д�����Ϣ�Ĳ�ѯ
void login_db_err_query(login_err_type _err , char* _err_info);

/******************************************************/
//������Jiraiya���
//���Ϸ�����Ϣ
void login__summer_send_info(login_info* _info , login_send* _send);

/******************************************************/
//����ducky���
//������Ϣ
void login_send_info(login_send* _send);