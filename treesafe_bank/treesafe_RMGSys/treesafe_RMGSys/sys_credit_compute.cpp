#include "stdafx.h"
#include "sys_credit_compute.h"
extern _ConnectionPtr *treesafe_db_connection ; 

bool SaveEventScores(credit_sum *_tar)
{
	FILE *pFile = NULL ;
	pFile = fopen(filename,"wt") ;

	if( ! pFile )
	{
		printf("can not open %s\n",filename) ;
		return false ;
	}

	fwrite(&_tar->_card_type,sizeof(float),sizeof(card_type)/sizeof(float),pFile) ;
	fwrite(&_tar->_edu_status,sizeof(float),sizeof(edu_status)/sizeof(float),pFile) ;
	fwrite(&_tar->_per_ann_income_status,sizeof(float),sizeof(per_ann_income_status)/sizeof(float),pFile) ;
	fwrite(&_tar->_fami_ann_income_status,sizeof(float),sizeof(fami_ann_income_status)/sizeof(float),pFile) ;
	fwrite(&_tar->_time_depos_status,sizeof(float),sizeof(time_depos_status)/sizeof(float),pFile) ;
	fwrite(&_tar->_demand_depos_status,sizeof(float),sizeof(demand_depos_status)/sizeof(float),pFile) ;
	fwrite(&_tar->_loan_amount_status,sizeof(float),sizeof(loan_amount_status)/sizeof(float),pFile) ;
	fwrite(&_tar->_remaining_repayment_months,sizeof(float),sizeof(remaining_repayment_months)/sizeof(float),pFile) ;
	fwrite(&_tar->_fixed_assets_be_pledged,sizeof(float),sizeof(fixed_assets_be_pledged)/sizeof(float),pFile) ;
	fwrite(&_tar->_fixed_assets_not_be_pledged,sizeof(float),sizeof(fixed_assets_not_be_pledged)/sizeof(float),pFile) ;
	fwrite(&_tar->_marital_status,sizeof(float),sizeof(marital_status)/sizeof(float),pFile) ;
	fwrite(&_tar->_spouse_card_type,sizeof(float),sizeof(spouse_card_type)/sizeof(float),pFile) ;
	fwrite(&_tar->_spouse_edu_status,sizeof(float),sizeof(spouse_edu_status)/sizeof(float),pFile) ;
	fwrite(&_tar->_spouse_has_loan,sizeof(float),sizeof(spouse_has_loan)/sizeof(float),pFile) ;
	fwrite(&_tar->_income_stability,sizeof(float),sizeof(income_stability)/sizeof(float),pFile) ;
	fwrite(&_tar->_bad_social_record,sizeof(float),sizeof(bad_social_record)/sizeof(float),pFile) ;

	fclose(pFile) ;

	return true ; 
}

bool ReadEventScores(credit_sum *_tar)
{
	FILE *pFile = NULL ;
	pFile = fopen(filename,"rt") ;

	if( ! pFile )
	{
		printf("can not open %s\n",filename) ;
		return false ;
	}
		
	fread(&_tar->_card_type,sizeof(float),sizeof(card_type)/sizeof(float),pFile) ;
	fread(&_tar->_edu_status,sizeof(float),sizeof(edu_status)/sizeof(float),pFile) ;
	fread(&_tar->_per_ann_income_status,sizeof(float),sizeof(per_ann_income_status)/sizeof(float),pFile) ;
	fread(&_tar->_fami_ann_income_status,sizeof(float),sizeof(fami_ann_income_status)/sizeof(float),pFile) ;
	fread(&_tar->_time_depos_status,sizeof(float),sizeof(time_depos_status)/sizeof(float),pFile) ;
	fread(&_tar->_demand_depos_status,sizeof(float),sizeof(demand_depos_status)/sizeof(float),pFile) ;
	fread(&_tar->_loan_amount_status,sizeof(float),sizeof(loan_amount_status)/sizeof(float),pFile) ;
	fread(&_tar->_remaining_repayment_months,sizeof(float),sizeof(remaining_repayment_months)/sizeof(float),pFile) ;
	fread(&_tar->_fixed_assets_be_pledged,sizeof(float),sizeof(fixed_assets_be_pledged)/sizeof(float),pFile) ;
	fread(&_tar->_fixed_assets_not_be_pledged,sizeof(float),sizeof(fixed_assets_not_be_pledged)/sizeof(float),pFile) ;
	fread(&_tar->_marital_status,sizeof(float),sizeof(marital_status)/sizeof(float),pFile) ;
	fread(&_tar->_spouse_card_type,sizeof(float),sizeof(spouse_card_type)/sizeof(float),pFile) ;
	fread(&_tar->_spouse_edu_status,sizeof(float),sizeof(spouse_edu_status)/sizeof(float),pFile) ;
	fread(&_tar->_spouse_has_loan,sizeof(float),sizeof(spouse_has_loan)/sizeof(float),pFile) ;
	fread(&_tar->_income_stability,sizeof(float),sizeof(income_stability)/sizeof(float),pFile) ;
	fread(&_tar->_bad_social_record,sizeof(float),sizeof(bad_social_record)/sizeof(float),pFile) ;

	fclose(pFile) ;
	return true ;
}

bool SaveEventWeight(event_wgt *_tar) 
{
	FILE *pFile = NULL ;
	pFile = fopen(filename,"wt") ;

	if( ! pFile )
	{
		printf("can not open %s\n",filename) ;
		return false ;
	}

	fwrite(_tar,sizeof(float),sizeof(event_wgt)/sizeof(float),pFile) ;

	fclose(pFile) ;
	return true ;
}

bool ReadEventWeight(event_wgt *_tar) 
{
		FILE *pFile = NULL ;
	pFile = fopen(filename,"rt") ;

	if( ! pFile )
	{
		printf("can not open %s\n",filename) ;
		return false ;
	}

	fread(_tar,sizeof(float),sizeof(event_wgt)/sizeof(float),pFile) ;

	fclose(pFile) ;
	return true ;
}

bool SaveScores2DB(credit_scores *_Scores,const char *_UserID) 
{
	return Insert_credit_scores(treesafe_db_connection,_Scores,_UserID) ;
}

bool ReadScoresFromDB(credit_scores *_Scores,const char *_UserID)
{
	return Get_credit_scores(treesafe_db_connection,_Scores,_UserID) ;
}

void score_compute(const credit_sum *_Js,const event_wgt *_Wgt,cust_score *_Outcome)
{

}