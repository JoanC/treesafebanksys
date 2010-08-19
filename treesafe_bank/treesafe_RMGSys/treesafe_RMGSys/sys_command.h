#pragma once
//ģ��2
#include "treesafe_cServer.h"

//���������̶�Ҫ����
#include "sys_login.h"//��½��������
#include "sys_error_compute.h"//������ģ��
#include "sys_reg.h"

typedef char* COMMAND_DATA;

enum{
	//�����ż���
	sys_cmd_login,//��¼ָ��
	sys_cmd_reg,//ע��ָ��
	sys_cmd_unexpect//δ֪����(���ɽ���)
};
#pragma once

/************************************************/
//ģ��2
// ��net�е�ָ��-->ת��-->��Ҫ���͵�����
//���ܹ��̵Ĺ���ģ��
//��ģ����Jiraiya�����鳤���

//��ģ�鱾����һ��Э��
//ÿ��ģ�����������д���������
//����data���͵���Ӧ���ӹ�����ȥ

//ģ��2.1
//0.1 -- �������������������,�������Խ���,��ִ����Ӧ�������̺�ʽ
//һ�����switch_case
//���ݲ�ͬ���������,���ò�ͬ�Ĵ�����
//����ָ��Ľ�����ڽ�Ҫ���͵�һ��net_datazhogn 
void sys_command(const sys_net_data* _command,char* _rlt);


//ģ��2.2
//0.2��ͬ���Ӵ�����

//��½ģ��Ĵ�����2.2.1
void sys_command_login(const sys_net_data* _cmd,char* _rlt);

//ע��ģ���Ӵ���ʽ
void sys_command_reg(const sys_net_data* _cmd , char* _rlt);

//ģ��2.3
//δ֪����Ĵ���ʽ
void sys_command_err(const sys_net_data* _command,char* _rlt);
