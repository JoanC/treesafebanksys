#include "database_mgr.h"
#include "sys_admin_employee_info.h"


#define MAX_EMPLOYEE_NUM 30

//ģ��23
//��ѯ��Ա�б�

struct query_employee_array_input{};

struct query_employee_array_info{
	int num;//����
	admin_employee_info employee_arr[MAX_EMPLOYEE_NUM];
};

struct query_employee_modle{
	query_employee_array_input input;//������Ϣ
	query_employee_array_info rlt_info;//�����Ϣ
};