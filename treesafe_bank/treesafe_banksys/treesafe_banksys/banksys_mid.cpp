#include "stdafx.h"
#include "banksys_mid.h"

//从网络层中获取数据
void mid_get_data_from_net(banksys_mid* _mid ,net_recieved_info* _rec){
	if(_mid == NULL) return;//中间转换器无效
#ifdef DEBUG_INFO
	printf("get recieved data from net\n");
#endif
	_mid->rec = *_rec;//获得数据
#ifdef DEBUG_INFO
	printf("check data , success\n");
#endif
}

//从数据库中接受数据
void mid_get_data_from_db(banksys_mid* _mid ,bankDB_result_info* _rlt){
	if(_mid == NULL) return;//中间转换器无效
#ifdef DEBUG_INFO
	printf("get reslut data from db\n");
#endif
	_mid->rlt = *_rlt;//获得数据
#ifdef DEBUG_INFO
	printf("check data , success\n");
#endif
}

//向数据库中发送数据
void mid_send_data_to_db(banksys_mid* _mid ,bankDB_request_info* _req){
		if(_mid == NULL) return;//中间转换器无效
#ifdef DEBUG_INFO
	printf("get reslut data from db\n");
#endif
	_mid->rlt = *_rlt;//获得数据
#ifdef DEBUG_INFO
	printf("check data , success\n");
#endif
}