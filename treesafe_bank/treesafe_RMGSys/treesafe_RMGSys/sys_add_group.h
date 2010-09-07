#pragma once 
#include "database_mgr.h"

#include "sys_group_info.h"

//添加分组信息

struct add_group_input{
	group_info group;
};

struct add_group_info{
	sys_err err_info;
};

/*****************************************/
//模块31

//31.1