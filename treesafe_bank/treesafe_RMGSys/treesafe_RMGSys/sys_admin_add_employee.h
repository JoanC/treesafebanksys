#include "database_mgr.h"//数据库处理函式
#include "sys_error_compute.h"//错误处理

//模块15
//管理员操作 -- 添加雇员
//用于添加一个雇员

#include "sys_admin_employee_info.h"


#define ADD_EMPLOYEE_COMMENT_LEN 51


//添加雇员时填入的信息
struct add_employee_input{
	admin_employee_info employ_basic_info;
	char comment[ADD_EMPLOYEE_COMMENT_LEN];
};


//添加雇员的结果信息
struct add_employee_info{
	bool is_succ;//添加是否成功
	sys_err err_info;//错误信息
};

struct add_employee_modle{
	add_employee_input input_info;//输入信息
	add_employee_info rlt_info;//结果记录信息
};


/*****************************************/
//模块15.1
//数据结构初始化和释放

//初始化输入的信息
void init_add_employee_input(add_employee_input* _init);

//初始化添加雇员的结果记录信息
void init_add_employee_info(add_employee_info* _init);

//初始化添加雇员的总模块
add_employee_modle* init_add_employee_modle();

/******************************************/
//模块15.2
//接受指令信息
//将接受的指令转化成输入的信息

//
void add_employee_copy_cmd
