#pragma once

#include "sys_error_compute.h"//������

//���봦������
#define APPLY_CUST_ID_LEN 19 //���������֤�ų���
#define APPLY_CUST_NAME_LEN 51//��������

enum APPLY_GENDER_TYPE {male , female};

//����Ա�������Ϣ�ṹ
struct apply_custmor_info{
	//������(��Ա)����Ϣ
	//...�д��������ȷ��
	char* cust_id[APPLY_CUST_ID_LEN];
	//����
	char* cust_name[APPLY_CUST_NAME_LEN];
	//�Ա�
	APPLY_GENDER_TYPE cust_gender;
	//����
	int cust_age;
};

struct apply_loan_info{
	//��������������������Ϣ
	//...�д��������ȷ��
};

struct apply_input_info{
	//���������˵Ļ�����Ϣ
	apply_custmor_info input_basic_info;
	apply_loan_info input_loan_info;
};

//���봦���������Ϣ�ṹ
struct apply_info{
	//��Ҫ������������Ϣ
	//������Ϊ:
	//ֻ��Ҫ�ѶԱȻ�����Ϣʱ�Ĵ��󴫸���ǰ��ҳ��
	//���û�д���
	//���ʾ���������ڽ������...

	//�����Ǵ�����Ϣ
	sys_err errInfo;//���봦���еĴ�����Ϣ
};


