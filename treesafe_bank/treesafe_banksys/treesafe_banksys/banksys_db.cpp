#include "stdafx.h"
#include "banksys_db.h"

const char c_strConenctionString[] = "Provider=SQLOLEDB.1;Password=111;Persist Security Info=True;User ID=bank_sys;Initial Catalog=bank_data;Data Source=192.168.0.155" ;

bool ConnectDB(_ConnectionPtr *pConn)
{
	::CoInitialize(0);
	pConn->CreateInstance(__uuidof(Connection));
	(*pConn)->ConnectionString = c_strConenctionString ;
	(*pConn) ->ConnectionTimeout = 10 ;
	(*pConn) ->CursorLocation = adUseServer;
	//setting param...
	(*pConn) ->Open("","","",-1) ;
	//open it 

	return true ; //return success or not
}
void DisconnectDB(_ConnectionPtr *pConn)
{
	(*pConn)->Close();
	pConn->Release();
	::CoUninitialize();
}
bool Cust_info_inquiry(banksys_db *_rlt,_ConnectionPtr *_pConn)
{
	_variant_t vt ;
	char cSqlStr[100] = "select * from Table_Cust_Info where id = " ;
	strcat_s(cSqlStr,_rlt->req.id) ;
	_RecordsetPtr rsp = (*_pConn)->Execute(cSqlStr,&vt,adCmdText);


	bankDB_result_cust_info *rlt_ = new bankDB_result_cust_info[1] ;
	// alloc space first...

	_variant_t varID ; 
	_variant_t varName ; 
	_variant_t varGend ; 
	_variant_t varAge ; 
	_variant_t varPhoneNum ;
	_variant_t varAddress ;
	// variants...
	varID				=	rsp->Fields->GetItem("id")->Value ;
	varName			=	rsp->Fields->GetItem(long(1))->Value ;
	varGend			=	rsp->Fields->GetItem(long(2))->Value ;
	varAge			=	rsp->Fields->GetItem(long(3))->Value ;
	varPhoneNum	=	rsp->Fields->GetItem(long(4))->Value ;
	varAddress	=	rsp->Fields->GetItem(long(5))->Value ;
	// get value...

	if (varID.vt == VT_NULL)
	{
		strcpy_s(rlt_[0].id , "null" ) ;
	}
	else
	{
		strcpy_s(rlt_[0].id , (char *)(_bstr_t)varID)  ;
	}
	//////////////////
	if (varName.vt == VT_NULL)
	{
		strcpy_s(rlt_[0].name , "null" ) ;
	}
	else
	{
		strcpy_s(rlt_[0].name , (char *)(_bstr_t)varName)  ;
	}
	/////////////////
	if (varGend.vt == VT_NULL)
	{
		//			strcpy_s(rlt_[nX].gend , "null" ) ;
	}
	else
	{
		rlt_[0].gend = varGend.boolVal ? true : false ;
	}
	//////////////////
	if (varAge.vt == VT_NULL)
	{
		rlt_[0].age = 0 ;
	}
	else
	{
		rlt_[0].age = varAge.iVal  ;
	}
	//////////////////
	if (varPhoneNum.vt == VT_NULL)
	{
		strcpy_s(rlt_[0].phone_num , "null" ) ;
	}
	else
	{
		strcpy_s(rlt_[0].phone_num , (char *)(_bstr_t)varPhoneNum)  ;
	}
	//////////////////////
	if (varAddress.vt == VT_NULL)
	{
		strcpy_s(rlt_[0].home_addr , "null" ) ;
	}
	else
	{
		strcpy_s(rlt_[0].home_addr , (char *)(_bstr_t)varAddress)  ;
	}
	_rlt->rlt.nCount = 1 ;
	_rlt->rlt.pRlt = rlt_ ;
	// next...

	return true ;
}
bool	Account_info_inquiry(banksys_db *_rlt,_ConnectionPtr *_pConn)
{
	return true ;
}
bool	Loan_info_inquiry(banksys_db *_rlt,_ConnectionPtr *_pConn)
{
	return true ;
}
bool	InquiryResult(banksys_db *_rlt,_ConnectionPtr *_pConn)
{
	switch ( _rlt->req.type )
	{
	case  CUST_INFO :
		Cust_info_inquiry( _rlt , _pConn ) ;
		break ;

	case ACCOUNT_INFO :
		Account_info_inquiry( _rlt , _pConn ) ;
		break ;

	case LOAN_INFO :
		Loan_info_inquiry( _rlt , _pConn ) ;
		break ;

	default :

		break ;
	}
	return true ;
}
