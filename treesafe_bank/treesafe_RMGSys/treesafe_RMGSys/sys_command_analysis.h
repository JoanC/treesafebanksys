//ģ��2
#include "treesafe_cServer.h"

typedef char* COMMAND_DATA;

enum{
	//�����ż���
	sys_cmd_login //��¼ָ��
};

//���ܹ��̵Ĺ���ģ��
//��ģ����Jiraiya�����鳤���

//��ģ�鱾����һ��Э��
//ÿ��ģ�����������д���������
//����data���͵���Ӧ���ӹ�����ȥ
//��ģ���뷢���޹�

//�������������������,�������Խ���
//һ�����switch_case
//���ݲ�ͬ���������,���ò�ͬ�Ĵ�����
void sys_command(const sys_net_data* _command);

//��ͬ���Ӵ�����

//��½ģ��Ĵ�����
void sys_command_login(COMMAND_DATA _data);