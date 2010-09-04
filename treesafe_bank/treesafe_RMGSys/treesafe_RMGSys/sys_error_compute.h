#pragma once

#include "string.h"
//ģ��4 ȫ�ִ�����
//��ģ����sunni���

//��ģ��߶ȶ����������ݿ��У�ͨ����������ȥ����������Ϣ
//������Ϣ���������ΪMAX_ERR_INFO

#define MAX_ERR_INFO 128 //��� ���ٶ�

//ģ��4.1
//�������ͱ���
//�����������Ŀ�Ŀ������ϵ�����
//�������� err_ģ������_����ԭ��
//һ��ö������
enum sys_err_type{
	err_no_err = 0,//�޴���
	err_unknow = 9,//���ɽ�������
	//��½�����н��������Ĵ���
	err_login_user_or_pwd_err = 1,//�û��������벻��
	err_login_vry_uncmp = 2,//��֤�벻ƥ��
	err_login_db_err = 3,//���ݿ���ʴ���
	//ע������л������Ĵ���
	err_reg_vry_pwd_err = 4,//����ȷ�ϳ���
	err_reg_info_check_wrong = 5,//�������е����ݱȶ�ʱ����
	err_reg_info_db_wrong=6,//���ݿ����ʧ��
	//�����봦��ʱ�������Ĵ���
	err_apply_info_chech_wrong = 7,//������Ϣ�˶��д�
	err_apply_info_no_user = 8//�޴��û�
};

//������Ϣ�ṹ��
struct sys_err{
	sys_err_type type;
	char info[MAX_ERR_INFO];
};



//������Ϣ�ṹ��ĳ�ʼ������
void init_sys_err(sys_err* _err);




//ģ��4.2
//������Ϣ����
//���ݴ�������,���Ҵ�����Ϣ
void sys_err_search(sys_err* _err);