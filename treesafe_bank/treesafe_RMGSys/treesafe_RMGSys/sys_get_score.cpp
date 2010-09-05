#include "stdafx.h"//预编译
#include "sys_get_score.h"//分数计算


extern _ConnectionPtr *treesafe_db_connection ; 
//11.1
void init_get_score_input_info(get_score_input_info* _init){
	_init->add_on_asset_score = 0;
	_init->add_on_loan_score = 0;
	_init->add_on_society_score = 0;
	_init->add_on_work_score = 0;
	memset(_init->card_id,'\0',GET_SCORE_ID_LEN);
}


void init_get_score_info(get_score_info* _init){
	init_sys_err(&_init->err_info);
}

get_score_modle* init_get_score_info(){
	get_score_modle* _new_modle
		= (get_score_modle*)malloc(sizeof(get_score_modle));
	init_get_score_input_info(&_new_modle->input_info);
	init_get_score_info(&_new_modle->rlt_info);
	return _new_modle;
}

void release_get_score_modle(get_score_input_info* _modle){
	free(_modle);
}

//11.2
void get_score_copy_cmd(const char* _cmd,char* _dest,int _cmd_len){
	memcpy(_dest,_cmd,_cmd_len);
}

get_score_input_info* get_score_convert_cmd(char* _info){
	return (get_score_input_info*)_info;
}

get_score_input_info* get_score_get_cmd(const char* _cmd,int _cmd_len){
	char* _new_info = (char*)malloc(_cmd_len);
	get_score_copy_cmd(_cmd,_new_info,_cmd_len);
	return get_score_convert_cmd(_new_info);
}

//11.3
 bool get_score_get_apply_info(char* _id , apply_score_prop* _info)
 {
	 return Get_app_cust_info(treesafe_db_connection,_info) 
			&& Get_app_asset_info(treesafe_db_connection,_info) 
			&& Get_app_cust_fami_info(treesafe_db_connection,_info) 
			&& Get_app_cust_loan_info(treesafe_db_connection,_info) ;
 }

void get_score_calcu(credit_sum* _score,apply_score_prop* _info
	,event_wgt* _wgt,credit_scores* _rlt,get_score_input_info* _input){
		ReadEventScores(_score);
		ReadEventWeight(_wgt);

		
		//计算
		//收入情况分值
		//数值5
		switch ( _info->input_basic_info.cust_card_type ) 
		{
		case id_card :
			_rlt->score_id_type = _score->_card_type.personal_id * _wgt->id_type ;
			break ;
		case ｍilitary_card :
			_rlt->score_id_type = _score->_card_type.soldier_id * _wgt->id_type ;
			break ;
		default :{}
			//....
		};
		//存款情况评分
		float _reg_dep = 0;
		switch(_info->input_asset_info.cust_regular_deposit){
		case deposit_none_range:{_reg_dep = _score->_time_depos_status.none;}break;
		case deposit_down_2000:{_reg_dep = _score->_time_depos_status.bellow2000;}break;
		case deposit_2000_to_5000 :{_reg_dep = _score->_time_depos_status.betw2000and4999;}break;
		case deposit_5000_to_8000:{_reg_dep = _score->_time_depos_status.betw5000and7999;}break;
		case deposit_8000_to_1w:{_reg_dep = _score->_time_depos_status.betw8000and9999;}break;
		case deposit_1w_to_2w:{_reg_dep = _score->_time_depos_status.betw10000and19999;};
		case deposit_2w_to_5w:{_reg_dep = _score->_time_depos_status.betw20000and49999;}break;
		case deposit_up_5w:{}break;
		default:{}//..
		};
		float _dem_dep = 0;
		switch(_info->input_asset_info.cust_demand_deposit){
		case deposit_none_range:{_dem_dep = _score->_demand_depos_status.none;}break;
		case deposit_down_2000:{_dem_dep = _score->_demand_depos_status.bellow2000;}break;
		case deposit_2000_to_5000 :{_dem_dep = _score->_demand_depos_status.betw2000and4999;}break;
		case deposit_5000_to_8000:{_dem_dep = _score->_demand_depos_status.betw5000and7999;}break;
		case deposit_8000_to_1w:{_dem_dep = _score->_demand_depos_status.betw8000and9999;}break;
		case deposit_1w_to_2w:{_dem_dep = _score->_demand_depos_status.betw10000and19999;}break;
		case deposit_2w_to_5w:{_dem_dep = _score->_demand_depos_status.betw20000and49999;}break;
		case deposit_up_5w:{}break; 
		};

		_rlt->score_depos = (_reg_dep + _dem_dep) * _wgt->depos;
		//分数1
		float _per_inco = 0;
		switch(_info->input_asset_info.cust_personal_annual_income){
		case pincome_down_2000:{_per_inco = _score->_per_ann_income_status.bellow2000;}break;
		case pincome_2000_to_5000:{_per_inco = _score->_per_ann_income_status.betw2000and4999;}break;
		case pincome_5000_to_8000:{_per_inco = _score->_per_ann_income_status.betw5000and8000;}break;
		case pincome_8000_to_1w:{_per_inco = _score->_per_ann_income_status.betw8000and9999;}break;
		case pincome_1w_to_15q:{_per_inco = _score->_per_ann_income_status.betw10000and14999;}break;
		case pincome_15q_to_2w:{_per_inco = _score->_per_ann_income_status.betw15000and19999;}break;
		case pincome_up_2w:{_per_inco = _score->_per_ann_income_status.above20000;}break;
		};
		float _fami_inco = 0;
		switch(_info->input_asset_info.cust_family_annual_income){
		case fincome_down_2000: {_fami_inco = _score->_fami_ann_income_status.bellow2000 ;}break;
		case fincome_up_10w: {_fami_inco = _score->_fami_ann_income_status.above100000 ;}break;
		case fincome_2000_to_5000: {_fami_inco = _score->_fami_ann_income_status.betw2000and4999 ;}break;
		case fincome_5000_to_1w: {_fami_inco = _score->_fami_ann_income_status.betw5000and9999 ;}break;
		case fincome_1w_to_3w: {_fami_inco = _score->_fami_ann_income_status.betw10000and29999 ;}break;
		case fincome_3w_to_5w: {_fami_inco = _score->_fami_ann_income_status.betw30000and49999 ;}break;
		case fincome_5w_to_10w: {_fami_inco = _score->_fami_ann_income_status.betw50000and99999;}break;
		};
		_rlt->score_income = (_per_inco + _fami_inco) * _wgt->income;
		//分数6
		float _edu = 0;
		switch(_info->input_basic_info.cust_edu){
		case edu_primary_and_below: {_edu = _score->_edu_status.primary_or_bellow; }break;
		case edu_high_school: {_edu = _score->_edu_status.senior_sch; }break;
		case edu_college: {_edu = _score->_edu_status.high_sch_or_secondary; }break;
		case edu_undergraduate: {_edu = _score->_edu_status.bachelor_or_college; }break;
		case edu_master_and_above: {_edu = _score->_edu_status.master_or_above; }break;
		};
		_rlt->score_edu = _edu * _wgt->edu;
		//分数3
		float _loan_mon = 0;
		switch(_info->input_asset_info.cust_loan_sum){
		case loan_none_range: {_loan_mon = _score->_loan_amount_status.none;}break;
		case loan_down_2000: {_loan_mon = _score->_loan_amount_status.bellow2000;}break;
		case loan_2000_to_5000: {_loan_mon = _score->_loan_amount_status.betw2000and4999;}break;
		case loan_5000_to_8000: {_loan_mon = _score->_loan_amount_status.betw5000and7999;}break;
		case loan_8000_to_1w: {_loan_mon = _score->_loan_amount_status.betw8000and9999;}break;
		case loan_1w_to_2w: {_loan_mon = _score->_loan_amount_status.betw10000and19999;}break;
		case loan_2w_to_5w: {_loan_mon = _score->_loan_amount_status.betw20000and49999;}break;
		case loan_up_5w: {_loan_mon = _score->_loan_amount_status.above50000;}break;
		};
		float _loan_time = 0;
		switch(_info->input_asset_info.cust_loan_time){
		case apply_time_none:{_loan_time = _score->_remaining_repayment_months.none;}break;
		case apply_time_down_6m:{_loan_time = _score->_remaining_repayment_months.bellow6;}break;
		case apply_time_6m_to_12m:{_loan_time = _score->_remaining_repayment_months.betw6and11;}break;
		case apply_time_12m_to_24m:{_loan_time = _score->_remaining_repayment_months.betw12and23;}break;
		case apply_time_up_24m:{_loan_time = _score->_remaining_repayment_months.above23;}break;
		};
		_rlt->score_loan_record = (_loan_mon + _loan_time) * _wgt->loan_record;
		//分数四
		float _fixed_ass = 0;
		switch(_info->input_asset_info.is_has_fixed_asset)
		{
		case true :{_fixed_ass = _score->_fixed_assets_be_pledged.no;}break;
		case false:{_fixed_ass = _score->_fixed_assets_be_pledged.yes;}break;
		};
		_rlt->score_fixed_assets_be_pledged = _wgt->fixed_assets_be_pledged * _fixed_ass;
		//分数7
		float _mar;
		if(_info->input_fammily_info.cust_marital_status == not_married){
			_mar = _score->_marital_status.married * 2;
		}
		else{
			float _mar_stu = 0;
			switch(_info->input_fammily_info.cust_marital_status){
			case divorced:{_mar_stu = _score->_marital_status.divorced;}break;
			case spouse_die:{_mar_stu = _score->_marital_status.widowed;}break;
			case not_married:{_mar_stu = _score->_marital_status.unmarried;}break;
			};
			float _mar_type = 0;
			switch(_info->input_fammily_info.cust_apouse_card_type){
			case id_card:{_mar_type = _score->_spouse_card_type.personal_id;}break;
			case ｍilitary_card:{_mar_type = _score->_spouse_card_type.soldier_id;}break;
			};
			float _mar_edu = 0;
			switch(_info->input_fammily_info.cust_spouse_edu_degree){
			case edu_primary_and_below:{_mar_edu = _score->_spouse_edu_status.primary_or_bellow;}break;
			case edu_high_school:{_mar_edu = _score->_spouse_edu_status.senior_sch;}break;
			case edu_college:{_mar_edu = _score->_spouse_edu_status.high_sch_or_secondary;}break;
			case edu_undergraduate:{_mar_edu = _score->_spouse_edu_status.bachelor_or_college;}break;
			case edu_master_and_above:{_mar_edu = _score->_spouse_edu_status.master_or_above;}break;
			};
			float _mar_loan = 0;
			switch(_info->input_fammily_info.does_cust_spouse_has_loan){
			case true:{_mar_loan = _score->_spouse_has_loan.yes;}break;
			case false:{_mar_loan = _score->_spouse_has_loan.no;}break;
			};
			_mar = (_mar_stu + _mar_type + _mar_edu + _mar_loan) * _wgt->marriage;
		}
		
		//分数10
		float _industry = _wgt->auditor_edit * _score->_fixed_assets_not_be_pledged.weight
			* _input->add_on_asset_score
			+ _score->_income_stability.weight * _input->add_on_work_score;
		_rlt->score_auditor_edit = _industry;
		
		//分数9
		_rlt->score_bad_social_record = _wgt->social_record * _input->add_on_society_score;
}

//11.4
void get_score_save_score(credit_scores* _rlt){
		SaveScores2DB(_rlt,_rlt->card_id) ;
}

//11.5

void get_score_convert_rlt(get_score_info* _info,char* _rlt,int* _rlt_len){
	*_rlt_len = sizeof(get_score_info);
	memcpy(_rlt,_info,*_rlt_len);
}

//模块11主函式
void get_score_frame(const char* _cmd , int _cmd_len, char* _rlt,int* _rlt_len){
	//11.1
	get_score_modle* _frame
		= (get_score_modle*)malloc(sizeof(get_score_modle));
	//11.2
//	_frame->
}