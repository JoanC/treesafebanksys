#include "stdafx.h"
#include "sys_command.h"


//ģ��2.1
void sys_command(const sys_net_data* _command,char* _rlt){
	int _command_type = _command->type;//��ȡ���������
	//Э�����
	switch (_command_type){
	case(sys_cmd_login):{
		//���õ�¼�����Ӻ���
		sys_command_login(_command,_rlt);
						}break;
	case(sys_cmd_unexpect):{
		sys_command_err(_command,_rlt);
						   }break;
	default:
		sys_command_err(_command,_rlt);
	}
}

//ģ��2.2
//2.2.1 ��½����
void sys_command_login(const sys_net_data* _cmd,char* _rlt){
	//���õ�½����ʽ
	login_frame(_cmd->data,_cmd->len,_rlt);
}

void sys_command_err(const sys_net_data* _command,char* _rlt){

}