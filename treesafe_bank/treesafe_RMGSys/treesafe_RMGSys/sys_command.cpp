#include "stdafx.h"
#include "sys_command.h"


//ģ��2.1
void sys_command(const sys_net_data* _command){
	int _command_type = _command->type;//��ȡ���������
	//Э�����
	switch (_command_type){
	case(sys_cmd_login):{
		//���õ�¼�����Ӻ���
		sys_command_login(_command);
						}break;
	case(sys_cmd_unexpect):{
		sys_command_err(_command);
						   }break;
	default:
		sys_command_err(_command);
	}
}

//ģ��2.2
//2.2.1 ��½����
void sys_command_login(const sys_net_data* _cmd){
	//���õ�½����ʽ
}