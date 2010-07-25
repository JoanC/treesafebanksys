#include "stdafx.h"
#include "banksys_mid.h"

//从网络层中获取数据
void mid_get_data_from_net(banksys_mid* _mid ,banksys_net* _net){
	if(_mid == NULL) return;//中间转换器无效
	if(_net == NULL) return;//_net层为空
#ifdef DEBUG_INFO
	printf("get recieved data from net\n");
#endif
	_mid->rec = _net->rec;//获得数据
#ifdef DEBUG_INFO
	printf("recieve done\n");
#endif
#ifdef DEBUG_INFO
	printf("check recieved data , success\n");
#endif
}

//从数据库中接受数据
void mid_get_data_from_db(banksys_mid* _mid ,banksys_db* _db){
	if(_mid == NULL) return;//中间转换器无效
	if(_db == NULL) return;//数据库无效
#ifdef DEBUG_INFO
	printf("get reslut data from db\n");
#endif
	_mid->rlt = _db->rlt;//获得数据
#ifdef DEBUG_INFO
	printf("recieve done\n");
#endif
#ifdef DEBUG_INFO
	printf("check recieved data , success\n");
#endif
}

//向数据库中发送数据
void mid_send_data_to_db(banksys_mid* _mid ,banksys_db* _db){
	if(_mid == NULL) return;//中间转换器无效
	if(_db == NULL) return;//数据库无效
#ifdef DEBUG_INFO
	printf("check send data , success\n");
#endif
#ifdef DEBUG_INFO
	printf("send request data to db\n");
#endif
	_db->req = _mid->req;//发送数据
#ifdef DEBUG_INFO
	printf("send done\n");
#endif
}

//向网络中发送数据
void mid_send_data_to_net(banksys_mid* _mid ,banksys_net* _net){
	if(_mid == NULL) return;//中间转换器无效
	if(_net == NULL) return;//网络层无效
#ifdef DEBUG_INFO
	printf("check send data , success\n");
#endif
#ifdef DEBUG_INFO
	printf("send result data to net\n");
#endif
	_net->send = _mid->send;//发送数据
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

//一次从net中接受数据,并把数据传给db的过程
void mid_recieve_frame(banksys_net* _net, banksys_db* _db){
#ifdef DEBUG_INFO
	printf("foundate a new middle convertor\n");
#endif
	//为一个新的中继器申请数据内存
	banksys_mid* _mid = (banksys_mid*)malloc(sizeof(banksys_mid));
	//判断是否申请成功
	if(_mid == NULL) return;
	//开始从net接受一个数据
	mid_get_data_from_net(_mid , _net);
	//转化数据
	mid_convert_rec_to_req(&_mid->rec , &_mid->req);
	//将请求数据发给db
	mid_send_data_to_db(_mid,_db);
}