#include "stdafx.h"
#include "sys_reg.h"
/*

/**********************************/
//ģ��6��ʵ���ļ�

//6.1 ��ʼ�����ͷ�

void reg_init_reg_basic_info(reg_basic_info* _init){
	//��ʼ��������Ϣ
	//��ʼ�û���
	strcpy(_init->reg_name,"");
	//��ʼ���û�����
	strcpy(_init->reg_pwd,"");
	//��ʼ�����֤��,ʮ��λ0
	strcpy(_init->reg_id,"000000000000000000");
	//��ʼ����ʵ����
	strcpy(_init->reg_basic_user_name,"");
	//��ʼ���Ա�,��
	_init->reg_gender = male;
	//��ʼ������,18
	_init->reg_age = 18;
	//��ͥסַ
	strcpy(_init->reg_home_addr,"");
}

void reg_init_reg_input_info(reg_input_info* _init){
	//��ʼ��������Ϣ
	//���û�����Ϣ��
	reg_init_reg_basic_info(&_init->basic_info);
	//��������������Ϣ,�����Ե����ʼ�Ϊ��
	strcpy(_init->email_addr,"");
	//��������˫����֤����ȷ��,��ʼ��Ϊfalse
	_init->is_pwd_vry_crr = false;
}

void reg_init_reg_cust_info(reg_cust_info* _init){
	//��ʼ���û���Ϣ
	
}
