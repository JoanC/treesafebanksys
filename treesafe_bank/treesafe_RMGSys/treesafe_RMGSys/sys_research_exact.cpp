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
	//初始化错误信息
	init_sys_err(&_init->err_info);
	strcpy(_init->research_apply_id,"");
}

research_exact_modle* research_exact_init_research_exact_modle(){
	//分配内存
	research_exact_modle* _new_modle
		= (research_exact_modle*)malloc(sizeof(research_exact_modle));
	//初始化输入信息
	research_exact_init_research_exact_input_info(&_new_modle->input_info);
	//初始化审核员信息
	research_exact_init_research_exact_investigator_prop(&_new_modle->investigator_prop);
	//初始化结果记录信息
	research_exact_init_research_exact_info(&_new_modle->rlt_info);
	//返回这个新建的指针
	return _new_modle;
}

void release_research_exact_modle(research_exact_modle* _release){
	free(_release);
}