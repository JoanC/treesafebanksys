#ifndef _BANKSYS_MID_H_
#define _BANKSYS_MID_H_


#include "banksys_data_struct.h"
#include "banksys_net.h"
#include "banksys_db.h"

//中间过渡模块
struct banksys_mid{
	bool isDbComplete;//将发送的
	net_recieved_info rec;//从网络接口中接受到的数据
	net_send_info send;//转化后，将要发送的数据
	bankDB_request_info req;//发送给数据库DB的请求数据
	bankDB_result_info rlt;//从数据库接受的DB结果信息
};

//从网络中接受数据
void mid_get_data_from_net(banksys_mid* _mid , banksys_net* _net);
//从数据库中接受数据
void mid_get_data_from_db(banksys_mid* _mid , banksys_db* _db);
//向数据库中发送数据
void mid_send_data_to_db(banksys_mid* _mid ,banksys_db* _db);
//向网络中发送数据
void mid_send_data_to_net(banksys_mid* _mid , banksys_net* _net);
//将从网络中接受的数据转化为向数据库的请求
void mid_convert_rec_to_req(net_recieved_info* _rec , bankDB_request_info* _req);
//将从数据库接受的运行结果数据转化为数据
void mid_convert_rlt_to_send(bankDB_result_info* _rlt , net_send_info* _send);

//一次从net中接受数据,并把数据传给db的过程
void mid_recieve_frame(banksys_net* _net, banksys_db* _db);

#endif