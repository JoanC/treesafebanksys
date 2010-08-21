#pragma once
//ģ��2

//���������̶�Ҫ����
#include "sys_login.h"//��½��������
#include "sys_error_compute.h"//������ģ��
#include "sys_reg.h"
#include "net.h"

typedef char* COMMAND_DATA;
#define SYS_CMD_MAX_RLT_SIZE 256

enum{
	//�����ż���
	sys_cmd_login,//��¼ָ��
	sys_cmd_reg,//ע��ָ��
	sys_cmd_unexpect//δ֪����(���ɽ���)
};

struct sys_net_data{
	int type;//��������
	int len;//�����
	COMMAND_DATA data;//�����е�����
};

/************************************************/
//ģ��2
// ��net�е�ָ��-->ת��-->��Ҫ���͵�����
//���ܹ��̵Ĺ���ģ��
//��ģ����Jiraiya�����鳤���

//��ģ�鱾����һ��Э��
//ÿ��ģ�����������д���������
//����data���͵���Ӧ���ӹ�����ȥ

/***********************************************/
//ģ��2.1
//��ʼ�����ͷ�sys_net_info
void sys_command_init_sys_net_data(sys_net_data* _init);
void sys_command_release_sys_net_data(sys_net_data* _release);

/************************************************/
//ģ��2.2
//0.2 -- ������Ľ�����Ϣת��Ϊ������Ϣ
void sys_command_convert(net_recieved_info* _rev , sys_net_data* _cmd);

/************************************************/
//ģ��2.3
//0.1 -- �������������������,�������Խ���,��ִ����Ӧ�������̺�ʽ
//һ�����switch_case
//���ݲ�ͬ���������,���ò�ͬ�Ĵ�����
//����ָ��Ľ�����ڽ�Ҫ���͵�һ��net_datazhogn 
void sys_command(const sys_net_data* _command,char* _rlt,int* _rlt_len);


//ģ��2.3
//0.3��ͬ���Ӵ�����

//��½ģ��Ĵ�����2.3.1
void sys_command_login(const sys_net_data* _cmd,char* _rlt,int* _rlt_len);

//ע��ģ���Ӵ���ʽ2.3.2
void sys_command_reg(const sys_net_data* _cmd , char* _rlt,int* _rlt_len);

//ģ��2.4
//δ֪����Ĵ���ʽ
void sys_command_err(const sys_net_data* _command,char* _rlt,int* _rlt_len);

//����ģ��
void sys_command_run_frame(net_recieved_info* _rev , net_send_info* _send);
