#include "sys_admin_employee_info.h"
#include "database_mgr.h"
#include "sys_error_compute.h"
#define UPDATE_EMPLOYEE_CARD_ID_LEN 19


//ģ��24
struct update_employee_input{
	char* card_id[UPDATE_EMPLOYEE_CARD_ID_LEN];//ԭ������Ϣ
	admin_employee_info new_info;//���������Ϣ
};

struct update_employee_info{
	sys_err err_info;//������Ϣ
};

struct update_employee_modle{
	update_employee_input input_info;//������Ϣ
	update_employee_info rlt_info;//�����Ϣ
};

//24.1
//��ʼ�����ͷ�ģ��
void init_update_employee_input(update_employee_input* _init);

void init_update_employee_info(update_employee_info* _init);

update_employee_modle* init_update_employee_modle();

void release_update_employee_modle(update_employee_modle* _release);

//24.2
//��ȡָ��

void update_employee_copy_cmd(const char* _cmd , char* _dest , int _cmd_len);

update_employee_input* update_employee_convet_cmd(char* _info);

update_employee_input* update_employee_get_cmd(const char* _cmd , int _cmd_len);

//24.3
//���ݿ����
//sunni���
void update_employee_set_date(char* _card_id_old
	,admin_employee_info* _new);

//24.4
//���ת������

void update_employee_convert_rlt(update_employee_info* _info 
	, char* _rlt , int* _rlt_len);

//ģ��24����ģ�����
void update_employee_frame(const char* _cmd,int _cmd_len
	,char* _rlt , int* _rlt_len);