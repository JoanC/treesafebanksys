//ģ��6 -- ��ͨ�û�ע��ע��
/******************************************/
//��ģ�����������ͨ���û������ʽ
//����Ա����������������ڹ���Ա��(�����Ա)ģ�鹦����ʵ��
#pragma once

#include "sys_error_compute.h"
#include "database_mgr.h"
#include "sys_connc_banksys_db.h"
#include "sys_error_compute.h"//������

#define REG_MAX_USER_NAME idLen
#define REG_MAX_USER_PWD pwdLen
#define REG_MAX_USER_BANK_ID 19//ʮ��λ���֤��,��'\0'19
#define REG_MAX_ADDR 64//��ϵ��ַ
#define REG_MAX_OTHER_STR_LEN 256

typedef char REG_USER_NAME;
typedef char REG_USER_PWD;
typedef char REG_USER_ID;
enum REG_GENDER_TYPE{male , female};


struct reg_basic_info{
	//��½�û���
	REG_USER_ID reg_name[REG_MAX_USER_NAME];
	//�û�����
	REG_USER_PWD reg_pwd[REG_MAX_USER_PWD];
	//���֤��,18λ
	REG_USER_ID reg_id[REG_MAX_USER_BANK_ID];
	//�û���ʵ����
	char reg_basic_user_name[REG_MAX_USER_NAME];
	//�Ա�
	REG_GENDER_TYPE reg_gender;
	//����
	int reg_age;
	//��ͥסַ
	char reg_home_addr[REG_MAX_ADDR];
};

struct reg_input_info{
	//�û�ע��������������Ϣ
	//���������Ϣ
	reg_basic_info basic_info;
	//�����ĸ�����Ϣ
	char email_addr[REG_MAX_ADDR];
	//����������֤�Ƿ���ȷ
	bool is_pwd_vry_crr;
};

struct reg_cust_info{
	REG_USER_ID cust_id[REG_MAX_USER_BANK_ID];//���id
	//...������Ϣ
};

//�ۺ���Ϣ,��Ҫ���͸�����˵���Ϣ
struct reg_info{
	//�û���
	//�����ڽ��������"XXX,����!ע��ɹ�"
	REG_USER_ID user_name[REG_MAX_USER_NAME];
	sys_err reg_err;//ע������г��ֵĴ�����쳣
};

//ע����̵�����ģ��
struct reg_modle{
	bool reg_succ;//ע����̳ɹ�
	int command_len;//������Ϣ�ĳ���
	char command_info[REG_MAX_OTHER_STR_LEN];//�����
	/*����������*/
	reg_input_info input_info;//�û��������Ϣ
	reg_basic_info db_query_from_bank;//������ϵͳ�����Ļ�����Ϣ
	reg_info info;//ע������е�����,Ҳ�ǽ������
};

/********************************************************/
//ģ��6.1
//Jiraiya���
//��¼��Ϣ�ĳ�ʼ��
//���¹�����Jiraiya���

//��ʼ��ע������ģ��
reg_modle* reg_init();
//�ͷ�����ģ��
void reg_release(reg_modle* _release);

//��ʼ��������Ϣ
void reg_init_reg_basic_info(reg_basic_info* _init);

//��ʼ���û���Ҫ�������Ϣ
void reg_init_reg_input_info(reg_input_info* _init);

//��ʼ���û���Ϣ
void reg_init_reg_cust_info(reg_cust_info* _init);

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
//��Jiraiya���
//���ݶԱ�,�Ա��û�����Ļ�����Ϣ�ʹ����е�������Ϣ���б�Ҫ�ıȶ�
//�ȶ�����Ҫ����,������ϵ�绰���Բ�����֤
//Ŀǰ�ȱȶ��û���ʵ����,�Ա�,����,��ͥסַ
bool reg_info_cmp(reg_basic_info* _input,reg_basic_info* _bank_data);

/********************************************************/
//6.5
//sunni���
//��ע����û����뵽���ݿ���
//�����û���Ϣ,����Ӧ�ĵ�½�õ��û��ź�����,�Լ����֤��
//�ڲ���ת������������db��
//ֻҪ���������Ϣ����
void reg_add_user_to_db(reg_basic_info* _info);

/********************************************************/
//6.5
//��Jiraiya���
//ע�������,�������Ϣת���ɽ�Ҫ���͵���Ϣ
void reg_generate_result(reg_info* _info , char* _rlt);
