#include "stdafx.h"
#include "sys_research_exact.h"


void init_research_exact_input_info(research_exact_input_info* _init){
	//��ʼ������ṹ
	strcpy(_init->research_work_id,"");
}


void init_research_exact_info(research_exact_info* _init){
	//��ʼ������ṹ
	strcpy(_init->app_id,"");
	//��ʼ��������Ϣ
	init_sys_err(&_init->err_info);
}


research_exact_modle* init_research_exact_modle(){
	//��ʼ������ģ��
	//�ڴ����
	research_exact_modle* _new_modle
		= (research_exact_modle*)malloc(sizeof(research_exact_modle));
	//��ʼ���������ݿ�
	init_research_exact_input_info(&_new_modle->input_info);
	init_research_exact_info(&_new_modle->rlt_info);
	return _new_modle;
}

//�ͷ�ģ��
void release_research_exact_info(research_exact_info* _release){
	free(_release);
}

void research_copy_cmd_data(const char* _cmd,char* _dest,int _cmd_len){
	//��������
	memcpy(_dest,_cmd,_cmd_len);
}

research_exact_input_info* research_convert_cmd(char* _info){
	//ת��ָ��
	return (research_exact_input_info*)_info;
}


research_exact_input_info* research_get_cmd(const char* _cmd,
	int _cmd_len){
		//8.2����ʽ
		//�����µ��ڴ�
		char* _new_info = 
			(char*)malloc(_cmd_len);
		//����ָ��
		research_copy_cmd_data(_cmd,_new_info,_cmd_len);
		//ת��������������Ϣ
		return research_convert_cmd(_new_info);
}
