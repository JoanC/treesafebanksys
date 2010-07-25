#ifndef _BANKSYS_DB_H_
#define _BANKSYS_DB_H_
#include "banksys_data_struct.h"

struct banksys_db{
	bankDB_request_info req;//数据库DB的请求数据
	bankDB_result_info rlt;//DB结果信息
	//...
};

#endif