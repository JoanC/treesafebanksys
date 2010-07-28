#include "stdafx.h"
#include "banksys_db.h"

const char c_strConenctionString[] = "Provider=SQLOLEDB.1;Password=111;Persist Security Info=True;User ID=bank_sys;Initial Catalog=bank_data;Data Source=192.168.0.101" ;

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
	const char table_deposit[]		=	" Table_Deposit " ;
	const char table_account[]		=	" Table_Account " ;

	char cSqlStr[100] = "select * from" ;
	strcat_s(cSqlStr,table_deposit) ;
	strcat_s(cSqlStr,"where id = ") ;
	strcat_s(cSqlStr,_rlt->req.id) ;
	//
	_variant_t vt ;
	_RecordsetPtr rsp = (*_pConn)->Execute(cSqlStr,&vt,adCmdText);
	//

	size_t stCount = 0 ;
	while( ! rsp->rsEOF  )
	{
		rsp->MoveNext() ;
		stCount++ ;
	}
	//count how many...

	rsp->MoveFirst() ;
	// move to first...

	bankDB_result_account_info *outcome = new bankDB_result_account_info[stCount] ;
	// alloc the space of length of stCount

	for (unsigned int i = 0 ; i < stCount ; i++ )
	{
		_variant_t varAcntNum ;
		varAcntNum		=		rsp->Fields->GetItem(long(1))->Value ;
		rsp->MoveNext() ;
		// get account_number...

		char ch_acnt_num[19] ;
		strcpy_s( ch_acnt_num , (char *)(_bstr_t)varAcntNum ) ;
		//get account number of type of char * 

		char sql_str[100] = "select * from" ;
		strcat_s(sql_str, table_account) ;
		strcat_s(sql_str, "where account_number = ") ;
		strcat_s(sql_str, ch_acnt_num) ;
		// get sql sentence...

		_RecordsetPtr temp_rsp = (*_pConn)->Execute(sql_str,&vt,adCmdText) ;
		// excute sql sentence...

		_variant_t varOpenBran			=		temp_rsp->Fields->GetItem(long(1))->Value ;
		_variant_t varOpenDate			=		temp_rsp->Fields->GetItem(long(2))->Value;
		_variant_t varType					=		temp_rsp->Fields->GetItem(long(3))->Value;
		_variant_t varBalance				=		temp_rsp->Fields->GetItem(long(4))->Value;
		_variant_t varMonthRemain	=		temp_rsp->Fields->GetItem(long(5))->Value;
		// read the data...

		strcpy_s(outcome[i].account_num , ch_acnt_num) ; 

		if (varOpenBran.vt == VT_NULL)
		{
			strcpy_s(outcome[i].open_branch , "null" ) ;
		}
		else
		{
			strcpy_s(outcome[i].open_branch , (char *)(_bstr_t)varOpenBran)  ;
		}
		// ...
		if (varOpenDate.vt == VT_NULL)
		{
			strcpy_s(outcome[i].open_date , "null" ) ;
		}
		else
		{
			strcpy_s(outcome[i].open_date , (char *)(_bstr_t)varOpenDate)  ;
		}
		//...

		outcome[i].type = varType.boolVal ? true : false ;
		//...

		if (varBalance.vt == VT_NULL)
		{
			outcome[i].balance = -1  ;
			// error if balnce < 0 
		}
		else
		{
			outcome[i].balance = varBalance ;
		}
		if (varMonthRemain.vt == VT_NULL)
		{
			outcome[i].month_remain = -1  ;
			// error if month_remain < 0 
		}
		else
		{
			outcome[i].month_remain = varMonthRemain.intVal ;
		}

		temp_rsp->MoveNext() ;
	}

	_rlt->rlt.nCount = stCount ; 
	_rlt->rlt.pRlt		= outcome ;
	//the result...
	return true ;
}
bool	Loan_info_inquiry(banksys_db *_rlt,_ConnectionPtr *_pConn)
{
	const char table_borrow[]		=	" Table_Borrow " ;
	const char table_Loan[]		=	" Table_Loan " ;

	char cSqlStr[100] = "select * from" ;
	strcat_s(cSqlStr,table_borrow) ;
	strcat_s(cSqlStr,"where id = ") ;
	strcat_s(cSqlStr,_rlt->req.id) ;
	//
	_variant_t vt ;
	_RecordsetPtr rsp = (*_pConn)->Execute(cSqlStr,&vt,adCmdText);
	//

	size_t stCount = 0 ;
	while( ! rsp->rsEOF  )
	{
		rsp->MoveNext() ;
		stCount++ ;
	}
	//count how many...

	rsp->MoveFirst() ;
	// move to first...

	bankDB_result_loan_info *outcome = new bankDB_result_loan_info[stCount] ;
	// alloc the space of length of stCount

	for (unsigned int i = 0 ; i < stCount ; i++ )
	{
		_variant_t varLoanNum ;
		varLoanNum		=		rsp->Fields->GetItem(long(1))->Value ;
		rsp->MoveNext() ;
		// get account_number...

		char ch_loan_num[19] ;
		strcpy_s( ch_loan_num , (char *)(_bstr_t)varLoanNum ) ;
		//get account number of type of char * 

		char sql_str[100] = "select * from" ;
		strcat_s(sql_str, table_Loan) ;
		strcat_s(sql_str, "where loan_number = ") ;
		strcat_s(sql_str, ch_loan_num) ;
		// get sql sentence...

		_RecordsetPtr temp_rsp = (*_pConn)->Execute(sql_str,&vt,adCmdText) ;
		// excute sql sentence...

		_variant_t varOpenBran			=		temp_rsp->Fields->GetItem(long(1))->Value ;
		_variant_t varOpenDate			=		temp_rsp->Fields->GetItem(long(2))->Value;
		_variant_t varAmount				=		temp_rsp->Fields->GetItem(long(3))->Value;
		_variant_t varMonthRemain	=		temp_rsp->Fields->GetItem(long(4))->Value;
		_variant_t varMonthlyRtn		=		temp_rsp->Fields->GetItem(long(5))->Value;
		// read the data...

		strcpy_s(outcome[i].loan_num , ch_loan_num) ; 

		if (varOpenBran.vt == VT_NULL)
		{
			strcpy_s(outcome[i].open_branch , "null" ) ;
		}
		else
		{
			strcpy_s(outcome[i].open_branch , (char *)(_bstr_t)varOpenBran)  ;
		}
		// ...
		if (varOpenDate.vt == VT_NULL)
		{
			strcpy_s(outcome[i].open_date , "null" ) ;
		}
		else
		{
			strcpy_s(outcome[i].open_date , (char *)(_bstr_t)varOpenDate)  ;
		}
		//...

		if (varAmount.vt == VT_NULL)
		{
			outcome[i].amount = -1 ;
		}
		else
		{
			outcome[i].amount = varAmount ;
		}
		//...
		if (varMonthRemain.vt == VT_NULL)
		{
			outcome[i].month_remain = -1  ;
			// error if month_remain < 0 
		}
		else
		{
			outcome[i].month_remain = varMonthRemain.intVal ;
		}
		//...

		if (varMonthlyRtn.vt == VT_NULL)
		{
			outcome[i].monthly_return = -1  ;
			// error if month_remain < 0 
		}
		else
		{
			outcome[i].monthly_return = varMonthlyRtn ;
		}

		temp_rsp->MoveNext() ;
	}
	//...

	_rlt->rlt.nCount = stCount ; 
	_rlt->rlt.pRlt		= outcome ;
	//the result...

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
		Loan_info_inquiry( _rlt , _pConn );
		break ;

	default :

		break ;
	}
	return true ;
}
