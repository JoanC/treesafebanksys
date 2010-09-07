#include "stdafx.h"
#include "sys_command.h"

//ģ��2.1
void sys_command_convert(net_recieved_info* _rev , sys_net_data* _cmd){
DEBUG_COMMAND_PRINT("command convert\n");
	//���ɵĽṹ���Ȼ���rev��
	//_cmd->data = (COMMAND_DATA)malloc(_rev->stNetDataLength);
	strcpy(_cmd->data,"");
	//�ڴ渴��,ת��
	memcpy(_cmd,_rev->cNetDataInfo,sizeof(sys_net_data));
}

void sys_command_init_sys_net_data(sys_net_data* _init){
DEBUG_COMMAND_PRINT("command:init system net data\n");
	//_init->data = NULL;
	_init->len = 0;
	_init->type = sys_cmd_unexpect;
	strcpy(_init->data,"");
}

void sys_command_release_sys_net_data(sys_net_data* _release){
DEBUG_COMMAND_PRINT("command:release system net data!\n");
	//if(_release->data != NULL) free(_release->data);
	free(_release);
}

//ģ��2.2
void sys_command(const sys_net_data* _command,char* _rlt , int* _rlt_len){
DEBUG_COMMAND_PRINT("command:analyze command!\n");

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
		//�����û���������ʽ
	case(sys_cmd_query_user_array):{
		sys_command_query_user_array(_command,_rlt,_rlt_len);
								   }break;
		//���ô洢��������ʽ
	case(sys_cmd_get_user_score):{
		sys_command_get_score(_command,_rlt,_rlt_len);
								 }break;
		//���÷�����ѯ����ʽ
	case(sys_cmd_query_user_score):{
		sys_command_query_user_score(_command,_rlt,_rlt_len);
								   }break;
		//���õ��˲�ѯ����ʽ
	case(sys_cmd_query_one_user_info):{
		sys_command_query_one_user_info(_command,_rlt,_rlt_len);
									  }break;
		//����Ȩ�ز�ѯ����ʽ
	case(sys_cmd_query_weight):{
		sys_command_query_weight(_command,_rlt,_rlt_len);
							   }break;
		//���ø���Ȩ������ʽ
	case(sys_cmd_update_weight):{
		sys_command_update_weight(_command,_rlt,_rlt_len);
								}break;
		//���ò��ҹ�Ա��������ʽ
	case(sys_cmd_query_employee_arr):{
		sys_command_query_employee_arr(_command,_rlt,_rlt_len);
									 }break;
	case(sys_cmd_update_user_info):{
		sys_command_update_user_info(_command,_rlt,_rlt_len);
								   }break;
		//���ø��Ĺ�Ա����ʽ
	case(sys_cmd_update_employee_info):{
		sys_command_update_emplyee_info(_command,_rlt,_rlt_len);
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
DEBUG_COMMAND_PRINT("command:login command\n");
	login_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.2 ע�ᴦ��
void sys_command_reg(const sys_net_data* _cmd , char* _rlt,int* _rlt_len){
DEBUG_COMMAND_PRINT("command:register command\n");
	reg_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.3 ���봦��
void sys_command_apply(const sys_net_data* _cmd , char* _rlt,int* _rlt_len){
DEBUG_COMMAND_PRINT("command:apply command\n");
	apply_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}
 
//2.4.4
void sys_command_add_employee(const sys_net_data* _cmd , char* _rlt,int* _rlt_len){
DEBUG_COMMAND_PRINT("command:add employee command\n");
	add_employee_frame(_cmd->data,_cmd->len
		,_rlt,_rlt_len);
}

//2.4.5
void sys_command_delete_employee(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
DEBUG_COMMAND_PRINT("command:delete employee command\n");
	delete_employee_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.6
void sys_command_commit_research(const sys_net_data* _cmd, char* _rlt,int* _rlt_len){
DEBUG_COMMAND_PRINT("command:commit research command\n");
	research_commit_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.7
void sys_command_query_research(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
DEBUG_COMMAND_PRINT("command:query research command\n");
	research_query_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.8
void sys_command_exact_research(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
DEBUG_COMMAND_PRINT("command:exact research command\n");
	research_exact_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}
  
//2.4.9
void sys_command_query_employee(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
DEBUG_COMMAND_PRINT("command:query employee command\n");
	employee_query_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.10
void sys_command_query_user_array(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
DEBUG_COMMAND_PRINT("command:query user array command\n");
	user_query_array_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.11
void sys_command_get_score(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
DEBUG_COMMAND_PRINT("command:get score command\n");
	get_score_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.12
void sys_command_query_user_score(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
DEBUG_COMMAND_PRINT("command:query user score command\n");
	query_score_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.13
void sys_command_query_one_user_info(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
DEBUG_COMMAND_PRINT("command:query one user info command\n");
	 query_user_one_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.14
void sys_command_query_weight(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
	DEBUG_COMMAND_PRINT("command:query the weight\n");
	query_weight_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.15
void sys_command_update_weight(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
	DEBUG_COMMAND_PRINT("command:update the weight\n");
	update_weight_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.16
void sys_command_query_employee_arr(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
	DEBUG_COMMAND_PRINT("command:query an employee array\n");
	query_employee_arr_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.17
void sys_command_update_emplyee_info(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
	DEBUG_COMMAND_PRINT("command:update an employee's information\n");
	update_employee_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//2.4.18
void sys_command_update_user_info(const sys_net_data* _cmd,char* _rlt,int* _rlt_len){
	DEBUG_COMMAND_PRINT("command:update an user's constract information\n");
	update_user_frame(_cmd->data,_cmd->len,_rlt,_rlt_len);
}

//ģ��2.5
void sys_command_err(const sys_net_data* _command,char* _rlt,int* _rlt_len){
DEBUG_COMMAND_PRINT("command:error command\n");
}

void sys_command_run_frame(net_recieved_info* _rev , net_send_info* _send){
DEBUG_COMMAND_PRINT("command:run frame command\n");
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