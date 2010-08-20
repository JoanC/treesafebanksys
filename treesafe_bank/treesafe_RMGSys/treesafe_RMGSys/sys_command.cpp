#include "stdafx.h"
#include "sys_command.h"


//ģ��2.1
void sys_command(const sys_net_data* _command,char* _rlt , int* _rlt_len){
	int _command_type = _command->type;//��ȡ���������
	//Э�����
	switch (_command_type){
	case(sys_cmd_login):{
		//���õ�¼�����Ӻ���
		sys_command_login(_command,_rlt , _rlt_len);
						}break;
	case(sys_cmd_reg):{
		//���õ�¼�����Ӻ���
		sys_command_reg(_command,_rlt,_rlt_len);
					  }break;
	case(sys_cmd_unexpect):{
		sys_command_err(_command,_rlt,_rlt_len);
						   }break;
	default:
		sys_command_err(_command,_rlt,_rlt_len);
	}
}

//ģ��2.2
//2.2.1 ��½����
void sys_command_login(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
	//���õ�½����ʽ
	login_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2,2,2 ע�ᴦ��
void sys_command_reg(const sys_net_data* _cmd , char* _rlt,int* _rlt_len){
	reg_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

void sys_command_err(const sys_net_data* _command,char* _rlt,int* _rlt_len){

}