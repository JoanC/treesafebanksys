


#include "stdafx.h"
#include "sys_command.h"

//ģ��2.1
void sys_command_convert(net_recieved_info* _rev , sys_net_data* _cmd){
	//���ɵĽṹ���Ȼ���rev��
	//_cmd->data = (COMMAND_DATA)malloc(_rev->stNetDataLength);
	strcpy(_cmd->data,"");
	//�ڴ渴��,ת��
	memcpy(_cmd,_rev->cNetDataInfo,sizeof(sys_net_data));
}

void sys_command_init_sys_net_data(sys_net_data* _init){
	//_init->data = NULL;
	_init->len = 0;
	_init->type = sys_cmd_unexpect;
	strcpy(_init->data,"");
}

void sys_command_release_sys_net_data(sys_net_data* _release){
	//if(_release->data != NULL) free(_release->data);
	free(_release);
}

//ģ��2.2
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
	case(sys_cmd_apply):{
		//�������봦����
		sys_command_apply(_command,_rlt,_rlt_len);
						}break;
		//�������ӹ�Ա������
	case(sys_cmd_add_employee):{
		sys_command_add_employee(_command,_rlt,_rlt_len);
							   }break;
		//����ɾ����Ա�Ĵ�����
	case(sys_cmd_delete_employee):{
		sys_command_delete_employee(_command,_rlt,_rlt_len);
								  }break;
		//�����ύ��˴���ʽ
	case(sys_cmd_commit_research):{
		sys_command_commit_research(_command,_rlt,_rlt_len);
								  }break;
		//������˲�ѯ����ʽ
	case(sys_cmd_query_research):{
		sys_command_query_research(_command,_rlt,_rlt_len);
								 }break;
		//������˳�ȡ�Ӻ�ʽ
	case(sys_cmd_exact_research):{
		sys_command_exact_research(_command,_rlt,_rlt_len);
								 }break;
		//���ù�Ա��ѯ��ʽ
	case(sys_cmd_query_employee):{
		sys_command_query_employee(_command,_rlt,_rlt_len);
								 }break;
	case(sys_cmd_unexpect):{
		sys_command_err(_command,_rlt,_rlt_len);
						   }break;
	default:
		sys_command_err(_command,_rlt,_rlt_len);
	}
}

//ģ��2.4
//2.4.1 ��½����
void sys_command_login(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
	//���õ�½����ʽ
	login_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.2 ע�ᴦ��
void sys_command_reg(const sys_net_data* _cmd , char* _rlt,int* _rlt_len){
	reg_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.3 ���봦��
void sys_command_apply(const sys_net_data* _cmd , char* _rlt,int* _rlt_len){
	apply_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.4
void sys_command_add_employee(const sys_net_data* _cmd , char* _rlt,int* _rlt_len){
	add_employee_frame(_cmd->data,_cmd->len
		,_rlt,_rlt_len);
}

//2.4.5
void sys_command_delete_employee(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
	delete_employee_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.6
void sys_command_commit_research(const sys_net_data* _cmd, char* _rlt,int* _rlt_len){
	research_commit_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.7
void sys_command_query_research(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
	research_query_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.8
void sys_command_exact_research(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
	research_exact_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.9
void sys_command_query_employee(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
	employee_query_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.10
void sys_command_query_user_array(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
	user_query_array_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//ģ��2.5
void sys_command_err(const sys_net_data* _command,char* _rlt,int* _rlt_len){

}

void sys_command_run_frame(net_recieved_info* _rev , net_send_info* _send){
	//2.1 -- ��ʼ���������ݿ�
	sys_net_data* _cmd_info
		= (sys_net_data*)malloc(sizeof(sys_net_data));
	
	char rlt[SYS_CMD_MAX_RLT_SIZE];
	
	int _len = 0;
	sys_command_init_sys_net_data(_cmd_info);

	//2.2 -- ת��
	sys_command_convert(_rev,_cmd_info);

	//2.3����������������ģ��
	sys_command(_cmd_info,rlt,&_len);

	//����Ҫ���͵���Ϣ
	_send->netType = NETDATA;//...
	_send->stNetDataLength = _len;
	//������Ϣ
	if(_len != 0){
		_send->cNetDataInfo = (char*)malloc(_len);
		memcpy(_send->cNetDataInfo,rlt,_len);
	}
	//�ͷ�
//	if(rlt != NULL) free(rlt);
	sys_command_release_sys_net_data(_cmd_info);
}