#include "sys_admin_employee_info.h"
#include "database_mgr.h"
#include "sys_error_compute.h"
#define UPDATE_EMPLOYEE_CARD_ID_LEN 19


struct update_employee_input{
	char* card_id[UPDATE_EMPLOYEE_CARD_ID_LEN];//原号码信息
	admin_employee_info new_info;//新输入的信息
};

struct update_employee_info{
	sys_err err_info;//错误信息
};