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
	(*pConn) ->Open("","","",-1) ;
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

bool Password_inquiry(_ConnectionPtr *_pConn,char *user_name , char *pwd_rlt)
{
	_variant_t vt ;
	char sqlStr[100] = "select login_pwd from Table_Login where login_id = " ;
	strcat_s(sqlStr,user_name) ;
	_RecordsetPtr rsp = (*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	//inquiry...
	_variant_t  varPwd ;

	if( ! rsp->rsEOF )
	{
		varPwd = rsp->Fields->GetItem(long(0))->Value ;
	}
	else
		return false ;

	if (varPwd.vt == VT_NULL)
	{
		const char emptyStr[] = "null" ;
		strcpy_s(pwd_rlt, PWD_LEN,emptyStr) ;
	
		return false ;
	}
	else
	{
		strcpy_s(pwd_rlt, PWD_LEN, (char *)(_bstr_t)varPwd)  ;
		return true ;
	}
}

void	Summery_inquiry(_ConnectionPtr *_pConn,char *user_name,sys_db_login *user_info_rlt) 
{
	_variant_t vt ;
	char sqlStr[200] = "select * from Table_Login where id = " ;
	strcat_s(sqlStr,idLen,user_name) ;
	_RecordsetPtr rsp = (*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
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
}

bool	add_new_to_Tab_Login(_ConnectionPtr *_pConn,reg_input_info *_reg_info) 
{
	char sqlStrTest[200] = "select login_competence from Table_Login where login_id = " ;
	strcat(sqlStrTest,_reg_info->basic_info.reg_id) ;
	_variant_t v ;
	_RecordsetPtr rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	if( ! rsp->rsEOF )
	{
		rsp.Release() ;
		return false ;
	}
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
	(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	return true ;
}

bool	add_new_to_Tab_Cust(_ConnectionPtr *_pConn,reg_input_info *_reg_info)
{
	char sqlStrTest[200] = "select name from Table_Cust_Info where id = " ;
	strcat(sqlStrTest,_reg_info->basic_info.reg_id) ;
	_variant_t v ;
	_RecordsetPtr rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	if( ! rsp->rsEOF )
	{
		rsp.Release() ;
		return false ;
	}
	rsp.Release() ;

	char sqlStr[300] = "insert into Table_Cust_Info values('" ;
	strcat(sqlStr,_reg_info->basic_info.reg_id) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_reg_info->basic_info.reg_basic_user_name) ;
	strcat(sqlStr,"','") ;
	char temp[6] ;
	strcpy(temp, _reg_info->basic_info.reg_gender == reg_info_male ? "true" : "false") ;
	
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
	(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;

	return true ;
}

bool	add_new_employee(_ConnectionPtr *_pConn,admin_employee_info *emp_info,char *_comment)
{
	char sqlStrTest[200] = "select employee_work_id from Table_Employee where employee_id = " ;
	strcat(sqlStrTest,emp_info->employee_id) ;
	_variant_t v ;
	_RecordsetPtr rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	if( ! rsp->rsEOF )
	{
		rsp.Release() ;
		return false ;
	}
	rsp.Release() ;

	char sqlStr[500] = "insert into Table_Employee values('" ;
	strcat(sqlStr,emp_info->employee_id) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,emp_info->employee_work_id) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,emp_info->employee_name) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr, emp_info->employee_gender == employee_male ? "true" : "false" ) ;
	strcat(sqlStr,"','") ;
	char temp_age[4]  = {0,0,0,0} ;
	itoa(emp_info->employee_age,temp_age,10) ;
	strcat(sqlStr,temp_age) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,emp_info->employee_addr) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,emp_info->employee_email) ;
	strcat(sqlStr,"','") ;
	char temp_type[2] = {0,0} ;
	itoa(emp_info->employee_type, temp_type , 10 ) ;
	strcat(sqlStr,temp_type) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,temp_type) ;
	strcat(sqlStr,"','") ;
	strcat(sqlStr,_comment) ;
	strcat(sqlStr,"')") ;

	_variant_t vt ;
	(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;
	return true ;
}

bool delete_employee(_ConnectionPtr *_pConn,const char *employee_id) 
{
	char sqlStrTest[200] = "select employee_work_id from Table_Employee where employee_id = " ;
	strcat(sqlStrTest,employee_id) ;
	_variant_t v ;
	_RecordsetPtr rsp = (*_pConn)->Execute(sqlStrTest,&v,adCmdText) ;
	if( ! rsp->rsEOF )
	{
		rsp.Release() ;
		return false ;
	}
	rsp.Release() ;

	char sqlStr[200] = "delete from Table_Employee where employee_id = " ;
	strcat(sqlStr,employee_id) ;

	_variant_t vt ;
	(*_pConn)->Execute(sqlStr,&vt,adCmdText) ;

	return true ;
}

bool	Apply_cust_info_query(_ConnectionPtr *_pConn,apply_custmor_info* _rlt)
{
	char sqlStrTest[200] = "select * from Table_Cust_Info where id = " ;
	strcat(sqlStrTest,_rlt->cust_id) ;
	_variant_t vt ;
	_RecordsetPtr rsp = (*_pConn)->Execute(sqlStrTest,&vt,adCmdText) ;
	if( ! rsp->rsEOF )
	{
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