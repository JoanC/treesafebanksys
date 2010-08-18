//ģ��6 -- ��ͨ�û�ע��ע��
/******************************************/
//��ģ�����������ͨ���û������ʽ
//����Ա����������������ڹ���Ա��(�����Ա)ģ�鹦����ʵ��
#include "sys_error_compute.h"
#include "database_mgr.h"
#include "treesate_cClient.h"//��Ҫ��������ϵͳ���н��н���
#include "sys_connc_banksys_db.h"

#define REG_MAX_USER_NAME idLen
#define REG_MAX_USER_PWD pwdLen
#define REG_MAX_USER_BANK_ID 18//ʮ��λ���֤��
#define REG_MAX_EMAIL_ADDR 32//��ϵ�����ַ
#define REG_MAX_OTHER_STR_LEN 128

typedef char REG_USER_NAME;
typedef char REG_USER_PWD;
typedef char REG_USER_ID;

struct reg_input_info{
	//�û�ע��������������Ϣ
	//�����½�û���
	REG_USER_NAME reg_name[REG_MAX_USER_NAME];
	//������û�����
	REG_USER_PWD reg_pwd[REG_MAX_USER_PWD];
	//����������֤�Ƿ���ȷ
	bool is_pwd_vry_crr;
	//���֤��,18λ
	REG_USER_ID reg_id[REG_MAX_USER_BANK_ID];
};

struct reg_cust_info{
	REG_USER_ID cust_id[REG_MAX_USER_BANK_ID];//���id

};

/********************************************************/
//ģ��6.1
//Jiraiya���
//��¼��Ϣ�ĳ�ʼ��
//���¹�����Jiraiya���

//��ʼ���û���Ҫ�������Ϣ
void reg_init_reg_input_info(reg_input_info* _info);

/*******************************************************/
//ģ��6.2
//Jiraiya���
//���û�UI����н���
//����һ������ת���Ĺ���,��cmd����Ϣת����input_info

/*6.2�ӹ���*/
//������Ϣ,����ָ���ֱ�ӸĶ�
void reg_copy_cmd(char* _dst,char* _cmd_info,int _len);
//����ת��,����һ��reg_input_info����,�������ƺ����Ϣת��
void reg_convert_cmd(char* _cmd);
//ģ��3.3����ʽ
void reg_get_info(char* _cmd , int _len);//�����������Ϣ����Ϣ����

/******************************************************/
//6.3
//Эͬ���
//���û���������֤idͨ��net(client)�˷��͸�banksys,�����жβ�ѯ�Ƿ��д��˵���Ϣ
//���û��,����һ��������
//�����,����λ�û��������Ϣ������ϵͳ�������,�������reg_cust_info��

//����ducky�Ľ��ܺ�����δд��,�������￴��,�Ҿ��û������һ��ģ��,��������̷�
//��һ������ʽ��,��sys_connc_bank
void reg_query_user(reg_cust_info* _cust_info);

//����һ��������Ϣ,_req
void reg_query_user_generate_req(bankDB_request_info* _req);
//��ѯ���,�����ת��ΪbankDB_result_cust_info
void reg_query_user_get_rlt(bankDB_result_cust_info* _db_rlt);
//����_db_rlt,��ȡ�����Ϣ,��䵽reg_cust_info��
void reg_query_user_convert_rlt(bankDB_result_cust_info* _db_rlt,reg_cust_info* _cust_info);

/********************************************************/
//6.4
//sunni���
//��ע����û����뵽���ݿ���
void reg_add_user_to_db();
