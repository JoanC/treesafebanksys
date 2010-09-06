#include "stdafx.h"
#include "sys_group_info.h"

bool init_group_member_info(group_member_info *_Outcome) 
{
	if ( ! _Outcome )
		return false ;
	//if _Outcome == NULL 

	for (int i = 0 ; i < MAX_GROUP_SIZE ; ++i)
		memset(&_Outcome->cust_id[i][0] , 0 , GROUP_CUST_ID_LEN ) ;
	
	_Outcome->num = 0 ;

	return true ;
}