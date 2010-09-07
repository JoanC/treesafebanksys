#include "sys_credit_compute.h"
#include "sys_error_compute.h"
#include "database_mgr.h"



//模块25
//修改权重

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
	wgt_int new_wgt;//新的权重
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
//初始化模块25
void init_update_weight_input(update_weight_input* _init);

void init_update_weight_info(update_weight_info* _init);

update_weight_modle* init_update_weight_info();

void release_update_weight_modle(update_weight_modle* _release);


//25.2
//获取模块25的指令

void update_weight_copy_cmd(const char* _cmd,char* _dest,int _cmd_len);

update_weight_input* update_weight_convert_cmd(char* _info);

update_weight_input* update_weight_get_cmd(const char* _cmd , int _cmd_len);

//模块25.3
//sunni完成
//数据库的更新

void update_weight_set_data(event_wgt* _new_data) ;

//模块25.4
//结果数据转化
void update_weight_convert_rlt(update_weight_info* _info,
	char* _rlt , int* _rlt_len);

void convet_from_int_to_float(wgt_int* _int ,event_wgt* _float);

//模块25的主函式
void update_weight_frame(const char* _cmd , int _cmd_len 
	, char* _rlt , int* _rlt_len);





