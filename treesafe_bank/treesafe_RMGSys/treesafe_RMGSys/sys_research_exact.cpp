#include "stdafx.h"
#include "sys_research_exact.h"

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