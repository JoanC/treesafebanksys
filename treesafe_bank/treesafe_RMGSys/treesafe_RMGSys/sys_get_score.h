#pragma once
#include "sys_credit_compute.h"//信用评级的工具函式
#include "sys_apply_info.h"
#include "database_mgr.h"

typedef apply_input_info apply_score_prop;


//模块11
#define GET_SCORE_ID_LEN 19

struct get_score_input_info{
	int add_on_asset_score;
	int add_on_work_score;
	int add_on_society_score; 
	int add_on_loan_score;
	char card_id[GET_SCORE_ID_LEN];
};

struct get_score_info{
	sys_err err_info;
};

struct get_score_modle{
	get_score_input_info input_info;
	get_score_info rlt_info;
	apply_score_prop prop;
	credit_sum basic_score;
	event_wgt wgr;
	credit_scores rlt_score;
};

/***********************************/
//初始化模块结构
//11.1

/*********************************************************************************************************
** Function name:			init_get_scores_input_info
**
** Descriptions:			initialize input info
**
** input parameters:	    get_score_input_info* _init -------------------- scores input info
** Returned value:		    bool
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-20
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void init_get_score_input_info(get_score_input_info* _init);

/*********************************************************************************************************
** Function name:			init_get_scores_info
**
** Descriptions:			initialize score info
**
** input parameters:	    get_score_info* _init -------------------- scores info
** Returned value:		    NILL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-20
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void init_get_score_info(get_score_info* _init);

/*********************************************************************************************************
** Function name:			init_get_scores_info
**
** Descriptions:			initialize score info
**
** input parameters:	    get_score_info* _init -------------------- scores info
** Returned value:		    get_score_modle -------------------------- get score modle
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-20
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
get_score_modle* init_get_score_info();

/*********************************************************************************************************
** Function name:			release_get_scores_info
**
** Descriptions:			release score info
**
** input parameters:	    get_score_modle* _modle -------------------- get scores modle
** Returned value:		    NILL
**         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-20
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void release_get_score_modle(get_score_modle* _modle);
/***********************************/
//11.2
//获取指令信息
/*********************************************************************************************************
** Function name:			get_score_copy_cmd
**
** Descriptions:			copy command
**
** input parameters:	    const char* _cmd -------------------- source stirng
** Returned value:		    char* _dest ------------------------- dest string
**                          int _cmd_lent ----------------------- command length         
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-20
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void get_score_copy_cmd(const char* _cmd,char* _dest,int _cmd_len);

/*********************************************************************************************************
** Function name:			init_get_scores_info
**
** Descriptions:			initialize score info
**
** input parameters:	    char* _info -------------------- scores info
** Returned value:		    get_score_input_info --------------------- score input info
**                          get_score_get_cmd ------------------------ command
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-20
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
get_score_input_info* get_score_convert_cmd(char* _info);

/*********************************************************************************************************
** Function name:			get_scores_input_info
**
** Descriptions:			get input info
**
** input parameters:	    const char* _cmd-------------------- command
**                          int _cmd_Len ----------------------- command length
** Returned value:		    get_score_input_info --------------------- score input info
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-20
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
get_score_input_info* get_score_get_cmd(const char* _cmd,int _cmd_len);

/***********************************/
//11.3
//计算结果 
//获取申请人数据
/*********************************************************************************************************
** Function name:			get_scores_get_apply_info
**
** Descriptions:			get apply info
**
** input parameters:	    char* _id -------------------- users info
** Returned value:		    apply_score_prop* _info--------------------- score property
** Used global variables:	bool
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-20
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
 bool get_score_get_apply_info(char* _id , apply_score_prop* _info);

 //计算出数据结果
 /*********************************************************************************************************
** Function name:			init_get_scores_info
**
** Descriptions:			initialize score info
**
** input parameters:	    credit_sum* _score ---------------------- creadit summery
**                          apply_score_prop* _info ----------------- score property
**                          event_wgt* _wgt ------------------------- event wgt
**                          credit_scores* _rlt --------------------- credit socres
**                          get_score_input_info* _input ------------ input info
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Jiraiya
** Created Date:			2010-7-20
**-------------------------------------------------------------------------------------------------------
** Modified by:				Jiraiya
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void get_score_calcu(credit_sum* _score,apply_score_prop* _info
	,event_wgt* _wgt,credit_scores* _rlt,get_score_input_info* _input);

/************************************/
//11.4
//将计算出来的分数填入数据库中
 /*********************************************************************************************************
** Function name:			get_score_save_score
**
** Descriptions:			save score
**
** input parameters:	    credit_scores* _rlt ---------------------- the result of save
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				Sunni
** Created Date:			2010-7-20
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void get_score_save_score(credit_scores* _rlt);

/*************************************/
//11.5
 /*********************************************************************************************************
** Function name:			get_scores_convert_rlt
**
** Descriptions:			convert result
**
** input parameters:	    get_score_info* _score ---------------------- score info
**                          char* _rlt ---------------------- result
**                          int* _rlt_len ---------------------- result length
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-20
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void get_score_convert_rlt(get_score_info* _info,char* _rlt,int* _rlt_len);

//11.6
//模块11主函式
 /*********************************************************************************************************
** Function name:			get_scores_frame
**
** Descriptions:			get socre main frame
**
** input parameters:	    const char* _cmd ---------------- command
**                          int _cmd_len -------------------- command length
**                          char* _rlt ---------------------- result
**                          int* _rlt_len ------------------- result length
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-20
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-29
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void get_score_frame(const char* _cmd , int _cmd_len, char* _rlt,int* _rlt_len);