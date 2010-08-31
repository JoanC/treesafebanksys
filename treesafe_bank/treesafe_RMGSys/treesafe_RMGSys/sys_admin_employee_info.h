#pragma once

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <string.h>


#define EMPLOYEE_ID_LEN 19
#define EMPLOYEE_NAME_LEN 51
#define EMPLOYEE_TEL_LEN 11
#define EMPLOYEE_ADDR_LEN 51
#define EMPLOYEE_PWD_LEN 18

#define EMPLOYEE_WORK_ID_LEN 8 //��Ա���� 
#define EMPLOYEE_EMAIL_ADDR_LEN 51 //�����ʼ���ַ�ĳ���

enum admin_mgr_gender{employee_male,employee_female};

//��Ա������
//���Ա���߲���Ա
//����Ա��Ȩ��������ֹ�Ա
enum admin_employee_type{
	employ_type_operator = 0 ,//����Ա
	employ_type_investigator = 1 ,//���(����)Ա
};

//��Ա��Ϣ
struct admin_employee_info{
	char employee_id[EMPLOYEE_ID_LEN];//��Ա�����֤��
	char employee_work_id[EMPLOYEE_WORK_ID_LEN];//��Ա����
	char employee_name[EMPLOYEE_NAME_LEN];//��Ա������;
	char employee_addr[EMPLOYEE_ADDR_LEN];//��Ա�ĵ�ַ
	char employee_email[EMPLOYEE_EMAIL_ADDR_LEN];//��Ա�����ʼ���ַ
	char employee_tel[EMPLOYEE_TEL_LEN];//�绰����
	admin_employee_type employee_type;//��Ա����
    admin_mgr_gender employee_gender;//��Ա�Ա�
	int employee_age;//��Ա������
};

//��ʼ������
void init_admin_employee_info(admin_employee_info* _init);
