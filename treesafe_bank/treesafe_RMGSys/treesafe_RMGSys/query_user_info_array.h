#pragma once

#include "query_user_info.h"
#include "database_mgr.h"
#include "sys_error_compute.h"

//ģ��20
//��ѯ����ӵ�д����ũ����Ϣ
//���� ���Ѿ����ڱ����ͨ����ũ����Ϣ


struct user_query_arr_input{};//�սṹ��

struct user_query_arr_info{
//	sys_err err_info;
	user_query_array_info query_arr_info;//������Ϣ
};//�����Ϣ

struct user_query_arr_modle{
	user_query_arr_input input_info;
	user_query_arr_info rlt_info;
};

//20.1
//jiraiya ���
//��ʼ���ṹ��
//��ʼ��ģ��20����ģ��

user_query_arr_modle* init_user_query_arr_modle();

//�ͷ�ģ��
void release_user_query_arr_modle(user_query_arr_modle* _release);

//20.2
//��ȡָ��
//����ָ��
void user_query_copy_cmd(const char* _cmd , char* _dest, int _cmd_len);

//ת��ָ��
user_query_arr_input* user_query_convert_cmd(char* _info);

user_query_arr_input* query_user_arr_get_cmd(const char* _cmd,int _cmd_len);

//20.3
//sunni���
//�õ�����ũ�������,��Щ�˵��������б����ͨ��������
//���������һ��������
bool user_query_arr_count(int* _count) ;

//20.4
//sunni���
//�õ�һ������
//�����д����Щũ�����Ϣ
//�������һ��ָ����
bool user_query_arr(user_query_arr_info* user_array,int* _arr_size) ;

//20.5
//ת���������
void user_query_arr_convert_rlt(user_query_arr_info* _info,char* _rlt,int* _rlt_len);


//ģ��20������ʽ
void user_query_array_frame(const char* _cmd,int _cmd_len,char* _rlt,int* _rlt_len);