#include "sys_admin_employee_info.h"
#include "database_mgr.h"
#include "sys_error_compute.h"
#define UPDATE_EMPLOYEE_CARD_ID_LEN 19


struct update_employee_input{
	char* card_id[UPDATE_EMPLOYEE_CARD_ID_LEN];//ԭ������Ϣ
	admin_employee_info new_info;//���������Ϣ
};

struct update_employee_info{
	sys_err err_info;//������Ϣ
};