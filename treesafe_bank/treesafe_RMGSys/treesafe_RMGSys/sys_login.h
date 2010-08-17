#pragma once

#include "sys_error_compute.h"
#include "database_mgr.h"
#define DEFAULT_INFO_LEN 64

#define MAX_USER_NAME_LEN 32
#define MAX_USER_PWD_LEN 16
#define MAX_OTHER_STR_LEN 128

typedef char  USER_NAME ;//�û���
typedef char  USER_PWD;//����
//typedef  char* VRY_CODE;//��֤��
typedef bool VRY_RESULT;//��֤��ļ����


//��½ϵͳ

//��½Ȩ��
//����Ա,һ���û�...
enum login_competence{
	compe_admin,
	compe_user
	//...other competence
};

struct login_user_info{
	USER_NAME input_user_name[MAX_USER_NAME_LEN];//�û���
	USER_PWD input_user_pwd[MAX_USER_PWD_LEN];//�û�����
};


struct login_check_info{
	//�û���UI�������Ϣ
	login_user_info user_info;//�û���������

	//???�Ƿ�Ҫ�ڷ������м����֤��???////
	//VRY_CODE input_verify_code;//��֤��
	//VRY_CODE verify_code;//��ȷ��(UI)���ɵ���֤��
	//������õĻ���������Ҫ��һ�������
	bool vry_is_correct;//��֤��ļ�����
};

//һ�ε�½���̵���Ϣ����
struct login_info{
	//�û�Ȩ��
	login_competence compe;
	//�û���
	char user_name[MAX_USER_NAME_LEN];//�û���
	//...����
	bool is_employee;//��½���û��Ƿ��ǹ�Ա
	int cust_id;//������û�,��ô�û�id
	int employee_id;//����ǹ�Ա,��ô��Ա��id

	//������Ϣ
	sys_err login_err;//������Ϣ
};

//����ģ��
struct login_modle{
	bool login_succ;
	int command_arg_len;//�������ݵĳ���
	char command_info[MAX_OTHER_STR_LEN];//ָ�����Ϣ
	login_check_info check_info;
	login_user_info db_query;//���ݿ���3.3�еĲ���ģ��
	login_info rlt_info;
};


//ģ��3--��½
/*********************************************************/
//ģ�� 3.1 
//0.1 -- ģ���ʼ�����ͷ�
//���²�����Jiraiya���
login_modle* login_init();
void login_release(login_modle* _release);

//�����ṹ��ĳ�ʼ������
void login_init_login_user_info(login_user_info* _init);
void login_init_login_check_info(login_check_info* _init);
void login_init_login_info(login_info* _init);

/********************************************************/
//������Jiraiya���
//ģ��3.2
//0.2 -- ������Ϣ����,��ģ��1����Ϣ�����sunni�ɼ�����Ϣ
//��UI�Ľ�����
//����������Ϣ
//�������Ͻ�����Ϣ
/*

void login_get_username(USER_NAME _name , char* _info);//��ui�ϻ�ȡ�û���
void login_get_pwd(USER_PWD _pwd , char* _info);//��ȡ����
//void login_get_input_verify(VRY_CODE _vry , char* _info);//��ȡ�������֤��
//void login_get_verify(VRY_CODE _vry , char* _info);//��ȡ��ȷ����֤��
void login_get_vry_result(VRY_RESULT _vry_rlt);//�õ���֤��Ľ��
*/

//����������,��ʵ����һ��copy,��һ�����ƺ�����ת���Ĺ���
void login_get_copy_data(char* _info , char* _copy_data , int _len);
login_check_info* login_get_convert(char* _info);

login_check_info* login_get_info(char* _data , int _data_len);//��ȡ����֤����Ϣ
/*******************************************************/
//������sunni���
//ģ��3.3
//0.3 -- ��ѯ
//////////////////////////////
//����0.2��username,���в�ѯ(��Ҫȥ�Ƚ�ֵ),������ѯ����洢��һ���ṹ��login_user_info��
//���û�в�ѯ�����û�,���_rlt����false

//�����ѯ�������ӹ���,��sunni�������

void login_db_query(_ConnectionPtr *_pConn,USER_NAME *_user , login_user_info* _info , bool* _rlt);

/******************************************************/
//������Jiraiya���
//ģ��3.4
//0.4 -- ��֤
//����0.2��������Ϣ��0.3�Ĳ�ѯ��Ϣ,������֤
//�ɹ�˵����½�ɹ�,����ʧ��,���ʧ��
bool login_check_name(USER_NAME* _db);
bool login_check_pwd(USER_PWD* _input , USER_PWD* _db);
//void login_check_vry(VRY_CODE _input , VRY_CODE _ui , login_err_type _type);
bool login_check(login_check_info* _input , login_user_info* _db);
/******************************************************/
//������sunni���
//ģ��3.5
//0.5 -- �����½�ɹ�,������ȷ���û�������,���и߼���Ϣ��ѯ����,
//������½��Ϣ����login_info
//����ɹ�,����и�ģ��Ĵ���

//�����login_info��Ҫ��sunni��ô����
void login_db_summery(login_user_info* _user_info , login_info* _info);

/******************************************************/
//������sunni���
//ģ��3.6
//0.6 -- �����½ʧ��
//���ݴ��������д�����Ϣ�Ĳ�ѯ
//void login_db_err_query(login_err_type _err , char* _err_info);

/******************************************************/
//������Jiraiya���
//ģ��3.7
//0.7�������Ϣ���͸����͹��ɲ�
void login_summer_send_info(login_info* _info);

/******************************************************/
//������Jiraiya���
//ģ��3.8
//0.8���е�½�����еĴ�����

void login_err_mgr(sys_err_type _err_type,login_modle* _mld);

/******************************************************/
//������Jiraiya���
//ģ��3.9
//0.9�����ս�����д���
void login_convert_rlt(login_info* _info , char* _rlt);

/******************************************************/
//��½ģ���������
//Jiraiya����
void login_frame(char* _command , int _arg_len , char* _rlt);