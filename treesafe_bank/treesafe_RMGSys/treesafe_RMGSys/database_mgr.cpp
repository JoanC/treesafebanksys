#include "stdafx.h"
#include "database_mgr.h"


char *GetIP()
{
	const char partConnStr[] = "Provider=SQLOLEDB.1;Password=123;Persist Security Info=True;User ID=ts_login;Initial Catalog=treesafe_Login;Data Source="  ;
	const int IPLen = 16 ;
	int nLenOfConnStr = strlen(partConnStr) + IPLen ;
	char *connStr = new char[nLenOfConnStr] ;

	char ch_ip[IPLen] ;
	memset( ch_ip , '\0' , IPLen ) ;
	
	printf("please input the ip address of the database...\r\n") ;
	scanf("%s",ch_ip) ;
	
	strcpy_s(connStr,nLenOfConnStr ,partConnStr ) ;
	strcat_s(connStr,nLenOfConnStr,ch_ip) ;

	return connStr ;
}

bool ConnectDB(_ConnectionPtr *pConn) 
{	
	char *connStr = GetIP() ;
	::CoInitialize(0);
	pConn->CreateInstance(__uuidof(Connection));
	(*pConn)->ConnectionString = connStr ;
	(*pConn) ->ConnectionTimeout = 10 ;
	(*pConn) ->CursorLocation = adUseServer;
	//setting param...
	(*pConn) ->Open("","","",-1) ;
	//open it 
	delete []connStr ;
	connStr = NULL ;
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