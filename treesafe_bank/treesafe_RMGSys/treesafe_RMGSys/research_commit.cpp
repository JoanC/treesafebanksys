#include "stdafx.h"
#include "research_commit.h"

//ģ��9 -- �����Ϣ����ύģ���ʵ�ִ���

//9.1 ��ʼ�����ͷ�ģ��

void research_commit_init_research_commit_input_info(research_commit_input_info* _init){
	//��ʼ������ύ��������Ϣ
	//���Ա��id,��ʼΪ��
	strcpy(_init->researcher_id,"");
	//���ύ�����������,��ʼΪ��
	strcpy(_init->research_apply_id,"");

	
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
	_init->is_commit_succ = true;
}

research_commit_modle* research_commit_init_research_commoit_modle(){
	//��ʼ��(������)��ģ��
	//�����ڴ�
	research_commit_modle* _new_modle = 
		(research_commit_modle*)malloc(sizeof(research_commit_modle));
	//��ʼ���ڲ�ϸ��
	//��ʼ��������Ϣ
	research_commit_init_research_commit_input_info(&_new_modle->input_info);
	//��ʼ�������Ϣ
	research_commit_init_research_commit_info(&_new_modle->rlt_info);
	//����ָ��ֵ
	return _new_modle;
}

void release_research_commit_modle(research_commit_modle* _release){
	//�ͷ�ģ��
	free(_release);
}

//9.2
//...
research_commit_input_info* research_commit_get_cmd(const char* _cmd
	,int _cmd_len){
	//Ϊ�µ���Ϣ�����ڴ�
		char* _info = (char*)malloc(_cmd_len);
		research_commit_copy_cmd(_cmd,_info,_cmd_len);
		return research_commit_convert_input(_info);
}

void research_commit_copy_cmd(const char* _cmd,char* _dest,int _cmd_len){
	//����������Ϣ
	memcpy(_dest,_cmd,_cmd_len);
}

research_commit_input_info* research_commit_convert_input(char* _info){
	//���ַ�������ǿ�����͵�ת��(�����л�)�Ĺ���
	return (research_commit_input_info*)_info;
}


//9.3
//...��sunni���


//9.4
//...��sunni���


//9.5
//�����Ϣ��ת��
void research_commit_convert_rlt(research_commit_info* _info
	,char* _rlt , int* _rlt_len){
		memcpy(_rlt,_info,sizeof(research_commit_info));
		*_rlt_len = sizeof(research_commit_info);
}

//ģ��9������ʽ
void research_commit_frame(const char* _cmd , int _cmd_len
	,char* _rlt , int* _rlt_len){
		//9.1
		//��ʼ��ģ��
		research_commit_modle* _research_commit_frame
			= (research_commit_modle*)malloc(sizeof(research_commit_modle));
		//9.2
		//����ָ��,��ȡ������Ϣ
		_research_commit_frame->input_info
			= *research_commit_get_cmd(_cmd,_cmd_len);
		//9.3
		//...

		//9.4
		//...

		//9.5
		//���ɽ����Ϣ
		research_commit_convert_rlt(&_research_commit_frame->rlt_info
			,_rlt,_rlt_len);
		
		//�ͷ�ģ��
		release_research_commit_modle(_research_commit_frame);
}