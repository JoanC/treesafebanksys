#include "stdafx.h"
#include "database_mgr.h"


bool GetConnStr(int index,char *outcome) 
{
	FILE *pFile = NULL ;
	if (fopen_s(&pFile,CSFileName,"rt") == S_OK ){
		for(int i  = 0 ; i <= index ; ++i){
			fgets(outcome,connStrLen,pFile) ;
		}
		fclose(pFile) ; 
		return true ;
	}
	else 
		return false ;
}
bool ConnectDB(_ConnectionPtr *pConn) 
{	
	char connStr[connStrLen] ;
	memset(connStr,0,connStrLen) ;

	printf("please input the index of the database you want to connect:\r\n") ;

	int index = 0 ;
	scanf("%d",&index) ;

	GetConnStr(index,connStr) ;

	::CoInitialize(0);
	pConn->CreateInstance(__uuidof(Connection));
	(*pConn)->ConnectionString = connStr ;
	(*pConn) ->ConnectionTimeout = 10 ;
	(*pConn) ->CursorLocation = adUseServer;
	//setting param...
	try{
		(*pConn) ->Open("","","",-1) ;
	}catch(...){
		return false ;
	} 
	//open it 

	//delete connStr that was newed in GetIP()
	char outputStr[] = "success to connect the database..." ;
	printf("%s\r\n",outputStr) ;

	return true ; //return success or not
}
void DisconnectDB(_ConnectionPtr *pConn) 
{
	(*pConn)->Close();
	pConn->Release();
	::CoUninitialize();

	char outputStr[] = "success to disconnect the database..." ;
	printf("%s\r\n",outputStr) ;
}
bool ConvertVar2CharStr(_variant_t *_Vt , char *_Dst) 
{
	if(VT_NULL == _Vt->vt){
		strcpy(_Dst,"null") ;
		return false ;
	}
	else {
		strcpy(_Dst,(char*)(_bstr_t)(*_Vt) ) ;
	}

	return true ;
}
bool ConvertVar2Int(_variant_t *_Vt , int *_Dst) 
{
	if(VT_NULL == _Vt->vt){
		*_Dst = -1 ; // err
		return false ;
	}
	else {
		*_Dst = _Vt->intVal ;
	}
	return true ;
}
bool ConvertVar2Bool(_variant_t *_Vt , bool *_Dst) 
{
	if(VT_NULL == _Vt->vt){
		return false ;
	}
	else {
		*_Dst = _Vt->boolVal ? true : false ;
	}
	return true ;
}
bool ConvertVar2Float(_variant_t *_Vt,float *_Dst) 
{
	if(VT_NULL == _Vt->vt){
		*_Dst = 0 ;
		return false ;
	}
	else {
		*_Dst = (float)_Vt->dblVal ;
	}
	return true ;
}
bool Password_inquiry(_ConnectionPtr *_pConn,char *user_name , char *pwd_rlt)
{
	_variant_t vt ;
	char sqlStr[100] = "select login_pwd from Table_Login where login_id = '" ;
	strcat(sqlStr,user_name) ;
	strcat(sqlStr,"'") ;
	_RecordsetPtr rsp;

	try{
		rsp = (*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false;
	}
	//inquiry...

	if( ! rsp->rsEOF )
	{
		_variant_t varPwd ;
		varPwd = rsp->Fields->GetItem(long(0))->Value ;
		ConvertVar2CharStr(&varPwd,pwd_rlt) ;
		rsp->Close() ;
		rsp.Release() ;
		return true ;
	}
	else
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}
}
bool	Summery_inquiry(_ConnectionPtr *_pConn,char *user_name,sys_db_login *user_info_rlt) 
{
	_variant_t vt ;
	char sqlStr[200] = "select * from Table_Login where login_id = '" ;
	strcat(sqlStr,user_name) ;
	strcat(sqlStr,"'") ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false;
	}
	// visit the db...

	_variant_t varUserID ; 
	_variant_t varCmpt ; 

	varCmpt			=	rsp->Fields->GetItem(long(2))->Value ;
	varUserID		=	rsp->Fields->GetItem(long(3))->Value ;

	if (varUserID.vt == VT_NULL)
	{
		strcpy_s(user_info_rlt->user_id , "null" ) ;
	}
	else
	{
		strcpy_s(user_info_rlt->user_id, (char *)(_bstr_t)varUserID)  ;
	}

	if (varCmpt.vt == VT_NULL)
	{
		user_info_rlt->cmpt = compe_err ;
	}
	else
	{
		user_info_rlt->cmpt = (login_competence)varCmpt.intVal  ;
	}
	rsp->Close() ;
	rsp.Release() ;

	return true ;
}
bool	add_new_to_Tab_Login(_ConnectionPtr *_pConn,reg_input_info *_reg_info) 
{
	char sqlStrTest[200] = "select login_competence from Table_Login where login_id = '" ;
	strcat(sqlStrTest,_reg_info->basic_info.reg_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;

	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}

	if( ! rsp->rsEOF ) // 如果已存在...
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}
	rsp->Close() ;
	rsp.Release() ;

	char sqlStr[200] = "insert into Table_Login values('" ;
	strcat(sqlStr,_reg_info->basic_info.reg_id) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_reg_info->basic_info.reg_pwd) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,"0") ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_reg_info->basic_info.reg_id) ;
	strcat(sqlStr,"')") ;

	_variant_t vt ;
	try{
		(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false;
	}
	return true ;
}
bool	add_new_to_Tab_Cust(_ConnectionPtr *_pConn,reg_input_info *_reg_info)
{
	char sqlStrTest[200] = "select name from Table_Cust_Info where id = '" ;
	strcat(sqlStrTest,_reg_info->basic_info.reg_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}
	if( ! rsp->rsEOF )
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}
	rsp->Close() ;
	rsp.Release() ;

	char sqlStr[300] = "insert into Table_Cust_Info values('" ;
	strcat(sqlStr,_reg_info->basic_info.reg_id) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_reg_info->basic_info.reg_basic_user_name) ;
	strcat(sqlStr,"','") ;
	char temp[6] ;
	memset(temp,0,6) ;
	itoa(_reg_info->basic_info.reg_gender,temp,10) ;
	strcat(sqlStr,temp) ;

	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	char age[4] ;
	itoa(_reg_info->basic_info.reg_age,age,10) ;
	strcat(sqlStr,age) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_reg_info->basic_info.reg_phone_num) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_reg_info->basic_info.reg_home_addr) ;
	strcat(sqlStr,"')") ;

	_variant_t vt ;
	try{
		(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false;
	}

	return true ;
}
bool	add_new_employee(_ConnectionPtr *_pConn,admin_employee_info *emp_info,char *_comment)
{
	char sqlStrTest[200] = "select employee_id from Table_Employee where employee_work_id = '" ;
	strcat(sqlStrTest,emp_info->employee_work_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr r;
	try{
		r = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}
	if( ! r->rsEOF )
	{
		r->Close() ;
		r.Release() ;
		return false ;
	}
	r->Close() ;
	r.Release() ;

	char sqlStr[500] = "insert into Table_Employee values('" ;
	strcat(sqlStr,emp_info->employee_id) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,emp_info->employee_work_id) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,emp_info->employee_name) ;
	strcat(sqlStr,"','") ;
	char temp[4]  = {0,0,0,0} ;
	itoa(emp_info->employee_gender,temp,10) ;
	strcat(sqlStr, temp ) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,4) ;
	itoa(emp_info->employee_age,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,emp_info->employee_addr) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,emp_info->employee_email) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,4) ;
	itoa(emp_info->employee_type, temp, 10 ) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_comment) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,emp_info->employee_tel) ;
	strcat(sqlStr,"')") ;

	_variant_t vt ;
	try{
		(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false;
	}
	return true ;
}
bool delete_employee(_ConnectionPtr *_pConn,const char *employee_id) 
{
	char sqlStrTest[200] = "select employee_work_id from Table_Employee where employee_id = '" ;
	strcat(sqlStrTest,employee_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}
	if( rsp->rsEOF ) //如果没这个人...
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}
	rsp->Close() ;
	rsp.Release() ;

	char sqlStr[200] = "delete from Table_Employee where employee_id = '" ;
	strcat(sqlStr,employee_id) ;
	strcat(sqlStr,"'") ;
	_variant_t vt ;

	try{
		(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false;
	}

	return true ;
}
bool	Apply_cust_info_query(_ConnectionPtr *_pConn,apply_custmor_info* _rlt)
{
	char sqlStrTest[200] = "select * from Table_Cust_Info where id = '" ;
	strcat(sqlStrTest,_rlt->cust_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t vt ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&vt,adCmdText) ;
	}
	catch(...){
		return false;
	}
	if( ! rsp->rsEOF )
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}

	_variant_t varName ;
	_variant_t varGender ;
	_variant_t varAge ;
	_variant_t varPhone ;

	varName		=		rsp->Fields->GetItem(long(1))->Value ;
	varGender	=		rsp->Fields->GetItem(long(2))->Value ;
	varAge		=		rsp->Fields->GetItem(long(3))->Value ;
	varPhone		=		rsp->Fields->GetItem(long(4))->Value ;

	if( VT_NULL == varName.vt)
	{
		return false ;
	}
	else
	{
		strcpy(_rlt->cust_name,(char *)(_bstr_t)varName) ;
	}
	if( VT_NULL == varGender.vt )
	{
		return false ;
	}
	else
	{
		_rlt->cust_gender = varGender.boolVal ? apply_info_male : apply_info_female ;
	}
	if (VT_NULL == varAge.vt )
	{
		return false ;
	}
	else 
	{
		_rlt->cust_age = varAge.intVal ;
	}
	if (VT_NULL == varPhone.vt )
	{
		return false ;
	}
	else
	{
		strcpy(_rlt->cust_tel_num,(char *)(_bstr_t)varPhone) ;
	}
	rsp->Close() ;
	rsp.Release() ;
	return true ;
}
bool IsACharNumber(char ch) 
{
	return ( ch >= 48 && ch <=  57 ) ;
}
bool IncreaseCharStr(char *_Dst,size_t _nLen) // '1' == 49 , nLen is not include '\0'
{
	for (unsigned int i = 0 ; i < _nLen ; ++i )
		if ( ! IsACharNumber(_Dst[i] ) )
			return false ;

	for (unsigned int i = _nLen-1 ; i >= 0 ; --i )
	{
		if ( ! IsACharNumber( ++_Dst[i] ) )
			_Dst[i] = '0' ;
		else
			break ;
	}
	return true ;
}
bool	FindMaxAppID(_ConnectionPtr *_pConn,char * _appID) 
{
	char sqlStr[200] = "select max(apply_id) from Table_App_ID_Set" ;

	_variant_t vt ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false;
	}
	// execute sql... 
	if( rsp->rsEOF )
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}

	_variant_t varAppID = rsp->Fields->GetItem(long(0))->Value ;
	if(VT_NULL == varAppID.vt)
	{
		return false ;
	}
	else 
	{
		strcpy(_appID,(char*)(_bstr_t)varAppID ) ;
	}
	rsp->Close() ;
	rsp.Release() ;
	return true ;
}
bool Insert_app_cust_info(_ConnectionPtr *_pConn,const apply_custmor_info *_info) 
{
	char sqlStrTest[200] = "select cust_gend from Table_App_Cust_Info where apply_id = '" ;
	strcat(sqlStrTest,_info->app_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}
	if( ! rsp->rsEOF )
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}
	char sqlStr[300] = "insert into Table_App_Cust_Info values('" ;
	strcat(sqlStr,_info->app_id) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_info->cust_name) ;
	strcat(sqlStr,"','") ;
	char temp[6] ;
	memset(temp,0,6) ;
	itoa(_info->cust_gender,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,6) ;
	itoa(_info->cust_age,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,6) ;
	itoa(_info->cust_card_type,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_info->cust_id) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_info->cust_tel_num) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_info->cust_other_tel_num) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,6) ;
	itoa(_info->cust_edu,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_info->cust_addr) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_info->cust_zip_code) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,6) ;
	itoa(_info->cust_house_type,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"')") ;

	_variant_t vt;
	try{
		(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}catch(...){
		return false ;
	}

	rsp->Close() ;
	rsp.Release() ;
	return true ;
}
bool	Insert_app_asset_info(_ConnectionPtr *_pConn,const apply_cust_asset_info *_info) 
{
	char sqlStrTest[200] = "select cust_app_indus_type from Table_App_Cust_Asset_Info where apply_id = '" ;
	strcat(sqlStrTest,_info->app_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	if( ! rsp->rsEOF )
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}

	char sqlStr[300] = "insert into Table_App_Cust_Asset_Info values('" ;
	strcat(sqlStr,_info->app_id) ;
	strcat(sqlStr,"','") ;
	char temp[15] ;
	memset(temp,0,15) ;
	itoa(_info->cust_family_annual_income,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,15) ;
	itoa(_info->cust_deposit_type,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,15) ;
	itoa(_info->cust_regular_deposit,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,15) ;
	itoa(_info->cust_demand_deposit,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_info->does_cust_have_loan == true ? "true" : "false" ) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,15) ;
	itoa(_info->cust_loan_sum,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,15) ;
	itoa(_info->cust_loan_time,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,15) ;
	itoa(_info->cust_unsecured_fixed_asset,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,15) ;
	itoa(_info->cust_industry,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_info->cust_work_unit) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_info->cust_work_pos) ;
	strcat(sqlStr,"')") ;

	_variant_t vt;
	try{
		(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false;
	}

	rsp->Close() ;
	rsp.Release() ;
	return true ;
}
bool	Insert_app_cust_fami_info(_ConnectionPtr *_pConn,const apply_cust_family_info *_info)
{
	char sqlStrTest[200] = "select cust_app_marital_status from Table_App_Cust_Fami_Info where apply_id = '" ;
	strcat(sqlStrTest,_info->app_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	if( ! rsp->rsEOF )
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}

	char sqlStr[300] = "insert into Table_App_Cust_Fami_Info values('" ;
	strcat(sqlStr,_info->app_id) ;
	strcat(sqlStr,"','") ;
	char temp[4] ;
	itoa(_info->cust_marital_status,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,4) ;
	itoa(_info->cust_children_num,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_info->cust_spouse_name) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,4) ;
	itoa(_info->cust_apouse_card_type,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_info->cust_spouse_card_id) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_info->cust_spouse_work_unit) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,4) ;
	itoa(_info->cust_spouse_edu_degree,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_info->does_cust_spouse_has_loan ? "true" : "false") ;
	strcat(sqlStr,"')") ;

	_variant_t vt;

	try{
		(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false;
	}

	rsp->Close() ;
	rsp.Release() ;
	return true ;
}
bool Insert_app_cust_loan_info(_ConnectionPtr *_pConn,const apply_loan_info *_info) 
{
	char sqlStrTest[200] = "select cust_loan_amount from Table_App_Loan_Info where apply_id = '" ;
	strcat(sqlStrTest,_info->app_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}
	if( ! rsp->rsEOF )
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}

	char sqlStr[300] = "insert into Table_App_Loan_Info values('" ;
	strcat(sqlStr,_info->app_id) ;
	strcat(sqlStr,"','") ;
	char temp[15] ;
	memset(temp,0,15) ;
	itoa(_info->loan_application_amount,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,15) ;
	itoa(_info->loan_dead_line,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,15) ;
	itoa(_info->loan_times,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_info->loan_comment) ;
	strcat(sqlStr,"','") ;
	memset(temp,0,15) ;
	itoa(_info->is_want_msg,temp,10) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"')") ;

	_variant_t vt;
	try{
		(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false;
	}

	rsp->Close() ;
	rsp.Release() ;
	return true ;
}
bool Insert_app_id_set(_ConnectionPtr *_pConn,const char *_app_id)
{
	char sqlStrTest[200] = "select apply_is_verified from Table_App_ID_Set where apply_id = '" ;
	strcat(sqlStrTest,_app_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}
	if( ! rsp->rsEOF ) //如果此id已存在...
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}
	rsp->Close() ;
	rsp.Release() ;
	char sqlStr[150] = "insert into Table_App_ID_Set values('" ;
	strcat(sqlStr,_app_id) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,"false") ;
	strcat(sqlStr,"')") ;

	try{
		_variant_t vt;
		(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}catch(...){
		return false ;
	}

	return true ;
}
bool Insert_app_pass_and_comment(_ConnectionPtr *_pConn,const char *_app_id)
{
	char sqlStrTest[200] = "select apply_asset_comment from Table_App_Pass_And_Comment where apply_id = '" ;
	strcat(sqlStrTest,_app_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}
	if( ! rsp->rsEOF )
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}

	char sqlStr[200] = "insert into Table_App_Pass_And_Comment values('" ;
	strcat(sqlStr,_app_id) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,"null") ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,"null") ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,"null") ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,"null") ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,"false") ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,"null") ;
	strcat(sqlStr,"')") ;

	try{
		_variant_t vt;
		(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}catch(...){
		return false ;
	}

	rsp->Close() ;
	rsp.Release() ;
	return true ;
}
bool Update_app_id_set(_ConnectionPtr *_pConn,const research_commit_input_info *_info) 
{
	char sqlStrTest[200] = "select apply_is_verified from Table_App_ID_Set where apply_id = '" ;
	strcat(sqlStrTest,_info->research_apply_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}
	if( rsp->rsEOF ) //如果此id不存在...
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}
	rsp->Close() ;
	rsp.Release() ;

	char sqlStr[150] = "update Table_App_ID_Set set apply_is_verified = 'true' from Table_App_ID_Set where apply_id = '" ;
	strcat(sqlStr,_info->research_apply_id) ;
	strcat(sqlStr, "'") ;
	try{
		_variant_t vt;
		(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}catch(...){
		return false ;
	}

	return true ;
}
bool Update_app_pass_and_comment(_ConnectionPtr *_pConn,const research_commit_input_info *_info) 
{
	char sqlStrTest[200] = "select apply_is_passed from Table_App_Pass_And_Comment where apply_id = '" ;
	strcat(sqlStrTest,_info->research_apply_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}
	if( rsp->rsEOF ) //如果此id不存在...
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}
	rsp->Close() ;
	rsp.Release() ;

	const char col0[] = "apply_asset_comment = '" ;
	const char col1[] = "apply_cust_comment = '" ;
	const char col2[] = "apply_fami_comment = '" ;
	const char col3[] = "apply_loan_comment = '" ;
	const char col4[] = "apply_is_passed = '" ;
	const char col5[] = "apply_researcher_work_id = '" ;
	char sqlStr[300] = "update Table_App_Pass_And_Comment set " ;

	strcat(sqlStr,col0) ;
	strcat(sqlStr,_info->asset_research_info_comment) ;
	strcat(sqlStr,"',") ;

	strcat(sqlStr,col1) ;
	strcat(sqlStr,_info->cust_research_info_comment) ;
	strcat(sqlStr,"',") ;

	strcat(sqlStr,col2) ;
	strcat(sqlStr,_info->family_research_info_comment) ;
	strcat(sqlStr,"',") ;

	strcat(sqlStr,col3) ;
	strcat(sqlStr,_info->loan_research_info_comment) ;
	strcat(sqlStr,"',") ;

	strcat(sqlStr,col4) ;
	strcat(sqlStr,_info->is_research_approved ? "true" : "false" ) ;
	strcat(sqlStr,"',") ;

	strcat(sqlStr,col5) ;
	strcat(sqlStr,_info->researcher_id) ;
	strcat(sqlStr,"' ") ;

	const char temp[] = "from Table_App_Pass_And_Comment where apply_id = '" ;

	strcat(sqlStr,temp);
	strcat(sqlStr,_info->research_apply_id) ;
	strcat(sqlStr,"'") ;

	try{
		(*_pConn)->Execute(sqlStr,&v,adCmdText) ;
	}catch(...){
		return false ;
	}
	return true ;
}
bool Get_app_cust_info(_ConnectionPtr *_pConn,apply_input_info *_info)
{
	char sqlStrTest[200] = "select * from Table_App_Cust_Info where apply_id = '" ;
	strcat(sqlStrTest,_info->input_basic_info.app_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}
	if( ! rsp->rsEOF ) //如果此id存在...
	{
		_variant_t varName ;
		_variant_t varGend ;
		_variant_t varAge ;
		_variant_t varCardType ;
		_variant_t varCardID ;
		_variant_t varPhoneNum ;
		_variant_t varOtherPhoneNum ;
		_variant_t varEdu ;
		_variant_t varAddr ;
		_variant_t varZipCode ;
		_variant_t varHouseOwnership ;

		varName						= rsp->Fields->GetItem(long(1))->Value ;
		varGend						= rsp->Fields->GetItem(long(2))->Value ;
		varAge						= rsp->Fields->GetItem(long(3))->Value ;
		varCardType				= rsp->Fields->GetItem(long(4))->Value ;
		varCardID					= rsp->Fields->GetItem(long(5))->Value ;
		varPhoneNum				= rsp->Fields->GetItem(long(6))->Value ;
		varOtherPhoneNum	= rsp->Fields->GetItem(long(7))->Value ;
		varEdu						= rsp->Fields->GetItem(long(8))->Value ;
		varAddr						= rsp->Fields->GetItem(long(9))->Value ;
		varZipCode					= rsp->Fields->GetItem(long(10))->Value ;
		varHouseOwnership	= rsp->Fields->GetItem(long(11))->Value ;

		bool bRtnVal = true ; 

		if (varName.vt == VT_NULL)
		{
			const char emptyStr[] = "null" ;
			strcpy(_info->input_basic_info.cust_name,emptyStr) ;

			bRtnVal = false ;
		}
		else
		{
			strcpy(_info->input_basic_info.cust_name, (char *)(_bstr_t)varName)  ;
		}

		ConvertVar2Int(&varGend,(int*)&_info->input_basic_info.cust_gender) ;

		if (varAge.vt == VT_NULL)
		{
			bRtnVal = false ;
		}
		else
		{
			_info->input_basic_info.cust_age = varAge.intVal ;
		}

		if (varCardType.vt == VT_NULL)
		{
			bRtnVal = false ;
		}
		else
		{
			if ( id_card == varCardType.intVal )
				_info->input_basic_info.cust_card_type = id_card ;
			else if(ｍilitary_card == varCardType.intVal)
				_info->input_basic_info.cust_card_type = ｍilitary_card ;
			else 
				bRtnVal = false ;
		}

		bRtnVal = bRtnVal && ConvertVar2CharStr(&varCardID,_info->input_basic_info.cust_id) ;

		if (varPhoneNum.vt == VT_NULL)
		{
			const char emptyStr[] = "null" ;
			strcpy(_info->input_basic_info.cust_tel_num,emptyStr) ;

			bRtnVal = false ;
		}
		else
		{
			strcpy(_info->input_basic_info.cust_tel_num, (char *)(_bstr_t)varPhoneNum)  ;
		}

		if (varOtherPhoneNum.vt == VT_NULL)
		{
			const char emptyStr[] = "null" ;
			strcpy(_info->input_basic_info.cust_other_tel_num,emptyStr) ;
		}
		else
		{
			strcpy(_info->input_basic_info.cust_other_tel_num, (char *)(_bstr_t)varOtherPhoneNum)  ;
		}

		if (varEdu.vt == VT_NULL)
		{
			bRtnVal = false ;
		}
		else
		{
			_info->input_basic_info.cust_edu = (APPLY_CUST_EDUCATION_DEGREE)varEdu.intVal ;
		}

		if (varAddr.vt == VT_NULL)
		{
			const char emptyStr[] = "null" ;
			strcpy(_info->input_basic_info.cust_addr,emptyStr) ;

			bRtnVal = false ;
		}
		else
		{
			strcpy(_info->input_basic_info.cust_addr, (char *)(_bstr_t)varAddr)  ;
		}

		if (varZipCode.vt == VT_NULL)
		{
			const char emptyStr[] = "null" ;
			strcpy(_info->input_basic_info.cust_zip_code,emptyStr) ;

			bRtnVal = false ;
		}
		else
		{
			strcpy(_info->input_basic_info.cust_zip_code, (char *)(_bstr_t)varZipCode)  ;
		}

		if (varHouseOwnership.vt == VT_NULL)
		{
			bRtnVal = false ;
		}
		else
		{
			_info->input_basic_info.cust_house_type = (APPLY_CUST_HOUSING_TENURE)varHouseOwnership.intVal ;
		}

		rsp->Close() ;
		rsp.Release() ;
		return bRtnVal ;
	}
	rsp->Close() ;
	rsp.Release() ;
	return false ;
}
bool Get_app_asset_info(_ConnectionPtr *_pConn,apply_input_info *_info) 
{
	char sqlStrTest[200] = "select * from Table_App_Cust_Asset_Info where apply_id = '" ;
	strcat(sqlStrTest,_info->input_asset_info.app_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}
	if( ! rsp->rsEOF ) //如果此id存在...
	{
		_variant_t varPAI ;
		_variant_t varDeposType ;
		_variant_t varRegDeposRang ;
		_variant_t varDemaDeposRang ;
		_variant_t varHasLoan ;
		_variant_t varLoanSum ;
		_variant_t varLoanTime ;
		_variant_t varUnsecFixedAssetType ;
		_variant_t varIndusType ;
		_variant_t varWorkUnit ;
		_variant_t varWorkPos ;

		varPAI									= rsp->Fields->GetItem(long(1))->Value ;
		varDeposType						= rsp->Fields->GetItem(long(2))->Value ;
		varRegDeposRang					= rsp->Fields->GetItem(long(3))->Value ;
		varDemaDeposRang				= rsp->Fields->GetItem(long(4))->Value ;
		varHasLoan							= rsp->Fields->GetItem(long(5))->Value ;
		varLoanSum							= rsp->Fields->GetItem(long(6))->Value ;
		varLoanTime							= rsp->Fields->GetItem(long(7))->Value ;
		varUnsecFixedAssetType	= rsp->Fields->GetItem(long(8))->Value ;
		varIndusType						= rsp->Fields->GetItem(long(9))->Value ;
		varWorkUnit							= rsp->Fields->GetItem(long(10))->Value ;
		varWorkPos							= rsp->Fields->GetItem(long(11))->Value ;

		bool bRtnVal = true ;
		if (varPAI.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_asset_info.cust_personal_annual_income = (APPLY_PERSON_INCOME_RANGE)varPAI.intVal ;
		//////////////////////////////
		if (varDeposType.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_asset_info.cust_deposit_type = (APPLY_DEPOSIT_TYPE)varDeposType.intVal ;
		//////////////////////////////
		if (varRegDeposRang.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_asset_info.cust_regular_deposit = (APPLY_DEPOSIT_RANGE)varRegDeposRang.intVal ;
		//////////////////////////////
		if (varDemaDeposRang.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_asset_info.cust_demand_deposit =  (APPLY_DEPOSIT_RANGE)varDemaDeposRang.intVal ;
		//////////////////////////////
		if (varHasLoan.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_asset_info.does_cust_have_loan = varHasLoan.boolVal ? true : false ;
		//////////////////////////////
		if (varLoanSum.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_asset_info.cust_loan_sum = (APPLY_LOAN_RANGE)varLoanSum.intVal ;
		//////////////////////////////
		if (varLoanTime.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_asset_info.cust_loan_time = (APPLY_LOAN_TIME)varLoanTime.intVal ;
		//////////////////////////////
		if (varUnsecFixedAssetType.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_asset_info.cust_unsecured_fixed_asset = (APPLY_UNSECURED_FIXED_ASSETS)varUnsecFixedAssetType.intVal ;
		//////////////////////////////
		if (varIndusType.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_asset_info.cust_industry = (APPLY_INDUSTRY_TYPE)varIndusType.intVal ;
		//////////////////////////////
		if (varWorkUnit.vt == VT_NULL){
			strcpy(_info->input_asset_info.cust_work_unit,"null") ;
			bRtnVal = false ;
		}
		else
			strcpy(_info->input_asset_info.cust_work_unit,(char*)(_bstr_t)varWorkUnit) ;
		//////////////////////////////
		if (varWorkPos.vt == VT_NULL){
			strcpy(_info->input_asset_info.cust_work_pos,"null") ;
			bRtnVal = false ;
		}
		else
			strcpy(_info->input_asset_info.cust_work_pos,(char*)(_bstr_t)varWorkPos) ;
		//////////////////////////////	
		rsp->Close() ;
		rsp.Release() ;

		return bRtnVal ;
	}
	rsp->Close() ;
	rsp.Release() ;
	return false ;	
}
bool Get_app_cust_fami_info(_ConnectionPtr *_pConn,apply_input_info *_info) 
{
	char sqlStrTest[200] = "select * from Table_App_Cust_Fami_Info where apply_id = '" ;
	strcat(sqlStrTest,_info->input_fammily_info.app_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}

	if( ! rsp->rsEOF ) //如果此id存在...
	{
		_variant_t varMarital ;
		_variant_t varChildrenNum ;
		_variant_t varSpouName ;
		_variant_t varSpouCardType ;
		_variant_t varSpouCardID ;
		_variant_t varSpouWorkUnit ;
		_variant_t varSpouEdu ;
		_variant_t varHasSpouLoan ;

		varMarital					= rsp->Fields->GetItem(long(1))->Value ;
		varChildrenNum			= rsp->Fields->GetItem(long(2))->Value ;
		varSpouName				= rsp->Fields->GetItem(long(3))->Value ;
		varSpouCardType		= rsp->Fields->GetItem(long(4))->Value ;
		varSpouCardID			= rsp->Fields->GetItem(long(5))->Value ;
		varSpouWorkUnit		= rsp->Fields->GetItem(long(6))->Value ;
		varSpouEdu				= rsp->Fields->GetItem(long(7))->Value ;
		varHasSpouLoan		= rsp->Fields->GetItem(long(8))->Value ;

		bool bRtnVal = true ;

		if (varMarital.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_fammily_info.cust_marital_status = (APPLY_CUST_MARITAL_STATUS)varMarital.intVal ;
		///////////////////////////////////////
		if (varChildrenNum.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_fammily_info.cust_children_num = varChildrenNum.intVal ;
		///////////////////////////////////////
		if (varSpouName.vt == VT_NULL){
			strcpy(_info->input_fammily_info.cust_spouse_name,"null") ;
			bRtnVal = false ;
		}
		else
			strcpy(_info->input_fammily_info.cust_spouse_name,(char*)(_bstr_t)varSpouName) ;
		///////////////////////////////////////
		if (varSpouCardType.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_fammily_info.cust_apouse_card_type = (APPLY_CARD_TYPE)varSpouCardType.intVal ;
		///////////////////////////////////////
		if (varSpouCardID.vt == VT_NULL){
			strcpy(_info->input_fammily_info.cust_spouse_card_id,"null") ;
			bRtnVal = false ;
		}
		else
			strcpy(_info->input_fammily_info.cust_spouse_card_id,(char*)(_bstr_t)varSpouCardID) ;
		///////////////////////////////////////
		if (varSpouWorkUnit.vt == VT_NULL){
			strcpy(_info->input_fammily_info.cust_spouse_work_unit,"null") ;
			bRtnVal = false ;
		}
		else
			strcpy(_info->input_fammily_info.cust_spouse_work_unit,(char*)(_bstr_t)varSpouWorkUnit) ;
		///////////////////////////////////////
		if (varSpouEdu.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_fammily_info.cust_spouse_edu_degree = (APPLY_CUST_EDUCATION_DEGREE)varSpouEdu.intVal ;
		///////////////////////////////////////
		if (varHasSpouLoan.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_fammily_info.does_cust_spouse_has_loan  = varHasSpouLoan.boolVal ? true : false  ;
		///////////////////////////////////////


		rsp->Close() ;
		rsp.Release() ;
		return bRtnVal ;
	}
	rsp->Close() ;
	rsp.Release() ;
	return false ;
}
bool Get_app_cust_loan_info(_ConnectionPtr *_pConn,apply_input_info *_info) 
{
	char sqlStrTest[200] = "select * from Table_App_Loan_Info where apply_id = '" ;
	strcat(sqlStrTest,_info->input_loan_info.app_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}

	if( ! rsp->rsEOF ) //如果此id存在...
	{
		_variant_t varLoanAmount ;
		_variant_t varLoanDeadLine ;
		_variant_t varLoanNum;
		_variant_t varLoanComment ;
		_variant_t varWantMSG ;

		varLoanAmount			= rsp->Fields->GetItem(long(1))->Value ;
		varLoanDeadLine		= rsp->Fields->GetItem(long(2))->Value ;
		varLoanNum				= rsp->Fields->GetItem(long(3))->Value ;
		varLoanComment		= rsp->Fields->GetItem(long(4))->Value ;
		varWantMSG				= rsp->Fields->GetItem(long(5))->Value ;

		bool bRtnVal = true ;

		if (varLoanAmount.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_loan_info.loan_application_amount = (APPLY_LOAN_RANGE)varLoanAmount.intVal ;
		///////////////////////////////////////////
		if (varLoanDeadLine.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_loan_info.loan_dead_line = varLoanDeadLine.intVal ;
		///////////////////////////////////////////
		if (varLoanNum.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_loan_info.loan_times = (APPLY_LOAN_TIMES)varLoanNum.intVal ;
		///////////////////////////////////////////
		if (varLoanComment.vt == VT_NULL){
			strcpy(_info->input_loan_info.loan_comment,"null") ;
			bRtnVal = false ;
		}
		else
			strcpy(_info->input_loan_info.loan_comment,(char*)(_bstr_t)varLoanComment) ;
		///////////////////////////////////////////
		if (varWantMSG.vt == VT_NULL)
			bRtnVal = false ;
		else
			_info->input_loan_info.is_want_msg = (APPLY_MESSAGE)varWantMSG.intVal ;
		///////////////////////////////////////////

		rsp->Close() ;
		rsp.Release() ;
		return bRtnVal ;
	}
	rsp->Close() ;
	rsp.Release() ;
	return false ;
}
bool Find_app_id_be_not_verified(_ConnectionPtr *_pConn,char *_outcome) 
{
	//select max(apply_id) from Table_App_ID_Set
	char sqlStr[200] = "select min(apply_id) from Table_App_ID_Set where apply_id in " ;
	char sqlTemp[100] = "( select apply_id from Table_App_ID_Set where apply_is_verified = 'False' )" ;
	strcat(sqlStr,sqlTemp) ;

	_variant_t v ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStr,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}

	if( ! rsp->rsEOF ) //如果此id存在...
	{
		_variant_t varAppID = rsp->Fields->GetItem(long(0))->Value ;

		if ( VT_NULL != varAppID.vt )
			strcpy(_outcome,(char*)(_bstr_t)varAppID ) ;

		rsp->Close() ;
		rsp.Release() ;
		return true ;
	}
	rsp->Close() ;
	rsp.Release() ;
	return false ;
}
bool Get_emplo_info_by_work_id(_ConnectionPtr *_pConn,admin_employee_info *_info) 
{
	char sqlStrTest[200] = "select * from Table_Employee where employee_work_id = '" ;
	strcat(sqlStrTest,_info->employee_work_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}
	if( rsp->rsEOF ) //如果此id不存在...
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}

	_variant_t varID ;
	_variant_t varName ;
	_variant_t varGend ;
	_variant_t varAge ;
	_variant_t varAddr ;
	_variant_t varEMail ;
	_variant_t varType ;
	_variant_t varComment ;
	_variant_t varPhoneNum ;

	varID					= rsp->Fields->GetItem(long(1))->Value ;
	varName				= rsp->Fields->GetItem(long(2))->Value ;
	varGend				= rsp->Fields->GetItem(long(3))->Value ;
	varAge				= rsp->Fields->GetItem(long(4))->Value ;
	varAddr				= rsp->Fields->GetItem(long(5))->Value ;
	varEMail				= rsp->Fields->GetItem(long(6))->Value ;
	varType				= rsp->Fields->GetItem(long(7))->Value ;
	varComment		= rsp->Fields->GetItem(long(8))->Value ;
	varPhoneNum		= rsp->Fields->GetItem(long(9))->Value ;

	bool bRtnVal = true ;

	bRtnVal = ConvertVar2CharStr(&varID,_info->employee_id) 
		&& ConvertVar2CharStr(&varName,_info->employee_name) 
		&& ConvertVar2Int(&varGend,(int*)&_info->employee_gender)
		&& ConvertVar2Int(&varAge,&_info->employee_age) 
		&& ConvertVar2CharStr(&varAddr,_info->employee_addr) 
		&& ConvertVar2CharStr(&varEMail,_info->employee_email)
		&& ConvertVar2Int(&varType,(int*)&_info->employee_type)
		&& ConvertVar2CharStr(&varComment,_info->employee_comment)
		&& ConvertVar2CharStr(&varComment,_info->employee_tel) ;

	return bRtnVal ; 
}
bool Get_emplo_info_by_card_id(_ConnectionPtr *_pConn,admin_employee_info *_info) 
{
	char sqlStrTest[200] = "select * from Table_Employee where employee_id = '" ;
	strcat(sqlStrTest,_info->employee_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}
	if( rsp->rsEOF ) //如果此id不存在...
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}

	_variant_t varWorkID;
	_variant_t varID ;
	_variant_t varName ;
	_variant_t varGend ;
	_variant_t varAge ;
	_variant_t varAddr ;
	_variant_t varEMail ;
	_variant_t varType ;
	_variant_t varComment ;
	_variant_t varPhoneNum ;

	varWorkID           = rsp->Fields->GetItem(long(0))->Value;
	varID					= rsp->Fields->GetItem(long(1))->Value ;
	varName				= rsp->Fields->GetItem(long(2))->Value ;
	varGend				= rsp->Fields->GetItem(long(3))->Value ;
	varAge				= rsp->Fields->GetItem(long(4))->Value ;
	varAddr				= rsp->Fields->GetItem(long(5))->Value ;
	varEMail				= rsp->Fields->GetItem(long(6))->Value ;
	varType				= rsp->Fields->GetItem(long(7))->Value ;
	varComment		= rsp->Fields->GetItem(long(8))->Value ;
	varPhoneNum		= rsp->Fields->GetItem(long(9))->Value ;

	bool bRtnVal = true ;

	bRtnVal = ConvertVar2CharStr(&varID,_info->employee_id) 
		&& ConvertVar2CharStr(&varName,_info->employee_name) 
		&& ConvertVar2Int(&varGend,(int*)&_info->employee_gender)
		&& ConvertVar2Int(&varAge,&_info->employee_age) 
		&& ConvertVar2CharStr(&varAddr,_info->employee_addr) 
		&& ConvertVar2CharStr(&varEMail,_info->employee_email)
		&& ConvertVar2Int(&varType,(int*)&_info->employee_type)
		&& ConvertVar2CharStr(&varComment,_info->employee_comment)
		&& ConvertVar2CharStr(&varPhoneNum,_info->employee_tel) 
		&& ConvertVar2CharStr(&varWorkID,_info->employee_work_id);

	return bRtnVal ; 
}
bool Insert_credit_scores(_ConnectionPtr *_pConn,const credit_scores_db *_Scores,const char *_UserID) 
{
	char sqlStrTest[200] = "select score_income from Table_Score_Set where card_id = '" ;
	strcat(sqlStrTest,_Scores->card_id) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}
	if( ! rsp->rsEOF ) // 如果已存在...
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}


	char sqlStr[200] = "Insert into Table_Score_Set values(" ;

	char temp[12] ;
	strcat(sqlStr,"'") ;
	strcat(sqlStr,_UserID) ;
	strcat(sqlStr,"',") ;

	memset(temp,0,12) ;
	sprintf(temp,"'%.2f',",_Scores->score_income) ;
	strcat(sqlStr,temp) ;

	memset(temp,0,12) ;
	sprintf(temp,"'%.2f',",_Scores->score_depos) ;
	strcat(sqlStr,temp) ;

	memset(temp,0,12) ;
	sprintf(temp,"'%.2f',",_Scores->score_repayment) ;
	strcat(sqlStr,temp) ;

	memset(temp,0,12) ;
	sprintf(temp,"'%.2f',",_Scores->score_fixed_assets_be_pledged) ;
	strcat(sqlStr,temp) ;

	memset(temp,0,12) ;
	sprintf(temp,"'%.2f',",_Scores->score_id_type) ;
	strcat(sqlStr,temp) ;

	memset(temp,0,12) ;
	sprintf(temp,"'%.2f',",_Scores->score_edu) ;
	strcat(sqlStr,temp) ;

	memset(temp,0,12) ;
	sprintf(temp,"'%.2f',",_Scores->score_marriage) ;
	strcat(sqlStr,temp) ;

	memset(temp,0,12) ;
	sprintf(temp,"'%.2f',",_Scores->score_loan_record) ;
	strcat(sqlStr,temp) ;

	memset(temp,0,12) ;
	sprintf(temp,"'%.2f',",_Scores->score_bad_social_record) ;
	strcat(sqlStr,temp) ;

	memset(temp,0,12) ;
	sprintf(temp,"'%.2f')",_Scores->score_auditor_edit) ;
	strcat(sqlStr,temp) ;

	try{
		(*_pConn)->Execute(sqlStr,&v,adCmdText) ;
	}catch(...){
		return false ;
	}

	rsp->Close() ;
	rsp.Release() ;
	return true ;
}
bool Update_credit_scores(_ConnectionPtr *_pConn,const credit_scores_db *_Scores,const char *_UserID) 
{
	const char col0[] = "score_income = '" ;
	const char col1[] = "score_depos = '" ;
	const char col2[] = "score_repayment = '" ;
	const char col3[] = "score_fixed_assets_be_pledged = '" ;
	const char col4[] = "score_id_type = '" ;
	const char col5[] = "score_edu = '" ;
	const char col6[] = "score_marriage = '" ;
	const char col7[] = "score_loan_record = '" ;
	const char col8[] = "score_bad_social_record = '" ;
	const char col9[] = "score_auditor_edit = '" ;

	char sqlStr[400] = "update Table_Score_Set set " ;

	char temp[6] ;
	memset(temp,0,6) ;

	strcat(sqlStr,col0) ;
	sprintf(temp,"%.2f",_Scores->score_income) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"',") ;

	strcat(sqlStr,col1) ;
	sprintf(temp,"%.2f",_Scores->score_depos) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"',") ;

	strcat(sqlStr,col2) ;
	sprintf(temp,"%.2f",_Scores->score_repayment) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"',") ;

	strcat(sqlStr,col3) ;
	sprintf(temp,"%.2f",_Scores->score_fixed_assets_be_pledged) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"',") ;

	strcat(sqlStr,col4) ;
	sprintf(temp,"%.2f",_Scores->score_id_type) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"',") ;

	strcat(sqlStr,col5) ;
	sprintf(temp,"%.2f",_Scores->score_edu) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"',") ;

	strcat(sqlStr,col6) ;
	sprintf(temp,"%.2f",_Scores->score_marriage) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"',") ;

	strcat(sqlStr,col7) ;
	sprintf(temp,"%.2f",_Scores->score_loan_record) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"',") ;

	strcat(sqlStr,col8) ;
	sprintf(temp,"%.2f",_Scores->score_bad_social_record) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"',") ;

	strcat(sqlStr,col9) ;
	sprintf(temp,"%.2f",_Scores->score_auditor_edit) ;
	strcat(sqlStr,temp) ;
	strcat(sqlStr,"' ") ;

	strcat(sqlStr,"from Table_Score_Set where card_id = '") ;
	strcat(sqlStr,_UserID) ;
	strcat(sqlStr,"'") ;

	_variant_t vt ;
	try{
		(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}catch(...){
		return false ;
	}

	return true ;
}
bool Get_credit_scores(_ConnectionPtr *_pConn,credit_scores_db *_Scores,const char *_UserID) 
{
	char sqlStrTest[200] = "select * from Table_Score_Set where card_id = '" ;
	strcat(sqlStrTest,_UserID) ;
	strcat(sqlStrTest,"'") ;
	_variant_t v ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	}
	catch(...){
		return false;
	}
	if( rsp->rsEOF ) //如果此id不存在...
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}
	_variant_t varIncome ;
	_variant_t varDepos ;
	_variant_t varRpy ;
	_variant_t varFABP ;
	_variant_t varIDType ;
	_variant_t varEdu ;
	_variant_t varMarriage;
	_variant_t varLoanRecrd ;
	_variant_t varSocialRecrd ;
	_variant_t varAuditorEdit ;

	varIncome			= rsp->Fields->GetItem(long(1))->Value ;
	varDepos			= rsp->Fields->GetItem(long(2))->Value ;
	varRpy					= rsp->Fields->GetItem(long(3))->Value ;
	varFABP				= rsp->Fields->GetItem(long(4))->Value ;
	varIDType			= rsp->Fields->GetItem(long(5))->Value ;
	varEdu				= rsp->Fields->GetItem(long(6))->Value ;
	varMarriage		= rsp->Fields->GetItem(long(7))->Value ;
	varLoanRecrd		= rsp->Fields->GetItem(long(8))->Value ;
	varSocialRecrd	= rsp->Fields->GetItem(long(9))->Value ;
	varAuditorEdit	= rsp->Fields->GetItem(long(10))->Value ;

	bool bRtnVal = true ;

	bRtnVal = ConvertVar2Float(&varIncome,&_Scores->score_income) 
		&& ConvertVar2Float(&varDepos,&_Scores->score_depos) 
		&& ConvertVar2Float(&varRpy,&_Scores->score_repayment) 
		&& ConvertVar2Float(&varFABP,&_Scores->score_fixed_assets_be_pledged) 
		&& ConvertVar2Float(&varIDType,&_Scores->score_id_type) 
		&& ConvertVar2Float(&varEdu,&_Scores->score_edu) 
		&& ConvertVar2Float(&varMarriage,&_Scores->score_marriage) 
		&& ConvertVar2Float(&varLoanRecrd,&_Scores->score_loan_record) 
		&& ConvertVar2Float(&varSocialRecrd,&_Scores->score_bad_social_record) 
		&& ConvertVar2Float(&varAuditorEdit,&_Scores->score_auditor_edit)  ;

	rsp->Close() ;
	rsp.Release() ;
	return bRtnVal ;
}
bool Find_how_many_passed_user(_ConnectionPtr *_pConn,int *_Outcome) 
{
	const char sqlStr[] = "select apply_id from Table_App_Pass_And_Comment where apply_is_passed = 'true'" ;
	_variant_t vt ;
	_RecordsetPtr rsp ;
	try{
		rsp = (*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}catch(...){
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}

	*_Outcome = 0 ;

	while( ! rsp->rsEOF  )
	{
		rsp->MoveNext() ;
		++(*_Outcome) ;
	}
	rsp->Close() ;
	rsp.Release() ;
	return true ;
}
bool Find_all_passed_user(_ConnectionPtr *_pConn,user_query_array_info *_info,size_t _Size)
{
	const char sqlStr0[] = "select apply_id from Table_App_Pass_And_Comment where apply_is_passed = 'true'" ;
	_variant_t vt ;
	_RecordsetPtr rsp ;
	try{
		rsp = (*_pConn)->Execute(sqlStr0,&vt,adCmdText) ;
	}catch(...){
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}

	for( size_t i = 0 ; i < _Size ; ++i )
	{
		_variant_t varAppID = rsp->Fields->GetItem(long(0))->Value ;
		rsp->MoveNext() ;
		///////////////////move to next...
		char app_id[APPLY_ID] ;
		memset(app_id,0,APPLY_ID) ;
		ConvertVar2CharStr(&varAppID,app_id) ;
		//convert to str
		char sqlStr[200] = "select * from Table_App_Cust_Info where apply_id = '" ;
		strcat(sqlStr,app_id) ;
		strcat(sqlStr,"'") ;

		_variant_t v ;
		_RecordsetPtr r ;
		try{
			r =  (*_pConn)->Execute(sqlStr,&v,adCmdText) ;
		}catch(...){
			return false ;
		}

		if( r->rsEOF )
			return false ;

		_variant_t varName ;
		_variant_t varID ;
		_variant_t varGend ;
		_variant_t varAge ;
		_variant_t varPhone ;
		_variant_t varAddr;

		varName		= r->Fields->GetItem(long(1))->Value ;
		varGend		= r->Fields->GetItem(long(2))->Value ;
		varAge		= r->Fields->GetItem(long(3))->Value ;
		varID			= r->Fields->GetItem(long(5))->Value ;
		varPhone		= r->Fields->GetItem(long(6))->Value ;
		varAddr		= r->Fields->GetItem(long(9))->Value ;

		bool bRtnVal = true ;
		bRtnVal = ConvertVar2CharStr(&varName,_info->user_array[i].user_name)
			&& ConvertVar2Int(&varGend,(int *)&_info->user_array[i].user_gender) 
			&& ConvertVar2Int(&varAge,&_info->user_array[i].user_age) 
			&& ConvertVar2CharStr(&varID,_info->user_array[i].user_card_id)
			&& ConvertVar2CharStr(&varPhone,_info->user_array[i].user_tel)
			&& ConvertVar2CharStr(&varAddr,_info->user_array[i].user_addr) ;

		r->Close() ;
		r.Release() ;

		if( ! bRtnVal )
			return false ;
	}

	rsp->Close() ;
	rsp.Release() ;
	return true ;
}
bool Find_specific_user(_ConnectionPtr *_pConn,user_query_info *_info,const char *_ID) 
{
	char sqlStr[200] = "select * from Table_App_Cust_Info where apply_id = '" ;
	strcat(sqlStr,_ID) ;
	strcat(sqlStr,"'") ;

	_variant_t v ;
	_RecordsetPtr r ;

	try{
		r =  (*_pConn)->Execute(sqlStr,&v,adCmdText) ;
	}catch(...){
		return false ;
	}

	if( r->rsEOF )
	{
		r->Close() ;
		r.Release() ;
		return false ;
	}


	_variant_t varName ;
	_variant_t varID ;
	_variant_t varGend ;
	_variant_t varAge ;
	_variant_t varPhone ;
	_variant_t varAddr;

	varName		= r->Fields->GetItem(long(1))->Value ;
	varGend		= r->Fields->GetItem(long(2))->Value ;
	varAge		= r->Fields->GetItem(long(3))->Value ;
	varID			= r->Fields->GetItem(long(5))->Value ;
	varPhone		= r->Fields->GetItem(long(6))->Value ;
	varAddr		= r->Fields->GetItem(long(9))->Value ;

	bool bRtnVal = true ;
	bRtnVal = ConvertVar2CharStr(&varName,_info->user_name)
		&& ConvertVar2Int(&varGend,(int *)&_info->user_gender) 
		&& ConvertVar2Int(&varAge,&_info->user_age) 
		&& ConvertVar2CharStr(&varID,_info->user_card_id)
		&& ConvertVar2CharStr(&varPhone,_info->user_tel)
		&& ConvertVar2CharStr(&varAddr,_info->user_addr) ;

	r->Close() ;
	r.Release() ;

	return bRtnVal ;
}
bool Get_max_group_id(_ConnectionPtr *_pConn,char *_Outcome) 
{
	char sqlStr[200] = "select max(group_id) from Table_Guaranteed_Group" ;

	_variant_t vt ;
	_RecordsetPtr rsp ;
	try{
		rsp = (*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false;
	}
	// execute sql... 
	if( rsp->rsEOF )
	{
		rsp->Close() ;
		rsp.Release() ;
		memset(_Outcome,0,GROUP_ID_LEN * sizeof(char)) ;
		return false ;
	}

	_variant_t varGPID = rsp->Fields->GetItem(long(0))->Value ; 

	ConvertVar2CharStr(&varGPID,_Outcome) ;

	rsp->Close() ;
	rsp.Release() ;
	return true ;
}
/*
bool Insert_group_info(_ConnectionPtr *_pConn,const char *group_id,const group_member_info *_Info) 
{
	char sqlStr[200] ;
	sprintf(sqlStr,"insert into Table_Guaranteed_Group values('%s','%s','%s','%s','%s','%s','%s')",
		group_id,
		_Info->cust_id[0][0] ,
		_Info->cust_id[1][0] ,
		_Info->cust_id[2][0] ,
		_Info->cust_id[3][0] ,
		_Info->cust_id[4][0] ,
		_Info->cust_id[5][0]  ) ;

	try{
		_variant_t v ;
		(*_pConn)->Execute(sqlStr,&v,adCmdText) ;
	}catch(...){
		return false ;
	}

	return true ;
}*/
bool Get_cust_basic_info(_ConnectionPtr *_pConn,user_query_info *_Info) 
{
	char sqlStr[200] = "select * from Table_Cust_Info where id = '" ; 
	strcat(sqlStr,_Info->user_card_id) ;
	strcat(sqlStr,"'") ;

	_variant_t vt ;
	_RecordsetPtr rsp;
	try{
		rsp = (*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false;
	}

	if ( rsp->rsEOF )// 如果没查到...
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}

	_variant_t varName		= rsp->Fields->GetItem(long(1))->Value ;
	_variant_t varGend		= rsp->Fields->GetItem(long(2))->Value ;
	_variant_t varAge			= rsp->Fields->GetItem(long(3))->Value ;
	_variant_t varPhone		= rsp->Fields->GetItem(long(4))->Value ;
	_variant_t varAddr		= rsp->Fields->GetItem(long(5))->Value ;

	bool bRtnVal = true ;

	bRtnVal = ConvertVar2CharStr(&varName,_Info->user_name) 
		&& ConvertVar2Int(&varGend,(int *)&_Info->user_gender)	
		&& ConvertVar2Int(&varAge,&_Info->user_age) 
		&& ConvertVar2CharStr(&varPhone,_Info->user_tel)
		&& ConvertVar2CharStr(&varAddr,_Info->user_addr) ;

	rsp->Close() ;
	rsp.Release() ;
	return bRtnVal ;
}
bool Find_how_many_employee(_ConnectionPtr *_pConn,int *_Num)
{
	char sqlStr[100] = "select employee_gender from Table_Employee" ;
	_variant_t vt ;
	_RecordsetPtr rsp ;
	try{
		rsp = (*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false;
	}

	while( ! rsp->rsEOF )
	{
		++(*_Num) ;
		rsp->MoveNext() ;
	}
	return true ;
}
bool Get_all_emplo_info(_ConnectionPtr *_pConn,admin_employee_info* _Arr,int _Count) 
{
	char sqlStr[100] = "select * from Table_Employee" ;

	_variant_t vt ;
	_RecordsetPtr rsp ;
	try{
		rsp = (*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false ;
	}

	for (int lp = 0 ; lp < _Count ; ++lp)
	{
		_variant_t varWkID		= rsp->Fields->GetItem(long(0))->Value ;
		_variant_t varCDID		= rsp->Fields->GetItem(long(1))->Value ;
		_variant_t varName		= rsp->Fields->GetItem(long(2))->Value ;
		_variant_t varGend		= rsp->Fields->GetItem(long(3))->Value ;
		_variant_t varAge			= rsp->Fields->GetItem(long(4))->Value ;
		_variant_t varAddr		= rsp->Fields->GetItem(long(5))->Value ;
		_variant_t varEmail		= rsp->Fields->GetItem(long(6))->Value ;
		_variant_t varType		= rsp->Fields->GetItem(long(7))->Value ;
		_variant_t varCmmt		= rsp->Fields->GetItem(long(8))->Value ;
		_variant_t varPhone		= rsp->Fields->GetItem(long(9))->Value ;

		bool bRtnVal = true ;

		bRtnVal = ConvertVar2CharStr(&varWkID,_Arr[lp].employee_work_id) 
			&& ConvertVar2CharStr(&varCDID,_Arr[lp].employee_id) 
			&& ConvertVar2CharStr(&varName,_Arr[lp].employee_name) 
			&& ConvertVar2Int(&varGend,(int *)&_Arr[lp].employee_gender)	
			&& ConvertVar2Int(&varAge,&_Arr[lp].employee_age) 
			&& ConvertVar2CharStr(&varAddr,_Arr[lp].employee_addr) 
			&& ConvertVar2CharStr(&varEmail,_Arr[lp].employee_email) 
			&& ConvertVar2Int(&varType,(int *)&_Arr[lp].employee_type) 
			&& ConvertVar2CharStr(&varAddr,_Arr[lp].employee_comment) 
			&& ConvertVar2CharStr(&varPhone,_Arr[lp].employee_tel) ;

		if( ! bRtnVal )
		{
			rsp->Close() ;
			rsp.Release() ;
			return false ;
		}
		rsp->MoveNext() ;
	}
	rsp->Close() ;
	rsp.Release() ;
	return true ;
}
bool Update_emplo_info(_ConnectionPtr *_pConn,char *_Old_ID,admin_employee_info* _Info) 
{
	const char col0[] = "employee_work_id" ;
	const char col1[] = "employee_id" ;
	const char col2[] = "employee_name" ;
	const char col3[] = "employee_gender" ;
	const char col4[] = "employee_age" ;
	const char col5[] = "employee_addr" ;
	const char col6[] = "employee_email" ;
	const char col7[] = "employee_type" ;
	const char col8[] = "employee_comment" ;
	const char col9[] = "employee_phone_num" ;

	char sqlStr[400]  ;
	memset(sqlStr,0,400) ;
	sprintf(sqlStr,"update Table_Employee set %s = '%s',%s = '%s',%s = '%s',%s = %d,%s = %d,%s = '%s',%s = '%s',%s = %d,%s = '%s',%s = '%s' from Table_Employee where %s = '%s'", 
		col0,_Info->employee_work_id,
		col1,_Info->employee_id,
		col2,_Info->employee_name,
		col3,_Info->employee_gender,
		col4,_Info->employee_age,
		col5,_Info->employee_addr,
		col6,_Info->employee_email,
		col7,_Info->employee_type,
		col8,_Info->employee_comment,
		col9,_Info->employee_tel,
		col1,_Old_ID) ;

	_variant_t vt ;
	try{
		(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false ;
	}
	return true ;
}
bool has_user_app(_ConnectionPtr *_pConn,const char *_ID) 
{
	char sqlStr[150] = "select cust_gend from Table_Cust_Info where cust_id = '" ;
	strcat(sqlStr,_ID) ;
	strcat(sqlStr,"'") ;

	_variant_t vt ;
	_RecordsetPtr rsp ;
	try{
		rsp = (*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false ;
	}

	if ( rsp->rsEOF )
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}
	rsp->Close() ;
	rsp.Release() ;
	return true ;
}
bool has_user_score(_ConnectionPtr *_pConn,const char *_ID) 
{
	char sqlStr[100] = "select cust_gend from Table_Score_Set where card_id = '" ;
	strcat(sqlStr,_ID) ;
	strcat(sqlStr,"'") ;

	_variant_t vt ;
	_RecordsetPtr rsp ; 
	try{
		rsp = (*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false ;
	}

	if ( rsp->rsEOF )
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}
	rsp->Close() ;
	rsp.Release() ;
	return true ;
}
bool Update_login_pwd(_ConnectionPtr *_pConn,const char *_ID,const char *_new_pwd) 
{
	char sqlStr[150] = "update Table_Login set login_pwd = '" ;
	strcat(sqlStr,_new_pwd) ;
	strcat(sqlStr,"'") ;
	strcat(sqlStr," from Table_Login where login_id = '") ;
	strcat(sqlStr,_ID) ;
	strcat(sqlStr,"'") ;

	_variant_t v ;
	try{
		(*_pConn)->Execute(sqlStr,&v,adCmdText) ;
	}catch(...){
		return false ;
	}
	return true ;
}
bool Cust_or_emplo(_ConnectionPtr *_pConn,const char *_ID,bool *_IsCust) 
{
	char sqlStr[200] = "select login_competence from Table_Login where login_id = '" ;
	strcat(sqlStr,_ID) ;
	strcat(sqlStr,"'" ) ;

	_variant_t vt ;
	_RecordsetPtr rsp ;
	try{
		rsp = (*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false ;
	}

	if ( rsp->rsEOF )
	{
		rsp->Close() ;
		rsp.Release() ;
		return false ;
	}

	_variant_t varCMP = rsp->Fields->GetItem(long(0))->Value ;
	int cmp = compe_err ;

	ConvertVar2Int(&varCMP,&cmp) ;
	rsp->Close() ;
	rsp.Release() ;

	if ( compe_cust == cmp)
	{
		*_IsCust = true ;
		return true ;
	}
	else if(compe_operater == cmp || compe_audi == cmp || compe_admin == cmp)
	{
		*_IsCust = false ;
		return true ;
	}
	else
	{
		return false ;
	}
}
bool Update_user_info(_ConnectionPtr *_pConn,const char *_ID,const char *_New_Addr,const char *_New_Email,const char *_New_Phone) 
{
	bool bIsCust ;
	if ( Cust_or_emplo(_pConn,_ID,&bIsCust) )
	{
		if (bIsCust)
		{
			char sqlStr[200] = "update Table_Cust_Info set home_adress = '" ;
			strcat(sqlStr,_New_Addr) ;
			strcat(sqlStr,"',phone_num = '") ;
			strcat(sqlStr,_New_Phone) ;
			strcat(sqlStr,"' from Table_Cust_Info where id = '") ;
			strcat(sqlStr,_ID) ;
			strcat(sqlStr,"'") ;

			_variant_t vt ;
			try{
				(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
			}
			catch(...){
				return false ;
			}
		}
		else
		{
			char sqlStr[200] = "update Table_Employee set employee_addr = '" ;
			strcat(sqlStr,_New_Addr) ;
			strcat(sqlStr,"',employee_email = '") ;
			strcat(sqlStr,_New_Email) ;
			strcat(sqlStr,"',employee_phone_num = '") ;
			strcat(sqlStr,_New_Phone) ;
			strcat(sqlStr,"' from Table_Employee where employee_id = '") ;
			strcat(sqlStr,_ID) ;
			strcat(sqlStr,"'") ;
			
			_variant_t vt ;
			try{
				(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
			}
			catch(...){
				return false ;
			}
		}
		return false ;
	}
	else
	{
		return true  ;
	}
}
bool Insert_group_info(_ConnectionPtr *_pConn,group_info *_Info,char *_Group_Id) 
{
	char sqlStr[200] = "insert into Table_Guaranteed_Group values('" ;
	strcat(sqlStr,_Group_Id) ;
	strcat(sqlStr,"','") ;

	for(int i = 0 ; i < _Info->length - 1 ; ++i)
	{
		strcat(sqlStr,_Info->mem[i]._id) ;
		strcat(sqlStr,"','") ;
	}
	strcat(sqlStr,_Info->mem[_Info->length - 1]._id ) ;
	strcat(sqlStr,"')") ;

	try{
		_variant_t vt ;
		(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	}
	catch(...){
		return false ;
	}
	return true ;
}