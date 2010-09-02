#include "stdafx.h"
#include "sys_research_info_query.h"

//ģ��18��ʵ���ļ�


//18.1
void init_research_query_input_info(research_query_input_info* _init){
    //��ʼ��������Ϣģ��	
	//�ַ����ĳ�ʼ��Ϊ��
	strcpy(_init->app_id,"");
}

void init_research_query_info(research_query_info* _init){
	//��ʼ�����ģ��
	//��ʼ��������Ϣ
	//��ʼ���û�������Ϣ
	apply_init_apply_custmor_info(&_init->query_info.input_basic_info);
	//��ʼ���û��ʲ���Ϣ
	apply_init_apply_custmor_assets_info(&_init->query_info.input_asset_info);
	//��ʼ���û���ͥ��Ϣ
	apply_init_apply_custmor_family_info(&_init->query_info.input_fammily_info);
	//��ʼ��������Ϣ
	apply_init_apply_loan_info(&_init->query_info.input_loan_info);
}

research_query_modle* init_research_query_modle(){
	//��ʼ��������ģ��
	research_query_modle* _new_modle
		= (research_query_modle*)malloc(sizeof(_new_modle));
	//��ʼ������ģ��
	init_research_query_input_info(&_new_modle->input_info);
	//��ʼ����ѯ��Ϣ
	init_research_query_info(&_new_modle->rlt_info);
	return _new_modle;
}

void release_research_query_modle(research_query_modle* _release){
	//�ͷ�ģ��
	free(_release);
}


//18.2
void research_query_copy_cmd(const char* _cmd
	,char* _dest , int _cmd_len){
		//������Ϣ�ĸ���
		memcpy(_dest,_cmd,_cmd_len);
}

research_query_input_info* research_query_convert_cmd(char* _info){
	//ת���������������Ϣ
	return (research_query_input_info*)_info;
}

research_query_input_info* research_query_get_cmd(const char* _cmd,int _cmd_len){
	//��ȡָ�������ʽ
	char* _info = (char*)malloc(_cmd_len);
	//����ָ��
	research_query_copy_cmd(_cmd,_info,_cmd_len);
	//ת��ָ��
	return research_query_convert_cmd(_info);
}

//ģ��18.3


//ģ��18.4
void research_query_convert_rlt(research_query_info* _info
	,char* _rlt , int* _rlt_len){
	//����ѯ���������ϵ����������
	*_rlt_len = sizeof(research_query_info);
	//����ָ��
	memcpy(_rlt,_info,*_rlt_len);
}

void research_query_frame(const char* _cmd,int _cmd_len
	,char* _rlt,int* _rlt_len){
		//ģ��18������ʽ
		//��ʼ��ģ��
		research_query_modle* _modle
			= init_research_query_modle();
		//����18.2
		_modle->input_info = *research_query_get_cmd(_cmd,_cmd_len);
		//����18.3
		/*(ģ��18.3��δ���)*/
		/*
		research_query_get_data(_modle->input_info.app_id
			,&_modle->rlt_info.query_info);
			*/
		//����18.4
		//�������ģ��
		research_query_convert_rlt(&_modle->rlt_info
			,_rlt,_rlt_len);
		//�ͷ�ģ��
		release_research_query_modle(_modle);
}