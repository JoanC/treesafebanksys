#pragma once

#include "database_mgr.h"//���ݿ⴦��
#include "sys_error_compute.h"//������

//���ԱID����
#define RESEARCH_COMMIT_RESEARCHER_ID_LEN 19
//���Ա��������
#define RESEARCH_COMMIT_RESEARCHER_NAME_LEN 51
//���Ա�ĵ绰��ϵ��ʽ
#define RESEARCH_COMMIT_RESEARCHER_TEL_LEN 19

//���ύ����������ID
#define RESEARCH_COMMIT_APPLY_ID_LEN 19



//ģ��9
//��˽���ύģ��


//�ύ��˱�������Ա������Ϣ
//������Щ�����Ա��д��
//���������Աid������ҳ���Զ����ɵ�

struct research_commit_input_info{
	//���Ա�������Ϣ
	char researcher_id[RESEARCH_COMMIT_RESEARCHER_ID_LEN];
	char researcher_name[RESEARCH_COMMIT_RESEARCHER_NAME_LEN];
	char research_tel[RESEARCH_COMMIT_RESEARCHER_TEL_LEN];
	//���ύ������������Ϣ
	char research_apply_id[RESEARCH_COMMIT_APPLY_ID_LEN];
	//����bool����ö�ٱ���
	//...
	//�д����ȷ��

};

//
