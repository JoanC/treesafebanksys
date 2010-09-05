#pragma once

//#include "sys_employee_query.h"
//数据库总管理函数
//为所有模块提供接口
//以表(table)为基础设计struct的结构
#include "sys_db_struct.h"
#include<stdio.h>
#include<conio.h>
#include "sys_error_compute.h"//错误处理
#import "C:\\Program Files\\Common Files\\System\\ado\\msado25.tlb" no_namespace rename("EOF","rsEOF")

#define PWD_LEN 16
#define REG_MAX_USER_NAME 19
#define REG_MAX_REAL_USER_NAME 51
#define REG_MAX_USER_PWD 16
#define REG_MAX_USER_BANK_ID 19//十八位身份证号,加'\0'19
#define REG_MAX_ADDR 64//联系地址
#define REG_MAX_OTHER_STR_LEN 256
#define REG_MAX_PHONE_NUM_LEN 12

typedef char REG_USER_NAME;
typedef char REG_USER_PWD;
typedef char REG_USER_ID;
enum REG_GENDER_TYPE{reg_info_male , reg_info_female};


struct reg_basic_info{
	//性别
	REG_GENDER_TYPE reg_gender;
	//年龄
	int reg_age;
	//家庭住址
	//身份证号,18位
	REG_USER_ID reg_id[REG_MAX_USER_BANK_ID];
	//REG_USER_ID reg_name[REG_MAX_USER_NAME];
	//用户密码
	REG_USER_PWD reg_pwd[REG_MAX_USER_PWD];
	//用户真实姓名
	char reg_basic_user_name[REG_MAX_REAL_USER_NAME];
	char reg_phone_num[REG_MAX_PHONE_NUM_LEN] ;
	char reg_home_addr[REG_MAX_ADDR];
};

struct reg_input_info{
	//用户注册所输入的相关信息
	//其它的附加信息
	char email_addr[REG_MAX_ADDR];
    //密码两次验证是否正确
	bool is_pwd_vry_crr;
	//输入基本信息
	reg_basic_info basic_info;
};


