#pragma once

#include "database_mgr.h"//���ݿ⴦������
#include "sys_error_compute.h"//������ģ��

//ģ��8
//�����Ϣ����ȡģ��
//��������Ա�������,�򷵻�����������Ϣ��״̬
//����:��һ�����Ա�ύһ����Ҫ��˵�����

#define RESEARCHER_ID_LEN 19

//������Ϣ
//����ҳ������һ�����Ա��id
struct research_exact_input_info{
	char investigator_id[RESEARCHER_ID_LEN];
};

/********************************************/
//ģ��8.1
//��������


