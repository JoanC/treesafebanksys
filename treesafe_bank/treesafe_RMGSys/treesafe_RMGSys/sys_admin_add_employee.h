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
struct add_employee_info{
	bool is_succ;//����Ƿ�ɹ�
	sys_err err_info;//������Ϣ
};

struct add_employee_modle{
	add_employee_input input_info;//������Ϣ
	add_employee_info rlt_info;//�����¼��Ϣ
};


/*****************************************/
//ģ��15.1
//���ݽṹ��ʼ�����ͷ�

//��ʼ���������Ϣ
void init_add_employee_input(add_employee_input* _init);

//��ʼ����ӹ�Ա�Ľ����¼��Ϣ
void init_add_employee_info(add_employee_info* _init);

//��ʼ����ӹ�Ա����ģ��
add_employee_modle* init_add_employee_modle();

/******************************************/
//ģ��15.2
//����ָ����Ϣ
//�����ܵ�ָ��ת�����������Ϣ

//
void add_employee_copy_cmd
