#include "database_mgr.h"//���ݿ⴦��ʽ

//ģ��15
//����Ա���� -- ��ӹ�Ա
//�������һ����Ա

#include "sys_admin_employee_info.h"

#define ADD_EMPLOYEE_COMMENT_LEN 51

//��ӹ�Աʱ�������Ϣ
struct add_employee_input{
	admin_employee_info employ_basic_info;
	char comment[ADD_EMPLOYEE_COMMENT_LEN];
};