#include "stdafx.h"
#include "sys_research_exact.h"

extern _ConnectionPtr* database_connection;

//ģ��8��ʵ��


//8.1
void research_exact_init_research_exact_input_info(research_exact_input_info* _init){
	strcpy(_init->investigator_id,"");
}

void research_exact_init_research_exact_investigator_prop(research_exact_investigator_prop* _init){
	_init->statu = false;
	strcpy(_init->research_apply_id,"");
}

void research_exact_init_research_exact_info(research_exact_info* _init){
	//��ʼ��������Ϣ
	init_sys_err(&_init->err_info);
	strcpy(_init->research_apply_id,"");
}

research_exact_modle* research_exact_init_research_exact_modle(){
	//�����ڴ�
	research_exact_modle* _new_modle
		= (research_exact_modle*)malloc(sizeof(research_exact_modle));
	//��ʼ��������Ϣ
	research_exact_init_research_exact_input_info(&_new_modle->input_info);
	//��ʼ�����Ա��Ϣ
	research_exact_init_research_exact_investigator_prop(&_new_modle->investigator_prop);
	//��ʼ�������¼��Ϣ
	research_exact_init_research_exact_info(&_new_modle->rlt_info);
	//��������½���ָ��
	return _new_modle;
}

void release_research_exact_modle(research_exact_modle* _release){
	free(_release);
}


//8.2
void research_exact_copy_cmd(const char* _cmd , char* _dest , int _cmd_len){
	//����������Ϣ
	memcpy(_dest,_cmd,_cmd_len);
}

research_exact_input_info* reasearch_exact_convert_cmd(char* _info){
	//ת������
	return (research_exact_input_info*)_info;
}

research_exact_input_info* research_exact_get_cmd(const char* _cmd , int _cmd_len){
	//Ϊ�µ�������Ϣ�����ڴ�
	char* _cmd_info = 
		(char*)malloc(_cmd_len);
	//���ȸ�������
	research_exact_copy_cmd(_cmd,_cmd_info,_cmd_len);
	//ת��ָ���ʽ
	return reasearch_exact_convert_cmd(_cmd_info);
}

//8.3
//...
//�д�sunni���


//8.4
//...
//�д�sunni���

//8.5
//...
//�д�sunni���
//...


//8.6
void research_exact_convert_rlt(research_exact_info* _info
	,char* _rlt , int* _len){
	//ȷ������
	*_len = sizeof(research_exact_info);
	//����
	memcpy(_rlt,_info,*_len);
}


//ģ��8������ʽ
void research_exact_frame(const char* _cmd
	,int _cmd_len,char* _rlt , int* _rlt_len){
		//8.1
		//��ʼ��ģ��
		research_exact_modle* _research_exact_frame
			= research_exact_init_research_exact_modle();
		//8.2
		//��������Ϣת��Ϊ�û����������
		_research_exact_frame->input_info
			= *research_exact_get_cmd(_cmd,_cmd_len);

		//8.3
		//...

		if(_research_exact_frame->investigator_prop.statu
			== true){
				//������Ա���ڿ���״̬
				//���ȡһ������,���ı�״̬
		//8.4
		//...

		//8.5
		//...
		}
		//8.6
		//�����ת����_rlt��,׼������
		research_exact_convert_rlt(&_research_exact_frame->rlt_info
			,_rlt,_rlt_len);
		//8.7
		//�ͷ���˳�ȡģ��
		release_research_exact_modle(_research_exact_frame);
}