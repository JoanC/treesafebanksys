#include "database_mgr.h"
#include "sys_admin_employee_info.h"


#define MAX_EMPLOYEE_NUM 15

//模块23
//查询雇员列表

struct query_employee_array_input{};

struct query_employee_array_info{
	int num;//个数
	admin_employee_info employee_arr[MAX_EMPLOYEE_NUM];
};

struct query_employee_modle{
	query_employee_array_input input;//输入信息
	query_employee_array_info rlt_info;//结果信息
};

/***************************************/
//23.1
//初始化与释放模块
 
//初始化输入模块
void init_query_employee_array_input(query_employee_array_input* _init);

//初始化结果模块
void init_query_employee_array_info(query_employee_array_info* _init);

//初始化模块23的主模块
query_employee_modle* init_query_employee_modle();

//释放模块
void release_query_employee_arr_modle(query_employee_modle* _release);

/*****************************************/
//23.2
//获取指令
//复制指令
void query_employee_arr_copy_cmd(const char* _cmd,
	char* _dest , int _cmd_len);

//转化指令
query_employee_array_input* query_employee_arr_convert_cmd(char* _info);

//主函式,获取指令
query_employee_array_input* query_employee_arr_get_cmd(const char* _cmd
	,int _cmd_len);

/******************************************/
//23.3
//数据库操作
bool query_employee_arr_get_num(int* _count);

bool query_employee_arr_get_data(admin_employee_info* _arr,int _Count);

/*******************************************/
//23.4
//结果信息转化
void query_employee_arr_convert_rlt(query_employee_array_info* _info,
	char* _rlt , int* _rlt_len);


//模块23主函式
void query_employee_arr_frame(const char* _cmd , int _cmd_len,
	char* _rlt , int* _rlt_len);


 