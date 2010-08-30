#pragma once
#include "sys_admin_employee_info.h" 
//���ݿ��ܹ�����
//Ϊ����ģ���ṩ�ӿ�
//�Ա�(table)Ϊ�������struct�Ľṹ
#include "sys_db_struct.h"
#include<stdio.h>
#include<conio.h>
#include "sys_error_compute.h"//������
#import "C:\\Program Files\\Common Files\\System\\ado\\msado25.tlb" no_namespace rename("EOF","rsEOF")

#define PWD_LEN 16
#define REG_MAX_USER_NAME 19
#define REG_MAX_REAL_USER_NAME 51
#define REG_MAX_USER_PWD 16
#define REG_MAX_USER_BANK_ID 19//ʮ��λ���֤��,��'\0'19
#define REG_MAX_ADDR 64//��ϵ��ַ
#define REG_MAX_OTHER_STR_LEN 256
#define REG_MAX_PHONE_NUM_LEN 12

typedef char REG_USER_NAME;
typedef char REG_USER_PWD;
typedef char REG_USER_ID;
enum REG_GENDER_TYPE{reg_info_male , reg_info_female};


struct reg_basic_info{
	//�Ա�
	REG_GENDER_TYPE reg_gender;
	//����
	int reg_age;
	//��ͥסַ
	//���֤��,18λ
	REG_USER_ID reg_id[REG_MAX_USER_BANK_ID];
	//REG_USER_ID reg_name[REG_MAX_USER_NAME];
	//�û�����
	REG_USER_PWD reg_pwd[REG_MAX_USER_PWD];
	//�û���ʵ����
	char reg_basic_user_name[REG_MAX_REAL_USER_NAME];
	char reg_phone_num[REG_MAX_PHONE_NUM_LEN] ;
	char reg_home_addr[REG_MAX_ADDR];
};

struct reg_input_info{
	//�û�ע��������������Ϣ
    //�����ĸ�����Ϣ
	char email_addr[REG_MAX_ADDR];
	//���������Ϣ
	reg_basic_info basic_info;
	//����������֤�Ƿ���ȷ
	bool is_pwd_vry_crr;
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
	/*����������*/
	reg_input_info input_info;//�û��������Ϣ
	reg_basic_info db_query_from_bank;//������ϵͳ�����Ļ�����Ϣ
	reg_info info;//ע������е�����,Ҳ�ǽ������
};

const char CSFileName[] = "ConnStrs.txt" ;
const size_t connStrLen = 241  ; // max 3 lines
char *	GetIP() ;
bool GetConnStr(int index,char *outcome) ;
//index means in which line of the connStr.txt.
bool ConnectDB(_ConnectionPtr *pConn) ;

void DisconnectDB(_ConnectionPtr *pConn) ;

bool	Password_inquiry(_ConnectionPtr *_pConn,char *user_name , char *pwd_rlt) ;

void	Summery_inquiry(_ConnectionPtr *_pConn,char *user_name,sys_db_login *user_info) ;

bool	add_new_to_Tab_Login(_ConnectionPtr *_pConn,reg_input_info *_reg_info) ;

bool	add_new_to_Tab_Cust(_ConnectionPtr *_pConn,reg_input_info *_reg_info) ;

bool	add_new_employee(_ConnectionPtr *_pConn,admin_employee_info *emp_info,char *_comment) ;

bool delete_employee(_ConnectionPtr *_pConn,const char *employee_id) ;

bool	Apply_cust_info_query(_ConnectionPtr *_pConn,apply_custmor_info* _rlt) ;
	//for 7.3