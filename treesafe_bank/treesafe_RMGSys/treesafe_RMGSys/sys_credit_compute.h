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
	float senior_sch ; // ����
	float primary_or_bellow ;				//���м�����
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
	float senior_sch  ;
	float primary_or_bellow ;				//����
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

typedef  credit_scores_db credit_scores ;

const char filename[] = "ini.txt" ;
const char filename_wgt[] = "event_wgt.txt" ; 

/*********************************************************************************************************
** Function name:			SaveEventScores
**
** Descriptions:			save event scores
**
** input parameters:	    credit_sum* _tar -------------------- save info
** Returned value:		    bool 
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-11
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool SaveEventScores(credit_sum *_tar) ;

/*********************************************************************************************************
** Function name:			ReadEventScores
**
** Descriptions:			read event scores
**
** input parameters:	    credit_sum* _tar -------------------- credit info
** Returned value:		    bool
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-11
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	ReadEventScores(credit_sum *_tar) ;

/*********************************************************************************************************
** Function name:			SaveEventWeight
**
** Descriptions:			save event weigths
**
** input parameters:	    event_wgt* _tar -------------------- event weight
** Returned value:		    bool
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-11
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool SaveEventWeight(event_wgt *_tar) ;

/*********************************************************************************************************
** Function name:			ReadEventWeight
**
** Descriptions:			read event weigths
**
** input parameters:	    event_wgt* _tar -------------------- event weight
** Returned value:		    bool
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-11
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool ReadEventWeight(event_wgt *_tar) ;

/*********************************************************************************************************
** Function name:			SaveScores2DB
**
** Descriptions:			save score to database
**
** input parameters:	    credit_scores* _Scores -------------------- event scores
**                          const char* _UserID ----------------------- user ID
** Returned value:		    bool
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-11
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool SaveScores2DB(credit_scores *_Scores,const char *_UserID) ;

/*********************************************************************************************************
** Function name:			ReadScoresFromsDB
**
** Descriptions:			read score from database
**
** input parameters:	    const char* _UserID -------------------- user ID
** Returned value:		    bool
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-11
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool ReadScoresFromDB(const char *_UserID) ;