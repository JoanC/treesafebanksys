#include "sys_admin_employee_info.h"
#include "database_mgr.h"
#include "sys_error_compute.h"
#define UPDATE_EMPLOYEE_CARD_ID_LEN 19


//模块24
struct update_employee_input{
	char* card_id[UPDATE_EMPLOYEE_CARD_ID_LEN];//原号码信息
	admin_employee_info new_info;//新输入的信息
};

struct update_employee_info{
	sys_err err_info;//错误信息
};

struct update_employee_modle{
	update_employee_input input_info;//输入信息
	update_employee_info rlt_info;//输出信息
};

//24.1
//初始化和释放模块
void init_update_employee_input(update_employee_input* _init);

void init_update_employee_info(update_employee_info* _init);

update_employee_modle* init_update_employee_modle();

void release_update_employee_modle(update_employee_modle* _release);

//24.2
//获取指令

void update_employee_copy_cmd(const char* _cmd , char* _dest , int _cmd_len);

update_employee_input* update_employee_convet_cmd(char* _info);

update_employee_input* update_employee_get_cmd(const char* _cmd , int _cmd_len);

//24.3
//数据库计算
//sunni完成
void update_employee_set_date(char* _card_id_old
	,admin_employee_info* _new);

//24.4
//结果转化计算

void update_employee_convert_rlt(update_employee_info* _info 
	, char* _rlt , int* _rlt_len);

//模块24的总模块计算
void update_employee_frame(const char* _cmd,int _cmd_len
	,char* _rlt , int* _rlt_len);