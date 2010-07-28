#include "stdafx.h"
#include "banksys_mid.h"
#include "banksys_macro.h"

//从网络层中获取数据
void mid_get_data_from_net(banksys_mid* _mid ,banksys_net* _net){
	ARRSERT_POINTER_NULL(_mid && _net)//中间转换器无效或_net层为空
#ifdef DEBUG_MID_INFO
	printf("get recieved data from net\n");
#endif
	_mid->rec = _net->rec;//获得数据
#ifdef DEBUG_MID_INFO
	printf("recieve done\n");
#endif
#ifdef DEBUG_MID_INFO
	printf("check recieved data , success\n");
#endif
}

//从数据库中接受数据
void mid_get_data_from_db(banksys_mid* _mid ,banksys_db* _db){
	ARRSERT_POINTER_NULL(_mid && _db)//中间转换器无效或数据库无效
#ifdef DEBUG_MID_INFO
	printf("get reslut data from db\n");
#endif
	_mid->rlt = _db->rlt;//获得数据
#ifdef DEBUG_MID_INFO
	printf("recieve done\n"); 
#endif
#ifdef DEBUG_MID_INFO
	printf("check recieved data , success\n");
#endif
}

//向数据库中发送数据
void mid_send_data_to_db(banksys_mid* _mid ,banksys_db* _db){
	ARRSERT_POINTER_NULL(_mid && _db)//中间转换器无效或数据库无效
#ifdef DEBUG_MID_INFO
	printf("check send data , success\n");
#endif
#ifdef DEBUG_MID_INFO
	printf("send request data to db\n");
#endif
	_db->req = _mid->req;//发送数据
#ifdef DEBUG_MID_INFO
	printf("send done\n");
#endif
}

//向网络中发送数据
void mid_send_data_to_net(banksys_mid* _mid ,banksys_net* _net){
	ARRSERT_POINTER_NULL(_mid && _net)//中间转换器无效或_net层为空
#ifdef DEBUG_MID_INFO
	printf("check send data , success\n");
#endif
#ifdef DEBUG_MID_INFO
	printf("send result data to net\n");
#endif
	_net->send = _mid->send;//发送数据
#ifdef DEBUG_MID_INFO
	printf("send done\n");
#endif
}

//将从网络中接受的数据转化为向数据库的请求
void mid_convert_rec_to_req(net_recieved_info* _rec , bankDB_request_info* _req){
   ARRSERT_POINTER_NULL(_rec) //接收数据为空
#ifdef DEBUG_MID_INFO
	printf("convert from net_recieved_info to bankDB_request_info...\n");
#endif
	memcpy(_req,_rec->cRecieveInfo,strlen(_rec->cRecieveInfo));//数据复制
}
//将从数据库接受的运行结果数据转化为数据
void mid_convert_rlt_to_send(bankDB_result_info* _rlt , net_send_info* _send){
    ARRSERT_POINTER_NULL(_rlt)//结果数据为空
#ifdef DEBUG_MID_INFO
	printf("convert from bankDB_result_info to net_send_info...\n");
#endif
	memcpy(_send->cSendInfo,_rlt,strlen((char*)_rlt));//数据复制
}

//一次从net中接受数据,并把数据传给db的过程
void mid_recieve_frame(banksys_net* _net, 
	banksys_mid* _mid , banksys_db* _db){
	ARRSERT_POINTER_NULL(_mid && _net && _db)//不可有一者为空
	//开始从net接受一个数据
	mid_get_data_from_net(_mid , _net);
	//转化数据
	mid_convert_rec_to_req(&_mid->rec , &_mid->req);
	//将请求数据发给db
	mid_send_data_to_db(_mid,_db);
}

//一次从db中接受数据,并把数据传给net的过程
void mid_send_frame(banksys_net* _net,
	banksys_mid* _mid ,banksys_db* _db){
	if(!(_mid && _net && _db)) return;
	//开始从数据库中接受一个数据
	mid_get_data_from_db(_mid,_db);
	//转化数据
	mid_convert_rlt_to_send(&_mid->rlt,&_mid->send);
	//将请求发给net
	mid_send_data_to_net(_mid,_net);
}