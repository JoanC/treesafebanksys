#include "stdafx.h"
#include "research_commit.h"

//ģ��9 -- �����Ϣ����ύģ���ʵ�ִ���

//9.1 ��ʼ�����ͷ�ģ��

void research_commit_init_research_commit_input_info(research_commit_input_info* _init){
	//��ʼ������ύ��������Ϣ
	//���Ա��id,��ʼΪ��
	strcpy(_init->researcher_id,"");
	//���Ա������,��ʼΪ��
	strcpy(_init->researcher_name,"");
	//���ύ�����������,��ʼΪ��
	strcpy(_init->research_apply_id,"");
	//���Ա����ϵ�绰��,��ʼΪ��
	strcpy(_init->research_tel,"");
	
	//������Ϣ����˽��(true/false)
	//ϸ�ڴ���

	//��˵����ս��,��ʼֵΪfalse
	_init->is_research_approved = false;
}

void research_commit_init_research_commit_info(research_commit_info* _init){
	//��ʼ�������¼��Ϣ
	//��ʼ��������Ϣ
	init_sys_err(&_init->err_info);
	//�ύ�Ƿ�ɹ�,��ʼΪtrue,(�м�������,���Ϊfalse)...
	_init->is_commit_succ
}