#include "sys_credit_compute.h"
#include "sys_error_compute.h"
#include "database_mgr.h"



//ģ��25
//�޸�Ȩ��

struct wgt_int{
	int income ;
	int depos ;
	int repayment ;
	int fixed_assets_be_pledged ;
	int id_type ;
	int edu ;
	int marriage ;
	int loan_record ;
	int social_record ;
	int auditor_edit ;
};

struct update_weight_input{
	wgt_int new_wgt;//�µ�Ȩ��
};

struct update_weight_info{
	 sys_err err_info;
};

struct update_weight_modle{
	update_weight_input input_info;
	update_weight_info rlt_info;
	event_wgt new_wgt;
};

//25.1
//��ʼ��ģ��25
void init_update_weight_input(update_weight_input* _init);

void init_update_weight_info(update_weight_info* _init);

update_weight_modle* init_update_weight_info();

void release_update_weight_modle(update_weight_modle* _release);


//25.2
//��ȡģ��25��ָ��

void update_weight_copy_cmd(const char* _cmd,char* _dest,int _cmd_len);

update_weight_input* update_weight_convert_cmd(char* _info);

update_weight_input* update_weight_get_cmd(const char* _cmd , int _cmd_len);

//ģ��25.3
//sunni���
//���ݿ�ĸ���

void update_weight_set_data(event_wgt* _new_data) ;

//ģ��25.4
//�������ת��
void update_weight_convert_rlt(update_weight_info* _info,
	char* _rlt , int* _rlt_len);

void convet_from_int_to_float(wgt_int* _int ,event_wgt* _float);

//ģ��25������ʽ
void update_weight_frame(const char* _cmd , int _cmd_len 
	, char* _rlt , int* _rlt_len);





