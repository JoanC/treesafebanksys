#pragma once
#include "database_mgr.h"



//模块11
//信用评级
//...待讨论

struct card_type  //申请证件类型
{
	float 	personal_id ;		//身份证
	float 	soldier_id ;		//军人证

	float	wgt ;
}	;
struct edu_status			//受教育情况
{
	float master_or_above ; //硕士及以上
	float bachelor_or_college ; //学士或大专
	float high_sch_or_secondary ; //高中或中专
	float bellow ;				//初中及以下

	float wgt ;
};
///////////////////////////////////////////
///////////////////////////////////////////income
struct per_ann_income_status //个人年收入
{
	float above20000 ;
	float betw15000and19999 ;
	float betw10000and14999 ;
	float betw8000and9999 ;
	float betw5000and8000 ;
	float betw2000and4999 ;
	float bellow2000 ; 

	float wgt ; //weight
};
struct fami_ann_income_status //家庭年收入
{
	float above100000 ;
	float betw50000and99999 ;
	float betw30000and49999 ;
	float betw10000and29999 ;
	float betw5000and9999 ;
	float betw2000and4999 ;
	float bellow2000 ;

	float wgt ; //weight
};

//////////////////////////////////////////
//////////////////////////////////////////deposits
struct time_depos_status  //定期存款
{
	float above50000 ;
	float betw20000and49999 ;
	float betw10000and19999 ;
	float betw8000and9999 ;
	float betw5000and7999 ;
	float betw2000and4999 ;
	float bellow2000 ;
	float none ;

	float wgt ;   // weight
};
struct demand_depos_status // 活期存款
{
	float above50000 ;
	float betw20000and49999 ;
	float betw10000and19999 ;
	float betw8000and9999 ;
	float betw5000and7999 ;
	float betw2000and4999 ;
	float bellow2000 ;
	float none ;

	float wgt ; //weight
};
///////////////////////////////////////////
///////////////////////////////////////////loan
struct loan_amount_status  // 贷款总额
{
	float none ;
	float bellow2000 ;
	float betw2000and4999 ;
	float betw5000and7999 ;
	float betw8000and9999 ;
	float betw10000and19999 ;
	float betw20000and49999 ;
	float above50000 ;

	float wgt ;		//weight
};
struct remaining_repayment_months // 贷款剩余月数
{
	float none ;
	float bellow6 ;
	float betw6and11 ;
	float betw12and23 ;
	float above23 ;

	float wgt ; //weight
};
struct fixed_assets_be_pledged  // 是否有已抵押的固定资产
{
	float yes ;
	float no ;

	float wgt ;
};
struct fixed_assets_not_be_pledged
{
	float yes ;
	float no ;

	float wgt ;
};
struct marital_status      //婚姻状况
{
	float married ;				//已婚
	float unmarried ;			//未婚
	float divorced ;			//离异
	float widowed ;				//丧偶

	float wgt ;
};
struct spouse_card_type    //配偶证件类型
{
	float personal_id ;		//身份证
	float soldier_id ;		//军人证

	float wgt ;
} ;
struct spouse_edu_status  //配偶受教育程度
{
	float master_or_above ; //硕士及以上
	float bachelor_or_college ; //学士或大专
	float high_sch_or_secondary ; //高中或中专
	float bellow ;				//初中及以下

	float wgt ;
} ;
struct credit_sum
{
	card_type										_card_type ;
	edu_status										_edu_status ;
	per_ann_income_status				_per_ann_income_status ;
	fami_ann_income_status				_fami_ann_income_status ;
	time_depos_status						_time_depos_status ;
	demand_depos_status					_demand_depos_status ;
	loan_amount_status						_loan_amount_status ;
	remaining_repayment_months		_remaining_repayment_months ;
	fixed_assets_be_pledged			_fixed_assets_be_pledged ;
	fixed_assets_not_be_pledged	_fixed_assets_not_be_pledged ;
	marital_status								_marital_status ;
	spouse_card_type							_spouse_card_type ;
	spouse_edu_status						_spouse_edu_status ;
} ;

const char filename[] = "ini.txt" ;

bool ModifyParam(credit_sum *_tar) ;

bool	ReadParam(credit_sum *_tar) ;