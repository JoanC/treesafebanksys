#pragma once
#include "database_mgr.h"

struct card_type  //����֤������
{
	float 	personal_id ;		//���֤
	float 	soldier_id ;		//����֤
}	;
struct edu_status			//�ܽ������
{
	float master_or_above ; //˶ʿ������
	float bachelor_or_college ; //ѧʿ���ר
	float high_sch_or_secondary ; //���л���ר
	float bellow ;				//���м�����
};
///////////////////////////////////////////
///////////////////////////////////////////income
struct per_ann_income_status //����������
{
	float above20000 ;
	float betw15000and19999 ;
	float betw10000and14999 ;
	float betw8000and9999 ;
	float betw5000and8000 ;
	float betw2000and4999 ;
	float bellow2000 ; 
};
struct fami_ann_income_status //��ͥ������
{
	float above100000 ;
	float betw50000and99999 ;
	float betw30000and49999 ;
	float betw10000and29999 ;
	float betw5000and9999 ;
	float betw2000and4999 ;
	float bellow2000 ;
};

//////////////////////////////////////////
//////////////////////////////////////////deposits
struct time_depos_status  //���ڴ��
{
	float above50000 ;
	float betw20000and49999 ;
	float betw10000and19999 ;
	float betw8000and9999 ;
	float betw5000and7999 ;
	float betw2000and4999 ;
	float bellow2000 ;
	float none ;
};
struct demand_depos_status // ���ڴ��
{
	float above50000 ;
	float betw20000and49999 ;
	float betw10000and19999 ;
	float betw8000and9999 ;
	float betw5000and7999 ;
	float betw2000and4999 ;
	float bellow2000 ;
	float none ;
};
///////////////////////////////////////////
///////////////////////////////////////////loan
struct loan_amount_status  // �����ܶ�
{
	float none ;
	float bellow2000 ;
	float betw2000and4999 ;
	float betw5000and7999 ;
	float betw8000and9999 ;
	float betw10000and19999 ;
	float betw20000and49999 ;
	float above50000 ;
};
struct remaining_repayment_months // ����ʣ������
{
	float none ;
	float bellow6 ;
	float betw6and11 ;
	float betw12and23 ;
	float above23 ;
};
struct fixed_assets_be_pledged  // �Ƿ����ѵ�Ѻ�Ĺ̶��ʲ�
{
	float yes ;
	float no ;
};
struct fixed_assets_not_be_pledged
{
	float weight ;
};
struct income_stability
{
	float weight ;
} ;
struct bad_social_record
{
	float weight ;
} ;
struct marital_status      //����״��
{
	float married ;				//�ѻ�
	float unmarried ;			//δ��
	float divorced ;			//����
	float widowed ;				//ɥż
};
struct spouse_card_type    //��ż֤������
{
	float personal_id ;		//���֤
	float soldier_id ;		//����֤
} ;
struct spouse_edu_status  //��ż�ܽ����̶�
{
	float master_or_above ; //˶ʿ������
	float bachelor_or_college ; //ѧʿ���ר
	float high_sch_or_secondary ; //���л���ר
	float bellow ;				//���м�����
} ;
struct spouse_has_loan
{
	float yes ;
	float no ;
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
	spouse_has_loan							_spouse_has_loan ;
	income_stability							_income_stability ;
	bad_social_record						_bad_social_record ;
} ;

struct event_wgt
{
	float income ;
	float depos ;
	float repayment ;
	float fixed_assets_be_pledged ;
	float id_type ;
	float edu ;
	float marriage ;
	float loan_record ;
	float social_record ;
	float auditor_edit ;
} ;


struct credit_cust_info
{
	APPLY_CARD_TYPE ct ;
	APPLY_CUST_EDUCATION_DEGREE edu ;
	APPLY_PERSON_INCOME_RANGE pin ;
	APPLY_FAMILY_INCOME_RANGE fin ;
	APPLY_DEPOSIT_TYPE dt ;
	APPLY_DEPOSIT_RANGE depos ;
	APPLY_LOAN_RANGE lr ;
	APPLY_LOAN_TIME lt ;
	bool b_fixed_assets_be_pledged ;
	APPLY_UNSECURED_FIXED_ASSETS ufa ;
	APPLY_CUST_MARITAL_STATUS cms ;
	APPLY_CARD_TYPE sct ;
	APPLY_CUST_EDUCATION_DEGREE sedu ;
	bool Sloan ;

} ;

typedef  credit_scores_db credit_scores ;
typedef event_wgt cust_score ;

const char filename[] = "ini.txt" ;
const char filename_wgt[] = "event_wgt.txt" ; 

bool SaveEventScores(credit_sum *_tar) ;

bool	ReadEventScores(credit_sum *_tar) ;

bool SaveEventWeight(event_wgt *_tar) ;

bool ReadEventWeight(event_wgt *_tar) ;

bool SaveScores2DB(credit_scores *_Scores,const char *_UserID) ;

bool ReadScoresFromDB(const char *_UserID) ;

void score_compute(const credit_sum *_Js,const event_wgt *_Wgt,cust_score *_Outcome) ;