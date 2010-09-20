#pragma once

#include "sys_group_info.h"
#include "database_mgr.h"
#include "sys_error_compute.h"

//ģ��32
//��ѯһ��С�����Ϣ
#define MAX_GROUP_INFO 25

struct query_group_input{
	//��
};

struct query_group_info{
	int group_num;
	sys_err err_info;
	group_info group[MAX_GROUP_INFO];//�������Ϣ
};

struct query_group_modle{
	query_group_input input_info;
	query_group_info rlt_info;
}:

//32.1
//��ʼ��ģ��
void init_query_group_input(query_group_input* _init);

void init_query_group_info(query_group_info* _init);

query_group_modle* init_query_group_modle();

//32.2
//����ָ��
void query_group_copy_cmd(const char* _cmd
	,char* _info,int _cmd_len);

query_group_input* query_convert_cmd(char* _info);

query_group_input* query_get_cmd(const char* _cmd,int _cmd_len);

//32.3
//���ݿ����
//1.���ҳ����еķ���
//2.������ĸ������뵽int��
//3.���еķ�����Ϣ�����������ʽ����ָ����









