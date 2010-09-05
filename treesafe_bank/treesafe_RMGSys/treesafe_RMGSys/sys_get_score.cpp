#include "stdafx.h"//预编译
#include "sys_get_score.h"//分数计算



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

void release_get_score_input_info(get_score_input_info* _modle){
	free(_modle);
}

//11.3


void get_score_calcu(credit_sum* _score,event_wgt* _wgt,credit_scores* _rlt){
		ReadEventScores(_score);
		bool ReadEventWeight(_wgt);
		//计算
		//收入情况分值
		//_rlt->score_income = 
		//	_score->_per_ann_income_status. + _score->_fami_ann_income_status;
}

//11.4
void get_score_save_score(credit_scores* _rlt){

}

//11.5
void get_score_frame(const char* _cmd , int _cmd_len, char* _rlt,int* _rlt_len){

}