#include "sys_credit_compute.h"
#include "sys_error_compute.h"
#include "database_mgr.h"



//模块25
//修改权重

struct update_weight_input{
	event_wgt new_wgt;//新的权重
};

struct update_weight_info{
	 sys_err err_info;
};

struct update_weight_modle{
	update_weight_input input_info;
	update_weight_info rlt_info;
};


//初始化模块25
void init_update_weight_input(update_weight_input* _init);

void init_update_weight_info(update_weight_info* _init);

update_weight_modle* init_update_weight_info();

void release_update_weight_modle(update_weight_modle* _release);

//获取模块25的指令

void update_weight_copy_cmd(const char* _cmd,char* _dest,int _cmd_len);

update_weight_input* update_weight_convert_cmd(char* _info);

update_weight_input* update_weight_get_cmd(char* );