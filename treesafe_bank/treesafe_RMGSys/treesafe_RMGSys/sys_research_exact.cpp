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

}
