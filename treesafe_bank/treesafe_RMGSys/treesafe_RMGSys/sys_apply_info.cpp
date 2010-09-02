#include "stdafx.h"
#include "sys_apply_info.h"


void apply_init_apply_custmor_info(apply_custmor_info* _init){
	//初始化用户信息
	strcpy(_init->app_id,"");
	_init->cust_age = 0;
	_init->cust_card_type = id_card;
	_init->cust_gender = apply_info_male;
	strcpy(_init->cust_id,"");
	strcpy(_init->cust_name,"");
	strcpy(_init->cust_other_tel_num,"");
	strcpy(_init->cust_tel_num,"");
	_init->cust_edu = edu_primary_and_below;
	//初始化邮政编码,家庭住址和住房权属
	strcpy(_init->cust_zip_code,"");
	strcpy(_init->cust_addr,"");
	_init->cust_house_type = own;//初始值为自有房产
}

void apply_init_apply_custmor_assets_info(apply_cust_asset_info* _init){
	//初始化用户资产信息
	strcpy(_init->app_id,"");
	_init->cust_deposit_type = none_deposit;
	_init->cust_family_annual_income = fincome_down_2000;
	_init->cust_industry = farm_industry_other;
	_init->does_cust_have_loan = false;
	_init->cust_loan_sum = loan_none_range;
	_init->cust_loan_time = apply_time_none;
	_init->cust_personal_annual_income = pincome_down_2000;
	_init->cust_unsecured_fixed_asset = asset_other;
	strcpy(_init->cust_work_unit,"");
	strcpy(_init->cust_work_pos,"");
	//-------------------------------------
//	_init->cust_deposit_range = deposit_none_range;
}

void apply_init_apply_custmor_family_info(apply_cust_family_info* _init){
	//初始化用户家庭信息
	strcpy(_init->app_id,"");
	_init->cust_apouse_card_type = id_card;
	_init->cust_children_num = 0;
	_init->cust_marital_status = not_married;
	_init->cust_spouse_edu_degree = edu_primary_and_below;
	strcpy(_init->cust_spouse_card_id,"");
	_init->does_cust_spouse_has_loan = false;
	strcpy(_init->cust_spouse_name,"");
	strcpy(_init->cust_spouse_work_unit,"");
}

void apply_init_apply_loan_info(apply_loan_info* _init){
	//初始化申请信息
	strcpy(_init->app_id,"");
	_init->loan_application_amount = loan_down_2000;
	strcpy(_init->loan_comment,"");
	_init->loan_dead_line = 0;
	_init->loan_times = loan_times_first;
	_init->is_want_msg = cust_want_msg;
}


void apply_init_apply_input_info(apply_input_info* _init){
	//初始化输入信息
	apply_init_apply_custmor_info(&_init->input_basic_info);
	apply_init_apply_custmor_assets_info(&_init->input_asset_info);
	apply_init_apply_custmor_family_info(&_init->input_fammily_info);
	apply_init_apply_loan_info(&_init->input_loan_info);
}
