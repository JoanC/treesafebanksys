#include "stdafx.h"
#include "sys_credit_compute.h"

bool ModifyParam(credit_sum *_tar)
{
	FILE *pFile = NULL ;
	pFile = fopen(filename,"wt") ;

	if( ! pFile )
	{
		printf("can not open %s",filename) ;
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

	fclose(pFile) ;

	return true ; 
}

bool ReadParam(credit_sum *_tar)
{
	FILE *pFile = NULL ;
	pFile = fopen(filename,"rt") ;

	if( ! pFile )
	{
		printf("can not open %s",filename) ;
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
	
	return true ;
}