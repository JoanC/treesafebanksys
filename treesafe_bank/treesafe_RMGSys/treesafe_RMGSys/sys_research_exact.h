#pragma once

#include "database_mgr.h"//���ݿ⴦������
#include "sys_error_compute.h"//������ģ��

//ģ��8
//�����Ϣ����ȡģ��
//��������Ա�������,�򷵻�����������Ϣ��״̬
//����:��һ�����Ա�ύһ����Ҫ��˵�����

#define RESEARCHER_ID_LEN 19
#define RESEARCH_APPLY_ID 19

//������Ϣ
//����ҳ������һ�����Ա��id
struct research_exact_input_info{
	char investigator_id[RESEARCHER_ID_LEN];
};

//�������Ϊ������͵���ҳ��
struct research_exact_info{
	//������
	char research_apply_id[RESEARCH_APPLY_ID];
	//��������Ϣ
	//...
	//��ǰ������
	//...
	//ע����Ϣ
	//...
};

/********************************************/
//8.1
//��ʼ�����ͷ�ģ��8�ĸ����ṹ��


/********************************************/
//ģ��8.2
//��������
void research_exact_copy_cmd(const char* _cmd , char* _dest , int _cmd_len);


