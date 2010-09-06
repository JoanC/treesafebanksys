#include "stdafx.h"
#include "sys_add_group.h"

extern _ConnectionPtr* treesafe_db_connection ;  

void init_add_group(group_member_info *_Outcome) 
{
	init_group_member_info(_Outcome) ;
}

void decode_group_member_info(const char *_Data,int _NumOfMembers,group_member_info *_Outcome) 
{
	_Outcome->num = _NumOfMembers ;

	for(int i = 0 ; i < _NumOfMembers ; ++i )
	{
		_Outcome->cust_id[i][0] = _Data[ i * GROUP_CUST_ID_LEN ] ;
	}
}

bool add_group_to_db(group_member_info *_info) 
{
	char group_id[GROUP_ID_LEN] ;
	memset(group_id,0,GROUP_ID_LEN) ;

	Get_max_group_id(treesafe_db_connection,group_id) ;
	IncreaseCharStr(group_id,GROUP_ID_LEN - 1) ;
	return Insert_group_info(treesafe_db_connection,group_id,_info) ;
}

void add_group_frame(const char *_Data,int _NumOfMember,int *_LenOfOutcome) 
{
	//初始化数据
	//。。。。。
	group_member_info _info ;
	init_add_group(&_info) ;


	//解析参数，获得数据
	//。。。。。
	decode_group_member_info(_Data,_NumOfMember,&_info) ;

	//数据库操作
	//。。。。。
	add_group_to_db(&_info) ;

	//释放变量
	//。。。。。
}