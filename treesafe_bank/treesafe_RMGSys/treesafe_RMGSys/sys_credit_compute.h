#pragma once
#include "database_mgr.h"



//ģ��11
//��������
//...������

struct card_type  //����֤������
{
	float 	personal_id ;		//���֤
	float 	soldier_id ;		//����֤

	float	wgt ;
}	;
struct edu_status			//�ܽ������
{
	float master_or_above ; //˶ʿ������
	float bachelor_or_college ; //ѧʿ���ר
	float high_sch_or_secondary ; //���л���ר
	float bellow ;				//���м�����

	float wgt ;
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

	float wgt ; //weight
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

	float wgt ; //weight
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

	float wgt ;   // weight
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

	float wgt ; //weight
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

	float wgt ;		//weight
};
struct remaining_repayment_months // ����ʣ������
{
	float none ;
	float bellow6 ;
	float betw6and11 ;
	float betw12and23 ;
	float above23 ;

	float wgt ; //weight
};
struct fixed_assets_be_pledged  // �Ƿ����ѵ�Ѻ�Ĺ̶��ʲ�
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
struct marital_status      //����״��
{
	float married ;				//�ѻ�
	float unmarried ;			//δ��
	float divorced ;			//����
	float widowed ;				//ɥż

	float wgt ;
};
struct spouse_card_type    //��ż֤������
{
	float personal_id ;		//���֤
	float soldier_id ;		//����֤

	float wgt ;
} ;
struct spouse_edu_status  //��ż�ܽ����̶�
{
	float master_or_above ; //˶ʿ������
	float bachelor_or_college ; //ѧʿ���ר
	float high_sch_or_secondary ; //���л���ר
	float bellow ;				//���м�����

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