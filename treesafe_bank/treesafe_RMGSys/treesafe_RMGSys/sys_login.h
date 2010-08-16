#pragma once

#include "error_type.h"

#define DEFAULT_INFO_LEN 64

typedef char* USER_NAME ;//�û���
typedef char*  USER_PWD;//����
//typedef  char* VRY_CODE;//��֤��
typedef bool* VRY_RESULT;//��֤��ļ����


//��½ϵͳ

//��½Ȩ��
//����Ա,һ���û�...
enum login_competence{
	compe_admin,
	compe_user
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
	USER_PWD input_user_pwd;//�û�����
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
	char* user_name;//�û���
	//...����
	bool is_employee;//��½���û��Ƿ��ǹ�Ա
	int cust_id;//������û�,��ô�û�id
	int employee_id;//����ǹ�Ա,��ô��Ա��id

	//������Ϣ
	//????�����Ƿ�ϲ���һ���ṹ��??//
	login_err_type err;
	char* err_info;//������Ϣ
};

//����ģ��
struct login_modle{
	bool login_succ;
	int command_arg_len;//�������ݵĳ���
	char* command_info;//ָ�����Ϣ
	login_check_info check_info;
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

void login_db_query(USER_NAME _user , login_user_info* _info , bool* _rlt);

/******************************************************/
//������Jiraiya���
//ģ��3.4
//0.4 -- ��֤
//����0.2��������Ϣ��0.3�Ĳ�ѯ��Ϣ,������֤
//�ɹ�˵����½�ɹ�,����ʧ��,���ʧ��
bool login_check_name(USER_NAME _db);
bool login_check_pwd(USER_PWD _input , USER_PWD _db);
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
void login_db_err_query(login_err_type _err , char* _err_info);

/******************************************************/
//������Jiraiya���
//ģ��3.7
//0.8�������Ϣ���͸����͹��ɲ�
void login_summer_send_info(login_info* _info);

/******************************************************/
//��½ģ���������
//Jiraiya����
void login_frame(char* _command , int _arg_len);