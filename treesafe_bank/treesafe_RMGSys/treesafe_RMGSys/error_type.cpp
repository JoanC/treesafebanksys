#include "stdafx.h"
#include "error_type.h"

void err_search_info(int _err_id , err_info* _err_rlt){
	//根据err的id去搜索错误信息
	//...db查询
#ifdef DEBUG_ERR_INFO
	printf("search the error: %d",_err_id);
#endif
}