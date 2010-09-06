#include "database_mgr.h"
#include "sys_admin_employee_info.h"


#define MAX_EMPLOYEE_NUM 15

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

/***************************************/
//23.1
//��ʼ�����ͷ�ģ��
 
//��ʼ������ģ��
void init_query_employee_array_input(query_employee_array_input* _init);

//��ʼ�����ģ��
void init_query_employee_array_info(query_employee_array_info* _init);

//��ʼ��ģ��23����ģ��
query_employee_modle* init_query_employee_modle();

//�ͷ�ģ��
void release_query_employee_arr_modle(query_employee_modle* _release);

/*****************************************/
//23.2
//��ȡָ��
//����ָ��
void query_employee_arr_copy_cmd(const char* _cmd,
	char* _dest , int _cmd_len);

//ת��ָ��
query_employee_array_input* query_employee_arr_convert_cmd(char* _info);

//����ʽ,��ȡָ��
query_employee_array_input* query_employee_arr_get_cmd(const char* _cmd
	,int _cmd_len);

/******************************************/
//23.3
//���ݿ����
bool query_employee_arr_get_num(int* _count);

bool query_employee_arr_get_data(admin_employee_info* _arr,int _Count);

/*******************************************/
//23.4
//�����Ϣת��
void query_employee_arr_convert_rlt(query_employee_array_info* _info,
	char* _rlt , int* _rlt_len);


//ģ��23����ʽ
void query_employee_arr_frame(const char* _cmd , int _cmd_len,
	char* _rlt , int* _rlt_len);


 