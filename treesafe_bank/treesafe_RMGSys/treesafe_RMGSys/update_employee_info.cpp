#include "stdafx.h"
#include "update_employee_info.h"

extern _ConnectionPtr* treesafe_db_connection ; 
//24.1
void init_update_employee_input(update_employee_input* _init){
DEBUG_UPDATE_EMPLOYEE_INFO_PRINT("init_update_employee_input");
	memset(_init->card_id,'\0'
		,UPDATE_EMPLOYEE_CARD_ID_LEN);
	init_admin_employee_info(&_init->new_info);
}

void init_update_employee_info(update_employee_info* _init){
DEBUG_UPDATE_EMPLOYEE_INFO_PRINT("init_update_employee_info");
	init_sys_err(&_init->err_info);
}

update_employee_modle* init_update_employee_modle(){
DEBUG_UPDATE_EMPLOYEE_INFO_PRINT("init_update_employee_modle");
	update_employee_modle* _new_modle =
		(update_employee_modle*)malloc(sizeof(update_employee_modle));
	init_update_employee_input(&_new_modle->input_info);
	init_update_employee_info(&_new_modle->rlt_info);
	return _new_modle;
}

void release_update_employee_modle(update_employee_modle* _release){
DEBUG_UPDATE_EMPLOYEE_INFO_PRINT("release_update_employee_modle");
	free(_release);
}

//24.2

void update_employee_copy_cmd(const char* _cmd , char* _dest , int _cmd_len){
DEBUG_UPDATE_EMPLOYEE_INFO_PRINT("update_employee_copy_cmd");
	memcpy(_dest,_cmd,_cmd_len);
}

update_employee_input* update_employee_convet_cmd(char* _info){
DEBUG_UPDATE_EMPLOYEE_INFO_PRINT("update_employee_convet_cmd\n");
	update_employee_input* _input = (update_employee_input*)_info;
	DECODE_UTF7_TO_ASC(_input->new_info.employee_addr);
	DECODE_UTF7_TO_ASC(_input->new_info.employee_comment);
	DECODE_UTF7_TO_ASC(_input->new_info.employee_email);
	DECODE_UTF7_TO_ASC(_input->new_info.employee_name);
	DECODE_UTF7_TO_ASC(_input->new_info.employee_tel);
	return _input;
}


update_employee_input* update_employee_get_cmd(const char* _cmd , int _cmd_len){
DEBUG_UPDATE_EMPLOYEE_INFO_PRINT("update_employee_get_cmd\n");
	char* _info = (char*)malloc(_cmd_len);
	update_employee_copy_cmd(_cmd,_info,_cmd_len);
	return update_employee_convet_cmd(_info);
}


//24.3
//由sunni完成
bool update_employee_set_data(char* _card_id_old
	,admin_employee_info* _new) 
{
	DEBUG_UPDATE_EMPLOYEE_INFO_PRINT("update_employee_set_data\n");
	return Update_emplo_info(treesafe_db_connection,_card_id_old,_new) ;
}
//24.4
void update_employee_convert_rlt(update_employee_info* _info 
	, char* _rlt , int* _rlt_len){
DEBUG_UPDATE_EMPLOYEE_INFO_PRINT("update_employee_convert_rlt\n");
		*_rlt_len = sizeof(update_employee_info);
		memcpy(_rlt,_info,*_rlt_len);
}

//模块24

void update_employee_frame(const char* _cmd,int _cmd_len
	,char* _rlt , int* _rlt_len){
DEBUG_UPDATE_EMPLOYEE_INFO_PRINT("update_employee_frame\n");
		update_employee_modle* _frame
			= (update_employee_modle*)malloc(sizeof(update_employee_modle));
		_frame->input_info = *update_employee_get_cmd(_cmd,_cmd_len);
		//24.3
		//由sunni完成

		//24.4
		update_employee_convert_rlt(&_frame->rlt_info,
			_rlt,_rlt_len);
		//释放模块
		release_update_employee_modle(_frame) ;
}