#pragma once 
#include "sys_group_info.h"
#include "database_mgr.h"


//��ӷ�����Ϣ

struct add_group_input{
	group_info group;
};

struct add_group_info{
	bool is_add_group_succ;//���ӷ����Ƿ�ɹ�
	sys_err err_info;
};

struct add_group_modle{
	add_group_input input_info;//������Ϣ
	add_group_info rlt_info;//�����Ϣ
};

/*****************************************/
//ģ��31
//31.1
//��ʼ����Ϣ
void init_add_group_input(add_group_input* _init);

void init_add_group_info(add_group_info* _init);

add_group_modle* init_add_group_modle();

void add_group_release(add_group_modle* _release);
/******************************************/
//31.2
//��ȡָ��

//����ָ��
void add_group_copy_cmd(const char* _cmd,char* _info,int _cmd_len);

add_group_input* add_group_convert_cmd(char* _info);

add_group_input* add_group_get_cmd(const char* _cmd,int _cmd_len);

/********************************************/
//31.3
//�������ݿ�
//sunni���

//1.�Զ�����һ��group_id
//2.��group_id��Ϊ����,��������Ϣ�������ݿ���
bool add_group_db(group_info* _info);

/**********************************************/
//31.4
//����������Ϣ
void add_group_generate_rlt(add_group_info* _info,char* _rlt,int* _rlt_len);

/**********************************************/
//ģ��31����ʽ
void add_group_frame(const char* _cmd,int _cmd_len,char* _rlt,int* _rlt_len);


