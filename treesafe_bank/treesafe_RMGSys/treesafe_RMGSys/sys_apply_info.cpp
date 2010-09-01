#include "stdafx.h"
#include "sys_apply_info.h"


void apply_init_apply_custmor_info(apply_custmor_info* _init){
	//��ʼ���û���Ϣ
	_init->cust_age = 0;
	_init->cust_card_type = id_card;
	_init->cust_gender = apply_info_male;
	strcpy(_init->cust_id,"");
	strcpy(_init->cust_name,"");
	strcpy(_init->cust_other_tel_num,"");
	strcpy(_init->cust_tel_num,"");
	_init->cust_edu = edu_primary_and_below;
	//��ʼ����������,��ͥסַ��ס��Ȩ��
	strcpy(_init->cust_zip_code,"");
	strcpy(_init->cust_addr,"");
	_init->cust_house_type = own;//��ʼֵΪ���з���
}

void apply_init_apply_custmor_assets_info(apply_cust_asset_info* _init){
	//��ʼ���û��ʲ���Ϣ
	_init->cust_deposit_range = none_range;
	_init->cust_deposit_type = regular_deposit;
	_init->cust_family_annual_income = 0;
	_init->cust_industry = other_farming;
	_init->does_cust_have_loan = false;
	_init->cust_loan_sum = 0;
	_init->cust_loan_time = 0;
	_init->cust_personal_annual_income = 0;
	_init->cust_unsecured_fixed_asset = asset_none;
	strcpy(_init->cust_work_unit,"");
	strcpy(_init->cust_work_pos,"");
}

void apply_init_apply_custmor_family_info(apply_cust_family_info* _init){
	//��ʼ���û���ͥ��Ϣ
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
	//��ʼ��������Ϣ
	_init->loan_application_amount = 0;
	strcpy(_init->loan_comment,"");
	_init->loan_dead_line = 0;
	_init->loan_times = loan_times_first;
}


void apply_init_apply_input_info(apply_input_info* _init){
	//��ʼ��������Ϣ
	apply_init_apply_custmor_info(&_init->input_basic_info);
	apply_init_apply_custmor_assets_info(&_init->input_asset_info);
	apply_init_apply_custmor_family_info(&_init->input_fammily_info);
	apply_init_apply_loan_info(&_init->input_loan_info);
}
