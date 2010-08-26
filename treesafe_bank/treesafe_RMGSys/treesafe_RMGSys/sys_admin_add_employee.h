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
struct add_emloyee_info{
	bool is_succ;//添加是否成功
	sys_err err_info;//错误信息
};


/*****************************************/
//模块15.1
//数据结构初始化和释放
