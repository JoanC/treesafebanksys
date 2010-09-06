#include "database_mgr.h"
#include "sys_admin_employee_info.h"


#define MAX_EMPLOYEE_NUM 30

//模块23
//查询雇员列表

struct query_employee_array_input{};

struct query_employee_array_info{
	int num;//个数
	admin_employee_info employee_arr[MAX_EMPLOYEE_NUM];
};

struct query_employee_modle{
	query_employee_array_input input;//输入信息
	query_employee_array_info rlt_info;//结果信息
};