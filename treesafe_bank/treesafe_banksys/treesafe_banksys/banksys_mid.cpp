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
	printf("recieve done\n");
#endif
#ifdef DEBUG_INFO
	printf("check recieved data , success\n");
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
	printf("recieve done\n");
#endif
#ifdef DEBUG_INFO
	printf("check recieved data , success\n");
#endif
}

//向数据库中发送数据
void mid_send_data_to_db(banksys_mid* _mid ,bankDB_request_info* _req){
		if(_mid == NULL) return;//中间转换器无效
#ifdef DEBUG_INFO
	printf("check send data , success\n");
#endif
#ifdef DEBUG_INFO
	printf("send request data to db\n");
#endif
	*_req = _mid->req;//发送数据
#ifdef DEBUG_INFO
	printf("send done\n");
#endif
}

//向网络中发送数据
void mid_send_data_to_net(banksys_mid* _mid , net_send_info* _send){
	if(_mid == NULL) return;//中间转换器无效
#ifdef DEBUG_INFO
	printf("check send data , success\n");
#endif
#ifdef DEBUG_INFO
	printf("send result data to net\n");
#endif
	*_send = _mid->send;//发送数据
#ifdef DEBUG_INFO
	printf("send done\n");
#endif
}

//将从网络中接受的数据转化为向数据库的请求
void mid_convert_rec_to_req(net_recieved_info* _rec , bankDB_request_info* _req){
#ifdef DEBUG_INFO
	printf("convert from net_recieved_info to bankDB_request_info...\n");
#endif
}
//将从数据库接受的运行结果数据转化为数据
void mid_convert_rlt_to_send(bankDB_result_info* _rlt , net_send_info* _send){
#ifdef DEBUG_INFO
	printf("convert from bankDB_result_info to bankDB_send_info...\n");
#endif
}