const char CSFileName[] = "ConnStrs.txt" ;
const size_t connStrLen = 241  ; // max 3 lines
 /*********************************************************************************************************
** Function name:			getIP
**
** Descriptions:			get server IP from file
**
** input parameters:	    NULL
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
char *	GetIP() ;

 /*********************************************************************************************************
** Function name:			GetConnStr
**
** Descriptions:			get connect string
**
** input parameters:	    int index = the index of file
**                          char *outcome = outcome
** Returned value:		    NULL
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool GetConnStr(int index,char *outcome) ;

 /*********************************************************************************************************
** Function name:			ConnectDB
**
** Descriptions:			connect to database
**
** input parameters:	    _ConnectionPtr *pConn
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool ConnectDB(_ConnectionPtr *pConn) ;

 /*********************************************************************************************************
** Function name:			DisConnectDB
**
** Descriptions:			disconnect to database
**
** input parameters:	    _ConnectionPtr *pConn
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void DisconnectDB(_ConnectionPtr *pConn) ;

 /*********************************************************************************************************
** Function name:			ConvertVar2CharStr
**
** Descriptions:			convert variable to char
**
** input parameters:	    _variatnt_t *_Vt
**                          char *_Dst
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool ConvertVar2CharStr(_variant_t *_Vt , char *_Dst) ;

 /*********************************************************************************************************
** Function name:			ConvertVar2Int
**
** Descriptions:			convert variable to int
**
** input parameters:	    _variatnt_t *_Vt
**                          int* _Dst
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool ConvertVar2Int(_variant_t *_Vt , int *_Dst) ;

 /*********************************************************************************************************
** Function name:			ConvertVar2Bool
**
** Descriptions:			convert variable to bool
**
** input parameters:	    _variatnt_t *_Vt
**                          bool* _Dst
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool ConvertVar2Bool(_variant_t *_Vt , bool *_Dst) ;

 /*********************************************************************************************************
** Function name:			ConvertVar2Float
**
** Descriptions:			convert variable to float
**
** input parameters:	    _variatnt_t *_Vt
**                          float* _Dst
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-1
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-3
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool ConvertVar2Float(_variant_t *_Vt,float *_Dst) ;

 /*********************************************************************************************************
** Function name:			Password_inquiry
**
** Descriptions:			inquiry psw
**
** input parameters:	    _ConnectionPtr* _pConn
**                          char *user_name
**                          char *pwd_rlt
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-5
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-8
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	Password_inquiry(_ConnectionPtr *_pConn,char *user_name , char *pwd_rlt) ;

 /*********************************************************************************************************
** Function name:			Summery_inquiry
**
** Descriptions:			inquiry summery
**
** input parameters:	    _ConnectionPtr* _pConn
**                          char *user_name
**                          sys_db_login *user_info
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-5
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-8
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	Summery_inquiry(_ConnectionPtr *_pConn,char *user_name,sys_db_login *user_info) ;

 /*********************************************************************************************************
** Function name:			add_new_to_tab_login
**
** Descriptions:			add new row to table login
**
** input parameters:	    _ConnectionPtr* _pConn
**                          reg_input_info
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-5
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-8
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	add_new_to_Tab_Login(_ConnectionPtr *_pConn,reg_input_info *_reg_info) ;

 /*********************************************************************************************************
** Function name:			add_new_to_tab_Cust
**
** Descriptions:			add new row to table cust
**
** input parameters:	    _ConnectionPtr* _pConn
**                          reg_input_info *_req_info
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-5
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-8
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	add_new_to_Tab_Cust(_ConnectionPtr *_pConn,reg_input_info *_reg_info) ;

 /*********************************************************************************************************
** Function name:			add_new_employee
**
** Descriptions:			add new row to table employee
**
** input parameters:	    _ConnectionPtr* _pConn
**                          admin_employee_info *emp_info
**                          char *_comment
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-5
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-8
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	add_new_employee(_ConnectionPtr *_pConn,admin_employee_info *emp_info,char *_comment) ;

 /*********************************************************************************************************
** Function name:			delete_employee
**
** Descriptions:			delete row from table employee
**
** input parameters:	    _ConnectionPtr* _pConn
**                          const char* employee_id
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-5
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-8
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool delete_employee(_ConnectionPtr *_pConn,const char *employee_id) ;

 /*********************************************************************************************************
** Function name:			apply_cust_info_query
**
** Descriptions:			query cust info
**
** input parameters:	    _ConnectionPtr* _pConn
**                          apply_customr_info* _rlt
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-7
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-7
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	Apply_cust_info_query(_ConnectionPtr *_pConn,apply_custmor_info* _rlt) ;
	//for 7.3
 /*********************************************************************************************************
** Function name:			IsACharNumber
**
** Descriptions:			is a char number
**
** input parameters:	    char ch
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-7
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-7
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool IsACharNumber(char ch) ;
	// for 7.5
 /*********************************************************************************************************
** Function name:			IncreaseCharStr
**
** Descriptions:			increase char 
**
** input parameters:	    char *_Dst
**                          size_t _nLen
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-7
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-7
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool IncreaseCharStr(char *_Dst,size_t _nLen) ; // '1' == 49 , nLen is not include '\0'
	// for 7.5
 /*********************************************************************************************************
** Function name:			FindMaxAppID
**
** Descriptions:			find max apply ID
**
** input parameters:	    _ConnectionPtr *_pConn
**                          char * _appID
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-7
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-7
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	FindMaxAppID(_ConnectionPtr *_pConn,char * _appID) ;
	// for 7.5
 /*********************************************************************************************************
** Function name:			FindMaxAppID
**
** Descriptions:			find max apply ID
**
** input parameters:	    _ConnectionPtr *_pConn
**                          char * _appID
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-7
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-7
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool Insert_app_cust_info(_ConnectionPtr *_pConn,const apply_custmor_info *_info) ;
	//for 7.5
 /*********************************************************************************************************
** Function name:			Insert_app_asset_info
**
** Descriptions:			insert apply asset ino
**
** input parameters:	    _ConnectionPtr *_pConn
**                          connst apply_cust_asset_info *_info
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-7
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-7
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	Insert_app_asset_info(_ConnectionPtr *_pConn,const apply_cust_asset_info *_info) ;
	//for 7.5
 /*********************************************************************************************************
** Function name:			Insert_app_cust_fami_info
**
** Descriptions:			insert apply cust family info
**
** input parameters:	    _ConnectionPtr *_pConn
**                          connst apply_cust_family_info *_info
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-7
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-7
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool	Insert_app_cust_fami_info(_ConnectionPtr *_pConn,const apply_cust_family_info *_info) ;
	//for 7.5
 /*********************************************************************************************************
** Function name:			Insert_app_cust_fami_info
**
** Descriptions:			insert apply cust family info
**
** input parameters:	    _ConnectionPtr *_pConn
**                          connst apply_cust_family_info *_info
** Returned value:		    bool
** Used global variables:	NULL
** Calling modules:			NULL
**
** Created by:				sunni
** Created Date:			2010-7-7
**-------------------------------------------------------------------------------------------------------
** Modified by:				Sunni
** Modified date:			2010-7-7
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
bool Insert_app_cust_loan_info(_ConnectionPtr *_pConn,const apply_loan_info *_info) ;
	//for 7.5
bool Insert_app_id_set(_ConnectionPtr *_pConn,const char *_app_id) ;
	// for 7.5 new!!!
bool Insert_app_pass_and_comment(_ConnectionPtr *_pConn,const char *_app_id) ;
	// for 7.5 new!!!
bool Update_app_id_set(_ConnectionPtr *_pConn,const research_commit_input_info *_info) ;
	//for 9.3
bool Update_app_pass_and_comment(_ConnectionPtr *_pConn,const research_commit_input_info *_info) ;
	//for 9.3
bool Get_app_cust_info(_ConnectionPtr *_pConn,apply_input_info *_info) ;
	//for 18.3
bool Get_app_asset_info(_ConnectionPtr *_pConn,apply_input_info *_info) ;
	//for 18.3
bool Get_app_cust_fami_info(_ConnectionPtr *_pConn,apply_input_info *_info) ;
	//for 18.3
bool Get_app_cust_loan_info(_ConnectionPtr *_pConn,apply_input_info *_info) ;
	//for 18.3
bool Find_app_id_be_not_verified(_ConnectionPtr *_pConn, char *_outcome) ;
//FOR 8.3	
bool Get_emplo_info_by_work_id(_ConnectionPtr *_pConn,admin_employee_info *_info) ;
 //for 19.3
bool Get_emplo_info_by_card_id(_ConnectionPtr *_pConn,admin_employee_info *_info) ;

bool Insert_credit_scores(_ConnectionPtr *_pConn,const credit_scores_db *_Scores,const char *_UserID) ;

bool Update_credit_scores(_ConnectionPtr *_pConn,const credit_scores_db *_Scores,const char *_UserID) ;

bool Get_credit_scores(_ConnectionPtr *_pConn,credit_scores_db *_Scores,const char *_UserID) ;

bool Find_how_many_passed_user(_ConnectionPtr *_pConn,int *_Outcome) ;

bool Find_all_passed_user(_ConnectionPtr *_pConn,user_query_array_info *_info,size_t _Size) ;

bool Find_specific_user(_ConnectionPtr *_pConn,user_query_info *_info,const char *_ID) ;