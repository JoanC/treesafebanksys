#include "sys_credit_compute.h"
#include "sys_error_compute.h"
#include "database_mgr.h"



//ģ��25
//�޸�Ȩ��

struct update_weight_input{
	event_wgt new_wgt;//�µ�Ȩ��
};

struct update_weight_info{
	 sys_err err_info;
};

struct update_weight_modle{
	update_weight_input input_info;
	update_weight_info rlt_info;
};


//��ʼ��ģ��25
void init_update_weight_input(update_weight_input* _init);

void init_update_weight_info(update_weight_info* _init);

update_weight_modle* init_update_weight_info();

void release_update_weight_modle(update_weight_modle* _release);

//��ȡģ��25��ָ��

void update_weight_copy_cmd(const char* _cmd,char* _dest,int _cmd_len);

update_weight_input* update_weight_convert_cmd(char* _info);

update_weight_input* update_weight_get_cmd(char* );