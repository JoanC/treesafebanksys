#pragma once
#include "sys_error_compute.h"
#include "sys_db_struct.h"

/***********************************************/
//初始化函数
//所有结构体的初始化函数

//初始化用户信息
void apply_init_apply_custmor_info(apply_custmor_info* _init);

//初始化用户资产信息
void apply_init_apply_custmor_assets_info(apply_cust_asset_info* _init);

//初始化用户家庭信息
void apply_init_apply_custmor_family_info(apply_cust_family_info* _init);

//初始化贷款信息
void apply_init_apply_loan_info(apply_loan_info* _init);

//初始化输入信息
void apply_init_apply_input_info(apply_input_info* _init);
