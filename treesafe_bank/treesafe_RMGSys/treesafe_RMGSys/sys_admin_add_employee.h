#include "database_mgr.h"//���ݿ⴦��ʽ
#include "sys_error_compute.h"//������

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


//��ӹ�Ա�Ľ����Ϣ
struct add_emloyee_info{
	bool is_succ;//����Ƿ�ɹ�
	sys_err err_info;//������Ϣ
};


/*****************************************/
//ģ��15.1
//���ݽṹ��ʼ�����ͷ�
