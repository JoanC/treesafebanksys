#include "stdafx.h"
#include "update_employee_info.h"

void init_update_employee_input(update_employee_input* _init){
	memset(_init->card_id,'\0'
		,UPDATE_EMPLOYEE_CARD_ID_LEN);
	init_admin_employee_info(&_init->new_info);
}

void init_update_employee_info(update_employee_info* _init){
	init_sys_err(&_init->err_info);
}

update_employee_modle* init_update_employee_modle(){
	update_employee_modle* _new_modle =
		(update_employee_modle*)malloc(sizeof(update_employee_modle));
	init_update_employee_input(&_new_modle->input_info);
	init_update_employee_info(&_new_modle->rlt_info);
	return _new_modle;
}

